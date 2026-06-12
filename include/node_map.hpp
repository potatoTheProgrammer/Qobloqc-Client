/*  node_map.hpp

This header file declares node maps.

*/

#pragma once

#include <map>
#include <string>

class Node;

class ImANodeMap {
    private:
        ImANodeMap() = default;
        friend class NodeMap;
};

class NodeMap {
    public:
        Node* create_node(std::string node_class_name, std::string path);
        Node* get_node_from_path(std::string path);
        bool validate_node_path(std::string path);
    private:
        std::map<std::string, std::unique_ptr<Node>> nodes;
        static ImANodeMap im_a_node_map;
};