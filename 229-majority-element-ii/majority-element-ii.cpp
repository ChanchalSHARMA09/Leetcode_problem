class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj1 = INT_MIN;
        int maj2 = INT_MIN;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maj1) {
                cnt1++;
            } else if (nums[i] == maj2) {
                cnt2++;
            } else if (cnt1 == 0) {
                maj1 = nums[i];
                cnt1++;
            } else if (cnt2 == 0) {
                maj2 = nums[i];
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
      vector<int>res;

      int freq1=0;
      int freq2=0;
      for(int &num: nums){
        if(num==maj1){
            freq1++;
        }
        if(num==maj2){
            freq2++;
        }
      }
      if(freq1> floor(n/3)){
        res.push_back(maj1);
      }
      if(freq2> floor(n/3)){
        res.push_back(maj2);
      }
      return res;
    }
};