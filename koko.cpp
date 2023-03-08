class Solution {
public:
    bool isPossible(int speed,vector<int> &nums,int h){
        long long hr=0;

        for(int x: nums){
            if(x % speed != 0){
                hr += x/speed  + 1;
            }
            else hr += x/speed;
        }

        if(hr > h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        //min and max eating speed can be
        int st=1;
        int end=*max_element(nums.begin(),nums.end());
        
        int ans=end;//max speed
        while(st <= end){
            int mid = st + (end-st)/2;

            if(isPossible(mid,nums,h)){
                ans = min(ans,mid);
                end = mid - 1;
            }

            else st = mid + 1;
        }

        return ans;
    }
};
