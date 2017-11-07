/*
    Original HALV_takegive_crypto.sqf by Halv
    Copyright (C) 2015  Halvhjearne > README.md
    Edit to takegive_poptab.sqf for Exile by Dodo
*/

 _player = _this select 0;
_costs = _this select 1;

_playerMoney = _player getVariable ["ExileMoney", 0];
diag_log format["[HALV_takegive] Event player is %1 money before is %2 costs is %3",_player, _playerMoney, _costs];
_playerMoney = _playerMoney - _costs;
_player setVariable ["ExileMoney", _playerMoney, true];
diag_log format["[HALV_takegive] Event player is %1 money after is %2 costs is %3",_player, _playerMoney, _costs];
format["setPlayerMoney:%1:%2", _playerMoney, _player getVariable ["ExileDatabaseID", 0]] call ExileServer_system_database_query_fireAndForget;
//[_player, "purchaseVehicleSkinResponse", [0, str _playerMoney]] call ExileServer_system_network_send_to;
[_player, "toastRequest", ["SuccessTitleAndText", ["Service Point Info", "Removed poptabs for your purchase"]]] call ExileServer_system_network_send_to;
true
