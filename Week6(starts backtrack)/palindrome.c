#include<stdio.h>
#include<string.h>

int palindrome(int n, char* string, int len){
    if(0+n == len-n-1 && string[0+n] == string[len-n-1]) return 1;
    if(0+n == len-n){
        return 1;
    }else if(string[0+n]!=string[len-n-1]){
        return 0;
    }
    return palindrome(n+1, string, len);
}

int main(){
    int n= palindrome(0, "Askasa", strlen("Askasa"));
    printf("%d", n);
}