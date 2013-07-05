#include "distribution.hpp"
#include "beta_distribution.hpp"
#include "gamma_distribution.hpp"

double BetaDistribution::GetRandNum() {

  if (_alpha <= 1 || _beta <= 1) {
    throw BadArgumentException();
  }

  GammaDistribution* gd_1 = new GammaDistribution(_alpha, 1.0);
  GammaDistribution* gd_2 = new GammaDistribution(_beta, 1.0);

  double y_1 = gd_1->GetRandNum();
  double y_2 = gd_2->GetRandNum();

  return y_1 / (y_1 + y_2);

}

std::vector<double>* BetaDistribution::GetRandNums(unsigned int count) {

  if (_alpha <= 1 || _beta <= 1) {
    throw BadArgumentException();
  }

  std::vector<double>* the_vector = new std::vector<double>();
  GammaDistribution* gd_1 = new GammaDistribution(_alpha, 1.0);
  GammaDistribution* gd_2 = new GammaDistribution(_beta, 1.0);

  double y_1(0.0);
  double y_2(0.0);

  for (unsigned int i = 0; i < count; ++i) {
    y_1 = gd_1->GetRandNum();
    y_2 = gd_2->GetRandNum();

    the_vector->push_back( y_1 / (y_1 + y_2) );
  }

  return the_vector;

}
