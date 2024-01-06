#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void performBattle(priority_queue<int>& greenArmy, priority_queue<int>& blueArmy, vector<int>& greenSurvivors, vector<int>& blueSurvivors, int B) {
    for (int i = 0; i < B; i++) {
        if (greenArmy.empty() || blueArmy.empty()) {
            break;
        }

        int greenLemming = greenArmy.top();
        greenArmy.pop();

        int blueLemming = blueArmy.top();
        blueArmy.pop();

        if (greenLemming > blueLemming) {
            greenSurvivors.push_back(greenLemming - blueLemming);
        } else if (greenLemming < blueLemming) {
            blueSurvivors.push_back(blueLemming - greenLemming);
        }
    }
}


void simulateBattle(int B, int SG, int SB, priority_queue<int>& greenArmy, priority_queue<int>& blueArmy) {
    while (!greenArmy.empty() && !blueArmy.empty()) {
        vector<int> greenSurvivors;
        vector<int> blueSurvivors;

        performBattle(greenArmy, blueArmy, greenSurvivors, blueSurvivors, B);

        for (int power : greenSurvivors) {
            greenArmy.push(power);
        }

        for (int power : blueSurvivors) {
            blueArmy.push(power);
        }
    }
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int B, SG, SB;
        cin >> B >> SG >> SB;

        priority_queue<int> greenArmy;
        priority_queue<int> blueArmy;


        for (int i = 0; i < SG; i++) {
            int power;
            cin >> power;
            greenArmy.push(power);
        }

        for (int i = 0; i < SB; i++) {
            int power;
            cin >> power;
            blueArmy.push(power);
        }

        simulateBattle(B, SG, SB, greenArmy, blueArmy);

        if (greenArmy.empty() && blueArmy.empty()) {
            cout << "green and blue died" << endl;
        } else if (greenArmy.empty()) {
            cout << "blue wins" << endl;
            while (!blueArmy.empty()) {
                cout << blueArmy.top() << endl;
                blueArmy.pop();
            }
        } else {
            cout << "green wins" << endl;
            while (!greenArmy.empty()) {
                cout << greenArmy.top() << endl;
                greenArmy.pop();
            }
        }

        if (N > 0) {
            cout << endl;
        }
    }

    return 0;
}