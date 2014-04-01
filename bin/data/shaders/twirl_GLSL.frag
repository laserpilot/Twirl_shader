// vertex to fragment shader io
varying vec2 texcoord0;
varying vec2 texdim0;

// globals
uniform float amp;
uniform float phase;
uniform vec2 center;

// samplers
uniform sampler2DRect tex0;

// entry point
void 
main()
{
	
    vec2 PP = texcoord0/texdim0 - vec2(0.5,0.5);
    float P0 = PP[0];
    float P1 = PP[1];
    float radius = sqrt(P0 * P0 + P1 * P1);
    float angle = atan(P1,P0);

    float offset = radius * amp + phase;
    angle += offset;

    angle = mod(angle, 2.0 * 3.14159);
    float cosangle = -cos(angle - 3.14159);
    float sinangle = -sin(angle - 3.14159);

    vec2 newP = vec2 (0,0);
    newP[0] = radius * cosangle + center[0];
    newP[1] = radius * sinangle + center[1];

    gl_FragColor = texture2DRect(tex0, vec2(newP*texdim0));
}