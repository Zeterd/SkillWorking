#include <stdio.h>

int main(int argc, char const *argv[]){
	
	int num;

	printf("Enter your number: ");
	scanf("%d", &num);

	// this is kinda dumb...

	switch(num%2){
	case 0:
		printf("It's a even number!!\n");
		break;
	case 1:
		printf("It's a odd number!!\n");
		break;
	default:
		printf("Something went wrong!!\n");

	}

	return 0;
}