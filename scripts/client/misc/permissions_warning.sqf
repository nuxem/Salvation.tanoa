if ( FCLIB_permissions_param ) then {

	waitUntil { !(isNil "FCLIB_permissions") };

	sleep 5;

	while { count FCLIB_permissions == 0 } do {
		hint localize "STR_PERMISSION_WARNING";
		sleep 5;
	};

	hintSilent "";

};