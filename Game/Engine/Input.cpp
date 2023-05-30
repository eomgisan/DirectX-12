#include "pch.h"
#include "Input.h"

//---------------------------------------------------
// �ٸ��� ��������
// 1. ������ �����ε��� ���� ���� ����ϰ� �ڵ���!!!
// 2. ����â�� ��Ŀ���� ������� �ٷ� none���°� �ƴ� up ���·� ���� none���·� ������
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

	// ����â�� �ƴҰ�� ��� Ű�� �ٽ� �ʱ���·� ��������
	if (_hwnd != hwnd) {
		for (uint32 key = 0; key < KEY_TYPE_COUNT; key++) {
			--_states[key];
		}
		return;
	}

	BYTE asciiKeys[KEY_TYPE_COUNT] = {};
	if (::GetKeyboardState(asciiKeys) == false) return;

	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++) {
		if (asciiKeys[key] & 0x80) {
			++_states[key];
		}
		else {
			--_states[key];
		}
	}
}
