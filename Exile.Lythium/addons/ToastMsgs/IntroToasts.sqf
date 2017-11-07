/*

Intro Toasts by [FPS]kuplion

*/

//waitUntil{!isNull (findDisplay 46)};
waitUntil{sleep 1; ExileClientPlayerIsSpawned}; 
waitUntil{player == player};

if ( alive player ) then {

  	sleep 30;
	
	//["ErrorTitleAndText", ["Welcome Player!", "Welcome to the Cantankerous Old Goats PVE Exile Lythium server!"]] call ExileClient_gui_toaster_addTemplateToast; sleep 30;
	
	["ErrorTitleAndText", ["Welcome Player!", "The server will be temporarily turned off on Oct 15th. Check the website for more info."]] call ExileClient_gui_toaster_addTemplateToast; sleep 30;
	
	["ErrorTitleAndText", ["Website Info:", "Find us at cantankerousoldgoats.enjin.com for server updates and info."]] call ExileClient_gui_toaster_addTemplateToast; sleep 30;
	
	["ErrorTitleAndText", ["Teamspeak Info:", "Join us in Teamspeak at ts3.kurewe.com if you need help or want to chat."]] call ExileClient_gui_toaster_addTemplateToast; sleep 30;
	
	["ErrorTitleAndText", ["PVE Server!", "Don't kill players. Players should have a blue name above their head. If you don't see blue names, re-log."]] call ExileClient_gui_toaster_addTemplateToast; sleep 30;
	
	["ErrorTitleAndText", ["Rules and Info:", "Before playing, please make sure you read the 'Rules and Info' in the XM8, under More!!"]] call ExileClient_gui_toaster_addTemplateToast; sleep 30;
	
	["ErrorTitleAndText", ["Need Help?", "If you need help, just ask. Someone will point you in the right direction."]] call ExileClient_gui_toaster_addTemplateToast; sleep 60;
	
	//["ErrorTitleAndText", ["Chemlights", "Attach chemlights to your body at night by rolling the mouse wheel and clicking 'Attach'. Perfect for when you don't have NVGs yet.."]] call ExileClient_gui_toaster_addTemplateToast; sleep 60;
	
	//["ErrorTitleAndText", ["Claiming Vehicles", "If you have a code lock, you claim any vehicle not already owned"]] call ExileClient_gui_toaster_addTemplateToast; sleep 60;

	//["ErrorTitleAndText", ["Spawning Vehicles", "You can spawn a Quad or Motorcycle"]] call ExileClient_gui_toaster_addTemplateToast; sleep 60;
	
	// Chernarus Only
	//["ErrorTitleAndText", ["Persistent Vehicles", "All vehicles are server owned and persistent. The cannot be locked so be sure to hide them well."]] call ExileClient_gui_toaster_addTemplateToast; sleep 60;
	// Chernarus Only
	
	//["ErrorTitleAndText", ["Hordes", "There have been reports of large hordes of Zombies moving across the islands; be careful!!"]] call ExileClient_gui_toaster_addTemplateToast; sleep 60;
	
	// Tanoa Only
	//["ErrorTitleAndText", ["Incoming Transmission", "Please standby.."]] call ExileClient_gui_toaster_addTemplateToast; sleep 5;
	
	// Remove Toasts
	//call ExileClient_gui_toaster_removeAllToasts;
	
	//["ErrorTitleAndText", ["Radiation Zone", "The radiation has finally gone but the infected are still all over the island. Cross the bridge at 050115 with caution!!!"]] call ExileClient_gui_toaster_addTemplateToast;
	// Tanoa Only
	
};