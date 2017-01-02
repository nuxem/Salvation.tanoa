if (isServer) exitWith
{
[] execVM "INSLimitedAdmin\serverrpt.sqf";
};

[]ExecVM "INSLimitedAdmin\INSLimitedAdminServerSettings.hpp";
systemChat "INSLimitedAdmin: Starting AntiHack Scripts..."; //Startup message
_uid = getPlayerUID vehicle player; //Init variable
broadcast = 0; //Init variable
_hacklock = false; //Init variable
_player = name player; //Init variable
sleep 0.2;
_pboclassesdetect = INSLimitedAdminServerVariables select 0;
_pboclasses = INSLimitedAdminServerVariables select 1;
_bannedvarsdetect = INSLimitedAdminServerVariables select 2;
_bannedvars = INSLimitedAdminServerVariables select 3;
_speedhackdetect = INSLimitedAdminServerVariables select 4;
_maxspeed = INSLimitedAdminServerVariables select 5;
_bannedwepsdetect = INSLimitedAdminServerVariables select 6;
_bannedweps = INSLimitedAdminServerVariables select 7;
_bannedvclsdetect = INSLimitedAdminServerVariables select 8;
_bannedvcls = INSLimitedAdminServerVariables select 9;
_teleportdetect = INSLimitedAdminServerVariables select 10;
_banmessage = INSLimitedAdminServerVariables select 11;

_playermessage = "INSLimitedAdmin: " + _player + " Has Been Caught Hacking, Contact An Admin Now! UID:" + _uid;

servermessage = _player + " Joined The Server UID:" + _uid;
publicVariableServer "servermessage";
serverbroadcast = 1;
publicVariableServer "serverbroadcast";

sleep 0.2;

if (_teleportdetect) then
{
[] execVM "INSLimitedAdmin\antiteleport.sqf";
};

if (_pboclassesdetect) then
{
for "_i" from 0 to ((count _pboclasses) - 1) do
{
_classname = (_pboclasses select _i);
if (isClass (configFile >> _classname)) then
	{
	_hacklock = true;
	servermessage = "INSLimitedAdmin: " + _player + " Joined With A Banned MOD File UID:" + _uid;
	publicVariableServer "servermessage";
	serverbroadcast = 1;
	publicVariableServer "serverbroadcast";
	};
};
};

if (_bannedvarsdetect) then
{
for "_i" from 0 to ((count _bannedvars) - 1) do
{
_varname = (_bannedvars select _i);
if !(isnil _varname) then 
	{
	_hacklock = true;
	servermessage = "INSLimitedAdmin: " + _player + " Passed A Banned Variable UID:" + _uid;
	publicVariableServer "servermessage";
	serverbroadcast = 1;
	publicVariableServer "serverbroadcast";
	};
};
};

sleep 0.2;

if !(_hacklock) then
	{
	systemChat "INSLimitedAdmin: Done!"; //Startup message
	};

while {true} do
{
waituntil{((_bannedwepsdetect) && ((currentWeapon player) in _bannedweps)) or ((_bannedvclsdetect) && ((TypeOf (vehicle player)) in _bannedvcls)) or (broadcast == 1) or ((_speedhackdetect) && !((vehicle player) in vehicles) && (round speed (vehicle player) > 21) && (alive player)) or ((_speedhackdetect) && ((vehicle player) in vehicles) && (round speed (vehicle player) > _maxspeed))};
if ((_speedhackdetect) && !((vehicle player) in vehicles) && (round speed (vehicle player) > 21) && (alive player)) then
	{
	sleep 2;
	if (alive player) then
		{
		_hacklock = true;
		servermessage = "INSLimitedAdmin: " + _player + " Speed Hacked As Unit UID:" + _uid;
		publicVariableServer "servermessage";
		serverbroadcast = 1;
		publicVariableServer "serverbroadcast";
		};
	};
if ((_speedhackdetect) && ((vehicle player) in vehicles) && (round speed (vehicle player) > _maxspeed)) then
	{
	_hacklock = true;
	servermessage = "INSLimitedAdmin: " + _player + " Speed Hacked In Vehicle UID:" + _uid;
	publicVariableServer "servermessage";
	serverbroadcast = 1;
	publicVariableServer "serverbroadcast";
	};
if ((_bannedwepsdetect) && ((currentWeapon player) in _bannedweps)) then
	{
	_hacklock = true;
	servermessage = "INSLimitedAdmin: " + _player + " Used A Banned Weapon UID:" + _uid;
	publicVariableServer "servermessage";
	serverbroadcast = 1;
	publicVariableServer "serverbroadcast";
	};
sleep 0.2;
if ((TypeOf (vehicle player)) in _bannedvcls) then
	{
	_veh = vehicle player;
	deleteVehicle _veh;
	_hacklock = true;
	servermessage = "INSLimitedAdmin: " + _player + " Entered Banned Vehicle UID:" + _uid;
	publicVariableServer "servermessage";
	serverbroadcast = 1;
	publicVariableServer "serverbroadcast";
	};
sleep 0.2;
if (_hacklock) exitWith
	{
	titleCut ["", "BLACK",0];
	disableUserInput true;
	titleText [_banmessage, "PLAIN"];
	broadcast = 1;
	publicVariable "broadcast";
	publicVariable "_playermessage";
	player addScore -5000;
	servermessage = "INSLimitedAdmin: " + _player + " Was Hack-Locked By INSLimitedAdmin UID:" + _uid;
	publicVariableServer "servermessage";
	serverbroadcast = 1;
	publicVariableServer "serverbroadcast";
	execVM "INSLimitedAdmin\antimove.sqf";
	};
sleep 0.2;
if (broadcast == 1) then
	{
	hint playermessage;
	systemChat playermessage;
	broadcast = 0;
	};
};