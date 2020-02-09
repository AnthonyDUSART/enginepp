#pragma once

#include <SDL2/SDL.h>

class Input
{
public:
	Input();
	~Input();
	void listen();
	void showCursor(bool show);
	void lockCursor(bool lock);
	bool cursorIsShowed() const;
	bool cursorIsLocked() const;
	bool mouseIsMoved() const;
	bool getClose() const;
	const bool* getKeyboardKeys() const;
	bool getKeyboardKey(SDL_Scancode scancode) const;
	const bool* getMouseKeys() const;
	bool getMouseKey(Uint8 mousekey) const;
	int getXReal() const;
	int getYReal() const;

private:
	SDL_Event m_events;
	bool m_keyboardKeys[SDL_NUM_SCANCODES];
	bool m_mouseKeys[8];
	int m_x;
	int m_y;
	int m_xReal;
	int m_yReal;
	bool m_close;

};

