#include <iostream>
#include <cmath>

using namespace std;

int longueur_carre(int);
void test();

int main() {
  clock_t begin = clock();
  
  int start = 49; // case de départ
  int carre = longueur_carre(start); // calcul de la longueur des côtés du carré // on peut faire
  int end_x = (carre/2), end_y = (carre/2); // centre du tableau
  int value = 1;
  int tab[carre][carre] = {0};
  int x = end_x, y = end_y;
  int a = 1, b = 2;
  
  tab[end_x][end_y] = value; // le centre du tableau
  for(int i = 0; i < end_x; i++) { // X carré donnc par le centre
      tab[x][++y] = ++value; // déplacement à droite |+y
      printf("+y ");
      for(int j = 0; j < a; j++) {
          tab[--x][y] = ++value; // déplacement en haut |-x
          printf("-x ");
      }
      for(int j = 0; j < b; j++) {
          tab[x][--y] = ++value; // déplacement en haut |-y
          printf("-y ");
      }
      for(int j = 0; j < b; j++) {
          tab[++x][y] = ++value; // déplacement en haut |+x
          printf("+x ");
      }
      for(int j = 0; j < b; j++) {
          tab[x][++y] = ++value; // déplacement à droite |+y
          printf("+y ");
      }
      printf("\n");
      a+=2;
      b+=2;
  }
  
  for(int i = 0, j; i < carre; i++) {
      for(j=0; j < carre; j++) {
          printf("%5d",tab[i][j]);
      }
      printf("\n");
  }
  
  clock_t end = clock();
  printf("Carré de %dx%d\n",carre,carre);
  printf("Centre [%d][%d]\n",end_x,end_y);
  printf("Duration = %f s\n",(double)(end - begin) / CLOCKS_PER_SEC);
  
}

int longueur_carre(int value) {
    int carre = 1;
    while (value > (carre*carre)) carre += 2; // calcul de la longueur des côtés du carré // on peut faire
    return carre;
}
