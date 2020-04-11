#ifndef DEF_DECOR
#define DEF_DECOR

#include <iostream>
#include <SFML/Graphics.hpp>
#include "varGlob.h"
#include "enums.h"
#include "constantes.h"
#include "menu.h"
#include "balle.h"
#include "rame.h"
#include "son.h"
#include "info.h"


class Decor
{
public:
    Decor(sf::RenderWindow &fenetre);
    ~Decor();

    void gestMajD();
    void initInfo();
    void gestionTourIA(float temps_ec);
    Rame& getRame();
    Balle& getBalle();
    Info& getInfo();

    void retourMenu();
    void finJeu();
    void gestionDplSouris();
    void gestionSelectionSouris();
    void inverserAngleBalle();
    void afficherJeu();
    void afficherMenu();




private:
    sf::RenderWindow *m_fenetre;
    Rame* m_rame;
    Balle* m_balle;
    Menu* m_menu;
    Info* m_info;
    Son* m_son;
    sf::Texture m_t_fondEc;
    sf::Sprite m_s_fondEc;

};


#endif // DEF_DECOR
