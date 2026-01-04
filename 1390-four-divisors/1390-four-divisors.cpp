class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0 ;
        set<int>st; 
        for(int i= 0 ; i<nums.size() ; i++){
            
           
            for(int div = 1 ; div*div<=nums[i]; div++){
                if(nums[i]%div==0){
                    st.insert(nums[i]/div);
                    st.insert(div);
                   
                    }
            }
            if(st.size()==4){
               for(auto &it :st){
                
                 sum+=it;

               }
            }
            st.clear();
        
        }
        return sum;
    }
};