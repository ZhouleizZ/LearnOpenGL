#pragma once


class RawModel
{
private:
	unsigned int vaoID;
	int vertexCnt;
	unsigned int TextureId;
public:
	RawModel() :vaoID(0), vertexCnt(0) , TextureId(0){}
	RawModel(unsigned int _vaoID, int _vertexCnt,unsigned int _texId) :vaoID(_vaoID), vertexCnt(_vertexCnt),TextureId(_texId) {}
	
	unsigned int getVaoID() const { return vaoID; }
	int getVertexCnt() const { return vertexCnt; }
	unsigned int getTextureID() const { return TextureId; }
};