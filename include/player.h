#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

class Player
{
    public:
        Player();

        void AddScore(int);
        int GetScore(){return score;};
        void Update();
        SDL_Rect* GetPaddle(){return &paddle;};

    private:
        int score;
        SDL_Rect paddle;

};

#endif // PLAYER_H
