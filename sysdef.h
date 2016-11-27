#ifndef SYSDEF_H 
#define SYSDEF_H 

char *keywords[15] = {
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

char otherOperators[6] = {':', '+', '-', '*', '/', '%', '#'};

char delimiters[9] = {'.', '(', ')', ',', '{', '}', ';', '[', ']'};

char words[LIMIT][MAX]; // include identifiers, and keywords
int wordi = 0, wordj = 0;
int wordLineNums[LIMIT];

char keys[LIMIT][MAX]; // to store keywords
int keyi = 0;
int keyLineNums[LIMIT];
   
char idens[LIMIT][MAX]; // to store identifiers
int ideni = 0;
int idenLineNums[LIMIT];

char nums[LIMIT][MAX];  // to store numbers
int numi = 0, numj = 0;
int numLineNums[LIMIT];

/*--------------------*/
char delims[LIMIT]; // to store delimiters
int delimi = 0;
int delimLineNums[LIMIT];

char otherOps[LIMIT]; // to store other operators
int otherOpi = 0;
int otherOpLineNums[LIMIT];

char relOps[LIMIT][MAX]; // to store keywords
int relOpi = 0, relOpj = 0;
int relOpLineNums[LIMIT];
#endif
