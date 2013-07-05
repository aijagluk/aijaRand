#ifndef LOGNORMAL_DISTRIBUTION_HPP
#define LOGNORMAL_DISTRIBUTION_HPP

class Distribution;

class LognormalDistribution : public Distribution {
public:
  LognormalDistribution();
  LognormalDistribution(double expected_value, double variance) : _expected_value(expected_value), _variance(variance) {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  double _expected_value;
  double _variance;
};

#endif // LOGNORMAL_DISTRIBUTION_HPP
