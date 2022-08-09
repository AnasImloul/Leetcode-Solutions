class Solution:
    def minSteps(self, n: int) -> int:      
        # at every step we can copy or paste
        # paste -> we need to know the current clipboard content (count)
        # copy -> set clipboard count to current screen count (we should consider it, if the last operation was paste)
        
        memo = {}
        
        def dfs(clipboard_count, screen_count):
            if (clipboard_count, screen_count) in memo:                   
                return memo[(clipboard_count, screen_count)]
            
            # we reached n, this is a valid option
            if screen_count == n: return 0
            
            # we passed n, not a valid option
            if screen_count > n: return float('inf')                
            
            # paste or copy
            copy_opt = paste_opt = float('inf')
            
            # we should only paste if clipboard is not empty
            if clipboard_count > 0:
                paste_opt = dfs(clipboard_count, screen_count + clipboard_count)             
            
            # we should consider copy only if the last operation was paste
            if screen_count > clipboard_count:
                copy_opt = dfs(screen_count, screen_count) 
            
            # save to memo
            memo[(clipboard_count, screen_count)] = 1 + min(paste_opt, copy_opt)            
            return memo[(clipboard_count, screen_count)]
            
        return dfs(0, 1)
            
