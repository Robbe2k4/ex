// Vehicle Service Point by Axe Cop
//reworked for a3 epoch by Halv
//reworked for a3 exile by Dodo
 
private ["_refuel_enable","_refuel_costs","_refuel_updateInterval","_refuel_amount","_folder","_servicePointClasses","_maxDistance","_costsFree","_message","_messageShown","_repair_enable","_repair_costs","_repair_repairTime","_rearm_enable","_rearm_costs","_lastVehicle","_lastRole","_fnc_removeActions","_fnc_getCosts","_fnc_actionTitle","_fnc_getWeapons"];
 
//====================== general settings
_folder = "custom\service\"; // folder where the service point scripts are saved, relative to the mission file
_servicePointClasses = ["Land_FuelStation_Feed_F","Land_FuelStation_Shed_F","CargoNet_01_barrels_F","Land_A_FuelStation_Feed","Land_A_FuelStation_Build","Land_CarService_F","Land_fs_roof_F","Land_fs_feed_F","Land_FuelStation_01_pump_F","Land_FuelStation_02_pump_F","Land_FuelStation_02_workshop_F","Land_FuelStation_01_workshop_F","Land_Jbad_Ind_FuelStation_Feed"]; // service point classes (can be house, vehicle and unit classes)
_maxDistance = 15; // maximum distance from a service point for the options to be shown
_costsFree = "free"; // text for no costs
_message = "Welcome to Vehicle Service Point"; // message to be shown when in range of a service point (set to "" to disable)
_actionColour = "#FFB00C"; //the colour of the scroll action Blue: "#0096ff"
 
//====================== repair settings
_repair_enable = true; // enable or disable the repair option
_repair_repairTime = 2; // time needed to repair each damaged part (in seconds)
 
_repair_costs = [  //Need Money
        ["Air",300],
        ["AllVehicles",300]
];
 
//====================== refuel settings
_refuel_enable = true; // enable or disable the refuel option
_refuel_costs = [
    ["Air",0],
    ["AllVehicles",0]
]; // free for all vehicles (equal to [["AllVehicles",[]]])
_refuel_updateInterval = 0.2; // update interval (in seconds)
_refuel_amount = 0.05; // amount of fuel to add with every update (in percent)
 
//====================== rearm settings
_rearm_enable = true; // enable or disable the rearm option
 
//deny re-arm if more than this amount of current weapons magazines already in the vehicle
_deny_already_armed_with = 4;
//deny re-arm if more than this amount of magazines already in the vehicle
_GlobalMagazineMAX = 8;
 
//weapon classes disabled from re-arming
_NoGoWeapCName = [
        //irrelevant ones
        "Horn","MiniCarHorn","SportCarHorn","TruckHorn2","TruckHorn","BikeHorn","CarHorn","TruckHorn3","DixieHorn","FluffyHorn","BananaHorn",
        //not allowed ones
        "FFARLauncher_14","2A46M","2A46MRocket","M256","AT5LauncherSingle"
				//GH Flare
				//"CMFlareLauncher"
        //Missiles
        //"missiles_DAR","missiles_DAGR","rockets_230mm_GAT","missiles_Zephyr","missiles_ASRAAM","missiles_SCALPEL","rockets_Skyfire",
				//Bombs
				//"GBU12BombLauncher_Plane_Fighter_03_F","Mk82BombLauncher",
				//Tank Cannons
				//"cannon_105mm","cannon_120mm","cannon_125mm",
        //Speedboat GMG
        //"GMG_40mm",
				//CUP
				//"CUP_Vcannon_M256_M1Abrams","CUP_Vgmg_MK19_veh","CUP_Vacannon_GAU22_veh",
				//"CUP_Vmlauncher_FFAR_veh_UH1Y","CUP_Vblauncher_Mk82_veh","CUP_Vmlauncher_AIM120_veh","CUP_Vblauncher_GBU12_veh","CUP_Vmlauncher_AIM9L_veh"
];
 
//magazine classnames not allowed to be rearmed
_NoGoAmmoCName = [
        //O HMG 100 RND
        "100Rnd_127x99_mag_Tracer_Yellow","100Rnd_127x99_mag_Tracer_Green","100Rnd_127x99_mag",
        //GH 200 RND
        "200Rnd_65x39_Belt","200Rnd_65x39_Belt_Tracer_Green","200Rnd_65x39_Belt_Tracer_Yellow","200Rnd_65x39_Belt_Tracer_Red",
        //GH 2000 RND
        "2000Rnd_65x39_Belt","2000Rnd_65x39_Belt_Green","2000Rnd_65x39_Belt_Yellow",
        //GH 1000 RND
        "1000Rnd_65x39_Belt","1000Rnd_65x39_Belt_Green","1000Rnd_65x39_Belt_Yellow",
        //GH 2000 RND
        "2000Rnd_65x39_Belt_Tracer_Red","2000Rnd_65x39_Belt_Tracer_Green","2000Rnd_65x39_Belt_Tracer_Yellow",
        //GH 1000 RND
        "1000Rnd_65x39_Belt_Tracer_Green","1000Rnd_65x39_Belt_Tracer_Yellow",
        //GH 2000 RND
        "2000Rnd_65x39_Belt_Tracer_Green_Splash","2000Rnd_65x39_Belt_Tracer_Yellow_Splash",        
        //PAWNEE 5000 RND
        "5000Rnd_762x51_Belt"
				//MISSILES
				//"24Rnd_missiles","12Rnd_missiles","24Rnd_PG_missiles","12Rnd_PG_missiles","12Rnd_230mm_rockets",
				//"2Rnd_GAT_missiles","5Rnd_GAT_missiles","4Rnd_GAA_missiles",
				//"2Rnd_AAA_missiles","2Rnd_AAA_missiles_MI02","4Rnd_AAA_missiles","4Rnd_AAA_missiles_MI02",
				//"2Rnd_LG_scalpel","8Rnd_LG_scalpel","6Rnd_LG_scalpel",
				//"14Rnd_80mm_rockets","38Rnd_80mm_rockets",
				//BOMBS
				//"2Rnd_GBU12_LGB","2Rnd_GBU12_LGB_MI10","2Rnd_Mk82","2Rnd_Mk82_MI08",
				//CANNON RND
				//"40Rnd_105mm_APFSDS","40Rnd_105mm_APFSDS_T_Red","40Rnd_105mm_APFSDS_T_Green","40Rnd_105mm_APFSDS_T_Yellow",
				//"20Rnd_105mm_HEAT_MP","20Rnd_105mm_HEAT_MP_T_Red","20Rnd_105mm_HEAT_MP_T_Green","20Rnd_105mm_HEAT_MP_T_Yellow",
				//"32Rnd_120mm_APFSDS_shells","32Rnd_120mm_APFSDS_shells_Tracer_Red","32Rnd_120mm_APFSDS_shells_Tracer_Green","32Rnd_120mm_APFSDS_shells_Tracer_Yellow","30Rnd_120mm_APFSDS_shells","30Rnd_120mm_APFSDS_shells_Tracer_Red","30Rnd_120mm_APFSDS_shells_Tracer_Green","30Rnd_120mm_APFSDS_shells_Tracer_Yellow",
				//"30Rnd_120mm_HE_shells","30Rnd_120mm_HE_shells_Tracer_Red","30Rnd_120mm_HE_shells_Tracer_Green","30Rnd_120mm_HE_shells_Tracer_Yellow","16Rnd_120mm_HE_shells","16Rnd_120mm_HE_shells_Tracer_Red","16Rnd_120mm_HE_shells_Tracer_Green","16Rnd_120mm_HE_shells_Tracer_Yellow",
				//"24Rnd_125mm_APFSDS","24Rnd_125mm_APFSDS_T_Red","24Rnd_125mm_APFSDS_T_Green","24Rnd_125mm_APFSDS_T_Yellow",
				//"12Rnd_125mm_HE","12Rnd_125mm_HE_T_Red","12Rnd_125mm_HE_T_Green","12Rnd_125mm_HE_T_Yellow","12Rnd_125mm_HEAT","12Rnd_125mm_HEAT_T_Red","12Rnd_125mm_HEAT_T_Green","12Rnd_125mm_HEAT_T_Yellow",
        //GMG RND
        //"200Rnd_40mm_G_belt","96Rnd_40mm_G_belt","64Rnd_40mm_G_belt","32Rnd_40mm_G_belt",
				//30MM EXPLOSIVE
				//"250Rnd_30mm_HE_shells","250Rnd_30mm_HE_shells_Tracer_Red","250Rnd_30mm_HE_shells_Tracer_Green",
				//"140Rnd_30mm_MP_shells","140Rnd_30mm_MP_shells_Tracer_Red","140Rnd_30mm_MP_shells_Tracer_Green","140Rnd_30mm_MP_shells_Tracer_Yellow",
        //CUP
        //"CUP_4000Rnd_TE5_White_Tracer_762x51_M134_M","CUP_4000Rnd_TE5_Red_Tracer_762x51_M134_M","CUP_4000Rnd_TE1_Red_Tracer_762x51_M134_M",
        //"CUP_750Rnd_TE2_Red_Tracer_M197_20mm_HEI_M","CUP_750Rnd_TE2_Green_Tracer_M197_20mm_HEI_M","CUP_750Rnd_TE2_Yellow_Tracer_M197_20mm_HEI_M",
        //"CUP_20Rnd_TE1_Red_Tracer_120mmSABOT_M256_Cannon_M","CUP_20Rnd_TE1_Red_Tracer_120mmHE_M256_Cannon_M",
        //"CUP_96Rnd_40mm_MK19_M","CUP_48Rnd_40mm_MK19_M","CUP_32Rnd_40mm_MK19_M","CUP_220Rnd_TE1_White_Tracer_30mm_GAU22_M",
        //"CUP_14Rnd_FFAR_Mid_M","CUP_2Rnd_Mk82_M","CUP_4Rnd_Mk82_M","CUP_6Rnd_Mk82_M","CUP_8Rnd_Mk82_M","CUP_Mk82_G",
        //"CUP_2Rnd_GBU12_M","CUP_4Rnd_GBU12_M","CUP_6Rnd_GBU12_M","CUP_8Rnd_GBU12_M","CUP_GBU_G",
        //"CUP_4Rnd_AIM_9L_Sidewinder_External_M","CUP_2Rnd_AIM_9L_Sidewinder_External_M","CUP_Sidewinder_G"
];
 
//cost per magazine for individual vehicles
_rearm_costs = [
        ["Air",0],
        ["AllVehicles",0]        
];
 
//debug weapons to see classnames in chat/rpt
_debugWeapon = false;
 
 
//=================================== CONFIG END
_lastVehicle = objNull;
_lastRole = [];

SP_refuel_action = -1;
SP_repair_action = -1;
SP_rearm_actions = [];
 
_messageShown = false;
 
_fnc_removeActions = {
        if (isNull _lastVehicle) exitWith {};
    if (isNull _lastVehicle) exitWith {};
        _lastVehicle removeAction SP_refuel_action;
        SP_refuel_action = -1;        
        _lastVehicle removeAction SP_repair_action;
        SP_repair_action = -1;
        {
                _lastVehicle removeAction _x;
        } forEach SP_rearm_actions;
        SP_rearm_actions = [];
        _lastVehicle = objNull;
        _lastRole = [];
};
 
_fnc_getCosts = {
        private ["_vehicle","_costs","_cost"];
        _vehicle = _this select 0;
        _costs = _this select 1;
        _cost = [];
        {
                private "_typeName";
                _typeName = _x select 0;
                if (_vehicle isKindOf _typeName) exitWith {
                        _cost = _x select 1;
                };
        } forEach _costs;
        _cost
};
 
_fnc_actionTitle = {
        private ["_actionName","_costs","_costsText","_actionTitle"];
        _actionName = _this select 0;
        _costs = _this select 1;
        _costsText = _costsFree;
        if (_costs > 0) then {
                private ["_itemName","_displayName"];
                _costsText = format ["%1 Pop-Tabs",_costs];
        };
        _actionTitle = format ["<t color='%3'>%1 (%2)</t>", _actionName, _costsText,_actionColour];
        _actionTitle
};
 
_fnc_getWeapons = {
        private ["_vehicle","_role","_weapons"];
        _vehicle = _this select 0;
        //turrets positions to search for weapons
        _turrets = [[-1],[0],[1],[2],[0,0],[1,0],[2,0],[0,1],[0,2]];
        _weapons = [];
        {
                _turret = _x;
                _weaponsTurret = _vehicle weaponsTurret _turret;
                {
                        _weapon = _x;
                        if !(_weapon in _NoGoWeapCName) then{
                                _weaponName = getText (configFile >> "CfgWeapons" >> _weapon >> "displayName");
                                _weapons pushBack [_weapon, _weaponName, _turret];
                        };
                }forEach _weaponsTurret;
        }forEach _turrets;
        _weapons
};
 
_fnc_getAmmo = {
        private ["_vehicle","_role","_weapons"];
        _vehicle = _this select 0;
        _weapon = _this select 1;
        _allammo = getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines");
				_allammo append getArray (configFile >> "CfgWeapons" >> _weapon >> "HE" >> "magazines");
				_allammo append getArray (configFile >> "CfgWeapons" >> _weapon >> "AP" >> "magazines");
        _ammoreturn = [];
        {
                _curammo = _x;
                if !(_curammo in _NoGoAmmoCName) then{
                        _ammoname = getText (configFile >> "Cfgmagazines" >> _curammo >> "displayName");
                        _ammoreturn pushBack [_curammo, _ammoname];
                };
        }forEach _allammo;
        _ammoreturn
};
 
while {true} do {
        private ["_vehicle","_inVehicle"];
        _vehicle = vehicle player;
        _inVehicle = _vehicle != player;
        if (local _vehicle && _inVehicle) then {
                private ["_pos","_servicePoints","_inRange"];
                _pos = getPosATL _vehicle;
                _servicePoints = (nearestObjects [_pos, _servicePointClasses, _maxDistance]) - [_vehicle];
                _inRange = count _servicePoints > 0;
                if (_inRange && (speed (_vehicle) < 1) && (speed (_vehicle) > -1)) then {
                        private ["_servicePoint","_role","_actionCondition","_costs","_actionTitle"];
                        _servicePoint = _servicePoints select 0;
                        _role = assignedVehicleRole player;
                        if (((str _role) != (str _lastRole)) || (_vehicle != _lastVehicle)) then {
                                // vehicle or seat changed
                                call _fnc_removeActions;
                        };
                        _lastVehicle = _vehicle;
                        _lastRole = _role;
                        _actionCondition = "vehicle _this == _target && local _target";
                        if (SP_refuel_action < 0 && _refuel_enable) then {
                        _costs = [_vehicle, _refuel_costs] call _fnc_getCosts;
                        _actionTitle = [format["Refuel %1",getText (configFile >> "Cfgvehicles" >> typeOf _vehicle >> "displayName")], _costs] call _fnc_actionTitle;
                        SP_refuel_action = _vehicle addAction [_actionTitle, _folder + "service_point_refuel.sqf", [_servicePoint, _costs, _refuel_updateInterval, _refuel_amount], -1, false, true, "", _actionCondition];
                        };                        
                        if (SP_repair_action < 0 && _repair_enable) then {
                                _costs = [_vehicle, _repair_costs] call _fnc_getCosts;
                                _actionTitle = [format["Repair %1",getText (configFile >> "Cfgvehicles" >> typeOf _vehicle >> "displayName")], _costs] call _fnc_actionTitle;
                                SP_repair_action = _vehicle addAction [format["<img size='1.5'image='\a3\Ui_f\data\IGUI\Cfg\Cursors\iconrepairvehicle_ca.paa'/> %1",_actionTitle], _folder + "service_point_repair.sqf", [_servicePoint, _costs, _repair_repairTime], -1, false, true, "", _actionCondition];
                        };
                        if ((count SP_rearm_actions == 0) && _rearm_enable) then {
                                private ["_weapons"];
                                _costs = [_vehicle, _rearm_costs] call _fnc_getCosts;
                                _weapons = [_vehicle, _role] call _fnc_getWeapons;
                                {
                                        private "_weaponName";
                                        _curweapon = _x select 0;
                                        _weaponName = _x select 1;
                                        _curturret = _x select 2;
                                        if(_debugWeapon)then{_msg = format["WEAPONS DEBUG: %1",_x];diag_log _msg;systemChat _msg;};
                                        _ammo = [_vehicle,_curweapon] call _fnc_getAmmo;
                                        {
                                                _ammoclass = _x select 0;
                                                _ammoname = _x select 1;
                                                _actionTitle = [format["Rearm %1 with %2", _weaponName,_ammoname], _costs] call _fnc_actionTitle;
                                                SP_rearm_action = _vehicle addAction [format["<img size='1.5'image='\a3\Ui_f\data\IGUI\Cfg\WeaponIcons\mg_ca.paa'/> %1",_actionTitle], _folder + "service_point_rearm.sqf", [_servicePoint, _costs, [_weaponName,_ammoclass,_ammoname,_GlobalMagazineMAX,_deny_already_armed_with,_curturret]], -1, false, true, "", _actionCondition];
                                                SP_rearm_actions set [count SP_rearm_actions, SP_rearm_action];
                                        }forEach _ammo;
                                       
                                } forEach _weapons;
                        };
                        if (!_messageShown) then {
                                _messageShown = true;
                                cutText [format["%1", _message], "PLAIN DOWN"];
                        };
                } else {
                        call _fnc_removeActions;
                        _messageShown = false;
                };
        } else {
                call _fnc_removeActions;
                _messageShown = false;
        };
        sleep 2;
};