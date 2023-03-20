#include <vector>
#include <math.h>
#include <stdexcept>

bool isEqual(double x, double y){
  return std::fabs(x - y) < std::numeric_limits<double>::min();
}

std::vector<double> solve(double a, double b, double c) {
    if (isEqual(a, 0.0)){
      throw std::invalid_argument("a is zero");
    }
    
    if(b == 0 && a > 0 && c > 0){
      return {};
    } else if ( b == 0 && a > 0 && c < 0){
      double root = std::sqrt(std::fabs(c));
      return {root, -1.0 * root};
    }

    double D = b * b - 4 * a * c;
    if (D == 0){
      double x1 = -(b / (2 * a));
      return {x1, x1};
    }

    return {};
}