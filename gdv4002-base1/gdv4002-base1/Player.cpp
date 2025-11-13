#include "Player.h"
#include "Keys.h"
#include <bitset>
#include <complex>

extern std::bitset<5> keys;

Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initialPlayerSpeed) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {
	playerSpeed = initialPlayerSpeed;
}

void Player::update(double tDelta) {
	static float playerSpeed = 0.0f; // distance per second
	static float rotaSpeed = glm::radians(120.0f); // rotation per second
	static float acceleration = 2.0f;
	static float friction = 4.0f; // how much the ship glides to a stop
	static float maxSpeed = 5.0f; // maximum speed of the ship

	std::complex<float> i(0.0f, 1.0f);
	auto rotation = exp(i * orientation);
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

	position.x += playerSpeed * (float)tDelta * forward.x; // move forward
	position.y += playerSpeed * (float)tDelta * forward.y; // move forward


	if (keys.test(Key::D) == true) {

		orientation -= rotaSpeed * (float)tDelta; // rotate clockwise
	}

	if (keys.test(Key::A) == true) {

		orientation += rotaSpeed * (float)tDelta; // rotate anti-clockwise
	}


}


