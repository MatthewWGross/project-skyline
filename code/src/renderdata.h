#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

struct RenderData
{
    // These are owned by the PhysicsData
    const glm::vec3* pos = nullptr;
    const glm::mat3* rot = nullptr;
};