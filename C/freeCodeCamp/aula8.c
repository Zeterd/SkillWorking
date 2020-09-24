#include <stdio.h>

int main(int argc, char const *argv[]){
	
	int lucky_num[] = {1,2,3,4,5};

	printf("%d\n", lucky_num[3]);

	lucky_num[4] = 56;

	printf("%d\n", lucky_num[4]);


	return 0;
}