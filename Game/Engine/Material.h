#pragma once

class Shader;
class Texture;

enum {
	MATERIAL_INT_COUNT = 5,
	MATERIAL_FLOAT_COUNT = 5,
	MATERIAL_TEXTURE_COUNT = 5,
};

struct MaterialParams
{
	void SetInt(uint8 index, int32 value) { intParams[index] = value; }
	void SetFloat(uint8 index, float value) { floatParams[index] = value; }


	// array�� ��¥�� intParams[10] �� ���� ���� �迭��
	// ������ �ڵ����� �����˻� �� intParams[111] �� ���� ���� ���ϰ� ����
	array<int32, MATERIAL_INT_COUNT> intParams;
	array<int32, MATERIAL_FLOAT_COUNT> floatParams;
};



class Material
{
public:
	inline void SetShader(shared_ptr<Shader> shader) { _shader = shader; }
	inline void SetInt(uint8 index, int32 value) { _params.SetInt(index, value); }
	inline void SetFloat(uint8 index, float value) { _params.SetFloat(index, value); }
	inline void SetTexture(uint8 index, shared_ptr<Texture> tex) { _textures[index] = tex; }

	void Update();


private:
	array<shared_ptr<Texture>, MATERIAL_TEXTURE_COUNT> _textures;
	shared_ptr<Shader> _shader;
	MaterialParams		_params;
};

