class Solution {
public:
    string addBinary(string a, string b) {
        //int a_int = stoi(a);
       // int b_int = stoi(b);

        //  long long base = 1;
        //   long long decimal_a =0;
        //   long long  decimal_b =0; 
        //   for(int i =a.size()-1 ; i>= 0 ; i--){
        //          decimal_a += base*(a[i]-'0') ;
        //          base *=2;
        //   }
        //   base = 1;
        //   for(int i =b.size()-1 ; i>= 0 ; i--){
        //          decimal_b += base*(b[i]-'0') ;
        //          base*=2;
        //   }
           
        //  int sum = decimal_a + decimal_b;
        // return to_string(sum);

         int i = a.size()-1;
         int j = b.size()-1;
         string ans ="";
         
         int carry  = 0;
         while(i>= 0  ||  j>= 0){
            int sum = 0 ;
            if(i>=0){
                sum+= (a[i] -'0');
                i--;

            }
            if(j>=0){
                sum+= (b[j] - '0');
                j--;
            }
            sum += carry ;
            if(sum > 1){
                carry = 1;
            } else carry = 0;
            

            ans.push_back((sum%2==0) ? '0' : '1');



         }

         if(carry){
            ans.push_back('1');
         }

       (reverse(ans.begin() , ans.end()));
       return ans;

          



         

    }
};