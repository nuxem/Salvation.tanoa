//MAIN SETTINGS INSLimitedAdmin

_pboclassesdetect = true; //Scan player PBO files ("true" is on, "false" is off, set to true by default)
_pboclasses = ["stra_debug2","DevCon","mf_sdc","tao_a3_debugger","KRON_SupportCall"]; //Classnames from addons you don't wan't on your server


_bannedvarsdetect = false; //Detect player using Banned variable names ("true" is on, "false" is off, set to flase by default)
_bannedvars = [""]; //Banned variable names (e.g. an array called: playerteleport)


_speedhackdetect = true; //Detect player speed hacking ("true" is on, "false" is off, set to true by default)
_maxspeed = 400; //Non-unit vehicle max speed on your server (Variable for detecting speed-hacking, set to 400 by default)


_bannedwepsdetect = true; //Detect player using Banned weapon ("true" is on, "false" is off, set to flase by default)
_bannedweps = ["Binocular"]; //Weapons you can't obtain legitimately in your mission


_bannedvclsdetect = true; //Detect player using Banned vehicle ("true" is on, "false" is off, set to flase by default)
_bannedvcls = ["B_Hunter_F"]; //Vehicles you can't obtain legitimately in your mission


_teleportdetect = false; //Detect player teleporting ("true" is on, "false" is off, set to false by default, MAY CAUSE LAGG)


_banmessage = "Your Not Welcome Here, I Suggest You ALT+F4"; //Message Displayed To Hacker When Detected

//Do NOT edit below this point

INSLimitedAdminServerVariables = [_pboclassesdetect,_pboclasses,_bannedvarsdetect,_bannedvars,_speedhackdetect,_maxspeed,_bannedwepsdetect,_bannedweps,_bannedvclsdetect,_bannedvcls,_teleportdetect,_banmessage];