// Runtime: 11 ms (Top 21.91%) | Memory: 8.5 MB (Top 29.43%)
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        int n = ops.size();
        for(int i=0;i<n;i++){
                    if(ops[i] == "C"){
                        st.pop();
                    }
                    else if (ops[i] =="D"){
                        st.push(st.top() * 2);
                    }
                    else if(ops[i] =="+"){
                        int temp = st.top();
                        st.pop();
                        int temp2 = st.top();
                        st.push(temp);
                        st.push(temp+temp2);
                   }
                  else{
                      st.push(stoi(ops[i]));
                  }
        }
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};