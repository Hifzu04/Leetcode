class Solution {
public:
    int numWaterBottles(int bhara, int frate) {
      int ans = bhara;
      int  newbottle = 0 ;
      int empty =0;
      while(bhara>=frate){
       newbottle = bhara/frate ;
       ans+=newbottle;
       empty = newbottle + (bhara%frate);
      bhara = empty; 
      }
      return ans;
    }
};