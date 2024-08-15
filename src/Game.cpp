// Our includes
#include <huno/Game.h>
#include <huno/Mouse.h>

// HCLib includes
#include <hclib/Math.h>

// raylib includes
#include <raylib.h>

// std includes
#include <chrono>
#include <iostream>

namespace huno
{
    Game::Game(const u32 width, const u32 height, std::string title) HCLIB_NOEXCEPT :
        width(width), height(height), title(std::move(title)), running(false)
    {
    }

    Game::~Game()
    {
        close();
    }

    /* static */
    std::shared_ptr<Game> Game::instance()
    {
        static std::shared_ptr<Game> inst = nullptr;

        if (inst == nullptr)
        {
            constexpr u32 width = 1280;
            constexpr u32 height = 720;

            inst = std::make_shared<Game>(width, height, "UNO v0.01");
        }

        return inst;
    }

    u32 Game::getWidth() const HCLIB_NOEXCEPT
    {
        return width;
    }

    u32 Game::getHeight() const HCLIB_NOEXCEPT
    {
        return height;
    }

    void Game::close()
    {
        running = false;
    }

    s32 Game::launch()
    {
        if (running)
        {
            return EXIT_FAILURE;
        }

        running = true;
        constexpr u32 numPlayers = 1;
        board.reset(numPlayers);

        InitWindow(width, height, title.c_str());
        SetTargetFPS(60);
        auto lastTime = std::chrono::high_resolution_clock::now();

        while (running && !WindowShouldClose())
        {
            const auto timeNow = std::chrono::high_resolution_clock::now();
            using Duration = std::chrono::duration<f32>;
            const Duration dur = timeNow - lastTime;
            const f32 deltaTime = dur.count();
            update(deltaTime);
            lastTime = timeNow;

            BeginDrawing();
            ClearBackground(DARKGRAY);
            render();
            EndDrawing();
        }

        CloseWindow();

        return EXIT_SUCCESS;
    }

    void Game::render()
    {
        board.render();
    }

    void Game::update(const f32 deltaTime)
    {
        static f32 lastDeltaTime = 0.0F;
        const bool isApproxEqual = hclib::math::isApprox(deltaTime, lastDeltaTime, 0.0001F);

        if (isApproxEqual)
        {
            std::cout << "deltaTime: " << std::fixed << deltaTime << "s\n";
            lastDeltaTime = deltaTime;
        }

        auto mousePtr = Mouse::instance();
        mousePtr->update(deltaTime);
        board.update(deltaTime);
    }
}

