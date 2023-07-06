#include<stdio.h>
#include<stdlib.h>
#define N 10
int n;
int x[N];
void solution(){
    for(int i=1; i<=n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}

int check(int v, int k){
    if(v == 1 && x[k-1] == 1) return 0;
    return 1;
}

void Try(int k){
    for(int v=0; v<=1; v++){
        if(check(v,k) == 1){
            x[k]=v;
            if(k==n){
                solution();
            }else{
                Try(k+1);
            }
        }
    }
}

int main(){
    n=5;
    Try(1);
}
