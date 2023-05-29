#include "pch.h"
#include "Timer.h"

void Timer::Init()
{
	GetTickCount();
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount)); // CPU 클럭
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
}
// reinterpret_cast를 왜 사용할까 오류 발생 위험이 있는데 뭐고 LartgeInteger*로 형변환은 왜할까

void Timer::Update()
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount)/static_cast<float>(_frequency);
	_prevCount = currentCount;

	_frameCount++;
	_frameTime += _deltaTime;

	if (_frameTime > 1.f) {
		_fps = static_cast<uint32>(_frameCount / _frameTime);
		_frameCount = 0;
		_frameTime = 0.f;
	}
}
