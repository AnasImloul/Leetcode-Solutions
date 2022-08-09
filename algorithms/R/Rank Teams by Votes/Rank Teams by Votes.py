#["ABC","ACB","ABC","ACB","ACB"]
#d = {
#    "A": [5, 0, 0],
#    "B": [0, 2, 3],
#    "C": [0, 3, 2]
#}
#keys represent the candidates
#index of array in dict represent the rank
#value of array item represent number of votes casted
#ref: https://www.programiz.com/python-programming/methods/built-in/sorted
class Solution:
    #T=O(mn + mlgm), S=O(mn)
	#n=number of votes
	#m=number of candidates and m(number of ranks) is constant(26)
    def rankTeams(self, votes: List[str]) -> str:
        d = {}
        #build the dict
        #T=O(mn), S=O(mn)
		#n=number of votes, m=number of candidates(26)
        for vote in votes:
            for i, c in enumerate(vote):
                #if key not in dict
                if c not in d:
                    #d[char] = [0, 0, 0]
                    d[c] = [0]*len(vote)
                #increment the count of votes for each rank
                #d["A"][0] = 1
                d[c][i] += 1
        #sort the dict keys in ascending order because if there is a tie we return in ascending order
		#sorted uses a stable sorting algorithm
        #T=O(mlgm), S=O(m)
        vote_names = sorted(d.keys()) #d.keys()=["A", "B", "C"]
        #sort the dict keys based on votes for each rank in descending order
        #T=O(mlgm), S=O(m)
        #sorted() always returns a list
        vote_rank = sorted(vote_names, reverse=True, key= lambda x: d[x])
        #join the list
        return "".join(vote_rank)
