#ifndef AIJARAND_HPP
#define AIJARAND_HPP

#include "aijaRand/distribution.hpp"
#include "aijaRand/uniform_distribution.hpp"
#include "aijaRand/bernoulli_distribution.hpp"
#include "aijaRand/binomial_distribution.hpp"
#include "aijaRand/cauchy_distribution.hpp"
#include "aijaRand/exponential_distribution.hpp"
#include "aijaRand/erlang_distribution.hpp"
#include "aijaRand/gamma_distribution.hpp"
#include "aijaRand/beta_distribution.hpp"
#include "aijaRand/weibull_distribution.hpp"
#include "aijaRand/geometric_distribution.hpp"
#include "aijaRand/negative_binomial_distribution.hpp"
#include "aijaRand/logistic_distribution.hpp"
#include "aijaRand/normal_distribution.hpp"
#include "aijaRand/chi_square_distribution.hpp"
#include "aijaRand/f_distribution.hpp"
#include "aijaRand/t_distribution.hpp"
#include "aijaRand/lognormal_distribution.hpp"
#include "aijaRand/triangular_distribution.hpp"
#include "aijaRand/poisson_distribution.hpp"

class AijaRand {
public:
  explicit AijaRand(Distribution* distribution);
  double GetRandNum();
  std::vector<double>* GetRandNums(unsigned int count);

private:
  Distribution* _distribution;
};

#endif // AIJARAND_HPP
