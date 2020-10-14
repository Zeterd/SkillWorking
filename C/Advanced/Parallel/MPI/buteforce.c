#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  int length;

  printf("Enter you length of code: ");
  scanf("%d", &length);

  char input[length];

  printf("Enter you code(10 digits): ");
  scanf("%s", input);

  char guess[length];
  int flag = 0;
  clock_t startClock = clock();
  while(1){
    flag = 0;
    for(int i=0; i<length; i++){
      int x = rand()%10;
      guess[i] = x + '0';
    }
    for(int i=0; i<length; i++){
      if(guess[i] != input[i]){
        flag = 1;
      }
    }

    if(!flag) {
      printf("Code was chracked!!\n");
      break;
    }

  }
  clock_t finishClock = clock();
  printf("%ld", (finishClock - startClock) / CLOCKS_PER_SEC);

  return 0;
}
