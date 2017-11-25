%{
/* C++ string header, for string ops below */
#include <string>

/* Implementation of yyFlexScanner */ 
#include "mc_scanner.hpp"
#undef  YY_DECL
#define YY_DECL int MC::MC_Scanner::yylex( MC::MC_Parser::semantic_type * const lval, MC::MC_Parser::location_type *loc )

/* typedef to make the returns for the tokens shorter */
using token = MC::MC_Parser::token;

/* define yyterminate as this instead of NULL */
#define yyterminate() return( token::END )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option debug
%option nodefault
%option yyclass="MC::MC_Scanner"
%option noyywrap
%option c++

%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
%}

"abrir"|"cerrar"|"activar_emergencia"|"desactivar_emergencia" {
				return( token::PRS );
			}

"subir"|"bajar"|"llamar" {
				//std::cout<<"MOVER "<<std::endl;
				return ( token::PRP );
}

"if" 		{
				return ( token::COND );
			}

"var"		{
				return ( token::DVAR );
			}

"("		    {
               return( token::AGPL );
            }

")"         {
				return( token::AGPR );
			}

"{"			{
				return( token::AGLL );
			}

"}"			{
				return( token::AGLR );
			}

"+"|"-"     {
               return( token::OPER_AR );
            }

"="|":="|"<-" {

               return( token::OPER_ASIG );
            }

"=="|"<="|">="|"~="|"<"|">" {
               return( token::OPER_COMP );
            }

";"         {
               return( token::FINAL_LINEA );
            }

"--"	    {
				return( token::COMENTARIO );
			}

[0-9]       {
				return( token::DIGITO );
			}

[a-z]+ {
				return( token::VARIABLE_USER );
			}

"."			{
				return( token::DECI);
			}

" "			{
				return (token::SPACE);
			}

""			{
				return (token::NOTHING);
			}

\n			{  return (token::BLN);
			}

.           {
               return( token::INVALID );
            }
%%

