class Solution {
public:
    string maskPII(string s) {
        // EMAIL CASE
        if (s.find('@') != string::npos) {
            // convert to lowercase
            for (char &c : s) c = tolower(c);

            int atPos = s.find('@');
            string ans;
            ans += s[0];                 // first letter
            ans += "*****";              // mask
            ans += s[atPos - 1];         // last letter of name
            ans += s.substr(atPos);      // domain
            return ans;
        }

        // PHONE CASE
        string digits = "";
        for (char c : s) {
            if (isdigit(c)) digits += c;
        }

        int countryLen = digits.length() - 10;
        string localLast4 = digits.substr(digits.length() - 4);

        string ans = "";
        if (countryLen > 0) {
            ans += "+";
            ans += string(countryLen, '*');
            ans += "-";
        }

        ans += "***-***-";
        ans += localLast4;

        return ans;
    }
};
