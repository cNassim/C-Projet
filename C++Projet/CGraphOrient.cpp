#include "CArc.h"
#include "CSommet.h"
#include "CException.h"
#include "CGraphOrient.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

template<typename T>
CGraphOrient<T>::CGraphOrient() : GRASom(), GRAArc() {
}

template <typename T>
CGraphOrient<T>::CGraphOrient(const vector<CSommet<T>*>& pSommet, const vector<CArc<T>*>& pArc)
    : GRASom(pSommet), GRAArc(pArc) {
    try {
        for (auto& Arc : GRAArc) {
            if (!Arc) {
                throw CException(1);
            }
            if (!Arc->ARCGet_SomDeb() || !Arc->ARCGet_SomA()) {
                throw CException(2);
            }
        }
        for (auto& Arc : GRAArc) {
            bool sommet1Existe = false;
            bool sommet2Existe = false;

            for (auto& sommet : GRASom) {
                if (sommet == Arc->ARCGet_SomDeb()) {
                    sommet1Existe = true;
                }
                if (sommet == Arc->ARCGet_SomA()) {
                    sommet2Existe = true;
                }
            }

            if (!sommet1Existe || !sommet2Existe) {
                throw CException(3);
            }
        }
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 1) {
            cerr << "Erreur : Un arc est nul dans le constructeur !" << endl;
        }
        else if (e.EXCGet_Val() == 2) {
            cerr << "Erreur : Un arc contient des sommets invalides !" << endl;
        }
        else if (e.EXCGet_Val() == 3) {
            cerr << "Erreur : Un ou les deux sommets de l'arc n'existent pas !" << endl;
        }
        else {
            cerr << "Erreur inconnue lors de la construction du graphe !" << endl;
        }
    }
}

template <typename T>
CGraphOrient<T>::CGraphOrient(const CGraphOrient& GraphOrient)
    : GRASom(), GRAArc() {
    try {

        for (auto& sommet : GraphOrient.GRASom) {
            CSommet<T>* pNewSommet = new CSommet<T>(*sommet);
            GRASom.push_back(pNewSommet);
        }

        for (auto& arc : GraphOrient.GRAArc) {
            CArc<T>* pNewArc = new CArc<T>(*arc);
            GRAArc.push_back(pNewArc);
        }
    }
    catch (const CException& e) {
        cerr << "Erreur lors de la copie du graphe ! Code erreur : " << e.EXCGet_Val() << endl;
    }
}

template <typename T>
CGraphOrient<T>::~CGraphOrient() {
    GRASom.clear();
    GRAArc.clear();
}

template <typename T>
void CGraphOrient<T>::CGraphOAjouterSommet(CSommet<T>* pSom) {
    try {
        if (pSom) {
            for (const auto& s : GRASom) {
                if (s == pSom) {
                    throw CException(6);
                }
            }
            GRASom.push_back(pSom);
        }
        else {
            throw CException(3);
        }
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 3) {
            cerr << "Erreur : Sommet nul" << endl;
        }
        else if (e.EXCGet_Val() == 6) {
            cerr << "Erreur : Le sommet existe deja dans le graphe" << endl;
        }
        else {
            cerr << "Erreur inconnue" << endl;
        }
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOAjouterArc(CArc<T>* pArc) {
    try {
        if (!pArc) {
            throw CException(4);
        }
        for (const auto& a : GRAArc) {
            if (*a == *pArc) {
                throw CException(6);
            }
        }
        if (GRASom.empty() && GRAArc.empty()) {
            GRASom.push_back(pArc->ARCGet_SomDeb());
            GRASom.push_back(pArc->ARCGet_SomA());
            GRAArc.push_back(pArc);
        }
        else {
            bool sommet1Existe = false;
            bool sommet2Existe = false;

            for (auto& sommet : GRASom) {
                if (sommet == pArc->ARCGet_SomDeb()) {
                    sommet1Existe = true;
                }
                if (sommet == pArc->ARCGet_SomA()) {
                    sommet2Existe = true;
                }
            }
            if (sommet1Existe && !sommet2Existe) {
                GRASom.push_back(pArc->ARCGet_SomA());
                GRAArc.push_back(pArc);
            }
            else if (!sommet1Existe && sommet2Existe) {
                GRASom.push_back(pArc->ARCGet_SomDeb());
                GRAArc.push_back(pArc);
            }
            else if (!sommet1Existe && !sommet2Existe) {
                throw CException(5);
            }
            else {
                GRAArc.push_back(pArc);
            }
        }
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 4) {
            cerr << "Erreur : L'arc est nul !" << endl;
        }
        else if (e.EXCGet_Val() == 5) {
            cerr << "Erreur : Aucun des deux sommets n'existe dans le graphe !" << endl;
        }
        else if (e.EXCGet_Val() == 6) {
            cerr << "Erreur : L'arc existe deja dans le graphe !" << endl;
        }
        else {
            cerr << "Erreur inconnue lors de l'ajout de l'arc !" << endl;
        }
    }
}

template <typename T>
vector<CSommet<T>*> CGraphOrient<T>::CGraphOGET_Sommet() const {
    return GRASom;
}

template <typename T>
const vector<CArc<T>*> CGraphOrient<T>::CGraphOGET_Arc() const {
    return GRAArc;
}

template <typename T>
vector<CArc<T>*>& CGraphOrient<T>::CGraphOGET_Arc() {
    return GRAArc;
}

template <typename T>
void CGraphOrient<T>::CGraphOModifierSommet(unsigned int uiIdsom, CSommet<T>* pNouveauSommet) {
    try {
        if (!pNouveauSommet) {
            throw CException(6);
        }

        CSommet<T>* pAncienSommet = CGraphOChercherSommetParId(uiIdsom);
        if (!pAncienSommet) {
            throw CException(7);
        }

        for (auto& arc : GRAArc) {
            if (arc->ARCGet_SomDeb() == pAncienSommet) {
                arc->ARCModifierSomDeb(pNouveauSommet);
            }
            if (arc->ARCGet_SomA() == pAncienSommet) {
                arc->ARCModifierSomA(pNouveauSommet);
            }
        }

        for (auto& sommet : GRASom) {
            if (sommet == pAncienSommet) {
                sommet = pNouveauSommet;
                return;
            }
        }
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 6) {
            cerr << "Erreur : Sommet invalide (nullptr)." << endl;
        }
        else if (e.EXCGet_Val() == 7) {
            cerr << "Erreur : Sommet avec l'ID " << uiIdsom << " non trouve." << endl;
        }
        else {
            cerr << "Erreur inconnue lors de la modification du sommet." << endl;
        }
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOModifierArc(CArc<T>* pArcToModify, CArc<T>* pNewArc) {
    try {
        if (!pNewArc) {
            throw CException(8);
        }

        for (auto& arc : GRAArc) {
            if (*arc == *pArcToModify) {
                arc = pNewArc;
                return;
            }
        }

        throw CException(9);
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 8) {
            cerr << "Erreur : Arc invalide" << endl;
        } else{
            cerr << "Erreur : Arc non trouve" << endl;
        }
    }
}

template <typename T>
void CGraphOrient<T>::CGraphOSupprimerSommet(unsigned int uiIdsom) {
    try {
        CSommet<T>* pSommetASupprimer = CGraphOChercherSommetParId(uiIdsom);
        if (!pSommetASupprimer) {
            throw CException(10);
        }

        for (auto it = GRAArc.begin(); it != GRAArc.end(); ) {
            if ((*it)->ARCGet_SomDeb() == pSommetASupprimer || (*it)->ARCGet_SomA() == pSommetASupprimer) {
                it = GRAArc.erase(it);
            }
            else {
                ++it;
            }
        }
        auto it = find(GRASom.begin(), GRASom.end(), pSommetASupprimer);
        if (it != GRASom.end()) {
            GRASom.erase(it);
        }
    }
    catch (const CException& e) {
        if (e.EXCGet_Val() == 10) {
            cerr << "Erreur : Sommet avec l'ID " << uiIdsom << " non trouve." << endl;
        }
        else {
            cerr << "Erreur inconnue lors de la suppression du sommet." << endl;
        }
    }
}


template <typename T>
void CGraphOrient<T>::CGraphOSupprimerArc(CArc<T>* pArcToDelete) {
    for (auto it = GRAArc.begin(); it != GRAArc.end(); ++it) {
        if (*it == pArcToDelete) {
            GRAArc.erase(it);
            return;
        }
    }
}

template <typename T>
CSommet<T>* CGraphOrient<T>::CGraphOChercherSommetParId(unsigned int uiIdsom) const {
    for (auto& sommet : GRASom) {
        if (sommet->SOMGet_Id() == uiIdsom) {
            return sommet;
        }
    }
    return nullptr;
}


template <typename T>
CGraphOrient<T>* CGraphOrient<T>::CGraphOLireFichier(const string& sNomFichier) {
    try {
        ifstream fichier(sNomFichier);
        if (!fichier.is_open()) {
            throw CException(1001); // Erreur : Fichier introuvable
        }

        string sLigne;
        int iNbSommets = 0;
        int iNbArcs = 0;
        vector<CSommet<T>*> pSommets;
        vector<CArc<T>*> pArcs;

        while (getline(fichier, sLigne)) {
            // Supprimer les espaces inutiles autour de la sLigne
            sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end());

            if (sLigne.find("NBSommets=") != string::npos) {
                string sVal = sLigne.substr(sLigne.find("=") + 1);
                if (!std::all_of(sVal.begin(), sVal.end(), ::isdigit)) {
                    throw CException(2001); // Format invalide pour NBSommets
                }
                iNbSommets = std::stoi(sVal);
                if (iNbSommets <= 0) {
                    throw CException(2001); // NBSommets doit être un entier positif
                }
            }
            else if (sLigne.find("NBArcs=") != string::npos) {
                string sVal = sLigne.substr(sLigne.find("=") + 1);
                if (!std::all_of(sVal.begin(), sVal.end(), ::isdigit)) {
                    throw CException(2002); // Format inValide pour NBArcs
                }
                iNbArcs = std::stoi(sVal);
                if (iNbArcs < 0) {
                    throw CException(2002); // NBArcs doit être un entier positif ou nul
                }
            }
            else if (sLigne.find("Sommets=[") != string::npos) {
                while (getline(fichier, sLigne) && sLigne.find("]") == string::npos) {
                    sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end());
                    if (sLigne.find("Numero=") != string::npos) {
                        string sVal = sLigne.substr(sLigne.find("=") + 1);
                        if (!std::all_of(sVal.begin(), sVal.end(), ::isdigit)) {
                            throw CException(2003); // Format insValide pour un sommet
                        }
                        int numero = std::stoi(sVal);
                        if (numero <= 0) {
                            throw CException(2003); // Numero doit être un entier positif
                        }
                        pSommets.push_back(new CSommet<T>(numero, {}, {}));
                    }
                    else {
                        throw CException(2004); // Ligne inattendue dans Sommets
                    }
                }
                if (sLigne.find("]") == string::npos) {
                    throw CException(2004); // Section Sommets mal fermée
                }
            }
            else if (sLigne.find("Arcs=[") != string::npos) {
                while (getline(fichier, sLigne) && sLigne.find("]") == string::npos) {
                    sLigne.erase(remove(sLigne.begin(), sLigne.end(), ' '), sLigne.end());
                    if (sLigne.find("Debut=") != string::npos && sLigne.find("Fin=") != string::npos) {
                        string sDebutStr = sLigne.substr(sLigne.find("Debut=") + 6, sLigne.find(",") - 6);
                        string sFinStr = sLigne.substr(sLigne.find("Fin=") + 4);
                        if (!std::all_of(sDebutStr.begin(), sDebutStr.end(), ::isdigit) || !std::all_of(sFinStr.begin(), sFinStr.end(), ::isdigit)) {
                            throw CException(2005); // Format inValide pour un arc
                        }
                        int iDebut = std::stoi(sDebutStr);
                        int iFin = std::stoi(sFinStr);

                        CSommet<T>* pSommetDebut = nullptr;
                        CSommet<T>* pSommetFin = nullptr;
                        for (auto& sommet : pSommets) {
                            if (sommet->SOMGet_Id() == iDebut) {
                                pSommetDebut = sommet;
                            }
                            if (sommet->SOMGet_Id() == iFin) {
                                pSommetFin = sommet;
                            }
                        }
                        if (pSommetDebut && pSommetFin) {
                            pArcs.push_back(new CArc<T>(pSommetDebut, pSommetFin));
                        }
                        else {
                            throw CException(1003); // Sommet introuvable
                        }
                    }
                    else {
                        throw CException(2006); // Ligne inattendue dans Arcs
                    }
                }
                if (sLigne.find("]") == string::npos) {
                    throw CException(2006); // Section Arcs mal fermée
                }
            }
            else if (!sLigne.empty()) {
                // Ligne inattendue en dehors des sections définies
                throw CException(2007);
            }
        }

        fichier.close();

        // Vérification des totaux
        if (static_cast<int>(pSommets.size()) != iNbSommets) {
            throw CException(2008); // Nombre de sommets incorrect
        }
        if (static_cast<int>(pArcs.size()) != iNbArcs) {
            throw CException(2009); // Nombre d'arcs incorrect
        }

        return new CGraphOrient<T>(pSommets, pArcs);
    }
    catch (const CException& e) {
        cerr << "Erreur (Code " << e.EXCGet_Val() << ") : ";
        switch (e.EXCGet_Val()) {
        case 1001:
            cerr << "Impossible d'ouvrir le fichier." << endl;
            break;
        case 1003:
            cerr << "Sommet introuvable lors de la creation d'un arc." << endl;
            break;
        case 2001:
            cerr << "Format inValide pour le nombre de sommets (NBSommets)." << endl;
            break;
        case 2002:
            cerr << "Format invalide pour le nombre d'arcs (NBArcs)." << endl;
            break;
        case 2003:
            cerr << "Format invalide pour un sommet dans la section Sommets." << endl;
            break;
        case 2004:
            cerr << "Ligne inattendue dans la section Sommets." << endl;
            break;
        case 2005:
            cerr << "Format invalide pour un arc dans la section Arcs." << endl;
            break;
        case 2006:
            cerr << "Ligne inattendue dans la section Arcs." << endl;
            break;
        case 2007:
            cerr << "Ligne inattendue en dehors des sections definies." << endl;
            break;
        case 2008:
            cerr << "Le nombre de sommets ne correspond pas à la declaration (NBSommets)." << endl;
            break;
        case 2009:
            cerr << "Le nombre d'arcs ne correspond pas à la declaration (NBArcs)." << endl;
            break;
        default:
            cerr << "Erreur inconnue." << endl;
            break;
        }
        return nullptr;
    }
}

template <typename T>
CGraphOrient<T>* CGraphOrient<T>::CGraphOInverse() const {
    CGraphOrient<T>* pGrapheInverse = new CGraphOrient<T>();
    for (CSommet<T>* pSommet : GRASom) {
        pGrapheInverse->CGraphOAjouterSommet(new CSommet<T>(pSommet->SOMGet_Id(), {}, {}));
    }
    for (CArc<T>* pArc : GRAArc) {
        CSommet<T>* pSommetDebut = pGrapheInverse->CGraphOChercherSommetParId(pArc->ARCGet_SomA()->SOMGet_Id());
        CSommet<T>* pSommetFin = pGrapheInverse->CGraphOChercherSommetParId(pArc->ARCGet_SomDeb()->SOMGet_Id());
        if (!pSommetDebut || !pSommetFin) {
            cerr << "Erreur : Sommets manquants dans l'arc." << std::endl;
            continue;
        }

        CArc<T>* pArcInverse = new CArc<T>(pSommetDebut, pSommetFin);
        pGrapheInverse->CGraphOAjouterArc(pArcInverse);
    }
    return pGrapheInverse;
}

template <typename T>
void CGraphOrient<T>::CGraphOAfficher() const {
    cout << "=== Affichage du Graphe Oriente ===" << endl;
    cout << "Nombre d'arcs : " << GRAArc.size() << endl;

    if (GRAArc.empty()) {
        cout << "Le graphe ne contient aucun arc." << endl;
    }
    else {
        cout << "Relations entre sommets :" << endl;
        for (const auto& arc : GRAArc) {
            CSommet<T>* psommetDebut = arc->ARCGet_SomDeb();
            CSommet<T>* psommetFin = arc->ARCGet_SomA();

            if (psommetDebut && psommetFin) {
                cout << "Sommet(" << psommetDebut->SOMGet_Id() << ") -----> Sommet(" << psommetFin->SOMGet_Id() << ")" << endl;
            }
            else {
                cout << "Arc invalide (sommets manquants)." << endl;
            }
        }
    }

    cout << "=== Fin de l'Affichage ===" << endl;
}

template class CGraphOrient<int>;
template class CGraphOrient<float>;
template class CGraphOrient<double>;
template class CGraphOrient<char>;
template class CGraphOrient<bool>;
template class CGraphOrient<string>;
template class CGraphOrient<unsigned int>;
template class CGraphOrient<long>;
template class CGraphOrient<unsigned long>;
template class CGraphOrient<short>;
template class CGraphOrient<unsigned short>;