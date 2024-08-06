#include <bits/stdc++.h>

using namespace std;

const string Word_list[] = {"cats","human","dog","Apple", "Bread", "Chair",
                            "Dance", "Eagle", "Fruit", "Ghost", "House", "Igloo",
                            "Joker", "Knife", "Lemon", "Magic", "Night", "Ocean",
                            "Pizza", "Queen", "Radio", "Snake", "Tiger", "Uncle",
                            "Voice", "Whale", "Zebra", "Angel", "Brave", "Crown",
                            "Dream",
};
const int Word_count = sizeof(Word_list) / sizeof(string);
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
    if(lost) cout<<FIGURE[7]<<"\n " <<"You lost!";
    else cout<<"You won!";
};



int main()
{
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

displayResult(badGuesseCount == 7);

    return 0;
};
