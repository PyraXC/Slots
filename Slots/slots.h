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
	int calcRoll(vector<vector<char>>);
	void createReel();
	int calcReel(vector<vector<char>>);
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
	int getBonusTotal();
	float getTotal();

	void setBet(int amount);
	void setBonus(int bonus);
	void setLines(int lines);
	void printRoll(vector<vector<char>>);

private:
	int money;
	int bet;
	int spins;
	int max;
	float total;
	int MW;
	int BONUS;
	int bonusTotal;
	vector<vector<char>> LINES;
};