class Solution {
public:
    vector<int> beautifulArray(int n) {
        // Base case: array with single element is always beautiful
        if (n == 1) {
            return {1};
        }
      
        // Recursively build beautiful arrays for odd and even numbers
        // For n numbers, we need (n+1)/2 odd numbers and n/2 even numbers
        vector<int> oddPart = beautifulArray((n + 1) >> 1);   // Ceiling division: (n+1)/2
        vector<int> evenPart = beautifulArray(n >> 1);        // Floor division: n/2
      
        // Construct the result array of size n
        vector<int> result(n);
        int index = 0;
      
        // Transform and add odd numbers first (2*x - 1 transforms to odd)
        // This maintains the beautiful array property
        for (int& num : oddPart) {
            result[index++] = num * 2 - 1;
        }
      
        // Transform and add even numbers (2*x transforms to even)
        // Odd and even numbers together maintain the beautiful property
        for (int& num : evenPart) {
            result[index++] = num * 2;
        }
      
        return result;
    }
};