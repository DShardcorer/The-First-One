#include<stdio.h>
#include<string.h>
int main(int argc, char argv[]){
        if(argc!=3){
        printf("Wrong number of arguments.\n");
        printf("CORRECT SYNTAX: wordreplica repword repnum \n");
        return 1;
        //return khac 0 ham main =exit but theres a problem with a program
    }
    int repnum = argv[2];
    char repword[100];
    strcpy(repword, argv[1]);
    for(int i =0;i<repnum;i++){
        printf("%s", repword);
    }
}