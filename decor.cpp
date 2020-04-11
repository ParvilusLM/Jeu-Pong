#include "decor.h"

Decor::Decor(sf::RenderWindow &fenetre):m_rame(0),m_balle(0),m_menu(0),m_info(0),m_son(0)
{
    m_fenetre=&fenetre;
    m_balle=new Balle(*m_fenetre);
    m_rame=new Rame(*m_fenetre);
    m_son=new Son();
    m_menu=new Menu(*m_fenetre);
    m_info= new Info(*m_fenetre);

    m_t_fondEc.loadFromFile("donnees/fondEc.png");

    m_s_fondEc.setTexture(m_t_fondEc);


}

void Decor::inverserAngleBalle()
{
    m_balle->setAngleBalle(true);
}

void Decor::gestMajD()
{
    if(!pauseBut)
    {
        m_balle->deplacementBalle();
    }

    m_info->indiquerScore();
}


Rame& Decor::getRame()
{
   return *m_rame;
}

Balle& Decor::getBalle()
{
    return *m_balle;
}

Info& Decor::getInfo()
{
   return *m_info;
}

void Decor::afficherMenu()
{
     m_menu->affficheMenu();
}

void Decor::afficherJeu()
 {
     m_fenetre->draw(m_s_fondEc);
     m_info->afficheInfo();
     m_rame->afficherRame();
     m_balle->afficherBalle();

 }


void Decor::retourMenu()
{
   m_menu->retourMenuP();
}


void Decor::finJeu()
{
    m_balle->initBalle();
    m_rame->initRame();
}

void Decor::gestionDplSouris()
{
    m_menu->elementActif();
}

void Decor::gestionSelectionSouris()
{
    m_menu->selectionElActif();
}


void Decor::initInfo()
{
    m_info->initInfo();
}

void Decor::gestionTourIA(float temps_ec)
{
    if(((m_rame->getVitesseR() < 0.f) && (m_rame->getRamePos(R_JOUEUR2).y - (m_rame->getTailleRame().y/2) > 0.f )) ||
       ((m_rame->getVitesseR() > 0.f) && (m_rame->getRamePos(R_JOUEUR2).y + (m_rame->getTailleRame().y/2) < hauteurF )))
    {
        m_rame->deplacementRame(R_DIR_IA,R_CPU);
    }

}

 Decor::~Decor()
 {
     delete m_balle;
     delete m_rame;
     delete m_son;
     delete m_menu;
     delete m_info;
 }

