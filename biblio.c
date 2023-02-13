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

    int chercherlivre(T_Bibliotheque *ptrB, int nbLivres, T_Titre titre1){
        
        int i=0;
        //printf("%d", i);
        if(ptrB -> nbLivres <= 0){
            return -1;
        }
        //printf("%d", i);
        nbLivres ++;
        while (i<nbLivres ){ 
            if(strcmp( (ptrB->etagere)[i].titre, titre1)==0){
                return i;
                }
        i++;
        }
        //printf("%d", i);
        return -2;
        
    }

	void chercherauteur (const T_Bibliotheque  *ptrB, T_Aut *auteur){
        int i;
        for(i=0;i<(ptrB->nbLivres);i++){
            if (strcmp(ptrB->etagere[i].auteur, *auteur)==0){
                printf("le livre est trouvé :");
                afficherLivre(&(ptrB->etagere[i]));
            }
        }


    }



    int supprimer(T_Bibliotheque *ptrB, T_Titre *titre){
        int i = 0;

        for( i = 0; i <= (ptrB->nbLivres); i++){ //cas limite 
            if(strcmp(ptrB->etagere[i].titre, *titre) == 0){ //on regarde si le titre du livre a supprimé est présent
                ptrB->etagere[i] = ptrB->etagere[ptrB->nbLivres-1]; //on supprime la case
                ptrB->nbLivres--;
                return 1;
            }
        }
        return 0;   
    }

    void sauvegarde(T_Bibliotheque *ptrB)
    {
    FILE *fic=NULL; //le type FILE
    int i;
    fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
    //fopen renvoie NULL si probleme (disque plein, disque non accessible ...
    if (fic!=NULL)
        {
        for(i=0;i<ptrB->nbLivres;i++)
            {
    //fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
        fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

            }
        fclose(fic);
        puts("SAUVEGARDE REUSSIE ..............");



        }
        else puts("ECHEC DE SAUVEGARDE  !!!!!  ");




    }



    void chargement(T_Bibliotheque *ptrB)
    {
    FILE *fic=NULL; //le type FILE
    int i=0;
    fic=fopen("baseLivres","r"); // r = le mode read
    printf(">%p<\n",fic);
    //fopen renvoie NULL si probleme (disque plein, disque non accessible ...
    if (fic!=NULL)
        {
        do
            {

            fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
            i++;
            }
            while(!feof(fic));
        fclose(fic);
        ptrB->nbLivres=i-1;
        puts("CHARGEMENT  REUSSI ..............");
        }
        else puts("ECHEC DE CHARGEMENT  !!!!!  ");

    }


    void lectureFichierTXT()
    {
    int M=100;
    FILE *fic=NULL; //le type FILE
    char chaine[M];
    char chaine2[M];
    char c;
    fic=fopen("fic.txt","rt"); // r = le mode read   w = mode write (avec ecrasement)
    //fopen renvoie NULL si probleme (fichier effac� , disque non accessible ...
    if (fic!=NULL)
        {
        do
            {
            //fgets(chaine,M,fic);   //fputs pour �crire dans un fichier txt
            //fscanf(fic,"%s",chaine); //fprintf pour �crire dans un fichier txt
        //	fscanf(fic,"%s %s",chaine,chaine2);
            fscanf(fic,"%c",&c);
            //fscanf(fic,"%c",&chaine[0]);
        //	if (!feof(fic))
            //printf("\n\t >%s--%s<",chaine,chaine2);
            printf(">%c<",c);
            }
        while(!feof(fic));
        fclose(fic);
        puts("\nLECTURE REUSSIE ..............");
        }
        else puts("ECHEC DE LECTURE DU FICHIER TXT !!!!!  ");
    }

