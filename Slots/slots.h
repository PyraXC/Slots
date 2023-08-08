#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

class Machine {
public:
	Machine(int dollars);
	Machine();
	vector<vector<char>> roll();
	vector<vector<char>> bonusRoll(int rollNum, int rolls, int &rng);
	void calcRoll(vector<vector<char>>);
	int calcVal(string str);
	string calcWild(string str);
	void addMoney(int mon);

	int getBal();
	int getBet();
	int getSpins();
	int getMax();
	int getLines();
	int getMW();
	int getBonus();
	float getTotal();

	void setBet(int amount);
	void setBonus(int bonus);
	void setLines(int lines);

private:
	int money;
	int bet;
	int spins;
	int max;
	float total;
	int MW;
	int BONUS;
	vector<vector<char>> LINES;
};