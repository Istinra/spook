//
// Created by Sam on 25/09/2022.
//

#ifndef SPOOK_LEVEL_H
#define SPOOK_LEVEL_H


#include <vector>
#include <memory>
#include "Player.h"
#include "glm/vec2.hpp"
#include "glm/mat4x4.hpp"
#include "../Renderer/VertexArray.h"
#include "../Renderer/Renderer.h"

struct Mountains {
    glm::vec2 position;
    float height;
};

class Level {
public:
    Level();

    void init();

    [[nodiscard]] const Player &getPlayer() const;

    void onUpdate(float time);

    void onRender(Renderer& renderer, const glm::mat4x4& viewProjection);

private:
    std::unique_ptr<VertexArray> vertexArray;
    Player player;
    std::vector<Mountains> mountains;
};


#endif //SPOOK_LEVEL_H
