#include "SelectSort.h"

SelectSort::SelectSort()
{

}

SelectSort::~SelectSort()
{

}

int SelectSort::sort_it(vector<int> &nums)
{
    select_sort(nums);
    return 0;
}

void SelectSort::print_it(vector<int> &nums)
{
    for (auto item: nums) {
        printf("%d ", item);
    }
    printf("\n");
}

bool SelectSort::select_sort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int min_id = i;
        for (int j = i+1; j < n; j++) {
            if (nums[j] < nums[min_id]) {
                min_id = j;
            }
        }
        swap(nums[i], nums[min_id]);
    }
    return true;
}

int main(int argc, char *argv[])
{
    vector<int> nums[] = {{7,3,1,5,2,9,10,44,22,3,6,1},
                        {9,8,7},
                        {1}};
    SelectSort s;
    for (auto &num: nums) {
        s.print_it(num);
        s.sort_it(num);
        s.print_it(num);
        printf("---------------------------------\n");
    }
    return 0;
}

