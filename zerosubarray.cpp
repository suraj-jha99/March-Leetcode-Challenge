class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();

        long long sum=0,ans=0;
        for(int i=0; i<n;){
            if(nums[i]==0){
                int cnt=0;
                while(i<n && nums[i]==0){
                 cnt++;
                 ans += cnt;
                 i++;
             }
           }
           else i++;
        }

        return ans;
    }
};
