#include<stdio.h>
#include<string.h>

char *findlastname(char array[]){
    int arrsize= strlen(array);
    int i=0;
    char* ptr=NULL;
    for(i=0;i<arrsize;i++){
        if(array[i] == ' ') ptr = *array[i+1]
    }
    return ptr;
}
void swaparray(char *array1, char *array2){
    char *temp=null;
    temp=array2;
    array2=array1;
    array1=temp;
}
//first name in VN, last in general
void namesort(char array[][100], int n){
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n; j++){
            char *lastnamei = findlastname[array[i]];
            char *lastnamej = findlastname[array[j]];
            if(strcmp(lastnamei,lastnamej)> 0) swaparray(array[i],array[j]);
        }
    }
}