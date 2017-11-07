/**
 * ExileClient_util_world_canBuildHere
 *
 * Exile Mod
 * www.exilemod.com
 * © 2015 Exile Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 */
 
private["_constructionConfigName", "_position", "_playerUID", "_result", "_requiresTerritory", "_canBePlacedOnRoad", "_allowDuplicateSnap", "_minimumDistanceToTraderZones", "_minimumDistanceToSpawnZones", "_minimumDistanceToOtherTerritories", "_maximumTerritoryRadius", "_positionObject", "_nearestFlags", "_radius", "_buildRights", "_territoryLevelConfigs", "_territoryLevelConfig", "_numberOfConstructionsAllowed"];
_constructionConfigName = _this select 0;
_position = _this select 1;
_playerUID = _this select 2;
_result = 0;
_requiresTerritory = getNumber (configFile >> "CfgConstruction" >> _constructionConfigName >> "requiresTerritory") isEqualTo 1;
_canBePlacedOnRoad = getNumber (configFile >> "CfgConstruction" >> _constructionConfigName >> "canBePlacedOnRoad") isEqualTo 1;
_allowDuplicateSnap = getNumber (configFile >> "CfgConstruction" >> _constructionConfigName >> "allowDuplicateSnap") isEqualTo 1;
_minimumDistanceToTraderZones = getNumber (missionConfigFile >> "CfgTerritories" >> "minimumDistanceToTraderZones");
_minimumDistanceToSpawnZones = getNumber (missionConfigFile >> "CfgTerritories" >> "minimumDistanceToSpawnZones");
_minimumDistanceToOtherTerritories = getNumber (missionConfigFile >> "CfgTerritories" >> "minimumDistanceToOtherTerritories");
_maximumTerritoryRadius = getNumber (missionConfigFile >> "CfgTerritories" >> "maximumRadius");
try 
{
	if ([_position, _minimumDistanceToTraderZones] call ExileClient_util_world_isTraderZoneInRange) then
	{
		throw 4;
	};
	if ([_position, _minimumDistanceToSpawnZones] call ExileClient_util_world_isSpawnZoneInRange) then
	{
		throw 5;
	};
	if ((AGLtoASL _position) call ExileClient_util_world_isInConcreteMixerZone) then 
	{
		throw 11;
	};
	if ((AGLtoASL _position) call ExileClient_util_world_isInNonConstructionZone) then 
	{
		throw 10;
	};
	if ((AGLtoASL _position) call ExileClient_util_world_isInRadiatedZone) then
	{
		throw 8;
	};
	if !(_canBePlacedOnRoad) then
	{
		if (isOnRoad [_position select 0, _position select 1, 0]) then
		{
			throw 3;
		};
	};
	if !(_allowDuplicateSnap) then 
	{
		{
			_positionObject = (ASLtoAGL (getPosASL _x));
			if (_position isEqualTo _positionObject) then
			{
				throw 7;
			};
		} 
		forEach (_position nearObjects ["Exile_Construction_Abstract_Static", 3]);
	};
	if (_constructionConfigName isEqualTo "Flag") then 
	{
		if ([_position, _minimumDistanceToOtherTerritories] call ExileClient_util_world_isTerritoryInRange) then
		{
			throw 2; 
		};
	}
	else 
	{
		_nearestFlags = (nearestObjects [_position, ["Exile_Construction_Flag_Static"], _maximumTerritoryRadius]);
		if !(_nearestFlags isEqualTo []) then
		{
			{
				_radius = _x getVariable ["ExileTerritorySize", -1];
				if (((AGLtoASL _position) distance (getPosASL _x)) < _radius) then
				{
					_buildRights = _x getVariable ["ExileTerritoryBuildRights", []];
					if (_playerUID in _buildRights) then
					{
						_territoryLevelConfigs = getArray (missionConfigFile >> "CfgTerritories" >> "prices");
						_territoryLevelConfig = _territoryLevelConfigs select ((_x getVariable ["ExileTerritoryLevel", 0]) - 1);
						_numberOfConstructionsAllowed = _territoryLevelConfig select 2;
						if ((_x getVariable ["ExileFlagStolen", 0]) isEqualTo 1) then
						{
							throw 9;
						};
						
						if ((_x getVariable ["ExileTerritoryNumberOfConstructions", 0]) >= _numberOfConstructionsAllowed) then
						{
							throw 6; 
						};
						if (_constructionConfigName isEqualTo "Safe") then{
							_numberOfSafesAllowed = _territoryLevelConfig select 3;
							_nearestSafe = (nearestObjects [(getPosASL _x), ["Exile_Container_Safe"], _maximumTerritoryRadius]);
							if ( ( count _nearestSafe) >= _numberOfSafesAllowed) then
							{
								throw 100; 
							};
						};
						if (_constructionConfigName isEqualTo "StorageCrate") then{
							_numberOfStorageCratesAllowed = _territoryLevelConfig select 5;
							_nearestStorageCrates = (nearestObjects [(getPosASL _x), ["Exile_Container_StorageCrate"], _maximumTerritoryRadius]);
							if ( ( count _nearestStorageCrates) >= _numberOfStorageCratesAllowed) then
							{
								throw 101;
							};
						};
						if (_constructionConfigName isEqualTo "CamoTent") then{
							_numberOfCamoTentsAllowed = _territoryLevelConfig select 6;
							_nearestCamoTents = (nearestObjects [(getPosASL _x), ["Exile_Container_CamoTent"], _maximumTerritoryRadius]);
							if ( ( count _nearestCamoTents) >= _numberOfCamoTentsAllowed) then
							{
							throw 102;
							};
						};
						if (_constructionConfigName isEqualTo "Land_Pallet_MilBoxes_F_Construction") then{
							_numberOfMilBoxAllowed = _territoryLevelConfig select 7;
							_nearestMilBox = (nearestObjects [(getPosASL _x), ["Land_Pallet_MilBoxes_F"], _maximumTerritoryRadius]);
							if ( ( count _nearestMilBox) >= _numberOfMilBoxAllowed) then
							{
							throw 103;
							};
						};
						if (_constructionConfigName isEqualTo "Land_CargoBox_V1_F_Construction") then{
							_numberOfCargoBoxV1Allowed = _territoryLevelConfig select 8;
							_nearestCargoBoxV1 = (nearestObjects [(getPosASL _x), ["Land_CargoBox_V1_F"], _maximumTerritoryRadius]);
							if ( ( count _nearestCargoBoxV1) >= _numberOfCargoBoxV1Allowed) then
							{
							throw 104;
							};
						};
						if (_constructionConfigName isEqualTo "Land_Cargo20_sand_F_Construction") then{
							_numberOfCargo20SandAllowed = _territoryLevelConfig select 9;
							_nearestCargo20Sand = (nearestObjects [(getPosASL _x), ["Land_Cargo20_sand_F"], _maximumTerritoryRadius]);
							if ( ( count _nearestCargo20Sand) >= _numberOfCargo20SandAllowed) then
							{
							throw 105;
							};
						};
						if (_constructionConfigName isEqualTo "Land_Cargo20_military_green_F_Construction") then{
							_numberOfCargo20MilAllowed = _territoryLevelConfig select 10;
							_nearestCargo20Mil = (nearestObjects [(getPosASL _x), ["Land_Cargo20_military_green_F"], _maximumTerritoryRadius]);
							if ( ( count _nearestCargo20Mil) >= _numberOfCargo20MilAllowed) then
							{
							throw 106;
							};
						};
						if (_constructionConfigName isEqualTo "Land_Cargo40_light_green_F_Construction") then{
							_numberOfCargo40Allowed = _territoryLevelConfig select 11;
							_nearestCargo40 = (nearestObjects [(getPosASL _x), ["Land_Cargo40_light_green_F"], _maximumTerritoryRadius]);
							if ( ( count _nearestCargo40) >= _numberOfCargo40Allowed) then
							{
							throw 107;
							};
						};
						throw 0;
					};
				};
				throw 2;
			}
			forEach _nearestFlags; 
		};
		if (_requiresTerritory) then 
		{
			throw 1;	
		};
	};
}
catch 
{
	_result = _exception;
};
_result