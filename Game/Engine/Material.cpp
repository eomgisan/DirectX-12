#include "pch.h"
#include "Material.h"
#include "Engine.h"

void Material::Update() 
{

	//CBV ���ε�
	CONST_BUFFER(CONSTANT_BUFFER_TYPE::MATERIAL)->PushData(&_params, sizeof(_params));


	//SRV ���ε�
	for (size_t i = 0; i < MATERIAL_TEXTURE_COUNT; i++) {
		if (_textures[i] == nullptr) continue;

		// �̹��� ���� �ȵ� ������ ������ �������ε� ����� �ֱ���
		SRV_REGISTER reg = SRV_REGISTER(static_cast<int8>(SRV_REGISTER::t0) + i);
		GEngine->GetTableDescHeap()->SetSRV(_textures[i]->GetCpuHandle(), reg);
	}


	// PSO cmdQueue�� �ø���
	_shader->Update();
}