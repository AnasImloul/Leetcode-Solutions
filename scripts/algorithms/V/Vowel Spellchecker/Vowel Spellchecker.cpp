// Runtime: 84 ms (Top 92.95%) | Memory: 32.7 MB (Top 97.44%)
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, vector<int>> umap;

        // step 1: add info in umap;
        for(int curr = 0; curr < wordlist.size(); curr++){
            // case 1: add same;
            umap[wordlist[curr]].push_back({curr});
            // notice that the lowercase may appear;

            // case 2: add lowercase;
            string tmp = wordlist[curr];
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

            if(umap.find(tmp) == umap.end() && tmp != wordlist[curr]) umap[tmp].push_back({curr});

            // case 3: add vowel errors;
            // convert aeiou to _;
            for(int c_index = 0; c_index < tmp.size(); c_index++){
                char c = tmp[c_index];
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') tmp[c_index] = '_';
            }

            if(umap.find(tmp) == umap.end()) umap[tmp].push_back({curr});
        }

        // step 2: convert queries;
        for(int curr = 0; curr < queries.size(); curr++){
            string tmp = queries[curr];
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

            // case 1: check same;
            if(umap.find(queries[curr]) != umap.end()){
                queries[curr] = (umap[queries[curr]].size() == 1) ? wordlist[umap[queries[curr]][0]] : wordlist[umap[queries[curr]][1]];
                continue;
            }

            // case 2: check lowercase;
            if(umap.find(tmp) != umap.end() && tmp != queries[curr]){
                queries[curr] = wordlist[umap[tmp][0]];
                continue;
            }

            // case 3: check vowel errors;
            // convert aeiou to _;
            for(int c_index = 0; c_index < tmp.size(); c_index++){
                char c = tmp[c_index];
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') tmp[c_index] = '_';
            }

            if(umap.find(tmp) != umap.end()){
                queries[curr] = wordlist[umap[tmp][0]];
                continue;
            }

            // case 4: not found;
            queries[curr] = "";
        }

        return queries;
    }
};

// 1. When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
// 2. When the query matches a word up to capitlization, you should return the first such match in the wordlist.
// 3. When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
// 4. If the query has no matches in the wordlist, you should return the empty string.