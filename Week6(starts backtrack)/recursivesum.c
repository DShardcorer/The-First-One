#include<stdio.h>

int sum(int n){
    if(n == 1) return 1;
    return n+sum(n-1);
}

int main(){
    int n = sum(8);
    printf("%d", n);
    return 0;
}