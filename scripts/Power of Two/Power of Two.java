class Solution {
    public boolean isPowerOfTwo(int n) { 
        return power2(0,n);
        
    }
    public boolean power2(int index,int n){
        if(Math.pow(2,index)==n)
            return true;
        if(Math.pow(2,index)>n)
            return false;
        return power2(index+1,n);
    }
}
