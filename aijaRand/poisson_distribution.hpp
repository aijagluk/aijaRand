#ifndef POISSON_DISTRIBUTION_HPP
#define POISSON_DISTRIBUTION_HPP

class Distribution;

class PoissonDistribution : public Distribution {
public:
  PoissonDistribution();
  explicit PoissonDistribution(double lambda) : _lambda(lambda) {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  double _lambda;
};

#endif // POISSON_DISTRIBUTION_HPP
