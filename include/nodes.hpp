/*  nodes.hpp

This header file declares all node classes.

*/

#pragma once

#include <string>

class NodeMap;
class ImANodeMap;

class Node {
    public:
        Node(std::string path, NodeMap& node_map, ImANodeMap& im_a_node_map);
        std::string get_path();
        void set_name(std::string name);
        std::string get_name();
        ~Node();
    private:
        std::string path;
        NodeMap& node_map;
};