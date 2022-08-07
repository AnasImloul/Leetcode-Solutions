class Solution:        
    def findTicketsAdjList(self, tickets):
        ticket = {}
        for src,dest in tickets:
            if src in ticket:
                ticket[src].append(dest)
            else:
                ticket[src] = [dest]

        for src,dest in ticket.items():
            if len(dest)>1:
                ticket[src] = sorted(ticket[src], reverse=True)
                
        return ticket
    
    def reconstructItinerary(self, source, tickets, itinerary):
        if source in tickets:
            while tickets[source]:        
                destination = tickets[source].pop()
                self.reconstructItinerary(destination, tickets, itinerary)
        itinerary.append(source)
        return itinerary
                        
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        if len(tickets)==1:
            if "JFK" not in tickets[0]:
                return []
            
        ticketsAdj = self.findTicketsAdjList(tickets)
        if "JFK" not in ticketsAdj:
            return []
        itinerary = []
        itinerary = self.reconstructItinerary("JFK", ticketsAdj, itinerary)
        
        return itinerary[::-1]
        
