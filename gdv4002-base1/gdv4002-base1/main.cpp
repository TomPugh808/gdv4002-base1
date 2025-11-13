#include "Engine.h"
#include "Keys.h"
#include "Player.h"
#include <bitset>
#include <complex>


// Function prototypes
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);


std::bitset<5> keys{ 0x0 };

const float pi = 3.141592f;

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	// Setup game scene objects here
	//
	GLuint playerTexture = loadTexture("Resources\\Textures\\player2_ship.png");

	Player* mainPlayer = new Player(glm::vec2(-1.5, 0.0f), 0.0f, glm::vec2(0.3f, 0.3f), playerTexture, 1.0f);
	addObject("player", mainPlayer);
	
	setKeyboardHandler(myKeyboardHandler);

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Check if the key was just pressed
	if (action == GLFW_PRESS) {

		// now check which key was pressed...
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			// If escape is pressed tell GLFW we want to close the window(and quit)
			glfwSetWindowShouldClose(window, true);
			break;

		case GLFW_KEY_W:
			keys[Key::W] = true;
			break;

		case GLFW_KEY_S:
			keys[Key::S] = true;
			break;

		case GLFW_KEY_D:
			keys[Key::D] = true;
			break;

		case GLFW_KEY_A:
			keys[Key::A] = true;
			break;

		}

	}
	// If not pressed, check the key has just been released
	else if (action == GLFW_RELEASE) {

		// handle key release events
		switch (key)
		{
		case GLFW_KEY_W:
			keys[Key::W] = false;
			break;

		case GLFW_KEY_S:
			keys[Key::S] = false;
			break;

		case GLFW_KEY_D:
			keys[Key::D] = false;
			break;

		case GLFW_KEY_A:
			keys[Key::A] = false;
			break;
		}

	}
}

	





