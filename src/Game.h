#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <unordered_map>
#include <string>
#include <vector>
#include "core/ShaderProgram.h"
#include "core/Camera.h"
#include "core/Mesh.h"
#include "core/Texture.h"
#include "ecs/Entity.h"
#include "ecs/Component.h"
#include "ecs/EntityManager.h"

class Game
{
private:
    SDL_Window *mWindow;    // Game window
    SDL_GLContext mContext; // OpenGL context
    bool mIsRunning;        // check if game is running

    int mTicksLastFrame;

    ShaderProgram *shaderProgram;
    FPSCamera *camera;
    float deltaTime;

    // Map of textures loaded
    std::unordered_map<std::string, class Texture *> mTextures;

    void Start();        // to process start for every entities
    void HandleEvents(); // handle the events from keyboard and mouse
    void Update();       // Update the process
    void Render();       // Render or draw the entities

    void LoadData();   // Load data
    void UnloadData(); // unload data

public:
    Game();          // Game constructor
    virtual ~Game(); // Game deconstructor

    bool Initialize(); // Initialize the game
    void Run();        // Run the game
    void Clear();

    Texture *GetTexture(const std::string &fileName);

}; // class Game

#endif // GAME_H