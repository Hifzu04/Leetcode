func maximumElementAfterDecrementingAndRearranging(arr []int) int {
   n := len(arr);
    ans := 1;
    sort.Ints(arr)
    for _ , ele := range arr {
        if ele > ans {
           ans = ans+1;

        }
    }
    if ans > n {
       return n ;
    } 
    return ans
}

//if each el is less than size of arr: ans = largest ele
// other wise ans = size of the arr
//1 1 100 1  => 
//100 1 100
//1 2 3 6 7
//1 1 1  1 3 
//if nums[i] > ans ,ans = ans+1;
// ans = min(ans , arr.size)