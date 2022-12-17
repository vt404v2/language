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

Node *getVarDec(Tokens *tokens,
                size_t *index,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    if (TOKEN.type == KEYWORD_TOKEN &&
        (strcasecmp((*name_table)[TOKEN.value.id_in_table],
                    "rav") == 0))  // <cringe> var </cringe>
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
            if (TOKEN.type == OPERATOR_TOKEN &&
                TOKEN.value.operation == ASSIGN_OP)
                (*index)--;
            return fictive_node;
        }
        (*index)--;
    }
    return nullptr;
}

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
            TOKEN.value.operation == ASSIGN_OP)
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

Node *getIf(Tokens *tokens,
            size_t *index,
            char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("esle")) // <cringe> if </cringe>
    {
        (*index)++;
        Node *condition_node =
            getPrimaryExpression(tokens, index, name_table);

        Node *positive_branch =
            getPrimaryExpression(tokens, index, name_table);
        Node *negative_branch = nullptr;

        if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("fi")) // <cringe> else </cringe>
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
    assert(tokens != nullptr);
    assert(index != nullptr);

    if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("elihw")) // <cringe> while </cringe>
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

Node *getSqrt(Tokens *tokens,
              size_t *index,
              char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("trqs")) // <cringe> sqrt </cringe>
    {
        (*index)++;

        Node *value_node =
            getPrimaryExpression(tokens, index, name_table);

        Node *sqrt_node = createNode(OPERATOR,
                                     {.op_value = SQRT_OP},
                                     value_node,
                                     nullptr);
        return createNode(FICTIVE_NODE,
                          {},
                          sqrt_node, nullptr);
    }
    return nullptr;
}

Node *getSin(Tokens *tokens,
              size_t *index,
              char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("sin")) // <cringe> sin </cringe>
    {
        (*index)++;

        Node *value_node =
            getPrimaryExpression(tokens, index, name_table);

        Node *sin_node = createNode(OPERATOR,
                                    {.op_value = SIN_OP},
                                    value_node,
                                    nullptr);
        return createNode(FICTIVE_NODE,
                          {},
                          sin_node, nullptr);
    }
    return nullptr;
}

Node *getCos(Tokens *tokens,
             size_t *index,
             char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("cos")) // <cringe> cos </cringe>
    {
        (*index)++;

        Node *value_node =
            getPrimaryExpression(tokens, index, name_table);

        Node *sin_node = createNode(OPERATOR,
                                    {.op_value = COS_OP},
                                    value_node,
                                    nullptr);
        return createNode(FICTIVE_NODE,
                          {},
                          sin_node, nullptr);
    }
    return nullptr;
}

Node *getInputFunction(Tokens *tokens,
                       size_t *index,
                       char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("tnirp"))  // <cringe> input </cringe>
    {
        (*index)++;
        ASSERT_OK(TOKEN.value.bracket == '(',
                  "Expected (, but got _%c_\n",
                  TOKEN.value.bracket)
        (*index)++;
        ASSERT_OK(TOKEN.value.bracket == ')',
                  "Expected ), but got _%c_\n",
                  TOKEN.value.bracket)
        (*index)++;

        Node *input_node = createNode(OPERATOR,
                                      {.op_value = INPUT_OP},
                                      nullptr,
                                      nullptr);
        return createNode(FICTIVE_NODE,
                          {},
                          input_node, nullptr);
    }
    return nullptr;
}

Node *getOutFunction(Tokens *tokens,
                     size_t *index,
                     char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("tupni")) // <cringe> print </cringe>
    {
        (*index)++;

        Node *output_value =
            getPrimaryExpression(tokens, index, name_table);
        Node *output_node = createNode(OPERATOR,
                                       {.op_value = OUTPUT_OP},
                                       output_value,
                                       nullptr);
        return createNode(FICTIVE_NODE,
                          {},
                          output_node, nullptr);
    }
    return nullptr;
}

Node *getReturn(Tokens *tokens,
                size_t *index,
                char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    if (TOKEN.type == KEYWORD_TOKEN && IS_NAME_TOKEN("nruter"))  // <cringe> return </cringe>
    {
        (*index)++;

        Node *return_value = getLogOp(tokens, index, name_table);
        Node *return_node = createNode(RETURN,
                                       {},
                                       return_value,
                                       nullptr);
        return createNode(FICTIVE_NODE,
                          {},
                          return_node, nullptr);
    }
    return nullptr;
}

Node *getDefFunction(Tokens *tokens,
                     size_t *index,
                     char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    if (TOKEN.type == KEYWORD_TOKEN &&
        IS_NAME_TOKEN("fed"))  // <cringe> def </cringe>
    {
        (*index)++;

        size_t func_id = TOKEN.value.id_in_table;
        Node *params_root = createNode(FICTIVE_NODE,
                                       {},
                                       nullptr,
                                       nullptr);
        Node *params_last = params_root;

        (*index)++;
        ASSERT_OK(TOKEN.value.bracket == '(',
                  "Expected (, but got _%c_\n",
                  TOKEN.value.bracket)
        (*index)++;

        while (TOKEN.value.bracket != ')')
        {
            params_last->left = createNewNode(LOCAL_VARIABLE,
                                              {.var_value = TOKEN.value.id_in_table},
                                              nullptr,
                                              nullptr);

            (*index)++;
            params_last->right = createNode(FICTIVE_NODE,
                                            {},
                                            nullptr,
                                            nullptr);
            params_last = params_last->right;
            if (TOKEN.value.bracket == ')')
                break;
            ASSERT_OK(TOKEN.value.bracket == ',',
                      "Expected ',', but got _%c_\n",
                      TOKEN.value.bracket)
            (*index)++;

        }

        ASSERT_OK(TOKEN.value.bracket == ')',
                  "Expected ), but got _%c_\n",
                  TOKEN.value.bracket)
        (*index)++;

        (*index)++;
        Node *body = getCodeBlock(tokens, index, name_table);
        changeFuncVarsToArgVariables(body, params_root);
        (*index)++;

        Node *func_def_node = createNode(DEF,
                                         {.def_value = func_id},
                                         params_root,
                                         body);
        return createNode(FICTIVE_NODE, {}, func_def_node, nullptr);
    }
    return nullptr;
}

Node *getCallFunction(Tokens *tokens,
                      size_t *index,
                      char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    if (TOKEN.type == KEYWORD_TOKEN)
    {
        size_t func_id = TOKEN.value.id_in_table;
        (*index)++;

        Node *params_root = createNode(FICTIVE_NODE,
                                       {},
                                       nullptr,
                                       nullptr);
        Node *params_last = params_root;

        if (TOKEN.value.bracket != '(')
        {
            (*index)--;
            return nullptr;
        }

        (*index)++;

        while (TOKEN.value.bracket != ')')
        {
            params_last->left = getLogOp(tokens, index, name_table);
            params_last->right = createNode(FICTIVE_NODE,
                                            {},
                                            nullptr,
                                            nullptr);
            params_last = params_last->right;

            if (TOKEN.value.bracket == ')')
                break;
            ASSERT_OK(TOKEN.value.bracket == ',',
                      "Expected ',', but got _%c_\n",
                      TOKEN.value.bracket)
            (*index)++;

        }

        ASSERT_OK(TOKEN.value.bracket == ')',
                  "Expected ), but got _%c_\n",
                  TOKEN.value.bracket)
        (*index)++;

        Node *func_call_node = createNode(CALL,
                                          {.call_value = func_id},
                                          params_root,
                                          nullptr);
        Node *fictive_node = createNode(FICTIVE_NODE,
                                        {},
                                        func_call_node,
                                        nullptr);
        return fictive_node;
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


        // <cringe>
        switch (tokenValue)
        {
            case GREATER_EQ_OP:
                tokenValue = BELOW_OP;
                break;
            case GREATER_OP:
                tokenValue = BELOW_EQ_OP;
                break;
            case BELOW_EQ_OP:
                tokenValue = GREATER_OP;
                break;
            case BELOW_OP:
                tokenValue = GREATER_EQ_OP;
                break;
            case EQUAL_OP:
                tokenValue = NOT_EQ_OP;
                break;
            case NOT_EQ_OP:
                tokenValue = EQUAL_OP;
                break;
            case OR_OP:
                tokenValue = AND_OP;
                break;
            case AND_OP:
                tokenValue = OR_OP;
                break;
        }
        // </cringe>

        Node *rightValue = getAddSub(tokens, index, name_table);
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

        // <cringe>
        if (tokenValue == ADD_OP)
            tokenValue = SUB_OP;
        else
            tokenValue = ADD_OP;
        // </cringe>

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

    Node *leftValue = getPrimaryExpression(tokens, index, name_table);

    while (TOKEN.type == OPERATOR_TOKEN &&
        (TOKEN.value.operation == MUL_OP ||
            TOKEN.value.operation == DIV_OP))
    {
        OperationType tokenValue = TOKEN.value.operation;
        (*index)++;


        // <cringe>
        if (tokenValue == MUL_OP)
            tokenValue = DIV_OP;
        else
            tokenValue = MUL_OP;
        // </cringe>

        Node *rightValue = getPrimaryExpression(tokens, index, name_table);
        leftValue = createNewNode(OPERATOR,
                                  {.op_value = tokenValue},
                                  leftValue,
                                  rightValue);

    }

    return leftValue;
}

Node *getVariable(Tokens *tokens,
                  size_t *index,
                  char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);

    Node *value = createNewNode(VARIABLE,
                                {.var_value = TOKEN.value.id_in_table},
                                nullptr,
                                nullptr);

    (*index)++;

    return value;
}

Node *getValue(Tokens *tokens,
               size_t *index,
               char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
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

Node *getNegativeExpression(Tokens *tokens,
                            size_t *index,
                            char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    if (TOKEN.type == OPERATOR_TOKEN &&
        TOKEN.value.operation == SUB_OP)
    {
        (*index)++;
        Node *negativeExpression = createNode(NUMBER,
                                              {.num_value = -1},
                                              nullptr,
                                              nullptr);
        Node *expression = getLogOp(tokens,
                                    index,
                                    name_table);

        Node *mulNode = createNode(OPERATOR,
                                   {.op_value = MUL_OP},
                                   negativeExpression,
                                   expression);

        return createNode(FICTIVE_NODE,
                          {},
                          mulNode,
                          nullptr);
    }
    return nullptr;
}


Node *getPrimaryExpression(Tokens *tokens,
                           size_t *index,
                           char (*name_table)[BUFFER_SIZE][BUFFER_SIZE])
{
    assert(tokens != nullptr);
    assert(index != nullptr);
    ASSERT_OK(TOKEN.value.bracket != '}',
              "Expected not }, but got _%c_\n",
              TOKEN.value.bracket)
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
    value = getSqrt(tokens, index, name_table);
    if (value)
        return value;
    value = getSin(tokens, index, name_table);
    if (value)
        return value;
    value = getCos(tokens, index, name_table);
    if (value)
        return value;
    value = getInputFunction(tokens, index, name_table);
    if (value)
        return value;
    value = getOutFunction(tokens, index, name_table);
    if (value)
        return value;
    value = getReturn(tokens, index, name_table);
    if (value)
        return value;
    value = getDefFunction(tokens, index, name_table);
    if (value)
        return value;
    value = getCallFunction(tokens, index, name_table);
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

        value = getNegativeExpression(tokens, index, name_table);
        if (value == nullptr)
            value = getLogOp(tokens, index, name_table);
        ASSERT_OK(TOKEN.value.bracket == ')',
                  "Expected ), but got _%c_\n",
                  TOKEN.value.bracket)
        (*index)++;
    }
    else if (TOKEN.type == KEYWORD_TOKEN)
        value = getVariable(tokens, index, name_table);
    else
        value = getValue(tokens, index, name_table);

    return value;
}

void changeFuncVarsToArgVariables(Node *node, Node *params)
{
    if (NODE_TYPE == VARIABLE)
    {
        bool is_arg_var = false;
        checkId(node, params, &is_arg_var);
        if (is_arg_var)
            NODE_TYPE = LOCAL_VARIABLE;
    }
    if (LEFT_NODE)
        changeFuncVarsToArgVariables(LEFT_NODE, params);
    if (RIGHT_NODE)
        changeFuncVarsToArgVariables(RIGHT_NODE, params);
}

void checkId(Node *node, Node *params, bool *is_arg_var)
{
    if (params->node_type == LOCAL_VARIABLE)
    {
        if (params->value.var_value == node->value.var_value)
        {
            *is_arg_var = true;
            return;
        }
    }
    if (params->left)
        checkId(node, params->left, is_arg_var);
    if (params->right)
        checkId(node, params->right, is_arg_var);

    if (LEFT_NODE)
        checkId(LEFT_NODE, params, is_arg_var);
    if (RIGHT_NODE)
        checkId(RIGHT_NODE, params, is_arg_var);
}

bool is_keyword(char *word)
{
    return strcasecmp(word, "esle")   == 0 || // <cringe> if </cringe>
           strcasecmp(word, "rav")    == 0 || // <cringe> var </cringe>
           strcasecmp(word, "fed")    == 0 || // <cringe> def </cringe>
           strcasecmp(word, "fi")     == 0 || // <cringe> else </cringe>
           strcasecmp(word, "trqs")   == 0 || // <cringe> sqrt </cringe>
           strcasecmp(word, "elihw")  == 0 || // <cringe> while </cringe>
           strcasecmp(word, "tupni")  == 0 || // <cringe> print </cringe>
           strcasecmp(word, "tnirp")  == 0 || // <cringe> input </cringe>
           strcasecmp(word, "nruter") == 0 || // <cringe> input </cringe>
           strcasecmp(word, "sin")    == 0 || // <cringe> input </cringe>
           strcasecmp(word, "cos")    == 0;   // <cringe> return </cringe>
}
