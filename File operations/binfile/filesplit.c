#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;

int main(int argc, char *argv[]){
    if(argc != 3){
        printf(" Incorrect number of arguments\n");
        return 1;
    }
    int splitnum = atoi(argv[2]);
    
    FILE *fp = fopen(argv[1], "r+b");
    char filename1[256];
    char filename2[256];
    sprintf(filename1,"%s_1", argv[1]);
    sprintf(filename2,"%s_2", argv[1]);
    FILE *fp1 = fopen(filename1, "wb");
    FILE *fp2 = fopen(filename2, "wb");
    fseek(fp, 0, SEEK_END);
    int total = ftell(fp)/sizeof(phoneaddress);
    rewind(fp);
    if(fp == NULL){
        printf("Cannot open file.\n");
        return 1;
    }

    phoneaddress* addressarray = (phoneaddress*)malloc( splitnum * sizeof(phoneaddress));

    fread(addressarray, sizeof(phoneaddress), splitnum, fp);
    fwrite(addressarray, sizeof(phoneaddress), splitnum, fp1);
    free(addressarray);

    phoneaddress* addressarray2 = (phoneaddress*)malloc((total-splitnum) * sizeof(phoneaddress));
    
    fread(addressarray2, sizeof(phoneaddress), total-splitnum, fp);
    fwrite(addressarray2, sizeof(phoneaddress), total-splitnum,fp2);
    free(addressarray2);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
}
