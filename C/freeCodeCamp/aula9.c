#include <stdio.h>

//declare functions
int funcSum(int num1, int num2);

//main function
int main(int argc, char const *argv[]){
	
	int num1 = 1;
	int num2 = 2;


 	int res = funcSum(num1, num2);

 	printf("%d \n", res);

	return 0;
}

//the altualy code of the declare function
//normaly tha function must be before the main function
int funcSum(int num1, int num2){
	return num1 + num2;
}