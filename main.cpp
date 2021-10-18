#include <iostream>

#include "./vanillaOption/VanillaOption.h"
#include "./quantFormula/Data.h"
#include "./quantFormula/BlackScholes/EuropeanOption.h"
#include "./quantFormula/MonteCarlo/OptionStockPricing.h"
#include "./quantFormula/Greeks/Greeks.h"
#include "./quantFormula/RandomNumber/GaussianBoxMuller.h"
#include "./quantFormula/Binomial/Binomial.h"
#include "./quantFormula/AsianExotic/AsianMain.h"
#include "./quantFormula/JumpDiffusionModel/JumpDiffusion.h"
#include "./quantFormula/StochasticVolatility/TestCorrelatedDraw.h"
#include "./quantFormula/StochasticVolatility/StochasticVolatilityMain.h"

int main() {
    std::cout << "Welcome to Geometric Brownian Motion Model for Option / Stock Pricing!!!\n" << std::endl;
    VanillaOption vo;
    std::cout << "Vanilla Call Price=" << vo.calcCallPrice() << std::endl;
    std::cout << "Vanilla Put Price=" << vo.calcPutPrice() << std::endl;

    // ========================================================
    // 1. Black-Schelos for European Vanilla Options -- ANALYTIC FORMULAE
    // ========================================================

    std::cout << "\n\n1. European Vanilla Option:" << std::endl;
    std::cout << "************************************** \n" << std::endl;
    OptionInput in = {100, 100, 0.05, 1, 0.25};
    EuropeanOption eo(in);
    Greeks gk(in);
    std::cout << "Black-Scholes European Vanilla Call Price=" << eo.call_price() << std::endl;
    std::cout << "Black-Scholes European Vanilla Call delta=" << gk.call_delta() << std::endl;
    std::cout << "Black-Scholes European Vanilla Call gamma=" << gk.call_gamma() << std::endl;
    std::cout << "Black-Scholes European Vanilla Call vega=" << gk.call_vega() << std::endl;
    std::cout << "Black-Scholes European Vanilla Call theta=" << gk.call_theta() << std::endl;
    std::cout << "Black-Scholes European Vanilla Call rho=" << gk.call_rho() << std::endl;

    std::cout << "\nBlack-Scholes European Vanilla Put Price=" << eo.put_price() << std::endl;
    std::cout << "Black-Scholes European Vanilla Put delta=" << gk.put_delta() << std::endl;
    std::cout << "Black-Scholes European Vanilla Put gamma=" << gk.put_gamma() << std::endl;
    std::cout << "Black-Scholes European Vanilla Put vega=" << gk.put_vega() << std::endl;
    std::cout << "Black-Scholes European Vanilla Put theta=" << gk.put_theta() << std::endl;
    std::cout << "Black-Scholes European Vanilla Put rho=" << gk.put_rho() << std::endl;

    // ========================================================
    // 2. MONTE CARLO -- solved based on numerical method (tree / Geometric Brownian Motion)
    // ========================================================

    OptionStockPricing op(in);
    int simulation_num = 10000000;
    double delta_s = 0.0001;    // Option price increment to calc delta, gamma, vega, theta, rho using FDM
    double delta_v = 0.01;    // Option price increment to calc vega using FDM
    std::cout << "\n\n2. Monte Carlo / Geometric Brownian Motion Option:" << std::endl;
    std::cout << "********************************************** \n" << std::endl;
    std::cout << "Monte Carlo European Vanilla Call Price=" << op.monte_carlo_call_price(simulation_num) << std::endl;
    std::cout << "Monte Carlo European Vanilla Call delta_fdm =" << gk.call_delta_fdm(delta_s) << std::endl;
    std::cout << "Monte Carlo European Vanilla Call gamma_fdm =" << gk.call_gamma_fdm(delta_s) << std::endl;
//    std::cout << "Monte Carlo European Vanilla Call vega_fdm =" << gk.call_vega_fdm(delta_v) << std::endl;
//    std::cout << "Monte Carlo European Vanilla Call theta_fdm =" << gk.call_theta_fdm(delta_s) << std::endl;
//    std::cout << "Monte Carlo European Vanilla Call rho_fdm =" << gk.call_rho_fdm(delta_s) << std::endl;

    std::cout << "\nMonte Carlo European Vanilla Put Price=" << op.monte_carlo_put_price(simulation_num) << std::endl;
    std::cout << "Monte Carlo European Vanilla Put delta_fdm =" << gk.put_delta_fdm(delta_s) << std::endl;
    std::cout << "Monte Carlo European Vanilla Put gamma_fdm =" << gk.put_gamma_fdm(delta_s) << std::endl;


    std::cout << "Monte Carlo Future Stock Price=" << op.monte_carlo_stock_price(simulation_num) << std::endl;

    // ========================================================
    // 3. Binomial Lattice -- solved based on numerical method (tree / Geometric Brownian Motion)
    // ========================================================
    std::cout << "\n\n3. Binomial Lattice Amreican Option: " << std::endl;
    std::cout << "************************************** \n" << std::endl;
    double no_periods = 250;
    //double americaCall = Binomial::americanCall(in.S, in.K, in.r/no_periods, in.sigma, in.T, 0.0, 0.0, no_periods);
    double americaCall = Binomial::americanCall(in.T, in.S, in.K, in.r, in.sigma, 0.0, no_periods);
    double americaPut = Binomial::americanPut(in.T, in.S, in.K, in.r, in.sigma, 0.0, no_periods);
    std::cout << "Binomial Lattice Amreican Call=" << americaCall << std::endl;
    std::cout << "Binomial Lattice Amreican Put=" << americaPut << std::endl;

    // ========================================================
    // 4. Binomial Lattice -- solved based on numerical method (tree / Geometric Brownian Motion)
    // ========================================================
    std::cout << "\n\n4. Asian Exotic Option: " << std::endl;
    std::cout << "*************************** \n" << std::endl;
    simulation_num = 100000;
    double num_intervals = 250;
    //OptionInput in_asian = {29, 30, 0.08, 1, 0.3};
    double asianArithmeticCall = AsianMain::calcCallPrice(ARITHMETIC, simulation_num, num_intervals, in);
    double asianArithmeticPut = AsianMain::calcPutPrice(ARITHMETIC, simulation_num, num_intervals, in);
    std::cout << "Asian Exotic(Arithmetic mean) Call=" << asianArithmeticCall << std::endl;
    std::cout << "Asian Exotic(Arithmetic mean) Put=" << asianArithmeticPut << std::endl;

    double asianGeometricCall = AsianMain::calcCallPrice(GEOMETRIC, simulation_num, num_intervals, in);
    double asianGeometricPut = AsianMain::calcPutPrice(GEOMETRIC, simulation_num, num_intervals, in);
    std::cout << "\nAsian Exotic(Geometric mean) Call=" << asianGeometricCall << std::endl;
    std::cout << "Asian Exotic(Geometric mean) Put=" << asianGeometricPut << std::endl;

    // ========================================================
    // 5. Jump Diffusion -- solved based on Black-Scholes numerical method (Geometric Brownian Motion)
    // ========================================================
    std::cout << "\n\n5. Jump Diffusion Option: " << std::endl;
    std::cout << "*************************** \n" << std::endl;
    int N = 50;             // Terms in the finite sum approximation
    double m = 1.083287;    // Scale factor for J
    double lambda = 1.0;    // Intensity of jumps
    double nu = 0.4;        // Standard deviation of log-normal jump process
    double jumpEurCall = JumpDiffusion::jump_call_price(in, N, m, lambda, nu);
    double jumpEurPut = JumpDiffusion::jump_put_price(in, N, m, lambda, nu);
    std::cout << "\nJump Diffusion EUR Call=" << jumpEurCall << std::endl;
    std::cout << "Jump Diffusion EUR Put=" << jumpEurPut << std::endl;

    // ========================================================
    // Test the two Correlated normal distributions
    // ========================================================
    std::cout << "\n\n6. Test the two Correlated normal distributions: " << std::endl;
    std::cout << "******************************************* \n" << std::endl;
    TestCorrelatedDraw::testCorrelatedDraw();

    // ========================================================
    // Get Put / Call prices of EUR vanilla Option using TWO separated yet correlated
    // Geometric Brownian Motions: one for spot price random walk, one for volatility random walk
    // ========================================================
    std::cout << "\n\n6. Get Put / Call prices of EUR vanilla Option using TWO separated yet correlated GBM paths: " << std::endl;
    std::cout << "**************************************************************** \n" << std::endl;
    StochasticVolatilityMain stockastic;
    int num_sims = 100000;     // Number of simulated asset paths
    num_intervals = 1000;     // Number of intervals for the asset path to be sampled
    double rho = -0.7;            // Correlation of asset and volatility
    double kappa = 6.21;          // Mean−reversion rate
    double theta = 0.019;          // Long run average underlying asset volatility
    double xi = 0.61;             // ”Vol of vol”
    //in = {100, 100, 0.0319, 1, 0.010201};
    double stochastic_call_price = stockastic.call_price(num_sims, num_intervals, rho, kappa, theta, xi, in);
    double stochastic_put_price = stockastic.put_price(num_sims, num_intervals, rho, kappa, theta, xi, in);
    std::cout << "Stochastic Volatility Two GBM paths: call_price = " << stochastic_call_price << std::endl;
    std::cout << "Stochastic Volatility Two GBM paths: put_price = " << stochastic_put_price << std::endl;

    //GaussianBoxMuller gbox;
    //gbox.testRun(0.05, 0.2);

    return 0;
}
