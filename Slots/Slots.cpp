// Slots.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Gamba

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <time.h>
#include "slots.h"
#include <random>
#include <map>

using namespace std;
int PRINT = 1;
int DEBUG = 0;
int PRINTLINES = 0;
const vector<vector<char>> LIST{ 
    { 'A', 'a', 'K', 'k', 'Q', 'q', 'J', 'j', 'S', 's', 'W'},     //Reel 1
    { 'A', 'a', 'K', 'k', 'Q', 'q', 'J', 'j', 'S', 's', 'W'},     //Reel 2
    { 'A', 'a', 'K', 'k', 'Q', 'q', 'J', 'j', 'S', 's', 'W', 'B'},//Reel 3 Added Bonus
    { 'A', 'a', 'K', 'k', 'Q', 'q', 'J', 'j', 'S', 's', 'W', 'B'},//Reel 4 Added Bonus
    { 'A', 'a', 'K', 'k', 'Q', 'q', 'J', 'j', 'S', 's', 'W', 'B'} //Reel 5 Added Bonus
};
const vector<vector<char>> BONUSLIST{
    { 'A', 'a', 'K', 'k', 'Q', 'q', 'J', 'j', 'S', 's', 'W', 'W'},//Reel 1 Double Wilds
    { 'W'},                                                       //Reel 2 ALL WILD
    { 'A', 'a', 'K', 'k', 'Q', 'q', 'J', 'j', 'S', 's', 'W', 'W'},//Reel 3 Double Wilds
    { 'W'},                                                       //Reel 4 ALL WILD
    { 'A', 'a', 'K', 'k', 'Q', 'q', 'J', 'j', 'S', 's', 'W', 'W'} //Reel 5 Double Wilds
};

//const vector<char> LIST{ 'A', 'K', 'Q', 'J', 'A', 'K', 'Q', 'J','A', 'K', 'Q', 'J', 'S', 'S', 's', 's', 'W' };
//const vector<char> LIST{ 'A', 'K', 'Q', 'J', 'S', 'W' };
//const vector<char> LIST{ 'W', 'W' };
const map<char, int> VALUES{ {'A', 7},{'K', 6},{'Q', 6},{'J', 6},{'S', 10},{'B', 10}, {'W', 10},{'s', 8}, {'a', 4}, {'k', 4}, {'q', 4}, {'j', 4} };

vector<vector<char>> LINES15{  {'2','2','2','2','2'}, {'1','1','1','1','1'}, {'3','3','3','3','3'},
    {'1', '2', '3', '2', '1'}, {'3', '2', '1', '2', '3'},                                                   //Line 5
    {'1', '1', '3', '1', '1'},{'3', '3', '1', '3', '3'},
    {'1', '1', '2', '3', '3'},{'3', '3', '2', '1', '1'},
    {'1', '2', '1', '2', '1'},{'3', '2', '3', '2', '3'},{'2', '1', '2', '1', '2'},{'2', '3', '2', '3', '2'},
    {'2', '1', '2', '3', '2'},{'2', '3', '2', '1', '2'}                                                     //Line 15
};
vector<vector<char>> LINES30{ {'2','2','2','2','2'},{'1','1','1','1','1'},{'3','3','3','3','3'}, 
    {'1', '2', '3', '2', '1'},{'3', '2', '1', '2', '3'},
    {'1', '1', '2', '1', '1'},{'3', '3', '2', '3', '3'},
    {'2', '3', '3', '3', '2'},{'2', '1', '1', '1', '2'},{'1', '2', '2', '2', '1'},{'3', '2', '2', '2', '3'},//Line 11
    {'1', '2', '1', '2', '1'},{'3', '2', '3', '2', '3'},{'2', '1', '2', '1', '2'},{'2', '3', '2', '3', '2'},
    {'2', '2', '1', '2', '2'},{'2', '2', '3', '2', '2'},
    {'1', '3', '1', '3', '1'},{'3', '1', '3', '1', '3'},                                                    //Line 19
    {'2', '1', '3', '1', '2'},{'2', '3', '1', '3', '2'},
    {'1', '1', '3', '1', '1'},{'3', '3', '1', '3', '3'},
    {'1', '3', '3', '3', '1'},{'3', '1', '1', '1', '3'},                                                    //Line 25
    {'1', '3', '2', '3', '1'},{'3', '1', '2', '1', '3'},
    {'1', '1', '1', '2', '1'},{'3', '3', '3', '2', '3'}, {'2', '2', '2', '1', '2'}                          //Line 30
};
vector<vector<char>> LINES50{ {'2','2','2','2','2'},{'1','1','1','1','1'},{'3','3','3','3','3'},
    {'1', '2', '3', '2', '1'},{'3', '2', '1', '2', '3'},
    {'1', '1', '2', '1', '1'},{'3', '3', '2', '3', '3'},
    {'2', '3', '3', '3', '2'},{'2', '1', '1', '1', '2'},{'1', '2', '2', '2', '1'},{'3', '2', '2', '2', '3'},//Line 11
    {'1', '2', '1', '2', '1'},{'3', '2', '3', '2', '3'},{'2', '1', '2', '1', '2'},{'2', '3', '2', '3', '2'},
    {'2', '2', '1', '2', '2'},{'2', '2', '3', '2', '2'},
    {'1', '3', '1', '3', '1'},{'3', '1', '3', '1', '3'},                                                    //Line 19
    {'2', '1', '3', '1', '2'},{'2', '3', '1', '3', '2'},
    {'1', '1', '3', '1', '1'},{'3', '3', '1', '3', '3'},
    {'1', '3', '3', '3', '1'},{'3', '1', '1', '1', '3'},                                                    //Line 25
    {'1', '3', '2', '3', '1'},{'3', '1', '2', '1', '3'},
    {'1', '1', '1', '2', '1'},{'3', '3', '3', '2', '3'}, {'2', '2', '2', '1', '2'},                         //Line 30
    {'2', '1', '3', '2', '1'},{'2', '3', '1', '2', '3'},
    {'1', '3', '2', '1', '3'},{'3', '1', '2', '3', '1'},
    {'2', '1', '2', '3', '2'},{'2', '3', '2', '1', '2'},
    {'1', '2', '1', '2', '3'},{'3', '2', '3', '2', '1'},
    {'1', '1', '3', '3', '3'},{'3', '3', '1', '1', '1'},                                                    //Line 40
    {'2', '1', '2', '3', '3'},{'2', '3', '2', '1', '1'},
    {'3', '2', '1', '3', '2'},{'1', '2', '3', '1', '2'},
    {'2', '3', '3', '1', '1'},{'3', '1', '1', '2', '3'},
    {'1', '1', '2', '2', '3'},{'3', '3', '2', '2', '1'},
    {'1', '3', '2', '2', '1'},{'3', '1', '2', '2', '3'}                                                     //Line 50
};
vector<vector<char>> REELS = { {} };


regex rList("[AKQJSs]");
Machine::Machine() {
    money = 0;
    bet = 1;
    max = 0;
    spins = 0;
    total = 0.0;
    LINES = LINES30;
}
Machine::Machine(int dollars) {
    money = dollars;
    bet = 1;
    max = 0;
    spins = 0;
    total = 0.0;
    LINES = LINES30;
}
void Machine::addMoney(int mon) {
    money += mon;
}

vector<vector<char>> Machine::roll() {
    vector<vector<char>> roll;
    money -= getLines() * bet;
    spins++;
    int BC = 0;
    int bonus = 0;
    for (int j = 0; j < 5; j++) {
        vector<char> temp = {};
        BC = 0;
        for (int i = 0; i < 3; i++) {
            temp.push_back(LIST[j][rand() % LIST[j].size()-sin(BC)]);
            if (temp[i] == 'B') {
                BC++;
                bonus++;
            }
        }
        roll.push_back(temp);
    }
    if (PRINT) {
        printRoll(roll);
    }
    calcRoll(roll);
    if (bonus == 3) {
        BONUS++;
    }
    return roll;
}

vector<vector<char>> Machine::bonusRoll(int rollNum, int rolls, int &rng) {
    vector<vector<char>> roll;
    int BC = 0;
    int bonus = 0;
    if (rng == rollNum) {
        rng = rand() % rolls;
        if (PRINT) { cout << "SPECIAL ROLL" << endl; }
        for (int j = 0; j < 5; j++) {
            vector<char> temp = {};
            BC = 0;
            for (int i = 0; i < 3; i++) {
                temp.push_back(BONUSLIST[j][rand() % BONUSLIST[j].size() - sin(BC)]);
                if (temp[i] == 'B') {
                    BC++;
                    bonus++;
                }
            }
            roll.push_back(temp);
        }
    }
    else {
        for (int j = 0; j < 5; j++) {
            vector<char> temp = {};
            BC = 0;
            for (int i = 0; i < 3; i++) {
                temp.push_back(LIST[j][rand() % LIST[j].size() - sin(BC)]);
                if (temp[i] == 'B') {
                    BC++;
                    bonus++;
                }
            }
            roll.push_back(temp);
        }
    }
    if (PRINT) {
        printRoll(roll);
    }
    bonusTotal += calcRoll(roll);
    if (bonus == 3) {
        if (PRINT) { cout << "RETRIGGER" << endl; }
        BONUS++;
    }

    return roll;
}

int Machine::calcRoll(vector<vector<char>> roll) {
    int amount = 0;
    string line;
    string temp;
    int temp2;
    for(int i = 0; i < this->LINES.size(); i++) {
        line.clear();
        for (int j = 0; j < this->LINES[i].size(); j++) {
            line += roll[j][int(this->LINES[i][j]) - 49];
        }
        temp = calcWild(line);
        temp2 = calcVal(temp);
        if (temp2 > 0) {
            if (PRINT) { cout << "Line " << i + 1 << ": " << temp << " Worth " << temp2 << endl; }
            amount += temp2;
        }
    }
    if (amount / (getBet() * getLines()) > 5) {
        if (PRINT) { cout << "MASSIVE WIN" << endl; }
        this->MW++;
    }
    if (PRINT) { cout << "Total Win For This Spin:" << amount << endl; }
    money += amount;
    total += amount;
    if (amount >= max) { max = amount; }
    return amount;
}

string Machine::calcWild(string str) {
    if (str[0] == 'W') {
        int wildCount = 0;
        string temp;
        for (int j = 0; j < str.length(); j++) {
            temp = str[j];
            if (regex_match(temp, rList)) { 
                str[0] = str[j]; 
                j = str.length();
                wildCount += 1;
            }
        }
        if (wildCount == 0) { //Only Wild or Bonus
            str[0] = 'S';
        }
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'W') {
            if (str[i-1] != 'W') {
                str[i] = str[i-1];
            }
        }
    }
    return str;
}

int Machine::calcVal(string str) {
    int mult = VALUES.at('W');
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != 'W') { 
            mult = VALUES.at(str[i]); 
            i = str.length()+1;
        }
    }
    //cout << mult << endl;
            if(str[0] != str[1] && str[0] != 'W' && str[1] != 'W') {
                return 0;
            }
            else if ((str[0] == str[2] || str[2] == 'W') && (str[0] == str[3] || str[3] == 'W') && (str[0] == str[4] || str[4] == 'W')) {
                return getBet() * mult * 5;
            }
            else if ((str[0] == str[2] || str[2] == 'W') && (str[0] == str[3] || str[3] == 'W')) {
                return getBet() * mult * 4;
            }
            else if (str[0] == str[2] || str[2] == 'W') {
                return getBet() * mult * 2;
            }
        return 0;
}
int Machine::getBal() {
    return money;
}
int Machine::getBet() {
    return bet;
}
int Machine::getSpins() {
    return spins;
}
int Machine::getMax() {
    return max;
}
int Machine::getLines() {
    return LINES.size();
}
int Machine::getMW() {
    return MW;
}
int Machine::getBonus() {
    return BONUS;
}
int Machine::getBonusTotal() {
    int temp = bonusTotal;
    bonusTotal = 0;
    return temp;
}
float Machine::getTotal() {
    return total;
}
void Machine::printRoll(vector<vector<char>> roll) {
    if (PRINT) {
        for (int j = 0; j < roll[0].size(); j++) {
            for (int i = 0; i < roll.size(); i++) {
                cout << roll[i][j] << ' ';
            }
            cout << endl;
        }
    }
}
void Machine::setBet(int amount) {
    bet = amount;
}
void Machine::setBonus(int amount) {
    BONUS = amount;
}
void printReel(vector<vector<char>> reels) {
    if (PRINT) {
        for (int i = 0; i < reels.size(); i++) {
            for (int j = 0; j < reels[i].size(); j++) {
                cout << reels[i][j] << ' ';
            }
            cout << endl;
        }
    }
}
void Machine::setLines(int lines) {
    if (lines == 30) { this->LINES = LINES30; }
    else if (lines == 15) { this->LINES = LINES15; }
    else if (lines == 50) { this->LINES = LINES50; }
    else if (lines == 243) { this->LINES = REELS; }
    else {}
    if (PRINTLINES) { printReel(this->LINES); }
}
void ignoreLine() {
    cin.ignore(numeric_limits <std::streamsize>::max(), '\n');
}


vector<vector<char>> convReel(vector<vector<int>> reels) {
    vector<vector<char>> REELS;
    vector<char> REEL;
    for (int i = 0; i < reels.size(); i++) {
        for (int j = 0; j < reels[i].size(); j++) {
            REEL.push_back(to_string(reels[i][j])[0]);
        }
        REELS.push_back(REEL);
        REEL.clear();
    }
    return REELS;
}

void Machine::createReel() {
    vector<vector<int>> reels;
    vector<vector<char>> reel;
    int count = 0;
    int i = 1, j = 1, k = 1, l = 1, m = 1;
    while (i < 4) {
        while (j < 4) {
            while (k < 4) {
                while (l < 4) {
                    while (m < 4) {
                        reels.push_back({ i, j, k, l, m });
                        m++;
                    }
                    l++;
                    m = 1;
                }
                k++;
                l = 1;
            }
            j++;
            k = 1;
        }
        i++;
        j = 1;
    }
    reel = convReel(reels);
    //printReel(reel);
    REELS = reel;
}


/*vector<vector<char>> createReel() {
    vector<vector<int>> reels;
    vector<vector<char>> reel;
    int count = 0;
    int i = 0, j = 0, k = 0, l = 0, m = 0;
    while (i < 3) {
        while (j < 3) {
            while (k < 3) {
                while (l < 3) {
                    while (m < 3) {
                        reels.push_back({ i, j, k, l, m });
                        m++;
                    }
                    l++;
                    m = 0;
                }
                k++;
                l = 0;
            }
            j++;
            k = 0;
        }
        i++;
        j = 0;
    }
    reel = convReel(reels);
    return reel;
}*/

int main()
{  
    srand(time(NULL));
    if (DEBUG) {//Set to debug mode
    for (int i = 1; i < 10; i++) {
        int tSpins = 1000;
        int tBet = i;
        int tLines = 243;
        Machine M1(tBet * tLines * tSpins);
        M1.createReel();
        M1.setBet(tBet);
        M1.setLines(tLines);
        vector<vector<char>> temp;
        char input;
        string inp;
        string invalid;
        int mon;
        int bet;
        int rolls = 0;
        int rng = 0;
        regex regexp("[Nn]");
        regex regex1("[NnYyBbAaLl]");
        regex regexn("[1-9]");
        regex regexlin("15|30|50");
        if (PRINT) { cout << "Press B To Change Bet" << endl << "Press L To Change Lines" << endl << "Press N To Quit" << endl << endl; }
        // /*
            for (int i = 0; i < tSpins; i++) {
                M1.roll();
                while (M1.getBonus() >= 1) {
                    M1.setBonus(M1.getBonus() - 1);

                    //cout << "BONUS SPINS" << endl;
                    if (M1.getBet() > 7) { rolls = 12; }
                    else if (M1.getBet() > 4) { rolls = 10; }
                    else { rolls = 8; }
                    rng = rand() % rolls;
                    for (int i = 0; i < rolls; i++) {
                        //cout << "Press Y For Free Spin" << endl;
                        //cin >> inp;
                        //cout << "FREE SPIN: " << i + 1 << endl;
                        M1.bonusRoll(i, rolls, rng);
                    }
                }
                if (PRINT) { cout << "Bonus Total: " << M1.getBonusTotal(); }
            }

            int cost = (M1.getSpins() * M1.getBet() * M1.getLines());
            //cout << "Total Spins: " << M1.getSpins() << endl;
            cout << "Current Bet: " << i << endl;
            cout << "Total Cost " << cost << endl;
            cout << "Current Bal: " << M1.getBal() << endl;
            cout << "Loss: " << M1.getBal() - cost << " or " << (float(M1.getBal()) / float(cost)) * 100 << "% return" << endl;
            //cout << "Bonus?: " << M1.getBonus() << endl;
            cout << "Biggest Hit: " << M1.getMax() << endl;
            cout << endl;
        }
    }else{//Standard Mode
      //  createReel();
        int tSpins = 100;
        int tBet = 9;
        int tLines = 50;
        Machine M1(tBet * tLines * tSpins);
        M1.createReel();
        M1.setBet(tBet);
        M1.setLines(tLines);
        vector<vector<char>> temp;
        char input;
        string inp;
        string invalid;
        int mon;
        int bet;
        int rolls = 0;
        int rng = 0;
        regex regexp("[Nn]");
        regex regex1("[NnYyBbAaLl]");
        regex regexn("[1-9]");
        regex regexlin("15|30|50|[Rr]");
        if (PRINT) { cout << "Press B To Change Bet" << endl << "Press L To Change Lines" << endl << "Press N To Quit" << endl << endl; }
        while (true) {
            if (M1.getBet() * M1.getLines() > M1.getBal()) {
                cout << "Bet Amount Exceeds Balance" << endl << "Please Enter New Bet Amount Or Press N To Quit" << endl;
                cin >> inp;
                if (regex_match(inp, regexp)) { return 0; }
                else if (regex_match(inp, regexn)) {
                    bet = stoi(inp);
                    M1.setBet(bet);
                }
                else {
                    char c = inp.c_str()[0];
                    if (c == 'a' || c == 'A') {
                        cout << endl;
                    }
                    cout << "Non-valid input" << endl;
                }
            }
            else {
                cout << "Current Balance: " << M1.getBal() << '\n' << "Current Bet: " << M1.getBet() << " X " << M1.getLines() << " lines" << endl << "Total Spins : " << M1.getSpins() << " Max Win: " << M1.getMax() << endl
                    << "Press Y To Spin" << endl;
                cin >> input;
                switch (input) {
                case 'y':
                case 'Y':
                    cout << endl;
                    temp = M1.roll();
                    while (M1.getBonus() >= 1) {
                        M1.setBonus(M1.getBonus()-1);
                        cout << "BONUS SPINS" << endl;
                        if (M1.getBet() == 9) { rolls = 15; }
                        else if (M1.getBet() > 4) { rolls = 12; }
                        else { rolls = 8; }
                        rng = rand() % rolls;
                        for (int i = 0; i < rolls; i++) {
                            cout << "Press Y For Free Spin" << endl;
                            cin >> inp;
                            cout << "FREE SPIN: " << i + 1 << endl;
                            M1.bonusRoll(i, rolls, rng);
                        }if (PRINT) { cout << "Bonus Total: " << M1.getBonusTotal() << endl; }
                    }
                    cout << endl;
                    break;
                case 'n':
                case 'N':
                    return 0;
                    break;
                case 'a':
                case 'A':
                    cout << "Add Funds" << endl;
                    while (true) {
                        cin >> mon;
                        if (!cin) {
                            cin.clear();
                            ignoreLine();
                            cout << "Enter a Valid Number: ";
                        }
                        else {
                            M1.addMoney(mon);
                            break;
                        }
                    }
                    break;
                case 'b':
                case 'B':
                    cout << "Enter New Bet(1-9): ";
                    while (true) {
                        cin >> bet;
                        if (!cin) {
                            cin.clear();
                            ignoreLine();
                            cout << "Enter a Valid Number: ";
                        }
                        else if (bet > 9 || bet < 0) {
                            cout << "Out Of Range Max Bet is 9X" << endl << "Bet 1-9" << endl;
                            cin.clear();
                            continue;
                        }
                        else {
                            M1.setBet(bet);
                            break;
                        }
                    }
                    break;
                case 'l':
                case 'L':
                    string line;
                    cout << "Enter Lines, 15, 30, 50, R: ";
                    while (cin >> line) {
                        if (regex_match(line, regexlin)) {
                            if (line == "R" || line == "r") {
                                M1.setLines(243);
                            }
                            else {
                                M1.setLines(stoi(line));
                            }
                            break;
                        }
                        cout << "Enter a valid number: ";
                    }
                    break;
                }
                cout << endl;
            }
        }
    }
  
    return 0;
}