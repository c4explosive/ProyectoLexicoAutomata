#ifndef LEXEMA_H
#define LEXEMA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define N 500

using namespace std;
class Lexema
{
    private:
    	char *lex;
    	int type;
    public:
	Lexema();
	void setLex(char *);
	char * getLex();
	void setType(int);
	int getType();
};
#endif
