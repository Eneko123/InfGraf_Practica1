#version 330 core

in vec3 fragPos;
out vec4 color;

void main()
{
    // Crear un degradado de morado a rojo basado en la posición
    // fragPos va de -1 a 1, lo normalizamos a 0-1
    float factor = (fragPos.y + 1.0) * 0.5;  // Convertir de [-1,1] a [0,1]
    
    // Color morado: RGB(128, 0, 128) → normalizado (0.5, 0.0, 0.5)
    // Color rojo: RGB(255, 0, 0) → normalizado (1.0, 0.0, 0.0)
    
    vec3 morado = vec3(0.5, 0.0, 0.5);
    vec3 rojo = vec3(1.0, 0.0, 0.0);
    
    // Interpolar entre morado (abajo) y rojo (arriba)
    vec3 finalColor = mix(morado, rojo, factor);
    
    color = vec4(finalColor, 1.0);
}

