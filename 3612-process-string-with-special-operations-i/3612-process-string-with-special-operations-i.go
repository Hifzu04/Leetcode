func processStr(s string) string {
	ans := ""

	reverse := func(str string) string {
		r := []rune(str)
		for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
			r[i], r[j] = r[j], r[i]
		}
		return string(r)
	}

	for i := 0; i < len(s); i++ {
		switch s[i] {
		case '#':
			ans += ans
		case '%':
			ans = reverse(ans)
		case '*':
			if len(ans) > 0 {
				ans = ans[:len(ans)-1]
			}
		default:
			ans += string(s[i])
		}
	}

	return ans
}