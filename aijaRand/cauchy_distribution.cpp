#include "distribution.hpp"
#include "cauchy_distribution.hpp"
#include "uniform_distribution.hpp"

double CauchyDistribution::GetRandNum() {

  if (_beta <= 0) {
    throw BadArgumentException();
  }

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);
  double u = ud->GetRandNum();

  delete ud;

  return _alpha - (_beta / std::tan(M_PI * u));

}

std::vector<double>* CauchyDistribution::GetRandNums(unsigned int count) {

  if (_beta <= 0) {
    throw BadArgumentException();
  }

  std::vector<double>* the_vector = new std::vector<double>();
  the_vector->reserve(count);

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);

  double u(0.0);

  for (unsigned int i = 0; i < count; ++i) {
      u = ud->GetRandNum();
      the_vector->push_back( _alpha - (_beta / std::tan(M_PI * u)) );

  }


  delete ud;

  return the_vector;

}
