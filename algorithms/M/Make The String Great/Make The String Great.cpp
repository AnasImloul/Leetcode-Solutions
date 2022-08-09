class Solution {
public:
    string makeGood(string s) {
        	stack<char>st;
	st.push(s[0]);
	string ans="";

	for(int i=1;i<s.size();++i){
		if(!st.empty() and (st.top()==s[i]+32 or st.top()==s[i]-32)){
			cout<<"top :"<<st.top()<<endl;
			st.pop();
		}

		else {

			st.push(s[i]);
		}
	}

	
		while(!st.empty()){
		// cout<<st.top()<<"";
		ans+=st.top();
		st.pop();

		}
			reverse(ans.begin(),ans.end());
	
		return ans;
	
	
    }
};
