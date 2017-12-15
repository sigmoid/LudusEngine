/*
 * input_manager.h - Provides useful functions for detecting input.
 * Author: Adam Waggoner
 */

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "stdint.h"

class InputManager
{
	public:
		~InputManager();

		/* access functions through this instance of the InputManager */
		static InputManager *get_instance();

		void update();

		/* returns true if a key was pressed this frame */
		bool key_pressed(const int);
		/* returns true if a key was released this frame */
		bool key_released(const int);
		/* returns true if a key is currently down */
		bool key_down(const int);
		/* returns true if a key is currently up */
		bool key_up(const int);

	private:
		static InputManager *instance;
		uint8_t *keys, *prev_keys, *cur_keys;

		/* private constructor to maintain singleton */
		InputManager();
		InputManager(InputManager const&copy);

		void initialize();	
};	

#endif