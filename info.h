#ifndef DEF_INFO
#define DEF_INFO

#include <SFML/Graphics.hpp>
#include <iostream>
#include "varGlob.h"
#include "constantes.h"
#include "enums.h"
#include <sstream>


class Info
{
public:
    Info(sf::RenderWindow& fenetre);
    template <class T> std::string nbEnString(T nb);
    void initInfo();
    void reinitInfo();
    void afficheInfo();
    void indiquerScore();
    int getScore(int num_joueur);
    void gestionScore(int num_joueur);


    ~Info();



private:
    sf::Text m_txtScoreJ1;
    sf::Text m_txtScoreJ2;
    sf::Text m_txtPause;
    sf::Font m_font1,m_font2;
    int m_score[2];
    sf::RenderWindow *m_fenetre;


};

#endif // DEF_INFO
