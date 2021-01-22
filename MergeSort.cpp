#include "MergeSort.h"

MergeSort::MergeSort()
{

}

MergeSort::~MergeSort()
{

}

int MergeSort::sort_it(vector<int> &nums)
{
    vector<int> tmps(nums.size(), 0);
    // boundary -> [0, nums.size())
    merge_sort(nums, tmps, 0, nums.size());
    return 0;
}

void MergeSort::print_it(vector<int> &nums)
{
    for (auto item: nums) {
        printf("%d ", item);
    }
    printf("\n");
}

bool MergeSort::merge_sort(vector<int> &nums, vector<int> &tmps,
        const int left, const int right)
{
    if (left+1 >= right) {
        // 切割到只剩一個
        return false;
    } else {
        int mid = (right+left)/2;
        merge_sort(nums, tmps, left, mid);
        merge_sort(nums, tmps, mid, right);
        int L = left;
        int R = mid;
        int i = left;
        while (L < mid || R < right) {
            if (L < mid && R < right) {
                if (nums[L] <= nums[R]) {
                    tmps[i++] = nums[L++];
                } else {
                    tmps[i++] = nums[R++];
                }
            } else if (L < mid) {
                tmps[i++] = nums[L++];
            } else {
                tmps[i++] = nums[R++];
            }
        }
        for (int j=left; j<right; ++j) {
            nums[j] = tmps[j];
        }
        return true;
    }
}

int main(int argc, char *argv[])
{
    vector<int> nums[] = {{7,3,1,5,2,9,10,44,22,3,6,1},
                        {9,8,7},
                        {1}};
    MergeSort s;
    for (auto &num: nums) {
        s.print_it(num);
        s.sort_it(num);
        s.print_it(num);
        printf("---------------------------------\n");
    }
    return 0;
}

