class Solution {
public:
    string decodeString(string s) {

        stack<string> charstack;
        stack<int> numstack;

        string ans = "";
        int num = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }

            else if (s[i] == '[') {
                numstack.push(num);
                 num = 0;
               
                charstack.push("[");
            }

            else if (s[i] >= 'a' && s[i] <= 'z') {
                charstack.push(string(1, s[i]));
            }

            else if (s[i] == ']') {

                string temp = "";

                while (charstack.top() != "[") {
                    temp += charstack.top() ;
                    charstack.pop();
                }

                charstack.pop(); // remove '['

                int count = numstack.top();
                numstack.pop();

                string decoded = "";

                for (int j = 0; j < count; j++) {
                    decoded += temp;
                }

                charstack.push(decoded);
            }
        }

        while (!charstack.empty()) {
            ans += charstack.top() ;
            charstack.pop();
        }

         reverse(ans.begin()  , ans.end());
         return ans;
    }
};