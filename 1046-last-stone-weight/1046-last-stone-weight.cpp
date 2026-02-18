class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap;
        for(auto& x : stones){
              maxHeap.push(x);
        }

        while(maxHeap.size() >1){
            int heaviest = maxHeap.top();
            maxHeap.pop();
            int secondHeaviest = maxHeap.top();
            maxHeap.pop();
            if(heaviest != secondHeaviest){
                maxHeap.push(heaviest-secondHeaviest);
            }
        }


        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};