#include "Player.h"
#include <iostream>

int half(int p_ball, int house1, int house2) {
	std::cout << "The house rolled: " << house1 << " and " << house2 << std::endl;
	if ((house1 >= p_ball) && (house2 >= p_ball)) {
		return -1;
	}
	else {
		return 0;
	}
}

int Double(int p_ball, int house1, int house2) {
	std::cout << "The house rolled: " << house1 << " and " << house2 << std::endl;
	if ((house1 >= p_ball) || (house2 >= p_ball)) {
		return -2;
	}
	else {
		return +2;
	}
}

int keep(int p_ball, int house1) {
	std::cout << "The house rolled: " << house1 << std::endl;
	if (house1 >= p_ball) {
		return -1;
	}
	else {
		return +1;
	}
}

bool easy_mode() {

	int max{ 0 };
	int bet;
	int option{ 5 };
	int x;
	int player_ball;
	Player pl1;
	Player house;
	bool check{ true };

	while (check) {
		std::cout << "Enter the number of values on the wheel (6 - 20)\n";
		std::cin >> max;
		if ((max < 6) && (max > 20)) {
			check = false;
		}
		else {
			std::cout << "Please enetr a number in the range";
		}
	}
	std::cout << "Choose a minimum bet\n";
	std::cin >> bet;

	player_ball = pl1.ball(max);
	std::cout << "You rolled: " << player_ball << std::endl;
	std::cout << "Enter 0 to half your wager\n" <<
		"Enter 1 to keep wager\n" <<
		"Enter 2 to double your wager\n";
	std::cin >> option;
	int house_ball1 = house.ball(max);
	int house_ball2 = house.ball(max);

	switch (option) {
	case 0:
		x = half(player_ball, house_ball1, house_ball2);
		pl1.add(x * bet);
		break;
	case 1:
		x = keep(player_ball, house_ball1);
		pl1.add(x * bet);
		break;
	case 2:
		x = Double(player_ball, house_ball1, house_ball2);
		pl1.add(x * bet);
		break;
	}
	//keep house score?
	std::cout << "Your new score is: " << pl1.getScore() << std::endl;
	//lose or cash out?
	if (pl1.getScore() <= 0) {
		return false;
	}
	return true;
}

bool hard_mode() {

	int max{ 0 };
	int bet;
	int option{ 5 };
	int x;
	int player_ball;
	Player pl1;
	Player house;
	bool check{ true };
	int house_wins{ 0 };

	while (check) {
		std::cout << "Enter the number of values on the wheel (6 - 20)\n";
		std::cin >> max;
		int house_range = max;
		if ((max < 6) && (max > 20)) {
			check = false;
		}
		else {
			std::cout << "Please enetr a number in the range";
		}
	}
	std::cout << "Choose a minimum bet\n";
	std::cin >> bet;

	player_ball = pl1.ball(max);
	std::cout << "You rolled: " << player_ball << std::endl;
	std::cout << "Enter 0 to half your wager\n" <<
		"Enter 1 to keep wager\n" <<
		"Enter 2 to double your wager\n";
	std::cin >> option;
	int house_ball1 = house.ball(max);
	int house_ball2 = house.ball(max);

	switch (option) {
	case 0:
		x = half(player_ball, house_ball1, house_ball2);
		pl1.add(x * bet);
		if (x < 0) {
			house_wins += 1;
		}
		else {
			house_wins = 0;
		}
		break;
	case 1:
		x = keep(player_ball, house_ball1);
		pl1.add(x * bet);
		break;
		if (x < 0) {
			house_wins += 1;
		}
		else {
			house_wins = 0;
		}
	case 2:
		x = Double(player_ball, house_ball1, house_ball2);
		pl1.add(x * bet);
		break;
		if (x < 0) {
			house_wins += 1;
		}
		else {
			house_wins = 0;
		}
	}
	//keep house score?
	std::cout << "Your new score is: " << pl1.getScore() << std::endl;
	//lose or cash out?
	if (pl1.getScore() <= 0) {
		return false;
	}
	return true;
}

int main() {
	
	int max{ 0 };
	int bet;
	int option{ 5 };
	int x;
	int player_ball;
	Player pl1;
	Player house;
	char hard_mode{ 'a' };

	bool check{ true };
	while (check) {
		std::cout << "Would you like to play in Hard mode? (y or n)\n";
		std::cin >> hard_mode;
		if ((hard_mode == 'y') || (hard_mode == 'n')) {
			check = false;
		}
		else {
			std::cout << "Please enetr y or n";
		}
	}
	
	bool flag{ true };
	while (flag) {
		if (hard_mode == 'y') {
			//do this
		}
		else {
			flag = easy_mode();
		}
	}

	return 0;
}