#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
uniform int useColor;

void main()
{
	if (useColor == 0)
		color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.2);
	else
		color = vec4(ourColor, 1.0f);
}