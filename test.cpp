#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

Time t1 = {0, 0};
Time t2 = {4,33};
Time t3 = {0, 50};
Time t4 = {2, 0};

TEST_CASE("Minutes Since Midnight") {
CHECK(minutesSinceMidnight(t1) == 0);
    CHECK(minutesSinceMidnight(t2) == 273);
    CHECK(minutesSinceMidnight(t3) == 50);
    CHECK(minutesSinceMidnight(t4) == 120);
}
TEST_CASE("Minutes Between Two Times")
{
    CHECK(minutesUntil(t1, t2) == 273);
    CHECK(minutesUntil(t2, t3) == -223);
    CHECK(minutesUntil(t3, t4) == 70);
    CHECK(minutesUntil(t2, t4) == -153);
}
TEST_CASE("Add Minutes")
{
    CHECK(addMinutes(t1, 65).h == 1);
    CHECK(addMinutes(t1, 65).m == 5);
    
    CHECK(addMinutes(t2, 452).h == 12);
    CHECK(addMinutes(t2, 452).m == 5);
    CHECK(addMinutes(t3, 600).h == 10);
    CHECK(addMinutes(t3, 600).m == 50);
}

Movie m1 = {"Back to the Future", COMEDY, 116};
Movie m2 = {"Black Panther", ACTION, 134};
Movie m3 = { "Blind", THRILLER , 111 };
Movie m4 = { "Titanic", DRAMA, 120 };
Movie m5 = { "Titanic", DRAMA, 120 };
Movie m6 = { "Bridesmaids", COMEDY, 132 };
TimeSlot morning = {m1, {9, 15}};
TimeSlot daytime = {m2, {12, 15}};
TimeSlot evening = {m3, {16, 45}};
TimeSlot ts1 = { m5,{ 14, 20 } };
TimeSlot ts3 = { m6,{ 15, 20 } };

TEST_CASE("Get Time Slots")
{ 
    CHECK(getTimeSlot(morning) == "Back to the Future COMEDY (116 min)  [start at 9:15, ends by 11:11]");
    CHECK(getTimeSlot(daytime) == "Black Panther ACTION (134 min)  [start at 12:15, ends by 14:29]");
    CHECK(getTimeSlot(evening) == "Blind THRILLER (111 min)  [start at 16:45, ends by 18:36]");
}

TEST_CASE("Next Movie Time Slot")
{
    CHECK(scheduleAfter(morning, m1).startTime.h == 11);
    CHECK(scheduleAfter(morning, m1).startTime.m == 11);
    CHECK(scheduleAfter(daytime, m2).startTime.h == 14);
    CHECK(scheduleAfter(daytime, m2).startTime.m == 29);
    CHECK(scheduleAfter(evening, m1).startTime.h == 18);
    CHECK(scheduleAfter(evening, m3).startTime.m == 36);
}

TEST_CASE("Overlap Cases")
{
    CHECK(timeOverlap(morning, daytime) == false);
    CHECK(timeOverlap(ts1, ts3) == true);
}
