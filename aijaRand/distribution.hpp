#ifndef DISTRIBUTION_HPP
#define DISTRIBUTION_HPP

#include <cstdlib>
#include <cmath>
#include <vector>

#include "exceptions.hpp"

class Distribution {
public:
  virtual ~Distribution(){}

  virtual double GetRandNum() = 0;
  virtual std::vector<double>* GetRandNums(unsigned int count) = 0;  

protected:
  Distribution(){}
};

#endif // DISTRIBUTION_HPP
