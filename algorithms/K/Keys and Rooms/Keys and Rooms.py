class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        # Create a set of for rooms visited
        visited_rooms = set()
        
        # Create a queue to do a breadth first search visiting rooms
        # Append the first room, 0, to the queue to begin the search
        queue = collections.deque()
        queue.append(0)
        
        # Perform the breadth first search with the queue
        while queue:
            for _ in range(0, len(queue)):
                # Search the room
                room_number = queue.popleft()
                
                # If we haven't visited the room, get the keys from the room
                if room_number not in visited_rooms:
                
                    # Collect the keys from the room
                    found_keys = rooms[room_number]
                    
                    # Add the keys to the queue so they can be tested
                    for key in found_keys:
                        queue.append(key)
                        
                    # Add the current room to the visited set
                    visited_rooms.add(room_number)
        
        # If we visited all of the rooms, then the number of visited rooms should be
        # equal to the number of total rooms
        if len(visited_rooms) == len(rooms):
            return True
        
        return False
