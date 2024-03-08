#version 330 core

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
out vec4 outColor;

uniform sampler2D tex;
uniform float time;

void main(){
    vec2 pos=fragTexCoord;
    pos.y+=time;
    vec4 texColor=texture(tex,pos);
    texColor.r=1.0f;
    outColor=texColor;
}