#version 330 core

layout(location = 0) in vec3 pos;

uniform mat4 model;
uniform mat4 projection;

out vec3 fragPos;

void main()
{
    gl_Position = projection * model * vec4(pos, 1.0);
    // Pasar la posición del vertice al fragment shader
    fragPos = pos;
}