#include "distribution.hpp"
#include "bernoulli_distribution.hpp"
#include "uniform_distribution.hpp"

double BernoulliDistribution::GetRandNum(){

  if (_p < 0 || _p > 1) {
    throw BadArgumentException();
  }

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);
  double u = ud->GetRandNum();
  delete ud;

  if (u <= _p) {
    return 1.0;
  }
  else {
    return 0.0;
  }

}


std::vector<double>* BernoulliDistribution::GetRandNums(unsigned int count){

  if (_p < 0 || _p > 1) {
    throw BadArgumentException();
  }

  std::vector<double>* the_vector = new std::vector<double>();
  the_vector->reserve(count);

  UniformDistribution* ud = new UniformDistribution(0.0, 1.0);
  double u;

  for (unsigned int i = 0; i < count; ++i) {

    u = ud->GetRandNum();

    if (u <= _p) {
      the_vector->push_back(1.0);
    }
    else {
      the_vector->push_back(0.0);
    }

  }

  delete ud;

  return the_vector;

}
