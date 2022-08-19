// Runtime: 1195 ms (Top 33.33%) | Memory: 146.2 MB (Top 33.33%)

var findAllPeople = function(n, meetings, firstPerson) {
    const timeToMeeting = mapSortedTimeToMeetings(meetings);

    const peopleThatCurrentlyHaveSecret = new Set([0, firstPerson]);
    for (const peopleInMeetings of timeToMeeting.values()) {
        const personToMeetingsWithPeople =
            mapPeopleToPeopleTheyAreHavingMeetingsWith(peopleInMeetings);
        let peopleInMeetingsWithSecret =
            findPeopleThatHaveTheSecret(peopleInMeetings, peopleThatCurrentlyHaveSecret);

        // BFS algorithm
        while (peopleInMeetingsWithSecret.size > 0) {
            const nextPeopleInMeetingsWithSecret = new Set();
            for (const attendee of peopleInMeetingsWithSecret) {
                for (const personInMeetingWithAttendee of personToMeetingsWithPeople[attendee]) {

                    // only add new people that have the secret otherwise there will be an
                    // infinite loop
                    if (!peopleThatCurrentlyHaveSecret.has(personInMeetingWithAttendee)) {
                        nextPeopleInMeetingsWithSecret.add(personInMeetingWithAttendee);
                        peopleThatCurrentlyHaveSecret.add(personInMeetingWithAttendee);
                    }
                }
            }
            peopleInMeetingsWithSecret = nextPeopleInMeetingsWithSecret;
        }
    }
    return [...peopleThatCurrentlyHaveSecret];
};

// groups all the meetings by time
// keys (time) is sorted in ascending order
function mapSortedTimeToMeetings(meetings) {
    meetings.sort((a, b) => a[2] - b[2]);

    const timeToMeeting = new Map();
    for (const [person1, person2, time] of meetings) {
        if (!timeToMeeting.has(time)) {
            timeToMeeting.set(time, []);
        }
        timeToMeeting.get(time).push([person1, person2]);
    }
    return timeToMeeting;
}

// creates an adjacency list of people and people they are having meetings with
function mapPeopleToPeopleTheyAreHavingMeetingsWith(peopleInMeetings) {
    const personToMeetingsWithPeople = {};
    for (const [person1, person2] of peopleInMeetings) {
        if (!personToMeetingsWithPeople[person1]) {
            personToMeetingsWithPeople[person1] = [];
        }
        if (!personToMeetingsWithPeople[person2]) {
            personToMeetingsWithPeople[person2] = [];
        }
        personToMeetingsWithPeople[person1].push(person2);
        personToMeetingsWithPeople[person2].push(person1);
    }
    return personToMeetingsWithPeople;
}

// finds all the people that are in meetings that have the secret
// set data structue is used so that people are not duplicated
function findPeopleThatHaveTheSecret(peopleInMeetings, peopleThatCurrentlyHaveSecret) {
    const peopleInMeetingsWithSecret = new Set();
    for (const peopleInMeeting of peopleInMeetings) {
        for (const person of peopleInMeeting) {
            if (peopleThatCurrentlyHaveSecret.has(person)) {
                peopleInMeetingsWithSecret.add(person);
            }
        }
    }
    return peopleInMeetingsWithSecret;
}