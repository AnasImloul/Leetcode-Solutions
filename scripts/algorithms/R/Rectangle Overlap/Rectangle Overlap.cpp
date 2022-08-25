// Runtime: 4 ms (Top 30.08%) | Memory: 7.8 MB (Top 65.04%)
        class Solution {
        public:
            bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
            {
               if(rec2[1]>=rec1[3] || rec1[1]>=rec2[3] || rec1[0]>=rec2[2] || rec2[0]>=rec1[2])
                   return false;
                return true;
            }
        };