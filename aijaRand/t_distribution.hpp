#ifndef T_DISTRIBUTION_HPP
#define T_DISTRIBUTION_HPP

class Distribution;

class TDistribution : public Distribution {
public:
  TDistribution();
  explicit TDistribution(unsigned int k) : _k(k) {}

  virtual ~TDistribution() {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  unsigned int _k;
};

#endif // T_DISTRIBUTION_HPP
