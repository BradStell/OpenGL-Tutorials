#version 330 core
in vec3 ourColor;

out vec4 colorVert;

void main()
{
    colorVert = vec4(ourColor, 1.0f);
}