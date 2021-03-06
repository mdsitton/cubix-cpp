#pragma once

#include <map>
#include <string>
#include <type_traits>
#include "SDL.h"

namespace CubixCore
{

    enum class KeyCode
    {
        _KEY_NONE = 0,
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,
        KEY_1,
        KEY_2,
        KEY_3,
        KEY_4,
        KEY_5,
        KEY_6,
        KEY_7,
        KEY_8,
        KEY_9,
        KEY_RETURN,
        KEY_ESCAPE,
        KEY_BACKSPACE,
        KEY_TAB,
        KEY_SPACE,
        KEY_MINUS,
        KEY_EQUALS,
        KEY_LEFT_BRACKET,
        KEY_RIGHT_BRACKET,
        KEY_BACKSLASH,
        KEY_SEMICOLON,
        KEY_APOSTROPHE,
        KEY_GRAVE,
        KEY_COMMA,
        KEY_PERIOD,
        KEY_SLASH,
        KEY_CAPS_LOCK,
        KEY_F1,
        KEY_F2,
        KEY_F3,
        KEY_F4,
        KEY_F5,
        KEY_F6,
        KEY_F7,
        KEY_F8,
        KEY_F9,
        KEY_F10,
        KEY_F11,
        KEY_F12,
        KEY_PRINT_SCREEN,
        KEY_SCROLL_LOCK,
        KEY_PAUSE,
        KEY_INSERT,
        KEY_HOME,
        KEY_PAGE_UP,
        KEY_DELETE,
        KEY_END,
        KEY_PAGE_DOWN,
        KEY_RIGHT,
        KEY_LEFT,
        KEY_DOWN,
        KEY_UP,
        KEY_NUMLOCK_CLEAR,
        KEY_KP_DIVIDE,
        KEY_KP_MULTIPLY,
        KEY_KP_MINUS,
        KEY_KP_PLUS,
        KEY_KP_ENTER,
        KEY_KP_1,
        KEY_KP_2,
        KEY_KP_3,
        KEY_KP_4,
        KEY_KP_5,
        KEY_KP_6,
        KEY_KP_7,
        KEY_KP_8,
        KEY_KP_9,
        KEY_KP_0,
        KEY_KP_PERIOD,
        KEY_NON_US_BACKSLASH,
        KEY_LEFT_CTRL,
        KEY_LEFT_SHIFT,
        KEY_LEFT_ALT,
        KEY_LEFT_SUPER,
        KEY_RIGHT_CTRL,
        KEY_RIGHT_SHIFT,
        KEY_RIGHT_ALT,
        KEY_RIGHT_SUPER
    };

    enum class ModFlag
    {
        MOD_NONE            = 0,
        MOD_LEFT_SHIFT      = 1 << 0,
        MOD_RIGHT_SHIFT     = 1 << 1,
        MOD_LEFT_CTRL       = 1 << 2,
        MOD_RIGHT_CTRL      = 1 << 3,
        MOD_LEFT_ALT        = 1 << 4,
        MOD_RIGHT_ALT       = 1 << 5,
        MOD_LEFT_SUPER      = 1 << 6,
        MOD_RIGHT_SUPER     = 1 << 7,
        MOD_NUM             = 1 << 8,
        MOD_CAPS            = 1 << 9,
    };

    using underlying = std::underlying_type<ModFlag>::type;

    static ModFlag operator|(const ModFlag& left, const ModFlag& right)
    {
        return static_cast<ModFlag>(static_cast<underlying>(left) | static_cast<underlying>(right));
    }

    static ModFlag operator&(const ModFlag& left, const ModFlag& right)
    {
        return static_cast<ModFlag>(static_cast<underlying>(left) & static_cast<underlying>(right));
    }


    static std::map<int, ModFlag> modMap {
        {KMOD_NONE, ModFlag::MOD_NONE},
        {KMOD_LSHIFT, ModFlag::MOD_LEFT_SHIFT},
        {KMOD_RSHIFT, ModFlag::MOD_RIGHT_SHIFT},
        {KMOD_LCTRL, ModFlag::MOD_LEFT_CTRL},
        {KMOD_RCTRL, ModFlag::MOD_RIGHT_CTRL},
        {KMOD_LALT, ModFlag::MOD_LEFT_ALT},
        {KMOD_RALT, ModFlag::MOD_RIGHT_ALT},
        {KMOD_LGUI, ModFlag::MOD_LEFT_SUPER},
        {KMOD_RGUI, ModFlag::MOD_RIGHT_SUPER},
        {KMOD_NUM, ModFlag::MOD_NUM},
        {KMOD_CAPS, ModFlag::MOD_CAPS}};


    static std::map<int, KeyCode> keyMap {
        {SDL_SCANCODE_A, KeyCode::KEY_A},
        {SDL_SCANCODE_B, KeyCode::KEY_B},
        {SDL_SCANCODE_C, KeyCode::KEY_C},
        {SDL_SCANCODE_D, KeyCode::KEY_D},
        {SDL_SCANCODE_E, KeyCode::KEY_E},
        {SDL_SCANCODE_F, KeyCode::KEY_F},
        {SDL_SCANCODE_G, KeyCode::KEY_G},
        {SDL_SCANCODE_H, KeyCode::KEY_H},
        {SDL_SCANCODE_I, KeyCode::KEY_I},
        {SDL_SCANCODE_J, KeyCode::KEY_J},
        {SDL_SCANCODE_K, KeyCode::KEY_K},
        {SDL_SCANCODE_L, KeyCode::KEY_L},
        {SDL_SCANCODE_M, KeyCode::KEY_M},
        {SDL_SCANCODE_N, KeyCode::KEY_N},
        {SDL_SCANCODE_O, KeyCode::KEY_O},
        {SDL_SCANCODE_P, KeyCode::KEY_P},
        {SDL_SCANCODE_Q, KeyCode::KEY_Q},
        {SDL_SCANCODE_R, KeyCode::KEY_R},
        {SDL_SCANCODE_S, KeyCode::KEY_S},
        {SDL_SCANCODE_T, KeyCode::KEY_T},
        {SDL_SCANCODE_U, KeyCode::KEY_U},
        {SDL_SCANCODE_V, KeyCode::KEY_V},
        {SDL_SCANCODE_W, KeyCode::KEY_W},
        {SDL_SCANCODE_X, KeyCode::KEY_X},
        {SDL_SCANCODE_Y, KeyCode::KEY_Y},
        {SDL_SCANCODE_Z, KeyCode::KEY_Z},
        {SDL_SCANCODE_1, KeyCode::KEY_1},
        {SDL_SCANCODE_2, KeyCode::KEY_2},
        {SDL_SCANCODE_3, KeyCode::KEY_3},
        {SDL_SCANCODE_4, KeyCode::KEY_4},
        {SDL_SCANCODE_5, KeyCode::KEY_5},
        {SDL_SCANCODE_6, KeyCode::KEY_6},
        {SDL_SCANCODE_7, KeyCode::KEY_7},
        {SDL_SCANCODE_8, KeyCode::KEY_7},
        {SDL_SCANCODE_9, KeyCode::KEY_8},
        {SDL_SCANCODE_0, KeyCode::KEY_9},
        {SDL_SCANCODE_RETURN, KeyCode::KEY_RETURN},
        {SDL_SCANCODE_ESCAPE, KeyCode::KEY_ESCAPE},
        {SDL_SCANCODE_BACKSPACE, KeyCode::KEY_BACKSPACE},
        {SDL_SCANCODE_TAB, KeyCode::KEY_TAB},
        {SDL_SCANCODE_SPACE, KeyCode::KEY_SPACE},
        {SDL_SCANCODE_MINUS, KeyCode::KEY_MINUS},
        {SDL_SCANCODE_EQUALS, KeyCode::KEY_EQUALS},
        {SDL_SCANCODE_LEFTBRACKET, KeyCode::KEY_LEFT_BRACKET},
        {SDL_SCANCODE_RIGHTBRACKET, KeyCode::KEY_RIGHT_BRACKET},
        {SDL_SCANCODE_BACKSLASH, KeyCode::KEY_BACKSLASH},
        {SDL_SCANCODE_SEMICOLON, KeyCode::KEY_SEMICOLON},
        {SDL_SCANCODE_APOSTROPHE, KeyCode::KEY_APOSTROPHE},
        {SDL_SCANCODE_GRAVE, KeyCode::KEY_GRAVE},
        {SDL_SCANCODE_COMMA, KeyCode::KEY_COMMA},
        {SDL_SCANCODE_PERIOD, KeyCode::KEY_PERIOD},
        {SDL_SCANCODE_SLASH, KeyCode::KEY_SLASH},
        {SDL_SCANCODE_CAPSLOCK, KeyCode::KEY_CAPS_LOCK},
        {SDL_SCANCODE_F1, KeyCode::KEY_F1},
        {SDL_SCANCODE_F2, KeyCode::KEY_F2},
        {SDL_SCANCODE_F3, KeyCode::KEY_F3},
        {SDL_SCANCODE_F4, KeyCode::KEY_F4},
        {SDL_SCANCODE_F5, KeyCode::KEY_F5},
        {SDL_SCANCODE_F6, KeyCode::KEY_F6},
        {SDL_SCANCODE_F7, KeyCode::KEY_F7},
        {SDL_SCANCODE_F8, KeyCode::KEY_F8},
        {SDL_SCANCODE_F9, KeyCode::KEY_F9},
        {SDL_SCANCODE_F10, KeyCode::KEY_F10},
        {SDL_SCANCODE_F11, KeyCode::KEY_F11},
        {SDL_SCANCODE_F12, KeyCode::KEY_F12},
        {SDL_SCANCODE_PRINTSCREEN, KeyCode::KEY_PRINT_SCREEN},
        {SDL_SCANCODE_SCROLLLOCK, KeyCode::KEY_SCROLL_LOCK},
        {SDL_SCANCODE_PAUSE, KeyCode::KEY_PAUSE},
        {SDL_SCANCODE_INSERT, KeyCode::KEY_INSERT},
        {SDL_SCANCODE_HOME, KeyCode::KEY_HOME},
        {SDL_SCANCODE_PAGEUP, KeyCode::KEY_PAGE_UP},
        {SDL_SCANCODE_DELETE, KeyCode::KEY_DELETE},
        {SDL_SCANCODE_END, KeyCode::KEY_END},
        {SDL_SCANCODE_PAGEDOWN, KeyCode::KEY_PAGE_DOWN},
        {SDL_SCANCODE_RIGHT, KeyCode::KEY_RIGHT},
        {SDL_SCANCODE_LEFT, KeyCode::KEY_LEFT},
        {SDL_SCANCODE_DOWN, KeyCode::KEY_DOWN},
        {SDL_SCANCODE_UP, KeyCode::KEY_UP},
        {SDL_SCANCODE_NUMLOCKCLEAR, KeyCode::KEY_NUMLOCK_CLEAR},
        {SDL_SCANCODE_KP_DIVIDE, KeyCode::KEY_KP_DIVIDE},
        {SDL_SCANCODE_KP_MULTIPLY, KeyCode::KEY_KP_MULTIPLY},
        {SDL_SCANCODE_KP_MINUS, KeyCode::KEY_KP_MINUS},
        {SDL_SCANCODE_KP_PLUS, KeyCode::KEY_KP_PLUS},
        {SDL_SCANCODE_KP_ENTER, KeyCode::KEY_KP_ENTER},
        {SDL_SCANCODE_KP_1, KeyCode::KEY_KP_1},
        {SDL_SCANCODE_KP_2, KeyCode::KEY_KP_2},
        {SDL_SCANCODE_KP_3, KeyCode::KEY_KP_3},
        {SDL_SCANCODE_KP_4, KeyCode::KEY_KP_4},
        {SDL_SCANCODE_KP_5, KeyCode::KEY_KP_5},
        {SDL_SCANCODE_KP_6, KeyCode::KEY_KP_6},
        {SDL_SCANCODE_KP_7, KeyCode::KEY_KP_7},
        {SDL_SCANCODE_KP_8, KeyCode::KEY_KP_8},
        {SDL_SCANCODE_KP_9, KeyCode::KEY_KP_9},
        {SDL_SCANCODE_KP_0, KeyCode::KEY_KP_0},
        {SDL_SCANCODE_KP_PERIOD, KeyCode::KEY_KP_PERIOD},
        {SDL_SCANCODE_NONUSBACKSLASH, KeyCode::KEY_NON_US_BACKSLASH},
        {SDL_SCANCODE_LCTRL, KeyCode::KEY_LEFT_CTRL},
        {SDL_SCANCODE_LSHIFT, KeyCode::KEY_LEFT_SHIFT},
        {SDL_SCANCODE_LALT, KeyCode::KEY_LEFT_ALT},
        {SDL_SCANCODE_LGUI, KeyCode::KEY_LEFT_SUPER},
        {SDL_SCANCODE_RCTRL, KeyCode::KEY_RIGHT_CTRL},
        {SDL_SCANCODE_RSHIFT, KeyCode::KEY_RIGHT_SHIFT},
        {SDL_SCANCODE_RALT, KeyCode::KEY_RIGHT_ALT},
        {SDL_SCANCODE_RGUI, KeyCode::KEY_RIGHT_SUPER}
    };


    static std::map<KeyCode, std::string> keyStrMap {
        {KeyCode::KEY_CAPS_LOCK, "CAPS LOCK"},
        {KeyCode::KEY_F1, "F1"},
        {KeyCode::KEY_F2, "F2"},
        {KeyCode::KEY_F3, "F3"},
        {KeyCode::KEY_F4, "F4"},
        {KeyCode::KEY_F5, "F5"},
        {KeyCode::KEY_F6, "F6"},
        {KeyCode::KEY_F7, "F7"},
        {KeyCode::KEY_F8, "F8"},
        {KeyCode::KEY_F9, "F9"},
        {KeyCode::KEY_F10, "F10"},
        {KeyCode::KEY_F11, "F11"},
        {KeyCode::KEY_F12, "F12"},
        {KeyCode::KEY_PRINT_SCREEN, "PRINT SCREEN"},
        {KeyCode::KEY_SCROLL_LOCK, "SCROLL LOCK"},
        {KeyCode::KEY_PAUSE, "PAUSE"},
        {KeyCode::KEY_INSERT, "INSERT"},
        {KeyCode::KEY_HOME, "HOME"},
        {KeyCode::KEY_PAGE_UP, "PAGE UP"},
        {KeyCode::KEY_END, "END"},
        {KeyCode::KEY_PAGE_DOWN, "PAGE DOWN"},
        {KeyCode::KEY_RIGHT, "RIGHT"},
        {KeyCode::KEY_LEFT, "LEFT"},
        {KeyCode::KEY_DOWN, "DOWN"},
        {KeyCode::KEY_UP, "UP"},
        {KeyCode::KEY_NUMLOCK_CLEAR, "NUMLOCK CLEAR"},
        {KeyCode::KEY_LEFT_CTRL, "LEFT CTRL"},
        {KeyCode::KEY_LEFT_SHIFT, "LEFT SHIFT"},
        {KeyCode::KEY_LEFT_ALT, "LEFT ALT"},
        {KeyCode::KEY_LEFT_SUPER, "LEFT SUPER"},
        {KeyCode::KEY_RIGHT_CTRL, "RIGHT CTRL"},
        {KeyCode::KEY_RIGHT_SHIFT, "RIGHT SHIFT"},
        {KeyCode::KEY_RIGHT_ALT, "RIGHT ALT"},
        {KeyCode::KEY_RIGHT_SUPER, "RIGHT SUPER"}
    };



// def process_modkeys(value):
//  keys = []
//  for key in modmap:
//      if value & key:
//          keys.append(modmap[key])
//  return keys

// def process_key_char(value):
//  char = None
//  try:
//      char = str(chr(value))
//  except ValueError:
//      temp = value ^ (1<<30)
//      if temp in keymap:
//          char = keystrMap[keymap[temp]]
//  return char

}
