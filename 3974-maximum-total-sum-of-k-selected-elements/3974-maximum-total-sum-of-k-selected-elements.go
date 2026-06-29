func maxSum(nums []int, k int, mul int) int64 {
   var totSum int64 = 0 ; 
    // for _ , sum := range nums {
    //     totSum += int64(sum);
    // }

    sort.Ints(nums)

    for i := len(nums)-1 ;i >=len(nums) - k ; i-- {
        if  mul > 0 {
            totSum += int64(nums[i]) * int64(mul)
            mul--
        }else {
            totSum += int64(nums[i])
        }
    }

    return totSum;
}