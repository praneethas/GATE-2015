#include<stdio.h>

/* simple recursive program for Fibonacci numbers */
int fib(int n)
{
   if ( n <= 1 )
      return n;
   return fib(n-1) + fib(n-2);
}

int main(){
	printf("Fibonacci of 4 is %d", fib(4));
	return 0;
}