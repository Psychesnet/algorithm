#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class BubbleSort
{
    private:
        bool bubble_sort(vector<int> &nums);

    public:
        BubbleSort();
        virtual ~BubbleSort();
        int sort_it(vector<int> &nums);
        void print_it(vector<int> &nums);
};

#endif /* BUBBLESORT_H */
