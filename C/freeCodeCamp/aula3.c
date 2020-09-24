#include <stdio.h>

int main(int argc, char const *argv[]) {
	
	int age = 23;
	float grade = 4.5;

	char nameP[] = "Peter";
	char nameJ[] = "John";



	printf("My name is %s and i'm %d years old\n", nameP, age);
	printf("%s had %.2f out of 5 in a test and i got mad about him!\n", nameJ, grade);


	return 0;
}