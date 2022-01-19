#include <iostream>

#include "../include/physics_object.h"
//#include "../include/game.h"
#include "../include/node.h"
#include "../include/scene.h"
#include "../include/util.h"

#include "../include/box2d/b2_body.h"
#include "../include/box2d/b2_world.h"
#include "../include/box2d/b2_polygon_shape.h"
#include "../include/box2d/b2_fixture.h"


PhysicsObject::PhysicsObject(bool is_dynamic) : GameObject() {
    // Constructor
    name = "PhysicsObject-" + Util::gen_uid();
    size = sf::Vector2f(10.0, 10.0);
    position = sf::Vector2f(0, 0);
    shape = sf::RectangleShape(size);
    dynamic = is_dynamic;
    bodyDef.position.Set(-position.x / PHYS_SCALE, -position.y / PHYS_SCALE);
    physics_shape.SetAsBox(size.x / PHYS_SCALE, size.y / PHYS_SCALE);
}

void PhysicsObject::Update() {
    if (physics_body) {
        b2Vec2 physics_position = physics_body->GetPosition();
        setPosition(physics_position.x * PHYS_SCALE, -physics_position.y * PHYS_SCALE);
        std::cout << physics_position.y << std::endl;
    } else {
        Scene* parent = (Scene*) getParent();

        if (parent) {
            if (dynamic == true) {
                bodyDef.type = b2_dynamicBody;

                b2FixtureDef fixtureDef;
                fixtureDef.shape = &physics_shape;
                fixtureDef.density = 1.0f;
                fixtureDef.friction = 0.3f;
                
                physics_body = parent->world.CreateBody(&bodyDef);
                physics_body->CreateFixture(&fixtureDef);
            } 
            else {
                bodyDef.type = b2_staticBody;
                physics_body = parent->world.CreateBody(&bodyDef);
                physics_body->CreateFixture(&physics_shape, 0.0f);
            }
        } else {
            std::cout << "[Error] Physics body does not have scene parent" << std::endl;
        }
    }
}