#ifndef TRIANGULAR_DISTRIBUTION_HPP
#define TRIANGULAR_DISTRIBUTION_HPP

class Distribution;

class TriangularDistribution : public Distribution {
public:
  TriangularDistribution();
  TriangularDistribution(double a, double b, double m) : _a(a), _b(b), _m(m) {}

  virtual ~TriangularDistribution() {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  double _a;
  double _b;
  double _m;
};

#endif // TRIANGULAR_DISTRIBUTION_HPP
