#include <stdio.h>

#include <stdint.h>
#include <math.h>
#include "gfx.h"


#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "stb_image_write.h"

#define CHANNEL_NUM 3

int main() {
    int width, height, nbChannels;
    char c;

    uint8_t* rgb_image = stbi_load("image.png", &width, &height, &nbChannels, 0);

    if (rgb_image==NULL)
    {
        perror(stbi_failure_reason());
        exit(EXIT_FAILURE);
    }

    // Open a new window for drawing.
    gfx_open(width,height,"Example Graphics Program");

    for (int x=0;x<width;++x)
    {
        for (int y = 0; y < height; ++y)
        {
            gfx_color(rgb_image[(x + y * width) * nbChannels], rgb_image[1 + (x + y * width) * nbChannels],
                      rgb_image[2 + (x + y * width) * nbChannels]);
            gfx_point(x, y);
        }
    }


    while(1) {
        // Wait for the user to press a character.
        c = gfx_wait();

        // Quit if it is the letter q.
        if(c=='q') break;
    }

    stbi_image_free(rgb_image);







    // Write your code to populate rgb_image here

    //stbi_write_png("image2.png", width, height, CHANNEL_NUM, rgb_image, width*CHANNEL_NUM);
    //gfx_wait();

    return EXIT_SUCCESS;
}