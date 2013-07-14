#ifndef LOGISTIC_DISTRIBUTION_HPP
#define LOGISTIC_DISTRIBUTION_HPP

class Distribution;

class LogisticDistribution : public Distribution {
public:
  LogisticDistribution();
  LogisticDistribution(double a, double b) : _a(a), _b(b) {}

  virtual ~LogisticDistribution() {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  double _a;
  double _b;
};

#endif // LOGISTIC_DISTRIBUTION_HPP
