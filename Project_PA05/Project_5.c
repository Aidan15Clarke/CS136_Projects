// header files
#include "Console_IO_Utility.h"

// global constants
    //AZ taxes
        // AZ tax Baseline RATE
const double AZ_TAX_BASELINE_RATE = 0.0259;
        // AZ tax Baseline LIMIT
const double AZ_TAX_BASELINE_LIMIT = 27808.5;
        // AZ tax First bracket RATE
const double AZ_TAX_FIRST_BRACKET_RATE = 0.0334;
        // AZ tax First bracket LIMIT
const double AZ_TAX_FIRST_BRACKET_LIMIT = 55615.5;
        // AZ tax Second bracket RATE
const double AZ_TAX_SECOND_BRACKET_RATE = 0.0417;
        // AZ tax Second bracket LIMIT
const double AZ_TAX_SECOND_BRACKET_LIMIT = 166843.5;
        // AZ tax MAX bracket RATE
const double AZ_TAX_MAX_RATE = 0.045;

    // Federal taxes
        // Minimum FED Tax RATE
const double FED_TAX_BASELINE_RATE = 0.1000;
        // FED tax Baseline LIMIT
const double FED_TAX_BASELINE_LIMIT = 10275.5;
        // FED tax First bracket RATE
const double FED_TAX_FIRST_BRACKET_RATE = 0.1200;
        // FED tax First bracket LIMIT
const double FED_TAX_FIRST_BRACKET_LIMIT = 41775.5;
        // FED tax Second bracket RATE
const double FED_TAX_SECOND_BRACKET_RATE = 0.2200;
        // FED tax Second bracket LIMIT
const double FED_TAX_SECOND_BRACKET_LIMIT = 89075.5;
        // FED tax Third bracket RATE
const double FED_TAX_THIRD_BRACKET_RATE = 0.2400;
        // FED tax Third bracket LIMIT
const double FED_TAX_THIRD_BRACKET_LIMIT = 170050.5;
        // FED tax Fourth bracket RATE
const double FED_TAX_FOURTH_BRACKET_RATE = 0.3200;
        // FED tax Fourth bracket LIMIT
const double FED_TAX_FOURTH_BRACKET_LIMIT = 215950.5;
        // FED tax Fifth bracket RATE
const double FED_TAX_FIFTH_BRACKET_RATE = 0.3500;
        // FED tax Fifth bracket LIMIT
const double FED_TAX_FIFTH_BRACKET_LIMIT = 539900.5;
        // AZ tax MAX bracket RATE
const double FED_TAX_MAX_RATE = 0.3700;

    // Other Taxes
        // SSN Tax RATE
const double TAX_SSN = 0.0620;
        // MC Tax RATE
const double TAX_MC = 0.0145;


    // Percent Conversion, ratio
const double PERCENTAGE_CONVERSION = 100;

    // printing related constants
const int TWO_ENDLINES = 2;
    // constants for table
const int TABLE_WIDTH = 46;
const int DATA_NAME_WIDTH = 20;
const int UNIT_WIDTH = 7;
const int VALUE_WIDTH = 15;
const char TOP_LINE[]
                = "==============================================";
const char THICK_LINE_DIVIDER[]
                = "|============================================|";
const char THIN_LINE_DIVIDER[]
                = "|--------------------------------------------|";
const char PIPE_SPACE[] = "| ";
const char SPACE_PIPE[] = " |";

// function prototypes
double calculateFederalTax( double adjustedIncome );
double calculateArizonaTax( double adjustedIncome );

void displayResultsTable( double taxArizona, double taxFederal,
                          double incomeAfterTaxes, double effectiveTax,
                          double taxTotal, double incomeLocked);

// main program
int main()
    {
    // TODO: Write program as specified
    // show title
        // function: printString, printEndline(s)
    printEndline();
    printString( "Dummy tax calculator V0.3" );
    printEndline();
    printString( TOP_LINE );
    printEndlines( TWO_ENDLINES );

    // initialize variables/functions
    double totalIncome, contributionToIRA, adjustedIncome;
    double taxFederal, taxArizona;
    double taxSSN, taxMC, taxTotal;
    double incomeAfterTaxes;
    double effectiveTax, incomeLocked;

    // get user input
       // section title
           // function: printString, printEndline
    printString( "Provide your Tax information below." );
    printEndline();

        // total income $
            // function: promptForDouble
    totalIncome = promptForDouble("Total income $: ");

        // IRA contributions $
            // function: promptForDouble
    contributionToIRA = promptForDouble("Your IRA contributions $: ");

    // conduct computations
        // adjust income by IRA contributions, $
    adjustedIncome = totalIncome - contributionToIRA;

        // calculate federal tax, $
    taxFederal = calculateFederalTax(adjustedIncome);

        // calculate AZ tax, $
    taxArizona = calculateArizonaTax(adjustedIncome);

        // calculate SSN tax, $
    taxSSN = adjustedIncome * TAX_SSN;

        // calculate MC tax, $
    taxMC =  adjustedIncome * TAX_MC;

        // calculate Total tax to be payed, $
    taxTotal = taxFederal + taxArizona + taxSSN + taxMC;

        // calculate Income after Tax, $
    incomeAfterTaxes = totalIncome - taxTotal;

        // calculate effective tax rate, %
    effectiveTax = taxTotal / totalIncome;

        // calculate % of income locked in IRA, %
    incomeLocked = (contributionToIRA / totalIncome) * PERCENTAGE_CONVERSION;

    // display results
    displayResultsTable( taxArizona, taxFederal,
                         incomeAfterTaxes, effectiveTax,
                         taxTotal, incomeLocked);

    // end program / return program success
    return 0;
    }

// supporting functions
    // TODO


/*
Name: calculateArizonaTax
Process: calculates total marginal Arizona tax based on adjusted income
Function Input/Parameters: adjustedIncome
Function Output/Parameters: none
Function Output/Returned: total arizona tax
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: none
*/
double calculateArizonaTax( double adjustedIncome )
  {
    // marginal Arizona tax amount
    double arizonaTax;

    // check if in baseline bracket
    if( adjustedIncome < AZ_TAX_BASELINE_LIMIT )
      {
        // calculate base tax
        arizonaTax = adjustedIncome * AZ_TAX_BASELINE_RATE;
      }
    // check if in first bracket
    else if( adjustedIncome < AZ_TAX_FIRST_BRACKET_LIMIT )
      {
        // calculate marginal Arizona tax
          // calculate base tax
        arizonaTax = AZ_TAX_BASELINE_LIMIT * AZ_TAX_BASELINE_RATE;
          // calculate first bracket marginal tax
        arizonaTax += (adjustedIncome - AZ_TAX_BASELINE_LIMIT)
                                                * AZ_TAX_FIRST_BRACKET_RATE;
      }
    // check if in second bracket
    else if( adjustedIncome < AZ_TAX_SECOND_BRACKET_LIMIT )
      {
        // calculate marginal Arizona tax
          // calculate base tax
        arizonaTax = AZ_TAX_BASELINE_LIMIT * AZ_TAX_BASELINE_RATE;
          // calculate first bracket marginal tax
        arizonaTax += (AZ_TAX_FIRST_BRACKET_LIMIT - AZ_TAX_BASELINE_LIMIT)
                                                  * AZ_TAX_FIRST_BRACKET_RATE;
          // calculate second bracket marginal tax
        arizonaTax += (adjustedIncome - AZ_TAX_FIRST_BRACKET_LIMIT)
                                                  * AZ_TAX_SECOND_BRACKET_RATE;
      }
    // else, max tax rate
    else
      {
        // calculate marginal Arizona tax
          // calculate base tax
        arizonaTax = AZ_TAX_BASELINE_LIMIT * AZ_TAX_BASELINE_RATE;
          // calculate first bracket marginal tax
        arizonaTax += (AZ_TAX_FIRST_BRACKET_LIMIT - AZ_TAX_BASELINE_LIMIT)
                                                * AZ_TAX_FIRST_BRACKET_RATE;
          // calculate second bracket marginal tax
        arizonaTax +=
          (AZ_TAX_SECOND_BRACKET_LIMIT - AZ_TAX_FIRST_BRACKET_LIMIT)
                                                   * AZ_TAX_SECOND_BRACKET_RATE;
          // calculate max marginal tax
        arizonaTax += (adjustedIncome - AZ_TAX_SECOND_BRACKET_LIMIT)
                                                            * AZ_TAX_MAX_RATE;
      }

    // return results
    return arizonaTax;
  }


/*
Name: calculateFederalTax
Process: calculates total marginal federal tax based on adjusted income
Function Input/Parameters: adjustedIncome
Function Output/Parameters: none
Function Output/Returned: total federal tax
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: none
*/
double calculateFederalTax( double adjustedIncome )
  {
    // store tax amount
    double federalTax;

    // check if in baseline bracket
    if( adjustedIncome < FED_TAX_BASELINE_LIMIT )
      {
        // calculate base tax
        federalTax = adjustedIncome * FED_TAX_BASELINE_RATE;
      }
    // check if in first bracket
    else if( adjustedIncome < FED_TAX_FIRST_BRACKET_LIMIT )
      {
        // calculate marginal Federal tax
          // calculate base tax
        federalTax = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
          // calculate first bracket marginal tax
        federalTax += (adjustedIncome - FED_TAX_BASELINE_LIMIT)
                                                * FED_TAX_FIRST_BRACKET_RATE;
      }
    // check if in second bracket
    else if( adjustedIncome < FED_TAX_SECOND_BRACKET_LIMIT )
      {
        // calculate marginal Federal tax
          // calculate base tax
        federalTax = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
          // calculate first bracket marginal tax
        federalTax += (FED_TAX_FIRST_BRACKET_LIMIT - FED_TAX_BASELINE_LIMIT)
                                                  * FED_TAX_FIRST_BRACKET_RATE;
          // calculate second bracket marginal tax
        federalTax += (adjustedIncome - FED_TAX_FIRST_BRACKET_LIMIT)
                                                  * FED_TAX_SECOND_BRACKET_RATE;
      }
    // check if in third bracket
    else if( adjustedIncome < FED_TAX_THIRD_BRACKET_LIMIT )
      {
        // calculate marginal Federal tax
          // calculate base tax
        federalTax = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
          // calculate first bracket marginal tax
        federalTax += (FED_TAX_FIRST_BRACKET_LIMIT - FED_TAX_BASELINE_LIMIT)
                                                  * FED_TAX_FIRST_BRACKET_RATE;
          // calculate second bracket marginal tax
        federalTax +=
            (FED_TAX_SECOND_BRACKET_LIMIT - FED_TAX_FIRST_BRACKET_LIMIT)
                                                  * FED_TAX_SECOND_BRACKET_RATE;
          // calculate third bracket marginal tax
        federalTax += (adjustedIncome - FED_TAX_SECOND_BRACKET_LIMIT)
                                                  * FED_TAX_THIRD_BRACKET_RATE;
      }
    // check if in fourth bracket
    else if( adjustedIncome < FED_TAX_FOURTH_BRACKET_LIMIT )
      {
        // calculate marginal Federal tax
          // calculate base tax
        federalTax = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
          // calculate first bracket marginal tax
        federalTax += (FED_TAX_FIRST_BRACKET_LIMIT - FED_TAX_BASELINE_LIMIT)
                                                  * FED_TAX_FIRST_BRACKET_RATE;
          // calculate second bracket marginal tax
        federalTax +=
            (FED_TAX_SECOND_BRACKET_LIMIT - FED_TAX_FIRST_BRACKET_LIMIT)
                                                  * FED_TAX_SECOND_BRACKET_RATE;
          // calculate third bracket marginal tax
        federalTax +=
            (FED_TAX_THIRD_BRACKET_LIMIT - FED_TAX_SECOND_BRACKET_LIMIT)
                                                  * FED_TAX_THIRD_BRACKET_RATE;
          // calculate fourth bracket marginal tax
        federalTax += (adjustedIncome - FED_TAX_THIRD_BRACKET_LIMIT)
                                                  * FED_TAX_FOURTH_BRACKET_RATE;
      }
    // check if in fifth bracket
    else if( adjustedIncome < FED_TAX_FIFTH_BRACKET_LIMIT )
      {
        // calculate marginal Federal tax
          // calculate base tax
        federalTax = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
          // calculate first bracket marginal tax
        federalTax += (FED_TAX_FIRST_BRACKET_LIMIT - FED_TAX_BASELINE_LIMIT)
                                                  * FED_TAX_FIRST_BRACKET_RATE;
          // calculate second bracket marginal tax
        federalTax +=
            (FED_TAX_SECOND_BRACKET_LIMIT - FED_TAX_FIRST_BRACKET_LIMIT)
                                                  * FED_TAX_SECOND_BRACKET_RATE;
          // calculate third bracket marginal tax
        federalTax +=
            (FED_TAX_THIRD_BRACKET_LIMIT - FED_TAX_SECOND_BRACKET_LIMIT)
                                                  * FED_TAX_THIRD_BRACKET_RATE;
          // calculate fourth bracket marginal tax
        federalTax +=
            (FED_TAX_FOURTH_BRACKET_LIMIT - FED_TAX_THIRD_BRACKET_LIMIT)
                                                  * FED_TAX_FOURTH_BRACKET_RATE;
          // calculate fifth bracket marginal tax
        federalTax += (adjustedIncome - FED_TAX_FOURTH_BRACKET_LIMIT)
                                                  * FED_TAX_FIFTH_BRACKET_RATE;
      }
    // else, max tax rate
    else
      {
        // calculate marginal Federal tax
          // calculate base tax
        federalTax = FED_TAX_BASELINE_LIMIT * FED_TAX_BASELINE_RATE;
          // calculate first bracket marginal tax
        federalTax += (FED_TAX_FIRST_BRACKET_LIMIT - FED_TAX_BASELINE_LIMIT)
                                                  * FED_TAX_FIRST_BRACKET_RATE;
          // calculate second bracket marginal tax
        federalTax +=
            (FED_TAX_SECOND_BRACKET_LIMIT - FED_TAX_FIRST_BRACKET_LIMIT)
                                                  * FED_TAX_SECOND_BRACKET_RATE;
          // calculate third bracket marginal tax
        federalTax +=
            (FED_TAX_THIRD_BRACKET_LIMIT - FED_TAX_SECOND_BRACKET_LIMIT)
                                                  * FED_TAX_THIRD_BRACKET_RATE;
          // calculate fourth bracket marginal tax
        federalTax +=
            (FED_TAX_FOURTH_BRACKET_LIMIT - FED_TAX_THIRD_BRACKET_LIMIT)
                                                  * FED_TAX_FOURTH_BRACKET_RATE;
          // calculate fifth bracket marginal tax
        federalTax +=
            (FED_TAX_FIFTH_BRACKET_LIMIT - FED_TAX_FOURTH_BRACKET_LIMIT)
                                                  * FED_TAX_FIFTH_BRACKET_RATE;
          // calculate max bracket marginal tax
        federalTax += (adjustedIncome - FED_TAX_FIFTH_BRACKET_LIMIT)
                                                            * FED_TAX_MAX_RATE;
      }
      // return results
      return federalTax;
  }

/*
Name: displayResultsTable
Process: displays (prints) table for tax calculator V0.3
Function Input/Parameters: income after tax, effective tax rate,
                           total tax to be payed, and locked income.
Function Output/Parameters: none
Function Output/Returned: none
Device Input/Keyboard: none
Device Output/Monitor: table as showed in example for PA05
Dependencies: printEndline, printString, printCharacter, printStringJustified,
              printDoubleJustified
*/
void displayResultsTable( double taxArizona, double taxFederal,
                          double incomeAfterTaxes, double effectiveTax,
                          double taxTotal, double incomeLocked )
{
  // print top line
    // functions: printString, printEndline
  printEndline();
  printString( TOP_LINE );
  printEndline();

  // print title and divider line
    // functions: printCharacter, printStringJustified, printEndline
  printCharacter( PIPE );
  printStringJustified( "DUMMY TAX CALCULATIONS", TABLE_WIDTH-2, "CENTER" );
  printCharacter( PIPE );
  printEndline();

  printString( THICK_LINE_DIVIDER );
  printEndline();

  // print data name line and divider line
    // functions: printCharacter, printStringJustified, printEndline
  printString( PIPE_SPACE );
  printStringJustified( "Data Name", DATA_NAME_WIDTH-1, "LEFT" );
  printCharacter( PIPE );

  printStringJustified( "Units", UNIT_WIDTH, "CENTER" );
  printCharacter( PIPE );

  printStringJustified( "Value", VALUE_WIDTH, "CENTER" );
  printCharacter( PIPE );
  printEndline();

  printString( THICK_LINE_DIVIDER );
  printEndline();

  // print Arizona tax line and divider line
    // functions: printCharacter, printStringJustified, printDoubleJustified,
    //            printEndline
  printString( PIPE_SPACE );
  printStringJustified( "AZ Tax", DATA_NAME_WIDTH-1, "LEFT" );
  printCharacter( PIPE );

  printStringJustified( "$", UNIT_WIDTH, "CENTER" );
  printCharacter( PIPE );

  printDoubleJustified( taxArizona, PRECISION, VALUE_WIDTH-1, "RIGHT" );
  printString( SPACE_PIPE );
  printEndline();

  printString( THIN_LINE_DIVIDER );
  printEndline();

  // print Fed tax line and divider line
    // functions: printCharacter, printStringJustified, printDoubleJustified,
    //            printEndline
  printString( PIPE_SPACE );
  printStringJustified( "Fed Tax", DATA_NAME_WIDTH-1, "LEFT" );
  printCharacter( PIPE );

  printStringJustified( "$", UNIT_WIDTH, "CENTER" );
  printCharacter( PIPE );

  printDoubleJustified( taxFederal, PRECISION, VALUE_WIDTH-1, "RIGHT" );
  printString( SPACE_PIPE );
  printEndline();

  printString( THIN_LINE_DIVIDER );
  printEndline();

  // print effective tax line and divider line
    // functions: printCharacter, printStringJustified, printDoubleJustified,
    //            printEndline
  printString( PIPE_SPACE );
  printStringJustified( "Effective Tax Rate", DATA_NAME_WIDTH-1, "LEFT" );
  printCharacter( PIPE );

  printStringJustified( "%", UNIT_WIDTH, "CENTER" );
  printCharacter( PIPE );

  printDoubleJustified( effectiveTax * PERCENTAGE_CONVERSION,
                                            PRECISION, VALUE_WIDTH-1, "RIGHT" );
  printString( SPACE_PIPE );
  printEndline();

  printString( THIN_LINE_DIVIDER );
  printEndline();

  // print tax to be payed line and divider line
    // functions: printCharacter, printStringJustified, printDoubleJustified,
    //            printEndline
  printString( PIPE_SPACE );
  printStringJustified( "Tax To Be Payed", DATA_NAME_WIDTH-1, "LEFT" );
  printCharacter( PIPE );

  printStringJustified( "$", UNIT_WIDTH, "CENTER" );
  printCharacter( PIPE );

  printDoubleJustified( taxTotal, PRECISION, VALUE_WIDTH-1, "RIGHT" );
  printString( SPACE_PIPE );
  printEndline();

  printString( THIN_LINE_DIVIDER );
  printEndline();

  // print income after tax line and divider line
    // functions: printCharacter, printStringJustified, printDoubleJustified,
    //            printEndline
  printString( PIPE_SPACE );
  printStringJustified( "Income After Tax", DATA_NAME_WIDTH-1, "LEFT" );
  printCharacter( PIPE );

  printStringJustified( "$", UNIT_WIDTH, "CENTER" );
  printCharacter( PIPE );

  printDoubleJustified( incomeAfterTaxes, PRECISION, VALUE_WIDTH-1, "RIGHT" );
  printString( SPACE_PIPE );
  printEndline();

  printString( THIN_LINE_DIVIDER );
  printEndline();

  // print locked in IRA line and divider line
    // functions: printCharacter, printStringJustified, printDoubleJustified,
    //            printEndline
  printString( PIPE_SPACE );
  printStringJustified( "Locked in IRA", DATA_NAME_WIDTH-1, "LEFT" );
  printCharacter( PIPE );

  printStringJustified( "%", UNIT_WIDTH, "CENTER" );
  printCharacter( PIPE );

  printDoubleJustified( incomeLocked, PRECISION, VALUE_WIDTH-1, "RIGHT" );
  printString( SPACE_PIPE );
  printEndline();

  printString( THICK_LINE_DIVIDER );
  printEndline();
}
