#pragma once
#include <iostream>
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie {    
public: 
    std::string title;
    Genre genre;     
    int duration;    
};
