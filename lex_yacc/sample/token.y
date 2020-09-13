%{
#include <stdio.h>
%}
 
%token DIGIT LOWERCASELETTER UPPERCASELETTER OTHER STOP
 
%%
start :
    | start something
    ;
 
something : DIGIT {printf("DIGIT\n");}
    | LOWERCASELETTER {printf("LOWERCASELETTER\n");}
    | UPPERCASELETTER {printf("UPPERCASELETTER\n");}
    | OTHER {printf("OTHER\n");}
    | STOP {exit(0);}
    ;
%%
 
main()
{
    // Intro
    printf("Type something followed by Return. Type 'q' or 'Q' to end.\n");
    printf("\n");
    // Start the parser
    return(yyparse());
}
 
yyerror(s)
char *s;
{
    printf("yacc error: %s\n", s);
}
 
yywrap()
{
    return(0);
}
