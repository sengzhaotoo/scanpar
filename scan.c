#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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

void check(FILE *fp){
    int lineNum, valid; 
    char c; 
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
    }
    rewind(fp);
}


int main(int argc, char *argv[]){
    FILE *fp; 
    char *file; 

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
    printFile(fp);
    fclose(fp);
    exit(EXIT_SUCCESS); 
    return 0; // Should never reach here
}