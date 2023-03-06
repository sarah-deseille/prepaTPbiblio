// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"

int menu()
{
	int choix;
	
// au programme du TP7 :
printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
printf("\n 2 - afficher tous les livres de la bibliotheque "); 
printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)


// au programme du TP8 :
// ajouter le champ emprunteur à votre structure T_Livre

printf("\n 6 - emprunter un livre de la bibliotheque");
printf("\n 7 - restituer/rendre un livre de la bibliotheque");
printf("\n 8 - trier les livres (par titre)");
printf("\n 9 - trier les livres (par auteur)");
printf("\n 10 - trier les livres (par annee)");

// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
// printf("\n 11- lister les livres disponibles "); 
// printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
// printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ")

printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d[^\n]",&choix);getchar();
return choix;


}



int main()
{
int reponse=-2,chx;
int reponse1;
char nom[60], aut[60];
char s[60];
char emp[60];
T_Aut auteur;
T_Bibliotheque B; 
init( &B );
chargement(&B);
do
{
chx= menu();
switch(chx)
	{
	case  1 : reponse = ajouterLivre(   &B  );
				if (reponse==1)
					printf(" ajout reussi !!");
					else
					printf("impossible d ajouter (bibliotheque pleine)");
			break;
	case 2 : reponse=afficherBibliotheque(&B);
			if (reponse==0)	
					printf("La bibliotheque est vide");

			break;	
	case 3 : 
			printf("entrez le titre a chercher :");
			lire(s,MAX_TITRE);
			//printf("%s", s);
			reponse=chercherlivre(&B,CAPACITE_BIBLIO, s);
			//printf("%d", reponse);
			switch(reponse){
				case -1 :
					printf("la biblioteque est vide");
					break;
				case -2 :
					printf("le livre n'est pas trouvé");
					break;

				default :
					printf("le livre est trouvé");
			}
			break;
	case 4 :printf("enterz un auteur a chercher:");
			lireChaine("",auteur,K_MaxAut);
			chercherauteur(&B, auteur);
			break;

	case 5 :printf("veuillez entrer un titre à supprimer :");
			scanf("%s", s);
			reponse = supprimer(&B, &s);
			if(reponse == 1){
			 	printf("la suppression a été faite ");
			}
			else{
				printf("la supression a échoué");
			}
				
			break;

	case 6 :
			printf("quel livre voulez vous emprunter(titre) ?");
			lireChaine("",s,K_MaxTit);
			printf("quel est l'auteur du livre que vous voulez empreinter ?");
			lireChaine("",aut,K_MaxAut);
			int res=empreinter(&B,aut, s);
			// -1: trouvé mais empreinté
			// -2 non trouvé
			// else position du livre dans etagere


			switch(res){
				case -1 :
					printf("le livre est deja emprunté\n");
					break;
				case -2 :
					printf("le livre n'est pas dans la bibliotéque\n");
					break;

				default :
					printf("le livre est trouvé\n");
					printf("vous pouvez emprunter le livre\n");
					printf("quel est votre nom d'emprunteur ?\n");
					scanf("%s[^\n]", emp);
					getchar();
					strcpy((B.etagere[res].emprunteur),emp);
					printf("L'empreinteur est : %s\n",B.etagere[res].emprunteur );
			}
			break;
	case 7 :
			printf("quel livre voulez vous rendre(titre) ?");
			lireChaine("",s,K_MaxTit);
			printf("quel est l'auteur du livre que vous voulez rendre ?");
			lireChaine("",aut,K_MaxAut);

			if(empreinter(&B,aut,s) == -1){
				rendreLivre(&B, aut, s);
			}
			else{
				printf("le livre n'est pas emprunter\n");
			}
			break;
	case 8 : 
		    trieTitre(&B);
			break;
	}		
	

	}while(chx!=0);
sauvegarde(&B);


return 0;
}
