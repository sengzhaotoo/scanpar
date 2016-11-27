typedef enum {
    IDENTIFIER,
	KEYWORD,
	NUMBER,
	REL_OP, 	//  ==  <  >  =!=    =>  =<
	OP,			//  = :  +  -  *  / %
	DELIM,		//  . (  ) , { } ; [ ] 
	UNDEF,		// undefined
	EOT 		// end of token
} TokenType;


typedef struct {
    TokenType ttype;
    char *instance;
    int lineNum;  
} Token;

#define MAX 16 
#define LIMIT 200