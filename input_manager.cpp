#include "input_manager.h"
#include "SDL.h"

InputManager *InputManager::instance = NULL;

InputManager *InputManager::get_instance()
{
	if(instance == NULL)
	{
		instance = new InputManager();
		instance->initialize();
	}

	return instance;
}

/* default constructor */
InputManager::InputManager()
{
	keys = NULL;
	prev_keys = NULL;
}

InputManager::~InputManager()
{
	free(prev_keys);
	free(cur_keys);
}

void InputManager::initialize()
{
	SDL_PumpEvents();

	keys = (uint8_t*)SDL_GetKeyboardState(NULL);

	/* allocate an array of the proper size to copy keys into */
	prev_keys = (uint8_t*)calloc(SDLK_m, 1);
	cur_keys  = (uint8_t*)calloc(SDLK_m, 1); 
}

void InputManager::update()
{
	/* store a copy of keyboard state */
	memcpy(prev_keys, cur_keys, SDLK_m);
	memcpy(cur_keys, keys, SDLK_m);
}

bool InputManager::key_down(const int key)
{
	return (keys[key]);
}

bool InputManager::key_up(const int key)
{
	return !key_down(key);	
}

bool InputManager::key_pressed(const int key)
{
	return cur_keys[key] && !prev_keys[key];
}

bool InputManager::key_released(const int key)
{
	return !cur_keys[key] && prev_keys[key];
}
