#include <iostream>

using namespace std;

int longueur_carre(int);
void test();

int main() {
  clock_t begin = clock();
  
  int start = 81; // case de départ
  int carre = longueur_carre(start); // calcul de la longueur des côtés du carré // on peut faire
  int end_x = (carre/2), end_y = (carre/2); // centre du tableau
  int tab[carre][carre] = {0};
  int x = end_x, y = end_y;
  int a = 1, b = 2;
  
  for(int i = 0, j; i < carre; i++) {
    for(j=0; j < carre; j++) {
      tab[i][j] = 0;
    }
  }
  
  tab[x][y]   = 1; // centre
  for(int i = 0; i < end_x; i++) { // X carré donnc par le centre
  
    tab[x][++y] += tab[x][y-1]; // +y, à droite, généralement valeur pour nouveau carré
    if (i > 0) tab[x][y] += tab[x-1][y-1];

    for(int j = 0; j < a - 1; j++) {
        tab[--x][y] += tab[x+1][y-1] + tab[x+1][y] + tab[x][y-1] + tab[x-1][y-1]; // -x, milieu colonne de droite
    }
    tab[--x][y] += tab[x+1][y-1] + tab[x+1][y]; // -x, coin en haut à droite

    for(int j = 0; j < b - 1; j++) {
        tab[x][--y] += tab[x][y+1] + tab[x+1][y+1] + tab[x+1][y] + tab[x+1][y-1]; // -y, milieu ligne en haut
    }
    tab[x][--y] += tab[x][y+1] + tab[x+1][y+1]; // -y | 1 fois, coin en haut à gauche

    for(int j = 0; j < b - 1; j++) {
        tab[++x][y] += tab[x-1][y] + tab[x][y+1] + tab[x-1][y+1]+ tab[x+1][y+1]; // +x, milieu colonne de gauche
    }
    tab[++x][y] += tab[x-1][y] + tab[x-1][y+1]; // +x, coin en bas à gauche

    for(int j = 0; j < b - 1; j++) {
        tab[x][++y] += tab[x-1][y+1] + tab[x-1][y] + tab[x-1][y-1] + tab[x][y-1]; // +y, milieu ligne du bas
    }
    tab[x][++y] += tab[x-1][y] + tab[x-1][y-1] + tab[x][y-1]; // +y, coin en bas à droite
    
    a+=2;
    b+=2;
  }
  
  for(int i = 0, j; i < carre; i++) {
      for(j=0; j < carre; j++) {
          printf("%8d",tab[i][j]);
      }
      printf("\n");
  }
  
  clock_t end = clock();
  //printf("Carré de %dx%d\n",carre,carre);
  //printf("Centre [%d][%d]\n",end_x,end_y);
  printf("Duration = %f s\n",(double)(end - begin) / CLOCKS_PER_SEC);
  
}

int longueur_carre(int value) {
    int carre = 1;
    while (value > (carre*carre)) carre += 2; // calcul de la longueur des côtés du carré // on peut faire
    return carre;
}
