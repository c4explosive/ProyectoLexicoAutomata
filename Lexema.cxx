#include "Lexema.h"

Lexema::Lexema()
{
	lex = (char *) (malloc(500*sizeof(char)));
}

void Lexema::setLex(char* str)
{
	sprintf(lex,"%s",str);
	//strcpy(lex,str);
}

char * Lexema::getLex()
{
	return this->lex;
}

void Lexema::setType(int type)
{
	this->type=type;
}

int Lexema::getType()
{
	return this->type;
}
