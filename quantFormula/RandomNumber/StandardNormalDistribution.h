
#ifndef GBMPRICING_STANDARDNORMALDISTRIBUTION_H
#define GBMPRICING_STANDARDNORMALDISTRIBUTION_H

#include "StatisticalDistribution.h"

class StandardNormalDistribution : public StatisticalDistribution {
public:
    StandardNormalDistribution () ;
    ~StandardNormalDistribution() noexcept override;

    // Distribution functions
    double pdf(const double& x) const override;
    double cdf (const double& x) const override;

    // Inverse cumulative distribution function (aka the probit function)
    virtual double inv_cdf (const double& quantile ) const override;

    // Descriptive stats
    double mean() const override;    // equals to 0
    double var() const override;     // equals to 1
    double stdev() const override;   // equals to 1

    void random_draws(const std :: vector<double>& uniform_draws , std::vector<double>& dist_draws ) override ;
};


#endif //GBMPRICING_STANDARDNORMALDISTRIBUTION_H
