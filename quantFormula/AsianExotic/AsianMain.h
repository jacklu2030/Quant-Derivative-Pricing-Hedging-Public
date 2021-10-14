
#ifndef GBMPRICING_ASIANMAIN_H
#define GBMPRICING_ASIANMAIN_H

#include <vector>
#include "../Data.h"
#include "Payoff.h"
#include "PathGenerator.h"
#include "AsianExoticOption.h"

/**
 * Because of the averaging feature, Asian options reduce the volatility inherent in the option; therefore,
 * Asian options are typically cheaper than European or American options.
 *
 * Asian exotic option was originally created for fixed income derivatives / commodity options
 */
class AsianMain {
public:
    static double calcCallPrice(ASIAN_OPTION_SUM_TYPE sumType, const unsigned & num_sims, const unsigned & num_intervals, const OptionInput& in);
    static double calcPutPrice(ASIAN_OPTION_SUM_TYPE sumType, const unsigned & num_sims, const unsigned & num_intervals, const OptionInput& in);
};


#endif //GBMPRICING_ASIANMAIN_H
