/**
 * ExileClient_gui_selectSpawnLocation_show
 *
 * Exile Mod
 * www.exilemod.com
 * © 2015 Exile Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 */
 
private["_display","_spawnButton","_listBox","_listItemIndex","_numberOfSpawnPoints","_randNum","_randData","_randomSpawnIndex"];
disableSerialization;
diag_log "Selecting spawn location...";
ExileClientSpawnLocationSelectionDone = false;
ExileClientSelectedSpawnLocationMarkerName = "";
createDialog "RscExileSelectSpawnLocationDialog";
waitUntil{_display = findDisplay 24002;!isNull _display};
_display displayAddEventHandler ["KeyDown", "_this call ExileClient_gui_loadingScreen_event_onKeyDown"];
_listBox = _display displayCtrl 24002;
lbClear _listBox;
{
	if (getMarkerType _x == "ExileSpawnZone") then
	{
		_listItemIndex = _listBox lbAdd (markerText _x);
		_listBox lbSetData [_listItemIndex, _x];
	};
} forEach allMapMarkers;
_numberOfSpawnPoints = {getMarkerType _x == "ExileSpawnZone"} count allMapMarkers;
if(_numberOfSpawnPoints > 0)then 
{
	_randNum = floor(random _numberOfSpawnPoints);
	_randData = lbData [24002,_randNum];
	_randomSpawnIndex = _listBox lbAdd "Random";
	_listBox lbSetData [_randomSpawnIndex, _randData];
};

defaultLBsize = lbSize _listBox;
myUID = getPlayerUID player;
myFlags = [];
{
	_flag = _x;
	// _owner = _flag getVariable ["ExileOwnerUID", ""];
	_canBuild = _flag getVariable ["ExileTerritoryBuildRights", ""];
	if(myUID in _canBuild)then
	{
		_name = _flag getVariable ["ExileTerritoryName", ""];
		_lbid = _listBox lbAdd _name;
		_listBox lbSetColor [_lbid, [0,0.68,1,1]];
		_listBox lbSetData [_lbid,str(count myFlags)];
		myFlags pushBack _flag;
	};
} forEach (allMissionObjects "Exile_Construction_Flag_Static");

disableSerialization;
fnc_LBSelChanged_24002 = {
	disableSerialization;
	_ctrl = _this select 0;
	_curSel = lbCurSel _ctrl;
	if(_curSel < defaultLBsize)then
	{
		_this call ExileClient_gui_selectSpawnLocation_event_onListBoxSelectionChanged;
	}
	else
	{
		_data = _ctrl lbData _curSel;
		_num = parseNumber _data;
		_flag = myFlags select _num;
		
		markerName = format['FLAG_%1',myUID];
		deleteMarker markerName;
		createMarker [markerName,getPosATL _flag];
		ExileClientSelectedSpawnLocationMarkerName = markerName;
		
		localmarkerName = format['LOCALFLAG_%1',myUID];
		deleteMarkerLocal localmarkerName;
		_marker = createMarkerLocal [localmarkerName,getPosATL _flag];
		_marker setMarkerShapeLocal "ICON";
		_marker setMarkerTypeLocal "loc_Bunker";
		_marker setMarkerColorLocal "ColorGreen";
		_marker setMarkerTextLocal (_flag getVariable ["ExileTerritoryName", ""]);
		
		_mapControl = (findDisplay 24002) displayCtrl 24001;
		_mapControl ctrlMapAnimAdd [1, 0.1, getMarkerPos ExileClientSelectedSpawnLocationMarkerName]; 
		ctrlMapAnimCommit _mapControl;
	};
};
_listBox ctrlRemoveAllEventHandlers "LBSelChanged";
_listBox ctrlAddEventHandler ["LBSelChanged", "_this call fnc_LBSelChanged_24002;"];

fnc_ButtonClick_24003 = {
	[] call ExileClient_gui_selectSpawnLocation_event_onSpawnButtonClick;
	if(!isNil 'markerName')then
	{
		[] spawn {
			waitUntil {!isNil 'ExileClientLoadedIn'};
			uiSleep 3;
			deleteMarker markerName;
			deleteMarkerLocal localmarkerName;
		};
	};
};
_spawnButton = _display displayCtrl 24003;
_spawnButton ctrlRemoveAllEventHandlers "ButtonClick";
_spawnButton ctrlSetEventHandler["ButtonClick","call fnc_ButtonClick_24003"];
_spawnButton ctrlSetText "Let's go!";
_spawnButton ctrlEnable true;
_spawnButton ctrlCommit 0;

true