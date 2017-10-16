#ifndef SYMBOLSTABLE_H
#define SYMBOLSTABLE_H
#include "Tokens.h"
#include "Lexema.h"
class SymbolsTable
{
  private:
    Lexema ** SymbolTable ;
    int nSymbols;
    int isInSymbolsTable(char*);
  public:
    SymbolsTable();
    void addSymbols(Lexema *);
    Lexema ** getSymbolTable();
    int getNSymbols();
};
#endif
