#include "entity.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

void renderPlayerLife(Entity *player, SDL_Renderer *renderer, TTF_Font *font) {
    if (player->head != NULL) { 
        char lifeText[10];
        sprintf(lifeText, "Life %d", player->head->id);
        SDL_Surface *surface = TTF_RenderText_Solid(font, lifeText, (SDL_Color){255, 255, 255});
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect dstrect = {10, 10, surface->w, surface->h}; 
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}
