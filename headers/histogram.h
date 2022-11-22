
#pragma once

#include "image.h"

typedef struct histogram Histogram;

Histogram *histogram_compute(Image *image, int n_buckets);

void histogram_show(Histogram *histogram);

void histogram_destroy(Histogram *histogram);