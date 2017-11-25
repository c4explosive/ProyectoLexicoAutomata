#include "LexSeparator.h"

LexSeparator::LexSeparator(char * str)
{
	this->str=str;
	nLex=0;
}

Lexema * LexSeparator::getLexemas()
{
	return this->lexemas;
}

void LexSeparator::splitLexs()
{
	int i, j=0;
	char ch;
	char * buffer=(char *) malloc(500*sizeof(char));
	char * buffer2=(char *) malloc(500*sizeof(char));
	for(i=0;i<strlen(str);i++)
	{
	    ch=str[i];
	    if(ch != 0x20)
	    {
		buffer[j]=ch;	   
		j++;
	    }
	    else
	    {
		//printf("BUFFER %d ~ %s\n",nLex, buffer);
		sprintf(buffer2,"%s", buffer);
		lexemas[nLex].setLex(buffer2);
		j=0;
		buffer=(char *) malloc(500*sizeof(char));
		buffer2=(char *) malloc(500*sizeof(char));
		nLex++;
	    }
		
	}
	sprintf(buffer2,"%s", buffer);
	lexemas[nLex].setLex(buffer2);
	nLex++;

}
char * LexSeparator::getStr()
{
   	return this->str;
}

int LexSeparator::getNLex()
{
	return this->nLex;
}
