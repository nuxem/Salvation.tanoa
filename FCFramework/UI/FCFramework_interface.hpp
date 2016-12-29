// Control types
#define CT_STATIC           0
#define CT_BUTTON           1
#define CT_EDIT             2
#define CT_SLIDER           3
#define CT_COMBO            4
#define CT_LISTBOX          5
#define CT_TOOLBOX          6
#define CT_CHECKBOXES       7
#define CT_PROGRESS         8
#define CT_HTML             9
#define CT_STATIC_SKEW      10
#define CT_ACTIVETEXT       11
#define CT_TREE             12
#define CT_STRUCTURED_TEXT  13
#define CT_CONTEXT_MENU     14
#define CT_CONTROLS_GROUP   15
#define CT_SHORTCUT_BUTTON  16 // Arma 2 - textured button

#define CT_XKEYDESC         40
#define CT_XBUTTON          41
#define CT_XLISTBOX         42
#define CT_XSLIDER          43
#define CT_XCOMBO           44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT           80
#define CT_OBJECT_ZOOM      81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK        98
#define CT_USER             99
#define CT_MAP              100
#define CT_MAP_MAIN         101
#define CT_List_N_Box       102 // Arma 2 - N columns list box


// Static styles
#define ST_POS            0x0F
#define ST_HPOS           0x03
#define ST_VPOS           0x0C
#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02
#define ST_DOWN           0x04
#define ST_UP             0x08
#define ST_VCENTER        0x0c

#define CT_MAP_MAIN 101
#define ST_PICTURE 48

#define ST_TYPE           0xF0
#define ST_SINGLE         0
#define ST_MULTI          16
#define ST_TITLE_BAR      32
#define ST_PICTURE        48
#define ST_FRAME          64
#define ST_BACKGROUND     80
#define ST_GROUP_BOX      96
#define ST_GROUP_BOX2     112
#define ST_HUD_BACKGROUND 128
#define ST_TILE_PICTURE   144
#define ST_WITH_RECT      160
#define ST_LINE           176

#define ST_SHADOW         0x100
#define ST_NO_RECT        0x200 // this style works for CT_STATIC in conjunction with ST_MULTI
#define ST_KEEP_ASPECT_RATIO  0x800

#define ST_TITLE          ST_TITLE_BAR + ST_CENTER

// Slider styles
#define SL_DIR            0x400
#define SL_VERT           0
#define SL_HORZ           0x400

#define SL_TEXTURES       0x10

// Listbox styles
#define LB_TEXTURES       0x10
#define LB_MULTI          0x20

#define FontM             "puristaMedium"

#define COLOR_BROWN { 0.18, 0.14, 0.11, 0.75 }
#define COLOR_GREEN { 0.2, 0.23, 0.18, 0.75 }
#define COLOR_LIGHTGREEN { 0.4, 0.55, 0.36, 0.4 }
#define COLOR_LIGHTGRAY { 0.6, 0.6, 0.6, 0.8 }
#define COLOR_WHITE { 1, 1, 1, 1 }
#define COLOR_NOALPHA { 0, 0, 0, 0 }
#define COLOR_BLUFOR { 0, 0.3, 1, 1 }
#define COLOR_OPFOR { 1, 0, 0, 1 }
#define COLOR_GUER { 0.5, 0.5, 0.5, 0.5 }
#define COLOR_WHITE_TRANSP { 1, 1, 1, 0.5 }
#define COLOR_BLACK { 0, 0, 0, 1 }
#define COLOR_BLACK_ALPHA { 0, 0, 0, 0.85 }
#define COLOR_BLUFOR_NOALPHA { 0, 0, 1, 1 }
#define COLOR_OPFOR_NOALPHA { 1, 0, 0, 1 }
#define COLOR_RED_DISABLED { 1,0,0,0.4 }
#define COLOR_BLEEDOUT { 0.66,0,0,0.8 }
#define COLOR_BRIGHTGREEN { 0.2,1,0.2,1 }

#define BORDERSIZE      0.01

#define BASE_Y 			0.075

class RscListBox {
	idc = -1;
	type = 5;
	style = 0 + 0x10;
	font = FontM;
	sizeEx = 0.018 * safezoneH;
	rowHeight = 0.02 * safezoneH;
	color[] = COLOR_LIGHTGRAY;
	colorText[] = COLOR_WHITE;
	colorScrollbar[] = COLOR_BRIGHTGREEN;
	colorSelect[] = COLOR_BRIGHTGREEN;
	colorSelect2[] = COLOR_BRIGHTGREEN;
	colorSelectBackground[] = COLOR_LIGHTGRAY;
	colorSelectBackground2[] = COLOR_LIGHTGRAY;
	colorActive[] = COLOR_BRIGHTGREEN;
	colorDisabled[] = COLOR_GREEN;
	columns[] = {0.1, 0.7, 0.1, 0.1};
	period = 0;
	colorBackground[] = COLOR_GREEN;
	maxHistoryDelay = 1.0;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	soundSelect[] = {"\a3\Ui_f\data\Sound\CfgIngameUI\hintExpand", 0.09, 1};
	shadow = 2;

	class ListScrollBar {
		color[] = {1, 1, 1, 0.6};
		colorActive[] = {1, 1, 1, 1};
		colorDisabled[] = {1, 1, 1, 0.3};
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
};

class RscCombo {
	idc = -1;
	type = 4;
	style = 1;
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.035;
	colorSelect[] = COLOR_BRIGHTGREEN;
	colorText[] = COLOR_WHITE;
	colorBackground[] = COLOR_GREEN;
	colorSelectBackground[] = COLOR_LIGHTGRAY;
	colorScrollbar[] = COLOR_BRIGHTGREEN;
	arrowEmpty ="\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
	arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
	wholeHeight = 0.45;
	color[] = COLOR_LIGHTGRAY;
	colorActive[] = COLOR_BRIGHTGREEN;
	colorDisabled[] = COLOR_GREEN;
	font = FontM;
	sizeEx = 0.031;
	soundSelect[] = {"\a3\Ui_f\data\Sound\CfgIngameUI\hintExpand", 0.09, 1};
	soundExpand[] = {"\a3\Ui_f\data\Sound\CfgIngameUI\hintExpand", 0.09, 1};
	soundCollapse[] = {"\a3\Ui_f\data\Sound\CfgIngameUI\hintExpand", 0.09, 1};
	maxHistoryDelay = 1.0;

	class ComboScrollBar {
		color[] = {1, 1, 1, 0.6};
		colorActive[] = {1, 1, 1, 1};
		colorDisabled[] = {1, 1, 1, 0.3};
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
};

class FCFramework_Menu {
	idd = 5565;
	movingEnable = false;
	controlsBackground[] = {};
	controls[] = {"FCFramework_OuterBG", "BgPicture", "FCFramework_OuterBG_F","FCFramework_InnerBG", "FCFramework_InnerBG_F","FCFramework_Header","FCFramework_SquadLabel",
	"FCFramework_SquadZone","FCFramework_PlatoonLabel","FCFramework_ViewDistance","FCFramework_WorldQuality",
	"FCFramework_Close","FCFramework_ButtonWorldVeryLow","FCFramework_ButtonWorldLow","FCFramework_ButtonWorldNormal","FCFramework_ButtonWorldHigh",
	"FCFramework_Slider","FCFramework_SliderVD","FCFramework_LabelMarkers","FCFramework_TeammatesYes","FCFramework_TeammatesNo","FCFramework_LabelPlatoon",
	"FCFramework_PlatoonYes","FCFramework_PlatoonNo","FCFramework_LabelPlatoonActive","FCFramework_LabelMarkersActive","FCFramework_SquadList",
	"FCFramework_ButtonJoin","FCFramework_ButtonNew","FCFramework_ButtonRename","FCFramework_PlatoonZone","FCFramework_ViewZone","FCFramework_WorldZone",
	"FCFramework_MarkersZone","FCFramework_Squad_OuterBG","FCFramework_Squad_InnerBG","FCFramework_Squad_OuterBG_F","FCFramework_Squad_InnerBG_F",
	"FCFramework_ButtonName_Rename","FCFramework_ButtonName_Abort","FCFramework_Squad_TextField","FCFramework_LabelVD","FCFramework_ButtonLeader",
	"FCFramework_SliderVeh","FCFramework_LabelVDVeh","FCFramework_SliderVDVeh","FCFramework_SliderObj","FCFramework_LabelVDObj","FCFramework_SliderVDObj",
	"FCFramework_Leader_OuterBG", "FCFramework_Leader_InnerBG", "FCFramework_Leader_OuterBG_F", "FCFramework_Leader_InnerBG_F",
	"FCFramework_ButtonLeader_Choose", "FCFramework_ButtonLeader_Abort", "FCFramework_Squad_Combo", "FCFramework_VehSound", "FCFramework_SliderVehSound",
	"FCFramework_LabelVehSound","FCFramework_LabelNametags","FCFramework_NametagsActive","FCFramework_NametagsYes","FCFramework_NametagsNo",
	"FCFramework_FPSLabel","FCFramework_FPSEdit"};
	objects[] = {};

	class BgPicture {
		idc = -1;
		type = CT_STATIC;
		style = ST_PICTURE;
		colorText[] = {0.5, 0.4, 0.25, 0.6};
		colorBackground[] = {0, 0, 0, 1};
		font = FontM;
		sizeEx = 0.023;
		moving = false;
		text = "res\camo03.jpg";
		x = (0.15 * safezoneW + safezoneX) - ( 2 * BORDERSIZE);
		y = ((BASE_Y + 0.02) * safezoneH) + safezoneY - (3 * BORDERSIZE);
		w = (0.2 * safezoneW) + (4 * BORDERSIZE);
		h = (0.79 * safezoneH) + (6 * BORDERSIZE);
	};

	class FCFramework_OuterBG {
		idc = -1;
		type =  CT_STATIC;
		style = ST_SINGLE;
		colorText[] = COLOR_BLACK;
		colorBackground[] = COLOR_BROWN;
		font = FontM;
		sizeEx = 0.023;
		x = (0.15 * safezoneW + safezoneX) - ( 2 * BORDERSIZE);
		y = ((BASE_Y + 0.02) * safezoneH) + safezoneY - (3 * BORDERSIZE);
		w = (0.2 * safezoneW) + (4 * BORDERSIZE);
		h = (0.79 * safezoneH) + (6 * BORDERSIZE);
		text = "";
	};
	class FCFramework_OuterBG_F : FCFramework_OuterBG {
		style = ST_FRAME;
	};
	class FCFramework_InnerBG : FCFramework_OuterBG {
		colorBackground[] = COLOR_GREEN;
		x = (0.15 * safezoneW + safezoneX)  - ( BORDERSIZE);
		y = ((BASE_Y + 0.07) * safezoneH) + safezoneY - (1.5 * BORDERSIZE);
		w = 0.2 * safezoneW +  (2 * BORDERSIZE);
		h = 0.74 * safezoneH  + (3 * BORDERSIZE);
	};
	class FCFramework_InnerBG_F : FCFramework_InnerBG {
		style = ST_FRAME;
	};
	class FCFramework_StdText {
		idc = -1;
		type =  CT_STATIC;
		style = ST_LEFT;
		colorText[] = COLOR_WHITE;
		colorBackground[] = COLOR_NOALPHA;
		font = FontM;
		sizeEx = 0.02 * safezoneH;
		shadow = 2;
	};
	class FCFramework_StdHeader : FCFramework_StdText {
		style = ST_CENTER;
		sizeEx = 0.03 * safezoneH;
	};
	class FCFramework_Header : FCFramework_StdHeader {
		x = 0.15 * safezoneW + safezoneX - (BORDERSIZE);
		y = ((BASE_Y + 0.01) * safezoneH) + safezoneY;
		w = 0.2 * safezoneW + ( 2 * BORDERSIZE);
		h = 0.05 * safezoneH - (BORDERSIZE);
		text = "Extended Options";
		colorBackground[] = COLOR_LIGHTGRAY;
	};
	class FCFramework_ButtonGeneric {
		idc = -1;
		type = CT_BUTTON;
		style = ST_CENTER;
		default = false;
		font = FontM;
		sizeEx = 0.018 * safezoneH;
		colorText[] = { 0, 0, 0, 1 };
		colorFocused[] = { 1, 1, 1, 1 };
		colorDisabled[] = { 0.2, 0.2, 0.2, 0.7 };
		colorBackground[] = { 0.8, 0.8, 0.8, 0.8 };
		colorBackgroundDisabled[] = { 0.5, 0.5, 0.5, 0.5 };
		colorBackgroundActive[] = { 1, 1, 1, 1 };
		offsetX = 0.003;
		offsetY = 0.003;
		offsetPressedX = 0.002;
		offsetPressedY = 0.002;
		colorShadow[] = { 0, 0, 0, 0.5 };
		colorBorder[] = { 0, 0, 0, 1 };
		borderSize = 0;
		soundEnter[] = { "", 0, 1 };          // no sound
		soundPush[] = {"\a3\Ui_f\data\Sound\CfgIngameUI\hintExpand", 0.891251, 1};
		soundClick[] = { "", 0, 1 };          // no sound
		soundEscape[] = { "", 0, 1 };          // no sound
		x = 0.15 * safezoneW + safezoneX;
		w = 0.2 * safezoneW; h = 0.03 * safezoneH;
		text = "";
		action = "";
		shadow = 1;
	};
	class FCFramework_Label : FCFramework_StdHeader {
		x = 0.15 * safezoneW + safezoneX;
		w = 0.2 * safezoneW;
		h = 0.03 * safezoneH;
		sizeEx = 0.02 * safezoneH;
		colorBackground[] = COLOR_LIGHTGREEN;
	};

	class FCFramework_DefaultZone : FCFramework_StdText {
		style = ST_CENTER;
		x = 0.15 * safezoneW + safezoneX;
		w = 0.2 * safezoneW;
		colorText[] = COLOR_LIGHTGRAY;
		colorBackground[] = COLOR_RED_DISABLED;
		text = "- disabled -";
	};
	class FCFramework_RegularLabel : FCFramework_Label {
		colorBackground[] = COLOR_NOALPHA;
		style = ST_LEFT;
	};
	class FCFramework_Close : FCFramework_ButtonGeneric {
		idc = 6677;
		x = 0.335 * safezoneW + safezoneX;
		w = 0.015 * safezoneW;  h = 0.02 * safezoneH;
		y = ((BASE_Y + 0.015) * safezoneH) + safezoneY;
		text = "X";
		action = "closeDialog 0";
	};
	class FCFramework_SquadZone : FCFramework_DefaultZone {
		idc = 501;
		y = ((BASE_Y + 0.11) * safezoneH) + safezoneY;
		h = (0.2 * safezoneH) - (2 * BORDERSIZE);
	};
	class FCFramework_SquadLabel : FCFramework_Label {
		idc = 510;
		y = ((BASE_Y + 0.07) * safezoneH) + safezoneY;
		text = "Squad Management";
	};
	class FCFramework_SquadList : RscListBox {
		idc = 515;
		x = 0.15 * safezoneW + safezoneX;
		w = 0.15 * safezoneW;
		y = ((BASE_Y + 0.11) * safezoneH) + safezoneY;
		h = (0.2 * safezoneH) - (2 * BORDERSIZE);
	};
	class FCFramework_ButtonSquad : FCFramework_ButtonGeneric {
		x = 0.3 * safezoneW + safezoneX + BORDERSIZE;
		w = ((0.2 * safezoneW) / 4) - BORDERSIZE;
	};
	class FCFramework_ButtonJoin : FCFramework_ButtonSquad {
		idc = 511;
		text = "Join";
		action = "squadaction = 'join';";
		y = ((BASE_Y + 0.11) * safezoneH) + safezoneY;
	};
	class FCFramework_ButtonNew : FCFramework_ButtonSquad {
		idc = 512;
		text = "Create";
		action = "squadaction = 'create';";
		y = ((BASE_Y + 0.15) * safezoneH) + safezoneY;
	};
	class FCFramework_ButtonRename : FCFramework_ButtonSquad {
		idc = 513;
		text = "Rename";
		action = "squadaction = 'rename';";
		y = ((BASE_Y + 0.19) * safezoneH) + safezoneY;
	};
	class FCFramework_ButtonLeader : FCFramework_ButtonSquad {
		idc = 514;
		text = "Leader";
		action = "squadaction = 'leader';";
		y = ((BASE_Y + 0.23) * safezoneH) + safezoneY;
	};
	class FCFramework_Squad_OuterBG : FCFramework_OuterBG {
		idc = 521;
		style = ST_SINGLE;
		x = (0.37 * safezoneW + safezoneX) - (BORDERSIZE);
		y = ((BASE_Y + 0.18) * safezoneH) + safezoneY - (1.5 * BORDERSIZE);
		w = 0.2 * safezoneW +  (2 * BORDERSIZE);
		h = 0.05 * safezoneH  + (3 * BORDERSIZE);
	};
	class FCFramework_Squad_InnerBG : FCFramework_OuterBG {
		idc = 522;
		colorBackground[] = COLOR_GREEN;
		x = (0.37 * safezoneW + safezoneX);
		y = ((BASE_Y + 0.18) * safezoneH) + safezoneY;
		w = 0.2 * safezoneW;
		h = 0.05 * safezoneH;
	};
	class FCFramework_Squad_OuterBG_F : FCFramework_Squad_OuterBG {
		idc = 523;
		style = ST_FRAME;
	};
	class FCFramework_Squad_InnerBG_F : FCFramework_Squad_InnerBG {
		idc = 524;
		style = ST_FRAME;
	};
	class FCFramework_ButtonName : FCFramework_ButtonGeneric {
		w = ((0.2 * safezoneW) / 5) - BORDERSIZE;
		y = ((BASE_Y + 0.19) * safezoneH) + safezoneY;
	};
	class FCFramework_ButtonName_Rename : FCFramework_ButtonName {
		idc = 525;
		x = 0.4875 * safezoneW + safezoneX;
		text = "Rename";
		action = "squadname = ctrlText 527;";
	};
	class FCFramework_ButtonName_Abort : FCFramework_ButtonName {
		idc = 526;
		x = (0.4875 * safezoneW + safezoneX) + ((0.2 * safezoneW) / 5);
		text = "Cancel";
		action = "squadaction = '';";
	};
	class FCFramework_Squad_TextField : FCFramework_ButtonName {
		idc = 527;
		type = CT_EDIT;
		style = ST_LEFT;
		x = (0.37 * safezoneW + safezoneX) + BORDERSIZE;
		w = 0.11 * safezoneW;
		text = "";
		action = "";
		colorText[] = COLOR_WHITE;
		colorSelection[] = COLOR_BRIGHTGREEN;
		autocomplete = "";
	};

	class FCFramework_Leader_OuterBG : FCFramework_OuterBG {
		idc = 561;
		style = ST_SINGLE;
		x = (0.37 * safezoneW + safezoneX) - (BORDERSIZE);
		y = ((BASE_Y + 0.22) * safezoneH) + safezoneY - (1.5 * BORDERSIZE);
		w = 0.2 * safezoneW +  (2 * BORDERSIZE);
		h = 0.05 * safezoneH  + (3 * BORDERSIZE);
	};
	class FCFramework_Leader_InnerBG : FCFramework_OuterBG {
		idc = 562;
		colorBackground[] = COLOR_GREEN;
		x = (0.37 * safezoneW + safezoneX);
		y = ((BASE_Y + 0.22) * safezoneH) + safezoneY;
		w = 0.2 * safezoneW;
		h = 0.05 * safezoneH;
	};
	class FCFramework_Leader_OuterBG_F : FCFramework_Leader_OuterBG {
		idc = 563;
		style = ST_FRAME;
	};
	class FCFramework_Leader_InnerBG_F : FCFramework_Leader_InnerBG {
		idc = 564;
		style = ST_FRAME;
	};
	class FCFramework_ButtonLeaderGen : FCFramework_ButtonGeneric {
		w = ((0.2 * safezoneW) / 5) - BORDERSIZE;
		y = ((BASE_Y + 0.23) * safezoneH) + safezoneY;
	};
	class FCFramework_ButtonLeader_Choose : FCFramework_ButtonLeaderGen {
		idc = 565;
		x = 0.4875 * safezoneW + safezoneX;
		text = "Choose";
		action = "choose_squadleader = lbCurSel 567;";
	};
	class FCFramework_ButtonLeader_Abort : FCFramework_ButtonLeaderGen {
		idc = 566;
		x = (0.4875 * safezoneW + safezoneX) + ((0.2 * safezoneW) / 5);
		text = "Cancel";
		action = "squadaction = ''";
	};
	class FCFramework_Squad_Combo : RscCombo {
		idc = 567;
		x = (0.37 * safezoneW + safezoneX) + BORDERSIZE;
		w = 0.11 * safezoneW;
		y = ((BASE_Y + 0.23) * safezoneH) + safezoneY;
		h = 0.03 * safezoneH;
	};
	class FCFramework_PlatoonZone : FCFramework_DefaultZone {
		idc = 601;
		y = ((BASE_Y + 0.35) * safezoneH) + safezoneY;
		h = (0.04 * safezoneH) - (2 * BORDERSIZE);
	};
	class FCFramework_PlatoonLabel : FCFramework_Label {
		idc = 610;
		y = ((BASE_Y + 0.31) * safezoneH) + safezoneY;
		text = "Platoon & Squad Awareness";
	};
	class FCFramework_LabelPlatoon : FCFramework_RegularLabel {
		idc = 611;
		y = ((BASE_Y + 0.35) * safezoneH) + safezoneY;
		text = "Show platoon overlay : ";
	};
	class FCFramework_LabelPlatoonActive : FCFramework_RegularLabel {
		idc = 612;
		style = ST_RIGHT;
		colorText[] = COLOR_BRIGHTGREEN;
		text = "active";
		x = 0.2 * safezoneW + safezoneX;
		w = 0.1 * safezoneW;
		y = ((BASE_Y + 0.35) * safezoneH) + safezoneY;
	};
	class FCFramework_PlatoonYes : FCFramework_ButtonGeneric {
		idc = 613;
		w = ((0.08 * safezoneW) / 4);
		y = ((BASE_Y + 0.35) * safezoneH) + safezoneY;
		x = 0.305 * safezoneW + safezoneX;
		text = "Yes";
		action = "show_platoon = true";
	};
	class FCFramework_PlatoonNo : FCFramework_ButtonGeneric {
		idc = 614;
		w = ((0.08 * safezoneW) / 4);
		y = ((BASE_Y + 0.35) * safezoneH) + safezoneY;
		x = (0.32 + BORDERSIZE) * safezoneW + safezoneX;
		text = "No";
		action = "show_platoon = false";
	};
	class FCFramework_ViewZone : FCFramework_DefaultZone {
		idc = 701;
		y = ((BASE_Y + 0.51) * safezoneH) + safezoneY;
		h = (0.04 * safezoneH) - (2 * BORDERSIZE);
	};
	class FCFramework_ViewDistance : FCFramework_Label {
		idc = 711;
		y = ((BASE_Y + 0.47) * safezoneH) + safezoneY;
		text = "Adjust View Distance";
	};
	class FCFramework_Slider {
		idc = 712;
		type = CT_SLIDER;
		style = SL_HORZ;
		x = 0.19 * safezoneW + safezoneX;
		w = 0.12 * safezoneW;
		y = ((BASE_Y + 0.515) * safezoneH) + safezoneY;
		h = 0.025 * safezoneH;
		text = "View Distance";
		color[] = { 1, 1, 1, 1 };
		coloractive[] = { 1, 1, 1, 1 };
		onSliderPosChanged = "desiredviewdistance_inf = (sliderPosition 712)";
	};
	class FCFramework_SliderVD : FCFramework_Label {
		idc = 713;
		style = ST_LEFT;
		x = 0.31 * safezoneW + safezoneX;
		w = 0.05 * safezoneW;
		y = ((BASE_Y + 0.505) * safezoneH) + safezoneY;
		h = 0.03 * safezoneH;
		colorBackground[] = COLOR_NOALPHA;
		text = "";
	};
	class FCFramework_LabelVD : FCFramework_Label {
		idc = 714;
		style = ST_LEFT;
		x = 0.15 * safezoneW + safezoneX;
		w = 0.05 * safezoneW;
		y = ((BASE_Y + 0.505) * safezoneH) + safezoneY;
		h = 0.03 * safezoneH;
		colorBackground[] = COLOR_NOALPHA;
		text = "Infantry";
	};
	class FCFramework_SliderVeh {
		idc = 722;
		type = CT_SLIDER;
		style = SL_HORZ;
		x = 0.19 * safezoneW + safezoneX;
		w = 0.12 * safezoneW;
		y = ((BASE_Y + 0.545) * safezoneH) + safezoneY;
		h = 0.025 * safezoneH;
		text = "View Distance";
		color[] = { 1, 1, 1, 1 };
		coloractive[] = { 1, 1, 1, 1 };
		onSliderPosChanged = "desiredviewdistance_veh = (sliderPosition 722)";
	};
	class FCFramework_SliderVDVeh : FCFramework_Label {
		idc = 723;
		style = ST_LEFT;
		x = 0.31 * safezoneW + safezoneX;
		w = 0.05 * safezoneW;
		y = ((BASE_Y + 0.535) * safezoneH) + safezoneY;
		h = 0.03 * safezoneH;
		colorBackground[] = COLOR_NOALPHA;
		text = "";
	};
	class FCFramework_LabelVDVeh : FCFramework_Label {
		idc = 724;
		style = ST_LEFT;
		x = 0.15 * safezoneW + safezoneX;
		w = 0.05 * safezoneW;
		y = ((BASE_Y + 0.535) * safezoneH) + safezoneY;
		h = 0.03 * safezoneH;
		colorBackground[] = COLOR_NOALPHA;
		text = "Vehicles";
	};
	class FCFramework_SliderObj {
		idc = 732;
		type = CT_SLIDER;
		style = SL_HORZ;
		x = 0.19 * safezoneW + safezoneX;
		w = 0.12 * safezoneW;
		y = ((BASE_Y + 0.575) * safezoneH) + safezoneY;
		h = 0.025 * safezoneH;
		text = "View Distance";
		color[] = { 1, 1, 1, 1 };
		coloractive[] = { 1, 1, 1, 1 };
		onSliderPosChanged = "desiredviewdistance_obj = (sliderPosition 732)";
	};
	class FCFramework_SliderVDObj : FCFramework_Label {
		idc = 733;
		style = ST_LEFT;
		x = 0.31 * safezoneW + safezoneX;
		w = 0.05 * safezoneW;
		y = ((BASE_Y + 0.565) * safezoneH) + safezoneY;
		h = 0.03 * safezoneH;
		colorBackground[] = COLOR_NOALPHA;
		text = "";
	};
	class FCFramework_LabelVDObj : FCFramework_Label {
		idc = 734;
		style = ST_LEFT;
		x = 0.15 * safezoneW + safezoneX;
		w = 0.05 * safezoneW;
		y = ((BASE_Y + 0.565) * safezoneH) + safezoneY;
		h = 0.03 * safezoneH;
		colorBackground[] = COLOR_NOALPHA;
		text = "Objects";
	};
	class FCFramework_FPSLabel : FCFramework_Label {
		idc = 724;
		style = ST_LEFT;
		x = 0.15 * safezoneW + safezoneX;
		w = 0.3 * safezoneW;
		y = ((BASE_Y + 0.61) * safezoneH) + safezoneY;
		h = 0.03 * safezoneH;
		colorBackground[] = COLOR_NOALPHA;
		sizeEx = 0.018 * safezoneH;
		text = "Adjust view distance to keep FPS above";
	};
	class FCFramework_FPSEdit {
		idc = 960;
		access = 0;
		type = CT_EDIT;
		style = ST_LEFT + ST_FRAME;
		x = 0.317 * safezoneW + safezoneX;
		w = 0.03 * safezoneW;
		y = ((BASE_Y + 0.61) * safezoneH) + safezoneY;
		h = 0.03 * safezoneH;
		colorBackground[] = {0,0,0,0};
		colorText[] = {1,1,1,1};
		colorSelection[] = {1,1,1,0.25};
		colorDisabled[] = { 0.2, 0.2, 0.2, 0.7 };
		colorBackgroundDisabled[] = { 0.5, 0.5, 0.5, 0.5 };
		font = FontM;
		sizeEx = 0.02 * safezoneH;
		autocomplete = "";
		text = "";
		shadow = 0;
	};
	class FCFramework_WorldZone : FCFramework_DefaultZone {
		idc = 801;
		y = ((BASE_Y + 0.7) * safezoneH) + safezoneY;
		h = (0.04 * safezoneH) - (2 * BORDERSIZE);
	};
	class FCFramework_WorldQuality : FCFramework_Label {
		idc = 810;
		y = ((BASE_Y + 0.66) * safezoneH) + safezoneY;
		text = "Adjust Terrain Details";
	};
	class FCFramework_ButtonWorld : FCFramework_ButtonGeneric {
		w = ((0.2 * safezoneW) / 4) - BORDERSIZE;
		y = ((BASE_Y + 0.7) * safezoneH) + safezoneY;
	};
	class FCFramework_ButtonWorldVeryLow : FCFramework_ButtonWorld {
		idc = 812;
		x = 0.15 * safezoneW + safezoneX;
		text = "Very Low";
		action = "setTerrainGrid 50; hint 'Terrain details set to Very Low'";
	};
	class FCFramework_ButtonWorldLow : FCFramework_ButtonWorld {
		idc = 813;
		x = (0.15 * safezoneW + safezoneX) + (((0.2 * safezoneW) / 4) * 1);
		text = "Low";
		action = "setTerrainGrid 25; hint 'Terrain details set to Low'";
	};
	class FCFramework_ButtonWorldNormal : FCFramework_ButtonWorld {
		idc = 814;
		x = (0.15 * safezoneW + safezoneX) + (((0.2 * safezoneW) / 4) * 2);
		text = "Normal";
		action = "setTerrainGrid 12.5; hint 'Terrain details set to Normal'";
	};
	class FCFramework_ButtonWorldHigh : FCFramework_ButtonWorld {
		idc = 815;
		x = (0.15 * safezoneW + safezoneX) + (((0.2 * safezoneW) / 4) * 3);
		text = "High";
		action = "setTerrainGrid 3.125; hint 'Terrain details set to High'";
	};
	class FCFramework_MarkersZone : FCFramework_DefaultZone {
		idc = 901;
		y = ((BASE_Y + 0.43) * safezoneH) + safezoneY;
		h = (0.04 * safezoneH) - (2 * BORDERSIZE);
	};
	class FCFramework_LabelNametags : FCFramework_RegularLabel {
		idc = 961;
		y = ((BASE_Y + 0.39) * safezoneH) + safezoneY;
		text = "Show player nametags : ";
	};
	class FCFramework_NametagsActive : FCFramework_RegularLabel {
		idc = 962;
		style = ST_RIGHT;
		colorText[] = COLOR_BRIGHTGREEN;
		text = "active";
		x = 0.2 * safezoneW + safezoneX;
		w = 0.1 * safezoneW;
		y = ((BASE_Y + 0.39) * safezoneH) + safezoneY;
	};
	class FCFramework_NametagsYes : FCFramework_ButtonGeneric {
		idc = 963;
		w = ((0.08 * safezoneW) / 4);
		y = ((BASE_Y + 0.39) * safezoneH) + safezoneY;
		x = 0.305 * safezoneW + safezoneX;
		text = "Yes";
		action = "show_nametags = true";
	};
	class FCFramework_NametagsNo : FCFramework_ButtonGeneric {
		idc = 964;
		w = ((0.08 * safezoneW) / 4);
		y = ((BASE_Y + 0.39) * safezoneH) + safezoneY;
		x = (0.32 + BORDERSIZE) * safezoneW + safezoneX;
		text = "No";
		action = "show_nametags = false";
	};
	class FCFramework_LabelMarkers : FCFramework_RegularLabel {
		idc = 911;
		y = ((BASE_Y + 0.43) * safezoneH) + safezoneY;
		text = "Show teammates on map : ";
	};
	class FCFramework_LabelMarkersActive : FCFramework_RegularLabel {
		idc = 912;
		style = ST_RIGHT;
		colorText[] = COLOR_BRIGHTGREEN;
		text = "active";
		x = 0.2 * safezoneW + safezoneX;
		w = 0.1 * safezoneW;
		y = ((BASE_Y + 0.43) * safezoneH) + safezoneY;
	};
	class FCFramework_TeammatesYes : FCFramework_ButtonGeneric {
		idc = 913;
		w = ((0.08 * safezoneW) / 4);
		y = ((BASE_Y + 0.43) * safezoneH) + safezoneY;
		x = 0.305 * safezoneW + safezoneX;
		text = "Yes";
		action = "show_teammates = true";
	};
	class FCFramework_TeammatesNo : FCFramework_ButtonGeneric {
		idc = 914;
		w = ((0.08 * safezoneW) / 4);
		y = ((BASE_Y + 0.43) * safezoneH) + safezoneY;
		x = (0.32 + BORDERSIZE) * safezoneW + safezoneX;
		text = "No";
		action = "show_teammates = false";
	};

	class FCFramework_VehSound : FCFramework_Label {
		idc = 1101;
		y = ((BASE_Y + 0.74) * safezoneH) + safezoneY;
		text = "In-Vehicle Sound Volume";
	};
	class FCFramework_SliderVehSound {
		idc = 1102;
		type = CT_SLIDER;
		style = SL_HORZ;
		x = 0.15 * safezoneW + safezoneX;
		w = 0.16 * safezoneW;
		y = ((BASE_Y + 0.785) * safezoneH) + safezoneY;
		h = 0.025 * safezoneH;
		text = "View Distance";
		color[] = { 1, 1, 1, 1 };
		coloractive[] = { 1, 1, 1, 1 };
		onSliderPosChanged = "desired_vehvolume = (sliderPosition 1102)";
	};
	class FCFramework_LabelVehSound : FCFramework_Label {
		idc = 1103;
		style = ST_LEFT;
		x = 0.31 * safezoneW + safezoneX;
		w = 0.05 * safezoneW;
		y = ((BASE_Y + 0.775) * safezoneH) + safezoneY;
		h = 0.03 * safezoneH;
		colorBackground[] = COLOR_NOALPHA;
		text = "Test";
	};
};

class FCFrameworkButton {
	idc = -1;
	type = CT_BUTTON;
	style = ST_CENTER;
	default = false;
	font = FontM;
	sizeEx = 0.018 * safezoneH;
	colorText[] = { 0, 0, 0, 1 };
	colorFocused[] = { 1, 1, 1, 1 };
	colorDisabled[] = { 0.2, 0.2, 0.2, 0.7 };
	colorBackground[] = { 0.8, 0.8, 0.8, 0.8 };
	colorBackgroundDisabled[] = { 0.5, 0.5, 0.5, 0.5 };
	colorBackgroundActive[] = { 1, 1, 1, 1 };
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	colorShadow[] = { 0, 0, 0, 0.5 };
	colorBorder[] = { 0, 0, 0, 1 };
	borderSize = 0;
	soundEnter[] = { "", 0, 1 };          // no sound
	soundPush[] = {"\a3\Ui_f\data\Sound\CfgIngameUI\hintExpand", 0.891251, 1};
	soundClick[] = { "", 0, 1 };          // no sound
	soundEscape[] = { "", 0, 1 };          // no sound
	x = 0.45 * safezoneW + safezoneX;
	y = ((BASE_Y + 0.7) * safezoneH) + safezoneY;
	w = 0.1 * safezoneW;
	h = 0.04 * safezoneH;
	text = "";
	action = "";
	shadow = 1;
};

class FCFramework_respawn {
	idd = 5566;
	movingEnable = false;
	controlsBackground[] = {"FCFramework_BleedoutBar_BG"};
	controls[] = {"FCFramework_BleedoutBar","FCFramework_BleedoutBar_F","FCFramework_Useless","FCFramework_Respawn","FCFramework_ReviveLabel","FCFramework_WoundedLabel", "FCFramework_ReplaceAI"};
	objects[] = {};
	class FCFramework_Respawn : FCFrameworkButton {
		idc = -1;
		x = 0.45 * safezoneW + safezoneX;
		y = 0.75 * safezoneH + safezoneY;
		w = 0.1 * safezoneW;
		h = 0.04 * safezoneH;
		text = "Respawn";
		action = "player setDamage 1";
	};
	class FCFramework_ReplaceAI : FCFrameworkButton {
		idc = 678;
		x = 0.45 * safezoneW + safezoneX;
		y = 0.8 * safezoneH + safezoneY;
		w = 0.1 * safezoneW;
		h = 0.04 * safezoneH;
		text = "Replace nearest AI";
		action = "replace_ai = 1";

	}
	class FCFramework_Useless : FCFramework_Respawn {
		idc = -1;
		x = -5;
		y = -5;
		w = 0.1;
		h = 0.1;
		text = "";
		action = "";
	};
	class FCFramework_ReviveLabel {
		idc = 5567;
		type =  CT_STATIC;
		style = ST_CENTER;
		colorText[] = COLOR_WHITE;
		colorBackground[] = COLOR_NOALPHA;
		font = FontM;
		sizeEx = 0.02 * safezoneH;
		shadow = 1;
		x = 0.4 * safezoneW + safezoneX;
		y = 0.7 * safezoneH + safezoneY;
		w = 0.2 * safezoneW;
		h = 0.025 * safezoneH;
		text = "";
	};
	class FCFramework_WoundedLabel {
		idc = 4567;
		type =  CT_STATIC;
		style = ST_CENTER;
		colorText[] = COLOR_WHITE;
		colorBackground[] = COLOR_NOALPHA;
		font = FontM;
		sizeEx = 0.07 * safezoneH;
		shadow = 1;
		x = 0.3 * safezoneW + safezoneX;
		y = 0.25 * safezoneH + safezoneY;
		w = 0.4 * safezoneW;
		h = 0.07 * safezoneH;
		text = $STR_REVIVE_LABEL;
	};
	class FCFramework_BleedoutBar {
		idc = 6699;
		type =  CT_STATIC;
		style = ST_SINGLE;
		colorText[] = COLOR_WHITE;
		colorBackground[] = COLOR_BLEEDOUT;
		font = FontM;
		sizeEx = 0.023;
		x = 0.4 * safezoneW + safezoneX;
		y = 0.7 * safezoneH + safezoneY;
		w = 0.2 * safezoneW;
		h = 0.03 * safezoneH;
		text = "";
	};
	class FCFramework_BleedoutBar_BG : FCFramework_BleedoutBar {
		idc = -1;
		colorBackground[] = COLOR_BLACK_ALPHA;
		x = 0.4 * safezoneW + safezoneX - 0.005;
		y = 0.7 * safezoneH + safezoneY - 0.005;
		w = 0.2 * safezoneW + 0.01;
		h = 0.03 * safezoneH + 0.01;
	};
	class FCFramework_BleedoutBar_F : FCFramework_BleedoutBar {
		idc = 6698;
		colorText[] = COLOR_WHITE;
		style = ST_FRAME;
		x = 0.4 * safezoneW + safezoneX - 0.005;
		y = 0.7 * safezoneH + safezoneY - 0.005;
		w = 0.2 * safezoneW + 0.01;
		h = 0.03 * safezoneH + 0.01;
	};
};