
#ifndef GBMPRICING_BINOMIAL_H
#define GBMPRICING_BINOMIAL_H

#include <cmath>
#include <vector>
#include <algorithm>

/**
 * Binomial lattice model is based on the description of an underlying instrument over a period of time rather than a single point.
 * As a consequence, it is used to value American options that are exercisable at any time in a given interval,
 * as well as Bermudan options that are exercisable at specific instances of time.
 *
 * Although computationally slower than the Black–Scholes formula, it is more accurate,
 * particularly for longer-dated options on securities with dividend payments.
 */
class Binomial {
public:

    static double americanCall_buggy(const double& S, // spot price
                                  const double& K, // exercice price
                                  const double& r, // interest rate (per period)
                                  const double& sigma, // volatility
                                  const double& T,   // time to expire, number of years
                                  double u, // up movement
                                  double d, // down movement
                                  const int& no_periods); // no steps in binomial tree

    /**
     * Calculate American Put option price
     *
     * @param T  Expiration time in years
     * @param S  Stock price
     * @param K  Strike price
     * @param r  Risk-free interest rate
     * @param sigma  Volatility
     * @param d  Dividend yield
     * @param n  Height of the binomial tree
     * @return  American put option price
     */
    static double americanCall(double T, double S, double K, double r, double sigma, double d, double n);

    /**
     * Calculate American Put option price
     *
     * @param T  Expiration time in years
     * @param S  Stock price
     * @param K  Strike price
     * @param r  Risk-free interest rate
     * @param sigma  Volatility
     * @param d  Dividend yield
     * @param n  Height of the binomial tree
     * @return  American put option price
     */
    static double americanPut(double T, double S, double K, double r, double sigma, double d, double n);
};


#endif //GBMPRICING_BINOMIAL_H
