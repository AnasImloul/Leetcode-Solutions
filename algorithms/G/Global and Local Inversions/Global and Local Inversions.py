class Solution:
    def isIdealPermutation(self, nums: List[int]) -> bool:
        
        
        def mergecount(a,m,bb,n):
            # print(a,b)
            c=[0]*(m+n)
            k=0
            i=0
            j=0
            cnt=0
            while(k<m+n):
                # print()
                if (j==n or (i<m and a[i]<=bb[j])):
                    c[k]=a[i]
                    k+=1
                    i+=1
                elif (i==m or (j<n and a[i]>bb[j])):
                    # print(k,j,n,bb,c,i,m)
                    c[k]=bb[j]
                    k+=1
                    j+=1
                    cnt+=m-i
                    
                
            # print(cnt)
            return (cnt,c)
                    
                
        
        def mergesortcount(arr,l,r):
            
            if r-l==1:
                b=[]
                b.append(arr[l])
                return (0,b)
            
            if r-l>1:
                mid=(l+r)//2
                lc,larr=mergesortcount(arr,l,mid)
                # print(lc,larr,'lc,larr')
                rc,rarr=mergesortcount(arr,mid,r)
                # print(rc,rarr,'rc,rarr')
                mc,b=mergecount(larr,mid-l,rarr,r-mid)
                # print(mc,b,'mc,b')
                
                return ((lc+rc+mc),b)
            
        # print()
        
        def local():
            f=0
            for i in range(1,len(nums)):
                if nums[i]<nums[i-1]:
                    f+=1
            # print(f)        
            return f
        
        
                
        
        
        return mergesortcount(nums,0,len(nums))[0]==local()
        
