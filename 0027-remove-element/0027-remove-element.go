func removeElement(nums []int, val int) int {
    k := 0  ;
    for idx , _ := range nums {
        if nums[idx] != val {
            nums[k] = nums[idx];
            k++;
        } 
    }
    return k;
}