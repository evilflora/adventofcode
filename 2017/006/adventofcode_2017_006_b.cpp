#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
  clock_t begin = clock();

  const short len = 16; // taille tu tableau
  array<short, len> tab = {10,3,15,10,5,15,5,15,9,2,5,8,5,2,3,6}; // résultat 2765
  // array<short, len> tab = {2,8,8,5,4,2,3,1,5,5,1,2,15,13,5,14}; // résultat 1610
  short value = 0, i_seen = 0; // index = position dans le tableau, valeur = nombres d'étapes
  bool stop = false;
  vector<array<short, len>> memory;
  
  while(!stop) {
    short max = -1,index_found; // variable temporaire voir boucle
    short local_index = 0;
    
    for(int i = 0; i < len; i++) { // recherche du plus grand nombre et son index dans le tableau
      if(tab[i] > max) {
        max = tab[i];
        local_index=index_found=i;
      }
    }
    
    tab[index_found] = 0;
    while(max--) tab[(unsigned short)(++local_index)%len]++; // on fait ça X fois la valeur de max et on ahoute +1 à la case suivante
    
    memory.push_back(tab); // augmente automatiquement la taille du vector
    
    if(i_seen == 0) { // si on n'a jamais trouvé la solution
      for(int i = 0; i < memory.size()-1 ; i++) // on cherche si on l'a possède
        if(memory[i]==tab) { i_seen = value; break; } // si on la trouve on stock ou elle est
    } else if(tab == memory[i_seen]) stop = true; // sinon on regarde si on la trouve une seconde fois
    
    value++;
  }
  
  clock_t end = clock();
  printf("Résultat : "); for(int i = 0; i < len; i++) printf("%d ",tab[i]); printf("\n");
  printf("Nombre de steps : %d\n",value-i_seen-1);
  printf("Duration = %f s\n",(double)(end - begin) / CLOCKS_PER_SEC);
}
