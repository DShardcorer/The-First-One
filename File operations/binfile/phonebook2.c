#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;
int main()
{
    FILE *fp;
    fp = fopen("phonebook.dat", "r+b");
    if (fp == NULL)
    {
        printf("Failed to open file.\n");
        return 0;
    }
    int from = 4;
    int to = 8;
    int n = to - from;
    phoneaddress *addressarray = (phoneaddress *)malloc(n * sizeof(phoneaddress));
    if (addressarray == NULL)
    {
        printf("Cannot allocate memory.\n");
        return 0;
    }
    fseek(fp, (from - 1) * sizeof(phoneaddress), SEEK_SET);
    fread(addressarray, sizeof(phoneaddress), n, fp);
    for (int i = 0; i < n; i++)
    {
        printf("%s-", addressarray[i].name);
        printf("%s-", addressarray[i].tel);
        printf("%s\n", addressarray[i].email);
    }
    strcpy(addressarray[1].name, "Lan Hoa");
    strcpy(addressarray[1].tel, "0923456");
    strcpy(addressarray[1].email, "lovelybuffalo@hust.edu.vn");
    fseek(fp,(from-1)*sizeof(phoneaddress), SEEK_SET);
    fwrite(addressarray,sizeof(phoneaddress), n, fp);
    fclose(fp);
    //It is generally not recommended to use r+b mode for opening a file for writing, as it can lead to unexpected behavior. It is better to use w+b mode instead.
    fp = fopen("phonebook2.dat","w+b");
    fwrite(addressarray,sizeof(phoneaddress), n, fp);
    fclose(fp);
    free(addressarray);
}
