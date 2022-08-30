// Runtime: 0 ms (Top 100.00%) | Memory: 5.9 MB (Top 74.21%)
long long fun(long long a){ //sum of all natural from 1 to a
    long long b=a*(a+1)/2;
    return b;
}

class Solution {
public:
    int reachNumber(int target) {

         long long i=1,j=pow(10,5),x=abs(target),ans=0; //for -ve or +ve positive of a number the minimum no. of steps from the origin will be same

    while(i<=j){ // binary search to search if x is continous sum of some natural number starting from 1
        long long m=(i+j)/2;

        if(fun(m)==x){
            ans=m;
        }
        if(x>fun(m)){
            i=m+1;
        }
        else{
            j=m-1;
        }

    }

    if(ans!=0){ // If we found our ans return it

        return ans;
    }
    else{
     //in this for loop i have set the limit too high it can be less then 10^6 as max value j can be is 44723, so loop will never run fully, whatever the value of j will be, loop will maximum run for 3-10 iterations
    for(int l=j+1;l<100000;l++){ // in the end of binary search we get the value of j(or high end) as the position of the number(in the sequence of continous sum of natural number from 1, i.e. 1, 3,6,10........) whose value is just less than x(searching element)

        if((fun(l)-x)%2 ==0){ // as the total step will be more than x if we go backward from zero, thing to note is that if we go -ve direction we also have to come back so we covering even distance
             ans=l;// when the first fun(l) - x is even that l is our minimum jump

            break; // no need to search further

    }
    }

    }

        return ans;
    }

};