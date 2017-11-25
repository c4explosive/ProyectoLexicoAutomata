%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {MC}
%define parser_class_name {MC_Parser}

%code requires{
   namespace MC {
      class MC_Driver;
      class MC_Scanner;
   }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { MC_Scanner  &scanner  }
%parse-param { MC_Driver  &driver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "mc_driver.hpp"

#undef yylex
#define yylex scanner.yylex
}

/*PALABRA_RESERVADA, AGRUPACION, OPER_AR, OPER_ASIG, OPER_COMP, FINAL_LINEA, COMENTARIO, DIGITOS, VARIABLE_USER ,INVALIDO*/

/*{"abrir","cerrar","subir","bajar",
"llamar","activar_emergencia","if","var"*/

%define api.value.type variant
%define parse.assert

%token               END    0     "end of file"
%token               AGRUPACION
%token				 AGPL
%token				 AGPR
%token				 AGLL
%token				 AGLR
%token               OPER_AR
%token				 OPER_ASIG
%token               OPER_COMP
%token               FINAL_LINEA
%token				 PALABRA_RESERVADA
%token				 PRS
%token				 PRP
%token				 COND
%token				 DVAR
%token				 COMENTARIO
%token				 DIGITO
%token				 VARIABLE_USER
%token				 INVALID
%token				 BLN
%token				 SPACE
%token				 NOTHING
%token 				 DECI

%locations

%%

//list_option : END | list END;

/*list
  : item
  | list item
  ;

item
  : PRS AGPL AGPR FINAL_LINEA {driver.add_pRes(); }
  | PRP AGPL DIGITO AGPR FINAL_LINEA {driver.add_pRes(); }
  | BLN
  | SPACE
  ;*/
S
  : X|Y|Z|A|H
  ;

X:
	C AGPL AGPR FINAL_LINEA;

C: 
   PRS;

Y: 
   D AGPL L AGPR FINAL_LINEA;

D: 
   PRP;

N: //Enteros
   DIGITO N | DIGITO; //TODO:add nothig if don't work

I:
	N DECI N;

L:
   N O | J O | N | J | I | I O;

O:
	OPER_AR L;

Z:
	COND AGPL B P B AGPR AGLL S AGLR;

B: 
	N | J | I ;

P:
	OPER_COMP;

A:
	DVAR AGPL K AGPR FINAL_LINEA | DVAR AGPL J AGPR FINAL_LINEA;

J:
	VARIABLE_USER;

K:
	J U L;

H:
	K FINAL_LINEA;

U:
	OPER_ASIG;

%%


void 
MC::MC_Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
	exit( EXIT_FAILURE);
}
