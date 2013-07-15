#include "distribution.hpp"
#include "erlang_distribution.hpp"
#include "exponential_distribution.hpp"

double ErlangDistribution::GetRandNum() {

  ExponentialDistribution* ed = new ExponentialDistribution(_beta / static_cast<double>(_k));

  double total_y(0.0);

  for (unsigned int i = 0; i < _k; ++i) {
    total_y += ed->GetRandNum();
  }

  delete ed;

  return total_y;

}

std::vector<double>* ErlangDistribution::GetRandNums(unsigned int count) {

  std::vector<double>* the_vector = new std::vector<double>();
  the_vector->reserve(count);

  ExponentialDistribution* ed = new ExponentialDistribution(_beta / static_cast<double>(_k));

  double total_y(0.0);

  for (unsigned int n = 0; n < count; ++n) {

    for (unsigned int i = 0; i < _k; ++i) {
      total_y += ed->GetRandNum();
    }

    the_vector->push_back(total_y);
    total_y = 0;

  }

  delete ed;

  return the_vector;

}
