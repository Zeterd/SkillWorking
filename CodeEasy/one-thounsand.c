#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int verfy(int x, int arr[]){
	if(arr[x] != 0)
		return 0;
	else
		return 1;
}

int main(int argc, char const *argv[]){

	int i,j;
	int cont=0;
	int arr[MAX+1];

	for(i=1; i<=MAX; i++){
		arr[i] = 0;
	}

	for(i=1; i<=MAX; i++){
		for(j=1; j<=MAX; j++){
			if(i+j == MAX && verfy(i,arr) && verfy(j,arr)){
				arr[i] = arr[j] = 1;
				printf("%d + %d = %d\n", i, j, (i+j));
				cont++;
			}
		}
		
	}
	printf("%d\n", cont);
	
	return 0;
}