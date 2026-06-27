class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long , int > freqmap ;
        for (int  x : nums){
            freqmap[x]++;
        }

        int maxlen = freqmap[1] - (freqmap[1] % 2 ^1 );
         freqmap.erase(1);

        for(auto [key , freq] : freqmap){
            int currans = 0;
            long long base = key;
            while(freqmap.count(base) && freqmap[base] >1 ){
               
                base = base * base;
                 currans+=2 ;

            }

           currans += freqmap.count(base) ? 1 : -1;
           maxlen = max(maxlen , currans);
        }
        return maxlen;
    }
};