#include <SFML/Graphics.hpp>
#include <string>

#include "game_object.h"

// Physics
#include "box2d/b2_body.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"


#ifndef GAME_H
#define GAME_H

class Game
{
    private:
        int max_framerate = 60;
        int velocityIterations = 6;
        int positionIterations = 2;
        float timeStep = 1.0f / (float)max_framerate;
        std::string window_name;
        sf::Vector2f window_size;
        std::vector<GameObject*> game_objects;
    public:
        Game(std::string name, sf::Vector2f size);
        //int Run();
        //void Close();
};

#endif