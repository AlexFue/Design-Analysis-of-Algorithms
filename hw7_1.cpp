Problem: 
Write a program which displays the biggest number in an array with n integer numbers using a divide-and-conquer technique. 

Ex: Input: 8
		   1 3 11 7 5 6 4 9 

	Output:11

Explanation: The first number indicates the number of input data and the next line are those numbers. The output is 11 because that is the max from the numbers inputted



Solution: 
#include <iostream>
using namespace std;
#include <vector>

// turns the string of numbers into a vector of those numbers
vector<int> getInput(string line){
  vector<int>v;
  string word = "";

  // loop through string, puts numbers into vector after each space
  for(auto c : line){
    if(c==' '){
      v.push_back(stoi(word));
      word = "";
    }
    else{
      word+=c;
    }
  }
  v.push_back(stoi(word));
  return v;
}

// function uses divide n conquer to find max
int div_n_conq(vector<int> v, int start, int end){
  // base case when 1 number is left, returns it
  if (start == end) 
  {
      return v[start];
  }

  // divides vector into 2 halves recursively and then compares 2 numbers to find max
  else 
  {
      int num1 = div_n_conq (v, start, (start+end)/2);
      int num2 = div_n_conq (v, (start+end)/2+1, end);
      if(num1 > num2){return num1;}
      else{return num2;}
  }
}

int main() {
  int nums;
  string input;

  cin >> nums; // get number of nums inputted
  cin.ignore();
  getline(cin, input); // get line of numbers
  vector<int> v = getInput(input); // send line of numbers to function
  int max = div_n_conq(v, 0, v.size()-1); // recieve the max number of the line of numbers
  cout << max << endl; // print it out
}