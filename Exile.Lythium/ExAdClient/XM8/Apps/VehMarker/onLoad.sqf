params["_display","_slide","_idc"];
private ["_vehMarker","_backbtn","_vehPic","_Instruction","_OffBtn","_OnBtn","_newParent"];
disableSerialization;

_slideClass = "VehMarker";

_newParent = [_display,_slide,([_slideClass,"ctrlGrp"] call ExAd_fnc_getNextIDC),[0, -0.03, 34 * _pW, 0.76]] call ExAd_fnc_createCtrlGrp;
_newParent ctrlEnable true;

_OnBtn = _display ctrlCreate ["RscButtonMenu", 15012,_newParent];
_OnBtn ctrlSetPosition [(32 - 20) * (0.025),(20 - 10) * (0.04),6 * (0.025),1 * (0.04)];
_OnBtn ctrlCommit 0;
_OnBtn ctrlSetText "On";
_OnBtn ctrlSetEventHandler ["ButtonClick", "call fnc_vehMarkerOn"];
 
_OffBtn = _display ctrlCreate ["RscButtonMenu", 15013,_newParent];
_OffBtn ctrlSetPosition [(32 - 10) * (0.025),(20 - 10) * (0.04),6 * (0.025),1 * (0.04)];
_OffBtn ctrlCommit 0;
_OffBtn ctrlSetText "Off";
_OffBtn ctrlSetEventHandler ["ButtonClick", "call fnc_vehMarkerOff"];

_backbtn = _display ctrlCreate ["RscButtonMenu", 15014,_newParent];
_backbtn ctrlSetPosition [0.62,0.1,0.20,0.04]; 
_backbtn ctrlCommit 0;
_backbtn ctrlSetText "Go Back";
_backbtn ctrlSetEventHandler ["ButtonClick", "['extraApps', 1] call ExileClient_gui_xm8_slide"];

_Instruction = _display ctrlCreate ["RscStructuredText", 15015,_newParent];
_Instruction ctrlSetPosition [(5.8 - 3) * (0.025), (20 - 12) * (0.04), 7.2 * (0.12), 3.75 * (0.02)];
_Instruction ctrlCommit 0;
_Instruction ctrlSetStructuredText parseText "<t size='1' align='center'>Toggle your vehicle markers (Only viewable by you):</t>";

fnc_vehMarkerOn = {
   
        _playerUID = getPlayerUID player;
        {
            _vehicle = _x;
            diag_log format["_vehicle is %1", _vehicle];
            _vehOwner = _vehicle getVariable ["ExileOwnerUID", ""];
            diag_log format["_vehOwner is %1", _vehOwner];
            _vehicleName = getText(configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "displayName");
            diag_log format["_vehicleName is %1", _vehicleName];
            if ((_playerUID isEqualTo _vehOwner) && (_vehicle isKindOf "LandVehicle")) then
            {
            _pos = getPos _vehicle;
            _marker = createMarkerLocal [_vehicleName, _pos];
            _marker setMarkerTextLocal _vehicleName;
            _marker setMarkerTypeLocal "mil_triangle";
            _marker setMarkerColorLocal "ColorYellow"
            };
        }
        forEach (allMissionObjects "AllVehicles");
	["SuccessTitleAndText",["Vehicle Markers toggled on."]] call ExileClient_gui_toaster_addTemplateToast;
};
 
fnc_vehMarkerOff = {
   
        _playerUID = getPlayerUID player;
        {
            _vehicle = _x;
            _vehOwner = _vehicle getVariable ["ExileOwnerUID", ""];
            _vehicleName = getText(configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "displayName");
            if ((_playerUID isEqualTo _vehOwner) && (_vehicle isKindOf "LandVehicle")) then
            {
            _pos = getPos _vehicle;
            deleteMarkerLocal _vehicleName;
            };
        }
        forEach (allMissionObjects "AllVehicles");
	["ErrorTitleAndText",["Vehicle Markers toggled off."]] call ExileClient_gui_toaster_addTemplateToast;
};