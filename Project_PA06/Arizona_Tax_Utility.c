// Header files included
#include "Arizona_Tax_Utility.h"

// Global constants

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

// Function Implementations

/*
Name: calculateArizonaTax
Process: calculates total marginal Arizona tax based on adjusted income
Function Input/Parameters: income
Function Output/Parameters: none
Function Output/Returned: total arizona tax
Device Input/Keyboard: none
Device Output/Monitor: none
Dependencies: none
*/

double calculateArizonaTax( double income )
  {
    // marginal Arizona tax amount
    double arizonaTax;

    // check if in baseline bracket
    if( income < AZ_TAX_BASELINE_LIMIT )
      {
        // calculate base tax
        arizonaTax = income * AZ_TAX_BASELINE_RATE;
      }
    // check if in first bracket
    else if( income < AZ_TAX_FIRST_BRACKET_LIMIT )
      {
        // calculate marginal Arizona tax
          // calculate base tax
        arizonaTax = AZ_TAX_BASELINE_LIMIT * AZ_TAX_BASELINE_RATE;
          // calculate first bracket marginal tax
        arizonaTax += (income - AZ_TAX_BASELINE_LIMIT)
                                                * AZ_TAX_FIRST_BRACKET_RATE;
      }
    // check if in second bracket
    else if( income < AZ_TAX_SECOND_BRACKET_LIMIT )
      {
        // calculate marginal Arizona tax
          // calculate base tax
        arizonaTax = AZ_TAX_BASELINE_LIMIT * AZ_TAX_BASELINE_RATE;
          // calculate first bracket marginal tax
        arizonaTax += (AZ_TAX_FIRST_BRACKET_LIMIT - AZ_TAX_BASELINE_LIMIT)
                                                  * AZ_TAX_FIRST_BRACKET_RATE;
          // calculate second bracket marginal tax
        arizonaTax += (income - AZ_TAX_FIRST_BRACKET_LIMIT)
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
        arizonaTax += (income - AZ_TAX_SECOND_BRACKET_LIMIT)
                                                            * AZ_TAX_MAX_RATE;
      }

    // return results
    return arizonaTax;
  }
