//https://leetcode.com/problems/longest-string-chain/?envType=daily-question&envId=2023-09-23

class Solution {
public:
    int bt(vector<string>& words, string current, unordered_map<string, int>& memo) {
        if(memo.find(current) != memo.end()) return memo[current];
        if(find(words.begin(), words.end(), current) == words.end()) return 0;

        int maxi = INT_MIN;
        for(int i = 0; i < current.length(); i++) {
            maxi = max(maxi, 1+bt(words, current.substr(0, i) + current.substr(i+1, current.length()-i-1), memo));
        }

        return memo[current] = maxi;
    }

    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> memo;
        int result = 0;
        for(int i = 0; i < words.size(); i++) {
            result = max(result, bt(words, words[i], memo));
        }

        return result;

    }
};