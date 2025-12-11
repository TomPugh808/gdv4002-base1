#pragma once
#include "GameObject2d.h"

class Player : public GameObject2D {
private:
	float playerSpeed;
	float shootCooldown = 0.2f;
	float shootTimer = 0.0f;

public:
	Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initialPlayerSpeed);

	void update(double tDelta) override;

	void shoot();
};