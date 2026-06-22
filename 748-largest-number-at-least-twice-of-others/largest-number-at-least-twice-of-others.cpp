class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int max=nums[0];
        int ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>=max){
                max=nums[i];
                ans=i;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=ans && nums[ans]<2*nums[i]){
                return -1;
            }
        }
      return ans;
    }
};