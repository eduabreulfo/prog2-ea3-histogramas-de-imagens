
#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef enum{
  FLOAT = 0,
  INT = 1
} DataType;

typedef struct image Image;

// le um arquivo em path e retorna um ponteiro de imagem
Image *image_read(char *path);

// retorna o total de pixels numa imagem
int image_size(Image *image);

// libera a memoria da imagem e de seus componentes
void image_destroy(Image *image);