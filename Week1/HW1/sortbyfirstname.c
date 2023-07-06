#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char* find_last_name(char* name) {
    char* last_name = NULL;
    int i = 0;
    while (name[i] != '\0') {
        if (name[i] == ' ') {
            last_name = &name[i + 1];
        }
        i++;
    }
    return last_name;
}

void swap(char *str1, char *str2) {
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}


void sort_by_last_name(char names[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            char *last_name_i = find_last_name(names[i]);
            char *last_name_j = find_last_name(names[j]);
            if (strcmp(last_name_i, last_name_j) > 0) {
                swap(names[i], names[j]);
            }
        }
    }
}

int main() {
    char names[][100] = {"John Doe", "Alice Smith", "Bob Levas Aguar", "David Lee"};
    int n = 4;

    printf("Original list:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    sort_by_last_name(names, n);

    printf("\nSorted list:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}