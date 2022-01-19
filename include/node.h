#include <string>
#include <vector>

#include "util.h"

#ifndef NODE_H
#define NODE_H

class Node
{
    private:

    public:
        std::string name;
        Node* parent = NULL;
        std::vector<Node*> children;

        Node() {
            name = "Node-" + Util::gen_uid();
        };

        std::string getName() { return name; }

        Node* getParent() { return parent; };
        Node* getChild(int index) { return children[index]; }
        std::vector<Node*> getChildren() { return children; };
        
        void appendChild(Node *new_child){
            children.push_back(new_child);
            new_child->parent = this;
        };

        void appendToParent(Node *new_parent){
            parent = new_parent;
            parent->appendChild(this);
        };

        static void printNodeTree(Node* node, int level=0);
};

#endif