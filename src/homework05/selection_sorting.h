#pragma once

#include "sorting_method.h"

class SelectionSort : public SortingMethod {
 public:
  void sort(std::vector<int> &data) override {
    for (int i = 0; i < data.size() - 1; i++) {
      int min_index = i;
      for (int j = i + 1; j < data.size(); j++) {
        if (data[j] < data[min_index]) {
          min_index = j;
        }
      }
      if (min_index != i) {
        std::swap(data[i], data[min_index]);
      }
    }
  }
  ~SelectionSort() = default;
};