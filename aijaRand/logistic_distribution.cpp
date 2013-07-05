#include "distribution.hpp"
#include "logistic_distribution.hpp"
#include "uniform_distribution.hpp"

double LogisticDistribution::GetRandNum() {

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);
  double u = ud->GetRandNum();

  delete ud;

  return _a - _b * std::log(1.0 / u - 1.0);

}

std::vector<double>* LogisticDistribution::GetRandNums(unsigned int count) {

  std::vector<double>* the_vector = new std::vector<double>();
  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);  

  for (unsigned int i = 0; i < count; ++i) {
    the_vector->push_back( _a - _b * std::log(1.0 / ud->GetRandNum() - 1.0) );
  }

  delete ud;

  return the_vector;

}
