class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // Find the maximum value in the input array
        int maxValue = ranges::max(nums);

        // Count frequency of each number in the input array
        vector<int> frequencyCount(maxValue + 1);
        for (int number : nums) {
            ++frequencyCount[number];
        }

        vector<long long> gcdPairCount(maxValue + 1);

    
        for (int gcd = maxValue; gcd >= 1; --gcd) {
         
            long long multiplesCount = 0;

            // Iterate through all multiples of current gcd
            for (int multiple = gcd; multiple <= maxValue; multiple += gcd) {
                multiplesCount += frequencyCount[multiple];

                
     
                gcdPairCount[gcd] -= gcdPairCount[multiple];
            }

    
            gcdPairCount[gcd] += multiplesCount * (multiplesCount - 1) / 2;
        }

        for (int i = 2; i <= maxValue; ++i) {
            gcdPairCount[i] += gcdPairCount[i - 1];
        }

        vector<int> result;
        for (const auto& query : queries) {
    
            int gcdValue = upper_bound(gcdPairCount.begin(), gcdPairCount.end(), query) - gcdPairCount.begin();
            result.push_back(gcdValue);
        }

        return result;
    }
};




//4 2  1 2 1 1 => 1 1 1 2  2 2 
//total pair = > n * (n-1) /2  
// sort 
// run the query           
//O(N^2)


//otp 
//nums = [4,4,2,1], => 1 4 4 8 12   20