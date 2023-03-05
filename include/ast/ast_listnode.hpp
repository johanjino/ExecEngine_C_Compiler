#ifndef ast_listnode_hpp
#define ast_listnode_hpp

#include <string>
#include <iostream>
#include <vector>

#include "ast_node.hpp"

typedef std::vector<NodePtr> List;
typedef List *ListPtr;

// Functions to be used in parser for instantiation / concatenation
inline ListPtr init_list(NodePtr expr){
  ListPtr exprList = new List(); // Potentially replace with Nodelist(NodePtr) constructor
  exprList->push_back(expr);
  return exprList;
}

inline ListPtr concat_list(NodePtr expr, ListPtr exprList){
  exprList->push_back(expr);
  return exprList;
}

#endif
