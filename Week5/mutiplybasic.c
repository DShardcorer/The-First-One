#include <stdio.h>
int mutiply(int a, int b){
    if(b == 1) return a;
    return a + mutiply(a, b-1);
}

int main(){
    int n = mutiply(3,5);
    printf("%d", n);
}