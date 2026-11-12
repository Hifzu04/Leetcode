class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> merged;
        for(int i =   0 ; i <intervals.size() ; i++){
            if(i==0 || merged.back()[1] < intervals[i][0] ){
                merged.push_back(intervals[i]);
            }else {
                merged.back()[1] = max(intervals[i][1] , merged.back()[1]);
            }
        }
        return merged ; 

        // [[1,3],[2,6],[8,10],[15,18]]  
        //sort 
        // if its first el or mergerd[1] < vec[i][0] : merge.push_back(curr);
        //else merge it : marged.back()[1] = max(merge.back()[1] , vec[1])
        
    }
};