#include "SFML/Graphics.hpp"

#include "node.h"

#ifndef TILEMAP_H
#define TILEMAP_H

class TileMap : public Node {
    private:
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
    public:
        sf::Vector2f size;
        sf::Vector2f position;
        
        TileMap(const std::string& tileset_path);
        virtual void Update();
        void Instantiate();

        //void Draw();
        void Draw(sf::RenderWindow *window);
};

#endif