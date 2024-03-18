#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateProgression(int progression[], int length, int commonRatio) {
    progression[0] = generateRandomNumber(1, 10); 
    for (int i = 1; i < length; ++i) {
        progression[i] = progression[i - 1] * commonRatio; 
    }
}

int hideRandomNumber(int progression[], int length) {
    int index = generateRandomNumber(0, length - 1); 
    int hiddenNumber = progression[index]; 
    progression[index] = -1; 
    return hiddenNumber;
}

void printProgression(int progression[], int length) {
    for (int i = 0; i < length; ++i) {
        if (progression[i] == -1) {
            cout << ".. "; 
        } else {
            cout << progression[i] << " ";
        }
    }
    cout << endl;
}

int nod(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int nok(int a, int b) {
    return (a * b) / nod(a, b);
}

int generateNumber() {
    return rand() % 100 + 1; 
}

int nok_3(int a, int b, int c) {
    int nok_ab = nok(a, b);
    return nok(nok_ab, c);
}

int main() {
    int correctAnswers = 0;
    int rounds = 0;
    int choice;
    cout << "Welcome to the Brain Games!" << endl;
    cout << "May I have your name? ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    cout << "Please choose a game you want to play!" << endl;
    cout << "If you want to play 'Progression' type 1, if you want to play 'LCM' type 2." << endl;
    cin >> choice;
    if (choice == 1) {
        cout << "Great choice!" << endl;
        cout << "What number is missing in the progression?" << endl;
        while (correctAnswers < 3 && rounds < 3) {
            srand(time(0));
            int progressionLength = generateRandomNumber(5, 10); 
            int progression[10]; 
            int commonRatio = generateRandomNumber(2, 5); 
            generateProgression(progression, progressionLength, commonRatio); 
            int hiddenNumber = hideRandomNumber(progression, progressionLength); 

            cout << "Question: ";
            printProgression(progression, progressionLength);

            cout << "Your answer: ";
            int userAnswer;
            cin >> userAnswer;

            if (userAnswer == hiddenNumber) {
                cout << "Correct!" << endl;
                correctAnswers++;
            } else {
                cout << "'" << userAnswer << "' is wrong answer ;(. Correct answer was '" << hiddenNumber << "'." << endl;
                if (rounds != 2) {
                    cout << "Let's try again, " << name << "!" << endl;
                }
                rounds++;
            }
        }
    } else if (choice == 2) {
        cout << "Great choice!" << endl;
        cout << "Find the smallest common multiple of given numbers." << endl;
        while (correctAnswers < 3 && rounds < 3) {
            int a = generateNumber();
            int b = generateNumber();
            int c = generateNumber();
            int NokResult = nok_3(a, b, c);
            cout << "Question: " << a << " " << b << " " << c << endl;
            cout << "Your answer: ";
            int userAnswer;
            cin >> userAnswer;

            if (userAnswer == NokResult) {
                cout << "Correct!" << endl;
                correctAnswers++;
            } else {
                cout << "'" << userAnswer << "' is wrong answer ;(. Correct answer was '" << NokResult << "'." << endl;
                cout << "Let's try again, " << name << "!" << endl;
                correctAnswers = 0;
                rounds++;
            }
        }
    } else {
        cout << "You entered an invalid number, please choose either 1 or 2." << endl;
    }
    if(rounds == 3){
        if (correctAnswers == 3) {
            cout << "Congratulations, you answered all three questions correctly, " << name << "!" << endl;
        } else {
            cout << "Sorry, " << name << ". You didn't answer correctly all three questions correctly." << endl;
        }
    }
    
    return 0;
}
