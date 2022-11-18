#include <iostream>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"


using namespace std;
int main(){


Time t = {10, 30};
Time t2 = {13, 40};
Time t3 = {8,10};
cout << minutesSinceMidnight(t) << " " << minutesSinceMidnight(t2) << endl;

cout << minutesUntil( t, t2) << endl;

Time t4 = addMinutes(t3, 75);

cout << t4.h << " " << t4.m << endl;

Movie movie1 = {"Back to the Future", COMEDY, 116};

Movie movie2 = {"Black Panther", ACTION, 134};

Movie movie3 = { "Blind", THRILLER , 111 };
Movie movie5 = { "Titanic", DRAMA, 120 };
Movie movie6 = { "Bridesmaids", COMEDY, 132 };


TimeSlot morning = {movie1, {9, 15}};

TimeSlot daytime = {movie2, {12, 15}};

TimeSlot evening = {movie2, {16, 45}};

TimeSlot noon = {movie1,{13,00}};

TimeSlot night = {movie1,{20,20}};

cout << getTimeSlot(night) << endl;



TimeSlot ts1 = { movie5,{ 14, 20 } };

TimeSlot ts2 = scheduleAfter(ts1,movie5);

TimeSlot ts3 = { movie6,{ 15, 20 } };


cout << "Time slot for the next movie should start at: ";
printTime(ts2.startTime);



bool result = timeOverlap(ts1, ts2);

if (result){
cout << "\nThe two time slots are overlapped." << endl;
}
else{
cout << "\nThe two time slots are not overlapped." << endl;
}

bool result2 = timeOverlap(ts1, ts3);

if (result2){
cout << "The two time slots are overlapped." << endl;
}
else{
cout << "The two time slots are not overlapped." << endl;
}


}
