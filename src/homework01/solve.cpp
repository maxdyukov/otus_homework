#include <vector>
#include <math.h>
#include <stdexcept>

// const double epsilon{std::numeric_limits<double>::min()};
const double epsilon{0.001};

bool isEqual(double x, double y, double eps) { return std::fabs(x - y) < eps; }

std::vector<double> solve(double a, double b, double c) {
  if (isEqual(a, 0.0, epsilon)) {
    throw std::invalid_argument("The a is zero");
  }

  if(isEqual(b, 0.0, epsilon) && a > 0 && c > 0){
    return {};
  } else if (isEqual(b, 0.0, epsilon) && a > 0 && c < 0){
    double root = std::sqrt(std::fabs(c/a));
    return {root, -1.0 * root};
  }
  double D = b * b - 4 * a * c;
  if (isEqual(D, 0.0, epsilon)){
    double x1 = -(b / (2 * a));
    return {x1, x1};
  } else {
      
  }

    return {};
}