class Solution {
public:
    bool isAnagram(string s, string t) {
        // build a hashmap for both the strings and compare the index and the values
        if(s.size() != t.size()) {
            return false;
        }

        unordered_map<int, int> smap;
        unordered_map<int, int> tmap;

        for (int i = 0; i < s.size(); i++) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        for (int i = 0; i < smap.size(); i++) {
            if(smap[i] != tmap[i]) return false;
        }
        return true;
    }
};