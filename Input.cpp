#include "Input.h"

Input::Input() {
	m_x = 0;
	m_y = 0;
	m_xReal = 0;
	m_yReal = 0;
	m_close = false;

	for (int i = 0; i < SDL_NUM_SCANCODES; i++)
		m_keyboardKeys[i] = false;

	for (int i = 0; i < 8; i++)
		m_mouseKeys[i] = false;
}

Input::~Input() {
	
}

void Input::listen() {

	m_xReal = 0;
	m_yReal = 0;

	while (SDL_PollEvent(&m_events) == 1) {
		switch (m_events.type) {

			case SDL_KEYDOWN:
				m_keyboardKeys[m_events.key.keysym.scancode] = true;
			break;

			case SDL_KEYUP:
				m_keyboardKeys[m_events.key.keysym.scancode] = false;
			break;

			case SDL_MOUSEBUTTONDOWN:
				m_mouseKeys[m_events.button.button] = true;
			break;

			case SDL_MOUSEBUTTONUP:
				m_mouseKeys[m_events.button.button] = false;
			break;

			case SDL_MOUSEMOTION:
				m_x = m_events.motion.x;
				m_y = m_events.motion.y;
				m_xReal = m_events.motion.xrel;
				m_yReal = m_events.motion.yrel;
			break;

			case SDL_WINDOWEVENT:
				if (m_events.window.event == SDL_WINDOWEVENT_CLOSE)
					m_close = true;

		}
	}
}

void Input::showCursor(bool show) {
	if (show)
		SDL_ShowCursor(SDL_ENABLE);
	else
		SDL_ShowCursor(SDL_DISABLE);
}

void Input::lockCursor(bool lock) {
	if (lock)
		SDL_SetRelativeMouseMode(SDL_TRUE);
	else
		SDL_SetRelativeMouseMode(SDL_FALSE);
}

bool Input::cursorIsShowed() const {
	return SDL_ShowCursor(-1);
}

bool Input::cursorIsLocked() const {
	return SDL_GetRelativeMouseMode();
}

bool Input::mouseIsMoved() const {
	return (m_xReal != 0 || m_yReal != 0);
}

bool Input::getClose() const {
	return m_close;
}

const bool* Input::getKeyboardKeys() const {
	return m_keyboardKeys;
}

bool Input::getKeyboardKey(SDL_Scancode scancode) const {
	return m_keyboardKeys[scancode];
}

const bool* Input::getMouseKeys() const {
	return m_mouseKeys;
}

bool Input::getMouseKey(Uint8 mousekey) const {
	return m_mouseKeys[mousekey];
}

int Input::getXReal() const {
	return m_xReal;
}

int Input::getYReal() const {
	return m_yReal;
}