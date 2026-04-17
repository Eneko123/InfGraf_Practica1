#version 330 core

out vec4 color;

void main()
{
    // Color basado en la posición para ver algo interesante
    color = vec4(gl_FragCoord.x/800.0, gl_FragCoord.y/600.0, 0.5, 1.0);
}
