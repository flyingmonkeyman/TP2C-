#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "score.h"


int main() {
  std::fstream fichier("hiscore.txt", std::ios::in);

  std::map<long, Score> hiScoring;

  //Boucle pour remplir le map hiScoring
  while (!fichier.eof()) {
    long parti = 0;
    std::string pseudo;
    long scor = 0;

    fichier >> parti;
    fichier >> pseudo;
    fichier >> scor;

    hiScoring.emplace(scor, Score(parti, pseudo, scor));
  }
  //Creation du fichier texte "asterostorm.txt"
  std::ofstream write("asterostorm.txt", std::ios::out);

  //Iterateur inverse pour parcourir le map
  std::map<long, Score>::reverse_iterator iter;
  
  
  //Boucle pour afficher les scores et info
  for (iter = hiScoring.rbegin(); iter != hiScoring.rend(); iter++) {
    std::cout << iter->second.getPseudonym() << std::endl;
    std::cout << iter->second.getPartie() << std::endl;
    std::cout << "Asterostorm=" << iter->second.getScore() << std::endl;
  }
  //Boucle pour inscrire les scores et info dans "asterostorm.txt"
  for (iter = hiScoring.rbegin(); iter != hiScoring.rend(); iter++) {
    write << iter->second.getPseudonym() << std::endl;
    write << iter->second.getPartie() << std::endl;
    write << "Asterostorm=" << iter->second.getScore() << std::endl;
  }
}

