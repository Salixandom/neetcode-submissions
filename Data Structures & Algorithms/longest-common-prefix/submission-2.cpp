class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strs_num = strs.size();
        if(strs_num < 2) return strs[0];
        
        sort(strs.begin(), strs.end());

        int n = strs[0].length();
        for (int i = 0; i < n; i++) {
            for (string s: strs) {
                if(s[i] != strs[0][i]) return s.substr(0, i);
            }
        }
        return strs[0];
    }
};