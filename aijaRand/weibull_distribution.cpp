#include "distribution.hpp"
#include "weibull_distribution.hpp"
#include "exponential_distribution.hpp"

double WeibullDistribution::GetRandNum() {

  if (_alpha <= 0 || _beta <= 0) {
    throw BadArgumentException();
  }

  ExponentialDistribution* ed = new ExponentialDistribution(1.0);
  double y = _beta * std::pow(ed->GetRandNum(), (1.0 / _alpha));

  delete ed;

  return y;

}

std::vector<double>* WeibullDistribution::GetRandNums(unsigned int count) {

  if (_alpha <= 0 || _beta <= 0) {
    throw BadArgumentException();
  }

  std::vector<double>* the_vector = new std::vector<double>();
  the_vector->reserve(count);

  ExponentialDistribution* ed = new ExponentialDistribution(1.0);

  for (unsigned int i = 0; i < count; ++i) {
    the_vector->push_back( _beta * std::pow(ed->GetRandNum(), (1.0 / _alpha)) );
  }

  delete ed;

  return the_vector;

}
