/*
Explanation:

Let's say at some point we have coordinates as (a,b)
if(a>b) then at the previous step coordinate must be (a-b,b)
as it can't be (a,b-a) because all the coordinates are positive and for a>b... b-a<0
this continues till the point when a becomes <=b
we can run a loop till there but its time taking
we can observe that the above phenomeon occurs till it becomes (a%b,b)
example :
for (50,7) it would have been like this:
(50,7)...(43,7)...(36,7)...........(8,7)..(1,7)
1 = 50%7
By repeating this procedure, after the loop, we have to test if sx == tx or sy == ty. There is still a condition to test.
Let see we got sy = ty = 5 and have the following result
sx,sy = (16,5)
tx,ty = (21,5)
now if we run our program then it will stop at (1,5) which is not equal to sx,sy and will return false
however during our iteration we will encounter (16,5) infact after the first iteration only but according to our current code it won't detect it
so at the end we apply another condition:
check if (tx - sx) % ty == 0. In our case, (21 - 16) mod 5 = 0 so we can return true.
*/


class Solution 
{
public:
    // METHOD - 1
    bool reachingPoints_recursive(int sx, int sy, int tx, int ty) 
    {
        if (sx > tx ||  sy > ty)
        {
            return false;
        }
        
        if (sx == tx && sy == ty)
        {
            return true;
        }
        
        
        bool canReach = reachingPoints_recursive(sx, sx+sy, tx, ty);
        if (!canReach)
        {
            canReach = reachingPoints_recursive(sx+sy, sy, tx, ty);
        }
        
        return canReach;
    }
    
    
    // METHOD - 2
    bool reachingPoints_internal(int sx, int sy, int tx, int ty)
    {
        if (sx > tx || sy > ty)
        {
            return false;
        }
        else if (sx == tx && sy == ty)
        {
            return true;
        }
        
        while (tx > sx && ty > sy)
        {
            if (tx > ty)
            {
                // implies previous path to this tx, ty should have to be tx-ty, ty 
                // and this could continue till either tx < ty i.e difference would be tx % ty
                // so instead of doing that repeatedly just go the final point where 
                // tx would have started before started adding ty to it repeatedly 
                tx = tx % ty;
            }
            else
            {
                // implies previous path to this tx, ty should have to be (tx, ty-tx)
                // and this could continue till either tx > ty i.e difference would be tx % ty
                // so instead of doing that repeatedly just go the final point where 
                // ty would have started before started adding tx to it repeatedly
                ty = ty % tx;
            }
        }
        
        if ((tx == sx) && ((ty - sy) % sx == 0) )
        {
            return true;
        }
        else if ((ty == sy) && ((tx - sx) % sy == 0))
        {
            return true;
        }
        
        return false;
    }
    
    
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        // Method-1 : recurssion - will not work for larger numbers as stack will use up all the memory
		// return reachingPoints_recursive(sx, sy, tx, ty);
        
		// Method-2 : Effecient non recursive solution
        return reachingPoints_internal(sx, sy, tx, ty);
    }
};