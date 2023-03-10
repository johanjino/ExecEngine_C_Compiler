#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_node.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_listnode.hpp"
#include "ast/ast_declaration.hpp"
#include "ast/ast_output.hpp"

#include "ast/Function/ast_function.hpp"
#include "ast/Keyword/ast_return.hpp"
#include "ast/Types/ast_types.hpp"
#include "ast/Arrays/ast_arrays.hpp"

#include "ast/Types/ast_enum.hpp"
#include "ast/Types/ast_strings_chars.hpp"
#include "ast/Types/ast_struct_union.hpp"

#include "ast/Blocks/ast_block.hpp"
#include "ast/Blocks/ast_ifelse.hpp"
#include "ast/Blocks/ast_forloop.hpp"
#include "ast/Blocks/ast_whileloop.hpp"
#include "ast/Blocks/ast_switch_case.hpp"

#include "ast/Operators/ast_arithmetic.hpp"
#include "ast/Operators/ast_relational.hpp"
#include "ast/Operators/ast_unary.hpp"
#include "ast/Operators/ast_logical.hpp"
#include "ast/Operators/ast_assign.hpp"
#include "ast/Operators/ast_bitwise.hpp"
#include "ast/Operators/ast_shift.hpp"


extern const Node *parseAST(std::string file);

#endif
