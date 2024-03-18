#include <iostream>

using namespace std;

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
    cout << "Welcome to the Brain Games!" << endl;
    cout << "May I have your name? ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    cout << "Find the smallest common multiple of given numbers." << endl;

    int correctAnswers = 0;
    int rounds = 0;
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

    if (correctAnswers == 3) {
        cout << "Congratulations, you answered all three questions correctly, " << name << "!" << endl;
    } else {
        cout << "Sorry, " << name << ". You didn't answer correctly in 3 rounds." << endl;
    }

    return 0;
}
