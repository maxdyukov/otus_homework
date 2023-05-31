#pragma once

#include "sorting_method.h"

class InsertingSort : public SortingMethod {
 public:
  void sort(std::vector<int> &data) override {
    int n = data.size();

    for (int i = 1; i < n; ++i) {
        int key = data[i];
        int j = i - 1;

        // Перемещаем элементы большие, чем key, на одну позицию вперед
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }

        data[j + 1] = key;
    }
  }
  ~InsertingSort() = default;
};