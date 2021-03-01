Problem: 
Write a program that reads input numbers from a user and displays the number that occurs most frequently among all the input numbers.

Ex: 
	Input: 5
		   7
		  -7
		   20
		   7
		   15

	Output: 
		Number:7
		Frequency:2

Explanation: 
	The first number (= 5 in the example) indicates that there will be five integer 
	numbers in the input. Then, all numbers from the second line (= 7 in the example) to the last 
	ine (15 in the example) are actual numbers. Thus, your program should read them and display 
	the most frequent number among 7, -7, 20, 7, and 15. Because the number 7 appears twice in the 
	put, your answer should be 7. If you have more than one number that occurs most often, you 
	have to display the largest number.


Ex 2: 
	Input: 
		10
		-1
		20
		-15
		5
		72
		20
		5
		20
		5
		30

	Output: 
	Number:20
	Frequency:3

	This is the correct output of your program. Note that the frequencies of 5 and 20 are 3. 
	But since 20 is bigger than 5, the correct number should be 20


Solution: 
#include <iostream>
using namespace std;
#include <map>
#include <utility>

int main() 
{
  map<int, int> m; // map to hold digits and frequencies
  pair<int, int> p; // pair to hold biggest digit and frequency
  int nums;
  int user;
  cin >> nums;
  
  if(nums < 1) {return 0;} // corner case 

  for(int i = 0; i < nums; i++) //loop through x numbers given
  {
    cin >> user;
    m[user]++; // add them to map if not there and increment the value for each occurence
  }

  for(auto num : m) //loop through map to find biggest/most frequent number
  {
    if(num.second >= p.second) //check if the current key/value pair if bigger than our max key/value pair
    {
      p.first = num.first;
      p.second = num.second;
    }
  }

  // return it
  cout << "Number:" << p.first << endl;
  cout << "Frequency:" << p.second << endl;
}