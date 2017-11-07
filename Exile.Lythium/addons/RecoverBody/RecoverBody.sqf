/*
 *
 * Thanks to NoRulez for this neat little script
 * Recover your body from a wrecked vehicle
 *
 */

private ["_recover"];
player playMove "AinvPknlMstpSnonWnonDr_medic1";
sleep 10;
deleteVehicle (_this select 0);