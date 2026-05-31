class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strs_num = strs.size();
        if(strs_num < 2) return strs[0];
        
        sort(strs.begin(), strs.end());

        int n = strs[0].length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            unordered_set<char> tempSet;
            for(int j = 0; j < strs_num; j++) tempSet.insert(strs[j][i]);
            if (tempSet.size() > 1) return ans;
            ans += strs[0][i];
        }
        return ans;
    }
};