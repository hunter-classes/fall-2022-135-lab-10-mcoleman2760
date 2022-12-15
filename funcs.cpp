#include <iostream>
#include <cmath>
#include <string>
#include "time.h"
#include "movie.h"
#include "timeslot.h"



int minutesSinceMidnight(Time time){

int hrtomin = time.h * 60;
int totalminutes = hrtomin + time.m;

return totalminutes;


}

int minutesUntil(Time earlier, Time later){

int until = minutesSinceMidnight(later) - minutesSinceMidnight(earlier);

return until;

}

Time addMinutes(Time time0, int min){

time0.m = min  + time0.m;

if (time0.m == 60){
    time0.m = 0;
    time0.h = time0.h + 1;
}

else if(time0.m > 60){
int hours = time0.m/60;
time0.m = time0.m - hours*60;
time0.h = time0.h + hours;

}


return time0;

}

void printTime(Time time) {

std::cout << time.h << ":" << time.m ;

}

std::string printMovie(Movie mv){

std::string g;

switch (mv.genre) {

case ACTION : g = "ACTION"; break;

case COMEDY : g = "COMEDY"; break;

case DRAMA : g = "DRAMA"; break;

case ROMANCE : g = "ROMANCE"; break;

case THRILLER : g = "THRILLER"; break;

}

return mv.title + " " + g + " (" + std::to_string(mv.duration) + " min) ";

}

std::string getTimeSlot(TimeSlot ts){
   Time j = addMinutes(ts.startTime,ts.movie.duration);
    


     return (printMovie( ts.movie ) + " [start at " + std::to_string( ts.startTime.h) + ":" + std::to_string(ts.startTime.m) + ", ends by " 
     + std::to_string(j.h) + ":" + std::to_string(j.m) + "]"); 


}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  
Time nextShowTime = addMinutes(ts.startTime, nextMovie.duration);

TimeSlot nextTimeSlot = { nextMovie , nextShowTime };

return nextTimeSlot;

} 

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {

    int interval = minutesUntil(ts1.startTime, ts2.startTime);

    if (ts1.movie.duration > interval){
    return true;
    }
    else {
    return false;
    }
}
