#include <iostream>

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

int main() {
    int correctAnswers = 0;
    int rounds = 0;
    string name;
    
    cout << "Welcome to the Brain Games!" << endl;
        cout << "May I have your name? ";
        cin >> name;
        cout << "Hello, " << name << "!" << endl;
        cout << "What number is missing in the progression?" << endl;
        
    while(correctAnswers < 3 && rounds < 3) {
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
            if(rounds != 2){
                cout << "Let's try again, " << name << "!" << endl;
            }
            rounds++;
        }
        
    }
    if(correctAnswers == 3){
        cout << "Congratulations, " << name << " , you answered all questoins correctly!" << endl;
    }else {
        cout << "The game has ended. You did not answer all questions correctly, " << name << "." << endl;
    }
    
    
    


    return 0;
}
