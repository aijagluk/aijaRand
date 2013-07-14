#ifndef ERLANG_DISTRIBUTION_HPP
#define ERLANG_DISTRIBUTION_HPP

class Distribution;

class ErlangDistribution : public Distribution {
public:
  ErlangDistribution();
  ErlangDistribution(unsigned int k, double beta) : _k(k), _beta(beta) {}

  virtual ~ErlangDistribution() {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  unsigned int _k;
  double _beta;
};

#endif // ERLANG_DISTRIBUTION_HPP
