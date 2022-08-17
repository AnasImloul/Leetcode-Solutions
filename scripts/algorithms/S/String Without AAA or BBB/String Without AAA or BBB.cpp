class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        int i=0,j=0;
        bool flag = false;
        if(a > b){
            for(j=0;j<b;j++,i+=2){
                if(a-i == b-j){ // If this condition satisfies means from this point our count of remaining a and b become same so we need to print them alternatively.
                    flag = true;
                    break;
                }
                ans.push_back('a');
                ans.push_back('a');
                ans.push_back('b');
                
            }
            
            if(flag == true){
                //Printing a and b alternately as count of remaining a and b is same.
                for(i;i<a;i++){
                   ans.push_back('a');
                   ans.push_back('b');
               } 
            }
            else{       // If count does not become same then we print 2 a and 1 b in upper for loop and still some a remains we print them in below loop.
                while(i<a){
                    ans.push_back('a');
                    i++;
                }
            }
        }
        
        
        else if( b> a){
           for(i=0;i<a;i++,j+=2){
               if(a-i == b-j){
                    flag = true;
                    break;
                }
               ans.push_back('b');
               ans.push_back('b');
               ans.push_back('a');
               
           } 
             if(flag == true){
                 
                for(i;i<a;i++){
                   ans.push_back('a');
                   ans.push_back('b');
               } 
            }
            else{
                while(j<b){
                    ans.push_back('b');
                    j++;
                } 
            }
        }
        
        
        else{
           for(i=0;i<a;i++){
               ans.push_back('a');
               ans.push_back('b');
           } 
        }
        return ans;
    }
};
