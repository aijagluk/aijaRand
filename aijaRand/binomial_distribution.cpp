#include "distribution.hpp"
#include "binomial_distribution.hpp"
#include "bernoulli_distribution.hpp"

double BinomialDistribution::GetRandNum() {

  if (_p < 0 || _p > 1) {
    throw BadArgumentException();
  }

  BernoulliDistribution* bd = new BernoulliDistribution(_p);
  double total_y(0.0);

  for (unsigned int i = 0; i < _n; ++i) {
    total_y += bd->GetRandNum();
  }

  delete bd;

  return total_y;
}


std::vector<double>* BinomialDistribution::GetRandNums(unsigned int count) {

  if (_p < 0 || _p > 1) {
    throw BadArgumentException();
  }

  std::vector<double>* the_vector = new std::vector<double>();
  the_vector->reserve(count);

  BernoulliDistribution* bd = new BernoulliDistribution(_p);
  double total_y(0.0);

  for (unsigned int n = 0; n < count; ++n) {

    for (unsigned int i = 0; i < _n; ++i) {
      total_y += bd->GetRandNum();
    }

    the_vector->push_back(total_y);
    total_y = 0;

  }

  delete bd;

  return the_vector;

}
