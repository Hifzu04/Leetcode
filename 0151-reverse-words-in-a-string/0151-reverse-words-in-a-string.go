func reverseWords(s string) string {
    words := []string{}
    i := 0
    n := len(s)

    for i < n {
        for i < n && s[i] == ' ' {
            i++
        }
        if i >= n {
            break
        }

        word := ""
        for i < n && s[i] != ' ' {
            word += string(s[i])
            i++
        }

        words = append(words, word)
    }

    res := ""
    for i := len(words) - 1; i >= 0; i-- {
        res += words[i]
        if i != 0 {
            res += " "
        }
    }

    return res
}