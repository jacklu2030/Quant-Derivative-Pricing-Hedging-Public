#ifndef GBMPRICING_ASIANEXOTICOPTION_H
#define GBMPRICING_ASIANEXOTICOPTION_H

#include <vector>
#include "Payoff.h"

class AsianExoticOption {
public:
    AsianExoticOption(Payoff * _payoff);
    virtual ~AsianExoticOption() = default;

    virtual double pay_off_price(const std::vector<double> & spotPrices) const = 0;

protected:
    Payoff * payoff;
};

class AsianOptionArithmetic : public AsianExoticOption {
public:
    AsianOptionArithmetic(Payoff * _payoff);
    virtual ~AsianOptionArithmetic() = default;

    // Override pure virtua function of parent class
    virtual double pay_off_price(const std::vector<double> & spot_prices) const;
};

class AsianOptionGeometric : public AsianExoticOption {
public:
    AsianOptionGeometric(Payoff* _payoff);
    virtual ~AsianOptionGeometric() = default;

    // Override pure virtual function of parent class
    virtual double pay_off_price(const std::vector<double> & spot_prices) const;
};


#endif //GBMPRICING_ASIANEXOTICOPTION_H
