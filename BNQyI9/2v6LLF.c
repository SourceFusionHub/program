#include<stdio.h>
int main(){
    int N;
    printf("Enter the limit of the fibonacci series: ");
    scanf("%i",&N);
    int fibo[N];
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<N;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    for(int i=0;i<N;i++){
        printf("%i ",fibo[i]);
    }
    return 0;
}
