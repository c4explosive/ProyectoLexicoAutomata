#include "Tokens.h"
Tokens::Tokens()
{
    nPR=8;
    char paReserv [][500]={"abrir","cerrar","subir","bajar","llamar","activar_emergencia","if","var"};

    this->paReserv = (char **)malloc(nPR*sizeof(char *));
    for(int i=0; i<nPR; i++)
	this->paReserv[i]=paReserv[i];

    //printf("Esto es raro %s\n", this->paReserv[7]);
}

void Tokens::setLx(Lexema *lx)
{
    this->lx=lx;
}

Lexema * Tokens::getLx()
{
    return this->lx;
}
