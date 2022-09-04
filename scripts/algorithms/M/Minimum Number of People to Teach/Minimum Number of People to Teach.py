# Runtime: 2444 ms (Top 20.45%) | Memory: 28.6 MB (Top 5.68%)
class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        """
        1. Find out users who need to be taught
        2. If no user needs to be taught, return 0
        3. For all users who need to be taught a language, find the most popular language among them
        4. Teach that language to rest of the users who need to be taught.
        """
        need_to_be_taught = set()
        languages = [set(language) for language in languages]

        # 1. Find out users who needs to be taught
        for user1, user2 in friendships:
            # Adjust the 1 based indexing to 0 based indexing
            user1 = user1 - 1
            user2 = user2 - 1
            if not (languages[user1] & languages[user2]):
                need_to_be_taught.update([user1, user2])

        # 2. If no user needs to be taught, return 0
        if not need_to_be_taught:
            return 0

        # 3. For all users who needs to be taught a language, find the most popular language among them
        language_spoken_by = collections.defaultdict(int)
        for user in need_to_be_taught:
            # for each user increment the count of languages he can speak
            for language in languages[user]:
                language_spoken_by[language] += 1

        # find occurrence of language spoken by maximum users who can't communicate with each other
        popular_language_count = max(language_spoken_by.values())

        # 4. Teach that language to rest of the users who need to be taught.
        return len(need_to_be_taught)- popular_language_count
