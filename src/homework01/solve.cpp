#include <vector>
#include <math.h>
#include <stdexcept>
#include <float.h>
// const double epsilon{std::numeric_limits<double>::min()};
const double epsilon{0.001};

bool isEqual(double x, double y, double eps) { return std::fabs(x - y) < eps; }

std::vector<double> solve(double a, double b, double c) {
  if (isEqual(a, 0.0, epsilon)) {
    throw std::invalid_argument("The a is zero");
  }
  if (a == DBL_MAX || b == DBL_MAX || c == DBL_MAX){
    throw std::invalid_argument("Argument is very bigest");
  }
  long double D = b * b - 4 * a * c;
  if (D < 0.0 ) {
    return {};
  } else if (isEqual(D, 0.0, epsilon)){
    double x = -(b / (2 * a));
    return {x, x};
  } else{
    double x1 = ((-b) + sqrt(D)) / (2 * a);
    double x2 = ((-b) - sqrt(D)) / (2 * a);
    return {x1, x2};
  }
  return {};
}