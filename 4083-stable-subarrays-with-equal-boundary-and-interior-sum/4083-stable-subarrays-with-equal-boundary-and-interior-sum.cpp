
class Solution{
public:
long long countStableSubarrays(vector<int>&v){
int n=v.size();
vector<long long>ps(n);
ps[0]=v[0];
for(int i=1;i<n;i++)ps[i]=ps[i-1]+v[i];
map<pair<int,long long>,long long>cnt;
long long ans=0;
for(int j=0;j<n;j++){
long long val=v[j],sum=ps[j];
if(j>=2){
int i=j-2;
long long x=v[i],pref=i?ps[i-1]:0;
cnt[{x,pref+3*x}]++;
}
auto it=cnt.find({val,sum});
if(it!=cnt.end())ans+=it->second;
}
return ans;
}
};


//totalSum
//var : currsum[i] , midsum = totsum - cursum
//if(i =j) then vec[i] == midsum cnt++;
//cursum+= vecc[i]+vec[j];