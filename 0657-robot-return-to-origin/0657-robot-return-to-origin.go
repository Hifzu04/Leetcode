func judgeCircle(moves string) bool {
    //In go varibale default to zero no need to assign
  var  cntup , cntdown , cntrignt , cntleft int 
    for i :=0 ; i <len(moves) ; i++ {
        if (moves[i] == 'U') {
            cntup++;
        } else if (moves[i] == 'D'){
            cntdown++;
        } else if moves[i] == 'R'{
            cntrignt++;
        }else {
            cntleft++;
        }
    }


    if(cntup == cntdown && cntleft == cntrignt){
        return true;
    }

    return false ;
}