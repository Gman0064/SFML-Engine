#include <iostream>

#include "../include/scene.h"
#include "../include/game_object.h"
#include "../include/util.h"
#include "../include/node.h"

#include "../include/box2d/b2_world.h"


Scene::Scene() : Node(), world(gravity) {
    name = "Scene-" + Util::gen_uid();
    b2Vec2 gravity(0.0f, -20.0f);
    world = b2World(gravity);
}

void Scene::Draw(sf::RenderWindow *window) {
    std::vector<Node*> children = getChildren();
    if (children.size() > 0) {
        for (int i = 0; i < getChildren().size(); i++) {
            GameObject* child = (GameObject*)children[i];
            child->Draw(window);
        }
    }
}


void Scene::Update() {
    std::vector<Node*> children = getChildren();
    if (children.size() > 0) {
        for (int i = 0; i < getChildren().size(); i++) {
            children[i]->Update();
        }
    }
}