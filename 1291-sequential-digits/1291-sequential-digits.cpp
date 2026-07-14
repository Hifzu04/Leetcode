class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        //bfs
        queue<int>q;
        vector<int>vec;
         for(int i =1; i<=8 ; i++){
            q.push(i);
         }
         while(!q.empty()){
            int curr = q.front();
            if(curr > high) break;
            q.pop();
            if(curr >= low && curr<= high){
                vec.push_back(curr);
            }
            if (curr%10 != 9)
            q.push(curr*10 + (curr%10)+1);    

         }
         return vec;
    }
};