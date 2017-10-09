#include "parser_space.h"



int main(int argc, char* argv[])
{
    char bstr[]="welcome to the job( ) u";
    char str[N];
    char * newStr = (char *) (malloc(200*sizeof(char)));
    char * buffer;
    cout<<"Ingrese una instruccion: ";
    //scanf("%[^\n]",str);
    cin.getline(str,N);
    separateStrs(str, newStr);
    //printArray(newStr);
    LexSeparator lxs = LexSeparator(newStr);
    cout<<"String P:: "<<lxs.getStr()<<endl;
    lxs.splitLexs();
    for(int i=0; i<lxs.getNLex(); i++)
    	cout<<"GET MY FIRST LEX: "<<i<<" ~ "<<lxs.getLexemas()[i].getLex()<<endl;
    Tokens tks = Tokens();
}

