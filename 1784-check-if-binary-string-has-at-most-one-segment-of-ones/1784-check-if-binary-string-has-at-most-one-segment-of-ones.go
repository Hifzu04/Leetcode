func checkOnesSegment(s string) bool {
    for i := 1 ; i< len(s) ; i++ {
        if s[i-1] == '0' && s[i] == '1' {
            return false ;
        }
    }
    return true;
}