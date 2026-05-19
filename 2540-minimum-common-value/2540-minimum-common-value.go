func getCommon(nums1 []int, nums2 []int) int {
    n := len(nums1)
    m := len(nums2)
    i := 0 ; j :=0 ;
    for i<n && j<m {
        if nums1[i] < nums2[j] {
            i++
        }else if nums1[i] > nums2[j] {
            j++;
        }else {
            return nums1[i];
        }
    }

    return -1;
}