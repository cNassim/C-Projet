#include "CGraph.h"
#include "CArc.h"
#include "CGraphOrient.h"
#include "CSommet.h"
#include "CException.h"
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
CGraph<T>::CGraph() : CGraphOrient<T>() {}

template <typename T>
CGraph<T>::CGraph(const vector<CSommet<T>*>& Sommet, const vector<CArc<T>*>& Arc)
    : CGraphOrient<T>(Sommet, {}) {
    try {
        for (const auto& currentArc : Arc) {
            if (!currentArc) {
                throw CException(4);
            }

            this->CGraphAjouterArret(currentArc);

            CArc<T> ARCInverse = CArc<T>::ARCInverserArc(*currentArc);
            this->CGraphAjouterArret(new CArc<T>(ARCInverse));
        }
    }
    catch (const CException& e) {
        cerr << "Erreur lors de la construction d'un graphe non oriente : " << e.EXCGet_Val() << endl;
    }
}

template <typename T>
CGraph<T>::CGraph(const CGraph<T>& graph) : CGraphOrient<T>(graph) {}

template <typename T>
CGraph<T>::~CGraph() {}

template <typename T>
void CGraph<T>::CGraphAjouterArret(CArc<T>* pArret) {
    try {
        if (!pArret) {
            throw CException(4);
        }

        unsigned int uiSommetDebId = pArret->ARCGet_SomDeb()->SOMGet_Id();
        unsigned int uiSommetFinId = pArret->ARCGet_SomA()->SOMGet_Id();

        CSommet<T>* pSommetDeb = this->CGraphOChercherSommetParId(uiSommetDebId);
        if (!pSommetDeb) {
            pSommetDeb = pArret->ARCGet_SomDeb();
            this->CGraphOAjouterSommet(pSommetDeb);
        }

        CSommet<T>* pSommetFin = this->CGraphOChercherSommetParId(uiSommetFinId);
        if (!pSommetFin) {
            pSommetFin = pArret->ARCGet_SomA();
            this->CGraphOAjouterSommet(pSommetFin);
        }

        this->CGraphOAjouterArc(pArret);

        CArc<T> ARCInverse = CArc<T>::ARCInverserArc(*pArret);
        this->CGraphOAjouterArc(new CArc<T>(ARCInverse));

    }
    catch (const CException& e) {
        cerr << "Erreur lors de l'ajout d'une arete : " << e.EXCGet_Val() << endl;
    }
}

template <typename T>
void CGraph<T>::CGraphModifierArret(CArc<T>* pArretActuel, CArc<T>* pNouvelArret) {
    try {
        if (!pArretActuel || !pNouvelArret) {
            throw CException(4);
        }

        CGraphSupprimerArret(pArretActuel);
        CGraphAjouterArret(pNouvelArret);

    }
    catch (const CException& e) {
        cerr << "Erreur lors de la modification d'une arete : " << e.EXCGet_Val() << endl;
    }
}


template <typename T>
void CGraph<T>::CGraphSupprimerArret(CArc<T>* pArret) {
    try {
        if (!pArret) {
            throw CException(4);
        }
        unsigned int uiSommetDebId = pArret->ARCGet_SomDeb()->SOMGet_Id();
        unsigned int uiSommetFinId = pArret->ARCGet_SomA()->SOMGet_Id();

        CArc<T> ARCInverse = CArc<T>::ARCInverserArc(*pArret);

        auto& arcs = this->CGraphOGET_Arc();
        arcs.erase(remove_if(arcs.begin(), arcs.end(),
            [&pArret, &ARCInverse](CArc<T>* pArc) {
                return (*pArc == *pArret || *pArc == ARCInverse);
            }),
            arcs.end());
    }
    catch (const CException& e) {
        cerr << "Erreur lors de la suppression d'une arete : " << e.EXCGet_Val() << endl;
    }
}



template <typename T>
void CGraph<T>::CGraphAfficher() {
    cout << "=== Affichage du Graphe Non Oriente ===" << endl;
    if (this->CGraphOGET_Arc().empty()) {
        cout << "Le graphe ne contient aucune arete." << endl;
    }
    else {
        cout << "Relations entre sommets (aretes) :" << endl;
        vector<CArc<T>*> pArcsAffiches;
        for (const auto& arc : this->CGraphOGET_Arc()) {
            bool dejaAffiche = false;
            for (const auto& arcAffiche : pArcsAffiches) {
                if ((arcAffiche->ARCGet_SomDeb() == arc->ARCGet_SomDeb() &&
                    arcAffiche->ARCGet_SomA() == arc->ARCGet_SomA()) ||
                    (arcAffiche->ARCGet_SomDeb() == arc->ARCGet_SomA() &&
                        arcAffiche->ARCGet_SomA() == arc->ARCGet_SomDeb())) {
                    dejaAffiche = true;
                    break;
                }
            }
            if (!dejaAffiche) {
                CSommet<T>* pSommetDebut = arc->ARCGet_SomDeb();
                CSommet<T>* pSommetFin = arc->ARCGet_SomA();

                if (pSommetDebut && pSommetFin) {
                    cout << "Sommet(" << pSommetDebut->SOMGet_Id() << ") <-----> Sommet("
                        << pSommetFin->SOMGet_Id() << ")" << endl;
                    pArcsAffiches.push_back(arc);
                }
                else {
                    cout << "Arete invalide (sommets manquants)." << endl;
                }
            }
        }
    }
    cout << "=== Fin de l'Affichage ===" << endl;
}

template class CGraph<int>;
template class CGraph<float>;
template class CGraph<double>;
template class CGraph<char>;
template class CGraph<bool>;
template class CGraph<std::string>;
template class CGraph<unsigned int>;
template class CGraph<long>;
template class CGraph<unsigned long>;
template class CGraph<short>;
template class CGraph<unsigned short>;