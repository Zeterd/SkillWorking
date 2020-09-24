#include <stdio.h>

int main(int argc, char const *argv[]){
	
	char grade;

	scanf("%c", &grade);

	if(grade == 'A'){
		printf("Well done!!\n");
	}
	else if(grade == 'B'){
		printf("Good!\n");
	}
	else if(grade == 'C' || grade == 'D'){
		printf("Come on, you can do it better.\n");
	}
	else{
		printf("Damm, thats sucks...\n");
	}

	return 0;
}