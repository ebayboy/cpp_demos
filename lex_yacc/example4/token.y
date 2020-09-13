%{
#include <stdio.h>
#include <stdlib.h>
%}
 
%token NUMBER TOKHEAT STATE TOKTARGET TOKTEMPERATURE
 
%%
start :
    | start something
    ;
 
something : NUMBER {printf("NUMBER\n");}
    | TOKHEAT {printf("TOKHEAT\n");}
    | STATE {printf("STATE\n");}
    | TOKTARGET {printf("TOKTARGET\n");}
    | TOKTEMPERATURE {printf("TOKTEMPERATURE\n");}
    ;
%%
 
int main()
{
    // Intro
    printf("Type something followed by Return. Type 'q' or 'Q' to end.\n");
    printf("\n");
    // Start the parser
    return(yyparse());
}
 
int yyerror(s)
char *s;
{
    printf("yacc error: %s\n", s);
}
 
int yywrap()
{
    return(0);
}
