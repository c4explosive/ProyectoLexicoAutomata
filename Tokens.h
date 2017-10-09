#include "Lexema.h"
class Tokens
{
private:
    int nPR;
    Lexema *lx;
    int autoReserv();
    int autoAgrup();
    int autoArit();
    int autoAsig();
    int autoComp();
    int autoFLine();
    int autoComment();
    int autoDigits();
    void autoManager();
    void whatType();
    int compareStr(char*, char *);

public:
    enum tTokens { PALABRA_RESERVADA, AGRUPACION, OPER_AR, OPER_ASIG, OPER_COMP, FINAL_LINEA, COMENTARIO, DIGITOS, INVALIDO};
    char ** paReserv;
    Tokens();
    void setLx(Lexema * lx);
    Lexema * getLx();
    void autoCall();

};
