class Solution {
public:
    string reformatDate(string date) {
        map<string,int>m;
        m["Jan"] =1;
        m["Feb"] =2;
        m["Mar"] =3;
        m["Apr"] =4;
        m["May"] =5;
        m["Jun"] =6;
        m["Jul"] =7;
        m["Aug"] =8;
        m["Sep"] =9;
        m["Oct"] =10;
        m["Nov"] =11;
        m["Dec"] =12;
        string ans;
        for(int i=date.length()-4; i<date.length(); i++){
            ans+=date[i];
        }
        ans += "-";
        string month;
        for(int i=date.length()-8; i<=date.length()-6; i++){
            month+=date[i];
        }

        int yes = m[month];

        if(yes<=9){
            ans += '0';
        }
        ans = ans + to_string(yes);
        ans += "-";
        int i = 0;
        if(date[1]=='t' || date[1]=='s' || date[1]=='n' || date[1]=='r'){
            ans+='0';
            ans+=date[0];
        }
        else{
            ans+=date[0];
            ans+=date[1];
        }
        return ans;
    }
};