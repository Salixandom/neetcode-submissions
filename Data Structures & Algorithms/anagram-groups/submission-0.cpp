class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> resMap;

        for(string str: strs) {
            vector<int> freq(26, 0);
            for(char c: str) {
                freq[c - 'a']++;
            }

            string key;
            for(int x: freq) {
                key += "#" + to_string(x);
            }

            resMap[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto p: resMap) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
