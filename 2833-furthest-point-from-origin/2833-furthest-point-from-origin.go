 func abs(n int) int {
        if n < 0 {
            return n*-1 
        } 
         return n
    }
    

func furthestDistanceFromOrigin(moves string) int {


    countLeft := 0
    countRight := 0 
    
    for i := 0 ; i< len(moves) ; i++ {
        if moves[i] == 'L' {
            countLeft++
        }else if moves[i] == 'R' {
            countRight++
        }
    }
   

    return abs(countLeft-countRight) + (len(moves) - countLeft - countRight)


}