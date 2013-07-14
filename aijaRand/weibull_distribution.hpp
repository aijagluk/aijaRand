#ifndef WEIBULL_DISTRIBUTION_HPP
#define WEIBULL_DISTRIBUTION_HPP

class Distribution;

class WeibullDistribution : public Distribution {
public:
  WeibullDistribution();
  WeibullDistribution(double alpha, double beta) : _alpha(alpha), _beta(beta) {}

  virtual ~WeibullDistribution() {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  double _alpha;
  double _beta;
};

#endif // WEIBULL_DISTRIBUTION_HPP
