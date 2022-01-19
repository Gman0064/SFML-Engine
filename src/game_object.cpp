#include <iostream>

#include "../include/box2d/b2_body.h"
#include "../include/game.h"
#include "../include/game_object.h"
#include "../include/util.h"

GameObject::GameObject() : Node()
{
    // Constructor
    name = "GameObject-" + Util::gen_uid();
    size = sf::Vector2f(10.0, 10.0);
    position = sf::Vector2f(0, 0);
    shape = sf::RectangleShape(size);
}

void GameObject::Update() {
    // Template implementation, gets called each frame
}

void GameObject::Instantiate() {
    
}

void GameObject::Draw() {
    //windowshape
}

void GameObject::Draw(sf::RenderWindow *window) {
    (*window).draw(shape);
    std::vector<Node*> children = getChildren();
    if (children.size() > 0) {
        for (int i = 0; i < getChildren().size(); i++) {
            GameObject* child = (GameObject*)children[i];
            child->Draw(window);
        }
    }
}

void GameObject::Move(sf::Vector2f velocity) {
    shape.move(velocity.x, velocity.y);
}

void GameObject::Move(int x, int y) {
    shape.move(x, y);
}

void GameObject::setShapeFillColor(sf::Color new_color) {
    shape.setFillColor(new_color);
}

void GameObject::setPosition(sf::Vector2f new_position) {
    shape.setPosition(new_position);
    position = new_position;
}

void GameObject::setPosition(float x, float y) {
    sf::Vector2f new_position = sf::Vector2f(x, y);
    shape.setPosition(new_position);
    position = new_position;
}

void GameObject::setSize(sf::Vector2f new_size) {
    sf::Vector2f old_position = getPosition();
    sf::Color old_color = shape.getFillColor();
    shape = sf::RectangleShape(new_size);
    shape.setFillColor(old_color);
    shape.setPosition(old_position);
}

void GameObject::setSize(float x, float y) {
    sf::Vector2f old_position = getPosition();
    sf::Color old_color = shape.getFillColor();
    sf::Vector2f new_size = sf::Vector2f(x, y);
    shape = sf::RectangleShape(new_size);
    shape.setFillColor(old_color);
    shape.setPosition(old_position);
}