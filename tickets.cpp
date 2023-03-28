class Solution {
public:
    //easy prob. of dp
    
    //app 2: recursion + memo
    int mincost(int idx,vector<int>& days, vector<int>& costs,int n,vector<int> &dp){
        //base case
        if(idx >= n){
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        //option 1 is taking 1 day pass
        int option1 = costs[0] + mincost(idx+1,days,costs,n,dp);
        
        //option 2 is taking 7 days pass
        int i;
        //move our cur days indx ahead by 7 days
        for(i=idx; i<n && days[i] < days[idx] + 7; i++); //if day[0] is 1 then move till 7th day[included]
        
        int option2 = costs[1] + mincost(i,days,costs,n,dp);
        
        //option 3 is taking 30 days pass
        //move our cur days indx ahead by 7 days
        for(i=idx; i<n && days[i] < days[idx] + 30; i++);
        
        int option3 = costs[2] + mincost(i,days,costs,n,dp);
         
        
        return dp[idx] = min(option1,min(option2,option3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        //make a 1d array
        vector<int> dp(n+1,-1);
        return mincost(0,days,costs,n,dp);
    }
};
