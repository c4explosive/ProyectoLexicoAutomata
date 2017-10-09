#include "Tokens.h"
Tokens::Tokens()
{
    nPR=8;
    char paReserv [][500]={"abrir","cerrar","subir","bajar","llamar","activar_emergencia","if","var"};

    this->paReserv = (char **)malloc(20*sizeof(char *));
    for(int i=0; i<nPR; i++)
    {
	this->paReserv[i]=paReserv[i];
    }
    //printf("Esto es raro %s\n", this->paReserv[7]);
}

void Tokens::setLx(Lexema *lx)
{
    this->lx=lx;
    //cout<<"WAIT:: "<<this->paReserv[7]<<endl;
    //cout<<"LEXXS: "<<lx->getLex()<<endl;
}

Lexema * Tokens::getLx()
{
    return this->lx;
}

void Tokens::autoCall()
{
    autoManager();
    whatType();
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

int Tokens::compareStr(char *str1, char *str2)
{
    int i;
    for(i=0;i<strlen(str1);i++)
	    if(str1[i] != str2[i])
		return 0;
    return 1;
}

int Tokens::autoReserv()
{
    int i,j;
    for(i=0;i<nPR;i++)
    {
	if( compareStr(paReserv[i], lx->getLex()))
	{
		lx->setType(PALABRA_RESERVADA);
    		return 1;
	}
    }
    return 0;
}

int Tokens::autoAgrup()
{
    int i;
    char ch;
    for(i=0;i<strlen(lx->getLex());i++)
    {
        ch=lx->getLex()[i]; 
    	if(ch == 0x28 || ch == 0x29 || ch == 0x7b || ch == 0x7d)
	{
		lx->setType(AGRUPACION);
		return 1;
	}
    }
    return 0;
}

int Tokens::autoArit()
{   
    int i;
    char ch;
    for(i=0; i<strlen(lx->getLex());i++)
    {
        ch=lx->getLex()[i]; 
	if(ch == 0x2b || ch == 0x2c)
	{
		lx->setType(OPER_AR);
		return 1;
	}
    }
    return 0;
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
    int i;
    char ch, sig;
    ch=lx->getLex()[0];
    sig=lx->getLex()[1];
    if(ch == 0x3d && strlen(lx->getLex())==1)
    {
	lx->setType(OPER_ASIG);
    	return 1;
    }
    //TODO: CONTINUE HERE!!
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
       		cout<<" -> Signos de Agrupacion"<<endl;
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

