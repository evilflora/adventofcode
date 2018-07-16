#include <iostream>
#include <cstring>
#include <vector>
#include <array>
#include <map>

#define MAP map<short,map<short, short>>

using namespace std;

const vector<string> explode(const string&, const char&);
const int get_weight(const string&);

int main() {
  clock_t begin = clock();
  
  string input = "R3,L5,R1,R2,L5,R2,R3,L2,L5,R5,L4,L3,R5,L1,R3,R4,R1,L3,R3,L2,L5,L2,R4,R5,R5,L4,L3,L3,R4,R4,R5,L5,L3,R2,R2,L3,L4,L5,R1,R3,L3,R2,L3,R5,L194,L2,L5,R2,R1,R1,L1,L5,L4,R4,R2,R2,L4,L1,R2,R53,R3,L5,R72,R2,L5,R3,L4,R187,L4,L5,L2,R1,R3,R5,L4,L4,R2,R5,L5,L4,L3,R5,L2,R1,R1,R4,L1,R2,L3,R5,L4,R2,L3,R1,L4,R4,L1,L2,R3,L1,L1,R4,R3,L4,R2,R5,L2,L3,L3,L1,R3,R5,R2,R3,R1,R2,L1,L4,L5,L2,R4,R5,L2,R4,R4,L3,R2,R1,L4,R3,L3,L4,L3,L1,R3,L2,R2,L4,L4,L5,R3,R5,R3,L2,R5,L2,L1,L5,L1,R2,R4,L5,R2,L4,L5,L4,L5,L2,L5,L4,R5,R3,R2,R2,L3,R3,L2,L5"; // chaine d entree
  //string input = "R8, R4, R4, R8"; // chaine d entree
  short direction = 0; // voir switch
  vector<string> tab{explode(input, ',')}; // on decoupe la chaine en une liste de commandes
  int x = 0, y = 0; // point de depart
  short len = tab.size(); // le nombres de commandes à executer
  
  for(int i = 0; i < len; i++) {
   direction = (direction + (tab[i][0] == 'R' ? 1 : 3) ) % 4;
   switch(direction) {
    case 0: // Nord
      y += get_weight(tab[i]);
    break;
    case 1: // Est
      x += get_weight(tab[i]);
    break;
    case 2: // Sud
      y -= get_weight(tab[i]);
    break;
    case 3: // Ouest
      x -= get_weight(tab[i]);
    break;
   }
  } // listage des commandes
	
  clock_t end = clock();
  printf("Distance %d\n",abs(x) + abs(y)); // 236
  printf("Duration = %f s\n",(double)(end - begin) / CLOCKS_PER_SEC);
}

const vector<string> explode(const string& s, const char& c) {
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c && n != ' ') buff+=n; else
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
