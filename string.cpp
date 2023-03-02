class Solution {
public:
    //simple simulation of the prob. in O(N) 
    int compress(vector<char>& chars) {
        int n=chars.size();
        string ans="";
        
        int i=0;
        while(i<n){
            //process cur char
            char ch=chars[i];
            ans += ch;
            
            int len=0;
            while(i<n && chars[i] == ch){
                len++;
                i++;
            }
            
            if(len == 1) continue; //for len 1 don't add it's len val
            ans += to_string(len);
        }
        
        chars.clear();
        for(int i=0; i<ans.size(); i++){
            chars.push_back(ans[i]);
        }
        
        return chars.size();
    }
};
