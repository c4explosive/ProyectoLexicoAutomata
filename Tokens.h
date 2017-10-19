#ifndef TOKENS_H
#define TOKENS_H
#include "Lexema.h"
#include "SymbolsTable.h"
class Tokens
{
private:
    int nPR;
    int msgs;
    Lexema *lx;
    char ** stbWords;
    int autoReserv();
    int autoAgrup();
    int autoArit();
    int autoAsig();
    int autoComp();
    int autoFLine();
    int autoComment();
    int autoDigits();
    int autoUVar();
    void autoManager();
    void whatType();
    char ** paReserv;
    char ** msGS;
    char  *msgType;

public:
    enum tTokens { PALABRA_RESERVADA, AGRUPACION, OPER_AR, OPER_ASIG, OPER_COMP, FINAL_LINEA, COMENTARIO, DIGITOS, VARIABLE_USER ,INVALIDO};
    Tokens(SymbolsTable * stb);
    Tokens();
    void setLx(Lexema * lx);
    static int compareStr(char*, char *);
    Lexema * getLx();
    void autoCall();
    char *getMsgType();
    char *getMsgType(int);
};
#endif
