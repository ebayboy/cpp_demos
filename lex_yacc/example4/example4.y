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

%%
start :
    | start something
    ;
 
something : NUMBER {printf("NUMBER\n");}
    | TOKHEAT {printf("TOKHEAT\n");}
    | STATE {printf("STATE\n");}
    | TOKTARGET {printf("TOKTARGET\n");}
    | TOKTEMPERATURE {print("TOKTEMPERATURE");}
    ;
%%
 
