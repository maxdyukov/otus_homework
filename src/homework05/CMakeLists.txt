set(TARGET_NAME homework05)

add_library(${TARGET_NAME}
                           sorting_method.h
                           selection_sorting.h
                           inserting_sort.h
                           merge_sort.h
                           merge_sort.cpp
                           factory.h)

add_subdirectory(tests)