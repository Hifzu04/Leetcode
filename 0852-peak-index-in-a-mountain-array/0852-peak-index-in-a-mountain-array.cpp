class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l = 0;
        int r = arr.size()-1;
       
        while(l <= r){
            int mid = l + (r-l) /2 ;
            if(mid !=0 && arr[mid] > arr[mid-1] && mid != arr.size()-1 && arr[mid] > arr[mid+1]){
                  return mid;
            }else if (mid != arr.size()-1 && arr[mid] < arr[mid+1]){
                l = mid+1;
            }else if (mid != 0){
                r = mid -1 ;
            }
        }

        return -1 ;
    }
};

//1 2  4  5 9  100 65 9 2 

