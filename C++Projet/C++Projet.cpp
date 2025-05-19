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

int main(int argc, char* argv[]) {
    //bool modecin = false;
    //try {
        displayHeader();
        displayDetails();

        /*string sNomFichier;

        // Leve un exception si on a plus d'un paramètre
        if (argc > 2) {
            throw CException(1721);
        }

        // Vérifier si un nom de fichier est passé en paramètre
        if (argc == 2) {
            sNomFichier = argv[1];
        }
        else {
            modecin = true;
            cout << "Pas de parametres detecte, passage en mode 'cin'" << endl;
            cout << "Veuillez entrer le nom du fichier : ";
            getline(cin, sNomFichier);
        }

        // Étape 2 : Lire le fichier et créer le graphe associé
        CGraphOrient<int>* graphe = CGraphOrient<int>::CGraphOLireFichier(sNomFichier);
        if (!graphe) {
            cerr << "Erreur : Impossible de creer le graphe a partir du fichier." << endl;
            if (modecin) {
                cout << "\nAppuyez sur entrer pour fermer le programme..." << endl;
                cin.get();
            }
            return 1;
        }

        // Étape 3 : Afficher le graphe
        cout << "Graphe original :" << endl;
        graphe->CGraphOAfficher();

        // Calcul et affichage des ensembles dominants minimaux
        cout << "\nCalcul des ensembles dominants minimaux..." << endl;
        graphe->CGraphCalcDomMin();

        // Libération de la mémoire
        delete graphe;
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 1721) {
            cerr << "Trop de parametres fournis. Un seul parametre attendu ! Code erreur : " << e.EXCGet_Val() << endl;
        }
        else {
            cerr << "Une exception a ete levee : Code " << e.EXCGet_Val() << endl;
        }
        if (modecin) {
            cout << "\nAppuyez sur entrer pour fermer le programme..." << endl;
            cin.get();
        }
        return 1;
    }

    if (modecin) {
        cout << "\nAppuyez sur entrer pour fermer le programme..." << endl;
        cin.get();
    }
    return 0;
}*/
        cout << "\n--- Test : Calcul des ensembles dominants minimaux sur un triangle ---" << endl;

        // Création de 3 sommets
        vector<CSommet<int>*> sommets;
        for (int i = 0; i < 3; ++i)
            sommets.push_back(new CSommet<int>(i, {}, {}));

        // Création du graphe non orienté
        CGraph<int> graphe;

        // Ajout des sommets dans le graphe (si nécessaire selon ton implémentation, sinon saute cette étape)
        for (auto s : sommets)
            graphe.CGraphOAjouterSommet(s); // Si tu as une méthode d'ajout de sommet

        // Ajout des arêtes pour former un triangle 
        graphe.CGraphAjouterArret(new CArc<int>(sommets[0], sommets[1]));
        graphe.CGraphAjouterArret(new CArc<int>(sommets[1], sommets[2]));
        graphe.CGraphAjouterArret(new CArc<int>(sommets[2], sommets[0]));

        cout << "Nombre de sommets dans le graphe : " << graphe.CGraphOGET_Sommet().size() << endl;

        // Affichage du graphe
        graphe.CGraphAfficher();

        // Calcul et affichage des ensembles dominants minimaux
        graphe.CGraphCalcDomMin();

        // Libération mémoire (optionnel, dépend de la gestion dans CGraph)
        for (auto s : sommets) delete s;

   return 0;
}