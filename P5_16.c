// Exercise 5.16 Solution 
#include <stdio.h>

int integerPower( int b, int e );

int main()
{ 
   int exp; // integer exponent 
   int base; // integer base 

   printf( "%s", "Enter integer base and exponent: " );
   scanf( "%d%d", &base, &exp );

   printf( "%d to the power %d is: %d\n",
      base, exp, integerPower( base, exp ) );
} // end main 

// integerPower calculates and returns b raised to the e power 
int integerPower( int b, int e )
{ 
   int product = 1; // resulting product 
   unsigned int i; // loop counter 

   // multiply product times b (e repetitions) 
   for ( i = 1; i <= e; ++i ) {
      product *= b;
   } // end for 

   return product; // return resulting product 
} // end function integerPower 





