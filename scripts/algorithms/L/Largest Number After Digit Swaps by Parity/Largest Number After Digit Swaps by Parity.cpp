// Runtime: 9 ms (Top 5.70%) | Memory: 6 MB (Top 90.27%)
class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> p; // priority queue to store odd digits in descending order
        priority_queue<int> q; // priority queue to store even digits in descending order
        string nums=to_string(num); // converting num to a string for easy access of the digits
        int n=nums.size(); // n stores the number of digits in num

        for(int i=0;i<n;i++){
            int digit=nums[i]-'0';
            if((digit)%2) // if digit is odd, push it into priority queue p
                p.push(digit);
            else
                q.push(digit); // if digit is even, push it into priority queue q
        }

        int answer=0;
        for(int i=0; i<n; i++){
            answer=answer*10;
            if((nums[i]-'0')%2) // if the digit is odd, add the largest odd digit of p into the answer
                {answer+=p.top();p.pop();}
            else
                {answer+=q.top();q.pop();} // if the digit is even, add the largest even digit of q into the answer
        }
        return answer;
    }
};