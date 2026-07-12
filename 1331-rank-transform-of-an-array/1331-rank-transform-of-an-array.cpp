class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int>sortedArr(arr);
        sort(sortedArr.begin(),sortedArr.end());
        int n = arr.size();
        if(n==0) return arr;
        map<int,int>mp;
      int rank= 1;
        mp[sortedArr[0]] = rank ;
        for(int i=1 ; i<n ; i++ ){
           if(sortedArr[i] > sortedArr[i-1]){
            rank++;
           }
           mp[sortedArr[i]] = rank;
            
           
        }
        for(int i=0 ; i<n ; i++ ){
            arr[i]   = mp[arr[i]];
        }
        return arr;

    }
};


// 40-1 10-2 20-3 30-4
//sortedarr 10 20 30 40
//arr : arr[i]  =mp(arr[i])   