class Solution {
public:
    int minOperationsToFlip(string exp) {
        stack<pair<char,int>> st;   //exp val,cost

        pair<char,int> p;

        for(auto x:exp){
            if(x=='(' || x=='&' || x=='|'){
                st.push({x,0});   //till now no looking need to change exp so mark cost as 0 or we can add cost of these while solving exp
            }
            else{
                if(x==')'){
                    p=st.top();
                    st.pop();
                    st.pop();   //this pop for '(' 
                }
                else{
                    //if number or we can say '0' or '1'
                    p={x,1};    //cost going to be one becoz x if either '0' or '1'
                }
                while(!st.empty() && (st.top().first=='&' || st.top().first=='|')){
                    char op=st.top().first;
                    st.pop();
                    char val2=p.first;
                    int cost2=p.second;
                    char val1=st.top().first;
                    int cost1=st.top().second;
                    st.pop();

                    if(op=='&'){
                        if(val1=='1' && val2=='1'){
                            p={'1',min(cost1,cost2)};
                        }
                        if(val1=='1' && val2=='0'){
                            p={'0',1};
                        }
                        if(val1=='0' && val2=='1'){
                            p={'0',1};
                        }
                        if(val1=='0' && val2=='0'){
                            p={'0',min(1+cost1,1+cost2)};
                        }
                    }

                    if(op=='|'){
                        if(val1=='1' && val2=='1'){
                            p={'1',1+min(cost1,cost2)};
                        }
                        if(val1=='1' && val2=='0'){
                            p={'1',1};
                        }
                        if(val1=='0' && val2=='1'){
                            p={'1',1};
                        }
                        if(val1=='0' && val2=='0'){
                            p={'0',min(cost1,cost2)};
                        }
                    }
                }
                st.push(p);

            }
        }
        return st.top().second;
    }
};
//code by sachin