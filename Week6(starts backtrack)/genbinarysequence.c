#include<stdio.h>
#define N 100
int n;
int x[N];
void solution(){
    for(int i=1;i<=n;i++){
        printf("%d", x[i]);
    }
    printf("\n");
}

int check(int v, int k){
    return 1;
}
void Try(int k){
    for(int v=0;v<=1;v++){
        if(check(v,k)){
            x[k]=v;
            if(k==n)solution();
            else Try(k+1);
        }
    }
}
int main(){
    n=3;
    Try(1);
}