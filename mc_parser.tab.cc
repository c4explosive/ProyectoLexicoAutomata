// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "mc_parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "mc_parser.tab.hh"

// User implementation prologue.

#line 51 "mc_parser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 28 "mc_parser.yy" // lalr1.cc:413

   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "mc_driver.hpp"

#undef yylex
#define yylex scanner.yylex

#line 65 "mc_parser.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "mc_parser.yy" // lalr1.cc:479
namespace MC {
#line 151 "mc_parser.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  MC_Parser::MC_Parser (MC_Scanner  &scanner_yyarg, MC_Driver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  MC_Parser::~MC_Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  MC_Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  MC_Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  MC_Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      default:
        break;
    }

  }


  template <typename Base>
  inline
  MC_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  MC_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}


  template <typename Base>
  inline
  MC_Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  MC_Parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  MC_Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  MC_Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  MC_Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  MC_Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  MC_Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  MC_Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  MC_Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  MC_Parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  MC_Parser::symbol_type
  MC_Parser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_AGRUPACION (const location_type& l)
  {
    return symbol_type (token::AGRUPACION, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_AGPL (const location_type& l)
  {
    return symbol_type (token::AGPL, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_AGPR (const location_type& l)
  {
    return symbol_type (token::AGPR, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_AGLL (const location_type& l)
  {
    return symbol_type (token::AGLL, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_AGLR (const location_type& l)
  {
    return symbol_type (token::AGLR, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_OPER_AR (const location_type& l)
  {
    return symbol_type (token::OPER_AR, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_OPER_ASIG (const location_type& l)
  {
    return symbol_type (token::OPER_ASIG, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_OPER_COMP (const location_type& l)
  {
    return symbol_type (token::OPER_COMP, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_FINAL_LINEA (const location_type& l)
  {
    return symbol_type (token::FINAL_LINEA, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_PALABRA_RESERVADA (const location_type& l)
  {
    return symbol_type (token::PALABRA_RESERVADA, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_PRS (const location_type& l)
  {
    return symbol_type (token::PRS, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_PRP (const location_type& l)
  {
    return symbol_type (token::PRP, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_COND (const location_type& l)
  {
    return symbol_type (token::COND, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_DVAR (const location_type& l)
  {
    return symbol_type (token::DVAR, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_COMENTARIO (const location_type& l)
  {
    return symbol_type (token::COMENTARIO, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_DIGITO (const location_type& l)
  {
    return symbol_type (token::DIGITO, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_VARIABLE_USER (const location_type& l)
  {
    return symbol_type (token::VARIABLE_USER, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_INVALID (const location_type& l)
  {
    return symbol_type (token::INVALID, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_BLN (const location_type& l)
  {
    return symbol_type (token::BLN, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_SPACE (const location_type& l)
  {
    return symbol_type (token::SPACE, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_NOTHING (const location_type& l)
  {
    return symbol_type (token::NOTHING, l);
  }

  MC_Parser::symbol_type
  MC_Parser::make_DECI (const location_type& l)
  {
    return symbol_type (token::DECI, l);
  }



  // by_state.
  inline
  MC_Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  MC_Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  MC_Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  MC_Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  MC_Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  MC_Parser::symbol_number_type
  MC_Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  MC_Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  MC_Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  MC_Parser::stack_symbol_type&
  MC_Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  MC_Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  MC_Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  MC_Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  MC_Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  MC_Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  MC_Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  MC_Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  MC_Parser::debug_level_type
  MC_Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  MC_Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline MC_Parser::state_type
  MC_Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  MC_Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  MC_Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  MC_Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {

#line 772 "mc_parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  MC_Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  MC_Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char MC_Parser::yypact_ninf_ = -18;

  const signed char MC_Parser::yytable_ninf_ = -1;

  const signed char
  MC_Parser::yypact_[] =
  {
      -1,   -18,   -18,     7,    17,   -18,     4,   -18,    20,   -18,
      24,   -18,   -18,    21,    18,   -18,   -11,    12,   -18,    27,
     -11,   -18,   -11,   -18,    15,    10,   -18,    25,   -18,     1,
      31,    26,    -5,    30,    34,    30,   -18,   -18,    15,   -18,
     -11,    32,    33,   -18,   -11,   -18,   -18,    35,   -18,   -18,
      36,   -18,   -18,   -18,   -18,    39,    -1,    40,   -18
  };

  const unsigned char
  MC_Parser::yydefact_[] =
  {
       0,     8,    10,     0,     0,    28,     0,     2,     0,     3,
       0,     4,     5,     0,     0,     6,     0,     0,     1,     0,
       0,    31,     0,    30,    12,    22,    24,     0,    23,     0,
       0,     0,    16,    18,     0,    17,    29,    11,     0,    25,
       0,     0,     0,     7,     0,    14,    19,     0,    15,    13,
       0,    27,    26,    20,     9,     0,     0,     0,    21
  };

  const signed char
  MC_Parser::yypgoto_[] =
  {
     -18,    -8,   -18,   -18,   -18,   -18,   -15,   -14,   -17,   -13,
     -18,     2,   -18,   -18,     0,    37,   -18,   -18
  };

  const signed char
  MC_Parser::yydefgoto_[] =
  {
      -1,     6,     7,     8,     9,    10,    32,    33,    34,    45,
      11,    27,    40,    12,    35,    14,    15,    22
  };

  const unsigned char
  MC_Parser::yytable_[] =
  {
      13,    25,    26,    44,    18,    36,    41,    24,     5,    37,
      21,    16,     1,     2,     3,     4,    28,    29,     5,    38,
      46,    17,    48,    49,    19,    25,    26,    53,    20,    23,
      21,     5,    31,    24,    38,    39,    42,    43,    44,    47,
      28,    55,    50,    51,    52,    56,    54,    58,    57,     0,
       0,     0,     0,     0,    30,     0,    13
  };

  const signed char
  MC_Parser::yycheck_[] =
  {
       0,    16,    16,     8,     0,    22,     5,    18,    19,    24,
       9,     4,    13,    14,    15,    16,    16,    17,    19,    24,
      33,     4,    35,    38,     4,    40,    40,    44,     4,    11,
       9,    19,     5,    18,    24,    10,     5,    11,     8,     5,
      40,     5,    40,    11,    11,     6,    11,     7,    56,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    56
  };

  const unsigned char
  MC_Parser::yystos_[] =
  {
       0,    13,    14,    15,    16,    19,    26,    27,    28,    29,
      30,    35,    38,    39,    40,    41,     4,     4,     0,     4,
       4,     9,    42,    11,    18,    31,    32,    36,    39,    39,
      40,     5,    31,    32,    33,    39,    33,    31,    24,    10,
      37,     5,     5,    11,     8,    34,    34,     5,    34,    31,
      36,    11,    11,    33,    11,     5,     6,    26,     7
  };

  const unsigned char
  MC_Parser::yyr1_[] =
  {
       0,    25,    26,    26,    26,    26,    26,    27,    28,    29,
      30,    31,    31,    32,    33,    33,    33,    33,    33,    33,
      34,    35,    36,    36,    36,    37,    38,    38,    39,    40,
      41,    42
  };

  const unsigned char
  MC_Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     4,     1,     5,
       1,     2,     1,     3,     2,     2,     1,     1,     1,     2,
       2,     9,     1,     1,     1,     1,     5,     5,     1,     3,
       2,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const MC_Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "AGRUPACION", "AGPL", "AGPR",
  "AGLL", "AGLR", "OPER_AR", "OPER_ASIG", "OPER_COMP", "FINAL_LINEA",
  "PALABRA_RESERVADA", "PRS", "PRP", "COND", "DVAR", "COMENTARIO",
  "DIGITO", "VARIABLE_USER", "INVALID", "BLN", "SPACE", "NOTHING", "DECI",
  "$accept", "S", "X", "C", "Y", "D", "N", "I", "L", "O", "Z", "B", "P",
  "A", "J", "K", "H", "U", YY_NULLPTR
  };


  const unsigned char
  MC_Parser::yyrline_[] =
  {
       0,    90,    90,    90,    90,    90,    90,    94,    97,   100,
     103,   106,   106,   109,   112,   112,   112,   112,   112,   112,
     115,   118,   121,   121,   121,   124,   127,   127,   130,   133,
     136,   139
  };

  // Print the state stack on the debug stream.
  void
  MC_Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  MC_Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  MC_Parser::token_number_type
  MC_Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
    };
    const unsigned int user_token_number_max_ = 279;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "mc_parser.yy" // lalr1.cc:1167
} // MC
#line 1134 "mc_parser.tab.cc" // lalr1.cc:1167
#line 141 "mc_parser.yy" // lalr1.cc:1168



void 
MC::MC_Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
	exit( EXIT_FAILURE);
}
