#include "parser_space.h"

int main(int argc, char* argv[])
{
    char bstr[]="welcome to the job( ) u";
    char str[N];
    char * newStr = (char *) (malloc(200*sizeof(char)));
    char * buffer;
    int i;
    cout<<"Ingrese una instruccion: ";
    //scanf("%[^\n]",str);
    cin.getline(str,N);
    separateStrs(str, newStr);
    //printArray(newStr);
    LexSeparator lxs = LexSeparator(newStr);
    cout<<"Instruccion normalizada:: "<<lxs.getStr()<<endl;
    lxs.splitLexs();
    Tokens tks = Tokens();
    for(i=0; i<lxs.getNLex(); i++)
    {
    	tks.setLx(&lxs.getLexemas()[i]);
    	tks.autoCall();
    }
}

