#include "Bullet.h"
#include <glm/gtc/constants.hpp>
#include <cmath>

Bullet::Bullet(glm::vec2 pos, float orientation, glm::vec2 size, GLuint texID, float speed)
    : GameObject2D(pos, orientation, size, texID), bulletSpeed(speed)
{
}

void Bullet::update(double tDelta)
{
    // orientation is stored as degrees or radians? Assume radians here
    float radians = orientation;  // or glm::radians(orientation) if orientation is degrees

    // Calculate movement vector (unit vector pointing forward)
    float dx = cos(radians);
    float dy = sin(radians);

    // Move the bullet
    position.x += dx * bulletSpeed * tDelta;
    position.y += dy * bulletSpeed * tDelta;
}
