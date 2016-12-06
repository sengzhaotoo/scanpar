#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#include "token.h"
#include "parse.h"

void parse(char *lineData[LIMIT][MAXTOKS], int tokensInLine[LIMIT], int lineNumGlobal){
  int k = 0, i = 0, ideni = 0;
  //this was for debugging purposes:
  //printf("lng = %d\n", lineNumGlobal);
  //for (k = 1; k < lineNumGlobal; k++){
    //printf("TokensinlinePARSER %d = %d\n", k, tokensInLine[k]);
    //printf("fuck = %s\n\n", lineData[k][0]);
    //tokensInLineScan[k] = tokensInLine[k];
  //}

  printf("Begin Parsing\n");
  char *thisLine[MAXTOKS];
  /*  thisLine[0] = lineData[8][0];
  thisLine[1] = lineData[8][1];
  printf("equality = %d\n", strcmp(thisLine[0], "="));
  printf("equality = %d\n", strcmp(thisLine[1], "="));
  */
  for (k = 1; k < lineNumGlobal; k++){
    if(tokensInLine[k] > 3) {
      //printf("tokens in line %d = %d\n",k, tokensInLine[k]);
      //printf("thisLine = {");
      for (i = 0; i < tokensInLine[k]; i++){
	thisLine[i] = lineData[k][i];
	//	printf("\"%s\", ", thisLine[i]);

      }
      //printf("}\n");
 
      if (isAssignment(thisLine)){
	printf("assignment\n");
	if (isExpression(thisLine, tokensInLine[k])){
	  newExpression(thisLine);
	  printf("expression\n");
	}
	else{
	  identifiers[ideni++] = newIdentifier(thisLine);
	  printf("identifier %d = %s\n", ideni, identifiers[ideni-1]->name);
	}
      }
      else if (isConditional(thisLine)){
	newConditional(thisLine);
	printf("conditional\n");
	}
    }
  }

}



//Function definitions

int isArray(char **arr, int til){
  int i = 0;
  for(i = 0; i < til; i++){
    if(!strcmp(arr[i], "[")){
      if(!strcmp(arr[i+2], "]")){
	return 1;
      }
    }
  }
  return 0;
}

int isAssignment(char **arr){
  int i = 0;
  for(i = 1; i < 3; i++){
    if(!strcmp(arr[i], "=")){
      //identifiers[ideni++] = newIdentifier(arr, i)
      return 1;
    }
  }
  return 0;
}

int isExpression(char **arr, int til){
  int i = 0;
  for(i = 3; i < til - 1; i++){
    if(isOp(arr[i])){
      return 1;
    }
  }
  return 0;
}

int isOp(string operator){
  return operator == "+" || operator == "-" || operator == "*" || operator == "/";
}

int isConditional(char **arr){
  return arr[0] == "if";
}

struct expression* newExpression(string *arr){
  struct expression* eq_node = malloc(sizeof(struct expression)); 
  eq_node->eq = equals; 
  struct identifier* i = newIdentifier(arr);
  struct operation* p = newOperation(arr);
  
}

struct identifier* newIdentifier(string *arr){
  struct identifier* id_node = malloc(sizeof (struct identifier)); 
  id_node->name = arr[1];
  id_node->t;
  return id_node;
}

struct assignment* newAssignment(string *arr) {
  struct assignment* ass_node = malloc(sizeof(struct assignment));
  ass_node->name = arr[0];
  ass_node->rightside = newIdentifier(*arr[3]);
  return ass_node;
}


struct operation* newOperation(string *arr){
  struct operation* op_node = malloc(sizeof(struct operation));
  struct term* term_node1 = malloc(sizeof(struct term));
  struct term* term_node2 = malloc(sizeof(struct term));
  op_node->op = arr[3];
  op_node->term1 = term_node1;
  op_node->term2 = term_node2;
  term_node1->literal = arr[2];
  term_node2->literal = arr[4];
  //return 
}

struct conditional* newConditional(string *arr){
  struct conditional* cond_node = malloc(sizeof(struct conditional));
  struct statement* if_node = malloc(sizeof(struct statement));
  struct statement* else_node = malloc(sizeof(struct statement));  
}
 
