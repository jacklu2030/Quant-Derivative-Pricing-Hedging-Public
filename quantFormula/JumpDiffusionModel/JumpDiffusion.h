
#ifndef GBMPRICING_JUMPDIFFUSION_H
#define GBMPRICING_JUMPDIFFUSION_H

#include <cmath>
#include "../Data.h"
#include "../BlackScholes/EuropeanOption.h"

/**
 * Jump Diffusion is based on Black-Scholes model, with relaxed assumption: price can jump.
 *
 * Black-Scholes model the stock price evolves as a geometric Brownian motion continuous price changes.
 * Crucially, this allows Delta hedging and thus a fixed no-arbitrage price for any option on the stock.
 *
 * However, if prices can jump, it becomes impossible to perfectly hedge and leads to market incompleteness.
 * This leads to options prices which are only bounded rather than fixed
 *
 * Comparison to the Black-Scholes price of 10.4506 given in the prior European,
 * the value of the call under the jump diffusion process 18.7336 is much higher.
 * This is to be expected since the jumps introduce extra volatility into the model.
 */
class JumpDiffusion {

public:

    // Calculate the Merton jump−diffusion price based on
    // a finite sum approximation to the infinite series
    // solution, making use of the Black-Scholes call price.
    static double jump_call_price (const OptionInput& in,
                                   const int& N,
                                   const double& m,
                                   const double& lambda ,
                                   const double& nu );

    // Calculate the Merton jump−diffusion price based on
    // a finite sum approximation to the infinite series
    // solution, making use of the Black-Scholes call price.
    static double jump_put_price (const OptionInput& in,
                                   const int& N,
                                   const double& m,
                                   const double& lambda ,
                                   const double& nu );
};


#endif //GBMPRICING_JUMPDIFFUSION_H
