#version 460 core
layout (location = 0) in vec3 mPosition;  //位置变量的属性位置值 0
layout (location = 1) in vec3 aColor;     //颜色变量的属性位置值 1

out vec4 OutColor;
void main()
{
    gl_Position = vec4(mPosition,1.0);
    OutColor=vec4(aColor,1.0);// 将ourColor设置为我们从顶点数据那里得到的输入颜色
    //OutColor= vec4(mPosition.x + 0.5,mPosition.y+ 0.2,mPosition.z+ 0.6,1 );
}