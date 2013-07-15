#include "distribution.hpp"
#include "normal_distribution.hpp"
#include "uniform_distribution.hpp"

double NormalDistribution::GetRandNum() {

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);
  double u_1 = ud->GetRandNum();
  double u_2 = ud->GetRandNum();

  double y = std::sqrt(-2.0 * std::log(u_1)) * std::sin(2.0 * M_PI * u_2);

  delete ud;

  return _expected_value + _variance * y;

}

std::vector<double>* NormalDistribution::GetRandNums(unsigned int count) {

  std::vector<double>* the_vector = new std::vector<double>();
  the_vector->reserve(count);

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);
  double u_1;
  double u_2;
  double y;

  for (unsigned int i = 0; i < count; ++i) {

    u_1 = ud->GetRandNum();
    u_2 = ud->GetRandNum();

    y = std::sqrt(-2.0 * std::log(u_1)) * std::sin(2.0 * M_PI * u_2);
    the_vector->push_back( _expected_value + _variance * y );

  }

  delete ud;

  return the_vector;

}
