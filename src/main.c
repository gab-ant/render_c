#include "SDL3/SDL_init.h"
#include "SDL3/SDL_surface.h"
#include "SDL3/SDL_video.h"
#include <stdio.h>
#include <stdint.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;



int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
	printf("Error: could not init video");
	return 1;
    }

    SDL_Window *window = SDL_CreateWindow("my game", 400, 400, SDL_WINDOW_RESIZABLE);
    bool done = false;

    if (window == NULL) {
	printf("Error: could not create window");
	return 1;
    }
    
    SDL_Surface *surface = SDL_GetWindowSurface(window);

    u32 red = SDL_MapSurfaceRGB(surface, 255, 0, 0);
    
    // Assume colors layed out as 32-bit values
    u32 *pixels = (u32 *)surface->pixels;

    for (int i = 0; i < 100; i++) {
	pixels[20000 + i] = red;
    }

    SDL_UpdateWindowSurface(window);

    while (!done) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
	    if (event.type == SDL_EVENT_QUIT) {
		done = true;
	    }
	}
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
