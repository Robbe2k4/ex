/*
playerMarkers.sqf
*/
private["_markers","_members"];
_markers = [];
_members = [];

while {true} do {
	sleep 0.5;
	if(visibleMap) then {
		//_members = units (group player);
		_members = allPlayers;
		//Create markers
		{
			_marker = createMarkerLocal [format["%1_marker",_x],visiblePosition _x];
			if ((getPlayerUID _x) in ["76561198198312590","76561198085488659","76561198220432957","76561197972755075","76561198089653656","76561198060547790","76561197995061630","76561198130122751","76561198214378332","76561198089149482","76561198053832123","76561197971195545"]) then
				{
					_marker setMarkerColorLocal "ColorRed";
				}
				else
				{
					_marker setMarkerColorLocal "ColorBlue";
				};
			_marker setMarkerTypeLocal "cog_icon_man";
			_marker setMarkerTextLocal format["%1", _x getVariable["realname",name _x]];
			_marker setMarkerDirLocal (direction _x);
			_markers pushBack [_marker,_x];
		} foreach _members;
			
		while {visibleMap} do {
			{
				private["_marker","_unit"];
				_marker = _x select 0;
				_unit = _x select 1;
				if(!isNil "_unit") then {
					if(!isNull _unit) then {
					    _marker setMarkerPosLocal (visiblePosition _unit);
						_marker setMarkerDirLocal (direction _unit);
					};
				};
			} foreach _markers;
			if(!visibleMap) exitWith {};
			sleep 0.02;
		};

		{deleteMarkerLocal (_x select 0);} foreach _markers;
		_markers = [];
		_members = [];
	};
};