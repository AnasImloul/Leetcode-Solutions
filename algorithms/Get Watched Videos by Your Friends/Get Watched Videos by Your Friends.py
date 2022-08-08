  class Solution:
	def watchedVideosByFriends(self, w: List[List[str]], f: List[List[int]], id: int, l: int):
		d=deque([(id,0)])
		v={id}
		q={}
		while d:
			x,y=d.popleft()
			if y<l:
				for j in f[x]:
					if j not in v:
						v.add(j)
						d.append((j,y+1))
			else:
				for j in w[x]:
					q[j]=q.get(j,0)+1
		s=sorted([j,q[j]]for j in q)
		s.sort(key=lambda x:x[1])
		return [i[0] for i in s]