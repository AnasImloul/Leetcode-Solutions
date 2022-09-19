// Runtime: 290 ms (Top 55.58%) | Memory: 13.9 MB (Top 85.26%)
// For approach: ref: https://www.youtube.com/watch?v=ZVJ3asMoZ18&t=0s

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        // 1. Create a set and insert all wordList to the set to have
        // easy search of O(1)
        unordered_set<string> wordSet;
        bool isEndWordPresent = false;
        for (string s:wordList)
        {
            // Check if the destination string even present in the wordList
            // If not then there is no point in even trying to find the
            // route from source string to destination string
            if (!isEndWordPresent && s.compare(endWord) == 0)
            {
                isEndWordPresent = true;
            }
            wordSet.insert(s);
        }

        // 2. If endWord is not present in the wordList return
        if (!isEndWordPresent)
        {
            return 0;
        }

        // 3. Create a queue for BST insert the elements of currentlevel to the queue
        // currentLevel is defined as all the strings that can be reached from
        // all the strings of the previous string by just replacing one character
        // and the one-char-replaced-string is present in the wordSet / wordList
        queue<string> q;
        q.push(beginWord);
        int level = 0; // every time all the strings at this level are processed increment it

        // 4. Loop through all the elements in the queue
        while (!q.empty())
        {
            level++;
            int numStringsInCurLevel = q.size();
            // loop through all the strings in this current level
            // and find out if destination can be reached before
            // jumping to the next level of strings added to the queue
            while (numStringsInCurLevel--)
            {
                string curStr = q.front();
                q.pop();

                for (int i=0; i<curStr.length(); i++)
                {
                    string tempStr = curStr;
                    // Now check if swappin one char in the curStr will
                    // lead to any string in the wordSet
                    for (char c='a'; c<='z'; c++)
                    {
                        tempStr[i] = c;
                        if (tempStr.compare(curStr) == 0)
                        {
                            // Ignore the same string
                            continue;
                        }
                        // Check if we reached the destination
                        if (tempStr.compare(endWord) == 0)
                        {
                            return level+1;
                        }
                        if (wordSet.find(tempStr) != wordSet.end())
                        {
                            // this string is in the set so add it to the queue
                            // and remove it from the set
                            q.push(tempStr);
                            wordSet.erase(tempStr);
                        }
                    }
                }
            }
        }

        // If we are here then we couldn't reach destination
        // even though the destination string is present in the wordList
        // there is no path from source to destination for the given rules
        return 0;
    }
};