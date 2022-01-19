// Util
#include <SFML/Graphics.hpp>
#include <iostream>

// Physics
#include "../include/box2d/b2_body.h"
#include "../include/box2d/b2_world.h"
#include "../include/box2d/b2_polygon_shape.h"
#include "../include/box2d/b2_fixture.h"

// Engine Related
#include "../include/game.h"
#include "../include/node.h"
#include "../include/scene.h"
#include "../include/game_object.h"
#include "../include/physics_object.h"


Game::Game(std::string name, sf::Vector2f size) {
    window_name = name;
    window_size = size;
    sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), window_name);
    window.setFramerateLimit(max_framerate);

    Scene* root = new Scene();

    GameObject* platform = new GameObject();
    platform->appendToParent(root);
    platform->setShapeFillColor(sf::Color::Red);
    platform->setPosition(sf::Vector2f(0, 100));
    platform->setSize(200, 20);

    // Platform
    GameObject* platform2 = new GameObject();
    platform2->appendToParent(root);
    platform2->setShapeFillColor(sf::Color::Red);
    platform2->setPosition(sf::Vector2f(0, 200));
    platform2->setSize(200, 20);


    // Dynamic Object
    PhysicsObject* player = new PhysicsObject(true);
    player->appendToParent(root);
    player->setShapeFillColor(sf::Color::Green);
    player->setPosition(sf::Vector2f(0, 0));
    player->setSize(200, 20);


    window.setActive();


    Node::printNodeTree(root);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear();
        
        root->Draw(&window);

        //player->Update();

        window.display();
    }
}