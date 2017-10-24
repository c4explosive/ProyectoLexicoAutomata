#ifndef SYMBOLSTABLE_H
#define SYMBOLSTABLE_H
#include "Lexema.h"
class SymbolsTable
{
  private:
    int nPR;
    Lexema ** SymbolTable ;
    int nSymbols;
    int isInSymbolsTable(char*);
    char ** paReserv; 
  public:
    SymbolsTable();
    char ** getPaReserv();
    void addSymbols(Lexema *);
    Lexema ** getSymbolTable();
    int getNSymbols();
};
#endif
