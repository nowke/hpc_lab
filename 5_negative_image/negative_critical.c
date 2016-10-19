#include <stdio.h>
#include <gd.h>
#include <string.h>
#include <omp.h>

int main(int argc, char *argv[]) {

    if (argc < 4) {
        printf("Usage: ./negative input.png output.png num_threads\n");
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int num_threads = atoi(argv[3]);

    int color, x, y, i;
    int red, green, blue;

    FILE *fp;

    if((fp = fopen(input_file, "r")) == NULL) {
        printf("Error opening file %s\n", input_file);
        return 1;
    }

    gdImagePtr img = gdImageCreateFromPng(fp);
    int width = gdImageSX(img);
    int height = gdImageSY(img);

    double t1 = omp_get_wtime();

    #pragma omp parallel for private(y, color, red, green, blue) num_threads(num_threads)
    for(x=0; x<width; x++) {
        #pragma omp critical
        {
            for(y=0; y<height; y++) {
                color = x + 0;
                color = gdImageGetPixel(img, x, y);
                red   = 255 - gdImageRed(img, color);
                green = 255 - gdImageGreen(img, color);
                blue  = 255 - gdImageBlue(img, color);
                color = gdImageColorAllocate(img, red, green, blue);
                gdImageSetPixel(img, x, y, color);
            }
        }
    }

    double t2 = omp_get_wtime();

    if((fp=fopen(output_file, "w")) == NULL) {
        printf("Error opening output file %s\n", output_file);
        return 1;
    }

    gdImagePng(img, fp);
    gdImageDestroy(img);
    fclose(fp);

    printf("File Size: %dx%d\n", width, height);
    printf("Time Taken: %.3lfms\n",(t2 - t1) * 1000);
    return 0;
}
