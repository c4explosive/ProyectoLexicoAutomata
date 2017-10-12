#ifndef TOKENS_H
#define TOKENS_H
#include "Lexema.h"
class Tokens
{
private:
    int nPR;
    int msgs;
    Lexema *lx;
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
    int compareStr(char*, char *);
    char ** paReserv;
    char ** msGS;
    char  *msgType;

public:
    enum tTokens { PALABRA_RESERVADA, AGRUPACION, OPER_AR, OPER_ASIG, OPER_COMP, FINAL_LINEA, COMENTARIO, DIGITOS, VARIABLE_USER ,INVALIDO};
    Tokens();
    void setLx(Lexema * lx);
    Lexema * getLx();
    void autoCall();
    char *getMsgType();

};
#endif
