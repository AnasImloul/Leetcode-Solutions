class Solution:
    #Time-Complexity: Definitely faster than O(n!) since you don't recurse along every path poss
    #ible!
    #Space-Complexity: O(n), since in worst case, the recursion will utilize stack frame, which
    #will be at most stack depth of n! Also, arr array takes up n integers always!
    def countArrangement(self, n: int) -> int:
        #Initial Approach: Generate all permutations that use all elements in range 1-n and
        #check each individually at end if it's beautiful arragment and increment counter!
        
        #Additional optimization we can add to naive approach: If we every find that
        #current built up permutation is not beautiful, there is no need to build it further
        #-> This means stop recursing along this path and return to parent caller of recursion!
        
        #This can help avoid doing unnecessary recursive work!
        
        #first, define a helper function to swap two elements at two index positions given an array!
        
        #initialize array of numbers from 1 to n!
        arr = []
        for i in range(1, n+1):
            arr.append(i)
        
        def swap(a, i1, i2):
            nonlocal arr
            tmp = a[i1]
            a[i1] = a[i2]
            a[i2] = tmp
        
        #then we define a recursive helper function that will recursively build up permutation
        #that is gauranteed to be beautiful!
        
        #initialize counter!
        ans = 0
        n = len(arr)
        #parameters: i for index position in which we consider elements starting from
        def helper(i, cur):
            nonlocal ans, n
            #otherwise, check the base case -> we are able to consider swaps for each
            #and every element and index goes out of bounds!
            if(i == n):
                ans += 1
                return
            
            #otherwise, we need to consider swapping current ith index element with
            #all elements that come after it!
            
            for a in range(i, len(cur)):
                #once we do the swap go ahead and recurse!
                #But be careful: only recurse if cur[a] is divisble by position i + 1 or
                #otherway around: but needs at least 1 condition to be fulfilled!
                #otherwise, recursing along this particular path will lead to not beautiful
                #arrangement permutation!
                #check if current ith index element does not satisfy beautiful arragment rule!
                if(cur[a] % (i+1) != 0 and (i+1) % cur[a] != 0):
                    continue
                swap(cur, i, a)
                helper(i + 1, cur)
                #once we finish recursion and return, we need to restore the current array
                #by backtracking!
                swap(cur, i, a)
            
        helper(0, arr)
        return ans