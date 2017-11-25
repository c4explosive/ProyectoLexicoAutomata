#include <cctype>
#include <fstream>
#include <cassert>


#include "mc_driver.hpp"

MC::MC_Driver::~MC_Driver()
{
   delete(scanner);
   scanner = nullptr;
   delete(parser);
   parser = nullptr;
}

void 
MC::MC_Driver::parse( const char * const filename )
{
   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() )
   {
	   std::cout<<"FILE SHUT UP"<<"\n";
       exit( EXIT_FAILURE );
   }
   //std::cout<<"FSCK:: "<<in_file.rdbuf()<<"\n";
   parse_helper( in_file );
   return;
}

void
MC::MC_Driver::parse( std::istream &stream )
{
   if( ! stream.good()  && stream.eof() )
   {
	   std::cout<<"SHUT UP"<<"\n";
       return;
   }
   else
   {
   		parse_helper( stream ); 
   }
   return;
}


void 
MC::MC_Driver::parse_helper( std::istream &stream )
{
   delete(scanner);
   try
   {
      scanner = new MC::MC_Scanner( &stream );
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate scanner: (" <<
         ba.what() << "), exiting!!\n";
      exit( EXIT_FAILURE );
   }
   
   delete(parser); 
   try
   {
      parser = new MC::MC_Parser( (*scanner) /* scanner */, 
                                  (*this) /* driver */ );
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate parser: (" << 
         ba.what() << "), exiting!!\n";
      exit( EXIT_FAILURE );
   }
   const int accept( 0 );
   if( parser->parse() != accept )
   {
      std::cerr << "Parse failed!!\n";
   }
   return;
}

void 
MC::MC_Driver::add_pRes()
{ 
   pRes++;
}

void 
MC::MC_Driver::add_agrup()
{ 
   agrup++;
}

void 
MC::MC_Driver::add_oarit()
{
  	oarit++;
}

void 
MC::MC_Driver::add_ocomp()
{ 
   	ocomp++; 
}

void 
MC::MC_Driver::add_flinea()
{ 
   flinea++; 
}

void
MC::MC_Driver::add_oasig()
{
	oasig++;
}

void
MC::MC_Driver::add_comen()
{
	comen++;
}

void
MC::MC_Driver::add_digit()
{
	digit++;
}

void
MC::MC_Driver::add_varus()
{
	varus++;
}

void 
MC::MC_Driver::add_err()
{
	errr++;
}

void
MC::MC_Driver::add_line()
{
	ivis++;
}

std::ostream& 
MC::MC_Driver::print( std::ostream &stream )
{
   stream << blue  << "Instruccion Correcta " << norm << "\n";
 /*  stream << blue << "Palabras Reservadas: " << norm << pRes << "\n";
   stream << blue << "Agrupación: " << norm << agrup << "\n";
   stream << blue << "Operador Aritmetico: " << norm << oarit << "\n";
   stream << blue << "Operador de Asignacion: " << norm << oasig << "\n";
   stream << blue << "Operador de Comparacion: " << norm << ocomp << "\n";
   stream << blue << "Final de Linea: " << norm << flinea << "\n";
   stream << blue << "Comentarios: " << norm << comen << "\n";
   stream << blue << "Digitos: " << norm << digit << "\n";
   stream << blue << "Variables de Usuarios: " << norm << varus << "\n";
   stream << red << "Invalidos: "<< norm << errr << "\n";*/
   return(stream);
}
