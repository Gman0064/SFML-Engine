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
#include "../include/tilemap.h"


Game::Game(std::string name, sf::Vector2f size) {
    window_name = name;
    window_size = size;
    sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), window_name);
    window.setFramerateLimit(max_framerate);

    Scene* root = new Scene();


    // // Platform Two
    // PhysicsObject* platform2 = new PhysicsObject(false);
    // platform2->appendToParent(root);
    // platform2->setShapeFillColor(sf::Color::Red);
    // platform2->setPosition(sf::Vector2f(0, 600));
    // platform2->setSize(800, 20);

    // // Dynamic Object
    // PhysicsObject* player = new PhysicsObject(true);
    // player->appendToParent(root);
    // player->setShapeFillColor(sf::Color::Green);
    // player->setPosition(sf::Vector2f(0, 0));
    // player->setSize(20, 20);


    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    TileMap* map = new TileMap("tileset.png");

    //map->appendToParent(root);

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

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(window).x,
                                              sf::Mouse::getPosition(window).y);

                // Dynamic Object
                // PhysicsObject* new_block = new PhysicsObject(true);
                // new_block->appendToParent(root);
                // new_block->setShapeFillColor(sf::Color::Blue);
                // new_block->setPosition(pos);
                // new_block->setSize(20, 20);

                // Node::printNodeTree(root);
            }
        }

        window.clear();

        root->world.Step(max_framerate, 6, 2);

        root->Draw(&window);

        root->Update();

        window.display();
    }
}