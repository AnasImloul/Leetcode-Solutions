class Solution(object):
    def maxAbsValExpr(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        max_ppp,max_ppm,max_pmp,max_pmm=float('-inf'),float('-inf'),float('-inf'),float('-inf')
        min_ppp,min_ppm,min_pmp,min_pmm=float('inf'),float('inf'),float('inf'),float('inf')
        for i,(a,b) in enumerate(zip(arr1,arr2)):
            ppp=a+b+i
            if ppp>max_ppp:max_ppp=ppp
            if ppp<min_ppp:min_ppp=ppp
            ppm=a+b-i
            if ppm>max_ppm:max_ppm=ppm
            if ppm<min_ppm:min_ppm=ppm
            pmp=a-b+i
            if pmp>max_pmp:max_pmp=pmp
            if pmp<min_pmp:min_pmp=pmp
            pmm=a-b-i
            if pmm>max_pmm:max_pmm=pmm
            if pmm<min_pmm:min_pmm=pmm
        return max(max_ppp-min_ppp,max_ppm-min_ppm,max_pmp-min_pmp,max_pmm-min_pmm)   
