from bisect import bisect_left

class Solution:
    def avoidFlood(self, rains):
        full_lakes, dry_dates = {}, []
        ans = [-1] * len(rains)

        for date, rain_lake in enumerate(rains):
            if rain_lake == 0:  # no rain, we can dry one lake
                dry_dates.append(date)  # keep dry date, we'll decide later
                continue

            if rain_lake in full_lakes:  # the lake is already full
                # BS find out earliest day we can use to dry that lake | greedy
                dry_day = bisect_left(dry_dates, full_lakes[rain_lake])

                if dry_day >= len(dry_dates): return []  # can not find a date to dry this lake

                ans[dry_dates.pop(dry_day)] = rain_lake  # dry this lake at the date we choose

            # remember latest rain on this lake
            full_lakes[rain_lake] = date

        # we may have dry dates remain, on these days, rain > 0, we can not use -1, just choose day 1 to dry (maybe nothing happend)
        for dry_day in dry_dates:
            ans[dry_day] = 1

        return ans
