#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "controleur.h"




using namespace sf;

bool jeuEnCours = false;
float deltaTime=0.f;
int sourisX=0,sourisY=0;
bool pauseBut=false;
bool HumvsHum=false;
bool jeuPause=false;



int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    RenderWindow fenetre(VideoMode(largeurF,hauteurF),"Pong");
    fenetre.setFramerateLimit(60);

    Controleur controleurJ(fenetre);
    Clock horloge,horlIa,horl2;


    while(fenetre.isOpen())
    {
        Event evenement;
        while(fenetre.pollEvent(evenement))
        {
            if(evenement.type==Event::Closed)
            {
                 fenetre.close();
                 break;
            }

            if(evenement.type==Event::MouseMoved)
            {
                sourisX=evenement.mouseMove.x;
                sourisY=evenement.mouseMove.y;
                if(!jeuEnCours)
                {
                    controleurJ.gestionDplSouris();
                }
            }

            if(evenement.type==Event::MouseButtonPressed && !jeuEnCours)
            {
                  Mouse::Button button = evenement.mouseButton.button;
                  if (button == Mouse::Left) // Bouton gauche
                  {
                      controleurJ.gestionSelectionSouris();

                      if(jeuEnCours)
                      {
                          horloge.restart();
                          controleurJ.debutJeu();
                      }
                  }
            }

            if((evenement.type==Event::KeyPressed )&& (evenement.key.code==Keyboard::Space) && !pauseBut)
            {
                controleurJ.pauseJeu();
            }

            if((evenement.type==Event::KeyPressed )&& (evenement.key.code==Keyboard::R))
            {
                controleurJ.finJeu();
            }

        }

        if(jeuEnCours)
        {
            deltaTime=horloge.restart().asSeconds();
            float tempsEc= horlIa.getElapsedTime().asSeconds();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !pauseBut)
            {
                controleurJ.gestionMouvementRame(R_JOUEUR1,R_DIR_HAUT,tempsEc);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !pauseBut)
            {
                controleurJ.gestionMouvementRame(R_JOUEUR1,R_DIR_BAS,tempsEc);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8) && HumvsHum && !pauseBut)
            {
                controleurJ.gestionMouvementRame(R_JOUEUR2,R_DIR_HAUT,tempsEc);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2) && HumvsHum && !pauseBut)
            {
                controleurJ.gestionMouvementRame(R_JOUEUR2,R_DIR_BAS,tempsEc);
            }

            if(!HumvsHum && !pauseBut)
            {

                controleurJ.gestionMouvementRame(R_CPU,R_DIR_IA,tempsEc);
                if(tempsEc > 0.05f)
                {
                    horlIa.restart();
                }

            }


            if(!jeuPause)
            {
                controleurJ.gestMajD();
            }

            if(horl2.getElapsedTime().asSeconds() > 3.f)
            {
                pauseBut=false;
                horl2.restart();
            }


        }
        else
        {

        }


         fenetre.clear(Color(0,0,0));

         if(jeuEnCours)
         {
             controleurJ.afficheJeu();
         }
         else
         {
             controleurJ.afficheMenu();
         }


         //affiche tout a l'ecran
         fenetre.display();
    }



    return EXIT_SUCCESS;
}


