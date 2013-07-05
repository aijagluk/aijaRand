#ifndef UNIFORM_DISTRIBUTION_HPP
#define UNIFORM_DISTRIBUTION_HPP

class Distribution;

class UniformDistribution : public Distribution {
public:
  UniformDistribution();
  UniformDistribution(double a, double b);

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  double _a;
  double _b;
};

#endif // UNIFORM_DISTRIBUTION_HPP
