// header file for sort.cpp

#include<vector>

#ifndef SORT_H
#define SORT_H

void merge(std::vector<int> &v, int p, int q, int r);

void merge_sort(std::vector<int> &v, int p, int r);

void insertion_sort(std::vector<int> &v);

#endif
