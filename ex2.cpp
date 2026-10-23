
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Article {
public:
    string nom;
    float prix;
    int quantite;
    float tauxTVA;

    Article(string n, float p, int q, float t) {
        nom = n;
        prix = p;
        quantite = q;
        tauxTVA = t;
    }

    float calculerTotal() {
        return prix * quantite * (1 + tauxTVA / 100);
    }
};

class Facture {
private:
    vector<Article> articles;

public:
    // Version 1 : nom et prix unitaire
    void ajouterArticle(string nom, float prix) {
        articles.push_back(Article(nom, prix, 1, 0));
    }

    // Version 2 : nom, prix et quantite
    void ajouterArticle(string nom, float prix, int quantite) {
        articles.push_back(Article(nom, prix, quantite, 0));
    }

    // Version 3 : nom, prix, quantite et taux TVA
    void ajouterArticle(string nom, float prix,
                        int quantite, float tauxTVA) {
        articles.push_back(
            Article(nom, prix, quantite, tauxTVA)
        );
    }

    // Afficher le total de la facture
    void afficherTotal() {
        float total = 0;

        cout << "=== Detail de la facture ===" << endl;

        for (int i = 0; i < articles.size(); i++) {
            cout << "Article : " << articles[i].nom << endl;
            cout << "Prix unitaire : "
                 << articles[i].prix << " DH" << endl;
            cout << "Quantite : "
                 << articles[i].quantite << endl;
            cout << "TVA : "
                 << articles[i].tauxTVA << "%" << endl;
            cout << "Total article TTC : "
                 << articles[i].calculerTotal() << " DH"
                 << endl;
            cout << "----------------------" << endl;

            total += articles[i].calculerTotal();
        }

        cout << "Total de la facture : "
             << total << " DH" << endl;
    }
};

int main() {
    Facture f;

    f.ajouterArticle("Stylo", 5);
    f.ajouterArticle("Cahier", 20, 3);
    f.ajouterArticle("Sac", 200, 2, 20);

    f.afficherTotal();

    return 0;
}
