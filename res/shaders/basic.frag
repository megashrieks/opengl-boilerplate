#version 330 core

out vec4 color;


void main(){
    color = vec4(gl_FragCoord.xy / 500.0,0.0,1.0);
}