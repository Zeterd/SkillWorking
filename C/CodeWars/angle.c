#include <stdio.h>

int angle(int n){
    return (n-2)*180;
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%d\n", angle(n));
    return 0;
}