#define SYSDEF_H 

char *keywords[32] = {
    "auto", "double", "int", "struct", 
    "break", "else", "long", "switch",
    "case", "enum", "register", "typedef",
    "char", "extern", "return", "union",
    "const", "float", "short", "unsigned",
    "continue", "for", "signed", "void",
    "default", "goto", "sizeof", "volatile",
    "do", "if", "static", "while"
};	

char *relationalOperators[] = {"==", "<", ">", "!=", "=>", "=<"};
char otherOperators[6] = {':', '+', '-', '*', '/', '%'};
char delimiters[9] = {'.', '(', ')', ',', '{', '}', ';', '[', ']'};

/* include identifiers, and keywords */
char words[LIMIT][MAX]; 
int wordi = 0, wordj = 0;
int wordLineNums[LIMIT];

/* keywords */
char keys[LIMIT][MAX];
int keyi = 0;
int keyLineNums[LIMIT];
   
/* identifiers */
char idens[LIMIT][MAX];
int ideni = 0;
int idenLineNums[LIMIT];

/* numbers */
char nums[LIMIT][MAX];
int numi = 0, numj = 0;
int numLineNums[LIMIT];

/* delimiter */
char delims[LIMIT];
int delimi = 0;
int delimLineNums[LIMIT];

/* operators */
char otherOps[LIMIT];
int otherOpi = 0;
int otherOpLineNums[LIMIT];

/* relational operators */
char relOps[LIMIT][MAX];
int relOpi = 0, relOpj = 0;
int relOpLineNums[LIMIT];