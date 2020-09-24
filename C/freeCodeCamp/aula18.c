#include <stdio.h>

int main(int argc, char const *argv[]){
	
	int age = 34;

	printf("Adress: %p\n", &age); //address of age in memory

	int *pAge = &age;

	printf("Age: %d\n", *pAge);


	return 0;
}