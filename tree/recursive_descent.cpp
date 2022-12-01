#include "recursive_descent.h"

Node *recursiveDescent(Tokens *tokens, size_t *index)
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *value = getAddSub(tokens, index);
//    fprintf(stderr, "INDEX: %zu\n", *index);

    return value;
}

Node *getAddSub(Tokens *tokens, size_t *index)
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *leftValue = getMulDiv(tokens, index);

    while (TOKEN.type == OPERATOR_TOKEN &&
           (TOKEN.value.operation == '+' ||
            TOKEN.value.operation == '-'))
    {
        char tokenValue = TOKEN.value.operation;
        (*index)++;

        Node *rightValue = getMulDiv(tokens, index);
        if (tokenValue == '+')
            leftValue = createNewNode(OPERATION,
                                      {.op_value = ADD_OP},
                                      leftValue,
                                      rightValue);
        else
            leftValue = createNewNode(OPERATION,
                                      {.op_value = SUB_OP},
                                      leftValue,
                                      rightValue);

    }

    return leftValue;
}

Node *getMulDiv(Tokens *tokens, size_t *index)
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *leftValue = getPow(tokens, index);

    while (TOKEN.type == OPERATOR_TOKEN &&
           (TOKEN.value.operation == '*' ||
            TOKEN.value.operation == '/'))
    {
        char tokenValue = TOKEN.value.operation;
        (*index)++;

        Node *rightValue = getPow(tokens, index);

        if (tokenValue == '*')
            leftValue = createNewNode(OPERATION,
                                      {.op_value = MUL_OP},
                                      leftValue,
                                      rightValue);
        else
            leftValue = createNewNode(OPERATION,
                                      {.op_value = DIV_OP},
                                      leftValue,
                                      rightValue);
    }

    return leftValue;
}

Node *getPow(Tokens *tokens, size_t *index)
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *leftValue = getPrimaryExpression(tokens, index);
    Node *rightValue = nullptr;

    while (TOKEN.type == OPERATOR_TOKEN &&
           TOKEN.value.operation == '^')
    {
        char tokenValue = TOKEN.value.operation;
        (*index)++;

        rightValue = getPow(tokens, index);
        leftValue = createNewNode(OPERATION,
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

Node *getPrimaryExpression(Tokens *tokens, size_t *index)
{
    assert(tokens != nullptr);
    assert(index != nullptr);

    Node *value = nullptr;

    if (TOKEN.type == BRACKET_TOKEN &&
        TOKEN.value.bracket == '(')
    {
        (*index)++;

        value = getAddSub(tokens, index);
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
                                {.val_value =
                                tokens->tokens[*index].value.num_value},
                                nullptr,
                                nullptr);
    (*index)++;

    return value;
}

Node *getVariable(Tokens *tokens, size_t *index)
{
    assert(tokens != nullptr);

    Node *value = createNewNode(ID_IN_NAME_TABLE,
                                {.var_value = TOKEN.value.id_in_table},
                                nullptr,
                                value);

    (*index)++;

    return value;
}
