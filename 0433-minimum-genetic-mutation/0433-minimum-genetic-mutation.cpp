class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankset(bank.begin() , bank.end());
        unordered_set<string>visited;
        queue<string>q; 
        q.push(startGene);
        visited.insert(startGene);
        int level = 0 ;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i< n ; i++){
                string curr = q.front();
    
                q.pop();

                if(curr== endGene) return level;
                for(auto ch : "ACGT"){
                    for(int i = 0 ; i< curr.size() ; i++){
                        string newstring = curr;
                        newstring[i] = ch;
                        if(visited.find(newstring) == visited.end() 
                        && bankset.find(newstring )!= bankset.end()){
                            q.push(newstring);
                            visited.insert(newstring);
                        }
                    }
                }
               
            }
             level++;
        }
        return -1;

    }
};