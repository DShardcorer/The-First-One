#include<stdio.h>
#include<string.h>
void replace( char array[], char ori, char rep){
    int len= strlen(array);
    for(int i=0;i<len; i++){
        if(array[i]== ori) array[i]=rep;
    }
    printf("%s", array);
}

int main(){
    replace("uwuwuwu", 'u', 'a');
}