class Solution {
private:
    string getKey(string str) {
        vector<int> count(26);

        for(int i = 0; i < str.size(); i++) {
            count[str[i] - 'a']++;
        }
        string key = "";
        for(int j = 0; j < count.size(); j++) {
            key.append(to_string(count[j]) + '#');
        }
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Solution 1: sort the strings and group them but time complexity O(m.nlogn)
        // Condition given: Letters lowercase (a - z) 26 at most
        // eg: eat ( 1 - e, 1 - a, 1 - t) // let's have array called count(a-z)
        // Solution 2: 
        // Hashmap: our key is going to be [Value: list of anagrams (has the same pattern of count)]
        // Time complexity: O(m.n).26 -> O(m.n)
        unordered_map<string, vector<string>> m;
        for(int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};