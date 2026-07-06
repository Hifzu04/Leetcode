func getRange(val int) int {
    smallest := 10 
    largest := 0
    for val > 0 {
        dig := val%10
        if dig > largest {
            largest = dig
        }
        if dig < smallest {
            smallest = dig
        }

        val/=  10 
    }
    return largest - smallest
}

func maxDigitRange(nums []int) int {
    digitRange := make([]int ,  len(nums));
    for i:= 0 ; i< len(nums) ; i++ {
        digitRange[i] = getRange(nums[i])
    }
    maxVal := slices.Max(digitRange)
    ans := 0
    for i:=0 ; i<len(nums) ; i++ {
        if digitRange[i] == maxVal {
            ans += nums[i]
        }
    }
    return ans

}



//getdigit range and store them in digitrange vector
//get max digit range from vector
// if digitRange[i] == max digit range , sum += nums[i];
//return sum