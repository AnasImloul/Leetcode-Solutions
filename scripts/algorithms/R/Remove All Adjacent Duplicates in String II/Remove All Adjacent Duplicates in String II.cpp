class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <char> Stack;
        stack <pair <char, int>> freqMap;
        for (char &ch: s) {
            if (!Stack.empty() && Stack.top() == ch) {
                int freq = freqMap.top().second;
                if (freq + 1 == k) {
                    while (freq--) {
                        Stack.pop();
                    }
                    freqMap.pop();
                } else {
                    freqMap.pop();
                    freqMap.push({ch, freq + 1});
                    Stack.push(ch);
                }
            } else {
                Stack.push(ch);
                freqMap.push({ch, 1});
            }
        }
        string cleanedString = "";
        while (!Stack.empty()) {
            cleanedString += Stack.top();
            Stack.pop();
        }
        reverse(cleanedString.begin(), cleanedString.end());
        return cleanedString;
    }
};
