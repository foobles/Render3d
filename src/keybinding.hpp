//
// Created by foobles on 11/14/2021.
//

#ifndef RENDER_KEYBINDING_HPP
#define RENDER_KEYBINDING_HPP

#include <vector>
#include <array>
#include <unordered_map>
#include <utility>
#include <type_traits>
#include <cstdint>
#include "scancode.hpp"
#include "input_controller.hpp"

namespace engine {

    template<typename EventT>
    class Keybinding {
    public:
        Keybinding(EventT null_event, std::unordered_map<EventT, Scancode> inverse_bindings);
        Keybinding(Keybinding const &other) = default;
        Keybinding(Keybinding &&other) noexcept = default;
        Keybinding &operator=(Keybinding const &other) = default;
        Keybinding &operator=(Keybinding &&other) noexcept = default;
        ~Keybinding() noexcept = default;

        void bind(EventT event, Scancode sc);
        void unbind_event(EventT event);
        void unbind_key(Scancode sc);

        [[nodiscard]] EventT bound_event(Scancode sc) const;
        [[nodiscard]] bool is_event_pressed(InputController const &ic, EventT event) const;


    private:
        EventT &bound_event(Scancode sc);
        EventT null_event;
        std::array<EventT, SCANCODE_COUNT> bindings;
        std::unordered_map<EventT, Scancode> inverse_bindings;

        using BindingIndex = typename decltype(bindings)::size_type;
    };


    template<typename EventT>
    Keybinding<EventT>::Keybinding(EventT null_event, std::unordered_map<EventT, Scancode> inverse_bindings) :
        null_event(null_event),
        bindings(),
        inverse_bindings(std::move(inverse_bindings))
    {
        bindings.fill(null_event);
        for (auto [event, sc] : inverse_bindings) {
            bound_event(sc) = event;
        }
    }

    template<typename EventT>
    EventT &Keybinding<EventT>::bound_event(Scancode sc) {
        return bindings[static_cast<BindingIndex>(sc)];
    }

    template<typename EventT>
    EventT Keybinding<EventT>::bound_event(Scancode sc) const {
        return bindings[static_cast<BindingIndex>(sc)];
    }

    template<typename EventT>
    void Keybinding<EventT>::bind(EventT event, Scancode sc) {
        bound_event(sc) = event;
        inverse_bindings.insert_or_assign(event, sc);
    }

    template<typename EventT>
    void Keybinding<EventT>::unbind_event(EventT event) {
        Scancode sc = inverse_bindings[event];
        inverse_bindings.erase(event);
        bound_event(sc) = null_event;
    }

    template<typename EventT>
    void Keybinding<EventT>::unbind_key(Scancode sc) {
        EventT &event = bound_event(sc);
        inverse_bindings.erase(event);
        event = null_event;
    }

    template<typename EventT>
    bool Keybinding<EventT>::is_event_pressed(InputController const &ic, EventT event) const {
        if (auto entry = inverse_bindings.find(event); entry != inverse_bindings.end()) {
            return ic.is_key_down(entry->second);
        }
        return false;
    }


}
#endif //RENDER_KEYBINDING_HPP
