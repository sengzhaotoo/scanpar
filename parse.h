#define MAXVARS 20
#define MAXASSIGNS 20

//Type and struct Definitions

typedef struct variable{
  char *name;
  char *type;
} variable;


typedef struct binary{
  char *op;
  char *leftTerm;
  char *rightTerm;
} binary;

typedef struct binaryToBinary{
  char *op;
  char *leftTerm;
  binary *rightside;
} binaryToBinary;

  
typedef struct assignmentToLiteral{
  char *id;
  variable *rightside;
} assignmentToLiteral;

typedef struct assignmentToBinary{
  char *id;
  binary *rightside;
} assignmentToBinary;

typedef struct assignmentToBinaries{
  char *id;
  binaryToBinary *rightside;
} assignmentToBinaries;
/*
typedef struct assignmentToBinariesRec{
  char *id;
  binaryToBinaries *rightside;
} assignmentToBinariesRec;
*/

/*typedef struct binaryToBinaries{
  char *op;
  char *leftTerm;
  binaryToBinary *rightside;
} binaryToBinaries;
*/



///////////////////////
typedef char* string;

/*typedef enum{
  equals
} equals;

typedef enum{
  Int, 
  Float
} type;
*/

typedef struct identifier{
  char *name;  
  char *t;
  int isArray;
} identifier;

/*typedef struct assignment{
  char equals = '=';
  identifier leftside;
  binary rightside;
  } assignmentExp;


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
*/
//Global Variables
//identifier *identifiers[MAXVARS];
//assignment *assignments[MAXASSIGNS];

// Function Prototypes
int isArray(string *arr, int til);
int isAssignment(string *arr);
int isExpression(string *arr, int til);
int isOp(string operator);
int isConditional(string *arr);
void parse(char *lineData[LIMIT][MAXTOKS], int tokensInLine[LIMIT], int lineNumGlobal);

struct assignmentToLiteral* newAssignmentToLiteral(string *arr);
struct variable* newVariable(string *arr);
struct assignmentToBinary* newAssignmentToBinary(string *arr, int til);
struct assignmentToBinaries* newAssignmentToBinaries(string *arr, int til);

struct binary* newBinary(string *arr, int til);
struct binaryToBinary* newBinaryToBinary(string *arr, int til, int opsUsed);
//struct expression* newExpression(string *arr);
struct identifier* newIdentifier(string *arr);
//struct operation* newOperation(string *arr);
//struct conditional* newConditional(string *arr);


