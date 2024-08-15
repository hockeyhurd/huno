#pragma once

#ifndef UNO_GAME_H
#define UNO_GAME_H

// Our includes
#include <huno/Board.h>

// HCLib includes
#include <hclib/Types.h>

// std includes
#include <atomic>
#include <string>

namespace huno
{
    using namespace hclib;

    class Game
    {
    public:

        Game(const u32 width, const u32 height, std::string title) HCLIB_NOEXCEPT;

    public:

        Game(const Game&) = delete;
        Game(Game&&) HCLIB_NOEXCEPT = delete;
        ~Game();

        Game& operator= (const Game&) = delete;
        Game& operator= (Game&&) HCLIB_NOEXCEPT = delete;

        static std::shared_ptr<Game> instance();

        u32 getWidth() const HCLIB_NOEXCEPT;
        u32 getHeight() const HCLIB_NOEXCEPT;

        void close();
        s32 launch();

    private:

        void render();
        void update(const f32 deltaTime);

    private:

        u32 width;
        u32 height;
        std::string title;
        std::atomic_bool running;

        Board board;
    };
}

#endif //!UNO_GAME_H

