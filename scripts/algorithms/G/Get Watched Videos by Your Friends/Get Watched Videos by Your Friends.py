class Solution:
	def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
		q=[id]
		vis=set([id])
		l=0
		while l<level:
			new_q=[]
			for x in q:
				for friend in friends[x]:
					if not friend in vis:
						vis.add(friend)
						new_q.append(friend)
			q=new_q
			l+=1
		a=Counter()
		for x in q:
			for vids in watchedVideos[x]:
				a[vids]+=1
		A=sorted([[a[x],x] for x in a])
		return [x[1] for x in A]