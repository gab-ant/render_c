#include "SDL3/SDL_init.h"
#include "SDL3/SDL_pixels.h"
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
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window;
    bool done = false;

    window = SDL_CreateWindow("My render", 100, 100, SDL_WINDOW_RESIZABLE);  
    
    if (window == NULL) {
	SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
	return 1;
    }
    
    // Declaring colors (mapping RGB values to a u32)
    const SDL_PixelFormatDetails* FmtDetails = SDL_GetPixelFormatDetails(SDL_GetWindowSurface(window)->format);

    const u32 RedColor = SDL_MapRGB(
	    FmtDetails,
	    NULL,
	    255,
	    0,
	    0
    );
    
    // Make screen red
    SDL_FillSurfaceRect(SDL_GetWindowSurface(window), NULL, RedColor);
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
