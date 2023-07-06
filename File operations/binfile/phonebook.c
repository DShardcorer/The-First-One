#include <stdio.h>
#define MAX_ELEMENT 20
typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

int main()
{
    FILE *fp;
    int n;
    phoneaddress addressarray[MAX_ELEMENT];
    if ((fp = fopen("phonebook.dat", "wb")) == NULL)
    {
        printf("Cannot open file.\n");
        return 0;
    }
    printf("How many addresses do you want to enter ?\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("name:");
        scanf("%s", addressarray[i].name);
        printf("tel:");
        scanf("%s", addressarray[i].tel);
        printf("email:");
        scanf("%s", addressarray[i].email);
    }
    fwrite(addressarray, sizeof(phoneaddress), n, fp);
    for (int i = 0; i < n; i++)
    {
        printf("%s-", addressarray[i].name);
        printf("%s-", addressarray[i].tel);
        printf("%s\n", addressarray[i].email);
    }
    fclose(fp);
    return 1;
}
