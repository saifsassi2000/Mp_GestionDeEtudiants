#ifndef NOTE_H //header guard
#define NOTE_H
#define NOTE_H

struct note
{
	float DS;
	float TP;
	float EXAMEN;
};
typedef struct note note;

struct etudiant
{
	char nom[20];
	char prenom[20];
	char id[20];
	note notes;
};
typedef struct etudiant etudiant;
#endif
