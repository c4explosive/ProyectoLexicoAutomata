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
     int i,j=0,read=0,realLen=0;
     for(i=0;i<strlen(str);i++)
     {
	if(read)
	{
	    str2[j]=str[i];
	    j++;
	    realLen++;
	}
	else
	{
	    if(str[i] != 0x20)
	    {
		str2[j]=str[i];
	    	j++;
		realLen++;
		read=1;
	    }
	}
     }
     //cout<<"::STR::"<<endl;
     //printArray(str2);
     //cout<<"::STR::"<<endl;
     for(i=0;i<N;i++)
	str[i]='\0';
     //printf("REALLEN:: %d\n",realLen);
     for(i=0;i<realLen;i++)
	str[i]=str2[i];


}

int separateStrs(char * str, char * newStr)
{
    int i,j=0;
    int spaceC=0;
    char ant,ch;
        //strcpy(str,"welcome to the job");

    for (i=0; i<strlen(str);i++)
    {
	if(str[i] == 0x9)
    	    str[i]=0x20;

    }
    killBSpaces(str);
  
    if(strlen(str)==0)
	return -9;
    /*cout<<"::RAW TRACE::"<<endl;
    printArray(str);
    cout<<"::RAW TRACE::"<<endl;*/
    ant=str[0];
    for(i=0;i<strlen(str);i++)
    {
	ch=str[i];
	if(ch >= 0x41 && ch <= 0x5a)
		ch+=0x20;
	if(ch==0x20 || ch==0xa)
	{
	    ant=ch;
	    continue;
	}
	if(checkAlphaNum(ch) && checkAlphaNum(ant) ||
	(ch == 0x3d && ant == 0x3c) ||
	(ch == 0x3d && ant == 0x3a) ||
	(ch == 0x2d && ant == 0x3c) ||
	(ch == 0x3d && ant == 0x3d) ||
	(ch == 0x3d && ant == 0x3e) ||
	(ch == 0x3d && ant == 0x7e) ||
	(ch == 0x2d && ant == 0x2d)
	)
	    newStr[j]=ch;
	else
	{
	    if(ch != 0x20)
	    {
		if(i!=0)
		{
	    	    newStr[j]=0x20;
	    	    j++;
		}
	    	newStr[j]=ch;
	    }
	}
	ant=ch;
	j++;
    }
    //printf("STR:: %s\n", newStr);
    return 0;
}

