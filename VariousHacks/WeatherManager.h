#pragma once

namespace m3d
{
	enum GlobalTimeParams 
	{
		GTP_SUNRISE_TIME = 0,
		GTP_DAY_TIME = 1,
		GTP_SUNSET_TIME = 2,
		GTP_NIGHT_TIME = 3,
		GTP_NUM_PARAMS = 4
	};

	struct WeatherManager
	{
		BYTE _offset[0x3C];
		GlobalTimeParams m_curDayTime;

		void UpdateDayTime()
		{
			FUNC(0x00660060, void, __thiscall, _UpdateDayTime, WeatherManager*);
			_UpdateDayTime(this);
		}
	};
}