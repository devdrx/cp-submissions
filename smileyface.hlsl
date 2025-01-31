#define S(a,b,t) smoothstep(a,b,t)
#define sat(x) clamp(x, 0., 1.)

float remap01(float a, float b, float t){
    return sat((t-a)/(b-a));
}
float remap(float a, float b, float c, float d, float t){
    return sat((t-a)/(b-a)) * (d-c) + c;
}
vec2 within(vec2 uv, vec4 rect){
    return (uv - rect.xy)/(rect.zw - rect.xy);
}
vec4 Eye(vec2 uv){
    uv -= 0.5;
    float d = length(uv);
    vec4 col = vec4(1.);
    vec4 irisCol = vec4(.3, .5, 1., 1.);
    col = mix(col, irisCol, S(.1, .7, d)*.5); //eyecircle border shade
    col.rgb *= 1. - S(.45, .5, d)*.5*sat(-uv.y-uv.x);  //internal depth(see the depth near nose and flatness away from it)
    col.rgb = mix(col.rgb, vec3(0.), S(.3, .28, d)); //black circle behind iris
    irisCol.rgb *= 1. + S(.3, .05, d); //iris gradient
    col.rgb = mix(col.rgb, irisCol.rgb, S(.28, .25, d)); //iris
    col.rgb = mix(col.rgb, vec3(0.), S(.16, .14, d)); //pupil
    float highlight = S(.1, .09, length(uv - vec2(-.15,.15))); //bigger highlight
    highlight += S(.07, .05, length(uv + vec2(-.08,.08))); //smaller highlight
    col.rgb = mix(col.rgb, vec3(1), highlight); //highlight mix
    col.a = S(.5, .48, d); //eyecircle
    return col;
}
vec4 Mouth(vec2 uv){
    uv -= .5;
    //uv.y *= 1.5; //scaling
    //uv.y -= uv.x*uv.x*2.; //mouth curvature
    vec4 col = vec4(.5, .18, .05, 1.); //mouth color
    float d = length(uv);
    col.a = S(.5, .48, d);
    float td = length(uv-vec2(0., .6)); //teeth circle
    vec3 toothCol = vec3(1.)*S(.6, .35, d);
    col.rgb = mix(col.rgb, toothCol, S(.4, .37, td)); //teeth shadow
    //td = length(uv + vec2(0., .5));
    //col.rgb = mix(col.rgb, vec3(1., .5, .5), S(.5, .2 , td)); //tongue
    return col;
}
vec4 Head(vec2 uv){
    vec4 col = vec4(.9, .65, .1, 1.);
    float d = length(uv);
    col.a = S(.5, .49, d);
    float edgeShade = remap01(.35, .5, d);
    edgeShade *= edgeShade;
    col.rgb *= 1. - edgeShade*.5;
    col.rgb = mix(col.rgb, vec3(.6, .3, .1), S(.47, .48, d));
    float highlight = S(.41, .405, d)*.75;
    highlight *= remap(.41, -.1, .75, 0., uv.y);
    col.rgb = mix(col.rgb, vec3(1.), highlight);
    d = length(uv - vec2(.25, -.2));
    float cheek = S(.2, .01, d)*.4;
    cheek *= S(.17, .16, d);
    col.rgb = mix(col.rgb, vec3(1., .1, .1), cheek);
    
    return col;
}
vec4 Smiley(vec2 uv){
    vec4 col = vec4(0.);
    uv.x = abs(uv.x);
    vec4 head = Head(uv);
    vec4 eye = Eye(within(uv, vec4(.03, -.1, .37, .25)));
    vec4 mouth = Mouth(within(uv, vec4(-.3, -.4, .3, -.1)));
    col = mix(col, head, head.a);
    col = mix(col, eye, eye.a);
    col = mix(col, mouth, mouth.a);
    return col;
}


void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord/iResolution.xy;
    uv -= .5;
    uv.x *= iResolution.x/iResolution.y;
    
    fragColor = Smiley(uv);
}