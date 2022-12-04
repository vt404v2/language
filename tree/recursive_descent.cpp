#include "recursive_descent.h"

#define ADD_NODE                 \
    if (last_node)               \
    {                            \
        last_node->right = value;\
        last_node = value;       \
    }                            \
    else                         \
    {                            \
        root = value;            \
        last_node = value;       \
    }

#define IS_LOGICAL(operation)        \
    ((operation) == EQUAL_OP      || \
     (operation) == GREATER_OP    || \
     (operation) == BELOW_OP      || \
     (operation) == GREATER_EQ_OP || \
     (operation) == BELOW_EQ_OP   || \
     (operation) == NOT_EQ_OP     || \
     (operation) == NOT_OP        || \
     (operation) == OR_OP         || \
     (operation) == AND_OP)

#define IS_NAME_TOKEN(name)                                     \
strcasecmp((*name_table)[TOKEN.value.id_in_table], (name)) == 0

Node *recursiveDescent(Tokens *tokens,
                       size_t *index,
                       char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *root = nullptr;
    Node *last_node = root;

    while (*index < tokens->size)
    {
        Node *value = getLogOp(tokens, index, name_table);
        ADD_NODE
    }

    return root;
}

Node *getLogOp(Tokens *tokens,
               size_t *index,
               char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *leftValue = getAddSub(tokens, index, name_table);
    while (TOKEN.type == OPERATOR_TOKEN &&
        IS_LOGICAL(TOKEN.value.operation))
    {
        OperationType tokenValue = TOKEN.value.operation;
        (*index)++;

        Node *rightValue = getMulDiv(tokens, index, name_table);
        leftValue = createNewNode(OPERATOR,
                                  {.op_value = tokenValue},
                                  leftValue,
                                  rightValue);
    }

    return leftValue;
}

Node *getAddSub(Tokens *tokens,
                size_t *index,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *leftValue = getMulDiv(tokens, index, name_table);

    while (TOKEN.type == OPERATOR_TOKEN &&
        (TOKEN.value.operation == ADD_OP ||
            TOKEN.value.operation == SUB_OP))
    {
        OperationType tokenValue = TOKEN.value.operation;
        (*index)++;

        Node *rightValue = getMulDiv(tokens, index, name_table);
        leftValue = createNewNode(OPERATOR,
                                  {.op_value = tokenValue},
                                  leftValue,
                                  rightValue);
    }

    return leftValue;
}

Node *getMulDiv(Tokens *tokens,
                size_t *index,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *leftValue = getPow(tokens, index, name_table);

    while (TOKEN.type == OPERATOR_TOKEN &&
        (TOKEN.value.operation == MUL_OP ||
            TOKEN.value.operation == SUB_OP))
    {
        OperationType tokenValue = TOKEN.value.operation;
        (*index)++;

        Node *rightValue = getPow(tokens, index, name_table);
        leftValue = createNewNode(OPERATOR,
                                  {.op_value = tokenValue},
                                  leftValue,
                                  rightValue);

    }

    return leftValue;
}

Node *getPow(Tokens *tokens,
             size_t *index,
             char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *leftValue = getPrimaryExpression(tokens, index, name_table);
    Node *rightValue = nullptr;

    while (TOKEN.type == OPERATOR_TOKEN &&
        TOKEN.value.operation == POW_OP)
    {
        (*index)++;

        rightValue = getPow(tokens, index, name_table);
        leftValue = createNewNode(OPERATOR,
                                  {.op_value = POW_OP},
                                  leftValue,
                                  rightValue);
    }

    return leftValue;
}

//Node *getLog(Tokens *tokens)
//{
//    assert(tokens != nullptr);
//
//    Node *value = nullptr;
//
//    if (**program == 'l' && *((*program) + 1) == 'o'
//        && *((*program) + 2) == 'g')
//    {
//        (*program) += 3;
//        ASSERT_OK(**program == '(',
//                  "Expected (, but got _%c_\n",
//                  **program)
//        value = getSin(tokens);
//        value = createNewNode(OPERATION,
//                              {.op_value = LOG_OP},
//                              createNum(exp(1)),
//                              value);
//    }
//    else
//        value = getSin(tokens);
//
//    return value;
//}
//
//Node *getSin(Tokens *tokens)
//{
//    assert(tokens != nullptr);
//
//    Node *value = nullptr;
//
//    if (**program == 's' &&
//        *((*program) + 1) == 'i' &&
//        *((*program) + 2) == 'n')
//    {
//        (*program) += 3;
//        ASSERT_OK(**program == '(',
//                  "Expected (, but got _%c_\n",
//                  **program)
//        value = getCos(program);
//        value = createNewNode(OPERATION,
//                              {.op_value = SIN_OP},
//                              nullptr,
//                              value);
//    }
//    else
//        value = getCos(program);
//
//    return value;
//}
//
//Node *getCos(Tokens *tokens)
//{
//    assert(program != nullptr);
//    assert(*program != nullptr);
//
//    Node *value = nullptr;
//
//    if (**program == 'c' &&
//        *((*program) + 1) == 'o' &&
//        *((*program) + 2) == 's')
//    {
//        (*program) += 3;
//        ASSERT_OK(**program == '(',
//                  "Expected (, but got _%c_\n",
//                  **program)
//        value = getPrimaryExpression(program);
//        value = createNewNode(OPERATION,
//                              {.op_value = COS_OP},
//                              nullptr,
//                              value);
//    }
//    else
//        value = getPrimaryExpression(program);
//
//    return value;
//}

Node *getVarInit(Tokens *tokens,
                 size_t *index,
                 char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    if (TOKEN.type == KEYWORD_TOKEN &&
        !is_keyword((*name_table)[TOKEN.value.id_in_table]))
    {
        size_t variable_id = TOKEN.value.id_in_table;
        (*index)++;
        if (TOKEN.type == OPERATOR_TOKEN &&
            TOKEN.value.operation == EQUAL_OP)
        {
            (*index)++;
            Node *var_node = createNode(VARIABLE,
                                        {.var_value = variable_id},
                                        nullptr,
                                        nullptr);
            Node *init_value = getVarInit(tokens, index, name_table);
            if (init_value == nullptr)
                init_value = getLogOp(tokens, index, name_table);
            Node *init_node = createNode(OPERATOR,
                                         {.op_value=ASSIGN_OP},
                                         var_node,
                                         init_value);

            return createNode(FICTIVE_NODE, {}, init_node, nullptr);
        }
        (*index)--;
    }
    return nullptr;
}

Node *getVarDec(Tokens *tokens,
                size_t *index,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    if (TOKEN.type == KEYWORD_TOKEN &&
        (strcasecmp((*name_table)[TOKEN.value.id_in_table],
                    "var") == 0))
    {
        (*index)++;
        if (TOKEN.type == KEYWORD_TOKEN)
        {
            Node *declared_var = createNode(VAR_DEC,
                                            {.dec_value = TOKEN.value.id_in_table},
                                            nullptr,
                                            nullptr);
            (*index)++;

            Node *fictive_node = createNode(FICTIVE_NODE,
                                            {},
                                            declared_var,
                                            nullptr);
            return fictive_node;
        }
        (*index)--;
    }
    return nullptr;
}

Node *getIf(Tokens *tokens,
            size_t *index,
            char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("if"))
    {
        (*index)++;
        Node *condition_node =
            getPrimaryExpression(tokens, index, name_table);

        Node *positive_branch =
            getPrimaryExpression(tokens, index, name_table);
        Node *negative_branch = nullptr;

        if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("else"))
        {
            (*index)++;
            negative_branch =
                getPrimaryExpression(tokens, index, name_table);
        }

        Node *if2_node = createNode(IF2,
                                    {},
                                    positive_branch,
                                    negative_branch);
        Node *if_node = createNode(IF, {}, condition_node, if2_node);
        return createNode(FICTIVE_NODE,
                          {},
                          if_node, nullptr);
    }
    return nullptr;
}

Node *getWhile(Tokens *tokens,
               size_t *index,
               char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("while"))
    {
        (*index)++;
        Node *condition_node =
            getPrimaryExpression(tokens, index, name_table);
        Node *action = getPrimaryExpression(tokens, index, name_table);
        Node *while_node = createNode(WHILE,
                                      {},
                                      condition_node,
                                      action);
        return createNode(FICTIVE_NODE,
                          {},
                          while_node, nullptr);
    }
    return nullptr;
}

Node *getCodeBlock(Tokens *tokens,
                   size_t *index,
                   char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *root = nullptr;
    Node *last_node = root;

    while (*index < tokens->size)
    {
        Node *value = getLogOp(tokens, index, name_table);
        ADD_NODE
        if (TOKEN.type == BRACKET_TOKEN &&
            TOKEN.value.bracket == '}')
            break;
    }

    return root;
}

Node *getPrimaryExpression(Tokens *tokens,
                           size_t *index,
                           char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *value = getVarDec(tokens, index, name_table);
    if (value)
        return value;
    value = getVarInit(tokens, index, name_table);
    if (value)
        return value;
    value = getIf(tokens, index, name_table);
    if (value)
        return value;
    value = getWhile(tokens, index, name_table);
    if (value)
        return value;
    if (TOKEN.type == BRACKET_TOKEN &&
        TOKEN.value.bracket == '{')
    {
        (*index)++;
        value = getCodeBlock(tokens, index, name_table);
        ASSERT_OK(TOKEN.value.bracket == '}',
                  "Expected }, but got _%c_\n",
                  TOKEN.value.bracket)
        (*index)++;
    }
    else if (TOKEN.type == BRACKET_TOKEN &&
        TOKEN.value.bracket == '(')
    {
        (*index)++;

        value = getLogOp(tokens, index, name_table);
        ASSERT_OK(TOKEN.value.bracket == ')',
                  "Expected ), but got _%c_\n",
                  TOKEN.value.bracket)
        (*index)++;
    }
    else if (TOKEN.type == KEYWORD_TOKEN)
        value = getVariable(tokens, index);
    else
    {
        //        fprintf(stderr, "get value index: %zu\n", *index);
        value = getValue(tokens, index);
        //        fprintf(stderr, "after get value index: %zu\n", *index);
    }

    return value;
}

Node *getValue(Tokens *tokens, size_t *index)
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *value = createNewNode(NUMBER,
                                {.num_value =
                                tokens->tokens[*index].value.num_value},
                                nullptr,
                                nullptr);
    (*index)++;

    return value;
}

Node *getVariable(Tokens *tokens, size_t *index)
{
    assert(tokens != nullptr);

    Node *value = createNewNode(VARIABLE,
                                {.var_value = TOKEN.value.id_in_table},
                                nullptr,
                                nullptr);

    (*index)++;

    return value;
}

bool is_keyword(char *word)
{
    return strcasecmp(word, "if") == 0 ||
        strcasecmp(word, "else") == 0 ||
        strcasecmp(word, "while") == 0 ||
        strcasecmp(word, "var") == 0;
}