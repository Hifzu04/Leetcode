class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin() ,hBars.end());
        sort(vBars.begin() , vBars.end());
        int  hsize =hBars.size();
        int vsize = vBars.size();

        int maxh = 1;
        int TotH= 1;

        for(int i =0  ; i< hsize-1 ; i++){
            if(hBars[i+1]- hBars[i] ==1 ){
                maxh++;
                 TotH = max(maxh , TotH);
            }else maxh= 1 ;
       
        }
        int maxv =1  ;
        int TotV= 1;

         for(int i =0  ; i< vsize-1 ; i++){
            if(vBars[i+1]- vBars[i] ==1 ){
                maxv++;
                     TotV = max(maxv , TotV);
            }else maxv= 1;
       
        }

        int common = min(TotV , TotH);
       common+=1 ;
        return common*common;
    }
};