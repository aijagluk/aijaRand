#ifndef CHI_SQUARE_DISTRIBUTION_HPP
#define CHI_SQUARE_DISTRIBUTION_HPP

class Distribution;

class ChiSquareDistribution : public Distribution {
public:
  ChiSquareDistribution();
  explicit ChiSquareDistribution(unsigned int k) : _k(k) {}

  virtual ~ChiSquareDistribution() {}

  virtual double GetRandNum();
  virtual std::vector<double>* GetRandNums(unsigned int count);

private:
  unsigned int _k;
};

#endif // CHI_SQUARE_DISTRIBUTION_HPP
