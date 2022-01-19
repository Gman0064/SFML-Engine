#include <SFML/Graphics.hpp>
#include <string>

#include "node.h"

#include "box2d/b2_world.h"


#ifndef SCENE_H
#define SCENE_H

class Scene : public Node
{
    private:
        
    public:
        Scene();
        void Draw(sf::RenderWindow *window);
        void PrintTree();
        b2Vec2 gravity;
        b2World world;
};

#endif