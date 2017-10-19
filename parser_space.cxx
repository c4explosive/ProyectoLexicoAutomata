#include "parser_space.h"
#include "SymbolsTable.h"

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
    SymbolsTable stb = SymbolsTable();
    
    cout<<"Instruccion normalizada:: "<<lxs.getStr()<<endl;
    lxs.splitLexs();
    Tokens tks = Tokens(&stb);
    for(i=0; i<lxs.getNLex(); i++)
    {
    	tks.setLx(&lxs.getLexemas()[i]);
    	tks.autoCall();
	cout<<"El lexema es: "<<tks.getLx()->getLex();
    	cout<<" -> "<<tks.getMsgType()<<endl;
	if(tks.getLx()->getType()!=tks.INVALIDO)
		stb.addSymbols(&lxs.getLexemas()[i]);

    }

    printf("Tabla de Símbolos\n");
    for(i=0; i<stb.getNSymbols(); i++)
    {
	printf("[%i|%s|0x%x|%s]\n",i+1,stb.getSymbolTable()[i]->getLex(),stb.getSymbolTable()[i], tks.getMsgType(stb.getSymbolTable()[i]->getType()));
    }
    return 0;
    
}

//TODO:
//Agregar Palabras reservadas
//Arreglar lo del comentario pegado **   --foobarbaz
