// Code needed to make "playsound3D" triggered sounds work
// Thanks to KillZoneKid
MISSION_ROOT = call {
    private "_arr";
    _arr = toArray __FILE__;
    _arr resize (count _arr - 8);
    toString _arr
};

execVM "R3F_LOG\init.sqf";
SA_TOW_IN_EXILE_SAFEZONE_ENABLED = true;
ASL_EXILE_SAFEZONE_ENABLED = true;
ExileClientXM8IsPowerOn = true;

[] execVM "custom\RemoveMapObjects\rmo.sqf"; // Script for removing/hiding specific map objects
[] execVM "custom\money\takegive_poptab_init.sqf";
[] execVM "addons\statusBar\statusBar.sqf";
[] execVM "addons\playerMarkers.sqf";
[] execVM "addons\EnigmaRevive\init.sqf";
[] execVM "addons\ClaimVehicles_Client\ClaimVehicles_Client_init.sqf";
Kuplion_fnc_salvageMetal = compileFinal preprocessFileLineNumbers "addons\SalvageMetal\Kuplion_fnc_salvageMetal.sqf";

if(hasInterface) then
{
	[] ExecVM "VEMFr_client\sqf\initClient.sqf"; // Client-side part of VEMFr
	[] execVM "custom\service\service_point.sqf";
};

[] spawn {
	waitUntil{sleep 1;getClientStateNumber >= 10 && !isNull findDisplay 46};
	sleep 3;

#include "A3XAI_Client\A3XAI_initclient.sqf";