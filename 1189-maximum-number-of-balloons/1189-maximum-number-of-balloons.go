func maxNumberOfBalloons(text string) int {
	freq := make(map[rune]int)

	for _, ch := range text {
		freq[ch]++
	}

	return min(
		freq['b'],
		freq['a'],
		freq['l']/2,
		freq['o']/2,
		freq['n'],
	)
}

func min(nums ...int) int {
	ans := nums[0]

	for _, num := range nums {
		if num < ans {
			ans = num
		}
	}

	return ans
}