// Runtime: 29 ms (Top 64.0%) | Memory: 6.70 MB (Top 64.0%)

class Solution {
public:
    string abbreviateProduct(int left, int right) {
       
        // upper 12 digit of product
        double upper = 1;
        
        // lower 12 digit of product
        long long lower = 1L;
        
        // offset to make 12 digit in upper and lower
        long long Offset = 1e12;
        
        // offset to make 5 digit in upper and lower
        long long cutOffset = 1e5;
        
        // store log value of the product        
        double product = 0.0;
        
        // count trailing zero in the product
        int trailing = 0;
        
        for(int i=left;i<=right;i++)
        {
            // update log value of product
            product +=  log10(i);
            
            // multiple value with upper and lower 12 digit
            upper *= i;
            lower *= i;
            
            // keep 12 digit in upper
            while(upper>=Offset)upper/=10;
            
            // remove trailing zeroes
            while(lower%10==0)lower/=10,trailing++;
            
            // keep 12 digits in lower
            lower %= Offset;
        }
        
        // count total digits in product except trailing zeroes
        int digitLength = (int)product + 1 - trailing;
        
        // keep 5 digit in upper and lower
        while(upper>=cutOffset)upper/=10;
        lower %= cutOffset;
        
        int upperInt = upper;
        
        // take digit length digits from upper and lower when digit length <= 10
        if(digitLength<=10)
        {
            // make all digit 0 to tackle missing MSB zeroes in lower
            string result(digitLength,'0');
            string upperStr = to_string(upperInt);
            string lowerStr = to_string(lower);
            
            for(int i=0;i<upperStr.length() && digitLength >0; i++,digitLength--)
                result[i] = upperStr[i];
            
            for(int k=1;!lowerStr.empty() && digitLength >0; digitLength--,k++)
            {
                result[result.length()-k] = lowerStr.back();
                lowerStr.pop_back();
            }

            
            return result + "e" + to_string(trailing);
        } 
        else
        {   
           // take upper and lower 5 digits 
           string result = to_string(lower);
           return to_string(upperInt) + "..." + string(5-result.size(),'0') + result  + "e" + to_string(trailing);
        }
    }
};
