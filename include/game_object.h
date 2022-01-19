
#include <SFML/Graphics.hpp>
#include <string>

#include "node.h"

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject : public Node
{
    private:

    public:
        sf::Vector2f size;
        sf::Vector2f position;
        sf::RectangleShape shape;
        
        GameObject();
        void Update();
        void Instantiate();

        void Draw();
        void Draw(sf::RenderWindow *window);
        void Move(int x, int y);
        void Move(sf::Vector2f velocity);

        //Getters
        sf::Vector2f getSize() { return size; }
        sf::Vector2f getPosition() { return position; }
        sf::RectangleShape getShape() { return shape; }

        //Setters
        void setSize(sf::Vector2f new_scale);
        void setSize(float x, float y);
        void setShape(sf::RectangleShape new_shape);
        void setShapeFillColor(sf::Color color);
        void setPosition(sf::Vector2f position);
        void setPosition(float x, float y);
};

#endif