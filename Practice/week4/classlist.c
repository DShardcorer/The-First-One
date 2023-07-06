#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char no[3];
    char studentNumber[20];
    char firstName[20];
    char phoneNumber[20];
} studentData;

studentData *readDataFromFile(char *fileName, int *numberOfStudents)
{
    FILE *fp = fopen(fileName, "rb");
    fseek(fp, 0, SEEK_END);
    *numberOfStudents = ftell(fp) / sizeof(studentData);
    rewind(fp);
    studentData *data = (studentData *)malloc(*numberOfStudents * sizeof(studentData));
    fread(data, sizeof(studentData), *numberOfStudents, fp);
    fclose(fp);
    return data;
}
// int main() {
//  char string[50] = "Hello! We are learning about strtok";
//  Lấy token đầu tiên
// char * token = strtok(string, " ");
//  Lấy ra toàn bộ token
// while( token != NULL ) {
// printf( " %s\n", token ); //In mỗi token ra
// token = strtok(NULL, " ");
//}
// return 0;
//}

// Each call to strtok returns a pointer to the token found, and subsequent calls continue tokenizing the same string until no more tokens are found, at which point it returns NULL.

// It's important to note that strtok modifies the original input string by replacing the delimiter characters with null terminators ('\0'). If you need to preserve the original input string, make a copy before tokenizing it.

studentData *readTextDataFromFile(char *filename, int *numberOfStudents, studentData array[])
{
    FILE *fp = fopen(filename, "r");
    *numberOfStudents = 0;
    char string[70];
    char *token;
    int i = 0;
    while (feof(fp) == 0)
    {
        fgets(string, sizeof(string), fp);
        token = strtok(string, " ");
        strcpy(array[i].no, token);
        token = strtok(NULL, " ");
        strcpy(array[i].studentNumber, token);
        token = strtok(NULL, " ");
        strcpy(array[i].firstName, token);
        token = strtok(NULL, " \n"); // terminate the last \n char
        strcpy(array[i].phoneNumber, token);
        i++;
        (*numberOfStudents)++;
    }
    fclose(fp);
}
studentData *readTextDataFromFile2(char *filename, int *numberOfStudents)
{
    FILE *fp = fopen(filename, "r");
    char string[70];
    char *token;
    *numberOfStudents = 0;
    while (feof(fp) == 0)
    {
        fgets(string, sizeof(string), fp);
        (*numberOfStudents)++;
    }
    rewind(fp);
    studentData *array = (studentData *)malloc((*numberOfStudents) * sizeof(studentData));
    int i=0;
    while(feof(fp) == 0)
    {
        fgets(string, sizeof(string), fp);
        token = strtok(string, " ");
        strcpy(array[i].no, token);
        token = strtok(NULL, " ");
        strcpy(array[i].studentNumber, token);
        token = strtok(NULL, " ");
        strcpy(array[i].firstName, token);
        token = strtok(NULL, " \n"); // terminate the last \n character.
        strcpy(array[i].phoneNumber, token);
    i++;
    }
    fclose(fp);
    return array;
}
// In the code snippet you provided, the expression *numberOfStudents++ increments the numberOfStudents pointer itself, not the value it points to.
// The post-increment operator (++) has higher precedence than the dereference operator (*),
// so the increment operation is applied to the pointer first.

// To correctly increment the value pointed to by numberOfStudents,
// you need to dereference the pointer first using parentheses, like this: (*numberOfStudents)++.
// The parentheses ensure that the pointer is dereferenced before the increment operation is applied to the value.
void printList(studentData *array, int numberOfStudents)
{
    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("%s %s %s %s\n", array[i].no, array[i].studentNumber, array[i].firstName, array[i].phoneNumber);
    }
}

studentData *inputOneMore(studentData *array, int *numberOfStudents)
{
    studentData *resizedArray = (studentData *)realloc(array, ((*numberOfStudents) + 1) * sizeof(studentData));
    printf("Enter no. MSSV Name Phone_number accordingly.");
        scanf("%s %s %s %s", resizedArray[*numberOfStudents].no, resizedArray[*numberOfStudents].studentNumber, resizedArray[*numberOfStudents].firstName, resizedArray[*numberOfStudents].phoneNumber);
        (*numberOfStudents)++;
    return resizedArray;
} // REALLOCING PRESERVE ORGINAL DATA

//DO NOT TRY TO FREE SHITS LIKE studentData array[50]. THAT SHIT WILL KILL YOU.

int main()
{
    int numberOfStudents;
    studentData array[50];
    readTextDataFromFile("data.txt", &numberOfStudents, array);
    studentData *array2 = readTextDataFromFile2("data.txt", &numberOfStudents);
    printList(array2, numberOfStudents);

    char choice;
    while(1)
    {
        printf("Input more?Y/N.\n");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'Y':
            array2 = inputOneMore(array2, &numberOfStudents);
            printList(array2, numberOfStudents);
            break;
        case 'N':
            free(array2);
            exit(1);
            break;
            break;
        default:
            printf("Invalid input.\n"); break;
        }
    }
}