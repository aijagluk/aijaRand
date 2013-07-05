#include "aija_rand.hpp"

AijaRand::AijaRand(Distribution* distribution) {

  _distribution = distribution;

}

double AijaRand::GetRandNum() {

  return _distribution->GetRandNum();

}

std::vector<double>* AijaRand::GetRandNums(unsigned int count){

  return _distribution->GetRandNums(count);

}
