#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter une voiture
struct Voiture {
    int id;
    char description[50];
    char etat[20];
};

// Structure pour représenter une location
struct Location {
    int idVoiture;
    char date[20];
};

// Déclarations de fonctions
void louerVoiture(struct Voiture *voitures, int *historique, int *nbLocations);
void afficherDescription(struct Voiture *voitures);
void supprimerVoitureEnPanne(struct Voiture *voitures, int *nbVoitures);
void modifierDescriptionEtat(struct Voiture *voitures);
void afficherHistoriqueLocations(int *historique, struct Voiture *voitures, int nbVoitures);
void retourVoitureReclamation(int *historique);
void creerContrat(struct voiture, char *contrats, int voitureId, const char *clientNom) 

int main() {
    struct Voiture voitures[50];
    int historique[100];  // Tableau pour stocker l'historique des locations
    int nbVoitures = 0;   // Nombre de voitures disponibles
    int nbLocations = 0;  // Nombre total de locations

    // Menu principal
    int choix;
    do {
        printf("\nMenu E-Cars:\n");
        printf("1. Louer une voiture\n");
        printf("2. Afficher la description d'une voiture\n");
        printf("3. Supprimer une voiture en panne\n");
        printf("4. Modifier la description et l'etat d'une voiture\n");
        printf("5. Afficher l'historique des locations\n");
        printf("6. Retour d'une voiture en cas de reclamation\n");
        printf("7. Créer un contrat de location\n");
        printf("0. Quitter\n");

        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                louerVoiture(voitures, historique, &nbLocations);
                break;
            case 2:
                afficherDescription(voitures);
                break;
            case 3:
                supprimerVoitureEnPanne(voitures, &nbVoitures);
                break;
            case 4:
                modifierDescriptionEtat(voitures);
                break;
            case 5:
                afficherHistoriqueLocations(historique, voitures, nbVoitures);
                break;
            case 6:
                retourVoitureReclamation(historique);
                break;
            case 7:
                creerContrat(voitures,clients)
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 0);

    return 0;
}

#include <stdio.h>

// Structure représentant une voiture
struct Voiture {
    char modele[50];
    int annee;
    float prix;
    int estLouee;
};

// Fonction pour louer une voiture et enregistrer les données dans un fichier
void louerVoiture(struct Voiture *voiture, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "ab"); // "ab" pour ajouter au fichier binaire

    if (fichier != NULL) {
        if (!voiture->estLouee) {
            printf("Voiture louée avec succès et enregistrée dans le fichier!\n");

            // Écrire les données de la voiture dans le fichier
            fwrite(voiture, sizeof(struct Voiture), 1, fichier);

            voiture->estLouee = 1;
        } else {
            printf("Désolé, la voiture est déjà louée.\n");
        }

        fclose(fichier);
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}

#include <stdio.h>

struct Voiture {
    int id;
    char marque[50];
    char modele[50];
    char etat[20];
};

void afficherDescription(FILE *file, int voitureID) {
    struct Voiture voiture;

    // Rechercher la voiture dans le fichier
    int found = 0;
    while (fscanf(file, "%d %s %s %s", &voiture.id, voiture.marque, voiture.modele, voiture.etat) != EOF) {
        if (voiture.id == voitureID) {
            found = 1;
            break;
        }
    }

    // Afficher les détails de la voiture si elle est trouvée
    if (found) {
        printf("ID: %d\nMarque: %s\nModèle: %s\nÉtat: %s\n", voiture.id, voiture.marque, voiture.modele, voiture.etat);
    } else {
        printf("Voiture non trouvée.\n");
    }

    // Remettre le curseur de fichier au début pour une utilisation future
    rewind(file);
}
#include <stdio.h>

struct Voiture {
    int id;
    char marque[50];
    char modele[50];
    char etat[20];
};

void supprimerVoiture(FILE *file, int voitureID) {
    FILE *tempFile = fopen("temp.txt", "w"); // Fichier temporaire pour stocker les données modifiées

    if (tempFile == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        return;
    }

    struct Voiture voiture;

    // Copier les données sauf celle de la voiture à supprimer dans le fichier temporaire
    int found = 0;
    while (fscanf(file, "%d %s %s %s", &voiture.id, voiture.marque, voiture.modele, voiture.etat) != EOF) {
        if (voiture.id == voitureID) {
            found = 1; // Marquer que la voiture a été trouvée
        } else {
            fprintf(tempFile, "%d %s %s %s\n", voiture.id, voiture.marque, voiture.modele, voiture.etat);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        remove("temp.txt"); // Supprimer le fichier temporaire si la voiture n'a pas été trouvée
        printf("Voiture non trouvée.\n");
    } else {
        remove("voitures.txt");
        rename("temp.txt", "voitures.txt"); // Renommer le fichier temporaire pour remplacer l'ancien fichier
        printf("Voiture supprimée avec succès.\n");
    }
}
#include <stdio.h>

struct Voiture {
    int id;
    char marque[50];
    char modele[50];
    char etat[20];
};

void modifierVoiture(FILE *file, int voitureID, char nouvelleDescription[], char nouvelEtat[]) {
    FILE *tempFile = fopen("temp.txt", "w"); // Fichier temporaire pour stocker les données modifiées

    if (tempFile == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        return;
    }

    struct Voiture voiture;

    // Copier les données avec modification si la voiture est trouvée
    int found = 0;
    while (fscanf(file, "%d %s %s %s", &voiture.id, voiture.marque, voiture.modele, voiture.etat) != EOF) {
        if (voiture.id == voitureID) {
            found = 1; // Marquer que la voiture a été trouvée
            // Modifier la description et l'état de la voiture
            snprintf(voiture.marque, sizeof(voiture.marque), "%s", nouvelleDescription);
            snprintf(voiture.etat, sizeof(voiture.etat), "%s", nouvelEtat);
        }
        fprintf(tempFile, "%d %s %s %s\n", voiture.id, voiture.marque, voiture.modele, voiture.etat);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        remove("temp.txt"); // Supprimer le fichier temporaire si la voiture n'a pas été trouvée
        printf("Voiture non trouvée.\n");
    } else {
        remove("voitures.txt");
        rename("temp.txt", "voitures.txt"); // Renommer le fichier temporaire pour remplacer l'ancien fichier
        printf("Voiture modifiée avec succès.\n");
    }
}
#include <stdio.h>

struct Voiture {
    int id;
    char marque[50];
    char modele[50];
    char etat[20];
};

void afficherHistorique(FILE *file) {
    struct Voiture voiture;

    // Afficher l'en-tête de l'historique
    printf("Historique des locations :\n");

    // Parcourir le fichier et afficher les détails de chaque voiture (historique complet)
    while (fscanf(file, "%d %s %s %s", &voiture.id, voiture.marque, voiture.modele, voiture.etat) != EOF) {
        printf("ID: %d\nMarque: %s\nModèle: %s\nÉtat: %s\n", voiture.id, voiture.marque, voiture.modele, voiture.etat);
        printf("----------------------------\n");
    }
}
#include <stdio.h>

struct Voiture {
    int id;
    char marque[50];
    char modele[50];
    char etat[20];
};

void retourVoiture(FILE *file, int voitureID) {
    FILE *tempFile = fopen("temp.txt", "w"); // Fichier temporaire pour stocker les données modifiées

    if (tempFile == NULL) {
        printf("Erreur lors de l'ouverture du fichier temporaire.\n");
        return;
    }

    struct Voiture voiture;

    // Copier les données avec modification si la voiture est trouvée
    int found = 0;
    while (fscanf(file, "%d %s %s %s", &voiture.id, voiture.marque, voiture.modele, voiture.etat) != EOF) {
        if (voiture.id == voitureID) {
            found = 1; // Marquer que la voiture a été trouvée
            // Modifier l'état de la voiture pour la marquer comme disponible
            snprintf(voiture.etat, sizeof(voiture.etat), "Disponible");
        }
        fprintf(tempFile, "%d %s %s %s\n", voiture.id, voiture.marque, voiture.modele, voiture.etat);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        remove("temp.txt"); // Supprimer le fichier temporaire si la voiture n'a pas été trouvée
        printf("Voiture non trouvée.\n");
    } else {
        remove("voitures.txt");
        rename("temp.txt", "voitures.txt"); // Renommer le fichier temporaire pour remplacer l'ancien fichier
        printf("Retour enregistré avec succès.\n");
    }
}
#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter une voiture
struct Voiture {
    int id;
    char modele[50];
    char immatriculation[20];
    // Ajoutez d'autres champs selon vos besoins
};

// Structure pour représenter un contrat de location
struct Contrat {
    int contratId;
    int voitureId;
    char clientNom[50];
    // Ajoutez d'autres champs selon vos besoins
};

// Fonction pour créer un contrat de location
void creerContrat(FILE *voituresFile, FILE *contratsFile, int voitureId, const char *clientNom) {
    // Vérifiez si la voiture existe
    fseek(voituresFile, sizeof(struct Voiture) * (voitureId - 1), SEEK_SET);
    struct Voiture voiture;
    fread(&voiture, sizeof(struct Voiture), 1, voituresFile);

    if (voiture.id == 0) {
        printf("Erreur : Voiture introuvable.\n");
        return;
    }

    // Créez le contrat
    fseek(contratsFile, 0, SEEK_END);
    struct Contrat contrat;
    contrat.contratId = ftell(contratsFile) / sizeof(struct Contrat) + 1;
    contrat.voitureId = voitureId;
    strncpy(contrat.clientNom, clientNom, sizeof(contrat.clientNom));

    // Enregistrez le contrat dans le fichier des contrats
    fwrite(&contrat, sizeof(struct Contrat), 1, contratsFile);

    printf("Contrat créé avec succès.\n");
}