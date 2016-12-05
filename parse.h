//Type and struct Definitions
typedef char* string;

typedef enum{
  equals
} assignment;

typedef enum{
  Int, 
  Float
} type;

struct identifier{
  string name;  
  type t;
  int isArray;
};

struct term{
  string literal;
  type t;
};

struct operation{
  string op;
  struct term *term1;
  struct term *term2;
};

struct expression{
  assignment eq;
  struct identifier *id;
  struct operation *op;
};

struct statement{
  string cdtlStatement;
  string condition;
  struct statement *elses;
};

struct conditional{
  struct statement *ifs;
};

struct expression* newExpression(string *arr);
struct identifier* newIdentifier(string *arr);
struct operation* newOperation(string *arr);
struct conditional* newConditional(string *arr);



// Function Prototypes
int isArray(string *arr);
int isAssignment(string *arr);
int isExpression(string *arr);
int isOp(string operator);
int isConditional(string *arr);
void parse(char *lineData[LIMIT][MAXTOKS], int tokensInLine[LIMIT], int lineNumGlobal);
//void readData();
