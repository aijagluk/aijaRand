#ifndef EXPONENTIAL_DISTRIBUTION_HPP
#define EXPONENTIAL_DISTRIBUTION_HPP

class Distribution;

class ExponentialDistribution : public Distribution {
public:
  ExponentialDistribution();
  explicit ExponentialDistribution(double beta) : _beta(beta) {}

  virtual ~ExponentialDistribution() {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  double _beta;
};

#endif // EXPONENTIAL_DISTRIBUTION_HPP
