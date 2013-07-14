#ifndef GEOMETRIC_DISTRIBUTION_HPP
#define GEOMETRIC_DISTRIBUTION_HPP

class Distribution;

class GeometricDistribution : public Distribution {
public:
  GeometricDistribution();    
  explicit GeometricDistribution(double p) : _p(p) {}

  virtual ~GeometricDistribution() {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  double _p;
};

#endif // GEOMETRIC_DISTRIBUTION_HPP
