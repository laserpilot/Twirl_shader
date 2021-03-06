// Andrew Benson - andrewb@cycling74.com
//Copyright 2006 - Cycling '74

varying vec2 texcoord0;
varying vec2 texdim0;

uniform sampler2DRect tex0;

//effect state
uniform vec2 width;
uniform vec2 origin;

void main()
{
	vec2 orn = origin*texdim0;
	vec2 dst = texcoord0-orn;
	vec2 off = dst*width*-0.05;
    
	vec4 pr1 = texture2DRect(tex0,dst+orn);
	vec4 pr2 = texture2DRect(tex0,dst+off+orn);
	vec4 pr3 = texture2DRect(tex0,(dst+off*2.)+orn);
	vec4 pr4 = texture2DRect(tex0,(dst+off*3.)+orn);
	vec4 pr5 = texture2DRect(tex0,(dst+off*4.)+orn);
	vec4 pr6 = texture2DRect(tex0,(dst+off*5.)+orn);
	vec4 pr7 = texture2DRect(tex0,(dst+off*6.)+orn);
	vec4 pr8 = texture2DRect(tex0,(dst+off*7.)+orn);
	vec4 pr9 = texture2DRect(tex0,(dst+off*8.)+orn);
    
	vec4 avg9 = (pr1+pr2+pr3+pr4+pr5+pr6+pr7+pr8+pr9)/9.;
	
	// output texture
	gl_FragColor = avg9;
}
