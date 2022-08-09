class Solution 
{
public:
    
    int lcm(int a, int b)                   // Finding the LCM of a and b
    {
        if(a==b)
            return a;
        if(a > b)
        {
            int count = 1;
            while(true)
            {
                if((a*count)%b==0)
                    return a*count;
                count++;
            }
        }
        int count = 1;
        while(true)
        {
            if((b*count)%a==0)
                return b*count;
            count++;
        }
        return -1;      // garbage value--ignore.
    }
    
    int nthMagicalNumber(int n, int a, int b) 
    {
        long long int comm = lcm(a,b);                       //common element
        long long int first = (((comm*2) - comm) / a) - 1;   //no. of elements appearing before the comm multiples (a).
        long long int second = (((comm*2) - comm) / b) - 1;  //no. of elements appearing before the comm multiples(b).
    
        long long int landmark = (n / (first + second + 1)) * comm; // last common element before nth number.
        long long int offset = n % (first + second + 1);            // how many numbers to consider after last common
        
        long long int p = landmark, q = landmark;   // initialisations to find the offset from the landmarked element
        long long int ans = landmark;
        for(int i=1;i<=offset;i++)  // forwarding offset number of times.
        {
            if(p+a < q+b)           //this logic easily takes care of which elements to be considered for the current iteration. 
            {
                ans = p+a;
                p = p+a;
            }
            else
            {
                ans = q+b;
                q = q+b;
            }
        }
        
        return (ans%1000000007);    //returning the answer.
    }
};

/*
    a and b
    1st step would be to find the LCM of the two numbers --> Multiples of LCM would be the common numbers in the sequential pattern.
    The next step would be to find the numbers of a and numbers of b appearing between the common number.
    
	DRY : 
	
    4 and 6
    4 -> 4 8 12 16 20 24 28 32 36 40   -->  
    6 -> 6 12 18 24 30 36 42 48 54 60  -->
    
    4 6 8    12     16 18 20        24 --> n/(f + s) --->  23/4 = 5 and 3
    5th -----> (comm * 5 = 60) ------>
*/
