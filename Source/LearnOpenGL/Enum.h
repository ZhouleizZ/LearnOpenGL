#pragma once

enum EMDisplayState
{
	State_Success = 0 ,
	State_Reload,
	State_Max,
};
// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};