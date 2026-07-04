class Solution {
public:
     
     int binarySearch(vector<int>&nums , int i , int j , int target){
        while(i<= j){
            int mid = i + (j-i) /2;
            if(nums[mid] == target){
                return mid;
            }else if (nums[mid] < target){
                i = mid+1;
            }else {
                j = mid-1;
            }
        }
        return -1 ;
     }
   
    int findpivot(vector<int>& nums, int i, int j) {

        while (i <= j) {
            if (nums[i] <= nums[j]) {
                return i;
            }
            int mid = i + (j - i) / 2;
            if (nums[mid] > nums[j]) {
                i = mid + 1;
            } else {
                j = mid ;
            }
        }
        return i;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // Pivot return index of min ele
        int pivot = findpivot(nums, 0, n - 1);

        if (nums[pivot] == target) {
            return pivot;
        }

        if (pivot == 0)
            return binarySearch(nums, 0, n - 1, target);

        if (nums[0] <= target)
            return binarySearch(nums, 0, pivot - 1, target);

        return binarySearch(nums, pivot + 1, n - 1, target);
    }
};

// 3 approach
// 1 : U know
// 2 : divide the nums into 2 sorted array and apply binary search
// 3  : dont divide , just keep on finding