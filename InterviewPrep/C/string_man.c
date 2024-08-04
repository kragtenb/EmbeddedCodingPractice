/*
Question 3: String Manipulation
Description:

Implement the strcpy and strcat functions in C.
Key Concepts:

Pointer arithmetic.
String handling in C.
Proper null termination of strings.
*/

#include <stdio.h>
#include <stdlib.h>

char *my_strcpy(char *dest, const char *src) {
    char* dest_ptr = dest;
    while (*src != '\0') {
        *dest_ptr = *src;
        dest_ptr++;
        src++;
    }
    *dest_ptr = '\0';
    return dest;
}
char *my_strcat(char *dest, const char *src) {
    char* dest_ptr = dest;
    while (*dest_ptr != '\0') {
        dest_ptr++;
    }
    while (*src != '\0') {
        *dest_ptr = *src;
        dest_ptr++;
        src++;
    }
    *dest_ptr = '\0';
    return dest;
}

int main() {
    char dest[50];
    my_strcpy(dest, "Hello, ");
    my_strcat(dest, "World!");

    printf("%s\n", dest); // Output should be "Hello, World!"
    
    return 0;
}