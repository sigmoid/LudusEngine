#include <iostream>
#include <cstdint>
#include <cstdlib>
#include "SDL.h"
#include "SDL_thread.h"
#include "input_manager.h"
#include "vector2.h"

int main()
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Event e;
	Vector2 box_pos(100, 100);

	float delta_time = 0, prev_time = 0;

	/* initialize SDL */
	SDL_Init( SDL_INIT_EVERYTHING );

	window = SDL_CreateWindow("bipo",
							  SDL_WINDOWPOS_UNDEFINED,	/* window x */
							  SDL_WINDOWPOS_UNDEFINED,	/* window y */
							  640, 480,									/* width, height */
							  SDL_WINDOW_OPENGL);

	renderer = SDL_CreateRenderer(window, -1, 0);

	int quit = 0;
	while(!quit)
	{
		/* handle events */
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				quit = 1;
			}
		}

		/* calculate time since last frame */
		delta_time = SDL_GetTicks() - prev_time;
		prev_time = SDL_GetTicks();

		//std::cout << "dt: " << delta_time << std::endl;

		InputManager::get_instance()->update();

		if(InputManager::get_instance()->key_pressed(SDL_SCANCODE_ESCAPE))
			quit = 1;

		SDL_SetRenderDrawColor(renderer, (int)(prev_time /10 + 50)% 255, 255,
		 ((int)prev_time/10) % 255, 255);

		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, (int)(prev_time /10 + 50)% 255, 255,
		 ((int)prev_time/10) % 255, 0);

		SDL_RenderDrawRect(renderer, );

		SDL_RenderPresent(renderer);
	}

	/* shutdown SDL */
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}