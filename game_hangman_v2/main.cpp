#include <bits/stdc++.h>

using namespace std;

vector <string> Word_list;
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
 int Word_count = 1;
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


void renderGame (string guessWord , int badGuessCount) {
    cout<<guessWord<<endl;
    cout<<FIGURE[badGuessCount-1]<<endl;
};

char readAGuess(){
// đọc từ nhập vào
 cout<<"Enter your guess: ";
 char ch;
 cin>>ch;
 return ch;
};

string update (string guesseWord , char guess, string secretWord){
// cập nhật lại từ đang đoán sau khi nhập 1 lần
for(int i=0; i< guesseWord.length(); i++){
    if(guess == secretWord[i]) guesseWord[i] = guess;
}
return guesseWord;
};
string chooseWord() {
    // chọn từ để đoán
     srand(time(0));
    int randomIndex = rand() % Word_count;
    return Word_list[randomIndex];
};

bool containt(string word , char ch){
// kiểm tra word có chứa ch ko
return (word.find_first_of(ch) != string::npos);
};

void displayResult(bool lost){
    if(lost) cout<<FIGURE[7]<<"\n " <<"You lost!"<<endl;
    else cout<<"You won!"<<endl;
};



int main()
{
    readWordsFromFile("words.txt");
    Word_count = Word_list.size();

    int totalRounds = 0;
    int totalWins = 0;
    int totalLosses = 0;
    char playAgain = 'y';

while(playAgain == 'y' || playAgain == 'Y'){

    string secretWord = chooseWord();
    string guesseWord = string(secretWord.length(),'-');
    int badGuesseCount = 0;

    do{
        renderGame(guesseWord, badGuesseCount);
        char guess = readAGuess();
        if(containt(secretWord , guess)){
           guesseWord = update (guesseWord, guess, secretWord);

        } else badGuesseCount++;

    } while(badGuesseCount < 7 && guesseWord != secretWord);

        if (guesseWord == secretWord) {
            totalWins++;
            displayResult(false);
        } else {
            totalLosses++;
            displayResult(true);
        }
        totalRounds++;
        cout << "Total Rounds: " << totalRounds << endl;
        cout << "Total Wins: " << totalWins << endl;
        cout << "Total Losses: " << totalLosses << endl;

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

}



    return 0;
};
