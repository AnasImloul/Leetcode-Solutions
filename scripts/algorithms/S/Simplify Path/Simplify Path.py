class Solution:
   def simplifyPath(self, path: str) -> str:
   	stack = []
   	
   	i = 0
       while i < len(path):
           if path[i] == '/':
               i += 1
               continue

           else:
               cur = ''
               while i < len(path) and path[i] != '/':
                   cur += path[i]
                   i += 1

               if cur == '..':
                   if stack:
                       stack.pop()
               elif cur == '.' or cur == '':
                   i += 1
                   continue
               else:
                    stack.append(cur)

       return '/' + '/'.join(stack)
