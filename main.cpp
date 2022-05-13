#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

bool guessVerify(string guessedWord);

bool guessCheck(string guessedWord, string actualWord);

int main() {
  ifstream in;
  in.open("possible.txt");
  if(in.fail()){
    cout << "File didn't open"<<endl;
  }

  vector<string>  words;
  for (int i = 0; i < 12478; i++){
    string w;
    getline(in, w);
    words.push_back(w);
    if (in.fail()) break;
  }
  
  srand(time(0));
  int randomNumber = rand() % 12478;

  string guess = "";
  int count = 0;
  while(guess!=words[randomNumber] && count != 6){
    bool isRealWord = false;
    cout<<endl<<"Guess a 5-letter Word!"<<endl;
    cin>>guess;
    for(int c = 0; c<12478; c++){
      if(guess==words[c]){
        isRealWord = true;
      }
    }
    while(guessVerify(guess)==false || isRealWord==false){
      cout<<"Guess a 5-letter Word!"<<endl;
      cin>>guess;
      guessVerify(guess);
      for(int c = 0; c<12478; c++){
      if(guess==words[c]){
        isRealWord = true;
      }
    }
    }
    guessCheck(guess, words[randomNumber]);
    count++;
  }
  if(count==6 && guess!=words[randomNumber]){
    cout<<"You lose! The word was "<<words[randomNumber];
  }else if(guessCheck(guess,words[randomNumber])==true){
    cout<<endl<<"Yay! You got it! The word was "<<words[randomNumber]<<"!"<<endl;
  }
}

bool guessVerify(string guessedWord){
  if(guessedWord.length()!=5){
    return false;
  }else{
    return true;
  }
}

bool guessCheck(string guessedWord, string actualWord){
  string hold = "-----";
  for(int k = 0; k<5; k++){
    for(int p = 0; p<5; p++){
      if(guessedWord[k]==actualWord[p]&&k!=p){
        hold[k]=actualWord[p];
      }
    }
    if(guessedWord[k]==actualWord[k]){
      hold[k]=toupper(actualWord[k]);
    }
  }
  cout<<hold<<endl;
  if(guessedWord==actualWord){
    return true;
  }else{
    return false;
  }
}