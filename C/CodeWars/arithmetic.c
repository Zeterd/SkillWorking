#include <stdio.h>
#include <stdlib.h>

int main(){

    int a = 5, b = 2;
    char* op = "multiply";

    if(strcmp(op, "multiply") == 0){
        printf("%d\n", a*b);
    }
    else if(strcmp(op, "add") == 0){
        printf("%d\n", a+b);
    }
    else if(strcmp(op, "subtract") == 0){
        printf("%d\n", a-b);
    }
    else{
        printf("%d\n", a/b);
    }

    return 0;
}

/*
BEST CLEVER SOLUTION

double arithmetic(double a, double b, char* operator) {
  switch(operator[0]){
      case 'a':
         return a+b;
      case 's':
         return a-b;
      case 'm':
          return a*b;
      case 'd':
          return a/b; 
  }
}



*/