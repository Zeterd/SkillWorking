#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	
	FILE *f = fopen("test.txt", "w");

	fprintf(f, "Hello boyyyyyy");

	fclose(f);

	FILE *file2 = fopen("test.txt", "r");
	char line[255];

	fgets(line, 255, file2);
	printf("%s\n", line);

	fclose(file2);

	return 0;
}