#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#include "token.h"
#include "parse.h"

void parse(char *lineData[LIMIT][MAXTOKS], int tokensInLine[LIMIT], int lineNumGlobal){
  int k = 0, i = 0, ideni = 0, b = 0;
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
	if ((b = isBinary(thisLine, tokensInLine[k])) == 1){
	  printf("expression\n");
	  struct assignmentToBinary* aToB = malloc(sizeof(struct assignmentToBinary));
	  aToB = newAssignmentToBinary(thisLine, tokensInLine[k]);
	  printf("id = %s\n op = %s\n leftT = %s\n rightT = %s\n", aToB->id, aToB->rightside->op, aToB->rightside->leftTerm, aToB->rightside->rightTerm);
	}else if(b >= 2){
	  printf("multiple binaries\n");
	  struct assignmentToBinaries* aToBs = malloc(sizeof(struct assignmentToBinaries));
	  aToBs = newAssignmentToBinaries(thisLine, tokensInLine[k]);
	  printf("id = %s\n op = %s\n leftT = %s\n rightside =\n  op = %s\n  leftT = %s\n,  rightT = %s\n", aToBs->id, aToBs->rightside->op, aToBs->rightside->leftTerm, aToBs->rightside->rightside->op, aToBs->rightside->rightside->leftTerm, aToBs->rightside->rightside->rightTerm);

	  //struct assignmentToBinaries* aToBs
	  //identifiers[ideni++] = newIdentifier(thisLine);
	  //printf("identifier %d = %s\n", ideni, identifiers[ideni-1]->name);
	}
      }
      else if (isConditional(thisLine)){
        printf("conditional\n");
        struct conditional* cond = malloc(sizeof(struct conditional));
        char *nextLine[MAXTOKS];
        
        // This takes in the next line of data 
        for (i = 0; i < tokensInLine[k+1]; i++){
          nextLine[i] = lineData[k+1][i];
        }

        cond = newConditional(thisLine, tokensInLine[k], nextLine);
        if(cond == 1){ // if statement  
          
        } else if (cond == 2){ // else statement 

        }
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

int isBinary(char **arr, int til){
  int i = 0, numOfB = 0;
  for(i = 3; i < til; i++){
    if(isOp(arr[i])){
       numOfB += 1;
    }
  }
  return numOfB;
}

int isOp(string operator){
  if(!strcmp(operator, "+") || !strcmp(operator, "-") || !strcmp(operator,"*" ) || !strcmp(operator, "/")){
    return 1;
  }
  return 0;
}

int isConditional(char **arr, int til){ 
  if(!strcmp(arr[0],"if") && !strcmp(arr[til], "{")){ // check line start with if and end with {
    return 1; 
  }
  if(!strcmp(arr[0],"else") && !strcmp(arr[til], "{")){ // check line start with else and end with {
    return 2; 
  }
  return 0; // false 
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
  struct assignmentToBinary* aToB = malloc(sizeof(struct assignmentToBinary));
  aToB->id = arr[0];
  aToB->rightside = newBinary(arr, til); //arr + 2 to skip "id =" 
  //part of "id = 1 + x;", til - 2 to not check "x;" for operator, as the 
  //operator CANNOT be one of the last two things on the line or you're 
  //missing a semicolon. 
  return aToB;
}

struct assignmentToBinaries* newAssignmentToBinaries(string *arr, int til) {
  struct assignmentToBinaries* aToBs = malloc(sizeof(struct assignmentToBinaries));
  aToBs->id = arr[0];
  aToBs->rightside = newBinaryToBinary(arr, til, 0); //arr + 2 to skip "id =" 
  //part of "id = 1 + x;", til - 2 to not check "x;" for operator, as the 
  //operator CANNOT be one of the last two things on the line or you're 
  //missing a semicolon. 
  return aToBs;
}

struct binary* newBinary(string *arr, int til) {
  struct binary* bi_node = malloc(sizeof(struct binary));
  int i = 0;
  for(i = til - 2; i > 2; i--){ //starts at the end of the array to support binarytobinary
    if(isOp(arr[i])){
      bi_node->op = arr[i];
      bi_node->leftTerm = arr[i - 1];
      bi_node->rightTerm = arr[i + 1];
    }
  }
  return bi_node;
}

struct binaryToBinary* newBinaryToBinary(string *arr, int til, int opsUsed) {
  struct binaryToBinary* bi_node = malloc(sizeof(struct binaryToBinary));
  int i = 0, ops[20], numOfOps = 0;
  for(i = 2; i < til - 2; i++){
    if(isOp(arr[i])){
      numOfOps++;
      if(numOfOps > opsUsed)
	ops[numOfOps - opsUsed - 1] = i;
    }
  }

  bi_node->op = arr[ops[0]];
  bi_node->leftTerm = arr[ops[0] - 1];

  if ((numOfOps - opsUsed) > 1){
    //    for(i=0; i<(numOfOps - opsUsed); i++) {
    bi_node->rightside = newBinary(arr, til);
    //}
  } /*else {  
    struct binaryToBinary* new_node = malloc(sizeof(struct binaryToBinary));
    bi_node->rightside = new_node;
    bi_node->rightside->leftTerm = arr[ops[0] + 1];
    bi_node->rightside->op = '\0';
    bi_node->rightside->rightside = '\0';
    }*/
  return bi_node;
}

struct conditional* newConditional(string *arr, int til, string *arrNext) {
  struct conditional* cond_node = malloc(sizeof(struct conditional));
  int i = 0;
  // if statement 
  if(isConditional(arr[0]) == 1){
    if(strcmp(arr[1],"(") && strcmp(arr[til-1],")")) {
      for(i = 2; i < til-2; i++){ // This grabs everything in between the ()
        cond_node->ifs.condition = arr[i];
      }
      cond_node->ifs.cdtlStatement = newAssignmentToLiteral(arrNext);
    }
  } else if (isConditional(arr[0]) == 2){ // else statement
    cond_node->ifs.elses.condition = NULL;
    cond_node->ifs.cdtlStatement = newAssignmentToLiteral(arrNext);
  }
  return cond_node;
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
 
