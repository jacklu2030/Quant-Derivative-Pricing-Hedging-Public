
#ifndef GBMPRICING_EUROPEANOPTION_H
#define GBMPRICING_EUROPEANOPTION_H

#include <cmath>
#include "../Data.h"
#include "../Distribution.h"

/**
 * In this class, we try to use Analytic method to solve the Black-Scholes model
 * We will try numerical method later to solve Black-Scholes model.
 *
 * BSM assumes that:
 * 1) risk-free rate is constant, volatility is constant;
 * 2) the underlying asset prices S follow Geometric Brownian Motion (GBM), which are log-normal distribution.
 *    However, under GBM, asset / stock price return is generally normal bell curve distribution, with mean = 0
 *
 * In probability theory, a log-normal (or lognormal) distribution is a continuous
 * probability distribution of a random variable whose logarithm is normally distributed.
 * Thus, if the random variable X is log-normally distributed, then Y = ln(X) has a normal distribution.
 * Equivalently, if Y has a normal distribution, then the exponential function of Y, X = exp(Y), has a log-normal distribution.
 *
 * Analytic solution (under Itô's interpretation):
 */
class EuropeanOption {
public:
    EuropeanOption(const OptionInput& in);
    double call_price();
    double call_price(double S , double K, double r, double v, double T);
    double put_price();
    double put_price(double S , double K, double r, double v, double T);

private:
    double K;     // option strike price
    double S;     // underlying asset spot price
    double r = 0.0;     // risk-free interest rate per year
    double v = 0.0;     // volitility
    double T = 0.0;     // time to expire, year

    Distribution dist;
};


#endif //GBMPRICING_EUROPEANOPTION_H
