
                     Risk Neutral Portfolio Hedged via Geometric Browning Motion 
                                          By Jack Lu, Aug, 2021

0. Abstract: 

Every transaction is buying or selling risks. The main goal of the strategy is to build a portfolio where future values have zero chance being negative, and non-zero chance of being positive or higher.

I developed a C++ option pricing / hedging system, a sample risk neutral portfolio with arbitrage theory. The pros / cons of each pricing algorithms are analyzed. The algorithms below in the C++ pricing system are all based on arbitrage theory and Geometric Brownian Motion (GBM) theory:

1. Quant formulas for various option pricing, including:

• Black-Scholes model -- analytical solution / Partial Differential Equation(PDE)
• Monto Carlo model -- numerical solution, Finite Differential Equation(FDE)
• Asian Exotic option model -- arithmetic / geometric averaging
• Binomial lattice model (tree) – numerical solution with discrete-time
• Jump Diffusion model -- discrete time / price jump

2 Portfolio Construction and Evaluation

Here are the steps to construct a sample risk neutral portfolio with zero probability of negative value and greater than zero probability of positive value in the future:

a) Given the conditions below, the bank sells call option:
   1) S = current stock price
   2) K=strikeprice(S<K)
   3) r = interest rate
   4) T = time to expire
   5) σ = volatility
   6) C = call option premium calculated using the Black-Scholes model
b) Calculate the call premium and delta derivative
c) If stock price stays below K, we do nothing
d) Whenever stock price go above S, we buy shares (maybe factional) to cover the portfolio.
   Whenever stock price goes below K, we sell some shares, until we reach S where we sell all stock shares.
e) At expiry, stock price is S1. Below is the bank’s profit:
   1) IfS1<=S,profit=C
   2) IfS<S1<=K,profit=C+(K–S1)
   3) If S1 > K, we sell all shares to cover the call option, profit = C

The key of this sample risk neutral portfolio is to calculate the reasonable call option price, and the delta ratio of stock shares, with assumptions of no transaction cost, constant interest rate, constant volatility, no dividend, no tax.

3 C++ Implementation of GBM/PDE

The table below compares option prices from various quant formulas. Please refer to Github for the C++ implementation. The same parameters below are applied to all quant strategies for the purpose of comparison:

	K = 100 	Strike
	S = 100		Spot Price 
	r = 0.05	Risk-Free Interest Rate / Year 
	T= 1		Time to Expiry (years)
	σ = 0.25	volatility
	N = 50		Terms in the finite sum approximation
	m = 1.083278 	Scale Factor
	lambda = 1.0 	Intensit of Jump
	mu = 0.4 	Standard Deviation of Log-normal Jump Process	
	num_simulation = 100000

4. Here are the noticeable from the results:

   a) Black-Scholes, Monto Carlo, Binomial Lattice produce similar Put / Call prices. Binomial Lattice model can be adjusted to take into dividend;

   b) Asian Exotic produces much lower Put / Call prices due to its averaging feature, which reduces volatility substantially. Suitable for Fixed Income / Commodity;

   c) Jump Diffusion Black-Scholes produces much higher Put / Call prices. Jumps happen far more frequent in real market, which leads to higher volatility, and higher option prices.
 
    d) Monte Carlo simulations are also less susceptible to sampling errors when comparing to
 binomial techniques which uses discrete time units.

5 Conclusion

Geometric Brownian Motion / Black-Scholas model provide a reasonable good model to estimate option prices, with some limited assumptions, such as constant interest rate, volatility etc. These issues can be overcome through iterative pricing as rate / volatility change.

Binomial Lattice takes a different approach, yet with limitations, such as bigger sampling errors compared to Monto Carlo method, and handling fewer complex variables.

Not losing money is the main goal, maximize profit is another. A risk neutral profolio is a good way to achieve these two goals.

6. Performance:

	Black-Scholes analytic 	O(1) fastest

  	Monto Carlo 		O(nk) polynomial time

 	Asian Exotic 		O(nk) polynomial time

  	Binomial Lattice 	O(2n) slowest

   	Jump Diffusion BSM	O(nk) polynomial tim



Author’s contact: jianlu2001@yahoo.com
