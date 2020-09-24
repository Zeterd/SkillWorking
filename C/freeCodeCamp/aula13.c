#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	char name[20];
	char major[20];
	int age;
	double gpa;
};

int main(int argc, char const *argv[]){
	
	struct Student stu;

	stu.age = 23;
	strcpy(stu.name, "Josefi");
	strcpy(stu.major, "Informatics");
	stu.gpa = 3.2;

	printf("This is %s and is %d years old.\n", stu.name, stu.age);
	printf("His major is %s and have a gpa of %f\n", stu.major, stu.gpa);
	
	return 0;
}