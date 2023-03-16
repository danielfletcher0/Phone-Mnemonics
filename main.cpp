#include <cstring>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
using namespace std;
bool ValidPhoneNumber(string number);
bool isMatching(string userNumber,string wordCombo);
void findMatching(string userNumber, vector<string> &words3, vector<string> &words4, vector<string> &words7, ofstream &output);
int main() {
  ifstream inFS("ShortList.txt");
  ofstream outFS("output.txt") ;
  string word;
  string phoneNumber;
  bool isValid; 
  int len;
  vector<string> word2;
  vector<string> word3;
  vector<string> word4;
  vector<string> word5;
  vector<string> word6;
  vector<string> word7;

  // Testing the input and output files.
  if (!inFS.is_open()) {
    cout << "Error opening the file" << endl;
    return 1;
  }
  if (!outFS.is_open()) {
    cout << "Error writing to the file.";
    return 1;
  }
  // Prints out a message, if any of the files were unable to open.
  while (inFS >> word) {
      len = word.length();
      if (len == 2) {
        word2.push_back(word);
      }
      else if (len == 3) {
        word3.push_back(word);
      }
      else if (len == 4) {
        word4.push_back(word);
      }
      else if (len == 5) {
        word5.push_back(word);
      }
      else if (len == 6) {
        word6.push_back(word);
      }
      else if (len == 7) {
        word7.push_back(word);
      }
    
  }
  getline(cin, phoneNumber);
  isValid = ValidPhoneNumber(phoneNumber);
  if (isValid == false) {
    cout << "Invalid phone number" << endl;
    exit(1);
  }
  findMatching(phoneNumber, word3, word4, word7, outFS);
  
  return 0;
}
bool ValidPhoneNumber(string number) {
    int len = number.length();
    if (len != 8) return false;
  
    for (int i = 0; i < len; i++) {
      if (i == 3 && number[i] == '-') {
        continue;
      }
      else if (number[i] >= '2' && number[i] <= '9' ) {
        continue;
      }
      else {
        return false;
      }
    }
    return true;
}
bool isMatch(string numbers, string word) {
  bool temp = true;
    for (unsigned int i=0; i < word.length(); i++) {
      switch (word[i]) {
        case 'A' : case 'B' : case 'C' : case 'a' : case 'b' : case 'c':
          if (numbers[i] != '2')
            temp = false;
          break;
        case 'D' : case 'E' : case 'F' : case 'd' : case 'e' : case 'f':
          if (numbers[i] != '3')
            temp = false;
          break;
        case 'G' : case 'H' : case 'I' : case 'g' : case 'h' : case 'i':
          if (numbers[i] != '4')
            temp = false;
          break;
        case 'J' : case 'K' : case 'L' : case 'j' : case 'k' : case 'l':
          if (numbers[i] != '5')
            temp = false;
          break;
        case 'M' : case 'N' : case 'O' : case 'm' : case 'n' : case 'o':
          if (numbers[i] != '6')
            temp = false;
          break;
        case 'P' : case 'Q' : case 'R' : case 'S': case 'p' : case 'q' : case 'r': case 's':
          if (numbers[i] != '7')
            temp = false;
          break;
        case 'T' : case 'U' : case 'V' : case 't' : case 'u' : case 'v':
          if (numbers[i] != '8')
            temp = false;
          break;
        case 'W' : case 'X' : case 'Y' : case 'Z': case 'w' : case 'x' : case 'y': case 'z' :
          if (numbers[i] != '9')
            temp = false;
          break;
        }
    }
    return temp;
}

void  findMatching(string userNumber, vector<string> &words3, vector<string> &words4, vector<string> &words7, ofstream &output) {
    vector<string> word3matched;
    vector<string> word4matched;
    vector<string> word7matched;
    string number3 = userNumber.substr(0, 3);
    string number4 = userNumber.substr(4);
    string number7 = number3 + number4;
  
    for (unsigned int i = 0; i < words3.size(); i++) {
        if (isMatch(number3, words3[i])) {
          word3matched.push_back(words3[i]);
        }
    }
  
    for (unsigned int i = 0; i < words4.size(); i++) {
        if (isMatch(number4, words4[i])) {
          word4matched.push_back(words4[i]);
        }
    }
    for (unsigned int i = 0; i < words7.size(); i++) {
        if (isMatch(number7, words7[i])) {
          word7matched.push_back(words7[i]);
        }
    }
  
    for (unsigned int i = 0; i < word3matched.size(); i++) {
        for (unsigned int j = 0; j < word4matched.size(); j++) {
          output << word3matched[i] + " " + word4matched[j] << endl;
        }
    }
    for (unsigned int i = 0; i < word7matched.size(); i++) {
      output << word7matched[i] << endl;
    }
    if (word3matched.size() == 0 && word4matched.size() == 0 && word7matched.size() == 0) {
      output << "No results!" << endl;
    }
}