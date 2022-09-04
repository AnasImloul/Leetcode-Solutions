// Runtime: 12 ms (Top 6.32%) | Memory: 8.7 MB (Top 6.10%)
class Solution {
public:
    // helper functions
    bool isUpper(char ch) {
        return ch >= 65 && ch <= 90;
    }

    bool isLower(char ch) {
        return ch >= 97 && ch <= 122;
    }

    bool isLetter(char ch) {
        return isUpper(ch) || isLower(ch);
    }

    bool isNumber(char ch) {
        return ch >= 48 && ch <= 57;
    }

    void addKey(map<string, long int>& count, string key, long int value) {
        if(count.find(key) != count.end()) {
            count[key] = count[key] + value;
        }
        else {
            count[key] = value;
        }
    }

    // very specific utility function
    string buildName(string formula, int& i) {
        string name = "";
        name.push_back(formula[i]);
        if(isUpper(formula[i])) {
            return name;
        }
        if(i == formula.length()-1) {
            return name;
        }
        while(isLower(formula[i-1])) {
            name.push_back(formula[i-1]);
            i--;
        }
        name.push_back(formula[i-1]);
        i--;
        reverse(name.begin(), name.end());
        return name;
     }

    // very specific utility function
    long int buildCount(string formula, int& i, vector<long int>& stack) {
        long int num = formula[i] - '0';
        long int place = 1;
        if(i == 0) {
            return num;
        }
        while(isNumber(formula[i-1])) {
            place = place * 10;
            num = (formula[i-1]-'0') * place + num;
            i--;
        }
        return num;
    }

    string countOfAtoms(string formula) {
        string ans;
        map<string, long int> count;
        vector<long int> stack;
        long int factor = 1;
        string name = "";
        long int num = -1; // -1 indicates a number reset, ie, count = 1

        // iterator i is passed by reference to keep track of
        // the substrings that are builded, ie, atom
        // names or numbers
        int i = formula.length()-1;
        while (i >= 0) {
            // here we need the number after the bracket close. This is
            // either 1 or num depending on whether we built a number before
            if(formula[i] == ')') {
                if(i+1 <= formula.length()-1 && isNumber(formula[i+1])) {
                    stack.push_back(num);
                    factor = factor * num;
                    num = -1;
                }
                else {
                    stack.push_back(1);
                }
            }
            // here is why we need a stack. Remove latest factor that was added.
            else if(formula[i] == '(') {
                factor = factor / stack.back();
                stack.pop_back();
            }
            // once we detect a letter, we know it can only be a word. num gives us the atom subscript
            // and factor gives us the molecular count.
            else if(isLetter(formula[i])) {
                name = buildName(formula, i);
                if(num == -1) {
                    addKey(count, name, 1 * factor);
                }
                else {
                    addKey(count, name, num * factor);
                }
                num = -1; // reset number
            }
            else if(isNumber(formula[i])) {
                num = buildCount(formula, i, stack);
            }
            i--;
        }

        // arrange name and count in a string
        map<string, long int>::iterator it;
        for (it = count.begin(); it != count.end(); it++)
        {
            ans = ans + it->first;
            if(it->second != 1) {
                ans = ans + to_string(it->second);
            }
        }
        return ans;
    }
};
