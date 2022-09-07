# Runtime: 74 ms (Top 8.76%) | Memory: 14.1 MB (Top 82.26%)
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.final_list = []
        def subset(final_list,curr_list,listt,i):
            if i == len(listt):
                final_list.append(curr_list)
                return
            else:
                subset(final_list,curr_list,listt,i+1)
                subset(final_list,curr_list+[listt[i]],listt,i+1)
        subset(self.final_list,[],nums,0)
        return self.final_list