#version 460 core
in vec4 OutColor;
out vec4 mColor;
uniform vec4 GlobalColor;
void main()
{
    //mColor =OutColor + GlobalColor;
    mColor =OutColor;
}