#include<stdio.h>
#include<string.h>


//MUST ALLOCATE MEMORY TO TMPSTRING, YOU CAN DO THE MALLOC OR SIMPLY CHAR TMPSTRING[20]. CHAR*TMPSTRING/CHAR TMPSTRING[] DOESNT WORK
void swap(char * string1, char * string2){
    char tmpstring[20];
    strcpy(tmpstring, string2);
    strcpy(string2, string1);
    strcpy(string1, tmpstring);
}

//strcmp: If the return value is less than 0, it means that the first string is lexicographically less than the second string.
//If the return value is greater than 0, it means that the first string is lexicographically greater than the second string.

int main(){
    char namei[20];
    char namej[20];
    char arrayofnames[][20]={"James Bond", "Caligula Caevas", "Cao Huy Dong"};
    int numberofnames= sizeof(arrayofnames)/sizeof(arrayofnames[0]);
    for(int i=0;i<numberofnames;i++){
        for(int j=i; j<numberofnames; j++){
            strcpy(namei, strrchr(arrayofnames[i], ' '));
            strcpy(namej, strrchr(arrayofnames[j], ' '));
            if(strcmp(namej, namei)<0){
                swap(arrayofnames[i], arrayofnames[j]);
            }else if(strcmp(namei, namej)==0){
                if(strcmp(arrayofnames[j], arrayofnames[i])<0) swap(arrayofnames[j],arrayofnames[i]);
            }

        }
    }
    for(int i=0; i<numberofnames; i++){
        printf("%s\n", arrayofnames[i]);
    }
}