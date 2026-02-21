class Solution {
public:
    bool detectCapitalUse(string word) {
        int rangeA = 'A';
        int rangeB = 'Z';
        int cap = 0;
        int small = 0;
        for(int i = 0 ; i<word.size() ; i++){
            if(word[i] >=rangeA && word[i] <=rangeB ){
                  cap++;
            } else {
                small++;
            }
        }
        if(cap == word.size() || small== word.size() || (cap==1 && word[0] >= rangeA && word[0] <= rangeB) )return true;
        
        else return false;




    }
};