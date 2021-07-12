#include <bits/stdc++.h>
#include <iostream>

class Fraction {
public:
  //numerator_ denominator_
  Fraction();
  Fraction(int num, int den);
  ~Fraction();
  Fraction operator+(const Fraction &) const;
  Fraction operator-(const Fraction &) const;
  Fraction operator*(const Fraction &) const;
  Fraction operator/(const Fraction &) const;
  friend std::ostream &operator<<(std::ostream &, const Fraction &);

private:
  int numerator_, denominator_;
  Fraction reduction();
};

Fraction::Fraction() = default;

Fraction::Fraction(int num, int den) : numerator_(num), denominator_(den) {
  if (den == 0) {
    std::cerr << "Denominator equals zero!" << std::endl;
    exit(1);
  }
  *this = this->reduction();
}

Fraction::~Fraction() {}

Fraction Fraction::operator+(const Fraction &B) const {
  int num, den;
  num = this->numerator_ * B.denominator_ + this->denominator_ * B.numerator_;
  den = this->denominator_ * B.denominator_;
  return Fraction(num, den).reduction();
}

Fraction Fraction::operator-(const Fraction &B) const {
  int num, den;
  num = this->numerator_ * B.denominator_ - this->denominator_ * B.numerator_;
  den = this->denominator_ * B.denominator_;
  return Fraction(num, den).reduction();
}

Fraction Fraction::operator*(const Fraction &B) const {
  int num, den;
  num = this->numerator_ * B.numerator_;
  den = this->denominator_ * B.denominator_;
  return Fraction(num, den).reduction();
}

Fraction Fraction::operator/(const Fraction &B) const {
  if (B.numerator_ == 0) {
    std::cerr << "Division by zero!" << std::endl;
    exit(1);
  }
  int num, den;
  num = this->numerator_ * B.denominator_;
  den = this->denominator_ * B.numerator_;
  return Fraction(num, den).reduction();
}

Fraction Fraction::reduction() {
  std::function<int(const int &a, const int &b)> gcd;
  gcd = [&gcd](const int &a, const int &b) -> int {
    return b == 0 ? a : gcd(b, a % b);
  };
  int div = gcd(this->numerator_, this->denominator_);
  this->numerator_ /= div;
  this->denominator_ /= div;
  return *this;
}

std::ostream &operator<<(std::ostream &output, const Fraction &B) {
  output << "the value is: " << B.numerator_ << '/' << B.denominator_
         << std::endl;
  return output;
}

void NormalTest() {
  std::cout << "Here the Normal Test" << std::endl;
  Fraction A(4, 6), B(6, 12), C;
  std::cout << "A: " << A << "B: " << B;
  C = A + B;
  std::cout << "A+B:  " << C;
  C = A - B;
  std::cout << "A-B:  " << C;
  C = A * B;
  std::cout << "A*B:  " << C;
  C = A / B;
  std::cout << "A/B:  " << C;
  std::cout << std::endl << std::endl;
}

void DivZeroTest() {
  std::cout << "Here the Divide Zero Test" << std::endl;
  Fraction A(2, 3), B(0, 1), C;
  std::cout << "A: " << A << "B: " << B;
  C = A / B;
  std::cout << "A/B:  " << C;
  std::cout << std::endl << std::endl;
}

void InitZeroTest() {
  std::cout << "Here the Initial Zero Test" << std::endl;
  Fraction A(1, 0);
  std::cout << std::endl << std::endl;
}

int main() {
  NormalTest();
  // DivZeroTest();
  // InitZeroTest();
  return 0;
}
