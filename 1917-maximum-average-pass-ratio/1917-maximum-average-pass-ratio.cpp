class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>>maxheap;

        int n = classes.size();
        vector<double>delta(n);
        for(int i = 0  ; i<n ; i++){
            double curr = (double)classes[i][0]/classes[i][1];
            double newrat = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = newrat -curr;
            maxheap.push({delta, i});
        }

        while(extraStudents--){
            auto maxdel = maxheap.top();
            maxheap.pop();

            double delta = maxdel.first;
            double idx = maxdel.second;
            classes[idx][0]++;
            classes[idx][1]++;

             double curr = (double)classes[idx][0]/classes[idx][1];
            double newrat = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta = newrat -curr;

            maxheap.push({delta , idx});
        }

        double ans =0.0;
        for(int i = 0 ; i<n ; i++){
            ans+= (double)classes[i][0]/classes[i][1];
        }
        return ans/n;


    }
};