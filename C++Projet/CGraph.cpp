#include "CGraph.h"
#include "CException.h"
#include <iostream>

using namespace std;

template <typename T>
CGraph<T>::CGraph() : CGraphOrient<T>() {}

template <typename T>
CGraph<T>::CGraph(const vector<CSommet<T>*>& sommet, const vector<CArc<T>*>& arc)
    : CGraphOrient<T>(sommet, {}) {
    try {
        for (const auto& currentArc : arc) {
            if (!currentArc) {
                throw CException(4);
            }

            this->CGraphAjouterArret(currentArc);

            CArc<T> arcInverse = ARCInverserArc(*currentArc);
            this->CGraphAjouterArret(new CArc<T>(arcInverse));
        }
    }
    catch (const CException& e) {
        cerr << "Erreur lors de la construction d'un graphe non orienté : " << e.EXCGet_Val() << endl;
    }
}

template <typename T>
CGraph<T>::CGraph(const CGraph<T>& graph) : CGraphOrient<T>(graph) {}

template <typename T>
void CGraph<T>::CGraphAjouterArret(CArc<T>* Arret) {
    try {
        if (!Arret) {
            throw CException(4);
        }

        unsigned int sommetDebId = Arret->ARCGet_SomDeb()->SOMGet_Id();
        unsigned int sommetFinId = Arret->ARCGet_SomA()->SOMGet_Id();

        CSommet<T>* sommetDeb = this->CGraphOChercherSommetParId(sommetDebId);
        if (!sommetDeb) {
            sommetDeb = Arret->ARCGet_SomDeb();
            this->CGraphOAjouterSommet(sommetDeb);
        }

        CSommet<T>* sommetFin = this->CGraphOChercherSommetParId(sommetFinId);
        if (!sommetFin) {
            sommetFin = Arret->ARCGet_SomA();
            this->CGraphOAjouterSommet(sommetFin);
        }

        this->CGraphOAjouterArc(Arret);

        CArc<T> arcInverse = ARCInverserArc(*Arret);
        this->CGraphOAjouterArc(new CArc<T>(arcInverse));

        std::cout << "Arête ajoutée entre les sommets " << sommetDeb->SOMGet_Id()
            << " et " << sommetFin->SOMGet_Id() << std::endl;
    }
    catch (const CException& e) {
        std::cerr << "Erreur lors de l'ajout d'une arête : " << e.EXCGet_Val() << std::endl;
    }
}

template <typename T>
void CGraph<T>::CGraphModifierArret(CArc<T>* ArretActuel, CArc<T>* NouvelArret) {
    try {
        if (!ArretActuel || !NouvelArret) {
            throw CException(4);
        }

        CGraphSupprimerArret(ArretActuel);
        CGraphAjouterArret(NouvelArret);

        cout << "Arête modifiée avec succès." << endl;
    }
    catch (const CException& e) {
        cerr << "Erreur lors de la modification d'une arête : " << e.EXCGet_Val() << endl;
    }
}

// Méthode pour supprimer une arête existante
template <typename T>
void CGraph<T>::CGraphSupprimerArret(CArc<T>* Arret) {
    try {
        if (!Arret) {
            throw CException(4);
        }

        unsigned int sommetDebId = Arret->ARCGet_SomDeb()->SOMGet_Id();
        unsigned int sommetFinId = Arret->ARCGet_SomA()->SOMGet_Id();

        CArc<T> arcInverse = ARCInverserArc(*Arret);

        auto& arcs = this->CGraphOGET_Arc();
        arcs.erase(remove_if(arcs.begin(), arcs.end(),
            [&Arret, &arcInverse](CArc<T>* arc) {
                return (*arc == *Arret || *arc == arcInverse);
            }),
            arcs.end());

        cout << "Arête supprimée entre les sommets " << sommetDebId
            << " et " << sommetFinId << std::endl;
    }
    catch (const CException& e) {
        cerr << "Erreur lors de la suppression d'une arête : " << e.EXCGet_Val() << endl;
    }
}

template <typename T>
void CGraph<T>::CGraphAfficher() {
    cout << "=== Affichage du Graphe Non Orienté ===" << endl;

    if (this->CGraphOGET_Arc().empty()) {
        cout << "Le graphe ne contient aucune arête." << endl;
    }
    else {
        cout << "Relations entre sommets (arêtes) :" << endl;
        for (const auto& arc : this->CGraphOGET_Arc()) {
            CSommet<T>* sommetDebut = arc->ARCGet_SomDeb();
            CSommet<T>* sommetFin = arc->ARCGet_SomA();

            if (sommetDebut && sommetFin) {
                cout << "Sommet(" << sommetDebut->SOMGet_Id() << ") <-----> Sommet("
                    << sommetFin->SOMGet_Id() << ")" << endl;
            }
            else {
                cout << "Arête invalide (sommets manquants)." << endl;
            }
        }
    }

    cout << "=== Fin de l'Affichage ===" << endl;
}