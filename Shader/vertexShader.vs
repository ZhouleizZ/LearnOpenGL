#version 460 core

in vec3 mPosition;

out vec4 OutColor;
void main()
{
    gl_Position = vec4(mPosition.x,mPosition.y,mPosition.z,1 );
    OutColor= vec4(mPosition.x+ 0.1,mPosition.y + 0.5,mPosition.z+ 0.2,1 );
}