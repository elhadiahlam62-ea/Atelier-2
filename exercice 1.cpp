#include <iostream>

void compterAppels() {
    static int compteur = 0;  
    compteur++;
    std::cout << "appel numéro " << compteur << std::endl;
}

int main() {
    
    compterAppels();  
    compterAppels();  
    compterAppels();  
    compterAppels(); 
    
    return 0;
}