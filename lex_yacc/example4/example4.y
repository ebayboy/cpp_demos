%{
#include <stdio.h>
#include <string.h>

void yywrap()
{
    return  1；
}

main()
{
    yyparse();
}
%}

%token  NUMBER TOKHEAT STATE TOKTARGET TOKTEMPERATURE
