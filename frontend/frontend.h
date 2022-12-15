#ifndef LANGUAGE_FRONTEND_FRONTEND_H
#define LANGUAGE_FRONTEND_FRONTEND_H

#include "../tokenizer/tokenizer.h"

void convertProgramToTree(const char *filename,
                          const char *standard_tree_filename,
                          const char *backend_tree_filename);

#endif //LANGUAGE_FRONTEND_FRONTEND_H
