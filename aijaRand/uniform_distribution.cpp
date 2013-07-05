#include "distribution.hpp"
#include "uniform_distribution.hpp"

UniformDistribution::UniformDistribution(double a, double b) {

  if (a < b) {
    _a = a;
    _b = b;
  }
  else {
    _a = b;
    _b = a;
  }
}

double UniformDistribution::GetRandNum() {

  if (_a == _b) {
    throw ZeroRange();
  }

  return static_cast<double>(rand()) / (RAND_MAX - 1) * (_b - _a) + _a;

}

std::vector<double>* UniformDistribution::GetRandNums(unsigned int count) {

  if (_a == _b) {
    throw ZeroRange();
  }

  std::vector<double>* the_vector = new std::vector<double>();
  double tmp_value;

  for (unsigned int i = 0; i < count; ++i) {
    tmp_value = static_cast<double>(rand()) / (RAND_MAX - 1) * (_b - _a) + _a;
    the_vector->push_back(tmp_value);
  }

  return the_vector;

}
