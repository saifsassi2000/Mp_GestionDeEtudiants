#include <stdio.h>
#include <stdlib.h>
#include "note.h"
int main() 
{
	etudiant a;
	int i,id,n;
    FILE* catalogue = NULL;
	FILE* fichier = NULL;
    int choix,retour=0;
    char* chaine = NULL;
    if((chaine = (char*)calloc(21, sizeof(char))) == NULL)
    {
        printf("Impossible d'allouer la variable chaine\n");
        exit(EXIT_FAILURE);
    }
	/*printf("Donnez le nombre des etudiants :\t");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{*/
		
		do {
			if (retour==0)
        		printf("\n"); 
        	retour = 0;
        	printf("\n\n-------------- Menu --------------\n\n\n\n\n");
        	printf("1) Ajouter un etudiant :\n\n");
     	    printf("2) Consulter la liste des etudiants :\n\n");
     	    printf("3) Rechercher un etudiant :\n\n");
    	    printf("4) Supprimer un etudiant :\n\n");
    	    printf("5) Calculer la moyenne de la classe :\n\n");
    	    printf("0) Quitter\n\n");
    	    printf("\n\n\n\n --> Votre choix ? : ");
    	    scanf("%d",&choix);
    	    switch (choix)
	        {
	        	case 1:
    	            ajouter(catalogue,fichier);
        	        system("PAUSE");
            	    retour = 1;
                	break;        		
	        	case 2:
    	            afficher(fichier);
        	        system("PAUSE");
            	    retour = 1;
                	break;        		
	        	case 3:
	        		printf("Donnez l'identifiant de l'etudiant :");
	        		scanf("%s\n%s",id);
    	    		rechercher(fichier,id);
        			system("PAUSE");
        			retour=1;
        			break;
	        	case 4:
    	            supprimer(fichier,id);
        	        system("PAUSE");
            	    retour = 1;
                	break;
		        default:
    	            printf("\n >>> Choix Invalide ! <<< \n");
        	        retour = 1;
            	    break;        		
	        	case 5:
    	    		moy(fichier);
    	    		retour = 1;
    	    		break;
        		case 0:
            	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                	system("PAUSE");
                	exit(0);
                	break;   		
			}
		}   
     while ((choix<0 && choix>3) || retour==1);
	return 0;
}

