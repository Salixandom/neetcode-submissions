class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int n1 = word1.size(), n2 = word2.size();
        int i = 0, j = 0;

        while(i < n1 && j < n2) {
            res += word1[i];
            res += word2[j];
            i++;
            j++;
        }
        
        if (i < n1) res += word1.substr(i);
        if (j < n2) res += word2.substr(j);

        return res;
    }
};