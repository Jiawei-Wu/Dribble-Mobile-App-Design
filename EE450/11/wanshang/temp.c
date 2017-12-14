#include <stdio.h>
#define MAX 1000
int main()
{
FILE *fp;







char ch;
int g;
int line=0;
fp=fopen("job.txt","r");
while(!feof(fp))
{
   if((ch=fgetc(fp))==NULL) line++;
}

printf("sum to %d lines.\n",line);
fclose(fp);
return 0;
}
