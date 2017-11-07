private ["_light","_extinguish"];

_chemlights = ["Chemlight_green","Chemlight_yellow","Chemlight_red","Chemlight_blue"];

_items = magazines player;
_availChems = _items arrayIntersect _chemlights;

if (count _availChems == 0) then {hint "No chemlights";} else
{
	_chem = _availChems call BIS_fnc_selectRandom;

	/*

	_chemColour = [1.0, 0.0, 0.0];

	if (_chem == "Chemlight_red") then {_chemColour = [1.0, 0.0, 0.0];};
	if (_chem == "Chemlight_green") then {_chemColour = [0.0, 1.0, 0.0];};
	if (_chem == "Chemlight_blue") then {_chemColour = [0.0, 0.0, 1.0];};
	if (_chem == "Chemlight_yellow") then {_chemColour = [0.5, 0.5, 0.0];};	
	*/
	/*
	if (_chem == "Chemlight_red") then {_chemColour = "Chemlight_red";};
	if (_chem == "Chemlight_green") then {_chemColour = "Chemlight_green";};
	if (_chem == "Chemlight_blue") then {_chemColour = "Chemlight_blue";};
	if (_chem == "Chemlight_yellow") then {_chemColour = "Chemlight_yellow";};	
	*/
	player removeItem _chem;

	_pos = position player;
	_obj = player;

	player playMove "AinvPknlMstpSnonWnonDr_medic3";

	sleep 5;

	_chemLight = _chem createVehicle (position player);  
	//_chemLight attachTo [player, [0,0,-0.1]]; 
	_chemLight attachTo [player, [0,0,0.0],"pelvis"];
	/*
	_light = createVehicle ["#lightpoint", getPos _obj, [], 0, "NONE"];
	_light lightAttachObject [player, [0.0,0.0,-2.5]];
	_light setLightBrightness 0.8;
	_light setLightAmbient _chemColour;
	_light setLightColor _chemColour;
	*/

	_extinguish = player addAction ["Extinguish Chemlight","addons\AttachChemlight\extinguishLight.sqf",_chemLight,0,false,true,"","not (vehicle player != player)"];
	
	player setVariable ["chemlightAttached", true, false]; // Chemlight is on
	
	
};
uiSleep 875;
/*
deleteVehicle _light;
*/
deleteVehicle _chemLight;
player removeAction _extinguish;
player setVariable ["chemlightAttached", false, false]; // Chemlight is off

