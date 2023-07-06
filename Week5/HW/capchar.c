#include<stdio.h>
#include<string.h>
char cap(char s[],int n)
{
  if (n>strlen(s)-1)
    {
      return (char)0;
    }
  int t=(int)s[n];
  if (t>=65 && t<=90)
    {
      return s[n];
    }else
    {
      return cap(s,n+1);
    };
};
int main()
{
  char s[100],c;
  printf("Input string: ");scanf("%s",s);
  c=cap(s,0);
  if (c=='\0')
    {
      printf("There is no capital character in the string.\n");
    } else
    {
      printf("The first capital character in the string is %c.\n",c);
    };
   return 0;
}
