#include "parser_space.h"

int main(int argc, char* argv[])
{
    char str[N];
    char * newStr = (char *) (malloc(200*sizeof(char)));
    int i;
    cout<<"Ingrese una instruccion: ";
    cin.getline(str,N);
    
    if (separateStrs(str, newStr) < 0)
    {
	printf("Instruccion vacía, abortando...\n");
    	return 1;
    }

    LexSeparator lxs = LexSeparator(newStr);
    cout<<"Instruccion normalizada:: "<<lxs.getStr()<<endl;
    lxs.splitLexs();
    Tokens tks = Tokens();
    for(i=0; i<lxs.getNLex(); i++)
    {
    	tks.setLx(&lxs.getLexemas()[i]);
    	tks.autoCall();
	cout<<"El lexema es: "<<tks.getLx()->getLex();
    	cout<<" -> "<<tks.getMsgType()<<endl;

    }
    return 0;
}
//TODO:
//Hacer tabla de simbolos
//Arreglar lo del comentario pegado
