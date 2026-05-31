class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        if (s_len != t_len) return false;
        
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for(int i = 0; i < s_len; i++) {
            s_map[s[i]]++;
            t_map[t[i]]++;
        }
        if (s_map != t_map) return false;
        return true;
    }
};
