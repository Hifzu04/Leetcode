 
func minElement(nums []int) int {
    n := len(nums)
    ans := 10000000

   findsum := func(element int) int {
        currsum := 0
        for element > 0 {
            currsum += element % 10
            element /= 10
        }
        return currsum
    }


    for i := 0 ; i< n ; i++ {
        cursum := findsum(nums[i])
        ans = min(ans , cursum)
    }

    return ans
    
}