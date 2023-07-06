#include<stdio.h>
int main(){
    double A[10];
    int i;
    for(i=0;i<10;i++){
        scanf("%lf", &A[i]);
    }
    for(i=9;i>=0;i--){
        printf("%f", A[i] );
    }
}