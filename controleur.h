#ifndef DEF_CONTROLEUR
#define DEF_CONTROLEUR
#include <SFML/Graphics.hpp>
#include "decor.h"

class Controleur
{
public:
    Controleur(sf::RenderWindow &fenetre);
    ~Controleur();
    void debutJeu();
    void retourMenu();
    void afficheMenu();
    void afficheJeu();
    void gestionTourIA(float temps_ec);
    void finJeu();
    void gestionDplSouris();
    void gestionSelectionSouris();
    Decor* getDecor();
    void gestMajD();
    void gestionCollisions();
    void gestionMouvementRame(int num_rame,int direction, float temps_ec);
    void pauseJeu();

private:
    sf::RenderWindow* m_fenetre;
    Decor* m_decor;
};

#endif // DEF_CONTROLEUR
