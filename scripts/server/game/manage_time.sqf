private [ "_accelerated_time" ];

while { true } do {
	if ( FCLIB_shorter_nights && ( daytime > 21 || daytime < 3 ) ) then {
		_accelerated_time = FCLIB_time_factor * 3;
		if ( _accelerated_time > 100 ) then {
			_accelerated_time = 100;
		};
		setTimeMultiplier _accelerated_time;
	} else {
		setTimeMultiplier FCLIB_time_factor;
	};
	sleep 10;
};
