#include "distribution.hpp"
#include "geometric_distribution.hpp"
#include "uniform_distribution.hpp"

double GeometricDistribution::GetRandNum() {

  if (_p <= 0 || _p >= 1) {
    throw BadArgumentException();
  }

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);
  double r = ud->GetRandNum();

  double u = std::log(r) / std::log(1.0 - _p);

  return std::floor(u);

}

std::vector<double>* GeometricDistribution::GetRandNums(unsigned int count) {

  if (_p <= 0 || _p >= 1) {
    throw BadArgumentException();
  }

  std::vector<double>* the_vector = new std::vector<double>();
  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);    

  for (unsigned int i = 0; i < count; ++i) {
    the_vector->push_back( std::floor( std::log( ud->GetRandNum() ) / std::log(1.0 - _p) ) );
  }

  delete ud;

  return the_vector;

}
