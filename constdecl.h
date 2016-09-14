#pragma once

enum APP_STATE 
{
	TERMINATE,

	ENTER_SPLASH, SPLASH,	// Intro Screen
	ENTER_DEPART, DEPART,   // Say Goodbye
	ENTER_OPTION, OPTION,   // main menu
	ENTER_ACTION, ACTION,   // Game state


};


// States will have 4 properties:
	// initialization
		// Called once.
	// activation
		// Setting up the state.
	// update/draw
		// normal logic stuff.
	// transition
		// condition to move to a state
