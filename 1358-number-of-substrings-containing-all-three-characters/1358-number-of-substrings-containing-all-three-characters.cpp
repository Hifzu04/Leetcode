class Solution {
public:
    // bool isValid(string temp){

    //        if(temp.size() >= 3 && temp.contains('a')  && temp.contains('b')
    //        &&temp.contains('c') ){
    //              return true;
    //       }
    //        return true;
    // }
    //     for(int i = 0 ; i< n ; i++){
    //         string temp = "";
    //         for(int j =i ; j<n ; j++){
    //             temp.push_back(s[j]);
    //             if(isValid(temp)){
    //                 ans++;
    //             }

    //         }
    //     }

    //     return ans;
    // }

    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        int i = 0;
        int j = 0;
        vector<int> mp(3, 0);

        while (i < n) {
            char ch = s[i];
            mp[ch - 'a']++;
            while (mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                ans += (n - i);
                mp[s[j] - 'a']--;
                j++;
            }
            i++;
        }
        return ans;
    }
};

// a a a c  c b
//  a b c a b