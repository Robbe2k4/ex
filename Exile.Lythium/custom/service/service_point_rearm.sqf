// Vehicle Service Point (Rearm) by Axe Cop
//reworked for a3 epoch by Halv
//reworked for a3 exile by Dodo
 
private ["_vehicle","_args","_servicePoint","_costs","_magazineCount","_weapon","_type","_name","_weaponType","_weaponName","_turret","_magazines","_ammo","_exilew","_veh"];
 
_vehicle = _this select 0;
_args = _this select 3;
_servicePoint = _args select 0;
_costs = _args select 1;
_weapon = _args select 2;
_type = typeOf _vehicle;
_name = getText(configFile >> "cfgVehicles" >> _type >> "displayName");
_weaponName = _weapon select 0;
_ammoClass = _weapon select 1;
_ammoName = _weapon select 2;
_ammoMAX = _weapon select 3;
_ammoMIN = _weapon select 4;
_turret = _weapon select 5;
_exilew =  (player getVariable ["ExileMoney", 0]);
_veh = vehicle player; 

if (!local _vehicle) exitWith {cutText [format["%2 is not local to %1 - Re-Arm Denied!",name player, _name], "PLAIN DOWN"]; diag_log format["Error: called service_point_rearm.sqf with non-local vehicle: %1", _vehicle] };
//if(count (crew _vehicle) > 1) exitWith {cutText ["All Passengers Must Exit Vehicle - Re-Arm Denied!", "PLAIN DOWN"];};
//if(!(_veh isEqualTo player) && {(driver _veh) isEqualTo player}) exitWith {cutText ["You must be in the Gunner's seat - Re-Arm Denied!", "PLAIN DOWN"];};
if (_exilew < _costs) exitWith {['ErrorTitleAndText',[format['You need %1 Pop-Tabs to re-arm your %2', _costs,_name]]] call ExileClient_gui_toaster_addTemplateToast;};
_currentmags = magazines _vehicle;
_magscount = count _currentmags;
_ammocount = {_ammoClass == _x}count _currentmags;
if(_magscount > _ammoMAX)exitWith{cutText [format["You already have %1 magazine(s) in the %2",_magscount,_weaponName], "PLAIN DOWN"];};
if(_ammocount > _ammoMIN)exitWith{cutText [format["You already have %1 magazine(s) of %2 in the %3\nTotal of %4 magazine(s)",_ammocount,_ammoName,_weaponName,_magscount], "PLAIN DOWN"];};
 
if(_costs > 0 && isTradeEnabled)then{
        takegive_poptab = [player,_costs,true];
        publicVariableServer "takegive_poptab";
};
 
// add a magazines
_vehicle addMagazineTurret [_ammoClass, _turret];
 
cutText [format["%1 of your %2 rearmed with another magazine", _weaponName, _name], "PLAIN DOWN"];
