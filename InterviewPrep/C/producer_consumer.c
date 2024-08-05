#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

pthread_mutex_t mutex;
pthread_cond_t not_empty;
pthread_cond_t not_full;

void* producer(void* arg) {
    int* messages = (int*) arg;

    for (int i = 0; i < *messages; i++) {
        pthread_mutex_lock(&mutex);

        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&not_full, &mutex);
        }

        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Producer added %d\n", i);
        if (count == 1) {
            pthread_cond_signal(&not_empty);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* consumer(void* arg) {
    int* messages = (int*) arg;

    for (int i = 0; i < *messages; i++) {
        pthread_mutex_lock(&mutex);

        while (count == 0) {
            pthread_cond_wait(&not_empty, &mutex);
        }

        int value = buffer[out];
        count--;
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumer removed %d\n", value);
        if (count == BUFFER_SIZE - 1) {
            pthread_cond_signal(&not_full);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread;
    pthread_t consumer_thread;
    int messages = 20;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_empty, NULL);
    pthread_cond_init(&not_full, NULL);

    pthread_create(&producer_thread, NULL, producer, &messages);
    pthread_create(&consumer_thread, NULL, consumer, &messages);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);

    return 0;
}