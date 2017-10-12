#ifndef SYMBOLSTABLE_H
#define SYMBOLSTABLE_H
#include "Tokens.h"
#include "Lexema.h"
class SymbolsTable
{
  private:
    Lexema ** SymbolTable ;
    int nSymbols;
  public:
    SymbolsTable();
};
#endif
