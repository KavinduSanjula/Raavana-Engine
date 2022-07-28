#type Vertex

#version 330 core

layout(location = 0) in vec2 a_Pos;
layout(location = 1) in vec2 a_TexCoord;

out vec2 v_TexCoord;

void main() {
	gl_Position = vec4(a_Pos, 1.0, 1.0);
	v_TexCoord = a_TexCoord;
}

#type Fragment

#version 330 core

out vec4 Color;

in vec2 v_TexCoord;

uniform sampler2D tex;

void main() {
	vec4 texColor = texture(tex, v_TexCoord);
	Color = texColor;
}