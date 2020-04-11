#include "rame.h"

Rame::Rame(sf::RenderWindow &fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;
    m_tailleRame.x=20.f;
    m_tailleRame.y=100.f;

    //chargement textures
    m_trame1.loadFromFile("donnees/rame1.png");
    m_trame2.loadFromFile("donnees/rame2.png");

    m_srame1.setOrigin(m_tailleRame.x/2,m_tailleRame.y/2);
    m_srame2.setOrigin(m_tailleRame.x/2,m_tailleRame.y/2);



    initRame();



}

void Rame::initRame()
{
    m_vitesseRame=400.f;
    m_vitesseRame2=0.f;

    m_srame1.setPosition(20.f,hauteurF/2);
    m_srame1.setTexture(m_trame1);


    m_srame2.setPosition(largeurF-20.f,hauteurF/2);
    m_srame2.setTexture(m_trame2);

}

sf::Vector2f Rame::getRamePos(int num_rame)
{
    if(num_rame==R_JOUEUR1)
    {
        return m_srame1.getPosition();
    }
    else
        return m_srame2.getPosition();
}

sf::Vector2f Rame::getTailleRame()
{
    return m_tailleRame;
}

void Rame::deplacementRame(int direction,int num_rame)
{
    if(num_rame==R_JOUEUR1)
    {
        if(direction==R_DIR_HAUT)
        {
            m_srame1.move(0,-m_vitesseRame*deltaTime);

            if(m_srame1.getPosition().y-(m_tailleRame.y/2)<0.f)
            {
                m_srame1.setPosition(20.f,m_tailleRame.y/2);
            }
        }
        else
        {
            m_srame1.move(0,m_vitesseRame*deltaTime);

            if(m_srame1.getPosition().y+(m_tailleRame.y/2)>hauteurF)
            {
                m_srame1.setPosition(20.f,hauteurF-(m_tailleRame.y/2));
            }
        }
    }
    else if(num_rame==R_JOUEUR2)
    {
        if(direction==R_DIR_HAUT)
        {
            m_srame2.move(0,-m_vitesseRame*deltaTime);

            if(m_srame2.getPosition().y-(m_tailleRame.y/2)<0.f)
            {
                m_srame2.setPosition(largeurF-20.f,m_tailleRame.y/2);
            }
        }
        else
        {
            m_srame2.move(0,m_vitesseRame*deltaTime);

            if(m_srame2.getPosition().y+(m_tailleRame.y/2)>hauteurF)
            {
                m_srame2.setPosition(largeurF-20.f,hauteurF-(m_tailleRame.y/2));
            }
        }
    }
    else if(num_rame==R_CPU)
    {

        m_srame2.move(0.f, m_vitesseRame2*deltaTime);

        if(m_srame2.getPosition().y-(m_tailleRame.y/2)<0.f)
        {
            m_srame2.setPosition(largeurF-20.f,m_tailleRame.y/2);
        }


        if(m_srame2.getPosition().y+(m_tailleRame.y/2)>hauteurF)
        {
            m_srame2.setPosition(largeurF-20.f,hauteurF-(m_tailleRame.y/2));
        }

    }
    else
    {

    }
}

bool Rame::possibDeplRame(int direction,int num_rame)
{
    bool depl_possibl=false;

    if(num_rame==R_JOUEUR1)
    {
        if(direction==R_DIR_HAUT)
        {
            if(m_srame1.getPosition().y-(m_tailleRame.y/2)>0.f)
            {
                depl_possibl=true;
            }
        }
        else
        {
            if(m_srame1.getPosition().y+(m_tailleRame.y/2)<hauteurF)
            {
                depl_possibl=true;
            }
        }
    }
    else
    {
        if(direction==R_DIR_HAUT)
        {
            if(m_srame2.getPosition().y-(m_tailleRame.y/2)>0.f)
            {
                depl_possibl=true;
            }
        }
        else
        {
            if(m_srame2.getPosition().y+(m_tailleRame.y/2)<hauteurF)
            {
                depl_possibl=true;
            }
        }
    }
}

float Rame::getVitesseR()
{
    return m_vitesseRame2;
}

void Rame::inverserVitR(bool neg)
{
  if(neg==true)
  {
      m_vitesseRame2= -400.f;
  }
  else
  {
      m_vitesseRame2= 400.f;
  }

}

void Rame::mAZVRD()
{
    m_vitesseRame2=0.f;
}

void Rame::afficherRame()
{
    m_fenetre->draw(m_srame1);
    m_fenetre->draw(m_srame2);
}

Rame::~Rame()
{

}
