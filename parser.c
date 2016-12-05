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
	  printf("expression\n");
	  struct assignmentToBinary* assToB = malloc(sizeof(struct assignmentToBinary));
	  assToB = newAssignmentToBinary(thisLine, tokensInLine[k]);
	  printf("id = %s\n op = %s\n leftT = %s\n rightT = %s\n", assToB->id, assToB->rightside->op, assToB->rightside->leftTerm, assToB->rightside->rightTerm);
	}else{
	  printf("identifiers\n");
	  //identifiers[ideni++] = newIdentifier(thisLine);
	  //printf("identifier %d = %s\n", ideni, identifiers[ideni-1]->name);
	}
      }
      else if (isConditional(thisLine)){
	//newConditional(thisLine);
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
  for(i = 3; i < til; i++){
    if(isOp(arr[i])){
      return 1;
    }
  }
  return 0;
}

int isOp(string operator){
  if(!strcmp(operator, "+") || !strcmp(operator, "-") || !strcmp(operator,"*" ) || !strcmp(operator, "/")){
    return 1;
  }
  return 0;
}

int isConditional(char **arr){
  return arr[0] == "if";
}
/*
struct expression* newExpression(string *arr){
  struct expression* eq_node = malloc(sizeof(struct expression)); 
  eq_node->eq = equals; 
  struct identifier* i = newIdentifier(arr);
  struct operation* p = newOperation(arr);
  
  }*/

struct identifier* newIdentifier(string *arr){
  struct identifier* id_node = malloc(sizeof (struct identifier)); 
  id_node->name = arr[1];
  id_node->t;
  return id_node;
}

struct variable* newVariable(string *arr){
  struct variable* var_node = malloc(sizeof (struct variable)); 
  var_node->name = arr[1];
  var_node->type;
  return var_node;
}

struct assignmentToLiteral* newAssignmentToLiteral(string *arr) {
  struct assignmentToLiteral* ass_node = malloc(sizeof(struct assignmentToLiteral));
  ass_node->id = arr[0];
  ass_node->rightside = newVariable(arr + 3);
  return ass_node;
}

struct assignmentToBinary* newAssignmentToBinary(string *arr, int til) {
  struct assignmentToBinary* ass_node = malloc(sizeof(struct assignmentToBinary));
  ass_node->id = arr[0];
  ass_node->rightside = newBinary(arr, til); //arr + 2 to skip "id =" 
  //part of "id = 1 + x;", til - 2 to not check "x;" for operator, as the 
  //operator CANNOT be one of the last two things on the line or you're 
  //missing a semicolon. 
  return ass_node;
}

struct binary* newBinary(string *arr, int til) {
  struct binary* bi_node = malloc(sizeof(struct binary));
  int i = 0;
  for(i = 2; i < til - 2; i++){
    if(isOp(arr[i])){
      bi_node->op = arr[i];
      bi_node->leftTerm = arr[i - 1];
      bi_node->rightTerm = arr[i + 1];
    }
  }
  return bi_node;
}


/*
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
  }*/
 
