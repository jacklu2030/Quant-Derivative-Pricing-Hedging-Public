#ifndef GBMPRICING_PAYOFF_H
#define GBMPRICING_PAYOFF_H

#include <algorithm>

class Payoff {
public:
    Payoff();
    virtual ~Payoff() {};

    // To turn the class Payoff into an abstract function object, we need to overload operator()
    virtual double operator()(const double& S) const = 0;
};

class PayoffCall : public Payoff {
public:
    PayoffCall(const double & _K);
    virtual ~PayoffCall() {};
    virtual double operator()(const double& S) const;

private:
    double K;
};

class PayoffPut : public Payoff {
public:
    PayoffPut(const double & _K);
    virtual ~PayoffPut() {};
    virtual double operator()(const double& S) const;

private:
    double K;
};


#endif //GBMPRICING_PAYOFF_H
