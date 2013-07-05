#include "distribution.hpp"
#include "triangular_distribution.hpp"
#include "uniform_distribution.hpp"

double TriangularDistribution::GetRandNum() {

  if (_a >= _b || _a >= _m || _b <= _m) {
    throw BadArgumentException();
  }

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);

  double c = (_m - _a) / (_b - _a);
  double u = ud->GetRandNum();
  double y(0.0);

  if (u < c) {
    y = std::sqrt(c * u);
  }
  else {
    y = 1.0 - std::sqrt( (1.0 - c) * (1.0 - u) );
  }

  delete ud;

  return _a + (_b - _a) * y;

}

std::vector<double>* TriangularDistribution::GetRandNums(unsigned int count) {

  if (_a >= _b || _a >= _m || _b <= _m) {
    throw BadArgumentException();
  }

  std::vector<double>* the_vector = new std::vector<double>();
  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);

  double c = (_m - _a) / (_b - _a);
  double u(0.0);
  double y(0.0);

  for (unsigned int i = 0; i < count; ++i) {

    u = ud->GetRandNum();

    if (u < c) {
      y = std::sqrt(c * u);
    }
    else {
      y = 1.0 - std::sqrt( (1.0 - c) * (1.0 - u) );
    }

    the_vector->push_back( _a + (_b - _a) * y );

  }

  delete ud;

  return the_vector;

}
