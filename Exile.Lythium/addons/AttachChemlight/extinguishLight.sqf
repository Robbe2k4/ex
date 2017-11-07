_extinguish = _this select 2;
_chemlight = _this select 3;

player playMove "AinvPknlMstpSnonWnonDr_medic3";

sleep 5;

deleteVehicle _chemlight;
player removeAction _extinguish;

player setVariable ["chemlightAttached", false, false]; // Chemlight is off