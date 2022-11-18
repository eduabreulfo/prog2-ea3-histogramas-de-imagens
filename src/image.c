
#include "../headers/image.h"

struct image
{
    void *pixels;
    int n_rows;
    int n_columns;
    DataType type;
};