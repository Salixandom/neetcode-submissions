class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> character_map;

        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++) {
            character_map[s[i]]++;
        }

        for(int i = 0; i < t.size(); i++) {
            if(--character_map[t[i]] < 0) return false;
        }

        return true;
    }
};
