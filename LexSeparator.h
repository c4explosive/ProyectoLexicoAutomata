#ifndef LEXSEPARATOR_H
#define LEXSEPARATOR_H
#include "SymbolsTable.h"
#define lexN 50

class LexSeparator
{
  private:
    Lexema lexemas[lexN];
    char * str;
    int nLex;
  public:
    LexSeparator(char * str);
    Lexema * getLexemas();
    void splitLexs();
    char * getStr();
    int getNLex();

};
#endif
