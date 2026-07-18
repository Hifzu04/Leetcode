func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}




func findGCD(arr []int) int {
    min := arr[0]
	max := arr[0]

	// Single loop evaluates both conditions for maximum performance
	for _, num := range arr {
		if num < min {
			min = num
		}
		if num > max {
			max = num
		}
	}

    return gcd(min,max)

}