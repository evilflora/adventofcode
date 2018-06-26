#include <iostream>
#include <cmath>

using namespace std;

int longueur_carre(int);
void test();

int main() {
  clock_t begin = clock();
  
  int start = 312051; // case de départ
  int carre = longueur_carre(start); // calcul de la longueur des côtés du carré // on peut faire
  int end_x = (carre/2), end_y = (carre/2); // centre du tableau
  int start_x, start_y; // position du chiffre de départ
  int distance = 0; // nombre de steps

  // todo simplifier
  if (start >= (carre*carre)-(4*carre)+5 && start <= (carre*carre)-(3*carre)+3){
    start_x = ((carre*carre)-(3*carre)+3) - start;
    start_y = carre - 1;
  } else if (start >= (carre*carre)-(3*carre)+3 && start <= (carre*carre)-(2*carre)+2){
    start_x = 0;
    start_y = ((carre*carre)-(2*carre)+2) - start;
  } else if (start >= (carre*carre)-(2*carre)+2 && start <= (carre*carre)-(1*carre)+1){
    start_x = (carre - 1) - ( ((carre*carre)-(1*carre)+1) - start);
    start_y = 0;
  } else if (start >= (carre*carre)-(1*carre)+1 && start <= (carre*carre)-(0*carre)+0) {
    start_x = carre - 1;
    start_y = (carre - 1) - ( ((carre*carre)-(0*carre)+0) - start);
  }
  
  distance = abs(end_x - start_x) + abs(end_y - start_y); // nombre de steps

  clock_t end = clock();
  printf("Carré de %dx%d\n",carre,carre);
  printf("Centre [%d][%d]\n",end_x,end_y);
  printf("Position [%d][%d]\n",start_x,start_y);
  printf("Distance = %d\n",distance);
  printf("Duration = %f s\n",(double)(end - begin) / CLOCKS_PER_SEC);
  
}

int longueur_carre(int value) {
    int carre = 1;
    while (value > (carre*carre)) carre += 2; // calcul de la longueur des côtés du carré // on peut faire
    return carre;
}
