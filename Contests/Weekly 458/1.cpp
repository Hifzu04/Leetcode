#include<bits/stdc++.h>
using namespace std;
 
 string processStr(string s) {
        string result =""; 
        int n  = s.size();

        for(int i = 0 ; i< n ; i++){
            if(s[i]=='#'){
                result+=result;
            }
            else if(s[i]=='%'){
                reverse(result.begin() ,result.end());
                
            }
            else if(s[i]=='*'){
                //to remove the last char
                result.pop_back();
            }
            else{
                result+=s[i];
            }
        }
     //   if(result.size()==0) return "";
        return result;
    }

    int main(){
        string s ; cin>>s;
        cout<<processStr(s);
    }