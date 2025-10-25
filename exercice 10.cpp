#include <iostream>
#include <iomanip>  // Pour std::setprecision

using namespace std;

class Complexe {
private:
    double reel;    // Partie réelle
    double imag;    // Partie imaginaire

public:
    // Constructeur par défaut
    Complexe() : reel(0), imag(0) {}

    // Constructeur avec paramètres
    Complexe(double r, double i) : reel(r), imag(i) {}

    // Méthode pour saisir les valeurs
    void saisir() {
        cout << "Entrez la partie reelle : ";
        cin >> reel;
        cout << "Entrez la partie imaginaire : ";
        cin >> imag;
    }

    // Méthode pour afficher le nombre complexe
    void afficher() const {
        cout << fixed << setprecision(2) << reel;
        if (imag >= 0) {
            cout << " + " << imag << "i";
        } else {
            cout << " - " << -imag << "i";
        }
        cout << endl;
    }

    // Opération d'addition
    Complexe addition(const Complexe& autre) const {
        return Complexe(reel + autre.reel, imag + autre.imag);
    }

    // Opération de soustraction
    Complexe soustraction(const Complexe& autre) const {
        return Complexe(reel - autre.reel, imag - autre.imag);
    }

    // Opération de multiplication
    Complexe multiplication(const Complexe& autre) const {
        double r = reel * autre.reel - imag * autre.imag;
        double i = reel * autre.imag + imag * autre.reel;
        return Complexe(r, i);
    }

    // Opération de division
    Complexe division(const Complexe& autre) const {
        double denom = autre.reel * autre.reel + autre.imag * autre.imag;
        if (denom == 0) {
            cout << "Erreur : Division par zero !" << endl;
            return Complexe(0, 0);  // Retourne un complexe nul en cas d'erreur
        }
        double r = (reel * autre.reel + imag * autre.imag) / denom;
        double i = (imag * autre.reel - reel * autre.imag) / denom;
        return Complexe(r, i);
    }

    // Opération d'égalité
    bool egalite(const Complexe& autre) const {
        return (reel == autre.reel && imag == autre.imag);
    }
};

int main() {
    Complexe c1, c2, resultat;
    int choix;

    // Saisie des deux nombres complexes
    cout << "Saisie du premier nombre complexe :" << endl;
    c1.saisir();
    cout << "Saisie du deuxième nombre complexe :" << endl;
    c2.saisir();

    // Affichage des nombres saisis
    cout << "\nPremier nombre complexe : ";
    c1.afficher();
    cout << "Deuxième nombre complexe : ";
    c2.afficher();

    // Menu des opérations
    cout << "\nChoisissez une operation :" << endl;
    cout << "1. Egalite" << endl;
    cout << "2. Addition" << endl;
    cout << "3. Soustraction" << endl;
    cout << "4. Multiplication" << endl;
    cout << "5. Division" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    // Traitement du choix
    switch (choix) {
        case 1:
            if (c1.egalite(c2)) {
                cout << "Les deux nombres complexes sont egaux." << endl;
            } else {
                cout << "Les deux nombres complexes ne sont pas egaux." << endl;
            }
            break;
        case 2:
            resultat = c1.addition(c2);
            cout << "Resultat de l'addition : ";
            resultat.afficher();
            break;
        case 3:
            resultat = c1.soustraction(c2);
            cout << "Resultat de la soustraction : ";
            resultat.afficher();
            break;
        case 4:
            resultat = c1.multiplication(c2);
            cout << "Resultat de la multiplication : ";
            resultat.afficher();
            break;
        case 5:
            resultat = c1.division(c2);
            cout << "Resultat de la division : ";
            resultat.afficher();
            break;
        default:
            cout << "Choix invalide !" << endl;
            break;
    }

    return 0;
}
