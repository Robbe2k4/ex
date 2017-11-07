/**
 * ExileServer_object_player_createBambi
 *
 * Exile Mod
 * www.exilemod.com
 * © 2015 Exile Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 */
 
private["_sessionID", "_requestingPlayer", "_spawnLocationMarkerName", "_bambiPlayer", "_accountData", "_direction", "_position", "_spawnAreaPosition", "_spawnAreaRadius", "_clanID", "_clanData", "_clanGroup", "_player", "_devFriendlyMode", "_devs", "_parachuteNetID", "_spawnType", "_parachuteObject"];
_sessionID = _this select 0;
_requestingPlayer = _this select 1;
_spawnLocationMarkerName = _this select 2;
_bambiPlayer = _this select 3;
_accountData = _this select 4;
_direction = random 360;
if ((count ExileSpawnZoneMarkerPositions) isEqualTo 0) then 
{
	_position = call ExileClient_util_world_findCoastPosition;
	if ((toLower worldName) isEqualTo "namalsk") then 
	{
		while {(_position distance2D [76.4239, 107.141, 0]) < 100} do 
		{
			_position = call ExileClient_util_world_findCoastPosition;
		};
	};
}
else 
{
	_spawnAreaPosition = getMarkerPos _spawnLocationMarkerName;
	_spawnAreaRadius = getNumber(configFile >> "CfgSettings" >> "BambiSettings" >> "spawnZoneRadius");
	_position = [_spawnAreaPosition, _spawnAreaRadius] call ExileClient_util_math_getRandomPositionInCircle;
	while {surfaceIsWater _position} do 
	{
		_position = [_spawnAreaPosition, _spawnAreaRadius] call ExileClient_util_math_getRandomPositionInCircle;
	};
};
_name = name _requestingPlayer;
_clanID = (_accountData select 3);
if !((typeName _clanID) isEqualTo "SCALAR") then
{
	_clanID = -1;
	_clanData = [];
}
else
{
	_clanData = missionNamespace getVariable [format ["ExileServer_clan_%1",_clanID],[]];
	if(isNull (_clanData select 5))then
	{
		_clanGroup = createGroup independent;
		_clanData set [5,_clanGroup];
		_clanGroup setGroupIdGlobal [_clanData select 0];
		missionNameSpace setVariable [format ["ExileServer_clan_%1",_clanID],_clanData];
	}
	else
	{
		_clanGroup = (_clanData select 5);
	};
	[_player] joinSilent _clanGroup;
};
_bambiPlayer setPosATL [_position select 0,_position select 1,0];
_bambiPlayer disableAI "FSM";
_bambiPlayer disableAI "MOVE";
_bambiPlayer disableAI "AUTOTARGET";
_bambiPlayer disableAI "TARGET";
_bambiPlayer disableAI "CHECKVISIBLE";
_bambiPlayer setDir _direction;
_bambiPlayer setName _name;
_bambiPlayer setVariable ["ExileMoney", 0, true]; 
_bambiPlayer setVariable ["ExileScore", (_accountData select 0)];
_bambiPlayer setVariable ["ExileKills", (_accountData select 1)];
_bambiPlayer setVariable ["ExileDeaths", (_accountData select 2)];
_bambiPlayer setVariable ["ExileClanID", _clanID];
_bambiPlayer setVariable ["ExileClanData", _clanData];
_bambiPlayer setVariable ["ExileHunger", 100];
_bambiPlayer setVariable ["ExileThirst", 100];
_bambiPlayer setVariable ["ExileTemperature", 37];
_bambiPlayer setVariable ["ExileWetness", 0];
_bambiPlayer setVariable ["ExileAlcohol", 0]; 
_bambiPlayer setVariable ["ExileName", _name]; 
_bambiPlayer setVariable ["ExileOwnerUID", getPlayerUID _requestingPlayer]; 
_bambiPlayer setVariable ["ExileIsBambi", true];
_bambiPlayer setVariable ["ExileXM8IsOnline", true, true];
_bambiPlayer setVariable ["ExileLocker", (_accountData select 4), true];
_bambiPlayer setUnitTrait ["UAVHacker" ,true];
_devFriendlyMode = getNumber (configFile >> "CfgSettings" >> "ServerSettings" >> "devFriendyMode");
if (_devFriendlyMode isEqualTo 1) then 
{
	_devs = getArray (configFile >> "CfgSettings" >> "ServerSettings" >> "devs");
	{
		if ((getPlayerUID _requestingPlayer) isEqualTo (_x select 0))exitWith 
		{
			if ((name _requestingPlayer) isEqualTo (_x select 1))then
			{
				_bambiPlayer setVariable ["ExileMoney", 500000, true];
				_bambiPlayer setVariable ["ExileScore", 100000];
			};
		};
	}
	forEach _devs;
};
_parachuteNetID = "";
if ((getNumber(configFile >> "CfgSettings" >> "BambiSettings" >> "parachuteSpawning")) isEqualTo 1) then
{
	_position set [2, getNumber(configFile >> "CfgSettings" >> "BambiSettings" >> "parachuteDropHeight")]; 
	if ((getNumber(configFile >> "CfgSettings" >> "BambiSettings" >> "haloJump")) isEqualTo 1) then
	{
		_bambiPlayer addBackpackGlobal "B_Parachute";
		_bambiPlayer setPosATL _position;
		_spawnType = 2;
	}
	else 
	{
		_parachuteObject = createVehicle ["Steerable_Parachute_F", _position, [], 0, "CAN_COLLIDE"];
		_parachuteObject setDir _direction;
		_parachuteObject setPosATL _position;
		_parachuteObject enableSimulationGlobal true;
		_parachuteNetID = netId _parachuteObject;
		_spawnType = 1;
	};
}
else
{
	_spawnType = 0;
};

//BEGIN CODE FOR RESPECT BASED LOADOUTS

_respect = (_accountData select 0);

switch (true) do {

	case (_respect < 49999) :	//LEVEL 0
	{
		clearWeaponCargo _bambiPlayer;
		clearMagazineCargo _bambiPlayer;
		_bambiPlayer forceAddUniform "U_BG_Guerilla3_1";
		_bambiPlayer addHeadgear "H_Cap_blk";
		_bambiPlayer addWeapon 'Exile_Item_XM8';
		_bambiPlayer addWeapon "ItemCompass";
		_bambiPlayer addWeapon "ItemMap";
		_bambiPlayer addWeapon "ItemRadio";
		_bambiPlayer addItemToUniform "Exile_Item_EMRE";
		_bambiPlayer addItemToUniform "Exile_Item_PlasticBottleFreshWater";
		_bambiPlayer addItemToUniform "Exile_Item_LightBulb";
		_bambiPlayer addItemToUniform "Chemlight_yellow";
		cutText ["Basic Loadout Added","PLAIN DOWN"];
	};

	case (_respect > 49999 && _respect < 150000) :	//LEVEL 1
	{
		clearWeaponCargo _bambiPlayer;
		clearMagazineCargo _bambiPlayer;
		_bambiPlayer forceAddUniform "U_C_Poloshirt_redwhite";
		_bambiPlayer addVest "V_BandollierB_rgr";
		//_bambiPlayer addBackpack "B_Kitbag_rgr";
		_bambiPlayer addHeadgear "Exile_Headgear_SantaHat";
		//_bambiPlayer addWeapon "NVGoggles_OPFOR";
		_bambiPlayer addWeapon "Binocular";
		_bambiPlayer addWeapon "ItemGPS";
		_bambiPlayer addWeapon 'Exile_Item_XM8';
		_bambiPlayer addWeapon "ItemCompass";
		_bambiPlayer addWeapon "ItemMap";
		_bambiPlayer addWeapon "ItemRadio";
		_bambiPlayer addMagazines ["Exile_Magazine_6Rnd_45ACP", 3];  
		_bambiPlayer addWeapon "Exile_Weapon_TaurusGold";
		//_bambiPlayer addHandgunItem "muzzle_snds_L";
		_bambiPlayer addMagazines ["30Rnd_9x21_Red_Mag", 3];
		_bambiPlayer addWeapon "hgun_PDW2000_F";
		_bambiPlayer addPrimaryWeaponItem "optic_Aco";
		//_bambiPlayer addPrimaryWeaponItem "muzzle_snds_L";
		_bambiPlayer addItemToVest "Exile_Item_CanOpener";
		_bambiPlayer addItemToVest "Exile_Item_Dogfood";
		_bambiPlayer addItemToVest "Exile_Item_PlasticBottleFreshWater";
		_bambiPlayer addItemToVest "Exile_Item_LightBulb";
		_bambiPlayer addItemToVest "Exile_Item_Vishpirin";
		cutText ["50k Respect Loadout Added","PLAIN DOWN"];
	};

	case (_respect > 149999 && _respect < 250000) :	//LEVEL 2
	{
		clearWeaponCargo _bambiPlayer;
		clearMagazineCargo _bambiPlayer;
		_bambiPlayer forceAddUniform "U_Marshal";
		_bambiPlayer addVest "V_TacVest_blk_POLICE";
		//_bambiPlayer addBackpack "B_Kitbag_rgr";
		_bambiPlayer addHeadgear "H_Cap_police";
		_bambiPlayer addWeapon "NVGoggles_OPFOR";
		_bambiPlayer addWeapon "Binocular";
		_bambiPlayer addWeapon "ItemGPS";
		_bambiPlayer addWeapon 'Exile_Item_XM8';
		_bambiPlayer addWeapon "ItemCompass";
		_bambiPlayer addWeapon "ItemMap";
		_bambiPlayer addWeapon "ItemRadio";
		_bambiPlayer addMagazines ["16Rnd_9x21_red_Mag", 3];  
		_bambiPlayer addWeapon "hgun_Rook40_F";
		//_bambiPlayer addHandgunItem "muzzle_snds_L";
		_bambiPlayer addMagazines ["30Rnd_45ACP_Mag_SMG_01_Tracer_Red", 3];
		_bambiPlayer addWeapon "SMG_01_F";
		_bambiPlayer addPrimaryWeaponItem "optic_Aco";
		//_bambiPlayer addPrimaryWeaponItem "muzzle_snds_acp";
		_bambiPlayer addItemToVest "Exile_Item_CanOpener";
		_bambiPlayer addItemToVest "Exile_Item_Dogfood";
		_bambiPlayer addItemToVest "Exile_Item_PlasticBottleFreshWater";
		_bambiPlayer addItemToVest "Exile_Item_LightBulb";
		_bambiPlayer addItemToVest "Exile_Item_Vishpirin";
		cutText ["150k Respect Loadout Added","PLAIN DOWN"];
	};

	case (_respect > 249999 && _respect < 350000) :	//LEVEL 3
	{
		clearWeaponCargo _bambiPlayer;
		clearMagazineCargo _bambiPlayer;
		_bambiPlayer forceAddUniform "U_IG_Guerilla2_3";
		_bambiPlayer addVest "V_TacVest_oli";
		//_bambiPlayer addBackpack "B_Kitbag_rgr";
		_bambiPlayer addHeadgear "H_Watchcap_camo";
		_bambiPlayer addWeapon "NVGoggles_INDEP";
		_bambiPlayer addWeapon "Binocular";
		_bambiPlayer addWeapon "ItemGPS";
		_bambiPlayer addWeapon 'Exile_Item_XM8';
		_bambiPlayer addWeapon "ItemCompass";
		_bambiPlayer addWeapon "ItemMap";
		_bambiPlayer addWeapon "ItemRadio";
		_bambiPlayer addMagazines ["16Rnd_9x21_red_Mag", 3];  
		_bambiPlayer addWeapon "hgun_Rook40_F";
		_bambiPlayer addHandgunItem "muzzle_snds_L";
		_bambiPlayer addMagazines ["30Rnd_556x45_Stanag_Tracer_Red", 3];
		_bambiPlayer addWeapon "arifle_TRG21_F";
		_bambiPlayer addPrimaryWeaponItem "optic_Holosight";
		_bambiPlayer addPrimaryWeaponItem "muzzle_snds_M";
		_bambiPlayer addItemToVest "Exile_Item_CanOpener";
		_bambiPlayer addItemToVest "Exile_Item_Dogfood";
		_bambiPlayer addItemToVest "Exile_Item_PlasticBottleFreshWater";
		_bambiPlayer addItemToVest "Exile_Item_LightBulb";
		_bambiPlayer addItemToVest "Exile_Item_Vishpirin";
		cutText ["250k Respect Loadout Added","PLAIN DOWN"];
	}; 

	case (_respect > 349999 && _respect < 450000) :	//LEVEL 4
	{
		clearWeaponCargo _bambiPlayer;
		clearMagazineCargo _bambiPlayer;
		_bambiPlayer forceAddUniform "U_B_CTRG_3";
		_bambiPlayer addVest "V_TacVest_oli";
		//_bambiPlayer addBackpack "B_Kitbag_rgr";
		_bambiPlayer addHeadgear "H_Booniehat_khk";
		_bambiPlayer addWeapon "NVGoggles_OPFOR";
		_bambiPlayer addWeapon "Binocular";
		_bambiPlayer addWeapon "ItemGPS";
		_bambiPlayer addWeapon 'Exile_Item_XM8';
		_bambiPlayer addWeapon "ItemCompass";
		_bambiPlayer addWeapon "ItemMap";
		_bambiPlayer addWeapon "ItemRadio";
		_bambiPlayer addMagazines ["30Rnd_9x21_Mag", 3];  
		_bambiPlayer addWeapon "hgun_Rook40_F";
		_bambiPlayer addHandgunItem "muzzle_snds_L";
		_bambiPlayer addMagazines ["30Rnd_65x39_caseless_mag_Tracer", 3];
		_bambiPlayer addWeapon "arifle_MX_Black_F";
		_bambiPlayer addPrimaryWeaponItem "optic_MRCO";
		_bambiPlayer addPrimaryWeaponItem "muzzle_snds_H";
		_bambiPlayer addItemToVest "Exile_Item_CanOpener";
		_bambiPlayer addItemToVest "Exile_Item_DogFood_Cooked";
		_bambiPlayer addItemToVest "Exile_Item_PowerDrink";
		_bambiPlayer addItemToVest "Exile_Item_LightBulb";
		_bambiPlayer addItemToVest "Exile_Item_InstaDoc";
		cutText ["350k Respect Loadout Added","PLAIN DOWN"];
	}; 

	case (_respect > 449999 && _respect < 550000) :	//LEVEL 5
	{
		clearWeaponCargo _bambiPlayer;
		clearMagazineCargo _bambiPlayer;
		_bambiPlayer forceAddUniform "Exile_Uniform_Woodland";
		_bambiPlayer addVest "V_PlateCarrierL_CTRG";
		//_bambiPlayer addBackpack "B_Kitbag_rgr";
		_bambiPlayer addHeadgear "H_HelmetSpecB";
		_bambiPlayer addWeapon "NVGoggles_OPFOR";
		_bambiPlayer addWeapon "Rangefinder";
		_bambiPlayer addWeapon "ItemGPS";
		_bambiPlayer addWeapon 'Exile_Item_XM8';
		_bambiPlayer addWeapon "ItemCompass";
		_bambiPlayer addWeapon "ItemMap";
		_bambiPlayer addWeapon "ItemRadio";
		_bambiPlayer addMagazines ["11Rnd_45ACP_Mag", 3];  
		_bambiPlayer addWeapon "hgun_Pistol_heavy_01_F";
		_bambiPlayer addHandgunItem "muzzle_snds_acp";
		_bambiPlayer addMagazines ["200Rnd_65x39_cased_Box_Tracer", 2];
		_bambiPlayer addWeapon "LMG_Mk200_F";
		_bambiPlayer addPrimaryWeaponItem "optic_Hamr";
		_bambiPlayer addPrimaryWeaponItem "muzzle_snds_H";
		_bambiPlayer addItemToUniform "Exile_Item_CanOpener";
		_bambiPlayer addItemToVest "Exile_Item_DogFood_Cooked";
		_bambiPlayer addItemToVest "Exile_Item_DogFood_Cooked";
		_bambiPlayer addItemToVest "Exile_Item_PowerDrink";
		_bambiPlayer addItemToVest "Exile_Item_PowerDrink";
		_bambiPlayer addItemToVest "Exile_Item_LightBulb";
		_bambiPlayer addItemToVest "Exile_Item_Rope";
		_bambiPlayer addItemToVest "Exile_Item_DuctTape";
		_bambiPlayer addItemToVest "Exile_Item_InstaDoc";
		_bambiPlayer addItemToVest "Exile_Item_InstaDoc";
		cutText ["450k Respect Loadout Added","PLAIN DOWN"];
	};

	case (_respect > 549999) :	//LEVEL 6
	{
		clearWeaponCargo _bambiPlayer;
		clearMagazineCargo _bambiPlayer;
		_bambiPlayer forceAddUniform "U_O_FullGhillie_lsh";
		_bambiPlayer addVest "V_PlateCarrierGL_rgr";
		//_bambiPlayer addBackpack "B_Kitbag_rgr";
		_bambiPlayer addHeadgear "H_HelmetLeaderO_ocamo";
		_bambiPlayer addWeapon "NVGoggles_INDEP";
		_bambiPlayer addWeapon "Rangefinder";
		_bambiPlayer addWeapon "ItemGPS";
		_bambiPlayer addWeapon 'Exile_Item_XM8';
		_bambiPlayer addWeapon "ItemCompass";
		_bambiPlayer addWeapon "ItemMap";
		_bambiPlayer addWeapon "ItemRadio";
		_bambiPlayer addMagazines ["11Rnd_45ACP_Mag", 3];  
		_bambiPlayer addWeapon "hgun_Pistol_heavy_01_F";
		_bambiPlayer addHandgunItem "optic_MRD";
		_bambiPlayer addHandgunItem "muzzle_snds_acp";
		_bambiPlayer addMagazines ["Exile_Magazine_20Rnd_762x51_DMR_Red", 5];
		_bambiPlayer addWeapon "Exile_Weapon_DMR";
		_bambiPlayer addPrimaryWeaponItem "optic_Nightstalker";
		//_bambiPlayer addPrimaryWeaponItem "hlc_muzzle_300blk_KAC";
		_bambiPlayer addItemToUniform "Exile_Item_CanOpener";
		_bambiPlayer addItemToUniform "Exile_Item_DogFood_Cooked";
		_bambiPlayer addItemToUniform "Exile_Item_DogFood_Cooked";
		_bambiPlayer addItemToVest "Exile_Item_PowerDrink";
		_bambiPlayer addItemToVest "Exile_Item_PowerDrink";
		_bambiPlayer addItemToVest "Exile_Item_Rope";
		_bambiPlayer addItemToVest "Exile_Item_DuctTape";
		_bambiPlayer addItemToVest "Exile_Item_LightBulb";
		_bambiPlayer addItemToVest "Exile_Item_InstaDoc";
		_bambiPlayer addItemToVest "Exile_Item_InstaDoc";
		_bambiPlayer addItemToVest "HandGrenade";
		_bambiPlayer addItemToVest "HandGrenade";
		_bambiPlayer addItemToVest "HandGrenade";
		cutText ["550k Respect Loadout Added","PLAIN DOWN"];
	}; 

	default {
	};
};

//END CODE FOR RESPECT BASED LOADOUTS

_bambiPlayer addMPEventHandler ["MPKilled", {_this call ExileServer_object_player_event_onMpKilled}];
_bambiPlayer call ExileServer_object_player_database_insert;
_bambiPlayer call ExileServer_object_player_database_update;
[
	_sessionID, 
	"createPlayerResponse", 
	[
		_bambiPlayer, 
		_parachuteNetID, 
		str (_accountData select 0),
		(_accountData select 1),
		(_accountData select 2),
		100,
		100,
		0,
		(getNumber (configFile >> "CfgSettings" >> "BambiSettings" >> "protectionDuration")) * 60, 
		_clanData,
		_spawnType
	]
] 
call ExileServer_system_network_send_to;
[_sessionID, _bambiPlayer] call ExileServer_system_session_update;
true