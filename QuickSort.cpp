#include "QuickSort.h"

QuickSort::QuickSort()
{

}

QuickSort::~QuickSort()
{

}

int QuickSort::sort_it(vector<int> &nums)
{
    // boundary -> [0, nums.size())
    quick_sort(nums, 0, nums.size());
    return 0;
}

void QuickSort::print_it(vector<int> &nums)
{
    for (auto item: nums) {
        printf("%d ", item);
    }
    printf("\n");
}

bool QuickSort::quick_sort(vector<int> &nums, const int left, const int right)
{
    if (left+1 >= right) {
        return false;
    }
    int first = left;
    int last = right-1;
    int key = nums[first];
    while (first < last) {
        // find sth is smaller than key from right side
        while (first < last && nums[last] >= key) {
            --last;
        }
        // put small one to left side
        nums[first] = nums[last];
        // find sth is bigger than key from left side
        while (first < last && nums[first] <= key) {
            ++first;
        }
        // put big one to right side
        nums[last] = nums[first];
    }
    nums[first] = key;
    return (quick_sort(nums, left, first) | quick_sort(nums, first+1, right));
}

int main(int argc, char *argv[])
{
    vector<int> nums[] = {{7,3,1,5,2,9,10,44,22,3,6,1},
                        {9,8,7},
                        {1}};
    QuickSort s;
    for (auto &num: nums) {
        s.print_it(num);
        s.sort_it(num);
        s.print_it(num);
        printf("---------------------------------\n");
    }
    return 0;
}

