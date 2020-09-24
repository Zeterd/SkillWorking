#include <stdio.h>

int main(int argc, char const *argv[]){
	
	int guess;
	int secretNum = 4;
	int guessCont = 0;

	while(guess != secretNum && guessCont < 5){
		printf("What is the number? ");
		scanf("%d", &guess);
		guessCont++;
	}

	if(guessCont >= 5){
		printf("You lose!!\n");
	}
	else{
		printf("You win!!\n");
	}

	return 0;
}