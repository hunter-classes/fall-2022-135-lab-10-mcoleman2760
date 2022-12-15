#include <iostream>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

int main(){


Time t = {10, 30};
Time t2 = {13, 40};
Time t3 = {8,10};

std::cout << "These moments of time are " <<minutesSinceMidnight(t) << " and " <<minutesSinceMidnight(t2) << " minutes after midnight." << std::endl;
std::cout << "The interval between them is " << minutesUntil( t, t2) << " minutes"  << std::endl;

Time t4 = addMinutes(t3, 75);

std::cout <<  "Add Minutes Function: " << t4.h << " " << t4.m << std::endl;

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

std::cout << getTimeSlot(night) << std::endl;



TimeSlot ts1 = { movie5,{ 14, 20 } };
TimeSlot ts2 = scheduleAfter(ts1,movie5);
TimeSlot ts3 = { movie6,{ 15, 20 } };


std::cout << "Time slot for the next movie should start at: ";
printTime(ts2.startTime);



bool result = timeOverlap(ts1, ts2);

if (result){
std::cout << "\nThe two time slots are overlapped." << std::endl;
}
else{
std::cout << "\nThe two time slots are not overlapped." << std::endl;
}

bool result2 = timeOverlap(ts1, ts3);

if (result2){
std::cout << "The two time slots are overlapped." << std::endl;
}
else{
std::cout << "The two time slots are not overlapped." << std::endl;
}


}
