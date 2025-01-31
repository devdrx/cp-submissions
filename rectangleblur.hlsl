float Circle(vec2 uv, vec2 p, float r, float blur) {

    float d = length(uv-p);
    float c = smoothstep(r, r-blur, d);

    return c;
}

float Band(float t, float start, float end, float blur) {
    float step1 = smoothstep(start-blur, start+blur, t);
    float step2 = smoothstep(end+blur, end-blur, t);

    return step1*step2;
}

float Rect(vec2 uv, float left, float right, float bottom, float top, float blur) {
    float band1 = Band(uv.x, left, right, blur);
    float band2 = Band(uv.y, bottom, top, blur);

    return band1*band2;
}

float Smiley(vec2 uv, vec2 p, float size) {
    uv -= p;    // translating coordinate system
    uv /= size; // scaling coordinate system

    float mask = Circle(uv, vec2(0.), .4, .01);

    mask -= Circle(uv, vec2(-.13, .2), .07, .01);
    mask -= Circle(uv, vec2(.13, .2), .07, .01);

    float mouth = Circle(uv, vec2(0., 0.), .3, .02);
    mouth -= Circle(uv, vec2(0., 0.1), .3, .02);

    mask -= mouth;

    return mask;
}
float remap1(float a, float b, float t){
    return (t-a)/(b-a);
}
float remap( float a, float b, float c, float d, float t){
    return remap1(a,b,t) * (d-c) + c;
}
void mainImage( out vec4 fragColor, in vec2 fragCoord)
{
    vec2 uv = fragCoord.xy / iResolution.xy; // 0 <> 1.
    float t = iTime;
    uv -= .5;           // -0.5 <> 0.5
    uv.x *= iResolution.x/iResolution.y;

    vec3 col = vec3(0.);


    float mask = 0.;

    //Smiley(uv, vec2(0., 0.), 1.);
    float x = uv.x;
    float b = sin(x*8. + t)*.1;
    float y = uv.y - b;
    //x += .2;
    //x+=-.2*y;
    vec2 point = vec2(x, y);
    //mask = Rect(point, -.2+y*.2, .2-y*.2, -.3, .3, .01);
    float blur = remap(-.5, .5, 0.01, 0.25, x);
    blur*=blur;
    mask = Rect(point, -.5, .5, -.1, .1, blur);
    col = vec3(1., 1., 1.)*mask;

    fragColor = vec4(col, 1.0);
}