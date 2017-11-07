/*

Restart Timer Toasts by [FPS]kuplion

*/
	//sleep 13380; // 4 Hour Restarts, 15 Minutes before restart.. (2 minutes offset to compensate for server startup)
	sleep 9780; // 3 Hour Restarts, 15 Minutes before restart.. (2 minutes offset to compensate for server startup)
	
	// 15 Minutes before restart
	diag_log format ["15 minute Toast @ %1", time];
	["toastRequest", ["ErrorTitleAndText", ["Server Restart", "Restart in 15 minutes."]]] call ExileServer_system_network_send_broadcast; sleep 300;
	
	// 10 Minutes before restart
	diag_log format ["10 minute Toast @ %1", time];
	["toastRequest", ["ErrorTitleAndText", ["Server Restart", "Restart in 10 minutes."]]] call ExileServer_system_network_send_broadcast; sleep 300;
	
	// 5 Minutes before restart
	diag_log format ["5 minute Toast @ %1", time];
	["toastRequest", ["ErrorTitleAndText", ["Server Restart", "Restart in 5 minutes. Please logout now to avoid losing your gear."]]] call ExileServer_system_network_send_broadcast; sleep 120;
	
	// 3 Minutes before restart
	diag_log format ["3 minute Toast @ %1", time];
	["toastRequest", ["ErrorTitleAndText", ["Server Restart", "Restart in 3 minutes. Please logout now to avoid losing your gear."]]] call ExileServer_system_network_send_broadcast; sleep 120;
	
	// 1 Minutes before restart
	diag_log format ["1 minute Toast @ %1", time];
	["toastRequest", ["ErrorTitleAndText", ["Server Restart", "Restart in 1 minutes. Please logout now to avoid losing your gear."]]] call ExileServer_system_network_send_broadcast; sleep 50;
	
	// Restart now!!!
	diag_log format ["Final Restart Toast @ %1", time];
	["toastRequest", ["ErrorTitleAndText", ["Server Restart", "Restart in progress!!!"]]] call ExileServer_system_network_send_broadcast;
