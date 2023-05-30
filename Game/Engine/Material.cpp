#include "pch.h"
#include "Material.h"
#include "Engine.h"

void Material::Update() 
{
	//CBV 업로드
	CONST_BUFFER(CONSTANT_BUFFER_TYPE::MATERIAL)->PushData(&_params, sizeof(_params));


	//SRV 업로드
	for (size_t i = 0; i < MATERIAL_TEXTURE_COUNT; i++) {
		if (_textures[i] == nullptr) continue;

		// 이문법 이해 안됨 저렇게 생성자 형식으로도 만들수 있구나
		SRV_REGISTER reg = SRV_REGISTER(static_cast<int8>(SRV_REGISTER::t0) + i);
		GEngine->GetTableDescHeap()->SetSRV(_textures[i]->GetCpuHandle(), reg);
	}


	// PSO cmdQueue에 올리기
	_shader->Update();
}