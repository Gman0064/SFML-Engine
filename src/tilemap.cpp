#include <iostream>

#include "../include/tilemap.h"


TileMap::TileMap(const std::string& tileset_path) : Node() {
    name = "TileMap-" + Util::gen_uid();
    position = sf::Vector2f(0, 0);

    if (m_tileset.loadFromFile(tileset_path)) {

        sf::Vector2u tileSize = sf::Vector2u(16, 16);

        int* tiles = 0;

        int width = 10;
        int height = 10;

        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // for (int i = 0; i < width; ++i) {
        //     for (int j = 0; j < height; ++j) {
                
        //         int tileNumber = tiles[i + j * width];

        //         int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
        //         int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

        //         sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

        //         // define its 4 corners
        //         quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
        //         quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
        //         quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
        //         quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

        //         // define its 4 texture coordinates
        //         quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
        //         quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
        //         quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
        //         quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        //     }
        // }
    } else {
        std::cout << "Could not load image from path to tilemap" << std::endl;
    }

}

void TileMap::Draw(sf::RenderWindow *window) {
    //(*window).draw(m_vertices);
    // (*window).draw(shape);
    // std::vector<Node*> children = getChildren();
    // if (children.size() > 0) {
    //     for (int i = 0; i < getChildren().size(); i++) {
    //         GameObject* child = (GameObject*)children[i];
    //         child->Draw(window);
    //     }
    // }
}

void TileMap::Instantiate() {

}

void TileMap::Update() {

}