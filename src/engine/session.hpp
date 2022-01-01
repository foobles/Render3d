//
// Created by foobles on 11/6/2021.
//

#ifndef RENDER_SESSION_HPP
#define RENDER_SESSION_HPP

namespace engine {
    class Session {
    public:
        Session();
        ~Session() noexcept;

        Session(Session const &) = delete;
        Session &operator=(Session const &) = delete;
        Session(Session &&) = delete;
        Session &operator=(Session &&) = delete;

    };
}

#endif //RENDER_SESSION_HPP
