#include<stdio.h>
#include<stdlib.h>

void frequency(int array[], int size){
    int freq[21];
    for(int i=0;i<=20;i++){
        freq[i]=0;
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<=20;j++){
            if(array[i]== j) freq[j]++;
        }
    }
    for(int i=0;i<=20;i++){
        if(freq[i]!=0){
            printf("%d %d \n", i, freq[i]);
        }
    }
}

int main(){
    int size;
    int array[1000];
    scanf("%d", &size);
    for(int i=0;i<size;i++){
        scanf("%d", &array[i]);
    }
    frequency(array,size);
}