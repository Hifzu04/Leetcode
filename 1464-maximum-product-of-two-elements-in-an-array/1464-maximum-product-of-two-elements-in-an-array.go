func maxProduct(nums []int) int {
    maxm := math.MinInt;
    Smaxm := maxm;
    for _ , x := range nums {
        if x > maxm{
              Smaxm =maxm ;
            maxm =x;
          
        } else if  x > Smaxm {
            Smaxm = x;
        }

        
    }

    return (Smaxm-1)* (maxm-1) ;
}