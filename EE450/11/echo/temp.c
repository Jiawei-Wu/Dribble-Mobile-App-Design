#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
int main()
{
char str[999][999];
FILE *file;
file = fopen("job.txt", "r");
int i = 0;
while (fscanf(file, "%s", str[i]) != EOF)
{
//printf("%s\n", str[i]);
i++;
}
//for (int i=0; i<5; i++)
//{
//printf("%s\n", str[i]);
//}
}
