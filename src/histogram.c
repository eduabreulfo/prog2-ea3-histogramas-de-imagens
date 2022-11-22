
#include "../headers/histogram.h"

struct histogram
{
  int *tallies;
  unsigned int n_buckets;
  unsigned int size;
};

Histogram *histogram_compute(Image *image, int n_buckets)
{
  Histogram *histogram = (Histogram*)calloc(1, sizeof(Histogram));

  if(n_buckets <= 0){
    n_buckets = 1;
  }
  if(n_buckets > 256){
    n_buckets = 256;
  }
  histogram->n_buckets = n_buckets;

  histogram->tallies = (int*)calloc(n_buckets, sizeof(int));
  histogram->size = (int)(n_buckets/256);

  int i=0;
  for(i=0; i<(image_size(image)); i++)
  {
    histogram->tallies[(int)(image_pixel(image, i)/histogram->size)]++;
  }

  image_destroy(image);
  return histogram;
}

void histogram_show(Histogram *histogram)
{
  int i=0;
  for(i=0;i<histogram->n_buckets;i++){
    printf("[%d, %d): %d\n", i*histogram->size, (1+i)*histogram->size, histogram->tallies[i]);
  }
}

void histogram_destroy(Histogram *histogram)
{
  free(histogram->tallies);

  free(histogram);
}