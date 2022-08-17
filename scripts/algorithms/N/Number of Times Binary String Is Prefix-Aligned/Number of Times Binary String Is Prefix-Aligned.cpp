class BIT{
  public:
vector<int>bit;
int n;
BIT(int n){
    bit.resize(n+1,0);
    this->n=n;
}

int findSum(int i){
    
    int sum=0;
    while(i>0){
        sum+=bit[i];
        i-=(i&(-i));
    }
    return sum;
}

void update(int i,int val){
    

    while(i<=n){
        bit[i]+=val;
        i+=(i&(-i));
    }  
}

};


class Solution {
public:
int numTimesAllBlue(vector<int>& flips) {

    int n=flips.size();
    BIT tree(n+1);
    int res=0;
    string s=string(n,'0');
   
    int maxi=0;
    for(auto &x:flips){
        if(s[x-1]=='1'){
            tree.update(x,-1);
            s[x-1]='0';
        }
        else {
            s[x-1]='1';
            tree.update(x,1);
        }
        maxi=max(maxi,x);
        if(tree.findSum(x)==x && tree.findSum(maxi)==maxi)
            res++;
        
     
    
    }
    
	 return res;   
	}
};