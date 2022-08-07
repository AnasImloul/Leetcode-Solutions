class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        
        # Setup counts for bulls and cows
        bulls = cows = 0
        
        # Copy secret and guess into lists that are easier to work with
        secretCopy = list(secret)
        guessCopy = list(guess)
        
        # In a for loop, check every pair of letters at the same index in both guess and secret for matching letters, AKA bulls
        for i in range(len(secret)):
            
            # If they match, bulls += 1 and pop() the letters from the copy lists via their .index()
            if secret[i] == guess[i]:
                bulls += 1
                secretCopy.pop(secretCopy.index(secret[i]))
                guessCopy.pop(guessCopy.index(guess[i]))
                
                
        # Count() the letters remaining in secret and guess lists
        secretCounter = Counter(secretCopy)
        guessCounter = Counter(guessCopy)
        
        # Counter1 - Counter2 gives us Counter1 with any matching values of Counter1 and Counter2 removed; leftover Counter2 values are trashed
        # secretCounter - guessCounter gives us the secretCounter except for any correctly guessed letters
        # Therefore, subtract this difference from the OG secretCounter to be left with a counter of only correctly guessed letters
        dif = secretCounter - (secretCounter - guessCounter)
        
        # The .total() of the dif Counter is the number of cows
        cows = dif.total()

        # return the formatted string with req. info
        return f'{bulls}A{cows}B'
