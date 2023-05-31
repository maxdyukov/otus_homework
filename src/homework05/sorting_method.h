#pragma once

#include <vector>

class SortingMethod{
    public:
     virtual void sort(std::vector<int>& data) = 0;
     virtual ~SortingMethod() = default;
};
