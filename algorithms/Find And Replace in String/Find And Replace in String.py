class Solution:
    def findReplaceString(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        
        inputs = list(zip(indices,sources,targets))
        inputs.sort(key = lambda x: x[0])
        
        offset = 0
        for idx, src, tgt in inputs:
            idx += offset
            if s[idx:idx + len(src)] != src:
                print('hi')
                print(idx)
                continue
                
            offset += len(tgt) - len(src)
            s = s[:idx] + tgt + s[idx+len(src):]
            
        return s
