class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        
        //using min pq to sort array in ascending order
        priority_queue<int,vector<int> , greater<int> > pq;
        
        for(int &n: nums) pq.push(n);
        
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};
