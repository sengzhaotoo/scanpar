#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#include "token.h"
#include "sysdef.h"
#include "scan.h"

// Grammar Definitions

typedef char* string;

typedef struct identifier{
  string name;
} id;

typedef struct term{
  string literal;
} t;

typedef struct expression{
  t term1;
  string op;
  t term2;
} exp;

typedef struct assignment{
  id id_node;
  string equal;
  exp exp_node;
  string end;
} assn;

// Function Prototypes
int isAssignment(string *arr);

int isExpression(string *arr);

int isOp(string operator);

// Main Function
int main(int argc, string argv[]){
  
  /*
  string array[6] = {"a", "=", "1", "+", "2", ";"}; // Example input 

  if (isAssignment(array)){      
  assn test;
  test.equal = "=";
  test.end = ";"; 
  test.id_node.name = array[0];  
    if (isExpression(array)){
      test.exp_node.term1.literal = array[2];
      test.exp_node.op = array[3];  
      test.exp_node.term2.literal = array[4];
    }
 }
 */
}


//Function definitions

int isAssignment(char **arr){
  return arr[1] == "=";
}

int isExpression(char **arr){
  return isOp(arr[3]);
}

int isOp(string operator){
  return operator == "+" || operator == "-" || operator == "*" || operator == "/";
}
