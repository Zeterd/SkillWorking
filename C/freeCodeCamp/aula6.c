#include <stdio.h>

int main(int argc, char const *argv[]){
	/*
	int age;

	printf("Please enter your age: ");
	scanf("%d", &age);
	printf("Yor age is %d\n", age);
	*/
	char name[20];

	printf("Enter your name: ");
	fgets(name, 20, stdin);
	printf("My name is: %s\n", name);


	return 0;
}