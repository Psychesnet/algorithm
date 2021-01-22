#include "InsertSort.h"

InsertSort::InsertSort()
{

}

InsertSort::~InsertSort()
{

}

int InsertSort::sort_it(vector<int> &nums)
{
    insert_sort(nums);
    return 0;
}

void InsertSort::print_it(vector<int> &nums)
{
    for (auto item: nums) {
        printf("%d ", item);
    }
    printf("\n");
}

bool InsertSort::insert_sort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        // 從後面向前，把目前的值換到比自已小的後面
        for (int j = i; j > 0; j--) {
            if (nums[j-1] > nums[j]) {
                swap(nums[j], nums[j-1]);
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
    InsertSort s;
    for (auto &num: nums) {
        s.print_it(num);
        s.sort_it(num);
        s.print_it(num);
        printf("---------------------------------\n");
    }
    return 0;
}

