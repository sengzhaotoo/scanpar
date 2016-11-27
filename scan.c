#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#include "token.h"
#include "sysdef.h"

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

int eligibleRelationalOp(char c) {
	int result = 0; // false
	if (c == '=' || c == '<' || c == '>') {
		result = 1;
	}
	return result;	
}

int eligibleOp(char c) {
	 int i;
	 int result = 0; // false
	 for (i = 0; i < 6; i++) {
		if (otherOperators[i] == c) 
			result = 1;
	 }
	 return result;
}

int eligibleDelimiter(char c) {
	 int i;
	 int result = 0; // false
	 for (i = 0; i < 9; i++) {
		if (delimiters[i] == c) 
			result = 1;
	 }
	 return result;
}

int eligibleKeyword(char *str) {
	int i;
	int result = 0; // false
	for (i = 0; i < 15; i++) {
		if (!strcasecmp(keywords[i], str))
			result = 1;
	}
	return result;
}

void splitWords() {
	int i;
	for (i = 0; i < wordi; i++) {
		if (eligibleKeyword(words[i])) {
			strcpy(keys[keyi], words[i]);
			keyLineNums[keyi] =  wordLineNums[i];
			keyi++;
		} else {
			strcpy(idens[ideni], words[i]);
			idenLineNums[ideni] = wordLineNums[i];
			ideni++;

		}
	}
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

/*  Check if file is invalid -- file type, invalid characters etc */ 
TokenType getToken(FILE *fp){
    int lineNum = 1, // line number 
        ccount = 0, // character count for per word (greedy)
        valid = 1, // valid bit is true by default
        check = 0; // check bit is false by default   
    char c, temp[MAX];

    while((c = fgetc(fp)) != EOF){
        // Initial Check 
        if(check == 0){
            // New line 
            if(c == '\n'){
                lineNum++; 
            }

            // Comment line 
            if(c == '/'){
                if(fgetc(fp) == '/'){
                    while((c=fgetc(fp)) != '\n') {}
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
            check = 1; // check bit is true now -- initial check completed
            printFile(fp);
        } else if (check == 1) {
            lineNum = 1; 
            while ((c = fgetc(fp)) != EOF) {
                if (c == '\n') {
                    lineNum++;
                }

                // Ignore comment starting with // to the end of line
                if (c == '/') {
                    if (fgetc(fp) == '/') {
                        while ((c = fgetc(fp)) != '\n') {}
                        lineNum++;
                    } else
                        fseek(fp, -1, SEEK_CUR);
                }

                if (isalpha(c)) {
                    words[wordi][wordj++] = c;	
                    while (isalpha(c = fgetc(fp))) {
                        words[wordi][wordj++] = c;	
                    }
                    words[wordi][wordj] = '\0';	
                    wordLineNums[wordi] = lineNum;
                    wordi++; wordj = 0;	
                    fseek(fp, -1, SEEK_CUR);
                } 

                else if (isdigit(c)) {
                    nums[numi][numj++] = c;
                    while (isdigit(c = fgetc(fp))) {
                        nums[numi][numj++] = c;
                    }
                    nums[numi][numj] = '\0';
                    numLineNums[numi] = lineNum;
                    numi++; numj = 0;
                    fseek(fp, -1, SEEK_CUR);
                }

                else if (ispunct(c)) {
                    if (eligibleDelimiter(c)) {
                        delims[delimi] = c;
                        delimLineNums[delimi] = lineNum;
                        delimi++;
                    } 
                    else if (eligibleOp(c)) {
                        otherOps[otherOpi] = c;
                        otherOpLineNums[otherOpi] = lineNum;
                        otherOpi++;
                    }
                    else if (eligibleRelationalOp(c)) {
                        if (c == '<' || c == '>') {
                            relOps[relOpi][relOpj++] = c;
                            relOps[relOpi][relOpj] = '\0';
                            relOpLineNums[relOpi] = lineNum;
                            relOpi++; relOpj = 0;
                        }
                        else if (c == '=') {
                            if ((c = fgetc(fp)) == '=' || c == '>' || c == '<') {
                                relOps[relOpi][relOpj++] = '=';	
                                relOps[relOpi][relOpj++] = c;	
                                relOps[relOpi][relOpj] = '\0';
                                relOpLineNums[relOpi] = lineNum;
                                relOpi++; relOpj = 0;
                            } else if (c == '!') {
                                if ((c = fgetc(fp)) == '=') {
                                    relOps[relOpi][relOpj++] = '=';
                                    relOps[relOpi][relOpj++] = '!';
                                    relOps[relOpi][relOpj++] = c;	
                                    relOps[relOpi][relOpj] = '\0';
                                    relOpLineNums[relOpi] = lineNum;
                                    relOpi++; relOpj = 0;
                                } else {
                                    fseek(fp, -1, SEEK_CUR);
                                }
                            } else {
                                fseek(fp, -1, SEEK_CUR);
                            }
                    
                        }
                    }
                }
            } // end while            
        } else {
            printf("Unexpected error, exiting...!");
            exit(EXIT_FAILURE);
        }
    }
    rewind(fp);
    return EOT; // return token
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
    
    TokenType token = UNDEF; 
    while ((token = getToken(fp)) != EOT) {}
    
    fclose(fp);
    exit(EXIT_SUCCESS); 
    return 0; // Should never reach here
}