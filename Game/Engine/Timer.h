#pragma once
class Timer
{
public:
	void Init();
	void Update();

	inline uint32 GetFPS() { return _fps; }
	inline float GetDeltaTime() { return _deltaTime; }

private:
	float _deltaTime = 0.f;
	uint64 _frequency = 0;
	uint64 _prevCount = 0;

private:
	uint32 _frameCount = 0;
	uint32 _fps = 0;
	float _frameTime = 0.f;

};

