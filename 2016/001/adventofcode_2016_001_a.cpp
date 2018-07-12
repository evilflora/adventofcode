#include <iostream>
#include <cstring>
#include <vector>
#include <array>
#include <map>

using namespace std;

const vector<string> explode(const string&, const char&);
const int get_weight(const string&);
int main() {
  clock_t begin = clock();
  
  string input = "R5,L5,R5,R3"; // chaine d entree
  short direction = 0; // 0 = N, 1 = E, 2 = S, 3 = W
  vector<string> tab{explode(input, ',')}; // on decoupe la chaine en une liste de commandes
  int x = 0, y = 0; // point de deppart
  short len = tab.size(); // le nombres de commandes à executer
  
  for(int i = 0; i < len; i++) {
   direction = (direction + (tab[i][0] == 'R' ? 1 : -1) ) % 4;
   switch(direction) {
    case 0:
      x += get_weight(tab[i]);
    break;
    case 1:
      y += get_weight(tab[i]);
    break;
    case 2:
      x -= get_weight(tab[i]);
    break;
    case 3:
      y -= get_weight(tab[i]);
    break;
   }
  } // listage des commandes
	
  clock_t end = clock();
  printf("Distance %d\n",abs(x) + abs(y));
  printf("Duration = %f s\n",(double)(end - begin) / CLOCKS_PER_SEC);
}

const vector<string> explode(const string& s, const char& c) {
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}

const int get_weight(const string& s) {
  string buff = "0";
  
  for(auto n:s) {
    if(n >= '0' && n <= '9') { buff+=n; }
  } 
    
  return stoi(buff);
}
