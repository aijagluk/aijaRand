#ifndef CAUCHY_DISTRIBUTION_HPP
#define CAUCHY_DISTRIBUTION_HPP

class Distribution;

class CauchyDistribution : public Distribution {
public:
  CauchyDistribution();
  CauchyDistribution(double alpha, double beta) : _alpha(alpha), _beta(beta) {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  double _alpha;
  double _beta;
};

#endif // CAUCHY_DISTRIBUTION_HPP
