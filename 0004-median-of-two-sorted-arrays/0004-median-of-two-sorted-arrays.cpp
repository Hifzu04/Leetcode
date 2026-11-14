class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>num3 ;
        int i = 0 ; int j = 0 ;
        int n = nums1.size(); 
        int m = nums2.size();
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                num3.push_back(nums1[i]);
                i++;
            }else {
                num3.push_back(nums2[j]);
                j++;
            }
        }
         
         if(i < n) {
            for(int idx =  i ; idx < n ; idx++){
                num3.push_back(nums1[idx]);
            }
         }
          if(j < m) {
            for(int idx =  j ; idx < m ; idx++){
                num3.push_back(nums2[idx]);
            }
         }
        int s = num3.size();
        return num3.size()%2 == 0 ? ( num3[s/2] + num3[(s/2)-1] )/2.0 :  num3[num3.size()/2.0] ;
    }
};

/*
merge the array a
*/