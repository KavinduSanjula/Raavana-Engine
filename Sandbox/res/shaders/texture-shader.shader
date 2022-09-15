// vertex shader
#type Vertex

#version 330 core

layout(location = 0) in vec3 a_Pos;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TexCoord;
layout(location = 3) in float a_TexId;

out vec2 v_TexCoord;
out vec4 v_Color;
out float v_TexId;

uniform mat4 u_Proj;

void main() {
	gl_Position = u_Proj * vec4(a_Pos, 0.0);
	v_TexCoord = a_TexCoord;
	v_Color = a_Color;
	v_TexId = a_TexId;
}

// fragmant shader
#type Fragment

#version 330 core

out vec4 Color;

in vec2 v_TexCoord;
in vec4 v_Color;
in float v_TexId;

uniform sampler2D u_Textures[10];

void main() {
	vec4 texColor = texture(u_Textures[int(v_TexId)], v_TexCoord);
	Color = texColor* v_Color;
}