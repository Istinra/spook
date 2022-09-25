//
// Created by Sam on 25/09/2022.
//

#ifndef SPOOK_PLAYER_H
#define SPOOK_PLAYER_H


#include "glm/vec3.hpp"

class Player {

public:
    Player();

    void onUpdate(float dt);

    const glm::vec3 &getPosition() const;

private:

    glm::vec3 position;

};


#endif //SPOOK_PLAYER_H
