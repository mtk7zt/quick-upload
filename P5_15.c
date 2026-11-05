// Exercise 5.15 Solution 
#include <stdio.h>
#include <math.h>

double hypotenuse( double s1, double s2 ); // function prototype 

int main()
{ 
   unsigned int i; // loop counter 
   double side1; // value for first side 
   double side2; // value for second side 
   
   // loop 3 times 
   for ( i = 1; i <= 3; ++i ) { 
      printf( "%s", "Enter the sides of the triangle: " );
      scanf( "%lf%lf", &side1, &side2 );

      // calculate and display hypotenuse value 
      printf( "Hypotenuse:  %.1f\n\n", hypotenuse( side1, side2 ) );
   } // end for 
} // end main  

// hypotenuse calculates value of hypotenuse of
// a right triangle given two side values 
double hypotenuse( double s1, double s2 )
{ 
   return sqrt( pow( s1, 2 ) + pow( s2, 2 ) );
} // end function hypotenuse 



 