#include "balle.h"

Balle::Balle(sf::RenderWindow &fenetre):m_fenetre(0),m_angleBalle(0),m_facteurDepl(0)
{
    m_fenetre=&fenetre;
    m_vitesseBalle=400;

    m_tballe.loadFromFile("donnees/balle.png");

    m_rayBalle=10.f;
    initBalle();

}

void Balle::initBalle()
{
     do
     {
         m_angleBalle=(std::rand()%360)*2*pi/360;
     }
     while(std::abs(std::cos(m_angleBalle))<0.7f);

    m_sballe.setOrigin(m_rayBalle,m_rayBalle);
    m_sballe.setPosition(largeurF/2,hauteurF/2);
    m_sballe.setTexture(m_tballe);
}

sf::Vector2f Balle::getBallePos()
{
    return m_sballe.getPosition();
}

void Balle::setBallePos(float posx,float posy)
{
    m_sballe.setPosition(posx,posy);
}

float Balle::getRayBalle()
{
    return m_rayBalle;
}

void Balle::deplacementBalle()
{
    m_facteurDepl=m_vitesseBalle*deltaTime;
    m_sballe.move(std::cos(m_angleBalle)*m_facteurDepl,std::sin(m_angleBalle)*m_facteurDepl);
}

void Balle::afficherBalle()
{
    m_fenetre->draw(m_sballe);
}

void Balle::setAngleBalle(bool negatif)
{
    if(negatif==true)
    {
        m_angleBalle=-m_angleBalle;
    }
}

void Balle::setAngleBalle2(float angle)
{
    m_angleBalle=angle;
}

float Balle::getAngleBalle()
{
   return m_angleBalle;
}

Balle::~Balle()
{

}
