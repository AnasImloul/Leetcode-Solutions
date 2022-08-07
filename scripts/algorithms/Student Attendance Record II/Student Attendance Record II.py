class Solution:
    def checkRecord(self, n: int) -> int:
        if n == 1:
            return 3
        if n==2:
            return 8
        """
        Keep track of last 2 digits
        ways to get ll = last combinations ending with p,l (l,l not allowed)
        ways to get lp = last combinations ending with l,p + p,l
        and so on
        
        finally account for adding A by the usual loop.
        """
        
        combos_l_l = 1
        combos_l_p = 1
        combos_p_l = 1
        combos_p_p = 1

        MOD = 1000000007
        
        f = [0]*(n+1)
        f[0] = 1
        f[1] = 2
        f[2] = 4
        for i in range(2, n):
            combos_l_l_new = combos_p_l
            combos_l_p_new = combos_l_l + combos_p_l
            combos_p_l_new = combos_l_p + combos_p_p 
            combos_p_p_new = combos_l_p + combos_p_p
            
            combos_l_l, combos_l_p, combos_p_l, combos_p_p = combos_l_l_new%MOD, combos_l_p_new%MOD, combos_p_l_new%MOD, combos_p_p_new  %MOD
            
            f[i+1] = (combos_l_l + combos_l_p + combos_p_l + combos_p_p)%MOD
            

        total = f[-1]
        # print(f)
        for i in range(1,n+1):
            total += (f[i-1]*f[n-i]) 
            
        return ( total ) % (MOD)
            
