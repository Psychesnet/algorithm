#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class QuickSort
{
    private:
        bool quick_sort(vector<int> &nums, const int left, const int right);

    public:
        QuickSort();
        virtual ~QuickSort();
        int sort_it(vector<int> &nums);
        void print_it(vector<int> &nums);
};


#endif /* ifndef QUICK_SORT_H */
