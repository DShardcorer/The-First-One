#include <stdio.h>

int main(){
    FILE* fptr1= fopen("lab1.txt", "r");
    FILE* fptr2= fopen("lab1w.txt", "w+");
    if(fptr1 == NULL || fptr2 == NULL) {
        printf("Failed to open file(s).\n");
        return 1;
    char c;
    while(c != EOF){
        c=fgetc(fptr1);
        fputc(c, fptr2);
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
//U can even pass FILE* pointers to function

void CharReadWrite( FILE *fin, FILE *fout){
    int c;
    while((c=fgetc(fin))!= EOF){
        fputc(c,fout);
        putchar(c);//display characters onscreen also
    }
}