class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int minrepeat = b.size() / a.size();
        string na = "";
         int cnt = minrepeat ;
        while(cnt--){
            na +=a ;
        }
       

        if(na.find(b) != std::string::npos){
            return minrepeat;
        }
        na += a;
         if(na.find(b) != std::string::npos){
            return minrepeat+1;
        }

        na += a;
         if(na.find(b) != std::string::npos){
            return minrepeat+2;
        }

        return -1;
    }


};