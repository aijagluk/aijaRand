#ifndef BINOMIAL_DISTRIBUTION_HPP
#define BINOMIAL_DISTRIBUTION_HPP

class Distribution;

class BinomialDistribution : public Distribution {
public:
  BinomialDistribution();
  BinomialDistribution(unsigned int n, double p) : _n(n), _p(p) {}

  virtual ~BinomialDistribution() {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  unsigned int _n;
  double _p;
};

#endif // BINOMIAL_DISTRIBUTION_HPP
