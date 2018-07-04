//http://adventofcode.com/2017/day/1

#include <iostream>

using namespace std;

int main() {
  clock_t begin = clock();

  // La valeur d'entrée
  char input[] = "91212129";
  // Longueur de l'input, la boucle et le résultat
  short len = sizeof(input) - 1, i = 0, resultat = 0;
  /* Pour la longueur de boucle, on compare le caractère actuel au suivant
   * Si on arrive en bout de chaîne on compare au premier caractère
   * S'il est égale on convertit le caractère actuel en chiffre qu'on 
   * additionne au résultat
   */
  for(;i<len;i++) if (input[i] == input[(i+1)%len]) resultat+=input[i]-'0';

  clock_t end = clock();
  printf("Résultat %d\n",resultat);
  printf("Duration = %f s\n",(double)(end - begin) / CLOCKS_PER_SEC);
}
