#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_node.hpp"
#include "ast/ast_primitives.hpp"
///#include "ast/ast_functions.hpp"
#include "ast/ast_body.hpp"
#include "ast/ast_listnode.hpp"
#include "ast/ast_declaration.hpp"

#include "ast/Function/ast_function.hpp"
#include "ast/Keyword/ast_return.hpp"
#include "ast/Types/ast_types.hpp"
#include "ast/Operators/ast_arithmetic.hpp"
#include "ast/Operators/ast_unary.hpp"


extern const Node *parseAST(std::string file);

#endif
