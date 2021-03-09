Problem:
Write a program that reads two groups of numbers in which each group has several integer numbers without duplicates. 
Your program should display the non-common numbers in both groups in the descending order. 
***************************************************************************************************************************************

Ex1: 
	Input: 5
		   7
		   20
		   8
		   -7
		   15
		   3
		   8
		   14
		   7

	Output: 
		Answer:20 15 14 -7

	Explanation: 
		The first number (= 5 in the example) indicates that there are five numbers in the first group. 
		Then, the numbers from the second line (= 7 in the example) to the sixth line (15 in the example) are actual numbers of the first group. 
		The following number (= 3 in the example) indicates that there are three numbers in the second group which are 8, 14, and 7.

		For the input, your program should present the non-common numbers in both groups in the descending order. 
		Note that both 7 and 8 are common numbers in the two groups. 
		Thus, you have to display the non-common numbers (= 20, 15, 14, -7) in the descending order on the screen. 
		If there’s non-common number, your program should display NONE.
***************************************************************************************************************************************

Ex2: 	
	Input: 3
		   5
		   -5
		   0
		   3
		   -5
		   0 
		   5

	Output: 
		Answer: NONE
***************************************************************************************************************************************

Solution: 
#include <iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <set>

int main() 
{
  set<int> s; 
  int nums1;
  int nums2;
  int num;

  cin >> nums1; // get number of digits that will be in the first group

  for(int i = 0; i < nums1; i++) // get those n digits for first group and add them to a set
  {
    cin >> num;
    s.insert(num);
  }

  cin >> nums2; // get number of digits that will be in the second group

  for(int i = 0; i < nums2; i++) // get those n digits for second group and if it does not appear in the set already add it, but if it does, delete the num from the set
  {
    cin >> num;
    bool ans = s.find(num) != s.end();
    if(ans == false)
    {
      s.insert(num);
    }
    else
    {
      s.erase(num);
    }
  }
  
  if(s.size() == 0) // corner case for empty set
  {
      cout << "Answer:NONE";
      return 0;
  }

  set<int>::reverse_iterator it;
  cout << "Answer:";
  for(it = s.rbegin(); it != s.rend(); it++) // else print the numbers but in reverse order so it can be descending
  {
    cout << *it << " ";
  }
}


