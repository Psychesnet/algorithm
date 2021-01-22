#ifndef SELECTSORT_H
#define SELECTSORT_H
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class SelectSort
{
    private:
        bool select_sort(vector<int> &nums);

    public:
        SelectSort();
        virtual ~SelectSort();
        int sort_it(vector<int> &nums);
        void print_it(vector<int> &nums);
};

#endif /* SELECTSORT_H */
