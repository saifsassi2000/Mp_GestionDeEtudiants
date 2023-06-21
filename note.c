#include <stdio.h>
#include <stdlib.h>
#include "note.h"
void ajouter(FILE* catalogue , FILE* fichier)
{
    etudiant a;
    printf("\n -> nom : ");
    scanf("%s",a.nom);
    printf("\n -> prenom : ");
    scanf("%s",a.prenom);
    printf("\n -> L'identifiant : ");
    scanf("%s",a.id);
    printf("\n -> Les notes : ");
    printf("\n ->DS :");
    scanf("%f",a.notes.DS);
    printf("\n ->TP :");
    scanf("%.2f",a.notes.TP);
    printf("\n ->EXAMEN :");
    scanf("%.2f",a.notes.EXAMEN);
     
    if((fichier = fopen(a.nom, "wb")) != NULL)
    {
        fwrite(&a, sizeof(etudiant), 1, fichier);
        fclose(fichier);
    }
    else
    {
        printf("Impossible de créer le fichier  : %s\n", a.nom);
    }
     
    if((catalogue = fopen("Catalogue", "a")) != NULL)
    {
        fprintf(catalogue, a.nom, "\n");
        fclose(catalogue);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier : Catalogue\n");
    }
     
    printf("\n\n\n > Vous avez cree l'etudiant ' %s",a.nom);
    printf("' avec succses !\n\n\n");
}
 
void afficher(FILE *fichier) 
{
    etudiant a;
    printf("Liste des etudiants :\n");
    while (fread(&a, sizeof(etudiant), 1, fichier) == 1) 
	{
        printf("Nom : %s\n",a.nom);
        printf("Prénom : %s\n",a.prenom);
        printf("ID : %d\n",a.id);
        printf("Note : %.2f\n",a.notes.DS);
        printf("Note : %.2f\n",a.notes.TP);
        printf("Note : %.2f\n",a.notes.EXAMEN);
		printf("-----------------\n");
    }
}
void rechercher(FILE *fichier,int id) 
{
    etudiant a;
    int trouve = 0;
    while (fread(&a, sizeof(etudiant), 1, fichier) == 1) 
	{
        if (a.id == id)
		{
            printf("Etudiant trouvé :\n");
            trouve = 1;
            break;
        }
    }
    if (!trouve) 
	{
        printf("Aucun étudiant avec cet nom n'a été trouvé.\n");
    }
}

void moy(FILE *fichier) 
{
    etudiant a;
    float sommeNotes = 0.00;
    int nombreEtudiants = 0;

    while (fread(&a, sizeof(etudiant), 1, fichier) == 1) 
	{
        sommeNotes += (a.notes.DS*0.15)+(a.notes.TP*0.15)+(a.notes.EXAMEN*0.7);
        nombreEtudiants++;
    }
    if (nombreEtudiants > 0) {
        float moyenne = sommeNotes / nombreEtudiants;
        printf("La moyenne des notes est : %.2f\n", moyenne);
    } else {
        printf("Aucun étudiant n'a été trouvé.\n");
    }
}
void supprimer(FILE *fichier, int idSuppression) {
    FILE *tempFichier;
    etudiant a;
    int suppressionEffectuee = 0;

    tempFichier = fopen("temp.txt", "wb");

    if (tempFichier == NULL) 
	{
        printf("Erreur lors de la création du fichier temporaire.\n");
        return;
    }
    while (fread(&a, sizeof(etudiant), 1, fichier) == 1) 
	{
        if (a.id!= idSuppression)
		{
            fwrite(&a, sizeof(etudiant), 1, tempFichier);
        } else {
            suppressionEffectuee = 1;
        }
    }
    fclose(fichier);
    fclose(tempFichier);
    remove("stock.txt");
    rename("temp.txt", "stock.txt");
    if (suppressionEffectuee) {
        printf("Etudiant supprimé avec succès.\n");
    } else {
        printf("Aucun étudiant avec cet ID n'a été trouvé.\n");
    }
}
