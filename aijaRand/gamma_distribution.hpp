#ifndef GAMMA_DISTRIBUTION_HPP
#define GAMMA_DISTRIBUTION_HPP

class Distribution;

class GammaDistribution : public Distribution {
public:
  GammaDistribution();
  GammaDistribution(unsigned int alpha, double beta) : _alpha(alpha), _beta(beta) {}

  virtual ~GammaDistribution() {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  unsigned int _alpha;
  double _beta;
};

#endif // GAMMA_DISTRIBUTION_HPP
