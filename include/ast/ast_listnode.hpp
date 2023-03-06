#ifndef ast_listnode_hpp
#define ast_listnode_hpp

#include <string>
#include <iostream>
#include <vector>

#include "ast_node.hpp"

typedef std::vector<NodePtr> List;
typedef List *ListPtr;

// Functions to be used in parser for instantiation / concatenation
inline ListPtr init_list(NodePtr node){
  ListPtr nodeList = new List(); // Potentially replace with Nodelist(NodePtr) constructor
  nodeList->push_back(node);
  return nodeList;
}

inline ListPtr concat_list(NodePtr node, ListPtr nodeList){
  nodeList->push_back(node);
  return nodeList;
}

#endif
