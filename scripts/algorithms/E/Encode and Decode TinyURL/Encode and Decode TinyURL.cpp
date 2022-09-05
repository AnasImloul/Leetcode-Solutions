// Runtime: 4 ms (Top 69.87%) | Memory: 7.4 MB (Top 11.07%)
class Solution {
private:
    unordered_map<string, string> hash;
    string server = "http://tinyurl.com/";
    string all = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        srand(time(NULL));
        string add = "";
        int ran = rand() % 10;
        int strsize = all.size();
        while(ran){
            int index = rand() % strsize;
            add += all[index];
            ran--;
        }

        hash[(server+add)] = longUrl;

        return (server + add);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hash[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));