class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int N=nums.size();

        //edge case 
        if(N == 1 && n==0) return true;
        if(N == 1 && n==1) return nums[0]==0;
       
       //greedily place flowers at vacant positions
        for(int i=0; i<N && n; ){
            if(nums[i] == 0){
                if((i == 0 && nums[i+1] == 0) ||
                   (i == N-1 && nums[i-1] == 0) ||
                   (i-1>=0 && i+1<N && nums[i-1] == 0 && nums[i+1]==0) ){
                    nums[i] = 1;
                    n--;
                    i += 2;
                }
                else i++;
            }
            else i += 2;
        }

        return n == 0 ;
    }
};
