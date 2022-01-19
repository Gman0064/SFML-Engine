#include <iostream>

#include "../include/node.h"
#include "../include/util.h"
#include "../include/game_object.h"

void Node::printNodeTree(Node* node, int level) {
    for (int i = 1; i < level; i++) {
        std::cout << '\t';
    }
    if (level > 0) {
        std::cout << "    └───";
    }
    std::cout << node->name << std::endl;
    if (node->children.size() > 0) {
        for (int i = 0; i < node->children.size(); i++) {
            GameObject* child = (GameObject*)node->children[i];
            Node::printNodeTree(child, (level + 1));
        }
    }
}