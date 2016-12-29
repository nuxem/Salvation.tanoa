_loop = this select 1;
_run = true;

if !(_loop) exitWith {};

while {_run} do
{
	(0 fadeMusic 0.2);
	sleep random 300;
	[["RadioAmbient2", "RadioAmbient3", "RadioAmbient4", "RadioAmbient5", "RadioAmbient6", "RadioAmbient7", "RadioAmbient8", "RadioAmbient9", "RadioAmbient10", "RadioAmbient11", "RadioAmbient12", "RadioAmbient13", "RadioAmbient14", "RadioAmbient15", "RadioAmbient16", "RadioAmbient17", "RadioAmbient18", "RadioAmbient19", "RadioAmbient20", "RadioAmbient21", "RadioAmbient22", "RadioAmbient23", "RadioAmbient24", "RadioAmbient25", "RadioAmbient26", "RadioAmbient27", "RadioAmbient28", "RadioAmbient29", "RadioAmbient30"], 300] spawn BIS_fnc_music;
	if (vehicle player == player) then {_run = false};
};