#version 460 core
out vec4 mColor;

in vec4 OutColor;
in vec2 TexCoord;

uniform vec4 GlobalColor;

uniform sampler2D ourTexture;

void main()
{
    //mColor =OutColor + GlobalColor;
    //mColor =OutColor;
    //使用GLSL内建的texture函数来采样纹理的颜色，它第一个参数是纹理采样器，第二个参数是对应的纹理坐标。
    //texture函数会使用之前设置的纹理参数对相应的颜色值进行采样。这个片段着色器的输出就是纹理的（插值）纹理坐标上的(过滤后的)颜色。
    mColor = texture(ourTexture,TexCoord) * OutColor;
}