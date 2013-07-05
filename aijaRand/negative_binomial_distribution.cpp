#include "distribution.hpp"
#include "negative_binomial_distribution.hpp"
#include "geometric_distribution.hpp"

double NegativeBinomialDistribution::GetRandNum() {

  if (_p <= 0.0 || _p >= 1.0) {
    throw BadArgumentException();
  }

  double total_y(0.0);
  GeometricDistribution* gd = new GeometricDistribution(_p);

  for (unsigned int i = 0; i < _k; ++i) {
    total_y += gd->GetRandNum();
  }

  delete gd;

  return total_y;

}

std::vector<double>* NegativeBinomialDistribution::GetRandNums(unsigned int count) {

  if (_p <= 0.0 || _p >= 1.0) {
    throw BadArgumentException();
  }

  double total_y(0.0);
  std::vector<double>* the_vector = new std::vector<double>();
  GeometricDistribution* gd = new GeometricDistribution(_p);

  for (unsigned int n = 0; n < count; ++n) {

    for (unsigned int i = 0; i < _k; ++i) {
      total_y += gd->GetRandNum();
    }

    the_vector->push_back(total_y);

  }

  delete gd;

  return the_vector;

}
