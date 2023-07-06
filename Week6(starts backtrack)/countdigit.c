#include<stdio.h>

int countdigit(int num){
    if(num==0) return 1;
    return 1+ countdigit((int)num/10);
}

int sumdigit(int num){
    if (num == 0) return 0;
    return num%10 + sumdigit(num/10);
}
int main(){
    printf("%d ",countdigit(123456));
    printf("%d",sumdigit(1234));
    return 0;
}