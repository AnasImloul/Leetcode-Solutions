class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        LOWEST_DAY, LOWEST_MONTH, LOWEST_YEAR, DAY = 1, 1, 1971, 5
        DAYS = ("Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday")

        difference = self.daysBetweenDates((LOWEST_DAY, LOWEST_MONTH, LOWEST_YEAR), (day, month, year))
        return DAYS[(difference + DAY) % 7]

    def daysBetweenDates(self, date1: tuple, date2: tuple) -> int:
        LOWEST_YEAR = 1971

        def daysSinceLowest(date: tuple) -> int:
            day, month, year = date

            isLeapYear = lambda x: 1 if (x % 4 == 0 and x % 100 != 0) or x % 400 == 0 else 0

            days: int = 0
            # days between the LOWEST_YEAR and year
            days += 365 * (year - LOWEST_YEAR) + sum(map(isLeapYear, range(LOWEST_YEAR, year)))
            # days between year and exact date
            daysInMonth = (31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
            days += sum(daysInMonth[:month - 1]) + day
            return days

        return abs(daysSinceLowest(date1) - daysSinceLowest(date2))