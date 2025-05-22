#include <iostream>
#include <string>
#include <cstdlib>
#include "CGraph.h"

using namespace std;

// Affiche un en-tête décoratif pour le programme
void displayHeader() {
    cout << "+==========================================================+" << endl;
    cout << "|                C++ PROJECT/GRAPH LIBRARY                 |" << endl;
    cout << "+==========================================================+" << endl;
}

// Affiche des informations sur les auteurs et les fonctionnalités de la bibliothèque
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

// Affiche le menu principal, en précisant si un graphe est déjà créé
void menu(bool bIsOriente, CGraphOrient<int>* pCGraphOrient, CGraph<int>* pCGraph) {
    cout << "\n--- MENU ---" << endl;
    if (bIsOriente) {
        if (pCGraphOrient) {
            cout << ">>> Vous travaillez sur un graph oriente !" << endl;
        }
    }
    else {
        if (pCGraph) {
            cout << ">>> Vous travaillez sur un graph non oriente !" << endl;
        }
    }
    cout << "1. Creer un graphe." << endl;
    cout << "2. Ajouter un sommet." << endl;
    cout << "3. Ajouter un arc/arete." << endl;
    cout << "4. Supprimer un sommet." << endl;
    cout << "5. Supprimer un arc/arete." << endl;
    cout << "6. Afficher le graphe." << endl;
    cout << "7. Calculer les ensembles dominants minimaux." << endl;
    cout << "8. Charger un graphe oriente depuis un fichier." << endl;
    cout << "9. Inverser Graph ( oriente uniquement ) ." << endl;
    cout << "10 . Quitter le programme." << endl;
    cout << "--> Votre choix : ";
}

int main(int argc, char* argv[]) {
    try {
        // Pointeurs pour gérer le graphe courant (orienté ou non orienté)
        CGraphOrient<int>* pCGraphOrient = nullptr;
        CGraph<int>* pCGraph = nullptr;
        bool bIsOriente = false; // Indique le type de graphe courant
        vector<CSommet<int>*> vPCSommets; // Stocke tous les sommets pour gestion mémoire
        string sNomFichier; // Nom de fichier en cas de chargement par fichier

        // Affiche l'en-tête et les détails dès le lancement
        displayHeader();
        displayDetails();

        // Vérification du nombre d'arguments (trop de paramètres)
        if (argc > 2) {
            throw CException(1721);
        }

        // Si un nom de fichier est passé en argument, on charge directement un graphe orienté
        if (argc == 2) {
            sNomFichier = argv[1];
            CGraphOrient<int>* pCGraphOrient = CGraphOrient<int>::CGraphOLireFichier(sNomFichier);
            if (!pCGraphOrient) {
                cerr << "Erreur : Impossible de creer le graphe a partir du fichier." << endl;
                return 1;
            }
            // Affiche le graphe original
            cout << "Graphe original :" << endl;
            pCGraphOrient->CGraphOAfficher();

            // Crée et affiche le graphe inversé
            CGraphOrient<int>* pCGraphOrientInverse = pCGraphOrient->CGraphOInverse();
            cout << "\nGraphe inverse :" << endl;
            pCGraphOrientInverse->CGraphOAfficher();

            // Libère la mémoire allouée aux graphes
            delete pCGraphOrient;
            delete pCGraphOrientInverse;
        }
        else {
            int iChoix = 0; // Stocke le choix utilisateur pour le menu

            // Boucle principale du menu jusqu'à la sortie (choix 10)
            while (iChoix != 10) {
                displayHeader();
                menu(bIsOriente, pCGraphOrient, pCGraph);

                // Lecture et validation du choix utilisateur
                if (!(cin >> iChoix)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    system("cls");
                    throw CException(1045);
                    break;
                }

                switch (iChoix) {
                case 1: {
                    // Création d'un nouveau graphe (orienté ou non)
                    cout << "Type de graphe (0 = non oriente, 1 = oriente) ? ";
                    int iType;
                    if (!(cin >> iType)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        throw CException(1045);
                        break;
                    }
                    if (iType == 1) {
                        bIsOriente = 1;
                    }
                    else if (iType == 0) {
                        bIsOriente = 0;
                    }
                    else {
                        throw CException(1045);
                    }

                    // Libération mémoire si un graphe préexistant
                    if (pCGraphOrient) {
                        delete pCGraphOrient;
                        pCGraphOrient = nullptr;
                    }
                    if (pCGraph) {
                        delete pCGraph;
                        pCGraph = nullptr;
                    }
                    // Libération mémoire des sommets
                    for (auto pCSommet : vPCSommets) {
                        delete pCSommet;
                    }
                    vPCSommets.clear();

                    // Création du nouveau graphe vide selon le type choisi
                    if (bIsOriente) {
                        pCGraphOrient = new CGraphOrient<int>();
                    }
                    else {
                        pCGraph = new CGraph<int>();
                    }
                    system("cls");
                    cout << "Graphe vide cree !" << endl;
                    break;
                }
                case 2: {
                    // Ajout d'un sommet au graphe courant
                    int iId;
                    cout << "ID du sommet a ajouter : ";
                    if (!(cin >> iId)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        throw CException(1051);
                        break;
                    }
                    // Création dynamique du sommet et ajout à la liste mémoire
                    auto pCSommet = new CSommet<int>(iId, {}, {});
                    vPCSommets.push_back(pCSommet);

                    // Ajout du sommet au graphe courant
                    if (bIsOriente) {
                        if (pCGraphOrient) {
                            pCGraphOrient->CGraphOAjouterSommet(pCSommet);
                        }
                    }
                    else {
                        if (pCGraph) {
                            pCGraph->CGraphOAjouterSommet(pCSommet);
                        }
                    }
                    system("cls");
                    cout << "Sommet ajoute." << endl;
                    break;
                }
                case 3: {
                    // Ajout d'un arc (orienté) ou d'une arête (non orienté)
                    int iDeb, iFin;
                    cout << "Sommet de ";
                    if (!(cin >> iDeb)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        throw CException(1051);
                        break;
                    }
                    if (bIsOriente) {
                        cout << " a ";
                    }
                    else {
                        cout << " et ";
                    }
                    if (!(cin >> iFin)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        throw CException(1051);
                        break;
                    }

                    // Recherche des pointeurs vers les sommets de début et fin dans le tableau mémoire
                    CSommet<int>* pCSommetDeb = nullptr;
                    CSommet<int>* pCSommetFin = nullptr;
                    for (auto pCSommet : vPCSommets) {
                        if (pCSommet->SOMGet_Id() == iDeb) {
                            pCSommetDeb = pCSommet;
                        }
                        if (pCSommet->SOMGet_Id() == iFin) {
                            pCSommetFin = pCSommet;
                        }
                    }
                    // Si les deux sommets existent, création de l'arc/arête
                    if (pCSommetDeb && pCSommetFin) {
                        if (bIsOriente) {
                            pCGraphOrient->CGraphOAjouterArc(new CArc<int>(pCSommetDeb, pCSommetFin));
                            system("cls");
                            cout << " Arc ajoute." << endl;
                        }
                        else {
                            pCGraph->CGraphAjouterArret(new CArc<int>(pCSommetDeb, pCSommetFin));
                            system("cls");
                            cout << " Arete ajoutee." << endl;
                        }
                    }
                    else {
                        system("cls");
                        throw CException(1052); // Un sommet n'existe pas
                    }
                    break;
                }
                case 4: {
                    // Suppression d'un sommet par identifiant
                    int iId;
                    cout << "ID du sommet a supprimer : ";
                    if (!(cin >> iId)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        throw CException(1051);
                        break;
                    }
                    if (bIsOriente) {
                        pCGraphOrient->CGraphOSupprimerSommet(iId);
                        system("cls");
                        cout << "Sommet supprime !" << endl;
                    }
                    else {
                        pCGraph->CGraphOSupprimerSommet(iId);
                        system("cls");
                        cout << "Sommet supprime !" << endl;
                    }
                    break;
                }
                case 5: {
                    // Suppression d'un arc/arête entre deux sommets
                    int iDeb, iFin;
                    cout << "Sommet de ";
                    if (!(cin >> iDeb)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        throw CException(1051);
                        break;
                    }
                    if (bIsOriente) {
                        cout << " a ";
                    }
                    else {
                        cout << " et ";
                    }
                    if (!(cin >> iFin)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        throw CException(1051);
                        break;
                    }

                    CArc<int>* pCArcToDelete = nullptr;
                    if (bIsOriente) {
                        // Recherche de l'arc exact à supprimer (sens unique)
                        for (auto pCArc : pCGraphOrient->CGraphOGET_Arc()) {
                            if (pCArc->ARCGet_SomDeb()->SOMGet_Id() == iDeb && pCArc->ARCGet_SomA()->SOMGet_Id() == iFin) {
                                pCArcToDelete = pCArc;
                                break;
                            }
                        }
                        if (pCArcToDelete) {
                            pCGraphOrient->CGraphOSupprimerArc(pCArcToDelete);
                            system("cls");
                            cout << "Arc supprime." << endl;
                        }
                        else {
                            system("cls");
                            throw CException(1052); // arc non trouvé
                        }
                    }
                    else {
                        // Recherche de l'arête dans les deux sens (non orienté)
                        for (auto pCArete : pCGraph->CGraphOGET_Arc()) {
                            if (
                                (pCArete->ARCGet_SomDeb()->SOMGet_Id() == iDeb && pCArete->ARCGet_SomA()->SOMGet_Id() == iFin) ||
                                (pCArete->ARCGet_SomDeb()->SOMGet_Id() == iFin && pCArete->ARCGet_SomA()->SOMGet_Id() == iDeb)
                                ) {
                                pCArcToDelete = pCArete;
                                break;
                            }
                        }
                        if (pCArcToDelete) {
                            pCGraph->CGraphSupprimerArret(pCArcToDelete);
                            system("cls");
                            cout << "Arete supprimee." << endl;
                        }
                        else {
                            system("cls");
                            throw CException(1052); // arête non trouvée
                        }
                    }
                    break;
                }
                case 6: {
                    // Affichage du graphe courant (avec vérification d'existence)
                    if (bIsOriente)
                    {
                        if (pCGraphOrient) {
                            system("cls");
                            pCGraphOrient->CGraphOAfficher();
                        }
                        else {
                            system("cls");
                            throw CException(2132); // Pas de graphe en mémoire
                        }
                    }
                    else
                    {
                        if (pCGraph) {
                            system("cls");
                            pCGraph->CGraphAfficher();
                        }
                        else {
                            system("cls");
                            throw CException(2132); // Pas de graphe en mémoire
                        }
                    }
                    break;
                }
                case 7: {
                    // Calcul des ensembles dominants minimaux (pour graphes non orientés uniquement)
                    if (bIsOriente)
                    {
                        system("cls");
                        throw CException(2133); // Opération non permise sur un graphe orienté
                    }
                    else {
                        if (pCGraph) {
                            system("cls");
                            pCGraph->CGraphCalcDomMin();
                        }
                        else {
                            system("cls");
                            throw CException(2132);
                        }
                    }
                    break;
                }
                case 8: {
                    // Chargement d'un graphe orienté à partir d'un fichier
                    if (bIsOriente)
                    {
                        string sFilename;
                        cout << "Nom du fichier : ";
                        cin >> sFilename;

                        // Libère la mémoire du graphe et des sommets existants
                        if (pCGraphOrient) {
                            delete pCGraphOrient; pCGraphOrient = nullptr;
                        }
                        for (auto pCSommet : vPCSommets) {
                            delete pCSommet;
                        }
                        vPCSommets.clear();

                        pCGraphOrient = CGraphOrient<int>::CGraphOLireFichier(sFilename);
                        system("cls");
                        cout << "Graphe chargé !" << endl;
                        break;
                    }
                    else {
                        system("cls");
                        throw CException(2133); // Opération impossible sur un graphe non orienté
                    }
                }
                case 9:
                    // Inversion de tous les arcs du graphe orienté courant
                    if (bIsOriente)
                    {
                        if (pCGraphOrient) {
                            pCGraphOrient = pCGraphOrient->CGraphOInverse();
                            system("cls");
                            cout << "Graphe inverse avec success :" << endl;
                            pCGraphOrient->CGraphOAfficher();
                        }
                        else {
                            system("cls");
                            throw CException(2132);
                        }
                    }
                    else {
                        if (pCGraph) {
                            system("cls");
                            throw CException(2133);
                        }
                        else {
                            system("cls");
                            throw CException(2132);
                        }
                    }
                    break;
                case 10:
                    // Sortie du programme
                    cout << "Au revoir !" << endl;
                    break;
                default:
                    cout << "Choix invalide !" << endl;
                }
            }
            // Libération finale de la mémoire à la sortie du programme
            if (pCGraphOrient) {
                delete pCGraphOrient;
            }
            if (pCGraph) {
                delete pCGraph;
            }
            for (auto pCSommet : vPCSommets) {
                delete pCSommet;
            }
            return 0;
        }
    }
    catch (const CException& e) {
        // Gestion centralisée des exceptions personnalisées
        if (e.EXCGet_Val() == 1721) {
            cerr << "Trop de parametres fournis. Un seul parametre attendu. ! Code erreur : " << e.EXCGet_Val() << endl;
        }
        else if (e.EXCGet_Val() == 1045) {
            cerr << "Choix invalide !" << endl;
        }
        else if (e.EXCGet_Val() == 1051) {
            cerr << "Erreur de saisie ! Veuillez entrer un entier valide. Code erreur : " << e.EXCGet_Val() << endl;
        }
        else if (e.EXCGet_Val() == 1052) {
            cerr << "Sommet non trouve ! Code erreur : " << e.EXCGet_Val() << endl;
        }
        else if (e.EXCGet_Val() == 2132) {
            cerr << "Aucun graphe en memoire ! Code erreur : " << e.EXCGet_Val() << endl;
        }
        else if (e.EXCGet_Val() == 2133) {
            cerr << "Operation impossible sur un graphe oriente ! Code erreur : " << e.EXCGet_Val() << endl;
        }
        else if (e.EXCGet_Val() == 2212) {
            cerr << "Operation impossible sur un graphe non oriente ! Code erreur : " << e.EXCGet_Val() << endl;
        }
        else {
            cerr << "Une exception a ete levee : Code " << e.EXCGet_Val() << endl;
        }
        return 1;
    }
}