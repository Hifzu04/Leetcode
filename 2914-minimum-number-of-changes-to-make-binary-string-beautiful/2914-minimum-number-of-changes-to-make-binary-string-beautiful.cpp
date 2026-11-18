class Solution {
public:
    int minChanges(string s) {
         int count = 0 ; 
         int n = s.size();
        for(int i =1 ; i< n ; i++){
            if(( i % 2 == 0 )) {
                continue;
            }
            if( ( s[i] != s[i-1])) {
                count++;
            }

           
          }

        return count;
    }
};


/*


*/