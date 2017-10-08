#include "preProcess.h"

void printArray(const char * str) //holamundo
{
    printf("hola mundo");
	int i;
    printf(":::DBG:::\n");
    for(i=0;i<strlen(str);i++)
	    cout<<"0x"<<hex<<(int)(str[i])<<" "<<str[i]<<endl;
	    //printf("0x%x %c\n",str[i],str[i]);
	    
}

int checkAlphaNum(char ch)
{
    if((ch>=0x41 && ch<=0x7A || ch>=0x30 && ch<=0x39))
	   return 1;
    return 0; 

}

void killBSpaces( char * str)
{
     char *str2 = (char *)(malloc(N*sizeof(char)));
     int i,j=0,read=0;
     for(i=0;i<strlen(str);i++)
     {
	if(read)
	{
	    str2[j]=str[i];
	    j++;
	}
	else
	{
	    if(str[i] != 0x20)
	    {
		str2[j]=str[i];
	    	j++;
		read=1;
	    }
	}
     }
     for(i=0;i<strlen(str);i++)
	str[i]='\0';
     for(i=0;i<strlen(str2);i++)
	str[i]=str2[i];

}

void separateStrs(char * str, char * newStr)
{
    int i,j=0;
    int spaceC=0;
    char ant=0x41,ch;

    //strcpy(str,"welcome to the job");
    killBSpaces(str);
    for(i=0;i<strlen(str);i++)
    {
	ch=str[i];
	if(ch==0x20 || ch==0xa || ch==0x09)
	{
	    ant=ch;
	    continue;
	}
	if(checkAlphaNum(ch) && checkAlphaNum(ant))
	    newStr[j]=ch;
	else
	{
	    if(ch != 0x20)
	    {
	    	newStr[j]=0x20;
	    	j++;
	    	newStr[j]=ch;
	    }
	}
	ant=ch;
	j++;
    }
    //printf("STR:: %s\n", newStr);
}

