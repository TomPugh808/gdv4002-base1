#include "Engine.h"
#include "Keys.h"
#include <bitset>
#include <complex>


// Function prototypes
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
void myUpdateScene(GLFWwindow* window, double tDelta);

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
	addObject("player", glm::vec2(0, 0), glm::radians(0.0f), glm::vec2(0.5, 0.5), "Resources\\Textures\\player1_ship.png", TextureProperties::NearestFilterTexture());
	
	setKeyboardHandler(myKeyboardHandler);
	setUpdateFunction(myUpdateScene);

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

void myUpdateScene(GLFWwindow* window, double tDelta) {
	static float playerSpeed = 0.0f; // distance per second
	static float rotaSpeed = glm::radians(120.0f); // rotation per second
	static float acceleration = 2.0f;
	static float friction = 4.0f; // how much the ship glides to a stop
	static float maxSpeed = 5.0f; // maximum speed of the ship

	GameObject2D* player = getObject("player");

	std::complex<float> i(0.0f, 1.0f);
	auto rotation = exp(i * player->orientation);
	glm::vec2 forward(rotation.real(), rotation.imag());

	if (keys.test(Key::W) == true) {

		playerSpeed += acceleration * (float)tDelta; // increase speed

		if (playerSpeed > maxSpeed)
			playerSpeed = maxSpeed;

	} 
	else {
		playerSpeed -= friction * (float)tDelta; // apply friction
		
		if (playerSpeed < 0.0f)
			playerSpeed = 0.0f;

	}

	if (keys.test(Key::S) == true) {

		playerSpeed -= friction * (float)tDelta; // apply friction faster
	}

	player->position.x += playerSpeed * (float)tDelta * forward.x; // move forward
	player->position.y += playerSpeed * (float)tDelta * forward.y; // move forward


	if (keys.test(Key::D) == true) {

		player->orientation -= rotaSpeed * (float)tDelta; // rotate clockwise
	}

	if (keys.test(Key::A) == true) {

		player->orientation += rotaSpeed * (float)tDelta; // rotate anti-clockwise
	}


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



