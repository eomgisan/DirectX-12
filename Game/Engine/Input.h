#pragma once

enum class KEY_TYPE {
	LEFT = VK_LEFT,
	RIGHT = VK_RIGHT,
	UP = VK_UP,
	DOWN = VK_DOWN,
	Q = 'Q', W = 'W', E = 'E', R = 'R', T = 'T',
	A = 'A', S = 'S', D = 'D', F = 'F', G = 'G',
	Z = 'Z', X = 'X', C = 'C', V = 'V', B = 'V',


};


enum class KEY_STATE {

	DOWN,
	PRESS,
	UP,
	NONE,
	LAST,
};


enum {
	KEY_TYPE_COUNT = static_cast<uint32>(UINT8_MAX + 1),
	KEY_STATE_COUNT = static_cast<uint32>(KEY_STATE::LAST),
};



class Input
{
public:
	void Init(HWND hwnd);
	void Update();

	bool GetButtonDown(KEY_TYPE key) { return GetState(key) == KEY_STATE::DOWN; }
	bool GetButton(KEY_TYPE key) { return GetState(key) == KEY_STATE::PRESS; }
	bool GetButtonUp(KEY_TYPE key) { return GetState(key) == KEY_STATE::UP; }

private:
	inline KEY_STATE GetState(KEY_TYPE key) { return _states[static_cast<int>(key)]; }

	HWND _hwnd;
	vector<KEY_STATE> _states;
};

