func getX(n int64) int64 {
     var x int64= 0;
   var unit int64 = 1

    for n > 0 {
        if(n%10 != 0){
              x+= unit * (int64(n) %10)
              unit *= 10 ;
        }
        n/=10;
       
    }
    return x 
}

func getSum(n int64) int64 {
   var  sum int64 = 0
    for n > 0 {
        sum += int64(n)%10 
        n/=10
    }
    return sum
}


func sumAndMultiply(n int) int64 {
    var x int64 = getX(int64(n))
    var  sum int64 = getSum(int64(x))
     return int64(x*sum)  
}