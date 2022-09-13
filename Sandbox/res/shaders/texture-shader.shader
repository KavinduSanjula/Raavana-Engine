#type Vertex

#version 330 core

layout(location = 0) in vec2 a_Pos;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TexCoord;
layout(location = 3) in float a_TexId;

out vec2 v_TexCoord;
out vec4 v_Color;

void main() {
	gl_Position = vec4(a_Pos, 1.0, 1.0);
	v_TexCoord = a_TexCoord;
	v_Color = a_Color;
}

#type Fragment

#version 330 core

out vec4 Color;

in vec2 v_TexCoord;
in vec4 v_Color;

uniform sampler2D tex;

void main() {
	vec4 texColor = texture(tex, v_TexCoord);
	Color = v_Color; //texColor;
}