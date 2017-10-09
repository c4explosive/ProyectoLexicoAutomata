#include "Lexema.h"
class Tokens
{
    int nPR;
    Lexema *lx;
    public:
    enum tTokens { PALABRA_RESERVADA, AGRUPACION, OPER_AR, OPER_ASIG, OPER_COMP, FINAL_LINEA, COMENTARIO, DIGITOS, INVALIDO};
    char ** paReserv;
    Tokens();
    void setLx(Lexema * lx);
    Lexema * getLx();

};
