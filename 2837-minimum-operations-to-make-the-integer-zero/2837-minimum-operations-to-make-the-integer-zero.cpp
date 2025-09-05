class Solution {
 public:
  int makeTheIntegerZero(long long num1, long long num2) {


    for (int t = 0; t <= 60; t++) {
     long long target = num1 - t * num2;
      if (__builtin_popcountl(target) <= t && t <= target)
        return t;
    }

    return -1;
  }
};