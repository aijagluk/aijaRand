#ifndef NORMAL_DISTRIBUTION_HPP
#define NORMAL_DISTRIBUTION_HPP

class Distribution;

class NormalDistribution : public Distribution {
public:
  NormalDistribution();
  NormalDistribution(double expected_value, double variance) : _expected_value(expected_value), _variance(variance) {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  double _expected_value;
  double _variance;
};

#endif // NORMAL_DISTRIBUTION_HPP
