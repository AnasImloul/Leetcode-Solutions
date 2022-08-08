class Solution {
public:
int vals[7]={1,10,100,1000,10000,100000,1000000};
	bool util(unordered_set<char>&leadingZeroes,unordered_map<char,int>&map,int diff,int curr,string &s,int &visited){
    if(curr==s.length())
        return diff==0;
    
    //check for every value
    for(int i=0;i<=9;i++){
        if((visited&(1<<i))==0 && (i>0 || leadingZeroes.find(s[curr])==leadingZeroes.end())){
            visited=(visited | (1<<i));
            if(util(leadingZeroes,map,diff+map[s[curr]]*i,curr+1,s,visited))
                return true;
            visited=(visited^(1<<i));
        }
    }
    
    return false;
    
}
bool isSolvable(vector<string>& words, string result) {
    //PRUNING : 1st There should be no leading zeroes
    //CALCULATION PRUNING : this can be explained using a example i.e MATH so if lets say M=4 so what M can contribute to the                     //whole result = 4*1000 i.e 4th place so using this we can calculate the value of the whole array lets say array look like 
    // {MATH,PARTH} and mapping is like M=4,A=1,R=3,T=2,P=6,H=0 so the values will look like 4000+100+20+60000+1000+300+20+0 
    //So we can check for every mapping if we can get result if we can than we can return true
    //further we can use bitmasking for checking the visited values
    unordered_set<char>leadingZeroes;
    unordered_map<char,int>map;
    for(auto &x:words)
        for(int i=0;i<x.length();i++){
            if(i==0 && x.length()>1)
                leadingZeroes.insert(x[i]);
            map[x[i]]+=vals[x.length()-i-1];
        
        }
    for(int i=0;i<result.size();i++){
        if(i==0 && result.length()>1)
            leadingZeroes.insert(result[i]);
        map[result[i]]-=vals[result.length()-i-1];
    }
    
    string s="";
    for(auto &x:map)
        s+=x.first;
    //cout<<s;
    int visited=0;
    return util(leadingZeroes,map,0,0,s,visited);

}
};