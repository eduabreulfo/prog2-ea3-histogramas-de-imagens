
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

    const int N_BYTES = 4;

    fread(&image->n_rows, N_BYTES, 1, fp);
    fread(&image->n_columns, N_BYTES, 1, fp);

    fread(&image->type, N_BYTES, 1, fp);

    image->pixels = calloc((image->n_rows)*(image->n_columns), N_BYTES);

    fread(image->pixels, N_BYTES, (image->n_rows)*(image->n_columns), fp);
    if(image->type == FLOAT)
    {
        void *new_pointer = calloc((image->n_rows)*(image->n_columns), N_BYTES);

        int i=0;
        for(i=0;i<image_size(image);i++)
        {
            ((int*)(new_pointer))[i] = (((float*)(image->pixels))[i]*255);
        }
        free(image->pixels);
        image->pixels = new_pointer;
        image->type = INT;
    }

    fclose(fp);
    return image;
}

int image_size(Image *image)
{
    return (image->n_rows)*(image->n_columns);
}

int image_pixel(Image *image, int i)
{
    if(i > image_size(image)){
        printf("Acesso invalido!\n");
    }
    return *(int*)(image->pixels + i*sizeof(int));
}

void image_destroy(Image *image)
{
    free(image->pixels);

    free(image);
}