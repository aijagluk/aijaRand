#include "distribution.hpp"
#include "chi_square_distribution.hpp"
#include "normal_distribution.hpp"

double ChiSquareDistribution::GetRandNum() {

  NormalDistribution* nd = new NormalDistribution(0.0, 1.0);
  double total_z(0.0);
  double z(0.0);

  for (unsigned int i = 0; i < _k; ++i) {
    z = nd->GetRandNum();
    total_z += z * z;
  }

  delete nd;

  return total_z;

}

std::vector<double>* ChiSquareDistribution::GetRandNums(unsigned int count) {

  std::vector<double>* the_vector = new std::vector<double>();
  the_vector->reserve(count);

  NormalDistribution* nd = new NormalDistribution(0.0, 1.0);
  double total_z(0.0);
  double z(0.0);

  for (unsigned int n = 0; n < count; ++n) {

    for (unsigned int i = 0; i < _k; ++i) {
      z = nd->GetRandNum();
      total_z += z * z;
    }

    the_vector->push_back(total_z);
    total_z = 0;

  }

  delete nd;

  return the_vector;

}
