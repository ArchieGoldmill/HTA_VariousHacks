#pragma once

enum Messages
{
	 PROP_MODEL_CAST_SHADOW = 0,
	 PROP_SERVER_SLOT = 1,
	 PROP_MODEL_WIND_WAVY = 1,
	 PROP_SERVER_SLOT_1 = 2,
	 PROP_MODEL_TRANS = 2,
	 PROP_NODE_LAST_DEFAULT = 3,
	 PROP_MODEL_2SIDED = 3,
	 PROP_MODEL_TESSELLATE = 4,
	 PROP_MODEL_TRACK_LAND = 5,
	 PROP_MODEL_CAST_SHADOWVOL = 6,
	 PROP_MODEL_LAST_DEFAULT = 7,
	 PROP_MODEL_NAME = 0x100,
	 PROP_MODEL_FILENAME = 0x101,
	 PROP_NODE_DEBUG_STR = 0x1000,
	 PROP_NODE_FIRST = 0x1100,
	 PROP_NODE_BELONG = 0x1101,
	 PROP_NODE_FOV = 0x1102,
	 PROP_NODE_HAVE_CHILDSOUND = 0x1103,
	 PROP_NODE_PHYSICBODY = 0x1104,
	 PROP_NODE_GEOMOBJSLIST = 0x1105,
	 PROP_NODE_HAVECOLLISION = 0x1106,
	 PROP_NODE_LASTPARENT = 0x1107,
	 PROP_NODE_HANDLE = 0x1108,
	 PROP_NODE_GAMEOBJECT = 0x1109,
	 PROP_NODE_LAST = 0x110A,
	 PROP_LS_FIRST = 0x2100,
	 PROP_LS_COLOR = 0x2100,
	 PROP_LS_RADIUS = 0x2101,
	 PROP_LS_BRIGHTNESS = 0x2102,
	 PROP_LS_LAST = 0x2103,
	 PROP_DM_ACTION = 0x2200,
	 PROP_DM_SKIN = 0x2202,
	 PROP_DM_CFG = 0x2203,
	 PROP_DM_EFFECT_ACTION = 0x2204,
	 PROP_DM_MODEL_ACTION = 0x2205,
	 PROP_DM_ARRAY_EFFECT_ACTIONS = 0x2206,
	 PROP_DM_ADD_EFFECT_ACTION = 0x2207,
	 PROP_DM_DEL_EFFECT_ACTION = 0x2208,
	 PROP_DM_CHECK_ACTION = 0x2209,
	 PROP_DM_SUPPRESS_LPS = 0x220A,
	 PROP_DM_RESTART_EFFECT_ACTIONS = 0x220B,
	 PROP_DM_MANUAL_ANIMCONTROL = 0x220C,
	 PROP_DM_PASSABLE = 0x220D,
	 PROP_DM_OBSTACLE = 0x220E,
	 PROP_DM_LAST_TIME_UPDATED = 0x220F,
	 PROP_DM_IS_IMPOSTED = 0x2210,
	 PROP_DM_CAST_SHADOW = 0x2211,
	 PROP_SPR_FIRST = 0x2400,
	 PROP_SPR_MODE = 0x2400,
	 PROP_SPR_COLOR = 0x2401,
	 PROP_SPR_TIME0 = 0x2402,
	 PROP_SPR_ANIM_LEN = 0x2403,
	 PROP_SPR_ANGULAR_SPEED = 0x2404,
	 PROP_SPR_LOOPED = 0x2405,
	 PROP_SPR_LAST = 0x2406,
	 PROP_PS_FIRST = 0x2500,
	 PROP_PS_NUM_EMITTER_MESH = 0x2500,
	 PROP_PS_ADD_PARTICLE = 0x2501,
	 PROP_PS_MOVE_PARTICLES = 0x2502,
	 PROP_PS_ADD_PARTICLES = 0x2503,
	 PROP_PS_LAST = 0x2504,
	 PROP_SND_FIRST = 0x2600,
	 PROP_SND_LOOPED = 0x2600,
	 PROP_SND_CHANNELID = 0x2601,
	 PROP_SND_MAXVOLUME = 0x2602,
	 PROP_SND_BASE_FREQUENCY = 0x2603,
	 PROP_SND_PLAYBACK_COEFF = 0x2604,
	 PROP_SND_SOUND_ENABLED = 0x2605,
	 PROP_SND_LAST = 0x2606,
	 PROP_MUSIC_END_CALLBACK = 0x2680,
	 PROP_LINES_FIRST = 0x2700,
	 PROP_LINES_COLOR = 0x2700,
	 PROP_LINES_RAD = 0x2701,
	 PROP_LINES_LAST = 0x2702,
	 PROP_PROJECTOR_FIRST = 0x2800,
	 PROP_PROJECTOR_RADIUS = 0x2801,
	 PROP_PROJECTOR_LAST = 0x2802,
	 PROP_DECAL_LIST = 0x2900,
	 PROP_DECAL_ADD = 0x2901,
	 PROP_DECAL_RECALC = 0x2902,
	 PROP_SRV_BOUNDING_BOX = 0x3000,
	 PROP_SRV_SOUND_FOR_ACTION = 0x3001,
	 PROP_SRV_COLLISION_DATA_SZ = 0x3002,
	 PROP_SRV_COLLISION_DATA = 0x3003,
	 PROP_SRV_LOADPOINT = 0x3004,
	 PROP_SRV_IS_LOCAL = 0x3005,
	 PROP_SRV_SOUND_IS_LOOPED = 0x3006,
	 PROP_SRV_SNAPSHOT = 0x3007,
	 PROP_SRV_ACTION_TIME = 0x3008,
	 PROP_SRV_ATTACK_FRAMETIME = 0x3009,
	 PROP_SRV_SND_ID = 0x3020,
	 PROP_SRV_SND_SIMPLE = 0x3021,
	 PROP_SRV_SND_DOUBLE = 0x3022,
	 PROP_SRV_SND_TRIPLE = 0x3023,
	 PROP_INTERNAL_GET_MESH_POINTS = 0x4007,
	 PROP_INTERNAL_FREE_MESH_POINTS = 0x4008,
	 PROP_INTERNAL_GETGSMODEL = 0x4009,
	 PROP_INTERNAL_GETMODEL = 0x400A,
};