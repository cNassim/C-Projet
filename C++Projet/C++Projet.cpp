#include <iostream>
#include <string>
#include <cstdlib>
#include "CGraph.h"

using namespace std;

void displayHeader() {
    cout << "+==========================================================+" << endl;
    cout << "|                C++ PROJECT/GRAPH LIBRARY                 |" << endl;
    cout << "+==========================================================+" << endl;
}

void displayDetails() {
    cout << "+==========================================================+" << endl;
    cout << "|                         -Made by:                        |" << endl;
    cout << "|  - Nassim BELLANAYA (https://github.com/cNassim)         |" << endl;
    cout << "|  - EL YAZID GUERMA                                       |" << endl;
    cout << "+==========================================================+" << endl;
    cout << "|                 -Features of the library:                |" << endl;
    cout << "|1. Create graph objects                                   |" << endl;
    cout << "|2. Perform basic operations on a graph:                   |" << endl;
    cout << "|   a. Add/modify/delete a vertex                          |" << endl;
    cout << "|   b. Add/modify/delete an edge/arc                       |" << endl;
    cout << "|   c. Display a graph in the console                      |" << endl;
    cout << "|   d. Reverse an arc                                      |" << endl;
    cout << "|   e. Reverse an entire graph                             |" << endl;
    cout << "|   f. Read from a file                                    |" << endl;
    cout << "+==========================================================+" << endl;
}


void menu() {
    cout << "\n--- MENU ---" << endl;
    cout << "1. Créer un graphe" << endl;
    cout << "2. Ajouter un sommet" << endl;
    cout << "3. Ajouter un arc/arête" << endl;
    cout << "4. Supprimer un sommet" << endl;
    cout << "5. Supprimer un arc/arête" << endl;
    cout << "6. Afficher le graphe" << endl;
    cout << "7. Calculer les ensembles dominants minimaux" << endl;
    cout << "8. Charger un graphe orienté depuis un fichier" << endl;
    cout << "9. Quitter" << endl;
    cout << "Votre choix : ";
}

int main() {
    // Pointeur sur le graphe courant, pour pouvoir switcher orienté/non orienté
    CGraphOrient<int>* graphe = nullptr;
    CGraph<int>* grapheno = nullptr;
    bool isOriente = false;
    vector<CSommet<int>*> memSommets;
	
    displayHeader();
    displayDetails();
    int choix = 0;
    while (choix != 9) {
        displayHeader();
        menu();
        cin >> choix;
        switch (choix) {
        case 1: {
            cout << "Type de graphe (0 = non oriente, 1 = oriente) ? ";
            int type;
            cin >> type;
            isOriente = (type == 1);

            // Libère ancien graphe/sommets si besoin
            if (graphe) { delete graphe; graphe = nullptr; }
            if (grapheno) { delete grapheno; grapheno = nullptr; }
            for (auto s : memSommets) delete s;
            memSommets.clear();

            if (isOriente) {
                graphe = new CGraphOrient<int>();
            }
            else {
                grapheno = new CGraph<int>();
            }
            system("cls");
            cout << "Graphe vide cree !" << endl;
            break;
        }
        case 2: {
            // Ajouter un sommet
            int id;
            cout << "ID du sommet a ajouter : "; cin >> id;
            auto s = new CSommet<int>(id, {}, {});
            memSommets.push_back(s);
            if (isOriente) {
                if (graphe) {
                    graphe->CGraphOAjouterSommet(s);
                }
            }
            else {
                if (grapheno) {
                    grapheno->CGraphOAjouterSommet(s);
                }
			}
            system("cls");
            cout << "Sommet ajoute." << endl;
            break;
        }
        case 3: {
            // Ajouter un arc/arête
            int deb, fin;
            cout << "Sommet de "; cin >> deb;
            cout << (isOriente ? " a " : " et "); cin >> fin;
            CSommet<int>* sdeb = nullptr;
            CSommet<int>* sfin = nullptr;
            for (auto s : memSommets) {
                if (s->SOMGet_Id() == deb) sdeb = s;
                if (s->SOMGet_Id() == fin) sfin = s;
            }
            if (sdeb && sfin) {
                if (isOriente){
                    graphe->CGraphOAjouterArc(new CArc<int>(sdeb, sfin));
                    system("cls");
                    cout << " Arc ajoute." << endl;
                }
				else{
                    grapheno->CGraphAjouterArret(new CArc<int>(sdeb, sfin));
                    system("cls");
                    cout << " Arête ajoutee." << endl;
				}
            }
            else {
                system("cls");
                cout << "Sommet(s) non trouve(s) !" << endl;
            }
            break;
        }
        case 4: {
            // Supprimer un sommet
            int id;
            cout << "ID du sommet a supprimer : "; cin >> id;
            if (isOriente) {
                graphe->CGraphOSupprimerSommet(id);
                system("cls");
                cout << "Sommet supprime !" << endl;
            }
            else {
				grapheno->CGraphOSupprimerSommet(id);
                system("cls");
                cout << "Sommet supprime !" << endl;
            }
            break;
        }
        case 5: {
            // Supprimer un arc/arête
            int deb, fin;
            cout << "Sommet de "; cin >> deb;
            cout << (isOriente ? " a " : " et "); cin >> fin;
            // Chercher et supprimer l'arc/arête
            // (Parcours la liste des arcs/arêtes et supprime le bon)
            cout << "(Suppression a implementer selon ta lib !)" << endl;
            break;
        }
        case 6: {
            if (isOriente)
            {
                if (graphe) graphe->CGraphOAfficher();
                else {
                    system("cls");
                    cout << "Aucun graphe en memoire !" << endl;
                }

            }
            else
            {
                if(grapheno) grapheno->CGraphAfficher();
                else {
                    system("cls");
                    cout << "Aucun graphe en memoire !" << endl;
                }
            }
            break;
        }
        case 7: {
            if (isOriente)
            {
                system("cls");
                cout << "Operation impossible !!" << endl;
            }
            else {
                if (grapheno) {
                    system("cls");
                    grapheno->CGraphCalcDomMin();
                }
                else {
                    system("cls");
                    cout << "Aucun graphe en memoire !" << endl; 
                }
            }
            break;
        }
        case 8: {
            if (isOriente)
            {
                // Charger graphe orienté depuis fichier
                string filename;
                cout << "Nom du fichier : ";
                cin >> filename;
                if (graphe) { delete graphe; graphe = nullptr; }
                for (auto s : memSommets) delete s;
                memSommets.clear();
                graphe = CGraphOrient<int>::CGraphOLireFichier(filename);
                if (!graphe) {
                    system("cls");
                    cout << "Erreur de chargement !" << endl;
                }
                else {
                    system("cls");
                    cout << "Graphe chargé !" << endl;
                }
                break;
            }
            else {
                system("cls");
                cout << "Opération impossible !!" << endl;
            }
        }
        case 9:
            cout << "Au revoir !" << endl;
            break;
        default:
            cout << "Choix invalide !" << endl;
        }
    }

    if (graphe) delete graphe;
	if (grapheno) delete grapheno;
    for (auto s : memSommets) delete s;
    return 0;
}