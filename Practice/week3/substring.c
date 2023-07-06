#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *subString(char *s1, int offset, int number){
    if(number + offset > strlen(s1)){
        printf("Input is too big.\n");
        return NULL;
    }
    char* subStr = (char*)malloc((number+1)*sizeof(char));
    strncpy(subStr, &s1[offset], number);
    subStr[number] = '\0';
    return subStr;
}

int main(){
    char* example="Hey hello there";
    char* cut = subString(example, 4,12);
    printf("%s", cut); 
    free(cut);
    return 0;
}
//If you don't use dynamic allocation and instead return an array created inside the function, it can lead to undefined behavior.

//In C, local variables declared inside a function have automatic storage duration. This means that when the function returns, the memory allocated for these local variables is deallocated, and the memory becomes invalid. Returning a pointer to a local array from a function will result in a dangling pointer, as the memory it points to is no longer valid.

//Attempting to access or use the memory pointed to by a dangling pointer can lead to unpredictable results, including crashes, incorrect data, or undefined behavior.

//Therefore, it is generally not recommended to return a pointer to a local array created inside a function unless you use dynamic memory allocation (e.g., malloc) to allocate the memory on the heap.