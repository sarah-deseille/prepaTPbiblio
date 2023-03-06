#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
strcpy(ptrL->emprunteur,"");
lireChaine("CODE :", (ptrL->code), MAX_CODE);
lireChaine("Editeur :", (ptrL->editeur), MAX);
//printf("entrez l'année de l'édition :");
//scanf("%d", (ptrL->annee));
}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf(" - ");
afficherChaine("EMPRUNTEUR : ", (ptrL->emprunteur));
printf(" - ");
afficherChaine("CODE : ", (ptrL->code));
printf(" - ");
afficherChaine("EDITEUR : ", (ptrL->editeur));
printf("\n");
}

