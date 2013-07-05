#ifndef BERNOULLI_DISTRIBUTION_HPP
#define BERNOULLI_DISTRIBUTION_HPP

class Distribution;

class BernoulliDistribution : public Distribution {
public:
  BernoulliDistribution();
  explicit BernoulliDistribution(double p) : _p(p) {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  double _p;
};

#endif // BERNOULLI_DISTRIBUTION_HPP
