#include "distribution.hpp"
#include "poisson_distribution.hpp"
#include "uniform_distribution.hpp"

double PoissonDistribution::GetRandNum() {

  if (_lambda <= 0) {
    throw BadArgumentException();
  }

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);

  int x(0);
  double b(1.0);

  while ( b >= std::exp(-_lambda) ) {

    b *= ud->GetRandNum();
    ++x;

  }

  delete ud;

  return x - 1.0;

}

std::vector<double>* PoissonDistribution::GetRandNums(unsigned int count) {

  if (_lambda <= 0) {
    throw BadArgumentException();
  }

  std::vector<double>* the_vector = new std::vector<double>();
  the_vector->reserve(count);

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);
  int x(0);
  double b(1.0);

  for (unsigned int i = 0; i < count; ++i) {

    while ( b >= std::exp(-_lambda) ) {
      b *= ud->GetRandNum();
      ++x;
    }

    the_vector->push_back( x - 1.0 );

    x = 0;
    b = 1.0;

  }

  delete ud;

  return the_vector;

}
