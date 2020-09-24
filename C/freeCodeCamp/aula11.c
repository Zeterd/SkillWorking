#include <stdio.h>

int main(int argc, char const *argv[]){
	
	double num1;
	double num2;
	char op;

	printf("Enter your first number: ");
	scanf("%lf", &num1);

	printf("Enter your second number: ");
	scanf("%lf", &num2);

	printf("Enter your operator: ");
	scanf(" %c", &op);
	
	if(op == '+'){
		printf("Result: %f\n", num1+num2);
	}
	else if(op == '-'){
		printf("Result: %f\n", num1-num2);
	}
	if(op == '-'){
		printf("Result: %f\n", num1*num2);
	}
	if(op == '/'){
		printf("Result: %.2f\n", num1/num2);
	}
	else{
		printf("Operator not valid!!\n");
	}

	return 0;
}