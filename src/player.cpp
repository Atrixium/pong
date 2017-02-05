#include "player.h"

Player::Player()
{
        score = 0;
        paddle.x = 0;
        paddle.y = 0;
        paddle.h = 100;
        paddle.w = 15;
}

void Player::AddScore(int s)
{
    score += s;
}

void Player::Update()
{

}
