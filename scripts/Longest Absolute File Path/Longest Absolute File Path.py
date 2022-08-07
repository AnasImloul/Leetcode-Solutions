class Solution:
	def lengthLongestPath(self, input: str) -> int:
		if "." not in input:
			return 0

		a=input.split("\n")
		files=[]
		for i in a:
			if "." in i:
				files.append(i)

		final=[]
		for i in range(len(files)):
			file=files[i]
			lvl=file.count("\t")
			idx=a.index(file)-1
			save=[files[i].replace("\t","")]
			for j in range(lvl):
				while a[idx].count("\t")!=lvl-1:
					idx-=1
				lvl=a[idx].count("\t")
				save.append(a[idx].replace("\t",""))
				idx-=1
			final.append(save)

		final=list(map("/".join,final))
		return len(max(final,key=len))