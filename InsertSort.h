#ifndef INSERTSORT_H
#define INSERTSORT_H
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class InsertSort
{
    private:
        bool insert_sort(vector<int> &nums);

    public:
        InsertSort();
        virtual ~InsertSort();
        int sort_it(vector<int> &nums);
        void print_it(vector<int> &nums);
};

#endif /* INSERTSORT_H */
