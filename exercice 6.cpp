#include <iostream>
using namespace std;

// Fonction incrementer avec pointeur
void incrementer(int *p) {
    (*p)++;  // Incrémente la valeur pointée
}

// Fonction permuter avec pointeurs
void permuter(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    cout << "===== TRANSMISSION PAR ADRESSE (pointeurs) =====" << endl << endl;
    
    // Test incrementer avec pointeur
    int a = 10;
    cout << "Avant incrementer : a = " << a << endl;
    incrementer(&a);  // On passe l'adresse de a
    cout << "Apres incrementer : a = " << a << endl;
    cout << endl;
    
    // Test permuter avec pointeurs
    int x = 5, y = 20;
    cout << "Avant permuter : x = " << x << ", y = " << y << endl;
    permuter(&x, &y);  // On passe les adresses
    cout << "Apres permuter : x = " << x << ", y = " << y << endl;
    
    return 0;
}