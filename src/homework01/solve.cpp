#include <vector>
#include <math.h>

std::vector<double> solve(double a, double b, double c) {
    if(b == 0 && a > 0 && c > 0){
      return {};
    } else if ( b == 0 && a > 0 && c < 0){
      double root = std::sqrt(std::abs(c));
      return {root, -1.0 * root};
    }

    double D = b * b - 4 * a * c;
    if (D == 0){
      double x1 = -(b / (2 * a));
      return {x1, x1};
    }
    
    return {};
}