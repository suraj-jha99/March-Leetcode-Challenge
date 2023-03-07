class Solution {
public:
//binary searching the search space
    bool isPossible(long long ans,long long trips,vector<int> &time){
        long long cnt=0;
        for(int &x: time){
            cnt += ans/x;
        }

        return cnt >= trips;
    }
    long long minimumTime(vector<int>& time, int trips) {
        int maxi = INT_MIN;
        //find max trip time
        for(int &x: time){
             maxi = max(maxi,x);
        }

        unsigned long long st=1,end=(unsigned long long)maxi*trips;
        long long ans=end;
        while(st <= end){
            long long mid = st + (end-st)/2;

            if(isPossible(mid,trips,time)){
                ans = min(ans,mid);//or just ans = mid
                end=mid-1;
            }
            else st=mid+1;
        }

        return ans;
    }
};
