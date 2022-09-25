//
// Created by Sam on 25/09/2022.
//

#ifndef SPOOK_DEMOGAME_H
#define SPOOK_DEMOGAME_H


#include "../Application.h"
#include "Player.h"

class DemoGame : public Application {

public:
    DemoGame();

    void onInit() override;

    void onUpdate(float time) override;

private:
    Player player;
    Camera camera;
    std::unique_ptr<Shader> shader;
    std::unique_ptr<VertexArray> vertexArray;
};


#endif //SPOOK_DEMOGAME_H
