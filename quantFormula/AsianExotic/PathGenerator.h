#ifndef GBMPRICING_PATHGENERATOR_H
#define GBMPRICING_PATHGENERATOR_H

#include <vector>
#include <cmath>
#include "../RandomNumber/GaussianBoxMuller.h"

class PathGenerator {
public:
    // A vector containing sampled points of a
    // Geometric Brownian Motion stock price paths
    static void calc_path_spot_prices(std::vector<double>& spot_prices , // Asset path
            const double& r, // Risk free interest rate
            const double& v, // Volatility of underlying
            const double& T); // Expiry
};


#endif //GBMPRICING_PATHGENERATOR_H
