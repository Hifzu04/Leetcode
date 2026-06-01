func minimumCost(cost []int) int {
    ////2 2 5 6 7 9
   // n := len(cost);
   // sort.Ints(cost)
    count :=0 
    sum := 0;
    sort.Sort(sort.Reverse(sort.IntSlice(cost)))

    for _ , val := range cost {
        if count == 2 {
        
            count = 0 
            continue
        }
        sum += val ;
        count++
        
    }
    return sum
}