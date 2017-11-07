/**
 * ExileClient_object_player_initialize
 *
 * Exile Mod
 * www.exilemod.com
 * © 2015 Exile Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 */
 
private["_newPlayerObject","_oldPlayerObject"];
_newPlayerObject = _this;
_oldPlayerObject = player;
player reveal [_newPlayerObject, 4];
selectPlayer _newPlayerObject;
if (_oldPlayerObject isKindOf "Exile_Unit_GhostPlayer") then 
{
	deleteVehicle _oldPlayerObject;
};
//player setVariable ["ExileXM8IsOnline", (profileNamespace getVariable ["ExileEnable8GNetwork", false]), true];
player setVariable ["ExileXM8IsOnline", true, true];

// Chemlights
player setVariable ["chemlightAttached", false, false]; // Chemlight is off

player addAction ["Attach Chemlight","addons\AttachChemlight\attachChemlight.sqf",true,0,false,true,"","{_x in (magazines player)} count [ 'Chemlight_green', 'Chemlight_red', 'Chemlight_blue', 'Chemlight_yellow' ] > 0 && !(player getVariable ['chemlightAttached', true]) && (vehicle player isEqualto player) && ((daytime > 18) || (daytime < 6))"];

//player addAction ["Attach Chemlight","addons\AttachChemlight\attachChemlight.sqf",true,0,false,true,"","{_x in (magazines player)} count [ 'Chemlight_green', 'Chemlight_red', 'Chemlight_blue', 'Chemlight_yellow' ] > 0 && not (player getVariable ['chemlightAttached', true]) && not (vehicle player != player)"];

enableSentences false;
enableRadio false;
player setVariable ["BIS_noCoreConversations", true];
player disableConversation true;
player setSpeaker "NoVoice";
showSubtitles false;
[] call ExileClient_object_player_event_hook;
ExileGasMaskNextSoundAt = diag_tickTime;
if (ExileClientGasMaskVisible) then 
{
	false call ExileClient_gui_gasMask_toggle;
};
[] call ExileClient_object_player_stats_reset;
[] call ExileClient_gui_postProcessing_reset;
[] call ExileClient_system_breathing_event_onPlayerSpawned;
[] call ExileClient_system_snow_event_onPlayerSpawned;
[] call ExileClient_system_radiation_event_onPlayerSpawned;
ExileClientIsWaitingForInventoryMoneyTransaction = false;
true