// Runtime: 3 ms (Top 42.85%) | Memory: 6.7 MB (Top 18.22%)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec( n , vector<int> (n, 0));

        vector<int>helper;
        for(int i=0;i<n*n;i++){
            helper.push_back(i+1);
        }

        int k = 0;
        int top = 0;
        int down = n-1;

        int left = 0;
        int right = n-1;

        int direction = 0;

        vector<int>result;

        while(top<=down and left<=right){
            if(direction==0){
                for(int i=left;i<=right;i++){
                    vec[top][i] = helper[k];
                    k++;
                }
                top++;
            }
            else if(direction==1){
                for(int i=top;i<=down;i++){
                    vec[i][right] = helper[k];
                    k++;
                }
                right--;
            }
            else if(direction==2){
                for(int i=right;i>=left;i--){
                    vec[down][i] = helper[k];
                    k++;
                }
                down--;
            }
            else if(direction==3){
                for(int i=down;i>=top;i--){
                    vec[i][left] = helper[k];
                    k++;
                }
                left++;
            }
            direction = (direction+1)%4;
        }
        return vec;
    }
};