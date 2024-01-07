#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int GRID_SIZE = 1000;
int lights[GRID_SIZE][GRID_SIZE] = {0};

void toggle(int x1, int y1, int x2, int y2) {
    for (int x = x1; x <= x2; ++x) {
        for (int y = y1; y <= y2; ++y) {
            lights[x][y]+=2;
        }
    }
}

void switch_light(int x1, int y1, int x2, int y2, int action) {
    for (int x = x1; x <= x2; ++x) {
        for (int y = y1; y <= y2; ++y) {
          if(lights[x][y] == 0 && action == -1){
            continue;
          }
          lights[x][y] += action;
        }
    }
}

void lights_house(const string& line) {
    stringstream ss(line);
    string command, temp;
    int x1, y1, x2, y2;

    if (line.substr(0, 7) == "turn on") {
        command = "turn on";
        ss.ignore(8);
    } else if (line.substr(0, 8) == "turn off") {
        command = "turn off";
        ss.ignore(9);
    } else {
        command = "toggle";
        ss.ignore(7);
    }

    char comma;
    ss >> x1 >> comma >> y1 >> temp >> x2 >> comma >> y2;

    if (command == "turn on") {
        switch_light(x1, y1, x2, y2, +1);
    } else if (command == "turn off") {
        switch_light(x1, y1, x2, y2, -1);
    } else {
        toggle(x1, y1, x2, y2);
    }
}


int main() {
    ifstream file("input.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            lights_house(line);
        }
        file.close();
    } else {
        cout << "Unable to open file";
        return 1;
    }

    int count = 0;
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            count += lights[i][j];
        }
    }

    cout << "Result: " << count << endl;
    return 0;
}
