
#ifndef GBMPRICING_GREEKS_H
#define GBMPRICING_GREEKS_H
#include "../Data.h"
#include "../Distribution.h"
#include "../BlackScholes/EuropeanOption.h"

/**
 * Sensitivity Tests:
 *
 * • Delta - Derivative of an option with respect to (w.r.t.) the spot price, ∂C / ∂S
   • Gamma - Second derivative of an option w.r.t. the spot price, ∂2C / ∂S2
   • Vega - Derivative of an option w.r.t. the underlying volatility, ∂C / ∂σ
   • Theta - (Negative) derivative of an option w.r.t. the time to expiry, ∂C / ∂t
   • Rho - Derivative of an option w.r.t. the interest rate, ∂C / ∂r
 */
class Greeks {
public:
    explicit Greeks(const OptionInput& in);

    // ============================
    // ANALYTIC FORMULAE -- Based on analytic formula / solution of Bkack-Schelos for European Vanilla Options
    // ============================
    double call_delta();
    double call_gamma();
    double call_vega();
    double call_theta();
    double call_rho();

    double put_delta();
    double put_gamma();
    double put_vega();
    double put_theta();
    double put_rho();

    // ===========
    // MONTE CARLO -- solved based on numerical method (tree / Geometric Brownian Motion)
    // ===========
    double call_delta_fdm (const double delta_S);
    double call_gamma_fdm (const double delta_S);
//    double call_vega_fdm (const double delta_v);
//    double call_theta_fdm (const double delta_S);
//    double call_rho_fdm (const double delta_S);

    double put_delta_fdm (const double delta_S);
    double put_gamma_fdm (const double delta_S);
//    double put_vega_fdm (const double delta_S);
//    double put_theta_fdm (const double delta_S);
//    double put_rho_fdm (const double delta_S);

private:
    double K;     // option strike price
    double S;     // underlying asset spot price
    double r = 0.0;     // risk-free interest rate per year
    double v = 0.0;     // volitility
    double T = 0.0;     // time to expire, year

    Distribution dist;
    EuropeanOption eOption;
};


#endif //GBMPRICING_GREEKS_H
