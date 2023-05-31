#include <gtest/gtest.h>

#include "selection_sorting.h"
#include "inserting_sort.h"
#include "merge_sort.h"
#include "factory.h"


TEST(SortingTest, SelectionSortTest) {
    std::vector<int> data = {5, 2, 7, 1, 8, 4};

    FactorySort::performSorting(new SelectionSortFactory(), data);

    EXPECT_EQ(data, std::vector<int>({1, 2, 4, 5, 7, 8}));

}


TEST(SortingTest, InsertionSortTest) {
    std::vector<int> data = {5, 2, 7, 1, 8, 4};

    FactorySort::performSorting(new InsertionSortFactory(), data);

    EXPECT_EQ(data, std::vector<int>({1, 2, 4, 5, 7, 8}));
}

// Тестирование метода сортировки слиянием
TEST(SortingTest, MergeSortTest) {
    std::vector<int> data = {5, 2, 7, 1, 8, 4};

    FactorySort::performSorting(new MergeSortFactory(), data);

    EXPECT_EQ(data, std::vector<int>({1, 2, 4, 5, 7, 8}));


}