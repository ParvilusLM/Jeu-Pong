#ifndef DEF_RAME
#define DEF_RAME
#include <SFML/Graphics.hpp>
#include "enums.h"
#include "varGlob.h"
#include "constantes.h"
#include <iostream>


class Rame
{
public:
    Rame(sf::RenderWindow &fenetre);
    ~Rame();
    void initRame();
    sf::Vector2f getRamePos(int num_rame);
    sf::Vector2f getTailleRame();
    void mAZVRD();
    float getVitesseR();
    void inverserVitR(bool neg);
    void deplacementRame(int direction,int num_rame);
    bool possibDeplRame(int direction,int num_rame);
    void afficherRame();




private:
    sf::RenderWindow* m_fenetre;
    sf::Sprite m_srame1;
    sf::Texture m_trame1;
    sf::Sprite m_srame2;
    sf::Texture m_trame2;
    float m_vitesseRame;
    float m_vitesseRame2;
    sf::Vector2f m_tailleRame;



};

#endif // DEF_RAME
