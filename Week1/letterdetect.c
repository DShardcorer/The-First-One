#include<stdio.h>
#include<string.h>

int main(){
    char S[1000];
    scanf("%s", S);
    int size= strlen(S);
    int alphabet[26];
    for(int i=0;i<26;i++){
        alphabet[i]=0;
    }
    for(int i=0; i<26;i++){
        for(int j=0; j<size; j++){
            if(S[j]=='a'+i) alphabet[i]++;
        }
    }
    for(int i=0; i<26;i++){
        for(int j=0; j<size; j++){
            if(S[j]=='A'+i) alphabet[i]++;
        }
    }
    for(int i=0; i<26; i++){
        if(alphabet[i]!= 0){
            printf("%c %d\n", 'a'+i, alphabet[i]);
        }
    }
}