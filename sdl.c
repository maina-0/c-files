#include <SDL2/SDL.h>
#include <stdio.h>
#include "./constants.h"

int game_is_running=false;
SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;


int initialize_window(void){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr,"error initialising sdl. \n");
        return false;
    } 
    window = SDL_CreateWindow(NULL, \
                              SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, \
                              WINDOW_WIDTH,WINDOW_HEIGHT,\
                              SDL_WINDOW_BORDERLESS\
                              );
    if (!window){
        fprintf(stderr,"error creating window.\n");
        return false;
    }
    renderer=SDL_CreateRenderer(window,-1,0);
    if (!renderer){
        fprintf(stderr,"error creating renderer.\n");
        return false;
    }
    return true;
}



void process_input(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            game_is_running = false;
            break;

        case  SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE){
                game_is_running = false;}
            break;

    }

}
void setup(){

}
void update(){

} 
void render(){
    SDL_SetRenderDrawColor(renderer,255,255,0,255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);


}

void destroy_window(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


}

int main(){
    game_is_running = initialize_window();
    setup();

    while (game_is_running){
        process_input();
        update();
        render();
    }
    
    destroy_window();
    return 0;
}
