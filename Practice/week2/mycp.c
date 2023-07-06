#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Incorrect number of arguments.\n");
        exit(1);
    }
    FILE*sourceFile = fopen(argv[1],"r");
    FILE*desFile = fopen(argv[2], "w");
    if(sourceFile == NULL){
        printf("Cannot open source file.\n");
        exit(1);
    }
    if(desFile == NULL){
        printf("Cannot open destination file.\n");
        exit(1);
    }
    int c;
    while((c=fgetc(sourceFile))!= EOF){
        fputc(c, desFile);
        putchar(c);
    }
    printf("Copy successful.");
    fclose(sourceFile);
    fclose(desFile);
}
