//
// Created by Jian Lu on 10/5/21.
//

#ifndef GBMPRICING_DATA_H
#define GBMPRICING_DATA_H

struct OptionInput {
    double K;   // strike price
    double S;   // underlying asset price
    double r;   // risk-free interest rate, yearly
    double T;   // time to expire, year
    double sigma;   // volatility
    OptionInput(double _K, double _S, double _r, double _T, double _sigma) {
        K = _K;
        S = _S;
        r = _r;
        T = _T;
        sigma = _sigma;
    }
};

enum ASIAN_OPTION_SUM_TYPE {
    ARITHMETIC,
    GEOMETRIC
};

class Data {

};


#endif //GBMPRICING_DATA_H
