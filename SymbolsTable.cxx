#include "SymbolsTable.h"

SymbolsTable::SymbolsTable()
{
    nSymbols=0;
    SymbolTable = (Lexema **) (malloc(50*sizeof(Lexema *)));

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
    for(i=0; i<nSymbols; i++)
	if(Tokens::compareStr(str,SymbolTable[i]->getLex()))
	    return 1;
    return 0;
}
