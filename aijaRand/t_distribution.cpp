#include "distribution.hpp"
#include "t_distribution.hpp"
#include "normal_distribution.hpp"
#include "chi_square_distribution.hpp"

double TDistribution::GetRandNum() {

  NormalDistribution* nd = new NormalDistribution(0.0, 1.0);
  ChiSquareDistribution* chi_d = new ChiSquareDistribution(_k);
  double z = nd->GetRandNum();
  double y = chi_d->GetRandNum();

  delete chi_d;
  delete nd;

  return z / std::sqrt( y / static_cast<double>(_k) );

}

std::vector<double>* TDistribution::GetRandNums(unsigned int count) {

  std::vector<double>* the_vector = new std::vector<double>();
  NormalDistribution* nd = new NormalDistribution(0.0, 1.0);
  ChiSquareDistribution* chi_d = new ChiSquareDistribution(_k);
  double z(0.0);
  double y(0.0);

  for (unsigned int i = 0; i < count; ++i) {
    z = nd->GetRandNum();
    y = chi_d->GetRandNum();

    the_vector->push_back( z / std::sqrt( y / static_cast<double>(_k) ) );
  }

  delete chi_d;
  delete nd;

  return the_vector;

}
