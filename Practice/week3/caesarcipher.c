#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Incorrect number of arguments.\n");
        exit(1);
    }
    FILE*sourceFile = fopen(argv[1],"r");
    FILE*desFile = fopen("ciphered.txt","w");
    if(sourceFile == NULL){
        printf("Cannot open source file.\n");
        exit(1);
    }
    if(desFile == NULL){
        printf("Cannot open destination file.\n");
        exit(1);
    }
    int c;
    int offset = atoi(argv[2]);
    while((c=fgetc(sourceFile))!= EOF){
        if(c+offset <= 'Z' && c+offset >='A'){
        fputc(c+offset, desFile);
        }else if(c + offset <= 'z' && c+offset >='a'){
        fputc(c+offset, desFile);
        }else if(c <= '9' && c >= '1'){
        fputc(c, desFile);
        }
        putchar(c+offset);
    }

    printf("\nCopy successful.\n");
    fclose(sourceFile);
    fclose(desFile);
}
