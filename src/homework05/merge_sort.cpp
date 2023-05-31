#include "merge_sort.h"

  // Функция для слияния двух отсортированных массивов
  void MergeSort::merge(std::vector<int>& arr, int left, int mid, int right)
  {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создаем временные массивы для хранения значений
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Копируем данные во временные массивы
    for (int i = 0; i < n1; ++i) {
      leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
      rightArr[j] = arr[mid + 1 + j];
    }

    // Объединяем временные массивы обратно в основной массив
    int i = 0;     // Индекс для левого подмассива
    int j = 0;     // Индекс для правого подмассива
    int k = left;  // Индекс для объединенного массива

    while (i < n1 && j < n2) {
      if (leftArr[i] <= rightArr[j]) {
        arr[k] = leftArr[i];
        ++i;
      } else {
        arr[k] = rightArr[j];
        ++j;
      }
      ++k;
    }

    // Копируем оставшиеся элементы левого подмассива, если они есть
    while (i < n1) {
      arr[k] = leftArr[i];
      ++i;
      ++k;
    }

    // Копируем оставшиеся элементы правого подмассива, если они есть
    while (j < n2) {
      arr[k] = rightArr[j];
      ++j;
      ++k;
    }
  }

  // Функция сортировки слиянием
  void  MergeSort::mergeSort(std::vector<int>& arr, int left, int right)
  {
    if (left >= right) {
      return;  // Возвращаемся, если в массиве меньше двух элементов
    }

    int mid = left + (right - left) / 2;  // Находим средний индекс

    mergeSort(arr, left, mid);  // Рекурсивно сортируем левую половину
    mergeSort(arr, mid + 1, right);  // Рекурсивно сортируем правую половину

    merge(arr, left, mid, right);  // Слияние двух отсортированных половин
  }