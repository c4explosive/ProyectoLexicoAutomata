#include "SymbolsTable.h"
#include "Tokens.h"
SymbolsTable::SymbolsTable()
{
    int i,j; 
    nPR=8;
    nSymbols=0;
    SymbolTable = (Lexema **) (malloc(50*sizeof(Lexema *)));
    char paReserv [][500]={"abrir","cerrar","subir","bajar","llamar","activar_emergencia","if","var"};
    this->paReserv = (char **)malloc(20*sizeof(char *));
    for(i=0; i<nPR; i++)
    {
	this->paReserv[i]=(char*) malloc(50*sizeof(char));
	strcpy(this->paReserv[i],paReserv[i]);
	Tokens  tks = Tokens();
	Lexema *lx = new Lexema();
	lx->setLex(this->paReserv[i]);
	lx->setType(tks.PALABRA_RESERVADA);
	addSymbols(lx);
    }



}

char ** SymbolsTable::getPaReserv()
{
	return paReserv;
}

void SymbolsTable::addSymbols(Lexema * lex)
{
    if(isInSymbolsTable(lex->getLex())==0)
    {
    	SymbolTable[nSymbols]=lex;
    	nSymbols++;
    }
}

Lexema ** SymbolsTable::getSymbolTable()
{
    return this->SymbolTable;
}

int SymbolsTable::getNSymbols()
{
    return this->nSymbols;
}

int SymbolsTable::isInSymbolsTable(char * str)
{
	
    int i;
    //printf("NSym0:::: 0x%x", SymbolTable[0]);
    for(i=0; i<nSymbols; i++)
	if(Tokens::compareStr(str,SymbolTable[i]->getLex())) //FIXME: Change the method for compare, need circular reference for work!!
	    return 1;
    return 0;
}
