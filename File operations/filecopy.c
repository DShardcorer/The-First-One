#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE* f1, FILE* f2){
    int c;
    while((c = fgetc(f1))!= EOF){
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
    if(file1 == NULL){
        printf("Error opening %s", argv[1]);
        return 1;
    }
    if(file2 == NULL){
        printf("Error opening %s", argv[2]);
        return 1;
    }
    file1 = fopen(argv[1], "r");
    file2 = fopen(argv[2], "w");
    filecopy(file1,file2);
    fclose(file1);
    fclose(file2);
}