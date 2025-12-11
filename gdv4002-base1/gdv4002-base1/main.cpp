#include "Engine.h"
#include "Keys.h"
#include "Player.h"
#include "Enemy.h"
#include <bitset>
#include <complex>

GLuint bulletTexture = 0;

// Function prototypes
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);


std::bitset<5> keys{ 0x0 };

const float pi = 3.141592f;

int main(void) {

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);

	srand((unsigned)time(nullptr));

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

	// Load image textures
	GLuint playerTexture = loadTexture("Resources\\Textures\\player2_ship.png");
	GLuint enemyTexture1 = loadTexture("Resources\\Textures\\Asteroid1.png");
	bulletTexture = loadTexture("Resources\\Textures\\Bullet.png");


	// Create the objects
	Player* mainPlayer = new Player(glm::vec2(-1.5, 0.0f), 0.0f, glm::vec2(0.3f, 0.3f), playerTexture, 1.0f);
 
	Enemy* enemy1 = new Enemy(glm::vec2(0.0f), 5.0f, glm::vec2(0.8f, 0.8f), enemyTexture1, 0.0f, glm::radians(45.0f));
	Enemy* enemy2 = new Enemy(glm::vec2(0.0f), 0.0f, glm::vec2(0.55f, 0.55f), enemyTexture1, 0.0f, glm::radians(90.0f));
	Enemy* enemy3 = new Enemy(glm::vec2(0.0f), 0.0f, glm::vec2(0.65f, 0.65f), enemyTexture1, 0.0f, glm::radians(60.0f));
	Enemy* enemy4 = new Enemy(glm::vec2(0.0f), 0.0f, glm::vec2(0.7f, 0.7f), enemyTexture1, 0.0f, glm::radians(80.0f));

	// Add the objects to the engine
	addObject("player", mainPlayer);

	addObject("enemy1", enemy1);
	addObject("enemy2", enemy2);
	addObject("enemy3", enemy3);
	addObject("enemy4", enemy4);

	
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

		case GLFW_KEY_SPACE:
			keys[Key::SPACE] = true;
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

		case GLFW_KEY_SPACE:
			keys[Key::SPACE] = false;
			break;
		}

	}
}

	





