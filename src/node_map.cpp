/*  node_map.cpp

This source file defines node maps.

*/

#include <map>
#include <memory>
#include <iostream>

#include "node_map.hpp"
#include "nodes.hpp"

ImANodeMap NodeMap::im_a_node_map{};

Node* NodeMap::create_node(std::string node_class_name, std::string path) {
    
    if (!(validate_node_path(path) and nodes.find(path) == nodes.end())) {
        std::cout << "Node creation failed" << std::endl << std::endl;
        return nullptr;
    };
    
    // i know this wall of if statements looks stupid but it works and the complexity of the alternative is equally stupid
    // ok theres no wall just yet but there will be one in the future
    if (node_class_name == "Node") {
        nodes[path] = std::make_unique<Node>(path, *this, im_a_node_map);
    } else {
        return nullptr;
    };
    
    std::cout << "Node successfully created" << std::endl << std::endl;
    return nodes[path].get();
};

Node* NodeMap::get_node_from_path(std::string path) {
    auto node_iterator = nodes.find(path);
    if (node_iterator != nodes.end()) {
        return node_iterator -> second.get();
    };
    return nullptr;
};

bool NodeMap::validate_node_path(std::string path) {
    if (path.empty()) { // Check that the path is not empty
        std::cout << "Empty path" << std::endl;
        return false;
    };
    if (nodes.find(path.substr(0, path.rfind("."))) == nodes.end() and path.find(".") != std::string::npos) { // Check if parent node exists
        std::cout << "No parent node" << std::endl;
        return false;
    };
    if (path.find("..") != std::string::npos) { // Check for 2 periods next to each other
        std::cout << "Multiple adjacent periods" << std::endl;
        return false;
    };
    if (path[0] == '.' or path.back() == '.') { // Check that the path doesn't start or end with a period
        std::cout << "Starts or ends with period" << std::endl;
        return false;
    };
    
    return true;
};