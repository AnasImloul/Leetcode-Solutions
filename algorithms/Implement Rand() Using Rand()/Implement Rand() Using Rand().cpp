class Solution {
public:
    int rand10() {
        while(true)
        {
            int col = rand7();
            int last_row_tak = (rand7() - 1)*7;
            int val = last_row_tak + col;
            if(val<=40)
            {
                return (val-1)%10 + 1;
            }
        }
    }
};
