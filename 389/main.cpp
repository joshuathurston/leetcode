// https://leetcode.com/problems/find-the-difference/description/?envType=daily-question&envId=2023-09-25
// lets add some notes
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> vals(26, 0);

        for(int i = 0; i < t.length(); i++) {
            vals[t[i]-'a']--;
            if(i < s.length()) vals[s[i]-'a']++;
        }

        for(int i = 0; i < vals.size(); i++) {
            if(vals[i] == -1) return i+'a';
        }
        return 'a';
    }
};