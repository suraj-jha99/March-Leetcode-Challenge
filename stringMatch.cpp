class Solution {
public:
//app 1: using stl
    int strStr(string s, string t) {
       if(haystack.find(needle) != string::npos){
            return haystack.find(needle);
        }

        return -1;
    }
};
