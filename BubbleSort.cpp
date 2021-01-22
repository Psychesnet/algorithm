#include "BubbleSort.h"

BubbleSort::BubbleSort()
{

}

BubbleSort::~BubbleSort()
{

}

int BubbleSort::sort_it(vector<int> &nums)
{
    bubble_sort(nums);
    return 0;
}

void BubbleSort::print_it(vector<int> &nums)
{
    for (auto item: nums) {
        printf("%d ", item);
    }
    printf("\n");
}

bool BubbleSort::bubble_sort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n-1; i > 0; --i) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
            }
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    vector<int> nums[] = {{7,3,1,5,2,9,10,44,22,3,6,1},
                        {9,8,7},
                        {1}};
    BubbleSort s;
    for (auto &num: nums) {
        s.print_it(num);
        s.sort_it(num);
        s.print_it(num);
        printf("---------------------------------\n");
    }
    return 0;
}

