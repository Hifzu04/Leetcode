func pivotArray(nums []int, pivot int) []int {
   
    ans := []int{}
    for _ , val := range nums {
        if val < pivot {
           ans = append(ans , val)
        }
    }

     for _ , val := range nums {
        if val == pivot {
           ans = append(ans , val)
        }
    }


    for _ , val := range nums {
        if val > pivot {
           ans = append(ans , val)
        }
    }


    return ans;
}