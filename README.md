# scanpar
C-like scanner and parser that takes in C file and analyses the file itself. 

### Create executable
Right now, I am just using gcc scan.c parser.c, as I can't figure out how to make the Makefile do it right

gcc scan.c parser.c

//OLD
``` 
make 
```
### Run  

./a.out test.c
to run JUST the scanner

./a.out test.c y
to run the PARSER AND the SCANNER

'y' just for like yes I want to parse too please n thank you

//OLD
```
./scan [insert file name with extensions] 
./scan test.c
```
