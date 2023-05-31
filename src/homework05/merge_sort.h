#pragma once

#include "sorting_method.h"

class MergeSort : public SortingMethod {
 public:
  void sort(std::vector<int>& data) override {
    mergeSort(data, 0, data.size() - 1);
  }
  ~MergeSort() = default;

 private:
  // Функция для слияния двух отсортированных массивов
  void merge(std::vector<int>& arr, int left, int mid, int right);
  // Функция сортировки слиянием
  void mergeSort(std::vector<int>& arr, int left, int right);
};