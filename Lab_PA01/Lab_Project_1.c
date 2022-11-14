// header files
#include "Console_IO_Utility.h"
#include <math.h>
#include <stdio.h>

// global constants
const double PERCENTAGE_CONVERSION = .01;

const int FOUR_DIGITS = 4;
const int MONTHS_IN_YEAR = 12;
const int TWO_DIGITS = 2;
const int TWO_ENDLINES = 2;

const char PERCENT_CHAR = '%';

// prototypes
   // none

// main program
int main()
   {
    // initialize function/variables

       // initialize variables
       double borrowedAmount, monthlyInterestRate;
       double paymentNumerator, paymentDenominator;
       double monthlyPayment;
       int numMonths;

       // show title
          // function: printString, printEndline(s)
       printEndline();
       printString( "Monthly Payment Calculator" );
       printEndline();
       printString( "==========================" );
       printEndlines( TWO_ENDLINES );

    // get input

       // show data entry
          // function: printString, printEndline(s)
       printString( "Data Entry" );
       printEndline();
       printString( "----------" );
       printEndlines( TWO_ENDLINES);

       // get borrowed amount
          // function: promptForDouble
       borrowedAmount
                    = promptForDouble( "Enter the borrowed amount      ($): " );

       // get monthly interest rate
          // function: promptForDouble
       monthlyInterestRate
                   = promptForDouble(  "Enter the monthly interest rate(%): " );

       // get number of months
          // function: promptForInteger
       numMonths = promptForInteger(  "Enter the number of months     (M): " );

    // process data, calculate payment

       // calculate payment numerator
          // funtion: pow
       monthlyInterestRate = monthlyInterestRate / 100;
       paymentNumerator = monthlyInterestRate *
          pow((1 + monthlyInterestRate), numMonths);

       // calculate payment denominator
          // function: pow
       paymentDenominator = pow((1 + monthlyInterestRate), numMonths) - 1;

       // calculate payment
       monthlyPayment = borrowedAmount *
          (paymentNumerator / paymentDenominator);

    // show results

       // show title
          // functions: printString, printEndline(s)
       printEndline();
       printString( "Calculation Results" );
       printEndline();
       printString( "-------------------" );
       printEndline();

       // show borrowed amount
          // functions: printString, printDouble, printEndline(s)
       printEndline();
       printString( "Total Borrowed Amount : $" );
       printDouble( borrowedAmount, TWO_DIGITS );
       printEndline();

       // show monthly interest rate
          // functions: printString, printDouble, printCharacter, printEndline(s)
       printEndline();
       printString( "Monthly Interest Rate : " );
       printDouble( monthlyInterestRate, FOUR_DIGITS );
       printCharacter( PERCENT_CHAR );
       printEndline();

       // show monthly payment
          // functions: printString, printDouble, printEndline(s)
       printEndline();
       printString( "Monthly Payment       : $" );
       printDouble( monthlyPayment, TWO_DIGITS );
       printEndline();

    // end program

       // show end program
          // function: printString, printEndline
       printEndline();
       printString( "End Program" );
       printEndline();

       // return program success
       return 0;
   }


// supporting functions
   // none
