
#include "parser_space.h"



int main(int argc, char* argv[])
{
    //char str[]="welcome to the job( ) u";
    char str[N];
    char * newStr = (char *) (malloc(200*sizeof(char)));
    cout<<"Ingrese una instruccion: ";
    //scanf("%[^\n]",str);
    cin.getline(str,N);
    separateStrs(str, newStr);
    printArray(newStr);
}

