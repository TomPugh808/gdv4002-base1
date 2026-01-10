#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "GameObject2D.h"

class Bullet : public GameObject2D {
public:
    Bullet(glm::vec2 pos, float orientation, glm::vec2 size, GLuint texID, float speed);
    void update(double tDelta) override;


private:
    float bulletSpeed;
};