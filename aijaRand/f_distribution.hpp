#ifndef F_DISTRIBUTION_HPP
#define F_DISTRIBUTION_HPP

class Distribution;

class FDistribution : public Distribution {
public:
  FDistribution();
  FDistribution(unsigned int k_1, unsigned int k_2) : _k_1(k_1), _k_2(k_2) {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  unsigned int _k_1;
  unsigned int _k_2;
};

#endif // F_DISTRIBUTION_HPP
