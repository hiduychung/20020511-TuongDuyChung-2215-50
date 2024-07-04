#include <bits/stdc++.h>
using namespace std;

const string one[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                 "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

const string ten[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

const string giaTri[] = {"", "thousand", "million"};

string convertToString1(string s) {
  int len = s.length();
  string res = "";
  int n;
  if (len == 3 && s[0] != '0') {
    res = res + one[stoi(s) / 100] +" hundred ";
    n = stoi(s) % 100;
    s = to_string(n);
  } else {
    n = stoi(s);
  }
  string res2 = "";
  if (n > 19) {
      res2 += ten[n / 10] + "-" + one[n % 10];
  } else {
      res2 += one[n];
  }
  res = res + res2;
  return res;
}

int main()
{
    string s; cin >> s;

    string answer = "";

    if (s[0] == '-') {
      answer += "negative ";
      s.erase(0, 1);
    }

    vector<string> number;

    string temp = "";

    for (int i = s.length() - 1; i >= 0; --i) {
      temp += s[i];
      if (temp.length() == 3) {
        reverse(begin(temp), end(temp));
        number.push_back(temp);
        temp = "";
      }
    }

    if (!temp.empty()) {
      reverse(begin(temp), end(temp));
      number.push_back(temp);
    }

    int size_vector = number.size();
    for (int i = size_vector - 1; i >= 0; --i) {
      answer = answer + convertToString1(number[i]);
      if (number[i][0] != '0') {
        answer += " " + giaTri[i] + " ";
      }
    }

    cout << answer;

    return 0;
}
