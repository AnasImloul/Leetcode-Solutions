class Solution:
    
    def minDays(self, listOfFlowerBloomDays: List[int], targetNumberOfBouquets: int, flowersPerBouquet: int) -> int:
        
        def numberOfBouquetsWeCanMakeOnThisDay(dayThatWeAreChecking):
            
            currentListOfAdjacentBloomedFlowers = []
            numberOfBouquetsWeCanMakeOnThisDay = 0
            
            for dayThatFlowerBlooms in listOfFlowerBloomDays:
                
                # check if the flower has bloomed on this day 
                if dayThatFlowerBlooms <= dayThatWeAreChecking:
                    
                    # add to the list an adjacent bloomed flowers, I use 'x' because the description uses an 'x'
                    currentListOfAdjacentBloomedFlowers.append('x')
                    
                else:
                    # we've hit a day where we don't have a bloomed flower, so the list of adjacent bloomed flowers has to be reset
                    # BUT FIRST figure out how many bouquets we can make with this list of adjacent bloomed flowers
                    numberOfBouquetsWeCanMakeOnThisDay += len(currentListOfAdjacentBloomedFlowers)//flowersPerBouquet
                    
                    # RESET list of adjacent bloomed flowers cause we're on a day where the a flower has not bloomed yet
                    currentListOfAdjacentBloomedFlowers = []
            
            # we've gone through the entire listOfFlowerBloomDays list and need to check if the "residual" current list 
            # of adjacent bloomed flowers can make a bouquet ... so handle it here
            numberOfBouquetsWeCanMakeOnThisDay += len(currentListOfAdjacentBloomedFlowers)//flowersPerBouquet
                    
            return numberOfBouquetsWeCanMakeOnThisDay
        
        
        # if the TOTAL amount of flowers we need doesn't match the number of possible flowers we can grow,
        # then the given inputs are impossible for making enough bouquets (we don't have enough flowers)
        totalNumberOfFlowersNeeded = targetNumberOfBouquets*flowersPerBouquet
        numberOfFlowersWeCanGrow = len(listOfFlowerBloomDays)
        if numberOfFlowersWeCanGrow < totalNumberOfFlowersNeeded: 
            return -1
        
        # no need to go past the day of the flower with the longest bloom date
        leftDay = 0
        rightDay = max(listOfFlowerBloomDays)
        
        while leftDay < rightDay:
            
            # currentDay is functioning as the "mid" of a binary search
            currentDay = leftDay + (rightDay-leftDay)//2
            
            # as in most binary searches, we check if the mid (which I'm calling 'currentDay') satisfies the constraint
            # that is, if we can make the target amount of bouquets on this day
            if numberOfBouquetsWeCanMakeOnThisDay(currentDay) < targetNumberOfBouquets:
                
                # womp womp, we can't make enough bouquets on this day, so set up for next iteration
                # the "correct day" is on the right side, so we get rid of all the "incorrect days" on the left side
                # by updating the left to the currentDay+1
                leftDay = currentDay+1
            else:
                
                # yay, we can make enough bouquets on this day, but we don't know if this is the "minimum day"
                # we discard the right side to keep searching
                rightDay = currentDay
        
        # leftDay >= rightDay, so we've found the "minimum day"
        return leftDay
		