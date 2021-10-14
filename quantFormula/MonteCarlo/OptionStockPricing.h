
#ifndef GBMPRICING_OPTIONSTOCKPRICING_H
#define GBMPRICING_OPTIONSTOCKPRICING_H

#include <cmath>
#include <algorithm>
#include "../Data.h"

/**
 *
 * Put-Call Parity:
 *      C + PV(x) = P + S
 *      C + K = P + S
 *      PV(x) = the present value of the strike price (x), discounted from the value on the expiration date at the risk-free rate
 */
class OptionStockPricing {
public:
    explicit OptionStockPricing(const OptionInput& in);

    double monte_carlo_call_price(const int& num_sims);
    double monte_carlo_put_price(const int& num_sims);

    /**
    * Stock pricing using monte carlo / Geometric Brownian Motion (GBM)
    *
    * Note: Gaussian random number gauss_bm is normal (bell curve) distribution, it meets GBM requirement.
    *
    * The biggest issue is, sigma/volatilit is constant here. In reality, it varies a lot.
    * A smaller issue is, risk-free rate is constant here.
    *
    * @param num_sims -- Number of Monto Carlo simulation
    * @return Stock spot price, adjusted by risk-free rate to current value
    */
    double monte_carlo_stock_price(const int& num_sims);

    double monte_carlo_price(const int& num_sims);

    // A simple implementation of the Box−Muller algorithm , used to generate
    // gaussian random numbers − necessary for the Monte Carlo method below
    // Note that C++11 actually provides std : : normaldistribution <> in
    // the library , which can be used instead of this function
    double gaussian_box_muller( );

private:
    double K = 0.0;     // option strike price
    double S = 0.0;     // underlying asset spot price
    double r = 0.0;     // risk-free interest rate per year
    double v = 0.0;     // volitility
    double T = 0.0;     // time to expire, year
};


#endif //GBMPRICING_OPTIONSTOCKPRICING_H
