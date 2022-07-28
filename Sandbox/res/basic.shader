#type Vertex

#version 330 core

layout(location = 0) in vec2 a_Pos;

void main() {
	gl_Position = vec4(a_Pos, 1.0, 1.0);
}

#type Fragment

#version 330 core

out vec4 Color;

void main() {
	Color = vec4(1.0, 0.0, 0.0, 1.0);
}