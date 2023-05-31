#pragma once

#include "inserting_sort.h"
#include "merge_sort.h"
#include "selection_sorting.h"

// Абстрактная фабрика для создания экземпляров методов сортировки
class SortingMethodFactory {
 public:
  virtual SortingMethod* createSortingMethod() = 0;
};

// Конкретные фабрики, реализующие создание экземпляров различных методов
// сортировки

class SelectionSortFactory : public SortingMethodFactory {
 public:
  SortingMethod* createSortingMethod() override { return new SelectionSort(); }
};

class InsertionSortFactory : public SortingMethodFactory {
 public:
  SortingMethod* createSortingMethod() override { return new InsertingSort(); }
};

class MergeSortFactory : public SortingMethodFactory {
 public:
  SortingMethod* createSortingMethod() override { return new MergeSort(); }
};

class FactorySort {
 public:
  static void performSorting(SortingMethodFactory* factory,
                             std::vector<int>& data) {
    SortingMethod* sortingMethod = factory->createSortingMethod();
    sortingMethod->sort(data);
    delete sortingMethod;
  }
};