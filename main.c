#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


// Les structures necessaire
typedef struct {
	char nom[10];
	char pre[10]; 
	int nump;
}Prof;

typedef struct {
    char nom[10];
	char pre[10]; 
	int nume;
}Etd;

typedef struct {
    char nom[10]; 
	int numM;
}Mat;

typedef struct {
    Mat mat;
    Etd etud;
    //int numN;
	
}Niv;

typedef struct {
	Prof *tp;
	Niv tn[100][5];
    int np;
	int nE;
    int nM;
    int numN;
}Etab;

// Rechercher un Prof par son numero
int     FindProf(Etab *e, int v)
{
	int i;
	for(i=0;i<e->np;i++)
	{
		if(v==e->tp[i].nump)
		{
			return i;
		}
	}
	return -1;
}

// Rechercher un Etudiant par son numero
int     FindEt(Etab *e, int v)
{
	int i;
	for(i=0;i<e->nE;i++)
	{
		if(v==e->tn[i][e->numN].etud.nume)
		{
			return i;
		}
	}
	return -1;
}

// Rechercher une matiere par son numero
int     FindMat(Etab *e, int v)
{
	int i;
	for(i=0;i<e->nM;i++)
	{
		if(v==e->tn[i][e->numN].mat.numM)
		{
			return i;
		}
	}
	return -1;
}

/* 

    La phase MENU

*/


// MENU PRINCIPALE
void    menu()
{
	system("cls");
    printf("---------- MENU PRINCIPALE ----------\n\n 1-MENU PROF\n 2-MENU NIVEAU\n 3-Save/Load\n 4-QUITTER\n\n Votre choix --> ");
}

// MENU PROF
void    menuPr()
{
	system("cls");
	printf("---------- MENU PROF ----------\n\n 1-Ajouter Prof\n 2-Modifier Prof\n 3-Supprimer Prof\n 4-Afficher les Profs dispo \n 5-Retour \n\n Votre choix --> ");
}

// MENU NIVEAU
void    menuNv() {
    system("cls");
    printf("---------- MENU NIVEAU ----------\n\n 1-MENU ETUDIANT\n 2-MENU MATIERE\n 3-Retour\n\n Votre choix --> ");
}

// MENU ETUDIANT
void    menuEt() {
    system("cls");
	printf("---------- MENU ETUDIANT ----------\n\n 1-Ajouter Etud\n 2-Modifier Etud\n 3-Supprimer Etud\n 4-Afficher les Etuds dispo \n 5-Retour \n\n Votre choix --> ");
}

// MENU Matiere
void    menuMat() {
    system("cls");
	printf("---------- MENU MATIERE ----------\n\n 1-Ajouter Mat\n 2-Modifier Mat\n 3-Supprimer Mat\n 4-Afficher les Matieres dispo \n 5-Retour \n\n Votre choix --> ");
}

// MENU Save/Load
void	menuSL() {
	system("cls");
	printf("---------- MENU Save/Load ----------\n\n 1-Save\n 2-Load\n 3-Retour\n\n Votre choix --> ");
}

// MENU Save
void	menuSave() {
	system("cls");
	printf("---------- MENU Save ----------\n\n 1-Save Prof\n 2-Save Etudiant\n 3-Save Matiere\n 4-Retour\n\n Votre choix --> ");
}

// MENU Load
void	menuLoad() {
	system("cls");
	printf("---------- MENU Load ----------\n\n 1-Load Prof\n 2-Load Etudiant\n 3-Load Matiere\n 4-Retour\n\n Votre choix --> ");
}
/* 

    La phase PROF

*/


void ajouterPrf(Etab *e)
{
	if(e->np==0)//tp==NULL 
	{
		e->tp=(Prof*)malloc(sizeof(Prof));
	}
	else {
		realloc(e->tp,sizeof(Prof)*(e->np+1));
	}
	printf("---------------- Veuillez saisir les info suivante ----------------\n\n");
	do {
		printf("Veuillez saisir un numero Prof 	   :	");
		scanf("%d",&e->tp[e->np].nump);
	}while(FindProf(e,e->tp[e->np].nump)!=-1);
	printf("Veuillez saisir un nom 		   : \t");
	scanf("%s",e->tp[e->np].nom );
	printf("Veuillez saisir un prenom 	   : \t");
	scanf("%s",e->tp[e->np].pre);
	e->np++;
}

// Afficher Prof
void listerPrf(Etab *e)
{
	if (e->np!=0) {
		int i;
		printf("---------------- Voici les info disponible ----------------\n\n");
		for(i=0;i<e->np;i++) {
			printf("Numero --> %d\t\t\tMr/Miss\t%s %s\n",e->tp[i].nump,e->tp[i].nom,e->tp[i].pre);
		}
	}
	else {
		printf("\nNO DATA !\n\n");
	}
	printf("\n\nA bientot !!\n");
}

// Modifier un Prof
void    ModifierProf(Etab *e, int num) {
    int pos = FindProf(e,num);

    if (pos != -1) {
        printf("Veuillez saisir un nom : ");
		scanf("%s",e->tp[pos].nom);
		printf("Veuillez saisir un prenom : ");
		scanf("%s",e->tp[pos].pre);
    } else {
        printf("\nNumero introuvable !\n\n\nMerci!\n");
        getch();
    }
}

// Supprimer un Prof
void    SuppProf(Etab *e, int num) {
    int pos = FindProf(e,num);

    if (pos != -1) {
        int i;

        for (i = pos; i < e->np;i++) {
            e->tp[pos] = e->tp[pos + 1];
        }
        e->np--;
        printf("\nL'operation est terminer !\n\nMerci!\n");
        getch();
    } else {
        printf("\nNumero introuvable !\n\n\nMerci!\n");
        getch();
    }
}


/* 

    La phase d'etudiant

*/



// Ajouter un Etudiant
void AjouterEt(Etab *e)
{
	if(e->nE==100) {
		printf("Tableau Plein !!\n\n");
	}
	else {
		printf("---------------- Veuillez saisir les info suivante ----------------\n\n");
		do{
			printf("Veuillez saisir un numero etudiant  	  :        ");
			scanf("%d",&e->tn[e->nE][e->numN].etud.nume);
		}while(FindEt(e,e->tn[e->nE][e->numN].etud.nume)!=-1);
		printf("Veuillez saisir un nom	          	  :        ");
		scanf("%s",e->tn[e->nE][e->numN].etud.nom);
		printf("Veuillez saisir un prenom	          :        ");
		scanf("%s",e->tn[e->nE][e->numN].etud.pre);
		e->nE++;
	}
}

// Afficher les Etudiants dispo
void ListerEt(Etab *e)
{
    if (e->nE == 0) {
        printf("\n\n\nNO DATA !\n");
    } else {
        int i;
		printf("---------------- Voici les info disponible ----------------\n\n");
        for(i=0;i<e->nE;i++)
        {
            printf("\nNumero --> %d\t\t\tMr/Miss  %s %s \t\t\tNiveau=%d\n",e->tn[i][e->numN].etud.nume,e->tn[i][e->numN].etud.nom,e->tn[i][e->numN].etud.pre,e->numN);
		}
    }
	printf("\n\nA bientot !!\n");
}


// Modifier un Etudiant
void    ModifierEt(Etab *e, int num) {
    int pos = FindEt(e,num);

    if (pos != -1) {
        printf("Veuillez saisir un nom   	:\t");
		scanf("%s",e->tn[pos][e->numN].etud.nom);
		printf("Veuillez saisir un prenom 	:\t");
		scanf("%s",e->tn[pos][e->numN].etud.pre);
    } else {
        printf("\nNumero introuvable !\n\nMerci!\n");
        getch();
    }
}

// Supprimer un Etudiant
void    SuppEt(Etab *e, int num) {
    int pos = FindEt(e,num);

    if (pos != -1) {
        int i;

        for (i = pos; i < e->nE;i++) {
            e->tn[i][e->numN].etud = e->tn[i + 1][e->numN].etud;
        }
        e->nE--;
        printf("\nL'operation est terminer !\n\nMerci!\n");
        getch();
    } else {
        printf("\nNumero introuvable !\n\n\nMerci!\n");
        getch();
    }
}


/* 

    La phase matiere

*/



// Ajouter une matiere
void AjouterMat(Etab *e)
{
	if(e->nM==100)
	{
		printf("Tableau Plein \n");
	}
	else
	{
		do{
			printf("Veuillez saisir un numero de matiere : ");
			scanf("%d",&e->tn[e->nM][e->numN].mat.numM);
		}while(FindMat(e,e->tn[e->nM][e->numN].mat.numM)!=-1);
		printf("Veuillez saisir le nom 				  :");
		scanf("%s",e->tn[e->nM][e->numN].mat.nom);
		e->nM++;
	}
}

// Afficher les matieres dispo
void ListerMat(Etab *e)
{
    if (e->nM == 100) {
        printf("\n\n\nNO DATA !\n");
        getch();
    } else {
        int i;
        for(i=0;i<e->nM;i++)
        {
			printf("Niveau=%d \t\t\tMatiere= %s\t\t\tnumero= %d\n",e->numN,e->tn[i][e->numN].mat.numM,e->tn[i][e->numN].mat.nom);
		}
	}
}


// Modifier une matiere
void    ModifierMat(Etab *e, int num) {
    int pos = FindMat(e,num);

    if (pos != -1) {
        printf("Veuillez saisir une matiere : ");
		scanf("%s",e->tn[pos][e->numN].mat.nom);
    } else {
        printf("\nNumero introuvable !\n\n\nMerci!\n");
        getch();
    }
}

// Supprimer une matiere
void    SuppMat(Etab *e, int num) {
    int pos = FindMat(e,num);

    if (pos != -1) {
        int i;

        for (i = pos; i < e->nM;i++) {
            e->tn[i][e->numN].mat = e->tn[i + 1][e->numN].mat;
        }
        e->nM--;
        printf("\n\n\nMerci!\n");
        getch();
    } else {
        printf("\nNumero introuvable !\n\n\nMerci!\n");
        getch();
    }
}


/* 

    La phase Save/Load

*/

// Save Prof
void	saveProf(Etab *e, char nomFile[20]) {
	FILE *f;
	f=fopen(nomFile,"w");
	if(f!=NULL)
	{
		int i;
		for(i=0;i<e->np;i++) {
			fprintf(f,"Numero --> %d\t\t\tMr/Miss\t%s %s\n",e->tp[i].nump,e->tp[i].nom,e->tp[i].pre);
		}
		printf("\nL'operation est terminer !\n\nMerci!!\n");
		getch();
	} else {
		printf("\nErreur d'overture!\n\n");
		getch();
	}
	fclose(f);
}

// Save Etudiant
void	saveEtd(Etab *e, char nomFile[20]) {
	FILE *f;
	f=fopen(nomFile,"w");
	if(f!=NULL)
	{
		int i;
		for(i=0;i<e->nE;i++) {
			fprintf(f,"Niveau= %d\t\t\tNumero= %d\t\t Mr/Miss %s %s",e->numN,e->tn[i][e->numN].etud.nume,e->tn[i][e->numN].etud.nom,e->tn[i][e->numN].etud.pre);
		}
		printf("\nL'operation est terminer !\n\nMerci!!\n");
		getch();
	} else {
		printf("\nErreur d'overture!\n\n");
		getch();
	}
	fclose(f);
}

// Save Matiere
void	saveMat(Etab *e, char nomFile[20]) {
	FILE *f;
	f=fopen(nomFile,"w");
	if(f!=NULL)
	{
		int i;
		for( i=0;i<e->np;i++) {
			fprintf(f,"Niveau=%d \t\t\tMatiere= %s\t\t\tnumero= %d\n",e->numN,e->tn[i][e->numN].mat.numM,e->tn[i][e->numN].mat.nom);
		}
		printf("\nL'operation est terminer !\n\nMerci!!\n");
		getch();
	} else {
		printf("\nErreur d'overture!\n\n");
		getch();
	}
	fclose(f);
}
// void loadProf(Etab *e,char nomFile[20])
// {
	// FILE *f;
	// f=fopen("saveProf.txt","r");
	// if(f!=NULL)
	// {
	// 	int i=0;
	// 	char s[40];
	// 	while(!feof(f))
	// 	{
	// 		//fscanf(f,"%s",s);
	// 		//fscanf(f,"%s",s);
	// 		fscanf(f,"%d",&e->tp[e->np].nump);
	// 		//fscanf(f,"%s",s);
	// 		fscanf(f,"%s",e->tp[e->np].nom);
	// 		fscanf(f,"%s",e->tp[e->np].pre);
	// 		e->np++;
	// 	}
	// 	printf("\nL'operation est terminer !\n\nMerci!!\n");
	// 	getch();
	// 	fclose(f);
	// } else {
	// 	printf("\nErreur d'overture!\n\n");
	// 	getch();
	// }
// }

// void	loadEtd(Etab *e,char nomFile[20]) {
// 	// FILE *f;
	// f=fopen(nomFile,"r");
	// if (f!=NULL) {
	// 	while(fread(&e,sizeof(e),1,f)!=NULL) {
	// 		scanf("%d",&e->numN);
	// 		scanf("%d",&e->tn[e->nE][e->numN].etud.nume);
	// 		scanf("%s",e->tn[e->nE][e->numN].etud.nom);
	// 		scanf("%s",e->tn[e->nE][e->numN].etud.pre);
	// 		e->nE++;
	// 	}
	// }
// }
int		main() {
	Etab *e=NULL;
	e=(Etab*)malloc(sizeof(Etab));
	
	e->tp=NULL;	
	e->np=0;
	e->nE=0;
    e->nM=0;
	e->numN=0;
	int numU,choix,choixPr,choixNv,choixEt,nuN,choixMat,choixSL,choixSave,choixLoad;
	
    do {

        // MENU PRINCIPALE
		system("COLOR 3F");
        menu();
        scanf("%d",&choix);
        system("cls");
        switch (choix) {
            case 1:
					do {
						system("COLOR FF");
						// MENU PROF
						menuPr();
						scanf("%d",&choixPr);
						system("cls");
						switch (choixPr) {
							case 1:
									ajouterPrf(e);
									break;
							case 2:
									printf("Veuillez saisir un numero unique d'un Prof : ");
									scanf("%d",&numU);
									ModifierProf(e,numU);
									break;
							case 3:
									printf("Veuillez saisir un numero unique d'un Prof : ");
									scanf("%d",&numU);
									SuppProf(e,numU);
									break;
							case 4:
									listerPrf(e);
									getch();
									break;
							default:
									break;
						}
					}while (choixPr != 5);
					break;	
            case 2:
				
                //MENU NIVEAU
					do {
						system("cls");
						printf("---------------- Veuillez saisir un Niveau ----------------\n\n\t -Niveau 1\n\t -Niveau 2\n\t -Niveau 3\n\t -Niveau 4\n\t -Niveau 5\n\n\t Votre choix --> ");
						scanf("%d",&e->numN);
					} while (e->numN >5 || e->numN <1);
					do {
						system("COLOR 7A");
						menuNv();
						scanf("%d",&choixNv);
						system("cls");
						switch (choixNv) {
							case 1:
								system("COLOR 4F");
								// MENU ETUDIANT
									do {
										menuEt();
										scanf("%d",&choixEt);
										system("cls");
										switch (choixEt) {
											case 1:
													AjouterEt(e);
													break;
											case 2:
													printf("Veuillez saisir un numero unique d'un Etudiant : ");
													scanf("%d",&numU);
													ModifierEt(e,numU);
													break;
											case 3:
													printf("Veuillez saisir un numero unique d'un Etudiant : ");
													scanf("%d",&numU);
													SuppEt(e,numU);
													break;
											case 4:
													ListerEt(e);
													getch();
													break;
											default:
												break;
										}
									}while (choixEt != 5);
									break;
							case 2:
								system("COLOR EC");
								// MENU Matiere
									do {
										menuMat();
										scanf("%d",&choixMat);
										system("cls");
										switch (choixMat) {
											case 1:
													AjouterMat(e);
													break;
											case 2: 
													printf("Veuillez saisir un numero unique d'une matiere		: ");
													scanf("%d",&numU);
													ModifierMat(e,numU);
													break;
											case 3: 
													printf("Veuillez saisir un numero unique d'une matiere		: ");
													scanf("%d",&numU);
													SuppMat(e,numU);
													break;
											case 4:
													ListerMat(e);
													getch();
													break;
											default:
													break;
													
										}
									}while (choixMat != 5);
									break;
							default:
									break;
						}
						e->numN=0;
					}while (choixNv != 3);
					break;

			case 3:
				// MENU Save/Load
					do {
						menuSL();
						scanf("%d", &choixSL);
						system("cls");
						switch (choixSL)
						{
						case 1:
								do {
									menuSave();
									scanf("%d",&choixSave);
									system("cls");
									switch (choixSave)
									{
										case 1:
											saveProf(e,"saveProf.txt");
											break;
										case 2:
											saveEtd(e,"saveEtd.txt");
											break;
										case 3:
											saveMat(e,"saveMat.txt");
											break;	
										default:
											break;
									}
								}while(choixSave != 4);
								break;
						case 2:
								do {
									menuLoad();
									scanf("%d",&choixLoad);
									system("cls");
									switch (choixLoad)
									{
										case 1: {
											//loadProf(e, "saveprof.txt");
											break;
										}
										case 2:
											//loadEtd(e,"saveEtd.txt");
											break;
										case 3:
											break;
										default:
											break;
									}
								}while(choixLoad!=4);
								break;
						default:
								break;
						}
					}while (choixSL !=3);
					break;
            default:
                	break;
        }
    }while(choix != 4);
	
	return 0;
}
