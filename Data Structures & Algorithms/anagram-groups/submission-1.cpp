class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> resMap;

        for(string str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            resMap[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto p: resMap) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
