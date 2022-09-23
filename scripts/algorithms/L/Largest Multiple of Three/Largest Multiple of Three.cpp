// Runtime: 71 ms (Top 26.41%) | Memory: 19.4 MB (Top 72.64%)
class Solution {
public:

    vector<int> ans;

    void calculate(vector<int>& count,int no,vector<int>& temp){

        if(no==0){
            int flag=0,sum1=0,sum2=0,validSum=0;
            for(int j=1;j<10;j++){
                sum1+=temp[j];
                sum2+=ans[j];
                validSum+=(temp[j]*j);
            }
            if(validSum%3!=0){
                return ;
            }

            if(sum2>sum1)
                return;
            else if(sum1>sum2){
             for(int i=1;i<10;i++){
              ans[i]=temp[i];
             }
                return ;
            }
            int j=9;
            while(j>0){
                if(ans[j]<temp[j])
                {
                    flag=1;
                    break;
                }else if(ans[j]>temp[j])
                    break;
                j--;
            }
            if (flag==1){
             for(int i=1;i<10;i++){
              ans[i]=temp[i];
             }
            }
            return ;
        }

        int targetCount=count[no]-2;

        if(targetCount<0)
            targetCount=0;

        int co=count[no];

        do{
            temp[no]=co;

            calculate(count,no-1,temp);

            co--;
        }
        while(co>=targetCount);

    }

    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> count(10,0);
        int n=digits.size();
        for(int i=0;i<n;i++){
            count[digits[i]]++;
        }
        vector<int> temp(10,0);
        ans.resize(10,0);
        calculate(count,9,temp);

        string res="";
        ans[0]=count[0];
        for(int i=9;i>=0;i--){
            for(int j=1;j<=ans[i];j++){
                res+=('0'+i);
            }
        }
        if(res.size()>=2 && res[0]=='0' && res[1]=='0')
            return "0";
        return res;
    }
};