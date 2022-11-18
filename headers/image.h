
#pragma once

#include <stdio.h>

typedef enum{
  FLOAT = 0,
  INT = 1
} DataType;

typedef struct image Image;

// inicializa uma imagem em branco na memoria
Image *image_create();

// le um arquivo .bin e retorna um ponteiro de imagem
Image *image_read(FILE *fp);

// libera a memoria da imagem e de seus componentes
void image_destroy(Image *img);