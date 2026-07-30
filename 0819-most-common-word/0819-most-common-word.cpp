class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(int i=0;i<paragraph.size();i++){
            if(isupper(paragraph[i])){
                paragraph[i]=tolower(paragraph[i]);
            }
            if(!isalpha(paragraph[i])){
                paragraph[i]=' ';
            }
        }
        stringstream ss(paragraph);
        string  word;
        vector<string>v;
        while(ss>>word)
        {
           v.push_back(word);
        }

        map<string,int>mp;
        for(auto s:v){
            mp[s]++;
        }
        
        for(int i=0;i<banned.size();i++){
            mp.erase(banned[i]);
        }
        int max=0;
        string ans="";
        for(auto it:mp){
        if(it.second>max){
            max=it.second;
            ans=it.first;
        }
        }
        return ans;
    }
};


















// class Solution {
// public:
//     string mostCommonWord(string paragraph, vector<string>& banned) {

//         // Convert uppercase to lowercase and replace punctuation with spaces
//         for (int i = 0; i < paragraph.size(); i++) {
//             if (isupper(paragraph[i])) {
//                 paragraph[i] = tolower(paragraph[i]);
//             }

//             if (!isalpha(paragraph[i])) {
//                 paragraph[i] = ' ';
//             }
//         }

//         // Store words
//         stringstream ss(paragraph);
//         vector<string> words;
//         string word;

//         while (ss >> word) {
//             words.push_back(word);
//         }

//         string ans = "";
//         int repeat = 0;

//         // Count frequency
//         for (int i = 0; i < words.size(); i++) {

//             // Check if banned
//            // bool ban = false;
//             for (int k = 0; k < banned.size(); k++) {
//                 if (words[i] == banned[k]) {
//                    // ban = true;
//                     //break;
//                       goto skip;
//                 }
//             }
// skip:;
//            // if (ban)
//                // continue;

//             int count = 0;

//             // Count occurrences
//             for (int j = 0; j < words.size(); j++) {
//                 if (words[i] == words[j]) {
//                     count++;
//                 }
//             }

//             if (count > repeat) {
//                 repeat = count;
//                 ans = words[i];
//             }
//         }

//         return ans;
//     }
// };