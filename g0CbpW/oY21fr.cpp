#include<stdio.h>
int main(){
   int n,i;
   int fact,rem;
   printf("
Enter a number : ");
   scanf("%d",&n);
   printf("
");
   int sum = 0;
   int temp = n;
   while(n){
      i = 1,fact = 1;
      rem = n % 10;
      while(i <= rem){
         fact = fact * i;
         i++;
      }
      sum = sum + fact;
      n = n / 10;
   }
   if(sum == temp)
      printf("%d is a strong number
",temp);
   else
      printf("%d is not a strong number
",temp);
   return 0;
}
