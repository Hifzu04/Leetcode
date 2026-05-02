




func check(n int) bool {
    flag := false;
    for n > 0 {
        u := n%10 
        if u== 3 || u== 4 || u ==7 {
            return false 
        }
        if u == 2 || u == 5 || u == 6 || u == 9 {
           flag = true;
        }
        n /= 10 
    }

    return flag ;
}

func rotatedDigits(nums int) int {
    count := 0
    for i:= 1 ; i<= nums ; i++ {
         if check(i) == true {
            count++;
         }
    }
    return count
}