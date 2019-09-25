#pragma once


class RawModel
{
private:
	unsigned int vaoID;
	int vertexCnt;
	unsigned int TextureId;
	unsigned int Texture2Id;
public:
	RawModel() :vaoID(0), vertexCnt(0) , TextureId(0){}
	RawModel(unsigned int _vaoID, int _vertexCnt,unsigned int _texId, unsigned int _tex2Id) :vaoID(_vaoID), vertexCnt(_vertexCnt),TextureId(_texId),Texture2Id(_tex2Id) {}
	
	unsigned int getVaoID() const { return vaoID; }
	int getVertexCnt() const { return vertexCnt; }
	unsigned int getTextureID() const { return TextureId; }
	unsigned int getTexture2ID() const { return Texture2Id; }
};