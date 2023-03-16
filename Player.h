#pragma once
#include "Wheel.h"

//Create a player class that includes an instance of a wheel class.  
// The player should have a way to track their current amount of money.

//int player{ 100 };
//int player_ball{ 0 };
//int house{ 100 };
//int house_ball1{ 0 };
//int house_ball2{ 0 };

class Player {
public: //because fuck you
	Wheel wheel;
	int score{ 100 };
	//int ball;
	Player() {
		score = 100;
	}
	void add(int x) { score += x; }
	
	int getScore() { return score; }
	//put in cpp
	int ball(int max) {
		int x;
		x = wheel.spin();
		x = (x % max) + 1;
		return x;
	}

	int ball(int max, int wins) {
		//to do
		return 0;
	}
};