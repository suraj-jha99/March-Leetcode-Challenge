class Solution {
public:
// app 1: using bfs
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        //make map [num,indices where num is present]
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);

        int steps=0;
        while(!q.empty()){
            steps++;
            int N=q.size();

            for(int i=0; i<N; i++){
                //find j --> cur idx
                int j=q.front();
                q.pop();
                
                //jump to j-1
                if(j-1>=0 && mp.find(nums[j-1]) != mp.end()){
                    q.push(j-1);
                }

                //jump to j+1
                if(j+1<n && mp.find(nums[j+1]) != mp.end()){
                    if(j+1 == n-1) return steps;
                    q.push(j+1);
                }

                //jump to k --> nums[j]==nums[k]
                if(mp.find(nums[j]) != mp.end()){
                    for(int k : mp[nums[j]]){
                        if(j != k){
                            if(k == n-1) return steps;
                            q.push(k);
                        }
                    }
                }

                //erase cur num from map so that we don't keep looping on same num
                mp.erase(nums[j]);
            }
        }

        return steps;
    }
};
