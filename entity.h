/*
 *	entity.h - most basic representation of a physical ingame object
 * 	Author: Adam Waggoner
 */

class Entity
{
	public:
		void update(float dt);
		void render(SDL_Surface *screen);
};