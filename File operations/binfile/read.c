#include <stdio.h>
#include <stdlib.h>

typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

int main()
{
    FILE *fp;
    fp = fopen("phonebook.dat_2", "rb");
    if (fp == NULL)
    {
        printf("Failed to open file.\n");
        return 0;
    }

    int n = 2; // assuming there are 8 records in the file

    phoneaddress *addressarray = (phoneaddress *)malloc(n * sizeof(phoneaddress));
    if (addressarray == NULL)
    {
        printf("Cannot allocate memory.\n");
        return 0;
    }

    fread(addressarray, sizeof(phoneaddress), n, fp);

    for (int i = 0; i < n; i++)
    {
        printf("%s-", addressarray[i].name);
        printf("%s-", addressarray[i].tel);
        printf("%s\n", addressarray[i].email);
    }

    fclose(fp);

    free(addressarray);

    return 0;
}

