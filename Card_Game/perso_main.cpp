#include "Berserker.h"
#include "SnowQueen.h"
#include <iostream>
#include <thread>  // Pour std::this_thread::sleep_for
#include <chrono>  // Pour std::chrono::seconds

// Fonction pour gérer les dégâts sur la durée
void appliquerDegatsSurDuree(Personnage* cible, int degatsParSeconde, int dureeEnSecondes) {
    for (int i = 0; i < dureeEnSecondes; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Attendre 1 seconde
        cible->pointsDeVie -= degatsParSeconde;
        std::cout << "Dégâts sur la durée : -" << degatsParSeconde << " PV. PV restants de " << (cible == nullptr ? "???" : "cible") << " : " << cible->pointsDeVie << std::endl;
        if (cible->pointsDeVie <= 0) break;  // Si les PV tombent à 0, fin des dégâts
    }
}

// Fonction pour choisir et appliquer une action pour le Berserker
void tourBerserker(Berserker& berserker, Personnage& adversaire) {
    int choix;
    std::cout << "Tour du Berserker. Choisissez une action :\n"
              << "1 - Frappe préventive\n"
              << "2 - Blast\n"
              << "3 - Frappe punitive\n"
              << "4 - Coup déchaîné\n"
              << "5 - Movement Alpha\n";
    std::cin >> choix;

    switch (choix) {
    case 1:
        berserker.frappePreventive();
        adversaire.pointsDeVie -= berserker.attaque;
        break;
    case 2:
        berserker.blast();
        adversaire.pointsDeVie -= static_cast<int>(1.5 * berserker.attaque);
        break;
    case 3:
        berserker.frappePunitive();
        adversaire.pointsDeVie -= static_cast<int>(0.3 * berserker.pointsDeVie);
        break;
    case 4:
        berserker.coupDechaine();
        adversaire.pointsDeVie -= static_cast<int>(0.5 * berserker.pointsDeVie);
        break;
    case 5:
        berserker.movementAlpha();
        adversaire.pointsDeVie -= static_cast<int>(0.75 * berserker.pointsDeVie);
        break;
    default:
        std::cout << "Choix invalide. Frappe préventive par défaut." << std::endl;
        berserker.frappePreventive();
        adversaire.pointsDeVie -= berserker.attaque;
        break;
    }
}

// Fonction pour gérer les actions de la SnowQueen
void tourSnowQueen(SnowQueen& snowQueen, Personnage& adversaire) {
    int choix;
    std::cout << "Tour de la SnowQueen. Choisissez une action :\n"
              << "1 - Frappe préventive\n"
              << "2 - Blast\n"
              << "3 - Javelot de glace\n"
              << "4 - Vent glaciale\n"
              << "5 - Let It Go\n";
    std::cin >> choix;

    switch (choix) {
    case 1:
        snowQueen.frappePreventive();
        adversaire.pointsDeVie -= snowQueen.attaque;
        break;
    case 2:
        snowQueen.blast();
        adversaire.pointsDeVie -= static_cast<int>(15 * snowQueen.attaque);
        break;
    case 3:
        snowQueen.javelotDeGlace();
        adversaire.pointsDeVie -= static_cast<int>(12.5 * snowQueen.attaque);
        break;
    case 4:
        snowQueen.ventGlaciale();
        adversaire.pointsDeVie -= static_cast<int>(15 * snowQueen.attaque);
        break;
    case 5:
        if (snowQueen.energie >= 100) {
            snowQueen.letItGo();
            int degatsInitiaux = static_cast<int>(17.5 * snowQueen.attaque);
            int degatsSurLaDuree = static_cast<int>(2.5 * snowQueen.attaque);
            adversaire.pointsDeVie -= degatsInitiaux;
            std::thread degatsThread(appliquerDegatsSurDuree, &adversaire, degatsSurLaDuree, 5);
            degatsThread.detach();  // Laisser les dégâts sur la durée s'appliquer en arrière-plan
        } else {
            std::cout << "Pas assez d'énergie pour Let It Go !" << std::endl;
        }
        break;
    default:
        std::cout << "Choix invalide. Frappe préventive par défaut." << std::endl;
        snowQueen.frappePreventive();
        adversaire.pointsDeVie -= snowQueen.attaque;
        break;
    }
}

int main() {
    // Création des personnages
    Berserker berserker(15000, 60, 15, 0.8);
    SnowQueen snowQueen(12000, 50, 12, 1.2);

    Personnage* premier;
    Personnage* second;

    // Déterminer qui commence en fonction de la vitesse
    if (berserker.vitesse > snowQueen.vitesse) {
        premier = &berserker;
        second = &snowQueen;
    } else {
        premier = &snowQueen;
        second = &berserker;
    }

    int tempsEcoule = 0;
    const int pasDeTemps = 1;  // Chaque tour dure 1 seconde

    // Boucle de combat
    while (berserker.pointsDeVie > 0 && snowQueen.pointsDeVie > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(pasDeTemps));  // Simuler le passage du temps
        tempsEcoule += pasDeTemps;

        // Tour du premier personnage
        std::cout << "\nTemps écoulé : " << tempsEcoule << " secondes." << std::endl;
        std::cout << "C'est au tour de : " << (premier == &berserker ? "Berserker" : "SnowQueen") << std::endl;
        if (premier == &berserker) {
            tourBerserker(berserker, *second);
        } else {
            tourSnowQueen(snowQueen, *second);
        }

        if (second->pointsDeVie <= 0) break;  // Vérifier si le second personnage est mort

        // Tour du second personnage
        std::this_thread::sleep_for(std::chrono::seconds(pasDeTemps));  // Simuler le passage du temps
        tempsEcoule += pasDeTemps;

        std::cout << "\nTemps écoulé : " << tempsEcoule << " secondes." << std::endl;
        std::cout << "C'est au tour de : " << (second == &berserker ? "Berserker" : "SnowQueen") << std::endl;
        if (second == &berserker) {
            tourBerserker(berserker, *premier);
        } else {
            tourSnowQueen(snowQueen, *premier);
        }

        if (premier->pointsDeVie <= 0) break;  // Vérifier si le premier personnage est mort
    }

    // Déterminer le vainqueur
    if (berserker.pointsDeVie > 0) {
        std::cout << "Le Berserker a gagné !" << std::endl;
    } else if (snowQueen.pointsDeVie > 0) {
        std::cout << "La SnowQueen a gagné !" << std::endl;
    } else {
        std::cout << "Match nul !" << std::endl;
    }

    return 0;
}
