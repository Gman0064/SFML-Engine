
#include <SFML/Graphics.hpp>
#include <string>

#include "game_object.h"

#include "box2d/b2_body.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"

#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

class PhysicsObject : public GameObject
{
    private:
        const int PHYS_SCALE = 10;
        bool dynamic = false;
        float density = 1.0;
        float friction = 0.3;
        b2BodyDef bodyDef;
        b2Body* physics_body = NULL;
        b2PolygonShape physics_shape;
        

    public:
        PhysicsObject(bool is_dynamic);
        void Update();
        void Instantiate();
};

#endif