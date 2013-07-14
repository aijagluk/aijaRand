#ifndef NEGATIVE_BINOMIAL_DISTRIBUTION_HPP
#define NEGATIVE_BINOMIAL_DISTRIBUTION_HPP

class Distribution;

class NegativeBinomialDistribution : public Distribution {
public:
  NegativeBinomialDistribution();
  NegativeBinomialDistribution(unsigned int k, double p) : _k(k), _p(p) {}

  virtual ~NegativeBinomialDistribution() {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  unsigned int _k;
  double _p;
};

#endif // NEGATIVE_BINOMIAL_DISTRIBUTION_HPP
