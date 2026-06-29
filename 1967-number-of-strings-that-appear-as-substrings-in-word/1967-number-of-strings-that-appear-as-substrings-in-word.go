func numOfStrings(patterns []string, word string) int {
    
    ans := 0;
    for _ , pattern := range patterns {
        if strings.Contains(word , pattern){
            ans++
        }
    }
    return ans;
}