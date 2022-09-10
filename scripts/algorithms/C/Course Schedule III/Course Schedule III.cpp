// Runtime: 280 ms (Top 87.39%) | Memory: 56.3 MB (Top 66.94%)
class Solution {
public:
    bool static cmp(vector<int> &a,vector<int>&b) {
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
         sort(courses.begin(),courses.end(),cmp);
         int sm = 0;
         priority_queue<int> pq;
         for(int i=0; i<courses.size(); i++) {
               pq.push(courses[i][0]);
               sm+=courses[i][0]; // sum of duration of courses
               // when there exists a course duration that is invalid and can't be completed on that day!
               if(sm>courses[i][1]) {
                    sm-=pq.top(); // remove the biggest invalid course duration!
                    pq.pop();
               }
         }
        return pq.size();
    }
};