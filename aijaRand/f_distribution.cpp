#include "distribution.hpp"
#include "f_distribution.hpp"
#include "chi_square_distribution.hpp"

double FDistribution::GetRandNum() {

  ChiSquareDistribution* chi_d_1 = new ChiSquareDistribution(_k_1);
  ChiSquareDistribution* chi_d_2 = new ChiSquareDistribution(_k_2);

  double y_1 = chi_d_1->GetRandNum();
  double y_2 = chi_d_2->GetRandNum();

  delete chi_d_1;
  delete chi_d_2;

  return (y_1 / static_cast<double>(_k_1)) / (y_2 / static_cast<double>(_k_2));

}

std::vector<double>* FDistribution::GetRandNums(unsigned int count) {

  std::vector<double>* the_vector = new std::vector<double>();
  ChiSquareDistribution* chi_d_1 = new ChiSquareDistribution(_k_1);
  ChiSquareDistribution* chi_d_2 = new ChiSquareDistribution(_k_2);

  double y_1(0.0);
  double y_2(0.0);

  for (unsigned int i = 0; i < count; ++i) {
    y_1 = chi_d_1->GetRandNum();
    y_2 = chi_d_2->GetRandNum();
    the_vector->push_back( (y_1 / static_cast<double>(_k_1)) / (y_2 / static_cast<double>(_k_2)) );
  }

  delete chi_d_1;
  delete chi_d_2;

  return the_vector;

}
