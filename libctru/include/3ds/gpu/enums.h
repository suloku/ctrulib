#pragma once

//tex param
#define GPU_TEXTURE_MAG_FILTER(v) (((v)&0x1)<<1)  //takes a GPU_TEXTURE_FILTER_PARAM
#define GPU_TEXTURE_MIN_FILTER(v) (((v)&0x1)<<2)  //takes a GPU_TEXTURE_FILTER_PARAM
#define GPU_TEXTURE_WRAP_S(v)     (((v)&0x3)<<12) //takes a GPU_TEXTURE_WRAP_PARAM
#define GPU_TEXTURE_WRAP_T(v)     (((v)&0x3)<<8)  //takes a GPU_TEXTURE_WRAP_PARAM

// Combiner buffer write config
#define GPU_TEV_BUFFER_WRITE_CONFIG(stage0, stage1, stage2, stage3) ((stage0) | ((stage1) << 1) | ((stage2) << 2) | ((stage3) << 3))

typedef enum
{
	GPU_NEAREST = 0x0,
	GPU_LINEAR  = 0x1,
} GPU_TEXTURE_FILTER_PARAM;

typedef enum
{
	GPU_CLAMP_TO_EDGE   = 0x0,
	GPU_CLAMP_TO_BORDER = 0x1,
	GPU_REPEAT          = 0x2,
	GPU_MIRRORED_REPEAT = 0x3,
} GPU_TEXTURE_WRAP_PARAM;

typedef enum
{
	GPU_TEXUNIT0 = 0x1,
	GPU_TEXUNIT1 = 0x2,
	GPU_TEXUNIT2 = 0x4,
} GPU_TEXUNIT;

typedef enum
{
	GPU_RGBA8    = 0x0,
	GPU_RGB8     = 0x1,
	GPU_RGBA5551 = 0x2,
	GPU_RGB565   = 0x3,
	GPU_RGBA4    = 0x4,
	GPU_LA8      = 0x5,
	GPU_HILO8    = 0x6,
	GPU_L8       = 0x7,
	GPU_A8       = 0x8,
	GPU_LA4      = 0x9,
	GPU_L4       = 0xA,
	GPU_ETC1     = 0xB,
	GPU_ETC1A4   = 0xC,
} GPU_TEXCOLOR;

typedef enum
{
	GPU_NEVER    = 0,
	GPU_ALWAYS   = 1,
	GPU_EQUAL    = 2,
	GPU_NOTEQUAL = 3,
	GPU_LESS     = 4,
	GPU_LEQUAL   = 5,
	GPU_GREATER  = 6,
	GPU_GEQUAL   = 7,
}GPU_TESTFUNC;

typedef enum
{
	GPU_SCISSOR_DISABLE = 0, // disable scissor test
	GPU_SCISSOR_INVERT  = 1, // exclude pixels inside the scissor box
	// 2 is the same as 0
	GPU_SCISSOR_NORMAL  = 3, // exclude pixels outside of the scissor box
	
} GPU_SCISSORMODE;

typedef enum
{
	GPU_STENCIL_KEEP      = 0, // old_stencil
	GPU_STENCIL_ZERO      = 1, // 0
	GPU_STENCIL_REPLACE   = 2, // ref
	GPU_STENCIL_INCR      = 3, // old_stencil + 1 saturated to [0, 255]
	GPU_STENCIL_DECR      = 4, // old_stencil - 1 saturated to [0, 255]
	GPU_STENCIL_INVERT    = 5, // ~old_stencil
	GPU_STENCIL_INCR_WRAP = 6, // old_stencil + 1
	GPU_STENCIL_DECR_WRAP = 7, // old_stencil - 1
} GPU_STENCILOP;

typedef enum
{
	GPU_WRITE_RED   = 0x01,
	GPU_WRITE_GREEN = 0x02,
	GPU_WRITE_BLUE  = 0x04,
	GPU_WRITE_ALPHA = 0x08,
	GPU_WRITE_DEPTH = 0x10,
	
	GPU_WRITE_COLOR = 0x0F,
	GPU_WRITE_ALL   = 0x1F,
} GPU_WRITEMASK;

typedef enum
{
	GPU_BLEND_ADD              = 0,
	GPU_BLEND_SUBTRACT         = 1,
	GPU_BLEND_REVERSE_SUBTRACT = 2,
	GPU_BLEND_MIN              = 3,
	GPU_BLEND_MAX              = 4,
} GPU_BLENDEQUATION;

typedef enum
{
	GPU_ZERO                     = 0,
	GPU_ONE                      = 1,
	GPU_SRC_COLOR                = 2,
	GPU_ONE_MINUS_SRC_COLOR      = 3,
	GPU_DST_COLOR                = 4,
	GPU_ONE_MINUS_DST_COLOR      = 5,
	GPU_SRC_ALPHA                = 6,
	GPU_ONE_MINUS_SRC_ALPHA      = 7,
	GPU_DST_ALPHA                = 8,
	GPU_ONE_MINUS_DST_ALPHA      = 9,
	GPU_CONSTANT_COLOR           = 10,
	GPU_ONE_MINUS_CONSTANT_COLOR = 11,
	GPU_CONSTANT_ALPHA           = 12,
	GPU_ONE_MINUS_CONSTANT_ALPHA = 13,
	GPU_SRC_ALPHA_SATURATE       = 14,
} GPU_BLENDFACTOR;

typedef enum
{
	GPU_LOGICOP_CLEAR         = 0,
	GPU_LOGICOP_AND           = 1,
	GPU_LOGICOP_AND_REVERSE   = 2,
	GPU_LOGICOP_COPY          = 3,
	GPU_LOGICOP_SET           = 4,
	GPU_LOGICOP_COPY_INVERTED = 5,
	GPU_LOGICOP_NOOP          = 6,
	GPU_LOGICOP_INVERT        = 7,
	GPU_LOGICOP_NAND          = 8,
	GPU_LOGICOP_OR            = 9,
	GPU_LOGICOP_NOR           = 10,
	GPU_LOGICOP_XOR           = 11,
	GPU_LOGICOP_EQUIV         = 12,
	GPU_LOGICOP_AND_INVERTED  = 13,
	GPU_LOGICOP_OR_REVERSE    = 14,
	GPU_LOGICOP_OR_INVERTED   = 15,
} GPU_LOGICOP;

typedef enum
{
	GPU_BYTE          = 0,
	GPU_UNSIGNED_BYTE = 1,
	GPU_SHORT         = 2,
	GPU_FLOAT         = 3,
} GPU_FORMATS;

typedef enum
{
	GPU_CULL_NONE      = 0,
	GPU_CULL_FRONT_CCW = 1,
	GPU_CULL_BACK_CCW  = 2,
} GPU_CULLMODE;

#define GPU_ATTRIBFMT(i, n, f) (((((n)-1)<<2)|((f)&3))<<((i)*4))

/**
* Texture combiners sources 
*/
typedef enum
{
	GPU_PRIMARY_COLOR            = 0x00,
	GPU_FRAGMENT_PRIMARY_COLOR   = 0x01,
	GPU_FRAGMENT_SECONDARY_COLOR = 0x02,
	GPU_TEXTURE0                 = 0x03,
	GPU_TEXTURE1                 = 0x04,
	GPU_TEXTURE2                 = 0x05,
	GPU_TEXTURE3                 = 0x06,
	GPU_PREVIOUS_BUFFER          = 0x0D,
	GPU_CONSTANT                 = 0x0E,
	GPU_PREVIOUS                 = 0x0F,
} GPU_TEVSRC;

/**
* Texture RGB combiners operands
*/
typedef enum
{
	GPU_TEVOP_RGB_SRC_COLOR           = 0x00,
	GPU_TEVOP_RGB_ONE_MINUS_SRC_COLOR = 0x01,
	GPU_TEVOP_RGB_SRC_ALPHA           = 0x02,
	GPU_TEVOP_RGB_ONE_MINUS_SRC_ALPHA = 0x03,
	GPU_TEVOP_RGB_SRC_R               = 0x04,
	GPU_TEVOP_RGB_ONE_MINUS_SRC_R     = 0x05,
	GPU_TEVOP_RGB_0x06                = 0x06,
	GPU_TEVOP_RGB_0x07                = 0x07,
	GPU_TEVOP_RGB_SRC_G               = 0x08,
	GPU_TEVOP_RGB_ONE_MINUS_SRC_G     = 0x09,
	GPU_TEVOP_RGB_0x0A                = 0x0A,
	GPU_TEVOP_RGB_0x0B                = 0x0B,
	GPU_TEVOP_RGB_SRC_B               = 0x0C,
	GPU_TEVOP_RGB_ONE_MINUS_SRC_B     = 0x0D,
	GPU_TEVOP_RGB_0x0E                = 0x0E,
	GPU_TEVOP_RGB_0x0F                = 0x0F,
} GPU_TEVOP_RGB;


/**
* Texture ALPHA combiners operands
*/
typedef enum
{
	GPU_TEVOP_A_SRC_ALPHA           = 0x00,
	GPU_TEVOP_A_ONE_MINUS_SRC_ALPHA = 0x01,
	GPU_TEVOP_A_SRC_R               = 0x02,
	GPU_TEVOP_A_ONE_MINUS_SRC_R     = 0x03,
	GPU_TEVOP_A_SRC_G               = 0x04,
	GPU_TEVOP_A_ONE_MINUS_SRC_G     = 0x05,
	GPU_TEVOP_A_SRC_B               = 0x06,
	GPU_TEVOP_A_ONE_MINUS_SRC_B     = 0x07,
} GPU_TEVOP_A;

/**
* Texture combiner functions
*/
typedef enum
{
	GPU_REPLACE      = 0x00,
	GPU_MODULATE     = 0x01,
	GPU_ADD          = 0x02,
	GPU_ADD_SIGNED   = 0x03,
	GPU_INTERPOLATE  = 0x04,
	GPU_SUBTRACT     = 0x05,
	GPU_DOT3_RGB     = 0x06, //RGB only
	GPU_MULTIPLY_ADD = 0x08,
	GPU_ADD_MULTIPLY = 0x09,
} GPU_COMBINEFUNC;

/**
* Texture scale factors
*/
typedef enum
{
	GPU_TEVSCALE_1 = 0x0,
	GPU_TEVSCALE_2 = 0x1,
	GPU_TEVSCALE_4 = 0x2,
} GPU_TEVSCALE;

#define GPU_TEVSOURCES(a,b,c)  (((a))|((b)<<4)|((c)<<8))
#define GPU_TEVOPERANDS(a,b,c) (((a))|((b)<<4)|((c)<<8))

#define GPU_LIGHT_ENV_LAYER_CONFIG(n) ((n)+((n)==7))
#define GPU_LC1_SHADOWBIT(n)   BIT(n)
#define GPU_LC1_SPOTBIT(n)     BIT((n)+8)
#define GPU_LC1_LUTBIT(n)      BIT((n)+16)
#define GPU_LC1_ATTNBIT(n)     BIT((n)+24)
#define GPU_LIGHTPERM(i,n)     ((n) << (i))
#define GPU_LIGHTLUTINPUT(i,n) ((n) << ((i)*4))
#define GPU_LIGHTLUTIDX(c,i,o) ((o) | ((i) << 8) | ((c) << 11))
#define GPU_LIGHTCOLOR(r,g,b)  (((b) & 0xFF) | (((g) << 10) & 0xFF) | (((r) << 20) & 0xFF))

typedef enum
{
	GPU_NO_FRESNEL            = 0,
	GPU_PRI_ALPHA_FRESNEL     = 1,
	GPU_SEC_ALPHA_FRESNEL     = 2,
	GPU_PRI_SEC_ALPHA_FRESNEL = 3,
} GPU_FRESNELSEL;

typedef enum
{
	GPU_BUMP_NOT_USED = 0,
	GPU_BUMP_AS_BUMP  = 1,
	GPU_BUMP_AS_TANG  = 2,
} GPU_BUMPMODE;

typedef enum
{
	GPU_LUT_D0 = 0,
	GPU_LUT_D1 = 1,
	GPU_LUT_SP = 2,
	GPU_LUT_FR = 3,
	GPU_LUT_RB = 4,
	GPU_LUT_RG = 5,
	GPU_LUT_RR = 6,
	GPU_LUT_DA = 7,
} GPU_LIGHTLUTID;

typedef enum
{
	GPU_LUTINPUT_NH = 0,
	GPU_LUTINPUT_VH = 1,
	GPU_LUTINPUT_NV = 2,
	GPU_LUTINPUT_LN = 3,
	GPU_LUTINPUT_SP = 4,
	GPU_LUTINPUT_CP = 5,
} GPU_LIGHTLUTINPUT;

typedef enum
{
	GPU_LUTSCALER_1x    = 0,
	GPU_LUTSCALER_2x    = 1,
	GPU_LUTSCALER_4x    = 2,
	GPU_LUTSCALER_8x    = 3,
	GPU_LUTSCALER_0_25x = 6,
	GPU_LUTSCALER_0_5x  = 7,
} GPU_LIGHTLUTSCALER;

typedef enum
{
	GPU_LUTSELECT_COMMON = 0,
	GPU_LUTSELECT_SP     = 1,
	GPU_LUTSELECT_DA     = 2,
} GPU_LIGHTLUTSELECT;

typedef enum
{
	GPU_TRIANGLES      = 0x0000,
	GPU_TRIANGLE_STRIP = 0x0100,
	GPU_TRIANGLE_FAN   = 0x0200,
	GPU_GEOMETRY_PRIM  = 0x0300,
} GPU_Primitive_t;

typedef enum
{
	GPU_VERTEX_SHADER   = 0x0,
	GPU_GEOMETRY_SHADER = 0x1,
} GPU_SHADER_TYPE;
