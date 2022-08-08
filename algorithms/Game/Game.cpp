class Solution {
public:
    double cor=0.001;
    void dfs(vector<double> &cards,bool &res){
        if(res==true) return;
        if(cards.size()==1){
            if(abs(cards[0]-24)<cor) res=true;
            return;
        }
        for(int i=0;i<cards.size();i++){
            for(int j=0;j<i;j++){
                double p=cards[i],q=cards[j];
                vector<double> t{p+q,q-p,p-q,p*q};
                if(p>cor) t.push_back(q/p);
                if(q>cor) t.push_back(p/q);
                cards.erase(cards.begin()+i);
                cards.erase(cards.begin()+j);
                for(double d:t){
                    cards.push_back(d);
                    dfs(cards,res);
                    cards.pop_back();
                }
                cards.insert(cards.begin()+j,q);
                cards.insert(cards.begin()+i,p);
            }
        }
    }
    bool judgePoint24(vector<int>& cards) {
        bool res=false;
        vector<double> card (cards.begin(),cards.end());
        dfs(card,res);
        return res;
    }
};
