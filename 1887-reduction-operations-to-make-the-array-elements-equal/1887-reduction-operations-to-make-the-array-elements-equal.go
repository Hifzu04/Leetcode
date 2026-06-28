func reductionOperations(nums []int) int {
    sort.Ints(nums)
    totop, distgrp := 0 ,0;
    for i :=1 ; i< len(nums) ; i++ {
        if nums[i-1] != nums[i] {
            distgrp++
        }
        totop += distgrp;
    }
    return totop;
}


// 1 3 5 

// 1 1 2 2 3 
// 1 1 2 2 3 3 5 7   
// freq * (no of distinct ele -1 )--; 