#ifndef __MCDRIVER_HPP__
#define __MCDRIVER_HPP__ 1

#include <string>
#include <cstddef>
#include <istream>

#include "mc_scanner.hpp"
#include "mc_parser.tab.hh"

namespace MC{

class MC_Driver{
public:
   MC_Driver() = default;

   virtual ~MC_Driver();
   
   /** 
    * parse - parse from a file
    * @param filename - valid string with input file
    */
   void parse( const char * const filename );
   /** 
    * parse - parse from a c++ input stream
    * @param is - std::istream&, valid input stream
    */
   void parse( std::istream &iss );

   void add_pRes();
   void add_agrup();
   void add_oarit();
   void add_ocomp();
   void add_flinea();
   void add_oasig(); //Test of new token
   void add_comen();
   void add_digit();
   void add_varus();
   void add_err();
   void add_line();

   std::ostream& print(std::ostream &stream);
private:

   void parse_helper( std::istream &stream );

   std::size_t  pRes       = 0;
   std::size_t  agrup      = 0;
   std::size_t  oarit      = 0;
   std::size_t  ocomp	   = 0;
   std::size_t  flinea	   = 0;
   std::size_t  oasig      = 0;
   std::size_t  comen	   = 0;
   std::size_t  digit      = 0;
   std::size_t  varus	   = 0;
   std::size_t  errr       = 0;
   std::size_t  ivis  	   = 0; //esta variable
   MC::MC_Parser  *parser  = nullptr;
   MC::MC_Scanner *scanner = nullptr;
   
   const std::string red   = "\033[1;31m";
   const std::string blue  = "\033[1;36m";
   const std::string norm  = "\033[0m";
};

} /* end namespace MC */
#endif /* END __MCDRIVER_HPP__ */
