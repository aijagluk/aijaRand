#include "distribution.hpp"
#include "lognormal_distribution.hpp"
#include "normal_distribution.hpp"

double LognormalDistribution::GetRandNum() {

  NormalDistribution* nd = new NormalDistribution(_expected_value, _variance);
  double x = nd->GetRandNum();

  delete nd;

  return std::exp(x);

}

std::vector<double>* LognormalDistribution::GetRandNums(unsigned int count) {

  std::vector<double>* the_vector = new std::vector<double>();
  the_vector->reserve(count);

  NormalDistribution* nd = new NormalDistribution(_expected_value, _variance);

  for (unsigned int i = 0; i < count; ++i) {
    the_vector->push_back( std::exp(nd->GetRandNum()) );
  }

  delete nd;

  return the_vector;

}
