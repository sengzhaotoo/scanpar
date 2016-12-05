# scanpar
C-like scanner and parser that takes in C file and analyses the file itself. 

### Create executable
Right now, I am just using gcc scan.c parser.c, as I can't figure out how to make the Makefile do it right

gcc scan.c parser.c
### [Updated] Make   
```
gcc scan.c parser.c
```

### [Old] Make
``` 
make 
```



### [Updated] Run   
#### Parser Only
```
./a.out test.c
```

#### Parser & Scanner 
```
./a.out test.c y
``` 
The 'y' refers to yes for parsing. 

### [Old] Run   
```
./scan [insert file name with extensions] 
./scan test.c
```
