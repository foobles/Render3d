//
// Created by foobles on 12/20/2021.
//

#ifndef RENDER_ASSERT_HPP
#define RENDER_ASSERT_HPP

#if defined(_MSC_VER)
    __declspec(noinline)
#elif defined(__GNUC__)
    __attribute__((noinline))
#endif
void engine_throw();


#if defined(_MSC_VER)
    __forceinline
#elif defined(__GNUC__)
    inline __attribute__((always_inline))
#endif
void engine_assert(bool b) {
    if (!b) [[unlikely]] {
        engine_throw();
    }
}

#endif //RENDER_ASSERT_HPP
