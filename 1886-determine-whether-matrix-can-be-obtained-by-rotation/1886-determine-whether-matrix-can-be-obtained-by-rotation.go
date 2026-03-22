func rotate(mat [][]int){
    n := len(mat)

    //transpose 
    for i:= 0 ; i<n ; i++ {
        for j:= i ; j<n ; j++ {
            mat[i][j] , mat[j][i] = mat[j][i] , mat[i][j];
        }
    }
    //rev each row
    for i:= 0 ; i<n ; i++ {
        for j:= 0 ; j< n/2 ; j++ {
            k := n- j -1;
            mat[i][j] , mat[i][k] = mat[i][k] , mat[i][j];
        }
    }
}



func findRotation(matrix [][]int, target [][]int) bool {
   // n := len(matrix)

    for i:=0 ; i< 4 ; i++ {
        if equal(matrix , target) {
            return true;
        }
        rotate(matrix);

    }
    return false;

  
}


  func equal(a [][]int , b [][]int) bool {
        n := len(a);

        for i := 0 ; i< n ; i++{
            for j:=0 ; j<n ; j++{
                if(a[i][j] != b[i][j]){
                   return false;
                }
            }
        }

        return true;
    }