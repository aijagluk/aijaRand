#include "distribution.hpp"
#include "exponential_distribution.hpp"
#include "uniform_distribution.hpp"

double ExponentialDistribution::GetRandNum() {

  if (_beta <= 0) {
    throw BadArgumentException();
  }

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);
  double u = ud->GetRandNum();

  delete ud;

  return -_beta * std::log(u);

}

std::vector<double>* ExponentialDistribution::GetRandNums(unsigned int count) {

  if (_beta <= 0) {
    throw BadArgumentException();
  }

  std::vector<double>* the_vector = new std::vector<double>();
  the_vector->reserve(count);

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);

  for (unsigned int i = 0; i < count; ++i) {
    the_vector->push_back(-_beta * std::log( ud->GetRandNum() ));
  }

  delete ud;

  return the_vector;

}
