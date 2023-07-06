#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void fileencode(int offset, FILE *fp, char *filename)
{
    int c;
    FILE *tempfile = fopen("tempfile.txt", "w");
    if (tempfile == NULL)
    {
        printf("Unable to create temporary file.\n");
        return;
    }

    while ((c = getc(fp)) != EOF)
    {
        if (islower(c))
        {
            c = ((c - 'a' + offset) % 26) + 'a';
        }
        else if (isupper(c))
        {
            c = ((c - 'A' + offset) % 26) + 'A';
        }
        fputc(c, tempfile);
    }
    fclose(tempfile);
    fclose(fp);

    if (remove(filename) != 0)
    {
        printf("Unable to remove original file.\n");
        return;
    }

    if (rename("tempfile.txt", filename) != 0)
    {
        printf("Unable to rename temporary file.\n");
        return;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Incorrect number of arguments.\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "r+");
    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }
    int offset = atoi(argv[2]);
    fileencode(offset, fp, argv[1]);
    fclose(fp);
    return 0;
}