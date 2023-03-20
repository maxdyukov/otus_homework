#include <vector>
#include <math.h>

std::vector<double> solve(double a, double b, double c) {
    if(b == 0 && a > 0 && c > 0){
      return {};
    } else if ( b == 0 && a > 0 && c < 0){
      double root = std::sqrt(std::abs(c));
      return {root, -1.0 * root};
    }

    return {};
}