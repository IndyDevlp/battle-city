#version 460

in vec3 color;
in vec2 texCoords;
out vec4 frag_color;

uniform sampler2D tex;

void main()
{
   frag_color = texture(tex, texCoords);

   if (frag_color.rgb == vec3(0.0, 0.0, 1.0))
   {
		discard;
   }
}