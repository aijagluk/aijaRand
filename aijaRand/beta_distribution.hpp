#ifndef BETA_DISTRIBUTION_HPP
#define BETA_DISTRIBUTION_HPP

class Distribution;

class BetaDistribution : public Distribution {
public:
  BetaDistribution();
  BetaDistribution(unsigned int alpha, unsigned int beta) : _alpha(alpha), _beta(beta) {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  unsigned int _alpha;
  unsigned int _beta;
};

#endif // BETA_DISTRIBUTION_HPP
