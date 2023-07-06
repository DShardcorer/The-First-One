#include<stdio.h>
#include<string.h>
void conv(int n,char s[])
{
  int d,t;char c[1];
  if (n==0)
    {
      return;
    };
  d=n%2;
  t=n/2;
  c[0]=(char)(d+48);
  strcat(s,c);
  conv(t,s);
  return;
}
int main()
{
  char s[16];int n;
  strcpy(s,""); 
  printf("Input integer: ");scanf("%d",&n);
  if(n<0){
    printf("Negative number. Error.\n");
    return 1;
  }
  conv(n,s);
  printf("Converted to binary number: ");
  for (int i=strlen(s)-1;i>=0;i--)
    {
      if (s[i]=='\0')
	{
	  printf("0");
	} else
	{
	  printf("%c",s[i]);
	};
    };
  printf("\n");
  return 0;
}
