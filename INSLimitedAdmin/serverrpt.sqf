serverbroadcast = 0;
while {true} do
{
waituntil{(serverbroadcast == 1)};
if (serverbroadcast == 1) then
	{
	diag_log servermessage;
	serverbroadcast = 0;
	};
};