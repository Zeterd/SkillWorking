#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main(int argc, char const *argv[]){

	for(int i=1; i<MAX; i++){
	    for(int j=1; j<MAX; j++){
			double cont = (1+1+5+i+j)/5;
			if(cont == 4){
				printf("Number: %d %d\n", i, j);
				printf("Product: %d\n", (j*i*5));
			}
		}
	}

	return 0;
}

/* x x x x x
 Media = 4
 Moda = 1
 Mediano = 5
	
	Logo sabemos que o valor do meio é 5, entao:

	x x 5 x x

	Sabemos tambem que 1 é moda ou seja aparece 2 ou 3 vezes o valor 1

	1 1 5 x x ou 1 1 5 1 x
*/