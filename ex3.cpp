
#include <iostream>
using namespace std;

class CompteBancaire {
private:
    double solde;
    int codeSecurite;

public:
    // Constructeur sans solde initial
    CompteBancaire() {
        solde = 0;
        codeSecurite = 1234;
    }

    // Constructeur avec solde initial
    CompteBancaire(double s, int code) {
        if (s >= 0) {
            solde = s;
        } else {
            solde = 0;
        }

        codeSecurite = code;
    }

    // Afficher le solde
    void afficherSolde() {
        cout << "Solde actuel : " << solde << " DH" << endl;
    }

    // Retrait avec montant uniquement
    void retrait(double montant) {
        if (montant <= 0) {
            cout << "Montant invalide !" << endl;
        } else if (montant > solde) {
            cout << "Solde insuffisant !" << endl;
        } else {
            solde -= montant;
            cout << "Retrait effectue avec succes." << endl;
        }
    }

    // Retrait avec montant et code de securite
    void retrait(double montant, int code) {
        if (code != codeSecurite) {
            cout << "Code de securite incorrect !" << endl;
        } else if (montant <= 0) {
            cout << "Montant invalide !" << endl;
        } else if (montant > solde) {
            cout << "Solde insuffisant !" << endl;
        } else {
            solde -= montant;
            cout << "Retrait securise effectue avec succes." << endl;
        }
    }
};

int main() {
    // Compte sans solde initial
    CompteBancaire c1;

    cout << "=== Compte 1 ===" << endl;
    c1.afficherSolde();

    c1.retrait(100);

    // Compte avec solde initial et code de securite
    CompteBancaire c2(1000, 4567);

    cout << "\n=== Compte 2 ===" << endl;
    c2.afficherSolde();

    c2.retrait(200, 4567);
    c2.afficherSolde();

    // Test avec un code incorrect
    c2.retrait(100, 1111);
    c2.afficherSolde();

    return 0;
}
