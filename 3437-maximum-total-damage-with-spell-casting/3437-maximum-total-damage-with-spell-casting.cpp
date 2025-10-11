class Solution {
    typedef long long ll;
    int n;                                
    unordered_map<ll,ll> mpp;      
    vector<ll> t;
public:
 ll f(int idx , vector<ll>&vec ){
     if(idx >= vec.size()){
        return 0;
     }
     if (t[idx] != -1) return t[idx];

     ll nottake =0+ f(idx+1 , vec );
     int j = lower_bound(vec.begin()+idx +1 , vec.end() , vec[idx]+3) - vec.begin();
     ll take = vec[idx]*mpp[vec[idx]] + f(j , vec  );

     return t[idx] = max(take, nottake);
 }

    long long maximumTotalDamage(vector<int>& power) { 
       
       
      
       for (int x : power) 
            mpp[x]++;
  vector<ll> vec(mpp.size());
   for (auto &p : mpp)
            vec.push_back(p.first);

        sort(begin(vec), end(vec));
          n = vec.size();
        t.assign(n, -1);
       

       return f(0 , vec );
       
    }
};