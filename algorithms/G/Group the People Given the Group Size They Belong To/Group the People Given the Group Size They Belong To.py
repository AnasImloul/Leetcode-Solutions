class Solution(object):
    def groupThePeople(self, groupSizes):
        """
        :type groupSizes: List[int]
        :rtype: List[List[int]]
        """
        dict_group={}
        for i in range(len(groupSizes)):
            if groupSizes[i] not in dict_group:
                dict_group[groupSizes[i]]=[i]
            else:
                dict_group[groupSizes[i]].append(i)
        return_list=[]
        for i in dict_group:
            num_list=dict_group[i]
            for j in range(0,len(num_list),i):
                return_list.append(num_list[j:j+i])
        return return_list
