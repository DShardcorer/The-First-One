#include<stdio.h>
#include<string.h>

int equalorsymm(int array1[], int array2[]){
    int l1= strlen(array1);
    int l2= strlen(array2);
    if(l1!=l2) return 0;
    int len=l1;
    int equal=1;
    int symm=1;
    for(int i=0;i<len;i++){
        if(array1[i]!=array2[i]) equal =0;
    }
    for(int i=0;i<len;i++){
        if(array1[i]!=array2[len-1-i]) symm =0;
    }
    if(equal==1){
        return 1;
    }else if(symm==1){
        return -1;
    }else{
        return 0;
    }
}

int main(){
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {5, 4, 3, 2, 1};
    int arr4[] = {1, 2, 3, 4, 6};
    int result1 = equalorsymm(arr1, arr2);
    int result2 = equalorsymm(arr1, arr3);
    int result3 = equalorsymm(arr1, arr4);
    printf("%d %d %d\n", result1, result2, result3);
    return 0;
}