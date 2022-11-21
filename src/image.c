
#include "../headers/image.h"

struct image
{
    void *pixels; // as linhas estarao uma depois da outra
    int n_rows;
    int n_columns;
    DataType type;
};

Image *image_read(char *path)
{
    Image *image = (Image*)calloc(1, sizeof(Image));
    FILE *fp = fopen(path, "rb");
    if(fp == NULL){
        printf("Arquivo NAO foi aberto\n;");
        exit(1);
    }

    fread(&image->n_rows, 4, 1, fp);
    fread(&image->n_columns, 4, 1, fp);

    fread(&image->type, 4, 1, fp);

    image->pixels = calloc((image->n_rows)*(image->n_columns), 4);
    fread(image->pixels, 4, (image->n_rows)*(image->n_columns), fp);

    fclose(fp);
    return image;
}

int image_size(Image *image)
{
    return (image->n_rows)*(image->n_columns);
}

void image_destroy(Image *image)
{
    free(image->pixels);

    free(image);
}