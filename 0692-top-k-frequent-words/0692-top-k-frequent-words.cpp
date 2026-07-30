class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        map<string, int> mp;

        // Count frequency
        for (string word : words) {
            mp[word]++;
        }

        // Store unique words
        vector<string> v;
        for (auto it : mp) {
            v.push_back(it.first);
        }

        // Sort by frequency, then lexicographically
        sort(v.begin(), v.end(), [&](string a, string b) {
            if (mp[a] == mp[b])
                return a < b;
            return mp[a] > mp[b];
        });

        // Take first k words
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i]);
        }

        return ans;
    }
};