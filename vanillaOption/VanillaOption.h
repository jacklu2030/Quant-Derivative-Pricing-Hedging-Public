
#ifndef GBMPRICING_VANILLAOPTION_H
#define GBMPRICING_VANILLAOPTION_H

#include "cmath"
#include "../quantFormula/Distribution.h"

class VanillaOption {

public:
    VanillaOption();
    VanillaOption(const double _K, const double _S, const double _r, const double _T, const double _sigma);
    VanillaOption(const VanillaOption & v);     // copy constructor
    VanillaOption& operator=(const VanillaOption & v);   // assignment constructor
    virtual ~VanillaOption();

    double calcCallPrice() const;
    double calcPutPrice() const;

private:

    void init();
    void copy(const VanillaOption & rhs);
    double K;   // strike price
    double S;   // underlying asset price as of today
    double r;   // risk-free interest rate
    double T;   // time to expire
    double sigma;   // volatinity

};


#endif //GBMPRICING_VANILLAOPTION_H
