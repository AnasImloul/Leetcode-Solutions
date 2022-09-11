# Runtime: 2003 ms (Top 6.82%) | Memory: 20.5 MB (Top 21.33%)

def cal(ele):
    return ele[0]**2 +ele[1]**2

def partition(arr,start,end):
    # We must take a pivot element randomly to make Quick select work faster
    rdIdx = randint(start,end)
    arr[rdIdx],arr[end] = arr[end],arr[rdIdx]
    pivot = arr[end]
    i = start-1
    pivot_dis = cal(pivot)
    for j in range(start,end):
        if cal(arr[j]) <= pivot_dis:
            i+=1
            arr[j],arr[i] = arr[i],arr[j]

    arr[i+1],arr[end] = arr[end],arr[i+1]
    return i+1
def qSelect(arr,kth,start,end):
    if start < end:
        pv= partition(arr,start,end)
        # _______________________
        # | Left |ele| Right|
        # ------------------------
        # pv
        # after partition function call, pv is the index that sacrify:
        # all elements in Left will smaller than ele
        # all elements in Right side will greater than ele
        if pv == kth:#
            return
        if kth < pv:
            return qSelect(arr,kth,start,pv-1)
        else:
            return qSelect(arr,kth,pv+1,end)
# Space O (logn) because of using recursion
# Time: Average case: O(N)
# Worst case: O(N**2)
class Solution:
    def kClosest(self, points, k):
        # print(points)
        qSelect(points,k-1,0,len(points)-1)# kth smallest number will be at (k-1) index in sorted array
        return points[:k]