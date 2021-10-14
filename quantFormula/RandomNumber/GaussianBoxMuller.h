
#ifndef GBMPRICING_GAUSSIANBOXMULLER_H
#define GBMPRICING_GAUSSIANBOXMULLER_H

#include <cmath>
#include <limits>
#include <random>
#include <utility>
#include "iostream"

/*
 * A Box Muller transform takes a continuous, two dimensional uniform distribution,
 * and transforms it to a normal distribution (Bell Curve).
 *
 * 1. A uniform distribution, also called a rectangular distribution, is a probability distribution that has constant probability.

      This distribution is defined by two parameters, a and b:

          a is the minimum.
          b is the maximum.
      The distribution is written as U(a, b). Probability is evenly distributed between a and b.
      E.g. a = 1, b = 3, meaning a <= x <= 3, y must be 0.5. Like all probability distributions for continuous random variables,
      the area under the graph of a random variable is always equal to 1. In this example (3 - 1) * 0.5 = 1

      https://www.statisticshowto.com/probability-and-statistics/statistics-definitions/uniform-distribution/

 *    It is widely used in statistical sampling, and is an easy to run, elegant way to come up with a standard normal model.
 */
class GaussianBoxMuller {
public:

    /**
     * A simple implementation of the Box−Muller algorithm , used to generate
     * gaussian random numbers − necessary for the Monte Carlo method below
     * gaussian random numbers is normal distributed (bell curve), mostly with mean = 0.
     * @return gaussian random numbers
     */
    static double gaussian_box_muller();

    /**
     * The standard Box–Muller transform generates values from the standard normal distribution
     * (i.e. standard normal deviates) with mean 0 and standard deviation 1.
     *
     * The implementation below in standard C++ generates values from any normal distribution with
     * mean \mu and variance sigma^2 (a^2). If Z is a standard normal deviate, then X=Za + mu will have a normal distribution
     * with mean {\displaystyle \mu }\mu  and standard deviation {\displaystyle \sigma }\sigma .
     * Note that the random number generator has been seeded to ensure that new, pseudo-random values
     * will be returned from sequential calls to the generateGaussianNoise function.
     *
     * @param mu - drift rate
     * @param sigma (a) - Volatility
     * @return
     */
    static std::pair<double, double> generate_gaussian_noise(double mu, double sigma);

    void testRun(double mu, double sigma);
};


#endif //GBMPRICING_GAUSSIANBOXMULLER_H
