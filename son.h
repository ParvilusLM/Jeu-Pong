#ifndef DEF_SON
#define DEF_SON

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "varGlob.h"
#include "constantes.h"
#include "enums.h"

class Son
{
public:
    Son();
    ~Son();
    void jouerSon(int num_son);
    void pauseSon(int num_son);


private:

    sf::SoundBuffer m_balleSoundBuf;
    sf::Sound m_sonBalle;
    sf::SoundBuffer m_musiqueFondBuf;
    sf::Sound m_musiqueFond;

};

#endif // DEF_SON
