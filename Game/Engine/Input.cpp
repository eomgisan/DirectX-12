#include "pch.h"
#include "Input.h"

//---------------------------------------------------
// 다르게 구현한점
// 1. 연산자 오버로딩을 통해 좀더 깔끔하게 코딩함!!!
// 2. 현재창에 포커스가 없을경우 바로 none상태가 아닌 up 상태로 갔다 none상태로 가게함
//---------------------------------------------------
KEY_STATE& operator ++(KEY_STATE& key) {
	switch (key) {
	case KEY_STATE::DOWN:
		return key = KEY_STATE::PRESS;
	case KEY_STATE::UP:
		return key = KEY_STATE::DOWN;
	case KEY_STATE::NONE:
		return key = KEY_STATE::DOWN;
	default:
		return key;
	}
}
KEY_STATE& operator --(KEY_STATE& key) {
	switch (key) {
	case KEY_STATE::DOWN:
		return key = KEY_STATE::UP;
	case KEY_STATE::UP:
		return key = KEY_STATE::NONE;
	case KEY_STATE::PRESS:
		return key = KEY_STATE::UP;
	default:
		return key;
	}
}
void Input::Init(HWND hwnd) 
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT);
}

void Input::Update()
{
	HWND hwnd = ::GetActiveWindow();

	// 현재창이 아닐경우 모든 키를 다시 초기상태로 돌려야함
	if (_hwnd != hwnd) {
		for (uint32 key = 0; key < KEY_TYPE_COUNT; key++) {
			--_states[key];
		}
		return;
	}

	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++) {
		if (::GetAsyncKeyState(key) & 0x8000) {
			++_states[key];
		}
		else {
			--_states[key];
		}
	}
}
