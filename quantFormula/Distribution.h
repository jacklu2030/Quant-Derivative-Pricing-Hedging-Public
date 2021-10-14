//
// Created by Jian Lu on 10/5/21.
//

#ifndef GBMPRICING_DISTRIBUTION_H
#define GBMPRICING_DISTRIBUTION_H
#include "cmath"

class Distribution {
public:
    // standard normal distribution - normal probability density function
    static double norm_pdf(const double & x);

    // An approximation to the cumulative distribution function
    // for the standard normal distribution
    // Note: this is a recursive function
    static double norm_cdf(const double & x);

    // This calculates d_j , for j in {1 , 2}. This term appears in the closed
    // form solution for the European call or put price
    static double d_j ( const int& j , const double& S , const double& K, const double& r ,
                 const double& v , const double& T);
};


#endif //GBMPRICING_DISTRIBUTION_H
