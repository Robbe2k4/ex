/**
 * ExileServer_object_vehicle_event_onMPKilled
 *
 * Exile Mod
 * www.exilemod.com
 * © 2015 Exile Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 */
 
private["_vehicleObject"];
if !(isServer) exitWith {true};

params['_unit','_killer','_instigator'];

_killerName = if(alive _killer)then{_killer setVariable['ExileName',name _killer];name _killer}else{_killer getVariable['ExileName','']};
_killerUID = _killer getVariable ['ExileOwnerUID',getPlayerUID _killer];

_log = format['%1 @%2 killed by %3(%4) %5',
	typeOf _unit,
	getPos _unit,
	_killerName,
	_killerUID,
	typeOf _killer
];

_vehicleObject = _this select 0;
{
	moveout _x;
}forEach (crew _vehicleObject);

_vehicleObject call ExileServer_object_vehicle_remove;
_vehicleObject setVariable ["ExileDiedAt", time];

['VEHICLE_DESTROYED',_log] call FNC_A3_CUSTOMLOG;

true