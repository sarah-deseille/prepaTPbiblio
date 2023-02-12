#include "biblio.h"

void init (T_Bibliotheque *ptrB)
{
  ptrB -> nbLivres = 0;  
}


int ajouterLivre(T_Bibliotheque  *ptrB)
{

    if( ptrB -> nbLivres < CAPACITE_BIBLIO){
        saisirLivre(&(ptrB -> etagere[ptrB -> nbLivres]));
        ptrB -> nbLivres++;
        return 1;
    }
    return 0;
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
    int i;

    if(ptrB -> nbLivres > 0){
        for( i = 0; i < ptrB -> nbLivres; i++)
            afficherLivre(&(ptrB -> etagere[i]));
        return 1;
    }
    return 0;
}

