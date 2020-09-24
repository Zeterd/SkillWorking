#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	
	double num1;
	double num2;

	printf("Enter your first number: ");
	scanf("%lf", &num1);

	printf("Enter your second number: ");
	scanf("%lf", &num2);

	printf("Result of %lf + %lf = %lf\n", num1, num2, num1+num2);

	return 0;
}