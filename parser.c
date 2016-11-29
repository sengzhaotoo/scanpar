#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#include "token.h"
#include "sysdef.h"
#include "scan.h"

// Grammar Definitions

typedef char* string;

typedef enum{
  equals
} assignment;

typedef enum{
  plus,
  minus,
  divided_by,
  times
} operator;

typedef enum{
  Int, 
  Float
} type;

struct identifier{
  string name;
  type t;
};

struct term{
  string literal;
  type t;
};

struct operation{
  operator op;
  struct term *term1;
  struct term *term2;
};

struct equality{
  assignment eq;
  struct identifier *id;
  struct operation *op;
};

// Function Prototypes
int isAssignment(string *arr);

int isExpression(string *arr);

int isOp(string operator);

struct equality* newEquality(string *arr);

// Main Function
int main(int argc, string argv[]){
  
  
  string array[6] = {"a", "=", "1", "+", "2", ";"}; // Example input 
  newEquality(array);

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

struct equality* newEquality(string *arr){
  struct equality* eq_node = malloc(sizeof(struct equality)); 
  eq_node->eq = equals; 
 // struct identifier i;
 // struct operation p;
}
