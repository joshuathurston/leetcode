//https://leetcode.com/problems/remove-duplicate-letters/description/?envType=daily-question&envId=2023-09-26

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> monoStack;
        vector<int> seen(26, 0);
        unordered_set<char> unique;
        for(int i = 0; i < s.length(); i++) {
            seen[s[i]-'a']++;
        }

        for(int i = 0; i < s.length(); i++) {
            if(monoStack.empty()) {
                monoStack.push(s[i]);
                seen[s[i]-'a']--;
                unique.insert(s[i]);
            }
            else if(unique.find(s[i]) != unique.end()) {
                seen[s[i]-'a']--;
                continue;
            }
            else if(s[i] < monoStack.top() && seen[monoStack.top()-'a'] >= 1) {
                while(!monoStack.empty() && s[i] < monoStack.top() && seen[monoStack.top()-'a'] >= 1) {
                    unique.erase(monoStack.top());
                    monoStack.pop();
                }
                unique.insert(s[i]);
                monoStack.push(s[i]);
                seen[s[i]-'a']--;
            }

            else {
                seen[s[i]-'a']--;
                unique.insert(s[i]);
                monoStack.push(s[i]);
            }
        }

        string result = "";

        while(!monoStack.empty()) {
            result.push_back(monoStack.top());
            monoStack.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};