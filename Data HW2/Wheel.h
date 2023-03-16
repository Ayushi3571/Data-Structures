#pragma once
#include <cstdlib>

class Wheel {
private:
	int minimum = 1;   //might need setter
	int maximum = 10;

public:
	Wheel() {
		minimum = 1;
	}
	void SetMax(int x) { maximum = x; }
	
	// create a seperate Wheel.cpp for below
	Wheel(int a, int b) {
		minimum = a;
		maximum = b;
	}
	//Overloaded for bonus
	int spin(int max, int wins) {
		int x = rand();  
		x = (x % (max + wins)) + 1;
		return x;
	}
	
	int spin() {
		int x = rand();
		return x;
	}
};