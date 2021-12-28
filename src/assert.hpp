//
// Created by foobles on 12/20/2021.
//

#ifndef RENDER_ASSERT_HPP
#define RENDER_ASSERT_HPP

__declspec(noinline) void engine_throw();

__forceinline inline void engine_assert(bool b) {
    if (!b) [[unlikely]] {
        engine_throw();
    }
}

#endif //RENDER_ASSERT_HPP
