//Each capital letter is converted into a lower-case letter, and each
//lower-case letter is converted into a capital letter. The new
//sentence is then written into another file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void filecopy(FILE* f1, FILE* f2){
    int c;
    while((c = fgetc(f1))!= EOF){
        if('a'<= c && c <= 'z'){
             c=toupper(c);
        }else if('A'<= c && c <= 'Z' ){
             c=tolower(c);
        }
        fputc(c, f2);
    }
}
int main(int argc, char *argv[]){
    if(argc!= 3){
        printf("Incorrect number of arguments (Expected: 3)\n");
        return 1;
    }
    FILE* file1;
    FILE* file2;
    file1 = fopen(argv[1], "r");
    file2 = fopen(argv[2], "w");
    if(file1 == NULL){
        printf("Error opening %s", argv[1]);
        return 1;
    }
    if(file2 == NULL){
        printf("Error opening %s", argv[2]);
        return 1;
    }
    
    filecopy(file1,file2);
    fclose(file1);
    fclose(file2);
}