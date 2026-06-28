func minimumAbsDifference(arr []int) [][]int {
    sort.Ints(arr)
    ans := [][]int{}
    minDiff := arr[1] - arr[0]
    for i:= 1 ; i< len(arr) ; i++ {
        if minDiff > arr[i] - arr[i-1] {
            minDiff = arr[i] - arr[i-1]
        }
    }
    for i:= 1 ; i< len(arr) ; i++ {
           if minDiff == arr[i] -arr[i-1] {
             	ans = append(ans, []int{arr[i-1], arr[i]})
           }
        
    }
    return ans
}