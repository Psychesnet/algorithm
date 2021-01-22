#ifndef MERGESORT_H
#define MERGESORT_H
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class MergeSort
{
    private:
        bool merge_sort(vector<int> &nums, vector<int> &tmps,
                const int left, const int right);

    public:
        MergeSort();
        virtual ~MergeSort();
        int sort_it(vector<int> &nums);
        void print_it(vector<int> &nums);
};

#endif /* MERGESORT_H */
