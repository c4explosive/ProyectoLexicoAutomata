#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(const char * str)
{
    int i;
    printf(":::DBG:::\n");
    for(i=0;i<strlen(str);i++)
	    printf("0x%x %c\n",str[i],str[i]);
}

int main()
{
    char str[]="subir(98);";
    //char str[500];
    int i,j=0;
    char ant=0x41,ch;
    char * newStr = (char *) (malloc(200*sizeof(char)));

    //printf("Ingrese una instruccion: ");
    //scanf("%s",str);

    for(i=0;i<strlen(str);i++)
    {
	ch=str[i];
	if(ch==0x20 || ch==0xa || ch==0x09)
	   continue;
	if((ch>=0x41 && ch<=0x7A || ch>=0x30 && ch<=0x39) 
	&& (ant>=0x41 && ant<=0x7A || ant>=0x30 && ant<=0x39))
	    newStr[j]=ch;
	else
	{
	    newStr[j]=0x20;
	    j++;
	    newStr[j]=ch;
	}
	ant=ch;
	j++;
    }

    printf(":::STR:::\n%s\n",newStr);
    printArray(newStr);

}

