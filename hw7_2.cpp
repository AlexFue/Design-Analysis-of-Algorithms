Problem: 
Write a problem that displays the city names in the range of hop(s) from a starting city. For this problem, refer to the sample BFS program at https://repl.it/@YBYUN/BFS

Ex: Input: 4
		   Monterey
		   LA
		   SF
		   SD
		   6
		   Monterey LA
		   LA SD
		   SD Monterey
		   SF Monterey
		   SF LA
		   SF SD
		   Monterey
		   2

	Output:LA
		   Monterey
		   SD

	Explanation: 
		Your program should present the city names in the ascending order like below.  Note that LA can be reached from Monterey in one hop, Monterey in zero hop, and SD in two hops. For the problem, you can assume that the city name is always one word.

		Monterey ---> LA
			  ^	⬉   ➚ |
			  |	 \ /  |
			  |	  X   |
			  |	 / \  |
			  |	/   \ ↓
			  SF ---> SD 



Solution: 
#include <iostream>
using namespace std;
#include <vector>
#include<map>
#include <queue>
#include <set>
#include <utility>

string start; // global variable that stores starting city

// function finds all cities that are within hop number and displays them in alphabetical order 
void bfs(map<string, vector<string>> m, int hops) 
{
  queue<pair<string, int>>q; // noraml bfs queue but includes number of hops from origin city 
	set<string> seen; // set the keeps tracks of cities seen already
  set<string> places; // set for cities that are within hop range
    
  // start by adding starting city to seen cities, also add it to queue with # of hops away from start which is 0 (adding them as a pair)
	seen.insert(start); 
  pair<string, int> p(start, 0);
  q.push(p);

  while (!q.empty()) 
  {
    // get the front pair and check if its within # of hops to add.
    pair<string, int> curr = q.front();
    q.pop();
    if(curr.second <= hops){
      places.insert(curr.first);
    }
    
    // loop through neighbor cities of current city
    for(auto neighbor : m[curr.first]) 
    {
      // if havent seen neighbor, then add it to seen set, add it to queue with number of hops from current city (which is +1)
      if(!seen.count(neighbor)) 
      {
        seen.insert(neighbor);
        pair<string, int> p(neighbor, curr.second+1);
        q.push(p);
      }
    }
  }

  // loop through cities that are within hops and print them
  for(auto place : places){
    cout << place << endl;
  }
}


int main() {
  int v, e, hops;
  map<string, vector<string>> m;

  // get cities and add them to map 
  cin >> v;
  for(int i = 0; i < v; i++){
    string city;
    cin >> city;
    m[city];
  }

  // get paths of cities and add them to the city where it starts in the map
  cin >> e;
  cin.ignore();
  for(int i = 0; i < e; i++){
    string input;
    getline(cin, input);
    int space = input.find(' ');
    m[input.substr(0, space)].push_back(input.substr(space+1, input.length()));
  }

  // get starting city and # of hops
  cin >> start;
  cin >> hops;

  // call bfs hop function 
  bfs(m, hops);
}