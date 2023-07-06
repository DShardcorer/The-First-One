#include<stdio.h>

int memory[100];

int fibonacci(int n){
    if(n==0||n==1)return n;
    if(memory[n]!=0){
        return memory[n];
    }
    memory[n]= fibonacci(n-1)+fibonacci(n-2);
    return memory[n];
}

int factorial(int n){
    if(n==0||n==1) return n;
    return n*factorial(n-1);
}

int main(){
    for(int i =0; i<100;i++){
        memory[i]=0;
    }
    printf("%d ", fibonacci(30));
    printf("%d\n", factorial(6));
}