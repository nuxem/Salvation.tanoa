params [ "_source", "_permission" ];
private [ "_uidvar", "_ret" ];

if ( isNil "FCLIB_last_permission_check_time" ) then { FCLIB_last_permission_check_time = -1000; };
if ( isNil "FCLIB_permissions_cache" ) then { FCLIB_permissions_cache = []; };

_ret = false;

if ( !FCLIB_permissions_param ) then {
	_ret = true;
} else {
	if ( !(isNil "FCLIB_permissions") && !(isNull _source) ) then {

		if ( time > FCLIB_last_permission_check_time + 10 ) then {
			FCLIB_last_permission_check_time = time;
			_uidvar = getPlayerUID _source;
			{ if ( _uidvar == _x select 0 ) exitWith { FCLIB_permissions_cache  = [] + (_x select 1) }; } foreach FCLIB_permissions;
		};

		if ( count FCLIB_permissions_cache > _permission ) then {
			_ret = FCLIB_permissions_cache select _permission;
		};
	};
};

_ret