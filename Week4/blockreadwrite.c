#define MAX_LEN 80
void BlockReadWrite(FILE *fin, FILE *fout){
    int num;
    char buff[MAX_LEN+1];
    while(!feof(fin)){
        num=fread(buff, sizeof(char), MAX_LEN, fin);
        buff[num*sizeof(char)]='\0';
        printf("%s", buff);
        fwrite(buff, sizeof(char), num, fout);
    }
}
int main(int argc, char* argv[]){
    if(argc !=3){
        printf("Wrong syntax.");
    }
    FILE* fin = fopen(argv[1]);
    FILE* fout = fopen(argv[2]);
    BlockReadWrite(fin, fout);
    fclose(fin);
    fclose(fout);
}