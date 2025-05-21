#include "CGraph.h"
#include "CArc.h"
#include "CGraphOrient.h"
#include "CSommet.h"
#include "CException.h"
#include <vector>
#include <limits>
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
void CGraph<T>::CGraphCalcDomMin() {
    GRAD_min.clear();
    uiGRAtaille = numeric_limits<unsigned int>::max();
    set<CSommet<T>*> Ds;
    vector<CSommet<T>*> S = this->CGraphOGET_Sommet();

    // On passe la liste complète des sommets en plus
    CGraphCalcDomMinRecursive(Ds, S, S);

    cout << "Taille minimale : " << uiGRAtaille << endl;
    cout << "Ensembles dominants de taille minimale :" << endl;
    for (const auto& ensemble : GRAD_min) {
        cout << "{ ";
        for (const auto& sommet : ensemble) {
            cout << sommet->SOMGet_Id() << " ";
        }
        cout << "}" << endl;
    }
}

template <typename T>
void CGraph<T>::CGraphCalcDomMinRecursive(set<CSommet<T>*> Ds, vector<CSommet<T>*> S, const vector<CSommet<T>*>& tous) {
  
    // Vérifier la domination sur tous les sommets
    bool uitsCouv = true;
    for (CSommet<T>* s : tous) {
        bool uiCouv = false;
        if (Ds.count(s)) {
            uiCouv = true;
        }
        else {
            for (CSommet<T>* d : Ds) {
                // On ne considère qu'une seule direction pour éviter les doublons d'arêtes non orientées
                unsigned int idS = s->SOMGet_Id();
                unsigned int idD = d->SOMGet_Id();
                unsigned int minId = std::min(idS, idD);
                unsigned int maxId = std::max(idS, idD);

                for (CArc<T>* arc : this->CGraphOGET_Arc()) {
                    unsigned int arcDeb = arc->ARCGet_SomDeb()->SOMGet_Id();
                    unsigned int arcFin = arc->ARCGet_SomA()->SOMGet_Id();
                    unsigned int arcMin = std::min(arcDeb, arcFin);
                    unsigned int arcMax = std::max(arcDeb, arcFin);

                    if (arcMin == minId && arcMax == maxId) {
                        uiCouv = true;
                        break;
                    }
                }
                if (uiCouv) break;
            }
        }
        if (!uiCouv) {
            uitsCouv = false;
            break;
        }
    }
    if (uitsCouv) {
        if (Ds.size() < uiGRAtaille) {
            GRAD_min.clear();
            GRAD_min.insert(Ds);
            uiGRAtaille = Ds.size();
        }
        else if (Ds.size() == uiGRAtaille) {
            GRAD_min.insert(Ds);
        }
        return;
    }
    for (size_t iBoucle = 0; iBoucle < S.size(); ++iBoucle) {
        CSommet<T>* s = S[iBoucle];
        set<CSommet<T>*> DsNv = Ds;
        DsNv.insert(s);

        vector<CSommet<T>*> SNv = S;
        SNv.erase(SNv.begin() + iBoucle);

        CGraphCalcDomMinRecursive(DsNv, SNv, tous);
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
template class CGraph<string>;
template class CGraph<unsigned int>;
template class CGraph<long>;
template class CGraph<unsigned long>;
template class CGraph<short>;
template class CGraph<unsigned short>;