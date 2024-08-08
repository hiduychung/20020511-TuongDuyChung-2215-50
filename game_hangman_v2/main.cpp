#include <bits/stdc++.h>
using namespace std;

vector<string> Word_list;

void readWordsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        exit(1);
    }
    string word;
    while (file >> word) {
        Word_list.push_back(word);
    }
    file.close();
}

int Word_count;

const string FIGURE[] = {
    "  -------- \n"
    "  |      | \n"
    "  |       \n"
    "  |       \n"
    "  |       \n"
    "  |       \n"
    "  |       \n"
    "------    \n",

    "  -------- \n"
    "  |      | \n"
    "  |      O \n"
    "  |       \n"
    "  |       \n"
    "  |       \n"
    "  |       \n"
    "------    \n",

    "  -------- \n"
    "  |      | \n"
    "  |      O \n"
    "  |      | \n"
    "  |       \n"
    "  |       \n"
    "  |       \n"
    "------    \n",

    "  -------- \n"
    "  |      | \n"
    "  |      O \n"
    "  |     /| \n"
    "  |       \n"
    "  |       \n"
    "  |       \n"
    "------    \n",

    "  -------- \n"
    "  |      | \n"
    "  |      O \n"
    "  |     /|\\\n"
    "  |       \n"
    "  |       \n"
    "  |       \n"
    "------    \n",

    "  -------- \n"
    "  |      | \n"
    "  |      O \n"
    "  |     /|\\\n"
    "  |     /  \n"
    "  |       \n"
    "  |       \n"
    "------    \n",

    "  -------- \n"
    "  |      | \n"
    "  |      O \n"
    "  |     /|\\\n"
    "  |     / \\\n"
    "  |       \n"
    "  |       \n"
    "------    \n"
};

void renderGame(string guessWord, int badGuessCount, const set<char>& guessedLetters) {
    cout << guessWord << endl;
    if (badGuessCount > 0 && badGuessCount <= 7) {
        cout << FIGURE[badGuessCount - 1] << endl;
    }
    cout << "Guessed letters: ";
    for (char letter : guessedLetters) {
        cout << letter << " ";
    }
    cout << endl;
}

char readAGuess() {
    cout << "Enter your guess (or ? for a hint): ";
    char ch;
    cin >> ch;
    return ch;
}

string update(string guessWord, char guess, string secretWord) {
    for (int i = 0; i < guessWord.length(); i++) {
        if (guess == secretWord[i]) guessWord[i] = guess;
    }
    return guessWord;
}

bool contains(string word, char ch) {
    return (word.find_first_of(ch) != string::npos);
}

void displayResult(bool lost) {
    if (lost) {
        cout << FIGURE[6] << "\n" << "You lost!" << endl;
    } else {
        cout << "You won!" << endl;
    }
}

string chooseWord() {
    srand(time(0));
    int randomIndex = rand() % Word_count;
    return Word_list[randomIndex];
}

char recommend(const string& secretWord, const string& guessWord) {
    for (int i = 0; i < secretWord.length(); i++) {
        if (guessWord[i] == '-') {
            return secretWord[i];
        }
    }
    return '\0'; // Trả về '\0' nếu không có ký tự nào để gợi ý
}

void newGame() {
    string secretWord = chooseWord();
    string guessWord = string(secretWord.length(), '-');
    int badGuessCount = 0;
    set<char> guessedLetters;
    bool hintUsed = false;

    do {
        renderGame(guessWord, badGuessCount, guessedLetters);
        char guess = readAGuess();
        if (guess == '?') {
            if (!hintUsed) {
                char hint = recommend(secretWord, guessWord);
                if (hint != '\0') {
                    cout << "Hint: The word contains the letter '" << hint << "'" << endl;
                    guessedLetters.insert(hint);
                    guessWord = update(guessWord, hint, secretWord);
                    hintUsed = true;
                } else {
                    cout << "No hints available!" << endl;
                }
            } else {
                cout << "You have already used your hint!" << endl;
            }
        } else {
            guessedLetters.insert(guess);
            if (contains(secretWord, guess)) {
                guessWord = update(guessWord, guess, secretWord);
            } else {
                badGuessCount++;
            }
        }
    } while (badGuessCount < 7 && guessWord != secretWord);

    if (guessWord == secretWord) {
        displayResult(false);
    } else {
        displayResult(true);
    }
}

void instructions() {
    cout << "Welcome to Hangman Game!" << endl;
    cout << "The goal is to guess the word letter by letter." << endl;
    cout << "You can guess one letter at a time." << endl;
    cout << "If you guess wrong 7 times, you lose." << endl;
    cout << "You can use '?' once per game to get a hint." << endl;
    cout << "Good luck and have fun!" << endl;
}

void viewStatistics(int totalRounds, int totalWins, int totalLosses) {
    cout << "Total Rounds: " << totalRounds << endl;
    cout << "Total Wins: " << totalWins << endl;
    cout << "Total Losses: " << totalLosses << endl;
}

int main() {
    readWordsFromFile("words.txt");
    Word_count = Word_list.size(); // Khởi tạo Word_count sau khi đọc từ file

    if (Word_count == 0) {
        cerr << "No words loaded from file!" << endl;
        return 1;
    }

    int totalRounds = 0;
    int totalWins = 0;
    int totalLosses = 0;

    char choice;
    do {
        cout << "Hangman Game Menu:" << endl;
        cout << "1. New Game" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. View Statistics" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                newGame();
                totalRounds++;
                // Cập nhật thống kê thắng thua sau khi chơi
                cout << "Did you win the game? (y/n): ";
                char result;
                cin >> result;
                if (result == 'y' || result == 'Y') {
                    totalWins++;
                } else {
                    totalLosses++;
                }
                break;
            case '2':
                instructions();
                break;
            case '3':
                viewStatistics(totalRounds, totalWins, totalLosses);
                break;
            case '4':
                cout << "Thank you for playing!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}
