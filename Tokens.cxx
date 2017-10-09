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

void Tokens::autoManager()
{
    int flag=0;
    flag=autoReserv();
    if(flag) 
	return;
    flag=autoAgrup();
    if(flag)
	return;
    flag=autoArit();
    if(flag)
	return;
    flag=autoAsig();
    if(flag)
	return;
    flag=autoComp();
    if(flag)
	return;
    flag=autoFLine();
    if(flag)
	return;
    flag=autoComment();
    if(flag)
	return;
    flag=autoDigits();
    if(flag)
	return;
   
}

int Tokens::autoReserv()
{
    return 1;
}

int Tokens::autoAgrup()
{
    return 1;
}

int Tokens::autoArit()
{
    return 1;
}

int Tokens::autoComp()
{
    return 1;
}

int Tokens::autoFLine()
{
    return 1;
}

int Tokens::autoAsig()
{
    return 1;
}

int Tokens::autoComment()
{
    return 1;
}

int Tokens::autoDigits()
{
    return 1;
}

void Tokens::whatType()
{
    int type;
    type=lx->getType();
    cout<<"El lexema es: "<<lx->getLex();
    switch(type)
    {
	case PALABRA_RESERVADA:
       		cout<<" -> Palabra reservada"<<endl;
		break;
	case AGRUPACION:
       		cout<<" -> Signos de arupacion"<<endl;
		break;
	case OPER_AR:
		cout<<" -> Operador Aritmetico"<<endl;
		break;
	case OPER_ASIG:
		cout<<" -> Operador de Asignacion"<<endl;
		break;
	case OPER_COMP:
		cout<<" -> Operador de Comparacion"<<endl;
		break;
	case FINAL_LINEA:
		cout<<" -> Final de linea"<<endl;
		break;
	case COMENTARIO:
		cout<<" -> Comentario"<<endl;
		break;
	case DIGITOS:
		cout<<" -> Digitos/Numeros"<<endl;
		break;
	case INVALIDO:
		cout<<" -> Error Lexico // Token no encontrado"<<endl;
		break;
	default:
		cout<<" -> Esto es mas que desconocido..."<<endl;
		break;

    }
}

