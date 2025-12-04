#include "Enemy.h"
#include "Keys.h"
#include <bitset>
#include <complex>
#include <cstdlib>
#include <ctime>

Enemy::Enemy(
	glm::vec2 initPosition,
	float initOrientation,
	glm::vec2 initSize,
	GLuint initTextureID,
	float initialPhase,
	float initialPhaseVelocity)
: GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	float angle = ((float)rand() / RAND_MAX) * 6.283185f; // random direction
	float speed = 0.5f + ((float)rand() / RAND_MAX) * 1.0f; // random speed

	// random position
	position.x = -2.5f + ((float)rand() / RAND_MAX) * 5.0f;
	position.y = -2.5f + ((float)rand() / RAND_MAX) * 5.0f;

	velocity = glm::vec2(
		cos(angle) * speed,
		sin(angle) * speed
	);

	phaseAngle = initialPhase;
	phaseVelocity = initialPhaseVelocity;
}

void Enemy::update(double tDelta) {

	position += velocity * (float)tDelta;

	orientation += phaseVelocity * (float)tDelta;

	if (position.x > 2.5f) position.x -= 5.0f;
	if (position.x < -2.5f) position.x += 5.0f;
	if (position.y > 2.5f) position.y -= 5.0f;
	if (position.y < -2.5f) position.y += 5.0f;
}

