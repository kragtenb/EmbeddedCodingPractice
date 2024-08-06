#include <stdlib.h>
#include <stdio.h>

void insert(int* array, int index, int value) {
    array[index] = value;
}

void deleteValue(int* array, int size, int value) {
    for (int i=0; i<size; i++) {
        if (array[i] == value) {
            for (int j=i+1; j<size; j++) {
                array[j-1] = array[j];
            }
            return;
        }
    }
}

int main() {
    int m[5];
    for (int i=0; i < 5; i++) {
        m[i] = i;
    }

    insert(m, 2, 10);
    deleteValue(m, 5, 2);

    for (int i=0; i < 5; i++) {
        printf("%d\n", m[i]);
    }
    return 0;
}