/*  nodes.cpp

This source file defines all node classes.

*/

#include <string>

#include "nodes.hpp"

std::string Node::get_path() {
    return path;
};

void Node::set_name(std::string name) {
    size_t last_period = path.rfind(".");
    if (last_period == std::string::npos) {
        path = name;
        return;
    };
    path = path.substr(0, last_period + 1) + name;
};

std::string Node::get_name() {
    size_t last_period = path.rfind(".");
    if (last_period == std::string::npos) {
        return path;
    };
    return path.substr(last_period + 1);
};

Node::Node(std::string path, NodeMap& node_map, ImANodeMap& im_a_node_map) : path(path), node_map(node_map) {
    
};

Node::~Node() = default;