func areSimilar(mat [][]int, k int) bool {
     n :=  len(mat);
     m := len(mat[0]);

    for i:=0 ; i<n ; i++ {
        for j:= 0 ; j< m ; j++ {
            if mat[i][j] != mat[i][(j+k)% m] {
                return false;
            }
        }
    }

    return true;
}