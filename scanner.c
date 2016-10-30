#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  FILE *fp; 
  char c; 

  // Check if file exists and is not emtpy 
  if((fp = fopen(argv[1],"r")) == NULL){
    if(ftell(fp) == 0){
      printf("File is empty.\n");
    } else {
      printf("File does not exist or corrupted.\n");
    }
    exit(EXIT_FAILURE);
  }
  
  // Read contents and print 
  c = fgetc(fp);
  while(c!=EOF){
    printf("%c",c);
    c = fgetc(fp);
  }
  
  fclose(fp);
  exit(EXIT_SUCCESS);
  return 0; // Should not reach here
}