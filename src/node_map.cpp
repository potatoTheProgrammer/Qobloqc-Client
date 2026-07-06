/*  node_map.cpp

This source file defines node maps.

*/

#include <map>
#include <memory>
#include <iostream>
#include <vector>

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

void NodeMap::list_nodes() {
    for (const auto& [key, value] : nodes) {
        std::cout << key << std::endl;
    };
};

std::vector<Node*> NodeMap::get_nodes_with_prefix(std::string prefix) {
    std::vector<Node*> node_vector;
    
    auto node_iterator = nodes.lower_bound(prefix);
    while (node_iterator != nodes.end()) {
        if (node_iterator -> first.rfind(prefix, 0) == 0) {
            node_vector.push_back(node_iterator -> second.get());
            ++node_iterator;
        } else {
            break;
        };
    };
    
    return node_vector;
};

std::vector<std::string> NodeMap::get_node_keys_with_prefix(std::string prefix) {
    std::vector<std::string> key_vector;
    
    auto node_iterator = nodes.lower_bound(prefix);
    while (node_iterator != nodes.end()) {
        if (node_iterator -> first.rfind(prefix, 0) == 0) {
            key_vector.push_back(node_iterator -> first);
            ++node_iterator;
        } else {
            break;
        };
    };
    
    return key_vector;
};

void NodeMap::delete_node(Node* node) {
    std::string input_node_path = node -> get_path();
    
    std::string start_path = input_node_path + ".";
    auto start_iterator = nodes.lower_bound(start_path);
    
    std::string end_path = start_path;
    end_path.back()++;
    auto end_iterator = nodes.lower_bound(end_path);
    
    nodes.erase(input_node_path);
    nodes.erase(start_iterator, end_iterator);
};