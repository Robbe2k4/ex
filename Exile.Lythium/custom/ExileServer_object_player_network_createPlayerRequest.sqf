/**
 * ExileServer_object_player_network_createPlayerRequest
 *
 * Exile Mod
 * www.exilemod.com
 * © 2015 Exile Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 */
 
private["_sessionID", "_parameters", "_requestingPlayer", "_spawnLocationMarkerName", "_playerUID", "_accountData", "_bambiPlayer", "_cargoType"];
_sessionID = _this select 0;
_parameters = _this select 1;
_requestingPlayer = _sessionID call ExileServer_system_session_getPlayerObject;
try
{
	if (isNull _requestingPlayer) then 
	{
		throw format ["Session %1 requested a bambi character, but doesn't have a player object. Hacker or Monday?", _sessionID];
	};
	_spawnLocationMarkerName = _parameters select 0;
	_playerUID = getPlayerUID _requestingPlayer;
	if(_playerUID isEqualTo "")then
	{
		throw format ["Player: '%1' has no player UID. Arma/Steam sucks!.",name _requestingPlayer];
	};
	_accountData = format["getAccountStats:%1", _playerUID] call ExileServer_system_database_query_selectSingle;
	_bambiPlayer = (createGroup independent) createUnit ["Exile_Unit_Player", [0,0,0], [], 0, "CAN_COLLIDE"];

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

	removeHeadgear _bambiPlayer;
	{
		_cargoType = _x call ExileClient_util_cargo_getType;
		switch (_cargoType) do
		{
			case 1: 	{ _bambiPlayer addItem _x; };
			case 2: 	{ _bambiPlayer addWeaponGlobal _x; };
			case 3: 	{ _bambiPlayer addBackpackGlobal _x; };
			case 4:		{ _bambiPlayer linkItem _x; };
			default 	{ _bambiPlayer addItem _x; };
		};
	}
	forEach getArray(configFile >> "CfgSettings" >> "BambiSettings" >> "loadOut");
	[_sessionID, _requestingPlayer, _spawnLocationMarkerName, _bambiPlayer, _accountData] call ExileServer_object_player_createBambi;
}
catch
{
	_exception call ExileServer_util_log;
};