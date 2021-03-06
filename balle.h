#ifndef DEF_BALLE
#define DEF_BALLE

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "varGlob.h"
#include "constantes.h"
#include "enums.h"

class Balle
{
public:
    Balle(sf::RenderWindow &fenetre);
    ~Balle();
    void initBalle();
    sf::Vector2f getBallePos();
    void setBallePos(float posx,float posy);
    float getRayBalle();
    float getAngleBalle();
    void deplacementBalle();
    void afficherBalle();
    void setAngleBalle(bool negatif);
    void setAngleBalle2(float angle);


private:
    sf::RenderWindow* m_fenetre;
    sf::Sprite m_sballe;
    sf::Texture m_tballe;
    float m_rayBalle;
    float m_vitesseBalle;
    float m_angleBalle;
    int m_directionBalle;
    float m_facteurDepl;


};

#endif // DEF_BALLE
