#include "Engine.h"

const float pi = 3.141593f;

// Function prototypes
void myUpdateScene(GLFWwindow* window, double tDelta);

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
	addObject("player", glm::vec2(1, 1), glm::radians(0.0f), glm::vec2(0.5, 0.5), "Resources\\Textures\\player2_ship.png", TextureProperties::NearestFilterTexture());
	setUpdateFunction(myUpdateScene);

	addObject("player2", glm::vec2(-1.0f, -1.0f), glm::radians(45.0f), glm::vec2(0.5f, 1.0f), "Resources\\Textures\\mcblock01.png", TextureProperties::NearestFilterTexture());
	

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

void myUpdateScene(GLFWwindow* window, double tDelta) {
	GameObject2D* player = getObject("player");
	const float moveSpeed = 2.0f;
	const float rotSpeed = glm::radians(90.0f);
	float dt = static_cast<float>(tDelta);

	// Rotation (A/D or Left/Right)
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		player->orientation += rotSpeed * dt;
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		player->orientation -= rotSpeed * dt;

	// Movement (W/S only)
	glm::vec2 fwd = { sin(player->orientation), cos(player->orientation) };

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		player->position += fwd * moveSpeed * dt;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		player->position -= fwd * moveSpeed * dt;
}



