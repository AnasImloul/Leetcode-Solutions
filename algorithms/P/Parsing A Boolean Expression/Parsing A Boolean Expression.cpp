class Solution {
    pair<bool,int> dfs(string &e, int idx){
        bool res;
        if(e[idx]=='!'){
            auto [a,b]=dfs(e, idx+2);
            return {!a,b+3};
        }else if(e[idx]=='&'){
            int len=2;
            res=true;
            idx+=2;
            while(e[idx]!=')'){
                if(e[idx]==','){
                    idx++;len++;
                }
                auto [a,b]=dfs(e,idx);
                res&=a;
                idx+=b;
                len+=b;
            }
            return {res,len+1};
        }else if(e[idx]=='|'){
            int len=2;
            res=false;
            idx+=2;
            while(e[idx]!=')'){
                if(e[idx]==','){
                    idx++;len++;
                }
                auto [a,b]=dfs(e,idx);
                res|=a;
                idx+=b;
                len+=b;
            }
            return {res,len+1};
        }else{
            return {e[idx]=='t',1};
        }
    }
public:
    bool parseBoolExpr(string expression) {
        return dfs(expression, 0).first;
    }
};
