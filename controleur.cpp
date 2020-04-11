#include "controleur.h"

Controleur::Controleur(sf::RenderWindow &fenetre):m_fenetre(0),m_decor(0)
{
    m_fenetre=&fenetre;
    m_decor= new Decor(*m_fenetre);

}

void Controleur::debutJeu()
{
    jeuEnCours=true;
    m_decor->initInfo();

}

void Controleur::retourMenu()
{
   m_decor->retourMenu();


}

void Controleur::afficheMenu()
{
    m_decor->afficherMenu();
}

void Controleur::afficheJeu()
{
    m_decor->afficherJeu();
}



void Controleur::gestionTourIA(float temps_ec)
{
    m_decor->gestionTourIA(temps_ec);
}

void Controleur::gestionDplSouris()
{
    m_decor->gestionDplSouris();
}

void Controleur::gestionSelectionSouris()
{
    m_decor->gestionSelectionSouris();
}

void Controleur::finJeu()
{
    m_decor->finJeu();
    m_decor->retourMenu();
    m_decor->getInfo().reinitInfo();
    jeuEnCours=false;
    jeuPause=false;
    pauseBut=false;


}

Decor* Controleur::getDecor()
{
    return m_decor;
}

void Controleur::gestMajD()
{
    m_decor->gestMajD();
    gestionCollisions();

}

void Controleur::gestionCollisions()
{
    if(m_decor->getBalle().getBallePos().x-m_decor->getBalle().getRayBalle()<0.f)
    {
        m_decor->inverserAngleBalle();
        m_decor->getBalle().initBalle();
        m_decor->getRame().initRame();
        m_decor->getInfo().gestionScore(R_JOUEUR1);
        pauseBut=true;
    }

    if(m_decor->getBalle().getBallePos().x+m_decor->getBalle().getRayBalle()>largeurF)
    {
        m_decor->inverserAngleBalle();
        m_decor->getBalle().initBalle();
        m_decor->getRame().initRame();
        m_decor->getInfo().gestionScore(R_JOUEUR2);
        pauseBut=true;
    }

    if(m_decor->getBalle().getBallePos().y-m_decor->getBalle().getRayBalle()<0.f)
    {
        m_decor->inverserAngleBalle();
        m_decor->getBalle().setBallePos(m_decor->getBalle().getBallePos().x, m_decor->getBalle().getRayBalle()+0.1f);
    }

    if(m_decor->getBalle().getBallePos().y+m_decor->getBalle().getRayBalle()>hauteurF)
    {
        m_decor->inverserAngleBalle();
        m_decor->getBalle().setBallePos(m_decor->getBalle().getBallePos().x, hauteurF - m_decor->getBalle().getRayBalle()+0.1f);
    }


    if(m_decor->getBalle().getBallePos().x - m_decor->getBalle().getRayBalle() < m_decor->getRame().getRamePos(R_JOUEUR1).x + m_decor->getRame().getTailleRame().x/2
       &&  m_decor->getBalle().getBallePos().x - m_decor->getBalle().getRayBalle() > m_decor->getRame().getRamePos(R_JOUEUR1).x
       &&  m_decor->getBalle().getBallePos().y + m_decor->getBalle().getRayBalle() >= m_decor->getRame().getRamePos(R_JOUEUR1).y - m_decor->getRame().getTailleRame().y/2
       && m_decor->getBalle().getBallePos().y - m_decor->getBalle().getRayBalle() <= m_decor->getRame().getRamePos(R_JOUEUR1).y + m_decor->getRame().getTailleRame().y/2)
       {
           if(m_decor->getBalle().getBallePos().y > m_decor->getRame().getRamePos(R_JOUEUR1).y)
           {
               m_decor->getBalle().setAngleBalle2(pi - m_decor->getBalle().getAngleBalle() + (std::rand() % 20)*pi/180);
           }
           else
           {
               m_decor->getBalle().setAngleBalle2(pi - m_decor->getBalle().getAngleBalle() - (std::rand() % 20)*pi/180);
           }

           m_decor->getBalle().setBallePos(m_decor->getRame().getRamePos(R_JOUEUR1).x + m_decor->getBalle().getRayBalle() + m_decor->getRame().getTailleRame().x/2 + 0.1f, m_decor->getBalle().getBallePos().y);
       }


   if(m_decor->getBalle().getBallePos().x + m_decor->getBalle().getRayBalle() > m_decor->getRame().getRamePos(R_JOUEUR2).x - m_decor->getRame().getTailleRame().x/2
       &&  m_decor->getBalle().getBallePos().x + m_decor->getBalle().getRayBalle() < m_decor->getRame().getRamePos(R_JOUEUR2).x
       &&  m_decor->getBalle().getBallePos().y + m_decor->getBalle().getRayBalle() >= m_decor->getRame().getRamePos(R_JOUEUR2).y - m_decor->getRame().getTailleRame().y/2
       && m_decor->getBalle().getBallePos().y - m_decor->getBalle().getRayBalle() <= m_decor->getRame().getRamePos(R_JOUEUR2).y + m_decor->getRame().getTailleRame().y/2)
       {
           if(m_decor->getBalle().getBallePos().y > m_decor->getRame().getRamePos(R_JOUEUR2).y)
           {
               m_decor->getBalle().setAngleBalle2(pi - m_decor->getBalle().getAngleBalle() + (std::rand() % 20)*pi/180);

           }
           else
           {
               m_decor->getBalle().setAngleBalle2(pi - m_decor->getBalle().getAngleBalle() - (std::rand() % 20)*pi/180);

           }

           m_decor->getBalle().setBallePos(m_decor->getRame().getRamePos(R_JOUEUR2).x - m_decor->getBalle().getRayBalle() - m_decor->getRame().getTailleRame().x/2 - 0.1f, m_decor->getBalle().getBallePos().y);
       }

}

void Controleur::gestionMouvementRame(int num_rame, int direction, float temps_ec)
{
    if(num_rame==R_JOUEUR1)
    {
        if(direction==R_DIR_HAUT)
        {
            if(m_decor->getRame().getRamePos(R_JOUEUR1).y - (m_decor->getRame().getTailleRame().y/2) > 0.f )
            {
                m_decor->getRame().deplacementRame(direction,num_rame);
            }
        }
        else
        {
            if(m_decor->getRame().getRamePos(R_JOUEUR1).y + (m_decor->getRame().getTailleRame().y/2) <hauteurF - 0.f )
            {
                m_decor->getRame().deplacementRame(direction,num_rame);
            }
        }

    }
    else if(num_rame==R_JOUEUR2)
    {
        if(direction==R_DIR_HAUT)
        {
            if(m_decor->getRame().getRamePos(R_JOUEUR2).y - (m_decor->getRame().getTailleRame().y/2) > 0.f )
            {
                m_decor->getRame().deplacementRame(direction,num_rame);
            }
        }
        else
        {
            if(m_decor->getRame().getRamePos(R_JOUEUR2).y + (m_decor->getRame().getTailleRame().y/2) <hauteurF - 0.f )
            {
                m_decor->getRame().deplacementRame(direction,num_rame);
            }
        }
    }
    else if(num_rame==R_CPU)
    {
        gestionTourIA(temps_ec);

        if(temps_ec > tempsIA)
        {
            if(m_decor->getBalle().getBallePos().y + m_decor->getBalle().getRayBalle() > m_decor->getRame().getRamePos(R_JOUEUR2).y + (m_decor->getRame().getTailleRame().y/2) )
            {
                m_decor->getRame().inverserVitR(false);
            }
            else if(m_decor->getBalle().getBallePos().y - m_decor->getBalle().getRayBalle() < m_decor->getRame().getRamePos(R_JOUEUR2).y - (m_decor->getRame().getTailleRame().y/2))
            {
                m_decor->getRame().inverserVitR(true);
            }
            else
            {
                m_decor->getRame().mAZVRD();
            }


        }
    }
    else
    {

    }
}

void Controleur::pauseJeu()
{
    if(jeuPause)
    {
        jeuPause=false;
    }
    else
        jeuPause=true;
}

Controleur::~Controleur()
{
    delete m_decor;
}

