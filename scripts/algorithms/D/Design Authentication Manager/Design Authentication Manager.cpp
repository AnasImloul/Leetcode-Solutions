// Runtime: 233 ms (Top 27.28%) | Memory: 30.2 MB (Top 62.58%)
class AuthenticationManager {
    int ttl;
    unordered_map<string, int> tokens;
public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }

    void renew(string tokenId, int currentTime) {
        auto tokenIt = tokens.find(tokenId);
        if (tokenIt != end(tokens) && tokenIt->second > currentTime) {
            tokenIt->second = currentTime + ttl;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for (auto token: tokens) {
            if (token.second > currentTime) res++;
        }
        return res;
    }
};