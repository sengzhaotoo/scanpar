#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#include "token.h"

int eligibleChar(char c) {
	if (c == '.' || c == '(' || c == ')' || c == ',' || c == '{' || c == '}' ||
		c == ';' || c == '[' || c == ']' || c == '"' || c == '\\' || c == '_' ||
		c == ':' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || 
		c == '=' || c == '<' || c == '>' || c == '!' 
		|| c == '#') {
		return 1;
	} else 
		return 0;
}

void check(FILE *fp){
    int lineNum = 1, // line number 
        ccount = 0, // character count for per word (greedy)
        valid = 1; // valid bit is true by default 
    char c, temp[MAX];


    while((c = fgetc(fp)) != EOF){
        // New line 
        if(c == '\n'){
            lineNum++; 
        }

        // Comment line 
        if(c == '/'){
            if(fgetc(fp) == '/'){
                lineNum++;
            }
        }
        // Check for number, characters, operators, space 
        if(isalnum(c)){
            temp[ccount] = c; // this does not handle array-out-of-bound 
            ccount++;
            if(ccount > MAX){
                printf("Word '%s' on line %d is too long (>= 16 characters).\n", temp, lineNum);
                exit(EXIT_FAILURE);
            }
        } else if (isspace(c) || eligibleChar(c)) {
            ccount = 0;
        } else {
            printf("Invalid character '%c' at line %d.\n", c, lineNum);
            valid = 0;
            exit(EXIT_FAILURE);
        }
    }
    rewind(fp);
}

void printFile(FILE *fp){
    char c; 
    printf("Beginning of the C file:\n");
    c = fgetc(fp);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fp); 
    }
    printf("\nEnd Of File\n");
}

int main(int argc, char *argv[]){
    FILE *fp; 
    char *file; 

    // File name 
    file = argv[1]; 

    if((fp = fopen(file,"r"))== NULL){
        printf("File does not exist or corrupted.\n");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0, SEEK_END); // Reset file pointer position -> 0
    if(ftell(fp) == 0){
        printf("File is empty.\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp);
    check(fp); // Check if file is invalid
    printFile(fp); // Print the file which we will be working on
    fclose(fp);
    exit(EXIT_SUCCESS); 
    return 0; // Should never reach here
}