// Runtime: 117 ms (Top 72.95%) | Memory: 27.1 MB (Top 80.99%)
class Solution {
public:
    bool canBeValid(string s, string locked) {

        int n = s.size();
        if(n&1) return false;

        int balance = 0;

        // First check balance from left to right
        // For opening '(' brackets

        for(int i=0; i<n; i++) {

            // If either char is ( or it is unlocked,
            // We can increment balance

            if(locked[i] == '0' || s[i] == '(') balance++;
            else balance--; // otherwise decrement balance, since it is ) and also locked

            // Since balance is negative, we have more ')'.
            // And there is no unlocked char available
            // SO, it is invalid string for sure

            if(balance < 0) return false;
        }

        // reset balance
        balance = 0;

        // Then also check balance from right to left
        // For closing ')' brackets

        for(int i=n-1; i>=0; i--) {

            // If either char is ) or it is unlocked,
            // We can increment balance

            if(locked[i] == '0' || s[i] == ')') balance++;
            else balance--;

            // Since balance is negative, we have more '('.
            // And there is no unlocked char available
            // SO, it is invalid string for sure

            if(balance < 0) return false;
        }

        return true;
    }
};