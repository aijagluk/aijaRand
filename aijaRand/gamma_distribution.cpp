#include "distribution.hpp"
#include "gamma_distribution.hpp"
#include "exponential_distribution.hpp"

double GammaDistribution::GetRandNum() {

  if (_alpha <= 1) {
    throw BadArgumentException();
  }

  double x(0.0);
  ExponentialDistribution* ed = new ExponentialDistribution(1.0);

  unsigned int alpha_tmp = _alpha;

  while (alpha_tmp-- > 1) {

    x += ed->GetRandNum();

  }

  delete ed;

  return _beta * x;

}

std::vector<double>* GammaDistribution::GetRandNums(unsigned int count) {

  if (_alpha <= 1) {
    throw BadArgumentException();
  }

  unsigned int alpha_tmp(0);
  double x(0.0);
  std::vector<double>* the_vector = new std::vector<double>();
  the_vector->reserve(count);

  ExponentialDistribution* ed = new ExponentialDistribution(1.0);

  for (unsigned int i = 0; i < count; ++i) {

    alpha_tmp = _alpha;
    while (alpha_tmp-- > 1) {
      x += ed->GetRandNum();
    }

    the_vector->push_back(_beta * x);
    x = 0;

  }

  delete ed;

  return the_vector;

}
