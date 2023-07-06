#include <stdio.h>
#define MAX 100
int M[MAX][MAX];// M[k][n] store the value of  
                // C(k,n)
int C(int k,int n){
    if(k == 0 || k == n) M[k][n] = 1;
    else if(M[k][n] == 0) 
      M[k][n] = C(k,n-1) + C(k-1,n-1);
    return M[k][n];
}
