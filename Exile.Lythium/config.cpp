/**
 * config
 *
 * Exile Mod
 * www.exilemod.com
 * © 2015 Exile Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 */
 
class CfgXM8
{
	extraApps[] = {"ExAd_VG","ExAd_Info","ExAd_CHVD","ExAd_Journal","ExAd_Quad","ExAd_Motorcycle","BRAmaRecipes","BaseMarker"};
	//extraApps[] = {"ExAd_VG","ExAd_Info","ExAd_CHVD","ExAd_Journal","ExAd_Quad","ExAd_Motorcycle","BRAmaRecipes","BaseMarker","VehMarker"};
	
	class ExAd_VG 
	{
		title = "Virtual Garage";
		controlID = 50000;					//These need to be unique
		onLoad = "ExAdClient\XM8\Apps\VG\onLoad.sqf";
		onOpen = "ExAdClient\XM8\Apps\VG\onOpen.sqf";
		onClose = "ExAdClient\XM8\Apps\VG\onClose.sqf";
	};
	class ExAd_Info 
	{
		title = "Rules and Info";
		controlID = 50100;					//IDC:50100 -> 50102 || These need to be unique and out of range from each other
		logo = "ExadClient\XM8\Apps\Info\Icon_SI.paa";
		onLoad = "ExAdClient\XM8\Apps\Info\onLoad.sqf";
		onOpen = "ExAdClient\XM8\Apps\Info\onOpen.sqf";
		onClose = "ExAdClient\XM8\Apps\Info\onClose.sqf";
	};	
	class ExAd_CHVD 
	{
		title = "View Distance Settings";
		controlID = 50200;					//IDC:50200 -> 50102 || These need to be unique and out of range from each other
		config = "ExadClient\XM8\Apps\CHVD\config.sqf";
		logo = "ExadClient\XM8\Apps\CHVD\Icon_CHVD.paa";
		onLoad = "ExAdClient\XM8\Apps\CHVD\onLoad.sqf";
		onOpen = "ExAdClient\XM8\Apps\CHVD\onOpen.sqf";
		onClose = "ExAdClient\XM8\Apps\CHVD\onClose.sqf";
	};		
	class ExAd_Journal 
	{
		title = "Journal";
		controlID = 50300;					//IDC:50300 -> 50305 || These need to be unique and out of range from each other
		config = "ExadClient\XM8\Apps\Journal\config.sqf";
		logo = "ExadClient\XM8\Apps\Journal\Icon_Journal.paa";
		onLoad = "ExAdClient\XM8\Apps\Journal\onLoad.sqf";
		onOpen = "ExAdClient\XM8\Apps\Journal\onOpen.sqf";
		onClose = "ExAdClient\XM8\Apps\Journal\onClose.sqf";
	};
	class ExAd_Quad
	{
		title = "Deploy Quad";
		config = "ExadClient\XM8\Apps\DeployVehicle\config.sqf";
		bambiState = 0;
		vehicleClass = "B_G_Quadbike_01_F";
		recipe[] = {{"Exile_Item_LightBulb",1}};
		packable = 1;
		autoCleanUp = 1;
		quickFunction = "['ExAd_Quad'] call ExAd_XM8_DV_fnc_spawnVehicle";
	};
	class ExAd_Motorcycle
	{
		title = "Deploy Motorcycle";
		config = "ExadClient\XM8\Apps\DeployVehicle\config.sqf";
		bambiState = 0;
		vehicleClass = "CUP_B_M1030";
		recipe[] = {{"Exile_Item_LightBulb",1}};
		packable = 1;
		autoCleanUp = 1;
		quickFunction = "['ExAd_Motorcycle'] call ExAd_XM8_DV_fnc_spawnVehicle";
	};
	class BRAmaRecipes 
	{
		controlID = 107000;
		title = "Recipes";		
		logo = "ExAdClient\XM8\Apps\BRAmaRecipes\BRAma.paa";
		config = "ExAdClient\XM8\Apps\BRAmaRecipes\config.sqf";
		onLoad = "ExAdClient\XM8\Apps\BRAmaRecipes\onLoad.sqf";
		onOpen = "ExAdClient\XM8\Apps\BRAmaRecipes\onOpen.sqf";
	};
	class BaseMarker
	{
		controlID = 50500;
		title = "Base Marker";
		logo = "ExAdClient\XM8\Apps\BaseMarker\BaseMarker.paa";
		onLoad = "ExAdClient\XM8\Apps\BaseMarker\onLoad.sqf";
	};
/*
	class VehMarker
	{
		controlID = 50600;
		title = "Vehicle Marker";
		logo = "ExAdClient\XM8\Apps\VehMarker\VehMarker.paa";
		onLoad = "ExAdClient\XM8\Apps\VehMarker\onLoad.sqf";
	};
*/
}; 

class CfgClans
{
	/*
		Defines the amount of pop tabs needed to register a new clan

		Default: 20,000
	*/
	registrationFee = 20000;

	/*
		A list of all characters allowed in a clan *name*

		NOTE: 
	*/
	clanNameAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ._-!\\/";

	/*

		Maximum markers per clan

	*/
	maximumIcons = 20;

	/*
		Maximum number of characters on a Marker in a presistent system

		Note: MAX 255!
		
	*/
	maximumIconText = 50;

	/*

		Maximum poly markers per clan

	*/
	maximumPolys = 10;


	/* 

		Maximum points in poly
	*/
	maximumPolyNode = 10;
};
class Exile_AbstractCraftingRecipe
{
	name = "";
	pictureItem = ""; 
	returnedItems[] = {};
	components[] = {}; // Required components
	tools[] = {}; // Required tools (matches, gas cooker etc.)
	requiredInteractionModelGroup = ""; // See CfgInteractionModels
	requiresOcean = 0; // isSurfaceWater test
	requiresFire = 0; // inflamed object nearby
	requiresConcreteMixer = 0; // Check if concrete mixer is nearby
};

class CfgCraftingRecipes
{
	#include "addons\EBM\recipes.hpp"
	#include "addons\COG\recipes.hpp"

//START CUSTOM RECIPES

class MagazinesToPhotos: Exile_AbstractCraftingRecipe
{
	name = "Make A Photo Collection";
	pictureItem = "CUP_item_Kostey_photos";
	requiresFire = 1;
	returnedItems[] = 
	{
		{1, "CUP_item_Kostey_photos"}
	};
	components[] = 
	{
		{1, "Exile_Item_Magazine01"},
		{1, "Exile_Item_Magazine02"},
		{1, "Exile_Item_Magazine03"},
		{1, "Exile_Item_Magazine04"}
	};
	category = "COG Buildables";
};

class UpgradeTinToMetal: Exile_AbstractCraftingRecipe
{
	name = "Melt Tin";
	pictureItem = "Exile_Item_JunkMetal";
	requiresFire = 1;
	returnedItems[] = 
	{
		{1, "Exile_Item_JunkMetal"}
	};
	components[] = 
	{
		{5, "Exile_Item_Can_Empty"}
	};
	category = "Exile Materials";
};

class MakeVishpirin: Exile_AbstractCraftingRecipe
{
	name = "Make Vishpirin";
	pictureItem = "Exile_Item_Vishpirin";
	returnedItems[] = 
	{
		{1, "Exile_Item_Vishpirin"}
	};
	components[] = 
	{
		{5, "Exile_Item_Bandage"}
	};
	category = "Exile First Aid";
};

class MakeInstaDoc: Exile_AbstractCraftingRecipe
{
	name = "Make InstaDoc";
	pictureItem = "Exile_Item_InstaDoc";
	requiresFire = 1;
	returnedItems[] = 
	{
		{1, "Exile_Item_InstaDoc"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{4, "Exile_Item_Vishpirin"},
		{1, "Exile_Item_Heatpack"},
		{1, "Exile_Item_PlasticBottleFreshWater"}
	};
	category = "Exile First Aid";
};

class CanOpenerFromMetal: Exile_AbstractCraftingRecipe
{
	name = "Make Can Opener";
	pictureItem = "Exile_Item_CanOpener";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_CanOpener"}
	};
	tools[] =
	{
		"Exile_Item_Pliers"
	};
	components[] = 
	{
		{1, "Exile_Item_JunkMetal"}
	};
	category = "Exile Food";
};

class RecycleWoodDoorWay: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Doorway";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{6, "Exile_Item_WoodPlank"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodDoorwayKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodDoor: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Door";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{8, "Exile_Item_WoodPlank"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodDoorKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodFloor: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Floor";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{4, "Exile_Item_WoodPlank"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodFloorKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodFloorPort: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Floor Port";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{6, "Exile_Item_WoodPlank"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodFloorPortKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodGate: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Gate";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{8, "Exile_Item_WoodPlank"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodGateKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodStairs: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Stairs";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{6, "Exile_Item_WoodPlank"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodStairsKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodSupport: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Support";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{6, "Exile_Item_WoodPlank"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodSupportKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodWall: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Wall";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{4, "Exile_Item_WoodPlank"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodWallKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodWallHalf: Exile_AbstractCraftingRecipe
{
	name = "Recycle 1/2 Wood Wall";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{2, "Exile_Item_WoodPlank"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodWallHalfKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodWindow: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Window";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{6, "Exile_Item_WoodPlank"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodWindowKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodLadder: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Ladder";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] =
	{
		{6, "Exile_Item_WoodPlank"}
	};
	components[] =
	{
		{1, "Exile_Item_WoodLadderKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodDrawBridge: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Draw Bridge";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] =
	{
		{8, "Exile_Item_WoodPlank"},
		{1, "Exile_Item_JunkMetal"},
		{1, "Exile_Item_MetalScrews"}
	};
	components[] =
	{
		{1, "Exile_Item_WoodDrawBridgeKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

class RecycleWoodFloorPortSmall: Exile_AbstractCraftingRecipe
{
	name = "Recycle Wood Floor Port (Small)";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] =
	{
		{6, "Exile_Item_WoodPlank"}
	};
	components[] =
	{
		{1, "Exile_Item_WoodFloorPortSmallKit"}
	};
	tools[] =
	{
		"Exile_Item_Hammer"
	};
	category = "Exile Wood";
};

//END CUSTOM RECIPES

//START DONATION GOAL EBM RECIPES

class Barracks: Exile_AbstractCraftingRecipe
{
	name = "Barracks";
	pictureItem = "Land_i_Barracks_V1_F_Kit";
	returnedItems[] = 
	{
		{1, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"},
		{1, "Land_i_Barracks_V1_F_Kit"}
	};
	requiresFire = 0;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{2, "Exile_Item_MetalBoard"},
		{2, "Exile_Item_Cement"},
		{2, "Exile_Item_Sand"},
		{1, "Exile_Item_FuelCanisterFull"},
		{1, "Exile_Item_WaterCanisterDirtyWater"}
	};
	tools[] =
	{
		"Exile_Item_Shovel"
	};
	requiresConcreteMixer = 1;
	category = "Donation Goal EBM Buildings";
};

class AirportTower: Exile_AbstractCraftingRecipe
{
	name = "Airport Tower";
	pictureItem = "Land_Airport_Tower_F_Kit";
	returnedItems[] = 
	{
		{1, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"},
		{1, "Land_Airport_Tower_F_Kit"}
	};
	requiresFire = 1;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{5, "Exile_Item_Woodlog"},
		{2, "Exile_Item_Cement"},
		{1, "Exile_Item_Sand"},
		{1, "Exile_Item_FuelCanisterFull"},
		{1, "Exile_Item_WaterCanisterDirtyWater"}
	};
	tools[] =
	{
		"Exile_Item_Shovel"
	};
	requiresConcreteMixer = 1;
	category = "Donation Goal EBM Buildings";
};

class BigDome: Exile_AbstractCraftingRecipe
{
	name = "Big Dome";
	pictureItem = "Land_Dome_Big_F_Kit";
	returnedItems[] = 
	{
		{1, "Land_Dome_Big_F_Kit"}
	};
	requiresFire = 1;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{2, "Exile_Item_MetalPole"},
		{4, "Exile_Item_MetalBoard"},
		{4, "Exile_Item_Rope"},
		{4, "Exile_Item_MetalWire"},
		{4, "Exile_Item_MetalScrews"}
	};
	tools[] =
	{
		"Exile_Item_Pliers",
		"Exile_Item_Screwdriver",
		"Exile_Item_Grinder"
	};
	category = "Donation Goal EBM Buildings";
};

class AirplaneHangar: Exile_AbstractCraftingRecipe
{
	name = "Airplane Hangar";
	pictureItem = "Land_Hangar_F_Kit";
	returnedItems[] = 
	{
		{1, "Land_Hangar_F_Kit"}
	};
	requiresFire = 1;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{2, "Exile_Item_MetalPole"},
		{2, "Exile_Item_MetalBoard"},
		{4, "Exile_Item_Rope"},
		{4, "Exile_Item_MetalWire"},
		{4, "Exile_Item_DuctTape"}
	};
	tools[] =
	{
		"Exile_Item_Pliers",
		"Exile_Item_Screwdriver",
		"Exile_Item_Grinder"
	};
	category = "Donation Goal EBM Buildings";
};

class Tavern: Exile_AbstractCraftingRecipe
{
	name = "Tavern";
	pictureItem = "Land_i_Addon_03_V1_F_Kit";
	returnedItems[] = 
	{
		{1, "Land_i_Addon_03_V1_F_Kit"}
	};
	requiresFire = 1;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{10, "Exile_Item_WoodPlank"},
		{5, "Exile_Item_JunkMetal"},
		{2, "Exile_Item_MetalScrews"}
	};
	tools[] =
	{
		"Exile_Item_Screwdriver"
	};
	
	category = "Donation Goal EBM Buildings";
};

class TavernMiddle: Exile_AbstractCraftingRecipe
{
	name = "Tavern middle";
	pictureItem = "Land_i_Addon_03mid_V1_F_Kit";
	returnedItems[] = 
	{
		{1, "Land_i_Addon_03mid_V1_F_Kit"}
	};
	requiresFire = 1;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{10, "Exile_Item_WoodPlank"},
		{5, "Exile_Item_JunkMetal"},
		{2, "Exile_Item_MetalScrews"}
	};
	tools[] =
	{
		"Exile_Item_Screwdriver"
	};
	category = "Donation Goal EBM Buildings";
};

class TentHangar: Exile_AbstractCraftingRecipe
{
	name = "Tent Hangar";
	pictureItem = "Land_TentHangar_V1_F_Kit";
	returnedItems[] = 
	{
		{1, "Land_TentHangar_V1_F_Kit"}
	};
	requiresFire = 1;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{5, "Exile_Item_Woodlog"},
		{2, "Exile_Item_MetalPole"},
		{3, "Exile_Item_Rope"},
		{5, "Exile_Item_DuctTape"},
		{1, "Exile_Item_MetalScrews"}
	};
	tools[] =
	{
		"Exile_Item_Pliers",
		"Exile_Item_Handsaw",
		"Exile_Item_Screwdriver"
	};
	category = "Donation Goal EBM Buildings";
};

class Garage: Exile_AbstractCraftingRecipe
{
	name = "Garage";
	pictureItem = "Land_i_Garage_V2_F_Kit";
	returnedItems[] = 
	{
		{1,"Exile_Item_WaterCanisterEmpty"},
		{1,"Exile_Item_FuelCanisterEmpty"},
		{1, "Land_i_Garage_V2_F_Kit"}
	};
	requiresFire = 0;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{1, "Exile_Item_Sand"},
		{1, "Exile_Item_Cement"},
		{2, "Exile_Item_WoodPlank"},
		{2, "Exile_Item_MetalScrews"},
		{1, "Exile_Item_FuelCanisterFull"},
		{1, "Exile_Item_WaterCanisterDirtyWater"}
	};
	tools[] =
	{
		"Exile_Item_Shovel",
		"Exile_Item_Screwdriver"
	};
	requiresConcreteMixer = 1;
	category = "Donation Goal EBM Buildings";
};

class CargoTowerBig: Exile_AbstractCraftingRecipe
{
	name = "Cargo Tower Big";
	pictureItem = "Land_Cargo_Tower_V2_F_Kit";
	returnedItems[] = 
	{
		{1, "Land_Cargo_Tower_V2_F_Kit"}
	};
	requiresFire = 1;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{6, "Exile_Item_MetalBoard"},
		{1, "Land_Cargo_House_V2_F_Kit"},
		{6, "Exile_Item_MetalScrews"}
	};
	tools[] =
	{
		"Exile_Item_Grinder",
		"Exile_Item_Screwdriver"
	};
	category = "Donation Goal EBM Buildings";
};

class BunkerHuge: Exile_AbstractCraftingRecipe
{
	name = "Bunker HUGE";
	pictureItem = "Land_Bunker_F_Kit";
	returnedItems[] = 
	{
		{1, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"},
		{1, "Land_Bunker_F_Kit"}
	};
	requiresFire = 0;
	requiredInteractionModelGroup = "WorkBench";
	components[] = 
	{
		{1, "Land_Cargo40_light_green_F_Kit"},
		{2, "Exile_Item_Cement"},
		{2, "Exile_Item_Sand"},
		{1, "Exile_Item_FuelCanisterFull"},
		{1, "Exile_Item_WaterCanisterDirtyWater"}
	};
	tools[] =
	{
		"Exile_Item_Shovel"
	};
	requiresConcreteMixer = 1;
	category = "Donation Goal EBM Containers";
};

class ConcreteMixer: Exile_AbstractCraftingRecipe
{
	name = "Concrete Mixer";
	pictureItem = "Exile_ConcreteMixer_Kit";
	returnedItems[] = 
	{
		{1, "Exile_ConcreteMixer_Kit"}
	};
	requiresFire = 1;
	components[] = 
	{
		{1, "Exile_Item_PortableGeneratorKit"},
		{3, "Exile_Item_JunkMetal"},
		{2, "Exile_Item_MetalScrews"},
		{4, "Exile_Item_MetalWire"},
		{2, "Exile_Item_DuctTape"}
	};
	tools[] =
	{
		"Exile_Item_Grinder",
		"Exile_Item_Pliers",
		"Exile_Item_Screwdriver"
	};
	category = "Donation Goal EBM Misc";
};

class Airport01hangarAPEX: Exile_AbstractCraftingRecipe
{
	name = "Airport Hangar APEX";
	pictureItem = "Land_Airport_01_hangar_F_Kit";
	returnedItems[] = 
	{
		{1,"Land_Airport_01_hangar_F_Kit"},
	};
	requiresFire = 1;
	components[] = 
	{
		{3, "Exile_Item_MetalBoard"},
		{2, "Exile_Item_MetalPole"},
		{4, "Exile_Item_MetalScrews"},
		{4, "Exile_Item_JunkMetal"}
	};
	tools[] =
	{
		"Exile_Item_Screwdriver",
		"Exile_Item_Grinder",
		"Exile_Item_Hammer"
	};
	category = "Donation Goal EBM Buildings";
};

//END DONATION GOAL EBM RECIPES

class BreachingChargeBigMomma: Exile_AbstractCraftingRecipe
{
	name = "Breaching Charge (Big Momma)";
	pictureItem = "Exile_Item_BreachingCharge_BigMomma";
	returnedItems[] =
	{
		{1, "Exile_Item_BreachingCharge_BigMomma"}
	};
	tools[] =
	{
		"Exile_Item_Foolbox"
	};
	components[] = 
	{
		{3, "Exile_Item_BreachingCharge_Metal"},
		{1, "Exile_Item_MobilePhone"},
		{1, "Exile_Item_DuctTape"},
		{1, "Exile_Item_ZipTie"}
	};
	category = "Exile Explosives";
};

class BreachingChargeMetal: Exile_AbstractCraftingRecipe
{
	name = "Breaching Charge (Metal)";
	pictureItem = "Exile_Item_BreachingCharge_Metal";
	returnedItems[] =
	{
		{1, "Exile_Item_BreachingCharge_Metal"}
	};
	tools[] =
	{
		"Exile_Item_Foolbox"
	};
	components[] = 
	{
		{1, "Exile_Item_DuctTape"},
		{1, "SatchelCharge_Remote_Mag"}
	};
	category = "Exile Explosives";
};

class BreachingChargeWood: Exile_AbstractCraftingRecipe
{
	name = "Breaching Charge (Wood)";
	pictureItem = "Exile_Item_BreachingCharge_Wood";
	returnedItems[] =
	{
		{1, "Exile_Item_BreachingCharge_Wood"}
	};
	tools[] =
	{
		"Exile_Item_Foolbox"
	};
	components[] = 
	{
		{1, "Exile_Item_DuctTape"},
		{1, "DemoCharge_Remote_Mag"}
	};
	category = "Exile Explosives";
};

class CookBBQSandwich: Exile_AbstractCraftingRecipe
{
	name = "Cook BBQ Sandwich";
	pictureItem = "Exile_Item_BBQSandwich_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_BBQSandwich_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_BBQSandwich"}
	};
	category = "Exile Food";
};

class CookCatFood: Exile_AbstractCraftingRecipe
{
	name = "Cook Cat Food";
	pictureItem = "Exile_Item_CatFood_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_CatFood_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_CatFood"}
	};
	category = "Exile Food";
};

class CookChristmasTinner: Exile_AbstractCraftingRecipe
{
	name = "Cook Christmas Tinner";
	pictureItem = "Exile_Item_ChristmasTinner_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_ChristmasTinner_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_ChristmasTinner"}
	};
	category = "Exile Food";
};

class CookCoffee: Exile_AbstractCraftingRecipe
{
	name = "Brew Coffee";
	pictureItem = "Exile_Item_PlasticBottleCoffee";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_PlasticBottleCoffee"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_PlasticBottleFreshWater"},
		{1, "Exile_Item_InstantCoffee"}
	};
	category = "Exile Drink";
};

class CookDogFood: Exile_AbstractCraftingRecipe
{
	name = "Cook Dog Food";
	pictureItem = "Exile_Item_DogFood_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_DogFood_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_DogFood"}
	};
	category = "Exile Food";
};

class CookGloriousKnakworst: Exile_AbstractCraftingRecipe
{
	name = "Cook Glorious Knakworst";
	pictureItem = "Exile_Item_GloriousKnakworst_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_GloriousKnakworst_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_GloriousKnakworst"}
	};
	category = "Exile Food";
};

class CookMacasCheese: Exile_AbstractCraftingRecipe
{
	name = "Cook Macas Cheese";
	pictureItem = "Exile_Item_MacasCheese_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_MacasCheese_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_MacasCheese"}
	};
	category = "Exile Food";
};

class CookPlasticBottleDirtyWater: Exile_AbstractCraftingRecipe
{
	name = "Cook Dirty Water";
	pictureItem = "Exile_Item_PlasticBottleFreshWater";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_PlasticBottleFreshWater"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_PlasticBottleDirtyWater"}
	};
	category = "Exile Drink";
};

class CookPlasticBottleSaltWater: Exile_AbstractCraftingRecipe
{
	name = "Cook Salt Water";
	pictureItem = "Exile_Item_PlasticBottleFreshWater";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_PlasticBottleFreshWater"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_PlasticBottleSaltWater"}
	};
	category = "Exile Drink";
};

class CookSausageGravy: Exile_AbstractCraftingRecipe
{
	name = "Cook Sausage Gravy";
	pictureItem = "Exile_Item_SausageGravy_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_SausageGravy_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_SausageGravy"}
	};
	category = "Exile Food";
};

class CookSurstromming: Exile_AbstractCraftingRecipe
{
	name = "Cook Surströmming";
	pictureItem = "Exile_Item_Surstromming_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_Surstromming_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_Surstromming"}
	};
	category = "Exile Food";
};

class CraftBandage: Exile_AbstractCraftingRecipe
{
	name = "Craft Bandage";
	pictureItem = "Exile_Item_Bandage";
	returnedItems[] =
	{
		{1, "Exile_Item_Bandage"}
	};
	components[] = 
	{
		{4, "Exile_Item_ToiletPaper"}
	};
	category = "Exile First Aid";
};

class CraftConcreteDoorway: Exile_AbstractCraftingRecipe
{
	name = "Craft Concrete Doorway";
	pictureItem = "Exile_Item_ConcreteDoorwayKit";
	requiresConcreteMixer = true;
	returnedItems[] = 
	{
		{1, "Exile_Item_ConcreteDoorwayKit"},
		{3, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"}
	};
	components[] = 
	{
		{3, "Exile_Item_Cement"},
		{3, "Exile_Item_Sand"},
		{3, "Exile_Item_MetalPole"},
		{3, "Exile_Item_WaterCanisterDirtyWater"},
		{1, "Exile_Item_FuelCanisterFull"}
	};
	category = "Exile Concrete";
};

class CraftConcreteFloor: Exile_AbstractCraftingRecipe
{
	name = "Craft Concrete Floor";
	pictureItem = "Exile_Item_ConcreteFloorKit";
	requiresConcreteMixer = true;
	returnedItems[] = 
	{
		{1, "Exile_Item_ConcreteFloorKit"},
		{2, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"}
	};
	components[] = 
	{
		{2, "Exile_Item_Cement"},
		{2, "Exile_Item_Sand"},
		{2, "Exile_Item_MetalPole"},
		{2, "Exile_Item_WaterCanisterDirtyWater"},
		{1, "Exile_Item_FuelCanisterFull"}
	};
	category = "Exile Concrete";
};

class CraftConcreteFloorPort: Exile_AbstractCraftingRecipe
{
	name = "Craft Concrete Floor Port";
	pictureItem = "Exile_Item_ConcreteFloorPortKit";
	requiresConcreteMixer = true;
	returnedItems[] = 
	{
		{1, "Exile_Item_ConcreteFloorPortKit"},
		{3, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"}
	};
	components[] = 
	{
		{3, "Exile_Item_Cement"},
		{3, "Exile_Item_Sand"},
		{3, "Exile_Item_MetalPole"},
		{3, "Exile_Item_WaterCanisterDirtyWater"},
		{1, "Exile_Item_FuelCanisterFull"}
	};
	category = "Exile Concrete";
};

class CraftConcreteGate: Exile_AbstractCraftingRecipe
{
	name = "Craft Concrete Gate";
	pictureItem = "Exile_Item_ConcreteGateKit";
	requiresConcreteMixer = true;
	returnedItems[] = 
	{
		{1, "Exile_Item_ConcreteGateKit"},
		{4, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"}
	};
	components[] = 
	{
		{4, "Exile_Item_Cement"},
		{4, "Exile_Item_Sand"},
		{4, "Exile_Item_MetalPole"},
		{4, "Exile_Item_WaterCanisterDirtyWater"},
		{1, "Exile_Item_FuelCanisterFull"}
	};
	category = "Exile Concrete";
};

class CraftConcretStairs: Exile_AbstractCraftingRecipe
{
	name = "Craft Concrete Stairs";
	pictureItem = "Exile_Item_ConcreteStairsKit";
	requiresConcreteMixer = true;
	returnedItems[] = 
	{
		{1, "Exile_Item_ConcreteStairsKit"},
		{1, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"}
	};
	components[] = 
	{
		{1, "Exile_Item_Cement"},
		{1, "Exile_Item_Sand"},
		{1, "Exile_Item_MetalPole"},
		{1, "Exile_Item_WaterCanisterDirtyWater"},
		{1, "Exile_Item_FuelCanisterFull"}
	};
	category = "Exile Concrete";
};

class CraftConcretSupport: Exile_AbstractCraftingRecipe
{
	name = "Craft Concrete Support";
	pictureItem = "Exile_Item_ConcreteSupportKit";
	requiresConcreteMixer = true;
	returnedItems[] = 
	{
		{1, "Exile_Item_ConcreteSupportKit"},
		{1, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"}
	};
	components[] = 
	{
		{1, "Exile_Item_Cement"},
		{1, "Exile_Item_Sand"},
		{1, "Exile_Item_MetalPole"},
		{1, "Exile_Item_WaterCanisterDirtyWater"},
		{1, "Exile_Item_FuelCanisterFull"}
	};
	category = "Exile Concrete";
};

class CraftConcreteWall: Exile_AbstractCraftingRecipe
{
	name = "Craft Concrete Wall";
	pictureItem = "Exile_Item_ConcreteWallKit";
	requiresConcreteMixer = true;
	returnedItems[] = 
	{
		{1, "Exile_Item_ConcreteWallKit"},
		{2, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"}
	};
	components[] = 
	{
		{2, "Exile_Item_Cement"},
		{2, "Exile_Item_Sand"},
		{2, "Exile_Item_MetalPole"},
		{2, "Exile_Item_WaterCanisterDirtyWater"},
		{1, "Exile_Item_FuelCanisterFull"}
	};
	category = "Exile Concrete";
};

class CraftFirePlace: Exile_AbstractCraftingRecipe
{
	name = "Craft Fire Place";
	pictureItem = "Exile_Item_CampFireKit";
	returnedItems[] = 
	{
		{1, "Exile_Item_CampFireKit"}
	};
	components[] = 
	{
		{2, "Exile_Item_WoodLog"}
	};
	category = "Exile Interactive";
};

class CraftFloodLight: Exile_AbstractCraftingRecipe
{
	name = "Craft Flood Light";
	pictureItem = "Exile_Item_FloodLightKit";
	requiresFire = 1;
	returnedItems[] = 
	{
		{1, "Exile_Item_FloodLightKit"}
	};
	components[] = 
	{
		{1, "Exile_Item_MetalPole"},
		{1, "Exile_Item_LightBulb"},
		{1, "Exile_Item_ExtensionCord"}
	};
	category = "Exile Interactive";
};

class CraftFortificationUpgrade: Exile_AbstractCraftingRecipe
{
	name = "Craft Fortification Upgrade";
	pictureItem = "Exile_Item_MetalBoard"; //<< CHANGE IT
	requiresFire = 1;
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_FortificationUpgrade"}
	};
	components[] = 
	{
		{2, "Exile_Item_MetalPole"},
		{4, "Exile_Item_MetalBoard"}
	};
	tools[] = {"Exile_Item_Grinder"};
	category = "Exile Upgrades";
};

class CraftHBarrier5Kit: Exile_AbstractCraftingRecipe
{
	name = "Craft H-barrier (5 Blocks)";
	pictureItem = "Exile_Item_HBarrier5Kit";
	requiredInteractionModelGroup = "WorkBench";
	tools[] = 
	{
		"Exile_Item_Pliers"
	};
	returnedItems[] = 
	{
		{1, "Exile_Item_HBarrier5Kit"}
	};
	components[] = 
	{
		{3, "Exile_Item_SandBagsKit_Long"},
		{2, "Exile_Item_MetalWire"}
	};
	category = "Exile Props";
};

class CraftMetalBoard: Exile_AbstractCraftingRecipe
{
	name = "Craft Metal Board";
	pictureItem = "Exile_Item_MetalBoard";
	requiresFire = 1;
	returnedItems[] = 
	{
		{1, "Exile_Item_MetalBoard"}
	};
	components[] = 
	{
		{2, "Exile_Item_JunkMetal"}
	};
	tools[] = {"Exile_Item_Grinder"};
	category = "Exile Materials";
};

class CraftMetalHedgehog: Exile_AbstractCraftingRecipe
{
	name = "Craft Metal Hedgehog";
	pictureItem = "Exile_Item_MetalHedgehogKit";
	requiresFire = 1;
	returnedItems[] = 
	{
		{1, "Exile_Item_MetalHedgehogKit"}
	};
	components[] = 
	{
		{4, "Exile_Item_MetalPole"}
	};
	tools[] = {"Exile_Item_Grinder"};
	category = "Exile Props";
};

class CraftMetalPole: Exile_AbstractCraftingRecipe
{
	name = "Craft Metal Pole";
	pictureItem = "Exile_Item_MetalPole";
	requiresFire = 1;
	returnedItems[] = 
	{
		{1, "Exile_Item_MetalPole"}
	};
	components[] = 
	{
		{4, "Exile_Item_JunkMetal"}
	};
	tools[] = {"Exile_Item_Grinder"};
	category = "Exile Materials";
};

class CraftPortableGenerator: Exile_AbstractCraftingRecipe
{
	name = "Craft Portable Generator";
	pictureItem = "Exile_Item_PortableGeneratorKit";
	requiresFire = 1;
	returnedItems[] = 
	{
		{1, "Exile_Item_PortableGeneratorKit"}
	};
	components[] = 
	{
		{4, "Exile_Item_MetalBoard"},
		{1, "Exile_Item_FuelCanisterFull"},
		{1, "Exile_Item_ExtensionCord"}
	};
	category = "Exile Interactive";
};

/*class CraftRazorWireKit: Exile_AbstractCraftingRecipe
{
	name = "Craft Razor Wire Kit Kit";
	pictureItem = "Exile_Item_RazorWireKit_Long";
	requiredInteractionModelGroup = "WorkBench";
	tools[] = 
	{
		"Exile_Item_Grinder", 
		"Exile_Item_Pliers",
		"Exile_Item_Screwdriver"
	};
	returnedItems[] = 
	{
		{1, "Exile_Item_RazorWireKit_Long"}
	};
	components[] = 
	{
		{2, "Exile_Item_MetalPole"},
		{4, "Exile_Item_MetalWire"},
		{1, "Exile_Item_MetalScrews"}
	};
	category = "Exile Props";
};*/

class CraftRepairKitConcrete: Exile_AbstractCraftingRecipe
{
	name = "Craft Concrete Repair Kit";
	pictureItem = "Exile_Item_Cement";
	requiresConcreteMixer = true;
	returnedItems[] = 
	{
		{1, "Exile_Item_RepairKitConcrete"},
		{1, "Exile_Item_WaterCanisterEmpty"},
		{1, "Exile_Item_FuelCanisterEmpty"}
	};
	components[] = 
	{
		{4, "Exile_Item_Cement"},
		{2, "Exile_Item_Sand"},
		{1, "Exile_Item_WaterCanisterDirtyWater"},
		{1, "Exile_Item_FuelCanisterFull"}
	};
	category = "Exile Repair";
};

class CraftRepairKitMetal: Exile_AbstractCraftingRecipe
{
	name = "Craft Metal Repair Kit";
	pictureItem = "Exile_Item_RepairKitMetal";
	requiresFire = 0;
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_RepairKitMetal"}
	};
	components[] = 
	{
		{4, "Exile_Item_MetalBoard"}
	};
	tools[] = {"Exile_Item_Foolbox", "Exile_Item_Grinder"};
	category = "Exile Repair";
};

class CraftRepairKitWood: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Repair Kit";
	pictureItem = "Exile_Item_RepairKitWood";
	requiresFire = 0;
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_RepairKitWood"}
	};
	components[] = 
	{
		{4, "Exile_Item_WoodPlank"}
	};
	tools[] = {"Exile_Item_Foolbox"};
	category = "Exile Repair";
};

class CraftSandBagsKitCorner: Exile_AbstractCraftingRecipe
{
	name = "Craft Sandbags Kit (Corner)";
	pictureItem = "Exile_Item_SandBagsKit_Corner";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_SandBagsKit_Corner"}
	};
	components[] = 
	{
		{3, "Exile_Item_Sand"}
	};
	category = "Exile Props";
};

class CraftSandBagsKitLong: Exile_AbstractCraftingRecipe
{
	name = "Craft Sand Bags Kit (Long)";
	pictureItem = "Exile_Item_SandBagsKit_Long";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_SandBagsKit_Long"}
	};
	components[] = 
	{
		{6, "Exile_Item_Sand"}
	};
	category = "Exile Props";
};

class CraftStorageCrate: Exile_AbstractCraftingRecipe
{
	name = "Craft Storage Crate";
	pictureItem = "Exile_Item_StorageCrateKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_StorageCrateKit"}
	};
	components[] = 
	{
		{5, "Exile_Item_WoodPlank"}
	};
	category = "Exile Storage";
};

class CraftWaterBarrel: Exile_AbstractCraftingRecipe
{
	name = "Craft Water Barrel";
	pictureItem = "Exile_Item_WaterBarrelKit";
	requiredInteractionModelGroup = "WorkBench";
	requiresFire = 1;
	returnedItems[] = 
	{
		{1, "Exile_Item_WaterBarrelKit"}
	};
	components[] = 
	{
		{20, "Exile_Item_PlasticBottleEmpty"}
	};
	category = "Exile Props";
};

class CraftWireFenceKit: Exile_AbstractCraftingRecipe
{
	name = "Craft Wire Fence Kit";
	pictureItem = "Exile_Item_WireFenceKit";
	requiredInteractionModelGroup = "WorkBench";
	tools[] = 
	{
		"Exile_Item_Grinder", 
		"Exile_Item_Pliers",
		"Exile_Item_Screwdriver"
	};
	returnedItems[] = 
	{
		{1, "Exile_Item_WireFenceKit"}
	};
	components[] = 
	{
		{4, "Exile_Item_MetalPole"},
		{6, "Exile_Item_MetalWire"},
		{1, "Exile_Item_MetalScrews"}
	};
	category = "Exile Props";
};

class CraftWoodDoorWay: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Doorway";
	pictureItem = "Exile_Item_WoodDoorwayKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodDoorwayKit"}
	};
	components[] = 
	{
		{6, "Exile_Item_WoodPlank"}
	};
	category = "Exile Wood";
};

class CraftWoodDrawBridge: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Draw Bridge";
	pictureItem = "Exile_Item_WoodDrawBridgeKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] =
	{
		{1, "Exile_Item_WoodDrawBridgeKit"}
	};
	components[] =
	{
		{8, "Exile_Item_WoodPlank"},
		{1, "Exile_Item_JunkMetal"},
		{1, "Exile_Item_MetalScrews"}
	};
	category = "Exile Wood";
};

class CraftWoodFloor: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Floor";
	pictureItem = "Exile_Item_WoodFloorKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodFloorKit"}
	};
	components[] = 
	{
		{4, "Exile_Item_WoodPlank"}
	};
	category = "Exile Wood";
};

class CraftWoodFloorPort: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Floor Port";
	pictureItem = "Exile_Item_WoodFloorPortKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodFloorPortKit"}
	};
	components[] = 
	{
		{6, "Exile_Item_WoodPlank"}
	};
	category = "Exile Wood";
};

class CraftWoodFloorPortSmall: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Floor Port (Small)";
	pictureItem = "Exile_Item_WoodFloorPortSmallKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] =
	{
		{1, "Exile_Item_WoodFloorPortSmallKit"}
	};
	components[] =
	{
		{6, "Exile_Item_WoodPlank"}
	};
	category = "Exile Wood";
};

class CraftWoodGate: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Gate";
	pictureItem = "Exile_Item_WoodGateKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodGateKit"}
	};
	components[] = 
	{
		{8, "Exile_Item_WoodPlank"}
	};
	category = "Exile Wood";
};

class CraftWoodLadder: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Ladder";
	pictureItem = "Exile_Item_WoodLadderKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] =
	{
		{1, "Exile_Item_WoodLadderKit"}
	};
	components[] =
	{
		{6, "Exile_Item_WoodPlank"}
	};
	category = "Exile Wood";
};

class CraftWoodPlank: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Plank";
	pictureItem = "Exile_Item_WoodPlank";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodPlank"}
	};
	components[] = 
	{
		{2, "Exile_Item_WoodLog"}
	};
	tools[] = {"Exile_Item_Handsaw"};
	category = "Exile Wood";
};

class CraftWoodStairs: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Stairs";
	pictureItem = "Exile_Item_WoodStairsKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodStairsKit"}
	};
	components[] = 
	{
		{6, "Exile_Item_WoodPlank"}
	};
	category = "Exile Wood";
};

class CraftWoodSupport: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Support";
	pictureItem = "Exile_Item_WoodSupportKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodSupportKit"}
	};
	components[] = 
	{
		{6, "Exile_Item_WoodPlank"}
	};
	category = "Exile Wood";
};

class CraftWoodWall: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Wall";
	pictureItem = "Exile_Item_WoodWallKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodWallKit"}
	};
	components[] = 
	{
		{4, "Exile_Item_WoodPlank"}
	};
	category = "Exile Wood";
};

class CraftWoodWallHalf: Exile_AbstractCraftingRecipe
{
	name = "Craft 1/2 Wood Wall";
	pictureItem = "Exile_Item_WoodWallHalfKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodWallHalfKit"}
	};
	components[] = 
	{
		{2, "Exile_Item_WoodPlank"}
	};
	category = "Exile Wood";
};

class CraftWoodWindow: Exile_AbstractCraftingRecipe
{
	name = "Craft Wood Window";
	pictureItem = "Exile_Item_WoodWindowKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodWindowKit"}
	};
	components[] = 
	{
		{6, "Exile_Item_WoodPlank"}
	};
	category = "Exile Wood";
};

class CraftWorkBench: Exile_AbstractCraftingRecipe
{
	name = "Craft Work Bench";
	pictureItem = "Exile_Item_WorkBenchKit";
	returnedItems[] = 
	{
		{1, "Exile_Item_WorkBenchKit"}
	};
	components[] = 
	{
		{4, "Exile_Item_WoodLog"}
	};
	category = "Exile Interactive";
};

///////////////////////////////////////////////////////////////////////////////

class CookAlsatianSteak: Exile_AbstractCraftingRecipe
{
	name = "Cook Alsatian Steak";
	pictureItem = "Exile_Item_AlsatianSteak_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_AlsatianSteak_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_AlsatianSteak_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookCatSharkFilet: Exile_AbstractCraftingRecipe
{
	name = "Cook Cat Shark Filet";
	pictureItem = "Exile_Item_CatSharkFilet_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_CatSharkFilet_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_CatSharkFilet_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookChickenFilet: Exile_AbstractCraftingRecipe
{
	name = "Cook Chicken Filet";
	pictureItem = "Exile_Item_ChickenFilet_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_ChickenFilet_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_ChickenFilet_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookFinSteak: Exile_AbstractCraftingRecipe
{
	name = "Cook Fin Steak";
	pictureItem = "Exile_Item_FinSteak_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_FinSteak_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_FinSteak_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookGoatSteak: Exile_AbstractCraftingRecipe
{
	name = "Cook Goat Steak";
	pictureItem = "Exile_Item_GoatSteak_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_GoatSteak_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_GoatSteak_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookMackerelFilet: Exile_AbstractCraftingRecipe
{
	name = "Cook Mackerel Filet";
	pictureItem = "Exile_Item_MackerelFilet_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_MackerelFilet_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_MackerelFilet_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookMulletFilet: Exile_AbstractCraftingRecipe
{
	name = "Cook Mullet Filet";
	pictureItem = "Exile_Item_MulletFilet_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_MulletFilet_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_MulletFilet_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookOrnateFilet: Exile_AbstractCraftingRecipe
{
	name = "Cook Ornate Filet";
	pictureItem = "Exile_Item_OrnateFilet_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_OrnateFilet_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_OrnateFilet_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookRabbitSteak: Exile_AbstractCraftingRecipe
{
	name = "Cook Rabbit Steak";
	pictureItem = "Exile_Item_RabbitSteak_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_RabbitSteak_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_RabbitSteak_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookRoosterFilet: Exile_AbstractCraftingRecipe
{
	name = "Cook Rooster Filet";
	pictureItem = "Exile_Item_RoosterFilet_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_RoosterFilet_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_RoosterFilet_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookSalemaFilet: Exile_AbstractCraftingRecipe
{
	name = "Cook Salema Filet";
	pictureItem = "Exile_Item_SalemaFilet_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_SalemaFilet_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_SalemaFilet_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookSheepSteak: Exile_AbstractCraftingRecipe
{
	name = "Cook Sheep Steak";
	pictureItem = "Exile_Item_SheepSteak_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_SheepSteak_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_SheepSteak_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookSnakeFilet: Exile_AbstractCraftingRecipe
{
	name = "Cook Snake Filet";
	pictureItem = "Exile_Item_SnakeFilet_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_SnakeFilet_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_SnakeFilet_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookTunaFilet: Exile_AbstractCraftingRecipe
{
	name = "Cook Tuna Filet";
	pictureItem = "Exile_Item_TunaFilet_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_TunaFilet_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_TunaFilet_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class CookTurtleFilet: Exile_AbstractCraftingRecipe
{
	name = "Cook Turtle Filet";
	pictureItem = "Exile_Item_TurtleFilet_Cooked";
	requiresFire = 1;
	returnedItems[] =
	{
		{1, "Exile_Item_TurtleFilet_Cooked"}
	};
	tools[] =
	{
		"Exile_Item_CookingPot"
	};
	components[] = 
	{
		{1, "Exile_Item_TurtleFilet_Raw"}
	};
	category = "Exile Food";
};

///////////////////////////////////////////////////////////////////////////////

class EmptyFuelCanister: Exile_AbstractCraftingRecipe
{
	name = "Empty Fuel Canister";
	pictureItem = "Exile_Item_FuelCanisterEmpty";
	returnedItems[] = 
	{
		{1, "Exile_Item_FuelCanisterEmpty"}
	};
	components[] = 
	{
		{1, "Exile_Item_FuelCanisterFull"}
	};
category = "Exile Misc";
};

class EmptyPlasticBottleDirtyWater: Exile_AbstractCraftingRecipe
{
	name = "Empty Dirty Water";
	pictureItem = "Exile_Item_PlasticBottleEmpty";
	returnedItems[] =
	{
		{1, "Exile_Item_PlasticBottleEmpty"}
	};
	components[] =
	{
		{1, "Exile_Item_PlasticBottleDirtyWater"}
	};
category = "Exile Misc";
};

class EmptyPlasticBottleSaltWater: Exile_AbstractCraftingRecipe
{
	name = "Empty Salt Water";
	pictureItem = "Exile_Item_PlasticBottleEmpty";
	returnedItems[] =
	{
		{1, "Exile_Item_PlasticBottleEmpty"}
	};
	components[] =
	{
		{1, "Exile_Item_PlasticBottleSaltWater"}
	};
category = "Exile Misc";
};

class FillEmptyPlasticBottleWithDirtyWater: Exile_AbstractCraftingRecipe
{
	name = "Fill Dirty Water";
	pictureItem = "Exile_Item_PlasticBottleDirtyWater";
	requiredInteractionModelGroup = "WaterSource";
	returnedItems[] =
	{
		{1, "Exile_Item_PlasticBottleDirtyWater"}
	};
	components[] = 
	{
		{1, "Exile_Item_PlasticBottleEmpty"}
	};
category = "Exile Misc";
};

class FillEmptyPlasticBottleWithFreshWater: Exile_AbstractCraftingRecipe
{
	name = "Fill Fresh Water";
	pictureItem = "Exile_Item_PlasticBottleFreshWater";
	requiredInteractionModelGroup = "CleanWaterSource";
	returnedItems[] =
	{
		{1, "Exile_Item_PlasticBottleFreshWater"}
	};
	components[] = 
	{
		{1, "Exile_Item_PlasticBottleEmpty"}
	};
	category = "Exile Drink";
};

class FillEmptyPlasticBottleWithSaltWater: Exile_AbstractCraftingRecipe
{
	name = "Fill Salt Water";
	pictureItem = "Exile_Item_PlasticBottleSaltWater";
	requiresOcean = 1;
	returnedItems[] = 
	{
		{1, "Exile_Item_PlasticBottleSaltWater"}
	};
	components[] = 
	{
		{1, "Exile_Item_PlasticBottleEmpty"}
	};
category = "Exile Misc";
};

class FillEmptyWaterCanisterWithDirtyWater: Exile_AbstractCraftingRecipe
{
	name = "Fill Dirty Water";
	pictureItem = "Exile_Item_WaterCanisterDirtyWater";
	requiredInteractionModelGroup = "WaterSource";
	returnedItems[] =
	{
		{1, "Exile_Item_WaterCanisterDirtyWater"}
	};
	components[] = 
	{
		{1, "Exile_Item_WaterCanisterEmpty"}
	};
category = "Exile Misc";
};

class FillFuelCanister: Exile_AbstractCraftingRecipe
{
	name = "Fill Fuel Canister";
	pictureItem = "Exile_Item_FuelCanisterFull";
	requiredInteractionModelGroup = "FuelSource";
	returnedItems[] = 
	{
		{1, "Exile_Item_FuelCanisterFull"}
	};
	components[] = 
	{
		{1, "Exile_Item_FuelCanisterEmpty"}
	};
category = "Exile Misc";
};

class UpgradeToConcreteDoor: Exile_AbstractCraftingRecipe
{
	name = "Upgrade to Concrete Door";
	pictureItem = "Exile_Item_ConcreteDoorKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_ConcreteDoorKit"}
	};
	components[] = 
	{
		{1, "Exile_Item_ConcreteDoorwayKit"},
		{2, "Exile_Item_MetalPole"},
		{4, "Exile_Item_MetalBoard"}
	};
	category = "Exile Upgrades";
};

class UpgradeToConcreteFloorPort: Exile_AbstractCraftingRecipe
{
	name = "Upgrade to Concrete Floor Port";
	pictureItem = "Exile_Item_ConcreteFloorPortKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_ConcreteFloorPortKit"}
	};
	components[] = 
	{
		{1, "Exile_Item_ConcreteFloorKit"},
		{2, "Exile_Item_MetalPole"},
		{4, "Exile_Item_MetalBoard"}
	};
	category = "Exile Upgrades";
};

class UpgradeToConcreteGate: Exile_AbstractCraftingRecipe
{
	name = "Upgrade to Concrete Gate";
	pictureItem = "Exile_Item_ConcreteGateKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_ConcreteGateKit"}
	};
	components[] = 
	{
		{1, "Exile_Item_ConcreteWallKit"},
		{2, "Exile_Item_MetalPole"},
		{4, "Exile_Item_MetalBoard"}
	};
	category = "Exile Upgrades";
};

class UpgradeToConcreteWindow: Exile_AbstractCraftingRecipe
{
	name = "Upgrade to Concrete Window";
	pictureItem = "Exile_Item_ConcreteWindowKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_ConcreteWindowKit"}
	};
	components[] = 
	{
		{1, "Exile_Item_ConcreteWallKit"},
		{2, "Exile_Item_MetalPole"},
		{4, "Exile_Item_MetalBoard"}
	};
	category = "Exile Upgrades";
};

class UpgradeToWoodDoor: Exile_AbstractCraftingRecipe
{
	name = "Upgrade to Wood Door";
	pictureItem = "Exile_Item_WoodDoorKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodDoorKit"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodDoorwayKit"},
		{2, "Exile_Item_WoodPlank"}
	};
	category = "Exile Upgrades";
};

class UpgradeToWoodDrawBridge: Exile_AbstractCraftingRecipe
{
	name = "Upgrade to Wood Draw Bridge";
	pictureItem = "Exile_Item_WoodDrawBridgeKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] =
	{
		{1, "Exile_Item_WoodDrawBridgeKit"}
	};
	components[] =
	{
		{1, "Exile_Item_WoodGateKit"},
		{2, "Exile_Item_WoodPlank"},
		{1, "Exile_Item_JunkMetal"},
		{1, "Exile_Item_MetalScrews"}
	};
	category = "Exile Upgrades";
};

class UpgradeToWoodFloorPort: Exile_AbstractCraftingRecipe
{
	name = "Upgrade to Wood Floor Port";
	pictureItem = "Exile_Item_WoodFloorPortKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodFloorPortKit"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodFloorKit"},
		{2, "Exile_Item_WoodPlank"}
	};
	category = "Exile Upgrades";
};

class UpgradeToWoodGate: Exile_AbstractCraftingRecipe
{
	name = "Upgrade to Wood Gate";
	pictureItem = "Exile_Item_WoodGateKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodGateKit"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodWallKit"},
		{4, "Exile_Item_WoodPlank"}
	};
	category = "Exile Upgrades";
};

class UpgradeToWoodWall: Exile_AbstractCraftingRecipe
{
	name = "Upgrade to Wood Wall";
	pictureItem = "Exile_Item_WoodWallHalfKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodWallKit"}
	};
	components[] = 
	{
		{2, "Exile_Item_WoodWallHalfKit"}
	};
	category = "Exile Upgrades";
};

class UpgradeToWoodWindow: Exile_AbstractCraftingRecipe
{
	name = "Upgrade to Wood Window";
	pictureItem = "Exile_Item_WoodWindowKit";
	requiredInteractionModelGroup = "WorkBench";
	returnedItems[] = 
	{
		{1, "Exile_Item_WoodWindowKit"}
	};
	components[] = 
	{
		{1, "Exile_Item_WoodWallKit"},
		{2, "Exile_Item_WoodPlank"}
	};
	category = "Exile Upgrades";
};
};

class CfgExileAnimals
{
	/**
	 * Should animals spawn on your server? Y/N?
	 */
	enabled = 1;

	/**
	 * Should vanilla Arma animals (fish, rabbits, bees, etc.) be disabled?
	 * We think it should, since it might confuse players if they cant eat them. *munches on bees*
	 */
	disableVanillaAnimals = 0;

	/**
	 * Which animals to spawn. 
	 * Exile automatically spawns a color variation of that animal, if variations exist.
	 * Each player (client) has a maximum of one animal at a time.
	 * Exile checks which animal type can spawn in front of the player and then
	 * picks a random one. 
	 *
	 * For now it is like this:
	 * 
	 * - Goats spawn on hill tops, but not in forests
	 * - Sheep spawn on meadows, but not next to forests and not on hill tops
	 * - Hens and roosters spawn next to buildings only
	 *
	 * => More animal types will follow in upcoming Exile versions, hopefully.
	 */
	animalTypes[] = 
	{
		"Exile_Animal_Rooster_Abstract",
		"Exile_Animal_Hen_Abstract",
		"Exile_Animal_Goat_Abstract",
		"Exile_Animal_Sheep_Abstract"
	};

	/**
	 * Animals are always spawned in front of the player, but
	 * at least a certain distance away. The radius is applied on top.
	 *
	 * Example:
	 * Distance = 150
	 * Radius = 50
	 *
	 * => Minimum Distance from Player = 150 
	 * => Maximum Distance from Player = 150 + 50 * 2
	 */
	spawnDistance = 150;
	spawnRadius = 50;

	/**
	 * Specifies the minimum time in seconds between spawning animals.
	 * When the animal diededed, this time has to pass before it spawns
	 * a new one.
	 *
	 * It is a min/max setting, so the intervals will be uneven and a bit random.
	 * By default it will take 5 to 10 minutes to respawn a new animal.
	 */
	minimumSpawnDelay = 5 * 60;
	maximumSpawnDelay = 10 * 60;

	/**
	 * Clients will despawn animals if no player is in this radius around the animal
	 * This check is ran every 1 minute, so it is pretty unprecise, but performance-friendly. 
	 */
	keepAliveRadius = 500;

	/**
	 * Defines the minimum lifetime of an animal in seconds. During this time, right after spawning,
	 * it will not despawn. (+-0..1 minute delay)
	 */
	minimumLifetime = 5 * 60;
};

class CfgExileArsenal
{
	#include "addons\EBM\prices.hpp"
	#include "addons\NIA\prices.hpp"
	#include "addons\COG\prices.hpp"
	#include "addons\TRYK\prices.hpp"
	class Exile_Uniform_BambiOverall				{ quality = 1; price = 1; sellPrice = 1; };

	///////////////////////////////////////////////////////////////////////////////
	// Civillian Clothing
	///////////////////////////////////////////////////////////////////////////////
	class U_C_Journalist 															{ quality = 1; price = 20; };
	class U_C_Poloshirt_blue 													{ quality = 1; price = 20; };
	class U_C_Poloshirt_burgundy 											{ quality = 1; price = 20; };
	class U_C_Poloshirt_salmon 												{ quality = 1; price = 20; };
	class U_C_Poloshirt_stripped 											{ quality = 1; price = 20; };
	class U_C_Poloshirt_tricolour 										{ quality = 1; price = 20; };
	class U_C_Poor_1 																	{ quality = 1; price = 20; };
	class U_C_Poor_2 																	{ quality = 1; price = 20; };
	class U_C_Poor_shorts_1 													{ quality = 1; price = 20; };
	class U_OrestesBody 															{ quality = 1; price = 40; };
	class U_Rangemaster 															{ quality = 1; price = 40; };
	class U_NikosAgedBody 														{ quality = 1; price = 40; };
	class U_NikosBody 																{ quality = 1; price = 40; };
	class U_Competitor 																{ quality = 1; price = 40; };

	///////////////////////////////////////////////////////////////////////////////
	// Soldier Uniforms
	///////////////////////////////////////////////////////////////////////////////
	class U_B_CombatUniform_mcam 											{ quality = 2; price = 40; };
	class U_B_CombatUniform_mcam_tshirt 							{ quality = 2; price = 40; };
	class U_B_CombatUniform_mcam_vest 								{ quality = 2; price = 40; };
	class U_B_CombatUniform_mcam_worn 								{ quality = 2; price = 40; };
	class U_B_CTRG_1 																	{ quality = 2; price = 40; };
	class U_B_CTRG_2 																	{ quality = 2; price = 40; };
	class U_B_CTRG_3																	{ quality = 2; price = 40; };
	class U_I_CombatUniform 													{ quality = 2; price = 40; };
	class U_I_CombatUniform_shortsleeve								{ quality = 2; price = 40; };
	class U_I_CombatUniform_tshirt										{ quality = 2; price = 40; };
	class U_I_OfficerUniform													{ quality = 2; price = 40; };
	class U_O_CombatUniform_ocamo 										{ quality = 2; price = 40; };
	class U_O_CombatUniform_oucamo 										{ quality = 2; price = 40; };
	class U_O_OfficerUniform_ocamo 										{ quality = 3; price = 80; };
	class U_B_SpecopsUniform_sgg 											{ quality = 3; price = 80; };
	class U_O_SpecopsUniform_blk 											{ quality = 3; price = 80; };
	class U_O_SpecopsUniform_ocamo 										{ quality = 3; price = 80; };
	class U_I_G_Story_Protagonist_F 									{ quality = 3; price = 100; };
	class Exile_Uniform_Woodland 											{ quality = 3; price = 150; };

	///////////////////////////////////////////////////////////////////////////////
	// Guerilla Uniforms
	///////////////////////////////////////////////////////////////////////////////
	class U_C_HunterBody_grn													{ quality = 2; price = 40; };
	class U_IG_Guerilla1_1														{ quality = 2; price = 40; };
	class U_IG_Guerilla2_1														{ quality = 2; price = 60; };
	class U_IG_Guerilla2_2														{ quality = 2; price = 40; };
	class U_IG_Guerilla2_3														{ quality = 2; price = 40; };
	class U_IG_Guerilla3_1														{ quality = 2; price = 40; };
	class U_BG_Guerilla2_1														{ quality = 2; price = 40; };
	class U_IG_Guerilla3_2														{ quality = 2; price = 40; };
	class U_BG_Guerrilla_6_1													{ quality = 2; price = 60; };
	class U_BG_Guerilla1_1														{ quality = 2; price = 40; };
	class U_BG_Guerilla2_2														{ quality = 2; price = 40; };
	class U_BG_Guerilla2_3														{ quality = 2; price = 40; };
	class U_BG_Guerilla3_1														{ quality = 2; price = 40; };
	class U_BG_leader																	{ quality = 3; price = 40; };
	class U_IG_leader																	{ quality = 3; price = 40; };
	class U_I_G_resistanceLeader_F										{ quality = 3; price = 100; };

	///////////////////////////////////////////////////////////////////////////////
	// Ghillie Suits
	///////////////////////////////////////////////////////////////////////////////
	class U_B_FullGhillie_lsh												{ quality = 5; price = 150; };
	class U_I_FullGhillie_lsh												{ quality = 5; price = 150; };
	class U_O_FullGhillie_lsh												{ quality = 5; price = 150; };
	class U_B_FullGhillie_sard											{ quality = 5; price = 150; };
	class U_I_FullGhillie_sard											{ quality = 5; price = 150; };
	class U_O_FullGhillie_sard											{ quality = 5; price = 150; };
	class U_B_FullGhillie_ard												{ quality = 5; price = 150; };
	class U_I_FullGhillie_ard												{ quality = 5; price = 150; };
	class U_O_FullGhillie_ard												{ quality = 5; price = 150; };
	class U_B_GhillieSuit														{ quality = 4; price = 100; };
	class U_I_GhillieSuit														{ quality = 4; price = 100; };
	class U_O_GhillieSuit														{ quality = 4; price = 100; };

	///////////////////////////////////////////////////////////////////////////////
	// Wet Suits
	///////////////////////////////////////////////////////////////////////////////
	class U_I_Wetsuit																	{ quality = 3; price = 80; };
	class U_O_Wetsuit																	{ quality = 3; price = 80; };
	class U_B_Wetsuit																	{ quality = 3; price = 80; };
	class U_B_survival_uniform												{ quality = 3; price = 80; };

	///////////////////////////////////////////////////////////////////////////////
	// VR Suits
	///////////////////////////////////////////////////////////////////////////////
	class U_I_Protagonist_VR												{ quality = 6; price = 2500; };
	class U_O_Protagonist_VR												{ quality = 6; price = 2500; };
	class U_B_Protagonist_VR												{ quality = 6; price = 2500; };

	///////////////////////////////////////////////////////////////////////////////
	// Bandolliers
	///////////////////////////////////////////////////////////////////////////////
	class V_BandollierB_blk														{ quality = 1; price = 20; };
	class V_BandollierB_cbr														{ quality = 1; price = 20; };
	class V_BandollierB_khk														{ quality = 1; price = 20; };
	class V_BandollierB_oli														{ quality = 1; price = 20; };
	class V_BandollierB_rgr														{ quality = 1; price = 20; };

	///////////////////////////////////////////////////////////////////////////////
	// Chestrigs
	///////////////////////////////////////////////////////////////////////////////
	class V_Chestrig_blk														{ quality = 1; price = 30; };
	class V_Chestrig_khk														{ quality = 1; price = 30; };
	class V_Chestrig_oli														{ quality = 1; price = 30; };
	class V_Chestrig_rgr														{ quality = 1; price = 30; };

	///////////////////////////////////////////////////////////////////////////////
	// Vests
	///////////////////////////////////////////////////////////////////////////////
	class V_Press_F																		{ quality = 1; price = 10; };
	class V_Rangemaster_belt													{ quality = 1; price = 6; };
	class V_TacVest_blk																{ quality = 2; price = 50; };
	class V_TacVest_blk_POLICE												{ quality = 3; price = 50; };
	class V_TacVest_brn																{ quality = 2; price = 50; };
	class V_TacVest_camo															{ quality = 2; price = 50; };
	class V_TacVest_khk																{ quality = 2; price = 50; };
	class V_TacVest_oli																{ quality = 2; price = 50; };
	class V_TacVestCamo_khk														{ quality = 2; price = 50; };
	class V_TacVestIR_blk															{ quality = 2; price = 50; };
	class V_I_G_resistanceLeader_F										{ quality = 2; price = 50; };

	///////////////////////////////////////////////////////////////////////////////
	// Harnesses
	///////////////////////////////////////////////////////////////////////////////
	class V_HarnessO_brn															{ quality = 1; price = 40; };
	class V_HarnessO_gry															{ quality = 1; price = 40; };
	class V_HarnessOGL_brn														{ quality = 1; price = 30; };
	class V_HarnessOGL_gry														{ quality = 1; price = 30; };
	class V_HarnessOSpec_brn													{ quality = 1; price = 40; };
	class V_HarnessOSpec_gry													{ quality = 1; price = 40; };

	///////////////////////////////////////////////////////////////////////////////
	// Plate Carriers
	///////////////////////////////////////////////////////////////////////////////
	class V_PlateCarrier1_blk													{ quality = 1; price = 80; };
	class V_PlateCarrier1_rgr													{ quality = 1; price = 80; };
	class V_PlateCarrier2_rgr													{ quality = 2; price = 100; };
	class V_PlateCarrier3_rgr													{ quality = 2; price = 100; };
	class V_PlateCarrierGL_blk												{ quality = 6; price = 500; };
	class V_PlateCarrierGL_mtp												{ quality = 6; price = 500; };
	class V_PlateCarrierGL_rgr												{ quality = 6; price = 500; };
	class V_PlateCarrierH_CTRG												{ quality = 2; price = 100; };
	class V_PlateCarrierIA1_dgtl											{ quality = 2; price = 80; };
	class V_PlateCarrierIA2_dgtl											{ quality = 2; price = 100; };
	class V_PlateCarrierIAGL_dgtl											{ quality = 3; price = 400; };
	class V_PlateCarrierIAGL_oli											{ quality = 3; price = 400; };
	class V_PlateCarrierL_CTRG												{ quality = 2; price = 100; };
	class V_PlateCarrierSpec_blk											{ quality = 5; price = 200; };
	class V_PlateCarrierSpec_mtp											{ quality = 5; price = 200; };
	class V_PlateCarrierSpec_rgr											{ quality = 5; price = 200; };

	///////////////////////////////////////////////////////////////////////////////
	// Caps
	///////////////////////////////////////////////////////////////////////////////
	class H_Cap_blk 																	{ quality = 1; price = 6; };
	class H_Cap_blk_Raven 														{ quality = 1; price = 6; };
	class H_Cap_blu 																	{ quality = 1; price = 6; };
	class H_Cap_brn_SPECOPS 													{ quality = 1; price = 6; };
	class H_Cap_grn 																	{ quality = 1; price = 6; };
	class H_Cap_headphones 														{ quality = 1; price = 6; };
	class H_Cap_khaki_specops_UK 											{ quality = 1; price = 6; };
	class H_Cap_oli 																	{ quality = 1; price = 6; };
	class H_Cap_press 																{ quality = 1; price = 6; };
	class H_Cap_red 																	{ quality = 1; price = 6; };
	class H_Cap_tan 																	{ quality = 1; price = 6; };
	class H_Cap_tan_specops_US 												{ quality = 1; price = 6; };

	///////////////////////////////////////////////////////////////////////////////
	// Glasses
	///////////////////////////////////////////////////////////////////////////////
	class G_Spectacles 																	{ quality = 1; price = 6; };
	class G_Spectacles_Tinted 													{ quality = 1; price = 6; };
	class G_Combat 																			{ quality = 1; price = 6; };
	class G_Lowprofile 																	{ quality = 1; price = 6; };
	class G_Shades_Black 																{ quality = 1; price = 6; };
	class G_Shades_Green 																{ quality = 1; price = 6; };
	class G_Shades_Red 																	{ quality = 1; price = 6; };
	class G_Squares 																		{ quality = 1; price = 6; };
	class G_Squares_Tinted 															{ quality = 1; price = 6; };
	class G_Sport_BlackWhite 														{ quality = 1; price = 6; };
	class G_Sport_Blackyellow 													{ quality = 1; price = 6; };
	class G_Sport_Greenblack 														{ quality = 1; price = 6; };
	class G_Sport_Checkered 														{ quality = 1; price = 6; };
	class G_Sport_Red 																	{ quality = 1; price = 6; };
	class G_Tactical_Black 															{ quality = 1; price = 6; };
	class G_Aviator 																		{ quality = 1; price = 6; };
	class G_Lady_Mirror 																{ quality = 1; price = 6; };
	class G_Lady_Dark 																	{ quality = 1; price = 6; };
	class G_Lady_Red 																		{ quality = 1; price = 6; };
	class G_Lady_Blue 																	{ quality = 1; price = 6; };
	class G_Diving 																			{ quality = 1; price = 6; };
	class G_B_Diving 																		{ quality = 1; price = 6; };
	class G_O_Diving 																		{ quality = 1; price = 6; };
	class G_I_Diving 																		{ quality = 1; price = 6; };
	class G_Goggles_VR 																	{ quality = 1; price = 6; };
	class G_Balaclava_blk 															{ quality = 2; price = 10; };
	class G_Balaclava_oli 															{ quality = 2; price = 10; };
	class G_Balaclava_combat 														{ quality = 2; price = 10; };
	class G_Balaclava_lowprofile 												{ quality = 2; price = 10; };
	class G_Bandanna_blk 																{ quality = 1; price = 6; };
	class G_Bandanna_oli 																{ quality = 1; price = 6; };
	class G_Bandanna_khk 																{ quality = 1; price = 6; };
	class G_Bandanna_tan 																{ quality = 1; price = 6; };
	class G_Bandanna_beast 															{ quality = 1; price = 6; };
	class G_Bandanna_shades 														{ quality = 1; price = 6; };
	class G_Bandanna_sport 															{ quality = 1; price = 6; };
	class G_Bandanna_aviator 														{ quality = 1; price = 6; };
	class G_Shades_Blue 																{ quality = 1; price = 6; };
	class G_Sport_Blackred 															{ quality = 1; price = 6; };
	class G_Tactical_Clear 															{ quality = 1; price = 6; };
	class G_Balaclava_TI_blk_F 													{ quality = 2; price = 15; };
	class G_Balaclava_TI_tna_F 													{ quality = 2; price = 15; };
	class G_Balaclava_TI_G_blk_F 												{ quality = 2; price = 15; };
	class G_Balaclava_TI_G_tna_F 												{ quality = 2; price = 15; };
	class G_Combat_Goggles_tna_F 												{ quality = 1; price = 6; };

	///////////////////////////////////////////////////////////////////////////////
	// Military Caps
	///////////////////////////////////////////////////////////////////////////////
	class H_MilCap_blue 															{ quality = 1; price = 8; };
	class H_MilCap_dgtl 															{ quality = 1; price = 8; };
	class H_MilCap_mcamo 															{ quality = 1; price = 8; };
	class H_MilCap_ocamo 															{ quality = 1; price = 8; };
	class H_MilCap_oucamo 														{ quality = 1; price = 8; };
	class H_MilCap_rucamo 														{ quality = 1; price = 8; };

	///////////////////////////////////////////////////////////////////////////////
	// Beanies
	///////////////////////////////////////////////////////////////////////////////
	class H_Watchcap_blk 															{ quality = 1; price = 6; };
	class H_Watchcap_camo 														{ quality = 1; price = 6; };
	class H_Watchcap_khk 															{ quality = 1; price = 6; };
	class H_Watchcap_sgg 															{ quality = 1; price = 6; };

	///////////////////////////////////////////////////////////////////////////////
	// Bandannas
	///////////////////////////////////////////////////////////////////////////////
	class H_Bandanna_camo 														{ quality = 1; price = 4; };
	class H_Bandanna_cbr 															{ quality = 1; price = 4; };
	class H_Bandanna_gry 															{ quality = 1; price = 4; };
	class H_Bandanna_khk 															{ quality = 1; price = 4; };
	class H_Bandanna_khk_hs 													{ quality = 1; price = 4; };
	class H_Bandanna_mcamo 														{ quality = 1; price = 4; };
	class H_Bandanna_sgg 															{ quality = 1; price = 4; };
	class H_Bandanna_surfer 													{ quality = 1; price = 4; };

	///////////////////////////////////////////////////////////////////////////////
	// Boonie Hats
	///////////////////////////////////////////////////////////////////////////////
	class H_Booniehat_dgtl 															{ quality = 1; price = 6; };
	class H_Booniehat_dirty 														{ quality = 1; price = 6; };
	class H_Booniehat_grn 															{ quality = 1; price = 6; };
	class H_Booniehat_indp 															{ quality = 1; price = 6; };
	class H_Booniehat_khk 															{ quality = 1; price = 6; };
	class H_Booniehat_khk_hs 														{ quality = 1; price = 6; };
	class H_Booniehat_mcamo 														{ quality = 1; price = 6; };
	class H_Booniehat_tan 															{ quality = 1; price = 6; };

	///////////////////////////////////////////////////////////////////////////////
	// Hats
	///////////////////////////////////////////////////////////////////////////////
	class H_Hat_blue 																	{ quality = 1; price = 6; };
	class H_Hat_brown 																{ quality = 1; price = 6; };
	class H_Hat_camo 																	{ quality = 1; price = 6; };
	class H_Hat_checker 															{ quality = 1; price = 6; };
	class H_Hat_grey 																	{ quality = 1; price = 6; };
	class H_Hat_tan 																	{ quality = 1; price = 6; };
	class H_StrawHat 																	{ quality = 1; price = 6; };
	class H_StrawHat_dark 														{ quality = 1; price = 6; };

	///////////////////////////////////////////////////////////////////////////////
	// Berets
	///////////////////////////////////////////////////////////////////////////////
	class H_Beret_02 																	{ quality = 2; price = 6; };
	class H_Beret_blk 																{ quality = 2; price = 6; };
	class H_Beret_blk_POLICE 													{ quality = 2; price = 6; };
	class H_Beret_brn_SF 															{ quality = 2; price = 6; };
	class H_Beret_Colonel 														{ quality = 3; price = 8; };
	class H_Beret_grn 																{ quality = 2; price = 6; };
	class H_Beret_grn_SF 															{ quality = 2; price = 6; };
	class H_Beret_ocamo 															{ quality = 2; price = 6; };
	class H_Beret_red 																{ quality = 2; price = 6; };

	///////////////////////////////////////////////////////////////////////////////
	// Shemags
	///////////////////////////////////////////////////////////////////////////////
	class H_Shemag_khk 																{ quality = 1; price = 10; };
	class H_Shemag_olive 															{ quality = 1; price = 10; };
	class H_Shemag_olive_hs 													{ quality = 1; price = 10; };
	class H_Shemag_tan 																{ quality = 1; price = 10; };
	class H_ShemagOpen_khk 														{ quality = 1; price = 10; };
	class H_ShemagOpen_tan 														{ quality = 1; price = 10; };
	class H_TurbanO_blk 															{ quality = 1; price = 10; };

	///////////////////////////////////////////////////////////////////////////////
	// Light Helmets
	///////////////////////////////////////////////////////////////////////////////
	class H_HelmetB_light															{ quality = 2; price = 20; };
	class H_HelmetB_light_black												{ quality = 2; price = 20; };
	class H_HelmetB_light_desert											{ quality = 2; price = 20; };
	class H_HelmetB_light_grass												{ quality = 2; price = 20; };
	class H_HelmetB_light_sand												{ quality = 2; price = 20; };
	class H_HelmetB_light_snakeskin										{ quality = 2; price = 20; };

	///////////////////////////////////////////////////////////////////////////////
	// Helmets
	///////////////////////////////////////////////////////////////////////////////
	class H_HelmetIA																	{ quality = 3; price = 40; };
	class H_HelmetIA_camo															{ quality = 3; price = 40; };
	class H_HelmetIA_net															{ quality = 3; price = 40; };
	class H_HelmetB																		{ quality = 3; price = 60; };
	class H_HelmetB_black															{ quality = 3; price = 60; };
	class H_HelmetB_camo															{ quality = 3; price = 80; }; // This one is awesome!
	class H_HelmetB_desert														{ quality = 3; price = 60; };
	class H_HelmetB_grass															{ quality = 3; price = 60; };
	class H_HelmetB_paint															{ quality = 3; price = 60; };
	class H_HelmetB_plain_blk													{ quality = 3; price = 60; };
	class H_HelmetB_sand															{ quality = 3; price = 60; };
	class H_HelmetB_snakeskin													{ quality = 3; price = 60; };

	///////////////////////////////////////////////////////////////////////////////
	// Spec Ops Helmets
	///////////////////////////////////////////////////////////////////////////////
	class H_HelmetSpecB																{ quality = 4; price = 80; };
	class H_HelmetSpecB_blk														{ quality = 4; price = 80; };
	class H_HelmetSpecB_paint1												{ quality = 4; price = 80; };
	class H_HelmetSpecB_paint2												{ quality = 4; price = 80; };

	///////////////////////////////////////////////////////////////////////////////
	// Super Helmets
	///////////////////////////////////////////////////////////////////////////////
	class H_HelmetO_ocamo														{ quality = 5; price = 150; };
	class H_HelmetO_oucamo													{ quality = 5; price = 150; };
	class H_HelmetSpecO_blk													{ quality = 5; price = 100; };
	class H_HelmetSpecO_ocamo												{ quality = 5; price = 100; };
	class H_HelmetLeaderO_ocamo											{ quality = 5; price = 200; };
	class H_HelmetLeaderO_oucamo										{ quality = 5; price = 200; };

	///////////////////////////////////////////////////////////////////////////////
	// Pointer Attachments
	///////////////////////////////////////////////////////////////////////////////
	class acc_flashlight 															{ quality = 1; price = 4; };
	class acc_pointer_IR 															{ quality = 1; price = 10; };

	///////////////////////////////////////////////////////////////////////////////
	// Bipod Attachments
	///////////////////////////////////////////////////////////////////////////////
	class bipod_01_F_blk	 														{ quality = 2; price = 10; };
	class bipod_01_F_mtp	 														{ quality = 2; price = 10; };
	class bipod_01_F_snd	 														{ quality = 2; price = 10; };
	class bipod_02_F_blk	 														{ quality = 2; price = 10; };
	class bipod_02_F_hex	 														{ quality = 2; price = 10; };
	class bipod_02_F_tan	 														{ quality = 2; price = 10; };
	class bipod_03_F_blk	 														{ quality = 2; price = 10; };
	class bipod_03_F_oli	 														{ quality = 2; price = 10; };

	///////////////////////////////////////////////////////////////////////////////
	// Muzzle Attachments
	///////////////////////////////////////////////////////////////////////////////
	class muzzle_snds_338_black 											{ quality = 5; price = 50; };
	class muzzle_snds_338_green 											{ quality = 5; price = 50; };
	class muzzle_snds_338_sand 												{ quality = 5; price = 50; };
	class muzzle_snds_93mmg 													{ quality = 4; price = 50; };
	class muzzle_snds_93mmg_tan 											{ quality = 4; price = 50; };
	class muzzle_snds_acp 														{ quality = 1; price = 10; };
	class muzzle_snds_B 															{ quality = 3; price = 20; };
	class muzzle_snds_H 															{ quality = 2; price = 20; };
	class muzzle_snds_H_MG 														{ quality = 2; price = 20; };
	class muzzle_snds_H_SW 														{ quality = 2; price = 20; };
	class muzzle_snds_L 															{ quality = 1; price = 10; };
	class muzzle_snds_M 															{ quality = 1; price = 10; };

	///////////////////////////////////////////////////////////////////////////////
	// UAVS
	///////////////////////////////////////////////////////////////////////////////
	class I_UavTerminal															{ quality = 4; price = 750; };
	class I_UAV_01_backpack_F												{ quality = 4; price = 3000; };
	class O_UAV_01_backpack_F												{ quality = 4; price = 3000; };
	class B_UAV_01_backpack_F												{ quality = 4; price = 3000; };

	///////////////////////////////////////////////////////////////////////////////
	// UGVS
	///////////////////////////////////////////////////////////////////////////////
	class B_UGV_01_F																{ quality = 6; price = 20000; };// Stomper (BLUFOR)
	class I_UGV_01_F																{ quality = 6; price = 20000; };// Stomper (IND)
	class O_UGV_01_F																{ quality = 6; price = 20000; };// Saif (OPFOR)
	class O_T_UGV_01_ghex_F													{ quality = 6; price = 20000; };// Saif GHEX (OPFOR)

	///////////////////////////////////////////////////////////////////////////////
	// Static MGs
	///////////////////////////////////////////////////////////////////////////////
	class O_HMG_01_weapon_F 												{ quality = 4; price = 5000; };
	class O_HMG_01_support_F 												{ quality = 4; price = 1000; };
	class I_HMG_01_high_weapon_F 										{ quality = 4; price = 5000; };
	class I_HMG_01_support_high_F 									{ quality = 4; price = 1000; };
	class O_HMG_01_high_weapon_F 										{ quality = 4; price = 5000; };
	class O_HMG_01_support_high_F 									{ quality = 4; price = 1000; };
	class B_HMG_01_high_weapon_F 										{ quality = 4; price = 5000; };
	class B_HMG_01_support_high_F 									{ quality = 4; price = 1000; };
	// Does not seem to work with HMG01, only the lower version does
	//class O_HMG_01_support_high_F 				{ quality = QUALITY_LEVEL_9000; price = 5000; };

	///////////////////////////////////////////////////////////////////////////////
	// Static MG Ammo
	///////////////////////////////////////////////////////////////////////////////
	class 500Rnd_127x99_mag_Tracer_Green 						{ quality = 4; price = 200; };
	class 500Rnd_127x99_mag_Tracer_Yellow 					{ quality = 4; price = 200; };
	class 500Rnd_127x99_mag_Tracer_Red 							{ quality = 4; price = 200; };

	///////////////////////////////////////////////////////////////////////////////
	// Optic Attachments
	///////////////////////////////////////////////////////////////////////////////
	class optic_Aco																		{ quality = 1; price = 70; };
	class optic_ACO_grn																{ quality = 1; price = 70; };
	class optic_ACO_grn_smg														{ quality = 1; price = 70; };
	class optic_Aco_smg																{ quality = 1; price = 70; };
	class optic_AMS																		{ quality = 5; price = 300; };
	class optic_AMS_khk																{ quality = 5; price = 300; };
	class optic_AMS_snd																{ quality = 5; price = 300; };
	class optic_Arco																	{ quality = 1; price = 100; };
	class optic_DMS																		{ quality = 2; price = 150; };
	class optic_Hamr																	{ quality = 3; price = 200; };
	class optic_Holosight															{ quality = 1; price = 50; };
	class optic_Holosight_smg													{ quality = 1; price = 50; };
	class optic_KHS_blk																{ quality = 4; price = 300; };
	class optic_KHS_hex																{ quality = 4; price = 300; };
	class optic_KHS_old																{ quality = 4; price = 300; };
	class optic_KHS_tan																{ quality = 4; price = 300; };
	class optic_LRPS																	{ quality = 5; price = 300; };
	class optic_MRCO																	{ quality = 1; price = 100; };
	class optic_MRD																		{ quality = 1; price = 10; };
	class optic_Nightstalker													{ quality = 6; price = 1000; };
	class optic_NVS																		{ quality = 4; price = 500; };
	class optic_SOS																		{ quality = 2; price = 200; };
	class optic_Yorris																{ quality = 1; price = 10; };

	///////////////////////////////////////////////////////////////////////////////
	// Hardware
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Item_Rope															{ quality = 1; price = 20; };
	class Exile_Item_DuctTape													{ quality = 1; price = 300; };
	class Exile_Item_ExtensionCord										{ quality = 1; price = 40; };
	class Exile_Item_FuelCanisterEmpty								{ quality = 1; price = 40; };
	class Exile_Item_WaterCanisterEmpty								{ quality = 1; price = 40; };
	class Exile_Item_JunkMetal												{ quality = 1; price = 400; };
	class Exile_Item_LightBulb												{ quality = 1; price = 20; };
	class Exile_Item_MetalBoard												{ quality = 1; price = 600; };
	class Exile_Item_SafeKit													{ quality = 4; price = 25000; };
	class Exile_Item_CodeLock													{ quality = 1; price = 5000; };
	class Exile_Item_Laptop														{ quality = 2; price = 9000; };
	class Exile_Item_BaseCameraKit										{ quality = 2; price = 5000; };
	class Exile_Item_CamoTentKit											{ quality = 1; price = 250; };
	class Exile_Item_MetalPole												{ quality = 1; price = 800; };
	class Exile_Item_MetalScrews											{ quality = 1; price = 100; };
	class Exile_Item_MetalWire												{ quality = 1; price = 100; };
	class Exile_Item_Cement														{ quality = 1; price = 20; };
	class Exile_Item_Sand															{ quality = 1; price = 20; };
	//class Exile_Item_CarWheel												{ quality = 1; price = 1000; };
	
	// Added in 1.0.3, but not used
	//class Exile_Item_SprayCan_Black									{ quality = 2; price = 20; };
	//class Exile_Item_SprayCan_Red										{ quality = 2; price = 20; };
	//class Exile_Item_SprayCan_Green									{ quality = 2; price = 20; };
	//class Exile_Item_SprayCan_White									{ quality = 2; price = 20; };
	//class Exile_Item_SprayCan_Blue									{ quality = 2; price = 20; };
	//class Exile_Item_BurlapSack											{ quality = 2; price = 5; };
	//class Exile_Item_Bullets_556										{ quality = 2; price = 5; };
	//class Exile_Item_Bullets_762										{ quality = 2; price = 5; };
	//class Exile_Item_WeaponParts										{ quality = 2; price = 20; };

	///////////////////////////////////////////////////////////////////////////////
	// Food
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Item_EMRE															{ quality = 3; price = 54; }; //75, 60
	class Exile_Item_GloriousKnakworst								{ quality = 3; price = 40; }; //60, 30
	class Exile_Item_Surstromming											{ quality = 3; price = 34; }; //55, 25
	class Exile_Item_SausageGravy											{ quality = 3; price = 30; }; //50, 25
	class Exile_Item_Catfood													{ quality = 2; price = 24; }; //40, 40
	class Exile_Item_ChristmasTinner									{ quality = 3; price = 20; }; //40, 60
	class Exile_Item_BBQSandwich											{ quality = 3; price = 20; }; //40, 60
	class Exile_Item_MacasCheese											{ quality = 3; price = 20; }; //40, 60
	class Exile_Item_Dogfood													{ quality = 2; price = 18; }; //30, 30
	class Exile_Item_BeefParts												{ quality = 2; price = 18; }; //30, 30
	class Exile_Item_Cheathas													{ quality = 2; price = 18; }; //30, 30
	class Exile_Item_Noodles													{ quality = 1; price = 14; }; //25, 50
	class Exile_Item_SeedAstics												{ quality = 1; price = 12; }; //20, 40
	class Exile_Item_Raisins													{ quality = 1; price = 10; }; //15, 30
	class Exile_Item_Moobar														{ quality = 1; price = 8; }; //10, 30
	class Exile_Item_InstantCoffee										{ quality = 1; price = 20; }; //5, 10
	class Exile_Item_Can_Empty												{ quality = 1; price = 1; sellPrice = 1; };
	//Meat
	class Exile_Item_SheepSteak_Cooked								{ quality = 4; price = 230; }; //100, 30
	class Exile_Item_AlsatianSteak_Cooked							{ quality = 4; price = 230; }; //100, 30
	class Exile_Item_CatSharkFilet_Cooked							{ quality = 4; price = 230; }; //100, 30
	class Exile_Item_FinSteak_Cooked									{ quality = 4; price = 230; }; //100, 30
	class Exile_Item_GoatSteak_Cooked									{ quality = 4; price = 230; }; //100, 30
	class Exile_Item_TurtleFilet_Cooked								{ quality = 4; price = 230; }; //100, 30
	class Exile_Item_TunaFilet_Cooked									{ quality = 3; price = 220; }; //90, 30
	class Exile_Item_RabbitSteak_Cooked								{ quality = 3; price = 215; }; //80, 30
	class Exile_Item_ChickenFilet_Cooked							{ quality = 3; price = 205; }; //70, 30
	class Exile_Item_RoosterFilet_Cooked							{ quality = 3; price = 205; }; //70, 30
	class Exile_Item_MulletFilet_Cooked								{ quality = 3; price = 200; }; //65, 30
	class Exile_Item_SalemaFilet_Cooked								{ quality = 3; price = 200; }; //65, 30
	class Exile_Item_MackerelFilet_Cooked							{ quality = 3; price = 190; }; //55, 30
	class Exile_Item_OrnateFilet_Cooked								{ quality = 3; price = 180; }; //40, 30
	class Exile_Item_SnakeFilet_Cooked								{ quality = 3; price = 180; }; //40, 30
	class Exile_Item_CatSharkFilet_Raw								{ quality = 2; price = 125; }; //25, 30
	class Exile_Item_TunaFilet_Raw										{ quality = 2; price = 120; }; //20, 30
	class Exile_Item_AlsatianSteak_Raw								{ quality = 2; price = 115; };	//15, 30
	class Exile_Item_TurtleFilet_Raw									{ quality = 2; price = 115; }; //15, 30
	class Exile_Item_SheepSteak_Raw										{ quality = 2; price = 115; }; //15, 30
	class Exile_Item_FinSteak_Raw											{ quality = 2; price = 115; }; //15, 30
	class Exile_Item_GoatSteak_Raw										{ quality = 2; price = 115; }; //15, 30
	class Exile_Item_ChickenFilet_Raw									{ quality = 2; price = 110; }; //10, 30
	class Exile_Item_RoosterFilet_Raw									{ quality = 2; price = 110; }; //10, 30
	class Exile_Item_MackerelFilet_Raw								{ quality = 2; price = 108; }; //5, 30
	class Exile_Item_MulletFilet_Raw									{ quality = 2; price = 108; }; //5, 30
	class Exile_Item_OrnateFilet_Raw									{ quality = 2; price = 108; }; //5, 30
	class Exile_Item_RabbitSteak_Raw									{ quality = 2; price = 108; }; //5, 30
	class Exile_Item_SalemaFilet_Raw									{ quality = 2; price = 108; }; //5, 30
	class Exile_Item_SnakeFilet_Raw										{ quality = 2; price = 108; }; //5, 30

	///////////////////////////////////////////////////////////////////////////////
	// Drinks
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Item_PlasticBottleCoffee	 			{ quality = 3; price = 70; sellPrice = 10; };//100, 60
	class Exile_Item_PowerDrink									{ quality = 3; price = 60; }; //95, 10
	class Exile_Item_PlasticBottleFreshWater		{ quality = 2; price = 50; sellPrice = 4; }; //80, 15
	class Exile_Item_Beer 											{ quality = 1; price = 50; }; //75, 30
	class Exile_Item_EnergyDrink								{ quality = 1; price = 40; }; //75, 20
	class Exile_Item_ChocolateMilk							{ quality = 1; price = 25; }; //75, 20
	class Exile_Item_MountainDupe								{ quality = 1; price = 30; }; //50, 20
	class Exile_Item_PlasticBottleEmpty					{ quality = 1; price = 4; };

	///////////////////////////////////////////////////////////////////////////////
	// First Aid
	///////////////////////////////////////////////////////////////////////////////
	class FirstAidKit																{ quality = 3; price = 800; };
	class Exile_Item_InstaDoc												{ quality = 3; price = 1250; };
	class Exile_Item_Vishpirin											{ quality = 2; price = 300; };
	class Exile_Item_Bandage												{ quality = 1; price = 100; };
	class Exile_Item_Heatpack												{ quality = 1; price = 50; };
	class Exile_Item_Defibrillator									{ quality = 5; price = 7500; };

	///////////////////////////////////////////////////////////////////////////////
	// Tools
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Item_Matches 													{ quality = 1; price = 60; };
	class Exile_Item_CookingPot												{ quality = 2; price = 80; };
	class Exile_Melee_Axe															{ quality = 2; price = 500; };
	class Exile_Melee_SledgeHammmer										{ quality = 3; price = 500; };
	class Exile_Melee_Shovel													{ quality = 3; price = 500; };
	class Exile_Item_CanOpener												{ quality = 1; price = 80; };
	class Exile_Item_Handsaw													{ quality = 2; price = 500; };
	class Exile_Item_Pliers														{ quality = 2; price = 350; };
	class Exile_Item_Grinder													{ quality = 2; price = 1250; };
	class Exile_Item_Foolbox													{ quality = 2; price = 4000; };
	class Exile_Item_Knife														{ quality = 2; price = 2500; };
	class Exile_Item_CordlessScrewdriver							{ quality = 1; price = 750; };
	class Exile_Item_FireExtinguisher									{ quality = 1; price = 650; };
	class Exile_Item_Hammer														{ quality = 1; price = 400; };
	class Exile_Item_OilCanister											{ quality = 1; price = 1750; };
	class Exile_Item_Screwdriver											{ quality = 1; price = 250; };
	class Exile_Item_Shovel														{ quality = 1; price = 500; };
	class Exile_Item_Wrench														{ quality = 1; price = 250; };
	class Exile_Item_SleepingMat											{ quality = 1; price = 1250; };
	class Exile_Item_ToiletPaper											{ quality = 1; price = 5; };
	class Exile_Item_ZipTie														{ quality = 1; price = 250; };

	///////////////////////////////////////////////////////////////////////////////
	// Navigation
	///////////////////////////////////////////////////////////////////////////////
	class ItemWatch																		{ quality = 1; price = 2; };
	class ItemGPS																			{ quality = 2; price = 40; };
	class ItemMap																			{ quality = 1; price = 6; };
	class ItemCompass																	{ quality = 1; price = 6; };
	class ItemRadio																		{ quality = 1; price = 40; };
	class Binocular																		{ quality = 1; price = 40; };
	class Rangefinder																	{ quality = 3; price = 200; };
	class Laserdesignator															{ quality = 6; price = 1500; };
	class Laserdesignator_01_khk_F										{ quality = 6; price = 1500; };
	class Laserdesignator_02													{ quality = 6; price = 1500; };
	class Laserdesignator_02_ghex_F										{ quality = 6; price = 1500; };
	class Laserdesignator_03													{ quality = 6; price = 1500; };
	class NVGoggles																		{ quality = 2; price = 100; };
	class NVGoggles_INDEP															{ quality = 2; price = 100; };
	class NVGoggles_OPFOR															{ quality = 2; price = 100; };
	class Exile_Item_XM8															{ quality = 2; price = 20; };
	class Exile_Item_MobilePhone											{ quality = 6; price = 500; };

	///////////////////////////////////////////////////////////////////////////////
	// Watch out for a Walter fart! He has gas!
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Headgear_GasMask											{ quality = 4; price = 500; };

	///////////////////////////////////////////////////////////////////////////////
	// Rebreather
	///////////////////////////////////////////////////////////////////////////////
	class V_RebreatherB															{ quality = 2; price = 250; };
	class V_RebreatherIA														{ quality = 2; price = 250; };
	class V_RebreatherIR														{ quality = 2; price = 250; };

	///////////////////////////////////////////////////////////////////////////////
	// Pilot Stuff
	///////////////////////////////////////////////////////////////////////////////
	class B_Parachute																{ quality = 3; price = 150; };
	class H_CrewHelmetHeli_B												{ quality = 3; price = 150; };
	class H_CrewHelmetHeli_I												{ quality = 3; price = 150; };
	class H_CrewHelmetHeli_O												{ quality = 3; price = 150; };
	class H_HelmetCrew_I														{ quality = 3; price = 100; };
	class H_HelmetCrew_B														{ quality = 3; price = 100; };
	class H_HelmetCrew_O														{ quality = 3; price = 100; };
	class H_PilotHelmetHeli_B												{ quality = 4; price = 100; };
	class H_PilotHelmetHeli_I												{ quality = 4; price = 100; };
	class H_PilotHelmetHeli_O												{ quality = 4; price = 100; };
	class U_B_HeliPilotCoveralls										{ quality = 4; price = 80; };
	class U_B_PilotCoveralls												{ quality = 2; price = 60; };
	class U_I_HeliPilotCoveralls										{ quality = 2; price = 60; };
	class U_I_pilotCoveralls												{ quality = 2; price = 60; };
	class U_O_PilotCoveralls												{ quality = 2; price = 60; };
	class H_PilotHelmetFighter_B										{ quality = 6; price = 400; };
	class H_PilotHelmetFighter_I										{ quality = 6; price = 400; };
	class H_PilotHelmetFighter_O										{ quality = 6; price = 400; };

	///////////////////////////////////////////////////////////////////////////////
	// Backpacks
	///////////////////////////////////////////////////////////////////////////////
	class B_HuntingBackpack														{ quality = 3; price = 70; };
	class B_OutdoorPack_blk														{ quality = 1; price = 80; };
	class B_OutdoorPack_blu														{ quality = 1; price = 80; };
	class B_OutdoorPack_tan														{ quality = 1; price = 80; };
	class B_AssaultPack_blk														{ quality = 1; price = 90; };
	class B_AssaultPack_cbr														{ quality = 1; price = 90; };
	class B_AssaultPack_dgtl													{ quality = 1; price = 90; };
	class B_AssaultPack_khk														{ quality = 1; price = 90; };
	class B_AssaultPack_mcamo													{ quality = 1; price = 90; };
	class B_AssaultPack_rgr														{ quality = 1; price = 90; };
	class B_AssaultPack_sgg														{ quality = 1; price = 90; };
	class B_FieldPack_blk															{ quality = 2; price = 120; };
	class B_FieldPack_cbr															{ quality = 2; price = 120; };
	class B_FieldPack_ocamo														{ quality = 2; price = 120; };
	class B_FieldPack_oucamo													{ quality = 2; price = 120; };
	class B_TacticalPack_blk													{ quality = 2; price = 150; };
	class B_TacticalPack_rgr													{ quality = 2; price = 150; };
	class B_TacticalPack_ocamo												{ quality = 2; price = 150; };
	class B_TacticalPack_mcamo												{ quality = 2; price = 150; };
	class B_TacticalPack_oli													{ quality = 2; price = 150; };
	class B_Kitbag_cbr																{ quality = 3; price = 200; };
	class B_Kitbag_mcamo															{ quality = 3; price = 200; };
	class B_Kitbag_sgg																{ quality = 3; price = 200; };
	class B_Bergen_blk																{ quality = 3; price = 200; };
	class B_Bergen_mcamo															{ quality = 3; price = 200; };
	class B_Bergen_rgr																{ quality = 3; price = 200; };
	class B_Bergen_sgg																{ quality = 3; price = 200; };
	class B_Carryall_cbr															{ quality = 4; price = 300; };
	class B_Carryall_khk															{ quality = 4; price = 300; };
	class B_Carryall_mcamo														{ quality = 4; price = 300; };
	class B_Carryall_ocamo														{ quality = 4; price = 300; };
	class B_Carryall_oli															{ quality = 4; price = 300; };
	class B_Carryall_oucamo														{ quality = 4; price = 300; };

	///////////////////////////////////////////////////////////////////////////////
	// Ammunition
	///////////////////////////////////////////////////////////////////////////////
	class 100Rnd_65x39_caseless_mag 									{ quality = 2; price = 30; };
	class 100Rnd_65x39_caseless_mag_Tracer 						{ quality = 2; price = 40; };
	class 10Rnd_127x54_Mag 														{ quality = 2; price = 30; };
	// Broken in Arma
	class 10Rnd_338_Mag 															{ quality = 2; price = 30; };
	class 10Rnd_762x54_Mag 														{ quality = 2; price = 30; };
	//class 10Rnd_762x51_Mag 													{ quality = 1; price = 30; };
	class 10Rnd_93x64_DMR_05_Mag 											{ quality = 2; price = 30; };
	class 11Rnd_45ACP_Mag 														{ quality = 1; price = 8; };
	class 150Rnd_762x54_Box 													{ quality = 2; price = 20; };
	class 150Rnd_762x54_Box_Tracer 										{ quality = 2; price = 30; };
	class 16Rnd_9x21_Mag 															{ quality = 1; price = 20; };
	class 16Rnd_9x21_red_Mag 													{ quality = 1; price = 20; };
	class 16Rnd_9x21_green_Mag 												{ quality = 1; price = 20; };
	class 16Rnd_9x21_yellow_Mag 											{ quality = 1; price = 20; };
	class 200Rnd_65x39_cased_Box 											{ quality = 2; price = 30; };
	class 200Rnd_65x39_cased_Box_Tracer 							{ quality = 2; price = 30; };
	class 150Rnd_93x64_Mag 														{ quality = 2; price = 50; };
	class 130Rnd_338_Mag 															{ quality = 2; price = 50; };
	class 20Rnd_556x45_UW_mag 												{ quality = 1; price = 20; };
	class 20Rnd_762x51_Mag 														{ quality = 2; price = 20; };
	class 30Rnd_45ACP_Mag_SMG_01 											{ quality = 1; price = 10; };
	class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green 				{ quality = 1; price = 10; };
	class 30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow				{ quality = 1; price = 10; };
	class 30Rnd_45ACP_Mag_SMG_01_Tracer_Red						{ quality = 1; price = 10; };
	class 30Rnd_556x45_Stanag 												{ quality = 1; price = 20; };
	class 30Rnd_556x45_Stanag_Tracer_Green 						{ quality = 1; price = 20; };
	class 30Rnd_556x45_Stanag_green  									{ quality = 1; price = 20; };
	class 30Rnd_556x45_Stanag_Tracer_Red 							{ quality = 1; price = 20; };
	class 30Rnd_556x45_Stanag_Tracer_Yellow 					{ quality = 1; price = 20; };
	class 30Rnd_556x45_Stanag_red 										{ quality = 1; price = 20; };
	class 30Rnd_65x39_caseless_green 									{ quality = 2; price = 20; };
	class 30Rnd_65x39_caseless_green_mag_Tracer 			{ quality = 2; price = 30; };
	class 30Rnd_65x39_caseless_mag 										{ quality = 2; price = 30; };
	class 30Rnd_65x39_caseless_mag_Tracer 						{ quality = 2; price = 30; };
	class 30Rnd_9x21_Mag 															{ quality = 1; price = 40; };
	class 30Rnd_9x21_Yellow_Mag												{ quality = 1; price = 40; };
	class 30Rnd_9x21_Green_Mag												{ quality = 1; price = 40; };
	class 30Rnd_9x21_Red_Mag													{ quality = 1; price = 40; };
	class 5Rnd_127x108_APDS_Mag 											{ quality = 2; price = 50; };
	class 5Rnd_127x108_Mag 														{ quality = 2; price = 40; };
	class 6Rnd_45ACP_Cylinder 												{ quality = 1; price = 8; };
	class 6Rnd_GreenSignal_F 													{ quality = 1; price = 30; };
	class 6Rnd_RedSignal_F 														{ quality = 1; price = 30; };
	class 7Rnd_408_Mag 																{ quality = 2; price = 30; };
	class 9Rnd_45ACP_Mag 															{ quality = 1; price = 6; };

	// Price for bullet cam magazines is normal magazine price + 20 pop tabs per bullet
	class Exile_Magazine_5Rnd_127x108_Bullet_Cam_Mag 						{ quality = 6; price = 140; };
	class Exile_Magazine_5Rnd_127x108_APDS_Bullet_Cam_Mag 			{ quality = 6; price = 140; };
	class Exile_Magazine_10Rnd_93x64_DMR_05_Bullet_Cam_Mag 			{ quality = 6; price = 240; };
	class Exile_Magazine_7Rnd_408_Bullet_Cam_Mag 								{ quality = 6; price = 150; };
	class Exile_Magazine_10Rnd_338_Bullet_Cam_Mag 							{ quality = 6; price = 230; };
	class Exile_Magazine_10Rnd_127x99_m107_Bullet_Cam_Mag 			{ quality = 6; price = 240; };
	class Exile_Magazine_5Rnd_127x108_KSVK_Bullet_Cam_Mag 			{ quality = 6; price = 140; };
	class Exile_Magazine_5Rnd_127x108_APDS_KSVK_Bullet_Cam_Mag	{ quality = 6; price = 140; };

	///////////////////////////////////////////////////////////////////////////////
	// Flares
	///////////////////////////////////////////////////////////////////////////////
	class Chemlight_blue															{ quality = 1; price = 5; };
	class Chemlight_green															{ quality = 1; price = 5; };
	class Chemlight_red																{ quality = 1; price = 5; };
	class Chemlight_yellow														{ quality = 1; price = 5; };
	class FlareGreen_F																{ quality = 1; price = 6; };
	class FlareRed_F																	{ quality = 1; price = 6; };
	class FlareWhite_F																{ quality = 1; price = 6; };
	class FlareYellow_F																{ quality = 1; price = 6; };
	class UGL_FlareGreen_F														{ quality = 2; price = 20; };
	class UGL_FlareRed_F															{ quality = 2; price = 20; };
	class UGL_FlareWhite_F														{ quality = 2; price = 20; };
	class UGL_FlareYellow_F														{ quality = 2; price = 20; };
	class UGL_FlareCIR_F															{ quality = 2; price = 20; };
	class 3Rnd_UGL_FlareGreen_F												{ quality = 2; price = 60; };
	class 3Rnd_UGL_FlareRed_F													{ quality = 2; price = 60; };
	class 3Rnd_UGL_FlareWhite_F												{ quality = 2; price = 60; };
	class 3Rnd_UGL_FlareYellow_F											{ quality = 2; price = 60; };
	class 3Rnd_UGL_FlareCIR_F													{ quality = 2; price = 60; };

	///////////////////////////////////////////////////////////////////////////////
	// Smokes
	///////////////////////////////////////////////////////////////////////////////
	class SmokeShell																	{ quality = 2; price = 20; };
	class SmokeShellBlue															{ quality = 2; price = 20; };
	class SmokeShellGreen															{ quality = 2; price = 20; };
	class SmokeShellOrange														{ quality = 2; price = 20; };
	class SmokeShellPurple														{ quality = 2; price = 20; };
	class SmokeShellRed																{ quality = 2; price = 20; };
	class SmokeShellYellow														{ quality = 2; price = 20; };
	class 1Rnd_Smoke_Grenade_shell										{ quality = 2; price = 20; };
	class 1Rnd_SmokeBlue_Grenade_shell								{ quality = 2; price = 20; };
	class 1Rnd_SmokeGreen_Grenade_shell								{ quality = 2; price = 20; };
	class 1Rnd_SmokeOrange_Grenade_shell							{ quality = 2; price = 20; };
	class 1Rnd_SmokePurple_Grenade_shell							{ quality = 2; price = 20; };
	class 1Rnd_SmokeRed_Grenade_shell									{ quality = 2; price = 20; };
	class 1Rnd_SmokeYellow_Grenade_shell							{ quality = 2; price = 20; };
	class 3Rnd_Smoke_Grenade_shell										{ quality = 2; price = 60; };
	class 3Rnd_SmokeBlue_Grenade_shell								{ quality = 2; price = 60; };
	class 3Rnd_SmokeGreen_Grenade_shell								{ quality = 2; price = 60; };
	class 3Rnd_SmokeOrange_Grenade_shell							{ quality = 2; price = 60; };
	class 3Rnd_SmokePurple_Grenade_shell							{ quality = 2; price = 60; };
	class 3Rnd_SmokeRed_Grenade_shell									{ quality = 2; price = 60; };
	class 3Rnd_SmokeYellow_Grenade_shell							{ quality = 2; price = 60; };

	///////////////////////////////////////////////////////////////////////////////
	// Grenades
	///////////////////////////////////////////////////////////////////////////////
	class HandGrenade																	{ quality = 2; price = 50; };
	class MiniGrenade																	{ quality = 2; price = 30; };
	class B_IR_Grenade																{ quality = 1; price = 50; };
	class O_IR_Grenade																{ quality = 1; price = 50; };
	class I_IR_Grenade																{ quality = 1; price = 50; };
	class 1Rnd_HE_Grenade_shell												{ quality = 2; price = 100; };
	class 3Rnd_HE_Grenade_shell												{ quality = 2; price = 300; };

	///////////////////////////////////////////////////////////////////////////////
	// Explosives
	///////////////////////////////////////////////////////////////////////////////
	class APERSBoundingMine_Range_Mag								{ quality = 3; price = 500; };
	class APERSMine_Range_Mag												{ quality = 3; price = 600; };
	class APERSTripMine_Wire_Mag										{ quality = 3; price = 300; };
	class ClaymoreDirectionalMine_Remote_Mag				{ quality = 3; price = 350; };
	class DemoCharge_Remote_Mag											{ quality = 4; price = 700; };
	class IEDLandBig_Remote_Mag											{ quality = 3; price = 600; };
	class IEDLandSmall_Remote_Mag										{ quality = 3; price = 300; };
	class IEDUrbanBig_Remote_Mag										{ quality = 3; price = 800; };
	class IEDUrbanSmall_Remote_Mag									{ quality = 3; price = 400; };
	class SatchelCharge_Remote_Mag									{ quality = 5; price = 1000; };
	class SLAMDirectionalMine_Wire_Mag							{ quality = 3; price = 700; };

	///////////////////////////////////////////////////////////////////////////////
	// Launchers
	///////////////////////////////////////////////////////////////////////////////
	class launch_RPG32_F														{ quality = 6; price = 2000; };
	class launch_RPG32_ghex_F												{ quality = 6; price = 2000; };
	class launch_B_Titan_F													{ quality = 6; price = 10000; };
	class launch_I_Titan_F													{ quality = 6; price = 10000; };
	class launch_O_Titan_F													{ quality = 6; price = 10000; };
	class RPG32_F																		{ quality = 6; price = 1000; };
	class RPG32_HE_F																{ quality = 6; price = 1000; };
	class Titan_AA																	{ quality = 6; price = 5000; };

	///////////////////////////////////////////////////////////////////////////////
	// Pistols
	///////////////////////////////////////////////////////////////////////////////
	class hgun_ACPC2_F 																{ quality = 1; price = 50; };
	class hgun_P07_F 																	{ quality = 1; price = 50; };
	class hgun_Pistol_heavy_01_F 											{ quality = 2; price = 80; };
	class hgun_Pistol_heavy_02_F 											{ quality = 2; price = 80; };
	class hgun_Pistol_Signal_F 												{ quality = 1; price = 100; };
	class hgun_Rook40_F 															{ quality = 1; price = 50; };

	///////////////////////////////////////////////////////////////////////////////
	// Sub Machine Guns
	///////////////////////////////////////////////////////////////////////////////
	class hgun_PDW2000_F 														{ quality = 1; price = 100; };
	class SMG_01_F 																	{ quality = 1; price = 150; };
	class SMG_02_F 																	{ quality = 1; price = 150; };

	///////////////////////////////////////////////////////////////////////////////
	// Light Machine Guns
	///////////////////////////////////////////////////////////////////////////////
	class arifle_MX_SW_Black_F											{ quality = 2; price = 250; };
	class arifle_MX_SW_khk_F												{ quality = 2; price = 250; };
	class arifle_MX_SW_F														{ quality = 2; price = 250; };
	class LMG_Mk200_F																{ quality = 2; price = 300; };
	class LMG_Zafir_F																{ quality = 3; price = 350; };
	class MMG_01_hex_F															{ quality = 6; price = 800; };
	class MMG_01_tan_F															{ quality = 6; price = 800; };
	class COG_Navid_Black_Hex												{ quality = 6; price = 800; };
	class MMG_02_black_F														{ quality = 6; price = 450; };
	class MMG_02_camo_F															{ quality = 5; price = 450; };
	class MMG_02_sand_F															{ quality = 5; price = 450; };

	///////////////////////////////////////////////////////////////////////////////
	// Assault Rifles
	///////////////////////////////////////////////////////////////////////////////
	class arifle_Katiba_C_F													{ quality = 2; price = 150; };
	class arifle_Katiba_F														{ quality = 2; price = 150; };
	class arifle_Katiba_GL_F												{ quality = 2; price = 200; };
	class arifle_Mk20_F															{ quality = 1; price = 150; };
	class arifle_Mk20_GL_F													{ quality = 1; price = 200; };
	class arifle_Mk20_GL_plain_F										{ quality = 1; price = 200; };
	class arifle_Mk20_plain_F												{ quality = 1; price = 150; };
	class arifle_Mk20C_F														{ quality = 1; price = 150; };
	class arifle_Mk20C_plain_F											{ quality = 1; price = 150; };
	class arifle_MX_Black_F													{ quality = 2; price = 450; };
	class arifle_MX_F																{ quality = 2; price = 450; };
	class arifle_MX_GL_Black_F											{ quality = 2; price = 450; };
	class arifle_MX_GL_F														{ quality = 2; price = 450; };
	class arifle_MXC_Black_F												{ quality = 2; price = 350; };
	class arifle_MXC_F															{ quality = 2; price = 350; };
	class arifle_SDAR_F															{ quality = 1; price = 650; };
	class arifle_TRG20_F														{ quality = 1; price = 250; };
	class arifle_TRG21_F														{ quality = 1; price = 250; };
	class arifle_TRG21_GL_F													{ quality = 1; price = 350; };

	///////////////////////////////////////////////////////////////////////////////
	// Sniper Rifles
	///////////////////////////////////////////////////////////////////////////////
	class arifle_MXM_Black_F 												{ quality = 2; price = 550; };
	class arifle_MXM_F 															{ quality = 2; price = 550; };
	class srifle_DMR_01_F 													{ quality = 3; price = 600; };
	class srifle_DMR_02_camo_F 											{ quality = 3; price = 800; };
	class srifle_DMR_02_F 													{ quality = 3; price = 800; };
	class srifle_DMR_02_sniper_F 										{ quality = 3; price = 800; };
	class srifle_DMR_03_F 													{ quality = 3; price = 750; };
	class srifle_DMR_03_khaki_F 										{ quality = 3; price = 750; };
	class srifle_DMR_03_multicam_F 									{ quality = 3; price = 750; };
	class srifle_DMR_03_tan_F 											{ quality = 3; price = 750; };
	class srifle_DMR_03_woodland_F 									{ quality = 3; price = 750; };
	class srifle_DMR_04_F 													{ quality = 4; price = 700; };
	class srifle_DMR_04_Tan_F 											{ quality = 4; price = 700; };
	class srifle_DMR_05_blk_F 											{ quality = 4; price = 850; };
	class srifle_DMR_05_hex_F 											{ quality = 4; price = 850; };
	class srifle_DMR_05_tan_f 											{ quality = 4; price = 850; };
	class srifle_DMR_06_camo_F 											{ quality = 5; price = 800; };
	class srifle_DMR_06_olive_F 										{ quality = 5; price = 800; };
	class srifle_EBR_F 															{ quality = 3; price = 700; };
	class srifle_GM6_camo_F 												{ quality = 6; price = 900; };
	class srifle_GM6_F 															{ quality = 6; price = 900; };
	class srifle_LRR_camo_F 												{ quality = 6; price = 850; };
	class srifle_LRR_F 															{ quality = 6; price = 850; };

	///////////////////////////////////////////////////////////////////////////////
	// ArmA 2 Weapons
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Weapon_AK107												{ quality = 1; price = 300; };
	class Exile_Weapon_AK107_GL											{ quality = 2; price = 400; };
	class Exile_Weapon_AK74													{ quality = 2; price = 350; };
	class Exile_Weapon_AK74_GL											{ quality = 2; price = 400; };
	class Exile_Weapon_AK47													{ quality = 3; price = 500; };
	class Exile_Weapon_AKM													{ quality = 3; price = 500; };
	class Exile_Weapon_AKS													{ quality = 3; price = 500; };
	class Exile_Weapon_AKS_Gold											{ quality = 3; price = 550; };
	class Exile_Weapon_DMR													{ quality = 3; price = 650; };
	class Exile_Weapon_LeeEnfield										{ quality = 1; price = 250; };
	class Exile_Weapon_CZ550												{ quality = 2; price = 400; };
	class Exile_Weapon_SVD													{ quality = 4; price = 800; };
	class Exile_Weapon_SVDCamo											{ quality = 4; price = 850; };
	class Exile_Weapon_VSSVintorez									{ quality = 3; price = 600; };
	class Exile_Weapon_RPK													{ quality = 2; price = 250; };
	class Exile_Weapon_PK														{ quality = 3; price = 300; };
	class Exile_Weapon_PKP													{ quality = 3; price = 350; };
	class Exile_Weapon_Colt1911											{ quality = 1; price = 100; };
	class Exile_Weapon_Makarov											{ quality = 1; price = 100; };
	class Exile_Weapon_Taurus												{ quality = 1; price = 100; };
	class Exile_Weapon_TaurusGold										{ quality = 1; price = 150; };
	class Exile_Weapon_M1014												{ quality = 2; price = 200; };
	class Exile_Weapon_SA61													{ quality = 1; price = 150; };
	class Exile_Weapon_m107													{ quality = 5; price = 850; };
	class Exile_Weapon_ksvk													{ quality = 5; price = 850; };
	class Exile_Weapon_M4														{ quality = 2; price = 300; };
	class Exile_Weapon_M16A4												{ quality = 2; price = 350; };
	class Exile_Weapon_M16A2												{ quality = 1; price = 300; };

	///////////////////////////////////////////////////////////////////////////////
	// ArmA 2 Ammunition
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Magazine_30Rnd_762x39_AK							{ quality = 2; price = 20; };
	class Exile_Magazine_30Rnd_545x39_AK							{ quality = 1; price = 20; };
	class Exile_Magazine_30Rnd_545x39_AK_Green				{ quality = 1; price = 20; };
	class Exile_Magazine_30Rnd_545x39_AK_Red					{ quality = 1; price = 20; };
	class Exile_Magazine_30Rnd_545x39_AK_White				{ quality = 1; price = 20; };
	class Exile_Magazine_30Rnd_545x39_AK_Yellow				{ quality = 1; price = 20; };
	class Exile_Magazine_45Rnd_545x39_RPK_Green				{ quality = 1; price = 20; };
	class Exile_Magazine_75Rnd_545x39_RPK_Green				{ quality = 1; price = 20; };
	class Exile_Magazine_20Rnd_762x51_DMR							{ quality = 2; price = 20; };
	class Exile_Magazine_20Rnd_762x51_DMR_Yellow			{ quality = 2; price = 20; };
	class Exile_Magazine_20Rnd_762x51_DMR_Red					{ quality = 2; price = 20; };
	class Exile_Magazine_20Rnd_762x51_DMR_Green				{ quality = 2; price = 20; };
	class Exile_Magazine_10Rnd_303										{ quality = 1; price = 20; };
	class Exile_Magazine_100Rnd_762x54_PK_Green				{ quality = 2; price = 20; };
	class Exile_Magazine_7Rnd_45ACP										{ quality = 1; price = 20; };
	class Exile_Magazine_8Rnd_9x18										{ quality = 1; price = 20; };
	class Exile_Magazine_6Rnd_45ACP										{ quality = 1; price = 20; };
	class Exile_Magazine_5Rnd_22LR										{ quality = 1; price = 20; };
	class Exile_Magazine_10Rnd_762x54									{ quality = 1; price = 20; };
	class Exile_Magazine_10Rnd_9x39										{ quality = 1; price = 20; };
	class Exile_Magazine_20Rnd_9x39										{ quality = 1; price = 20; };
	class Exile_Magazine_8Rnd_74Slug									{ quality = 1; price = 20; };
	class Exile_Magazine_8Rnd_74Pellets								{ quality = 1; price = 20; }; // broken?
	class Exile_Magazine_10Rnd_765x17_SA61						{ quality = 1; price = 10; };
	class Exile_Magazine_20Rnd_765x17_SA61						{ quality = 1; price = 20; };
	class Exile_Magazine_10Rnd_127x99_m107						{ quality = 3; price = 30; };
	class Exile_Magazine_5Rnd_127x108_APDS_KSVK				{ quality = 3; price = 40; };
	class Exile_Magazine_5Rnd_127x108_KSVK						{ quality = 3; price = 30; };

	///////////////////////////////////////////////////////////////////////////////
	// CUP Items & Weapons
	///////////////////////////////////////////////////////////////////////////////
	//Assault Rifles
	class CUP_arifle_AK74															{ quality = 1; price = 200; };
	class CUP_arifle_AK107														{ quality = 1; price = 200; };
	class CUP_arifle_AK107_GL													{ quality = 2; price = 200; };
	class CUP_arifle_AKS74														{ quality = 1; price = 200; };
	class CUP_arifle_AKS74U														{ quality = 1; price = 200; };
	class CUP_arifle_AK74_GL													{ quality = 2; price = 200; };
	class CUP_arifle_AKM															{ quality = 1; price = 200; };
	class CUP_arifle_AKS															{ quality = 1; price = 200; };
	class CUP_arifle_AKS_Gold													{ quality = 1; price = 200; };
	class CUP_arifle_RPK74														{ quality = 1; price = 200; };
	class CUP_arifle_FNFAL_railed											{ quality = 1; price = 300; };
	class CUP_arifle_G36K															{ quality = 1; price = 200; };
	class CUP_arifle_G36K_camo												{ quality = 1; price = 200; };
	class CUP_arifle_G36C															{ quality = 1; price = 200; };
	class CUP_arifle_G36C_camo												{ quality = 1; price = 200; };
	class CUP_arifle_L85A2														{ quality = 1; price = 200; };
	class CUP_arifle_L85A2_GL													{ quality = 2; price = 200; };
	class CUP_arifle_L86A2														{ quality = 1; price = 200; };
	class CUP_arifle_M16A2														{ quality = 1; price = 200; };
	class CUP_arifle_M16A2_GL													{ quality = 2; price = 350; };
	class CUP_arifle_M16A4_GL													{ quality = 2; price = 350; };
	class CUP_arifle_M4A1															{ quality = 1; price = 200; };
	class CUP_arifle_M4A1_camo												{ quality = 1; price = 200; };
	class CUP_arifle_M16A4_Base												{ quality = 1; price = 200; };
	class CUP_arifle_M16A4GL													{ quality = 2; price = 250; };
	class CUP_arifle_M4A1_BUIS_GL											{ quality = 2; price = 350; };
	class CUP_arifle_M4A1_BUIS_camo_GL								{ quality = 2; price = 350; };
	class CUP_arifle_M4A1_black												{ quality = 1; price = 200; };
	class CUP_arifle_M4A1_desert											{ quality = 1; price = 200; };
	class CUP_arifle_Sa58P														{ quality = 1; price = 200; };
	class CUP_arifle_Sa58V														{ quality = 1; price = 200; };
	class CUP_arifle_Sa58P_des												{ quality = 1; price = 200; };
	class CUP_arifle_Sa58V_camo												{ quality = 1; price = 200; };
	class CUP_arifle_Sa58RIS1													{ quality = 1; price = 250; };
	class CUP_arifle_Sa58RIS1_des											{ quality = 1; price = 250; };
	class CUP_arifle_Sa58RIS2													{ quality = 1; price = 250; };
	class CUP_arifle_Sa58RIS2_camo										{ quality = 1; price = 250; };
	class CUP_arifle_CZ805_A1													{ quality = 1; price = 200; };
	class CUP_arifle_CZ805_GL													{ quality = 1; price = 250; };
	class CUP_arifle_CZ805_A2													{ quality = 1; price = 200; };
	class CUP_arifle_CZ805_B													{ quality = 1; price = 200; };
	class CUP_arifle_CZ805_B_GL												{ quality = 1; price = 250; };
	class CUP_arifle_XM8_Compact_Rail									{ quality = 2; price = 250; };
	class CUP_arifle_XM8_Railed												{ quality = 2; price = 250; };
	class CUP_arifle_XM8_Carbine											{ quality = 2; price = 250; };
	class CUP_arifle_XM8_Carbine_GL										{ quality = 2; price = 300; };
	class CUP_arifle_xm8_SAW													{ quality = 2; price = 250; };
	class CUP_arifle_xm8_sharpshooter									{ quality = 2; price = 250; };
	class CUP_arifle_Mk16_CQC													{ quality = 2; price = 300; };
	class CUP_arifle_Mk16_CQC_FG											{ quality = 2; price = 300; };
	class CUP_arifle_Mk16_CQC_SFG											{ quality = 2; price = 300; };
	class CUP_arifle_Mk16_CQC_EGLM										{ quality = 3; price = 350; };
	class CUP_arifle_Mk16_STD													{ quality = 2; price = 300; };
	class CUP_arifle_Mk16_STD_FG											{ quality = 2; price = 300; };
	class CUP_arifle_Mk16_STD_SFG											{ quality = 2; price = 300; };
	class CUP_arifle_Mk16_SV													{ quality = 3; price = 500; };
	class CUP_arifle_Mk17_CQC													{ quality = 3; price = 500; };
	class CUP_arifle_Mk17_CQC_FG											{ quality = 3; price = 500; };
	class CUP_arifle_Mk17_CQC_SFG											{ quality = 3; price = 500; };
	class CUP_arifle_Mk17_CQC_EGLM										{ quality = 3; price = 600; };
	class CUP_arifle_Mk17_STD													{ quality = 3; price = 500; };
	class CUP_arifle_Mk17_STD_FG											{ quality = 3; price = 500; };
	class CUP_arifle_Mk17_STD_SFG											{ quality = 3; price = 500; };
	class CUP_arifle_Mk20															{ quality = 3; price = 800; };
	// Shotguns
	class CUP_sgun_AA12																{ quality = 3; price = 200; };
	class CUP_sgun_M1014															{ quality = 1; price = 200; };
	class CUP_sgun_Saiga12K														{ quality = 1; price = 200; };
	// Pistols
	class CUP_hgun_Glock17														{ quality = 1; price = 200; };
	class CUP_hgun_Compact														{ quality = 1; price = 200; };
	class CUP_hgun_Makarov														{ quality = 1; price = 200; };
	class CUP_hgun_PB6P9															{ quality = 1; price = 200; };
	class CUP_hgun_MicroUzi														{ quality = 1; price = 200; };
	class CUP_hgun_SA61																{ quality = 1; price = 200; };
	class CUP_hgun_Duty																{ quality = 1; price = 200; };
	class CUP_hgun_Phantom														{ quality = 1; price = 200; };
	// Light Machine Guns
	class CUP_lmg_M240																{ quality = 2; price = 850; };
	class CUP_lmg_M249																{ quality = 1; price = 800; };
	class CUP_lmg_M249_para														{ quality = 1; price = 800; };
	class CUP_lmg_Mk48_wdl														{ quality = 2; price = 800; };
	class CUP_lmg_Mk48_des														{ quality = 2; price = 800; };
	class CUP_lmg_PKM																	{ quality = 1; price = 750; };
	class CUP_lmg_Pecheneg														{ quality = 1; price = 750; };
	// Sub Machine Guns
	class CUP_smg_bizon																{ quality = 1; price = 200; };
	class CUP_smg_EVO																	{ quality = 1; price = 250; };
	class CUP_smg_MP5SD6															{ quality = 1; price = 250; };
	class CUP_smg_MP5A5																{ quality = 1; price = 200; };
	// Sniper Rifles
	class CUP_srifle_AWM_wdl													{ quality = 1; price = 850; };
	class CUP_srifle_AWM_des													{ quality = 1; price = 850; };
	class CUP_srifle_ksvk															{ quality = 1; price = 850; };
	class CUP_srifle_CZ750														{ quality = 1; price = 850; };
	class CUP_srifle_DMR															{ quality = 2; price = 850; };
	class CUP_srifle_CZ550														{ quality = 1; price = 850; };
	class CUP_srifle_M14															{ quality = 2; price = 850; };
	class CUP_srifle_Mk12SPR													{ quality = 2; price = 850; };
	class CUP_srifle_M24_wdl													{ quality = 1; price = 850; };
	class CUP_srifle_M40A3														{ quality = 1; price = 850; };
	class CUP_srifle_M107_Base												{ quality = 5; price = 900; };
	class CUP_srifle_M110															{ quality = 2; price = 900; };
	class CUP_srifle_SVD															{ quality = 1; price = 850; };
	class CUP_srifle_VSSVintorez											{ quality = 1; price = 850; };
	class CUP_srifle_AS50															{ quality = 4; price = 900; }; 
	// Grenade Launchers
	class CUP_glaunch_Mk13														{ quality = 3; price = 300; };
	class CUP_glaunch_M79															{ quality = 3; price = 300; };
	// Launchers 
	class CUP_launch_RPG7V														{ quality = 6; price = 2000; };
	class CUP_launch_Metis														{ quality = 6; price = 2000; };
	class CUP_launch_Mk153Mod0												{ quality = 6; price = 2000; };
	class CUP_launch_MAAWS														{ quality = 6; price = 2000; };
	class CUP_launch_NLAW															{ quality = 6; price = 10000; };
	class CUP_Stinger																	{ quality = 6; price = 10000; };
	//Launcher Optic Attachments
	class CUP_optic_NSPU_RPG													{ quality = 6; price = 500; };
	class CUP_optic_PGO7V															{ quality = 6; price = 250; };
	class CUP_optic_PGO7V2														{ quality = 6; price = 250; };
	class CUP_optic_PGO7V3														{ quality = 6; price = 250; };
	class CUP_optic_SMAW_Scope												{ quality = 6; price = 250; };
	class CUP_optic_MAAWS_Scope												{ quality = 6; price = 250; };
	// Optic Attachments
	class CUP_optic_AN_PVS_10													{ quality = 3; price = 500; };
	class CUP_optic_AN_PVS_4													{ quality = 3; price = 500; };
	class CUP_optic_NSPU															{ quality = 3; price = 500; };
	class CUP_optic_PSO_1															{ quality = 1; price = 50; };
	class CUP_optic_PSO_3															{ quality = 1; price = 50; };
	class CUP_optic_Kobra															{ quality = 1; price = 50; };
	class CUP_optic_PechenegScope											{ quality = 1; price = 50; };
	class CUP_optic_LeupoldMk4												{ quality = 1; price = 50; };
	class CUP_optic_HoloBlack													{ quality = 1; price = 50; };
	class CUP_optic_HoloWdl														{ quality = 1; price = 50; };
	class CUP_optic_HoloDesert												{ quality = 1; price = 50; };
	class CUP_optic_Eotech533													{ quality = 1; price = 50; };
	class CUP_optic_CompM4														{ quality = 1; price = 50; };
	class CUP_optic_SUSAT															{ quality = 1; price = 50; };
	class CUP_optic_ACOG															{ quality = 1; price = 50; };
	class CUP_optic_Leupold_VX3												{ quality = 1; price = 50; };
	class CUP_optic_CompM2_Black											{ quality = 1; price = 50; };
	class CUP_optic_CompM2_Woodland										{ quality = 1; price = 50; };
	class CUP_optic_CompM2_Woodland2									{ quality = 1; price = 50; };
	class CUP_optic_CompM2_Desert											{ quality = 1; price = 50; };
	class CUP_optic_RCO																{ quality = 1; price = 50; };
	class CUP_optic_RCO_desert												{ quality = 1; price = 50; };
	class CUP_optic_LeupoldM3LR												{ quality = 1; price = 50; };
	class CUP_optic_LeupoldMk4_10x40_LRT_Desert				{ quality = 1; price = 50; };
	class CUP_optic_LeupoldMk4_10x40_LRT_Woodland			{ quality = 1; price = 50; };
	class CUP_optic_ElcanM145													{ quality = 1; price = 50; };
	class CUP_optic_LeupoldMk4_CQ_T										{ quality = 1; price = 50; };
	class CUP_optic_ELCAN_SpecterDR										{ quality = 1; price = 50; };
	class CUP_optic_Elcan_reflex											{ quality = 1; price = 50; };
	class CUP_optic_LeupoldMk4_MRT_tan								{ quality = 1; price = 50; };
	class CUP_optic_SB_11_4x20_PM											{ quality = 1; price = 50; };
	class CUP_optic_ZDDot															{ quality = 1; price = 50; };
	class CUP_optic_MRad															{ quality = 1; price = 50; };
	class CUP_optic_TrijiconRx01_desert								{ quality = 1; price = 50; };
	class CUP_optic_TrijiconRx01_black								{ quality = 1; price = 50; };
	// Muzzle Attachments
	class CUP_muzzle_PBS4															{ quality = 1; price = 20; };
	class CUP_muzzle_PB6P9														{ quality = 1; price = 20; };
	class CUP_muzzle_Bizon														{ quality = 1; price = 20; };
	class CUP_muzzle_snds_M110												{ quality = 1; price = 20; };
	class CUP_muzzle_snds_M14													{ quality = 1; price = 20; };
	class CUP_muzzle_snds_M9													{ quality = 1; price = 20; };
	class CUP_muzzle_snds_MicroUzi										{ quality = 1; price = 20; };
	class CUP_muzzle_snds_AWM													{ quality = 1; price = 20; };
	class CUP_muzzle_snds_G36_black										{ quality = 1; price = 20; };
	class CUP_muzzle_snds_G36_desert									{ quality = 1; price = 20; };
	class CUP_muzzle_snds_L85													{ quality = 1; price = 20; };
	class CUP_muzzle_snds_M16_camo										{ quality = 1; price = 20; };
	class CUP_muzzle_snds_M16													{ quality = 1; price = 20; };
	class CUP_muzzle_snds_SCAR_L											{ quality = 1; price = 20; };
	class CUP_muzzle_mfsup_SCAR_L											{ quality = 1; price = 20; };
	class CUP_muzzle_snds_SCAR_H											{ quality = 1; price = 20; };
	class CUP_muzzle_mfsup_SCAR_H											{ quality = 1; price = 20; };
	class CUP_muzzle_snds_XM8													{ quality = 1; price = 20; }; 
	// Ammo
	//// Shotgun
	class CUP_20Rnd_B_AA12_Pellets										{ quality = 1; price = 10; };
	class CUP_20Rnd_B_AA12_74Slug											{ quality = 1; price = 10; };
	class CUP_20Rnd_B_AA12_HE													{ quality = 1; price = 25; };
	class CUP_8Rnd_B_Beneli_74Slug										{ quality = 1; price = 10; };
	class CUP_8Rnd_B_Saiga12_74Slug_M									{ quality = 1; price = 10; }; 
	////Launcher
	class CUP_PG7V_M																	{ quality = 6; price = 1000; };
	class CUP_PG7VM_M																	{ quality = 6; price = 1000; };
	class CUP_PG7VL_M																	{ quality = 6; price = 1000; };
	class CUP_PG7VR_M																	{ quality = 6; price = 1000; };
	class CUP_OG7_M																		{ quality = 6; price = 1000; };
	class CUP_TBG7V_M																	{ quality = 6; price = 1000; };
	class CUP_AT13_M																	{ quality = 6; price = 1000; };
	class CUP_SMAW_HEAA_M															{ quality = 6; price = 1000; };
	class CUP_SMAW_HEDP_M															{ quality = 6; price = 1000; };
	class CUP_MAAWS_HEAT_M														{ quality = 6; price = 1000; };
	class CUP_MAAWS_HEDP_M														{ quality = 6; price = 1000; };
	class CUP_NLAW_M																	{ quality = 6; price = 5000; };
	class CUP_Stinger_M																{ quality = 6; price = 5000; };
	//// Grenade Launcher
	class CUP_1Rnd_HE_M203														{ quality = 2; price = 100; };
	class CUP_1Rnd_HEDP_M203													{ quality = 2; price = 100; };
	class CUP_FlareWhite_M203													{ quality = 1; price = 20; };
	class CUP_FlareGreen_M203													{ quality = 1; price = 20; };
	class CUP_FlareRed_M203														{ quality = 1; price = 20; };
	class CUP_FlareYellow_M203												{ quality = 1; price = 20; };
	class CUP_1Rnd_Smoke_M203													{ quality = 1; price = 20; };
	class CUP_1Rnd_SmokeRed_M203											{ quality = 1; price = 20; };
	class CUP_1Rnd_SmokeGreen_M203										{ quality = 1; price = 20; };
	class CUP_1Rnd_SmokeYellow_M203										{ quality = 1; price = 20; }; 
	//// Handgun
	class CUP_8Rnd_9x18_Makarov_M											{ quality = 1; price = 8; };
	class CUP_8Rnd_9x18_MakarovSD_M										{ quality = 1; price = 8; };
	class CUP_15Rnd_9x19_M9														{ quality = 1; price = 8; };
	class CUP_18Rnd_9x19_Phantom											{ quality = 1; price = 8; };
	class CUP_17Rnd_9x19_glock17											{ quality = 1; price = 8; };
	class CUP_10Rnd_9x19_Compact											{ quality = 1; price = 8; }; 
	//// LMG
	class CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M	{ quality = 1; price = 50; };
	class CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M		{ quality = 1; price = 50; };
	class CUP_200Rnd_TE4_Red_Tracer_556x45_M249				{ quality = 1; price = 50; };
	class CUP_200Rnd_TE4_Yellow_Tracer_556x45_M249		{ quality = 1; price = 50; };
	class CUP_200Rnd_TE1_Red_Tracer_556x45_M249				{ quality = 1; price = 50; };
	class CUP_100Rnd_TE4_Green_Tracer_556x45_M249			{ quality = 1; price = 50; };
	class CUP_100Rnd_TE4_Red_Tracer_556x45_M249				{ quality = 1; price = 50; };
	class CUP_100Rnd_TE4_Yellow_Tracer_556x45_M249		{ quality = 1; price = 50; };
	//// SMG
	class CUP_64Rnd_9x19_Bizon_M											{ quality = 1; price = 20; };
	class CUP_64Rnd_Green_Tracer_9x19_Bizon_M					{ quality = 1; price = 20; };
	class CUP_64Rnd_Red_Tracer_9x19_Bizon_M						{ quality = 1; price = 20; };
	class CUP_64Rnd_White_Tracer_9x19_Bizon_M					{ quality = 1; price = 20; };
	class CUP_64Rnd_Yellow_Tracer_9x19_Bizon_M				{ quality = 1; price = 20; };
	class CUP_30Rnd_9x19_EVO													{ quality = 1; price = 10; };
	class CUP_30Rnd_9x19_UZI													{ quality = 1; price = 10; };
	class CUP_30Rnd_9x19_MP5													{ quality = 1; price = 10; };
	class CUP_20Rnd_B_765x17_Ball_M										{ quality = 1; price = 10; }; 
	//// Sniper
	class CUP_5Rnd_127x99_as50_M											{ quality = 1; price = 10; };
	class CUP_5Rnd_86x70_L115A1												{ quality = 1; price = 10; };
	class CUP_5Rnd_127x108_KSVK_M											{ quality = 1; price = 10; };
	class CUP_10Rnd_762x51_CZ750_Tracer								{ quality = 1; price = 10; };
	class CUP_10Rnd_762x51_CZ750											{ quality = 1; price = 10; };
	class CUP_5Rnd_762x51_M24													{ quality = 1; price = 10; };
	class CUP_10Rnd_127x99_m107												{ quality = 1; price = 10; };
	class CUP_20Rnd_762x51_B_M110											{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Yellow_Tracer_762x51_M110			{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Red_Tracer_762x51_M110				{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Green_Tracer_762x51_M110			{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_White_Tracer_762x51_M110			{ quality = 1; price = 10; };
	class CUP_10Rnd_762x54_SVD_M											{ quality = 1; price = 10; };
	class CUP_10Rnd_9x39_SP5_VSS_M										{ quality = 1; price = 10; };
	class CUP_20Rnd_9x39_SP5_VSS_M										{ quality = 1; price = 10; };
	class CUP_5x_22_LR_17_HMR_M												{ quality = 1; price = 10; };
	//// Assault Rifle
	class CUP_30Rnd_545x39_AK_M												{ quality = 1; price = 10; };
	class CUP_30Rnd_TE1_Green_Tracer_545x39_AK_M			{ quality = 1; price = 10; };
	class CUP_30Rnd_TE1_Red_Tracer_545x39_AK_M				{ quality = 1; price = 10; };
	class CUP_30Rnd_TE1_White_Tracer_545x39_AK_M			{ quality = 1; price = 10; };
	class CUP_30Rnd_TE1_Yellow_Tracer_545x39_AK_M			{ quality = 1; price = 10; };
	class CUP_75Rnd_TE4_LRT4_Green_Tracer_545x39_RPK_M	{ quality = 1; price = 10; };
	class CUP_30Rnd_762x39_AK47_M											{ quality = 1; price = 10; };
	class CUP_30Rnd_556x45_Stanag											{ quality = 1; price = 10; };
	class CUP_30Rnd_556x45_G36												{ quality = 1; price = 10; };
	class CUP_30Rnd_TE1_Red_Tracer_556x45_G36					{ quality = 1; price = 10; };
	class CUP_30Rnd_TE1_Green_Tracer_556x45_G36				{ quality = 1; price = 10; };
	class CUP_30Rnd_TE1_Yellow_Tracer_556x45_G36			{ quality = 1; price = 10; };
	class CUP_100Rnd_556x45_BetaCMag									{ quality = 1; price = 10; };
	class CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag		{ quality = 1; price = 10; };
	class CUP_100Rnd_TE1_Green_Tracer_556x45_BetaCMag	{ quality = 1; price = 10; };
	class CUP_100Rnd_TE1_Yellow_Tracer_556x45_BetaCMag	{ quality = 1; price = 10; };
	class CUP_20Rnd_556x45_Stanag											{ quality = 1; price = 10; };
	class CUP_20Rnd_762x51_CZ805B											{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Yellow_Tracer_762x51_CZ805B		{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Red_Tracer_762x51_CZ805B			{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Green_Tracer_762x51_CZ805B		{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_White_Tracer_762x51_CZ805B		{ quality = 1; price = 10; };
	class CUP_20Rnd_762x51_DMR												{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Yellow_Tracer_762x51_DMR			{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Red_Tracer_762x51_DMR					{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Green_Tracer_762x51_DMR				{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_White_Tracer_762x51_DMR				{ quality = 1; price = 10; };
	class CUP_20Rnd_762x51_FNFAL_M										{ quality = 1; price = 10; };
	class CUP_30Rnd_Sa58_M														{ quality = 1; price = 10; };
	class CUP_30Rnd_Sa58_M_TracerG										{ quality = 1; price = 10; };
	class CUP_30Rnd_Sa58_M_TracerR										{ quality = 1; price = 10; };
	class CUP_30Rnd_Sa58_M_TracerY										{ quality = 1; price = 10; };
	class CUP_20Rnd_762x51_B_SCAR											{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Yellow_Tracer_762x51_SCAR			{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Red_Tracer_762x51_SCAR				{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_Green_Tracer_762x51_SCAR			{ quality = 1; price = 10; };
	class CUP_20Rnd_TE1_White_Tracer_762x51_SCAR			{ quality = 1; price = 10; };

	///////////////////////////////////////////////////////////////////////////////
	// Apex Items & Weapons
	///////////////////////////////////////////////////////////////////////////////
	class hgun_Pistol_01_F														{ quality = 1; price = 65; };
	class hgun_P07_khk_F															{ quality = 1; price = 65; };
	class SMG_05_F																		{ quality = 1; price = 150; };
	class LMG_03_F																		{ quality = 2; price = 300; };
	class arifle_MX_khk_F															{ quality = 2; price = 450; };
	class arifle_MX_GL_khk_F													{ quality = 2; price = 500; };
	class arifle_MXC_khk_F														{ quality = 2; price = 350; };
	class arifle_MXM_khk_F														{ quality = 2; price = 500; };
	class srifle_LRR_tna_F														{ quality = 6; price = 850; };
	class srifle_GM6_ghex_F														{ quality = 6; price = 900; };
	class srifle_DMR_07_blk_F													{ quality = 4; price = 750; };
	class srifle_DMR_07_hex_F													{ quality = 4; price = 750; };
	class srifle_DMR_07_ghex_F												{ quality = 4; price = 750; };
	class arifle_AK12_F																{ quality = 3; price = 650; };
	class arifle_AK12_GL_F														{ quality = 3; price = 700; };
	class arifle_AKM_F																{ quality = 3; price = 400; };
	class arifle_AKM_FL_F															{ quality = 3; price = 400; };
	class arifle_AKS_F																{ quality = 3; price = 350; };
	class arifle_ARX_blk_F														{ quality = 4; price = 900; };
	class arifle_ARX_ghex_F														{ quality = 4; price = 900; };
	class arifle_ARX_hex_F														{ quality = 4; price = 900; };
	class arifle_CTAR_blk_F														{ quality = 2; price = 450; };
	class arifle_CTAR_hex_F														{ quality = 2; price = 450; };
	class arifle_CTAR_ghex_F													{ quality = 2; price = 450; };
	class arifle_CTAR_GL_blk_F												{ quality = 2; price = 450; };
	class arifle_CTARS_blk_F													{ quality = 2; price = 450; };
	class arifle_CTARS_ghex_F													{ quality = 2; price = 450; };
	class arifle_CTARS_hex_F													{ quality = 2; price = 450; };
	class arifle_SPAR_01_blk_F												{ quality = 1; price = 400; };
	class arifle_SPAR_01_khk_F												{ quality = 1; price = 400; };
	class arifle_SPAR_01_snd_F												{ quality = 1; price = 400; };
	class arifle_SPAR_01_GL_blk_F											{ quality = 1; price = 500; };
	class arifle_SPAR_01_GL_khk_F											{ quality = 1; price = 500; };
	class arifle_SPAR_01_GL_snd_F											{ quality = 1; price = 500; };
	class arifle_SPAR_02_blk_F												{ quality = 2; price = 550; };
	class arifle_SPAR_02_khk_F												{ quality = 2; price = 550; };
	class arifle_SPAR_02_snd_F												{ quality = 2; price = 550; };
	class arifle_SPAR_03_blk_F												{ quality = 3; price = 600; };
	class arifle_SPAR_03_khk_F												{ quality = 3; price = 600; };
	class arifle_SPAR_03_snd_F												{ quality = 3; price = 600; };					
	class muzzle_snds_H_khk_F													{ quality = 2; price = 50; };
	class muzzle_snds_H_snd_F													{ quality = 2; price = 50; };
	class muzzle_snds_58_blk_F												{ quality = 1; price = 20; };
	class muzzle_snds_m_khk_F													{ quality = 1; price = 15; };
	class muzzle_snds_m_snd_F													{ quality = 1; price = 15; };
	class muzzle_snds_B_khk_F													{ quality = 3; price = 50; };
	class muzzle_snds_B_snd_F													{ quality = 3; price = 50; };
	class muzzle_snds_58_wdm_F												{ quality = 1; price = 20; };
	class muzzle_snds_65_TI_blk_F											{ quality = 2; price = 75; };
	class muzzle_snds_65_TI_hex_F											{ quality = 2; price = 75; };
	class muzzle_snds_65_TI_ghex_F										{ quality = 2; price = 75; };
	class muzzle_snds_H_MG_blk_F											{ quality = 2; price = 20; };
	class muzzle_snds_H_MG_khk_F											{ quality = 2; price = 20; };
	class optic_Arco_blk_F														{ quality = 1; price = 100; };
	class optic_Arco_ghex_F														{ quality = 1; price = 100; };
	class optic_DMS_ghex_F														{ quality = 2; price = 150; };
	class optic_Hamr_khk_F														{ quality = 3; price = 200; };
	class optic_ERCO_blk_F														{ quality = 1; price = 125; };
	class optic_ERCO_khk_F														{ quality = 1; price = 125; };
	class optic_ERCO_snd_F														{ quality = 1; price = 125; };
	class optic_SOS_khk_F															{ quality = 2; price = 200; };
	class optic_LRPS_tna_F														{ quality = 5; price = 300; };
	class optic_LRPS_ghex_F														{ quality = 5; price = 300; };
	class optic_Holosight_blk_F												{ quality = 1; price = 50; };
	class optic_Holosight_khk_F												{ quality = 1; price = 50; };
	class optic_Holosight_smg_blk_F										{ quality = 1; price = 50; };
	class bipod_01_F_khk															{ quality = 2; price = 10; };
	class O_NVGoggles_hex_F														{ quality = 3; price = 150; };
	class O_NVGoggles_urb_F														{ quality = 3; price = 150; };
	class O_NVGoggles_ghex_F													{ quality = 3; price = 150; };
	class NVGoggles_tna_F															{ quality = 2; price = 100; };
	class U_B_T_Soldier_F															{ quality = 2; price = 40; };
	class U_B_T_Soldier_AR_F													{ quality = 2; price = 40; };
	class U_B_T_Soldier_SL_F													{ quality = 2; price = 40; };
	class U_B_T_Sniper_F															{ quality = 4; price = 100; };
	class U_O_T_Sniper_F															{ quality = 4; price = 100; };
	class U_B_T_FullGhillie_tna_F											{ quality = 5; price = 150; };
	class U_O_T_FullGhillie_tna_F											{ quality = 5; price = 150; };
	class U_B_CTRG_Soldier_F													{ quality = 2; price = 40; };
	class U_B_CTRG_Soldier_2_F												{ quality = 2; price = 40; };
	class U_B_CTRG_Soldier_3_F												{ quality = 2; price = 40; };
	class U_B_GEN_Soldier_F														{ quality = 2; price = 35; };
	class U_B_GEN_Commander_F													{ quality = 2; price = 35; };
	class U_O_T_Soldier_F															{ quality = 2; price = 40; };
	class U_O_T_Officer_F															{ quality = 3; price = 40; };
	class U_I_C_Soldier_Para_1_F											{ quality = 2; price = 30; };
	class U_I_C_Soldier_Para_2_F											{ quality = 2; price = 30; };
	class U_I_C_Soldier_Para_3_F											{ quality = 2; price = 30; };
	class U_I_C_Soldier_Para_4_F											{ quality = 2; price = 30; };
	class U_I_C_Soldier_Para_5_F											{ quality = 2; price = 30; };
	class U_I_C_Soldier_Bandit_1_F										{ quality = 1; price = 15; };
	class U_I_C_Soldier_Bandit_2_F										{ quality = 1; price = 15; };
	class U_I_C_Soldier_Bandit_3_F										{ quality = 1; price = 15; };
	class U_I_C_Soldier_Bandit_4_F										{ quality = 1; price = 15; };
	class U_I_C_Soldier_Bandit_5_F										{ quality = 1; price = 15; };
	class U_I_C_Soldier_Camo_F												{ quality = 2; price = 30; };
	class U_C_man_sport_1_F														{ quality = 1; price = 10; };
	class U_C_man_sport_2_F														{ quality = 1; price = 10; };
	class U_C_man_sport_3_F														{ quality = 1; price = 10; };
	class U_C_Man_casual_1_F													{ quality = 1; price = 10; };
	class U_C_Man_casual_2_F													{ quality = 1; price = 10; };
	class U_C_Man_casual_3_F													{ quality = 1; price = 10; };
	class U_C_Man_casual_4_F													{ quality = 1; price = 10; };
	class U_C_Man_casual_5_F													{ quality = 1; price = 10; };
	class U_C_Man_casual_6_F													{ quality = 1; price = 10; };
	class U_B_CTRG_Soldier_urb_1_F										{ quality = 2; price = 40; };
	class U_B_CTRG_Soldier_urb_2_F										{ quality = 2; price = 40; };
	class U_B_CTRG_Soldier_urb_3_F										{ quality = 2; price = 40; };
	class H_Helmet_Skate															{ quality = 2; price = 20; };
	class H_HelmetB_TI_tna_F													{ quality = 4; price = 100; };
	class H_HelmetB_tna_F															{ quality = 3; price = 50; };
	class H_HelmetB_Enh_tna_F													{ quality = 4; price = 100; };
	class H_HelmetB_Light_tna_F												{ quality = 2; price = 20; };
	class H_HelmetSpecO_ghex_F												{ quality = 5; price = 100; };
	class H_HelmetLeaderO_ghex_F											{ quality = 5; price = 175; };
	class H_HelmetO_ghex_F														{ quality = 5; price = 75; };
	class H_HelmetCrew_O_ghex_F												{ quality = 3; price = 75; };
	class H_MilCap_tna_F															{ quality = 1; price = 8; };
	class H_MilCap_ghex_F															{ quality = 1; price = 8; };
	class H_Booniehat_tna_F														{ quality = 1; price = 4; };
	class H_Beret_gen_F																{ quality = 2; price = 12; };
	class H_MilCap_gen_F															{ quality = 1; price = 10; };
	class H_Cap_oli_Syndikat_F												{ quality = 1; price = 6; };
	class H_Cap_tan_Syndikat_F												{ quality = 1; price = 6; };
	class H_Cap_blk_Syndikat_F												{ quality = 1; price = 6; };
	class H_Cap_grn_Syndikat_F												{ quality = 1; price = 6; };
	class H_FakeHeadgear_Syndikat_F										{ quality = 1; price = 6; };
	class V_TacChestrig_grn_F													{ quality = 1; price = 15; };
	class V_TacChestrig_oli_F													{ quality = 1; price = 15; };
	class V_TacChestrig_cbr_F													{ quality = 1; price = 15; };
	class V_PlateCarrier1_tna_F												{ quality = 3; price = 50; };
	class V_PlateCarrier2_tna_F												{ quality = 3; price = 60; };
	class V_PlateCarrierSpec_tna_F										{ quality = 5; price = 100; };
	class V_PlateCarrierGL_tna_F											{ quality = 6; price = 500; };
	class V_HarnessO_ghex_F														{ quality = 2; price = 50; };
	class V_HarnessOGL_ghex_F													{ quality = 1; price = 30; };
	class V_BandollierB_ghex_F												{ quality = 1; price = 10; };
	class V_TacVest_gen_F															{ quality = 1; price = 25; };
	class V_PlateCarrier1_rgr_noflag_F								{ quality = 2; price = 50; };
	class V_PlateCarrier2_rgr_noflag_F								{ quality = 2; price = 60; };
	class B_Bergen_Base_F															{ quality = 5; price = 400; };
	class B_Bergen_mcamo_F														{ quality = 5; price = 400; };
	class B_Bergen_dgtl_F															{ quality = 5; price = 400; };
	class B_Bergen_hex_F															{ quality = 5; price = 400; };
	class B_Bergen_tna_F															{ quality = 5; price = 400; };
	class B_AssaultPack_tna_F													{ quality = 1; price = 90; };
	class B_Carryall_ghex_F														{ quality = 4; price = 300; };
	class B_FieldPack_ghex_F													{ quality = 2; price = 120; };
	class B_ViperHarness_base_F												{ quality = 3; price = 250; };
	class B_ViperHarness_blk_F												{ quality = 3; price = 250; };
	class B_ViperHarness_ghex_F												{ quality = 3; price = 250; };
	class B_ViperHarness_hex_F												{ quality = 3; price = 250; };
	class B_ViperHarness_khk_F												{ quality = 3; price = 250; };
	class B_ViperHarness_oli_F												{ quality = 3; price = 250; };
	class B_ViperLightHarness_base_F									{ quality = 2; price = 200; };
	class B_ViperLightHarness_blk_F										{ quality = 2; price = 200; };
	class B_ViperLightHarness_ghex_F									{ quality = 2; price = 200; };
	class B_ViperLightHarness_hex_F										{ quality = 2; price = 200; };
	class B_ViperLightHarness_khk_F										{ quality = 2; price = 200; };
	class B_ViperLightHarness_oli_F										{ quality = 2; price = 200; };
	//// Ammo
	class 30Rnd_9x21_Mag_SMG_02												{ quality = 1; price = 10; };
	class 30Rnd_9x21_Mag_SMG_02_Tracer_Red						{ quality = 1; price = 15; };
	class 30Rnd_9x21_Mag_SMG_02_Tracer_Yellow					{ quality = 1; price = 15; };
	class 30Rnd_9x21_Mag_SMG_02_Tracer_Green					{ quality = 1; price = 15; };
	class 30Rnd_580x42_Mag_F													{ quality = 2; price = 15; };
	class 30Rnd_580x42_Mag_Tracer_F										{ quality = 2; price = 15; };
	class 100Rnd_580x42_Mag_F													{ quality = 2; price = 15; };
	class 100Rnd_580x42_Mag_Tracer_F									{ quality = 2; price = 15; };
	class 20Rnd_650x39_Cased_Mag_F										{ quality = 2; price = 20; };
	class 10Rnd_50BW_Mag_F														{ quality = 2; price = 35; };
	class 150Rnd_556x45_Drum_Mag_F										{ quality = 2; price = 75; };
	class 150Rnd_556x45_Drum_Mag_Tracer_F							{ quality = 2; price = 75; };
	class 30Rnd_762x39_Mag_F													{ quality = 2; price = 25; };
	class 30Rnd_762x39_Mag_Green_F										{ quality = 2; price = 25; };
	class 30Rnd_762x39_Mag_Tracer_F										{ quality = 2; price = 25; };
	class 30Rnd_762x39_Mag_Tracer_Green_F							{ quality = 2; price = 25; };
	class 30Rnd_545x39_Mag_F													{ quality = 1; price = 10; };
	class 30Rnd_545x39_Mag_Green_F										{ quality = 1; price = 10; };
	class 30Rnd_545x39_Mag_Tracer_F										{ quality = 1; price = 10; };
	class 30Rnd_545x39_Mag_Tracer_Green_F							{ quality = 1; price = 10; };
	class 200Rnd_556x45_Box_F													{ quality = 1; price = 90; };
	class 200Rnd_556x45_Box_Red_F											{ quality = 1; price = 90; };
	class 200Rnd_556x45_Box_Tracer_F									{ quality = 1; price = 90; };
	class 200Rnd_556x45_Box_Tracer_Red_F							{ quality = 1; price = 90; };
	class 10Rnd_9x21_Mag															{ quality = 1; price = 10; };
	
	// Jets DLC items
	class V_DeckCrew_yellow_F													{ quality = 2; price = 30; };
	class V_DeckCrew_blue_F														{ quality = 2; price = 30; };
	class V_DeckCrew_green_F													{ quality = 2; price = 30; };
	class V_DeckCrew_red_F														{ quality = 2; price = 30; };
	class V_DeckCrew_white_F													{ quality = 2; price = 30; };
	class V_DeckCrew_brown_F													{ quality = 2; price = 30; };
	class V_DeckCrew_violet_F													{ quality = 2; price = 30; };

	///////////////////////////////////////////////////////////////////////////////
	// BIKES
	///////////////////////////////////////////////////////////////////////////////
	//class Exile_Bike_OldBike 												{ quality = 1; price = 40; };
	//class Exile_Bike_MountainBike 									{ quality = 1; price = 50; };
	//class CUP_B_M1030																{ quality = 1; price = 2500; };

	///////////////////////////////////////////////////////////////////////////////
	// QUAD BIKES
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Bike_QuadBike_Black									{ quality = 1; price = 2500; };
	class Exile_Bike_QuadBike_Blue									{ quality = 1; price = 2500; };
	class Exile_Bike_QuadBike_Red										{ quality = 1; price = 2500; };
	class Exile_Bike_QuadBike_White									{ quality = 1; price = 2500; };
	class Exile_Bike_QuadBike_Nato									{ quality = 1; price = 2500; };
	class Exile_Bike_QuadBike_Csat									{ quality = 1; price = 2500; };
	class Exile_Bike_QuadBike_Fia										{ quality = 1; price = 2500; };
	class Exile_Bike_QuadBike_Guerilla01						{ quality = 1; price = 2500; };
	class Exile_Bike_QuadBike_Guerilla02						{ quality = 1; price = 2500; };

	///////////////////////////////////////////////////////////////////////////////
	// KARTS
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Kart_BluKing										{ quality = 1; price = 1100; };
	class Exile_Car_Kart_RedStone										{ quality = 1; price = 1100; };
	class Exile_Car_Kart_Vrana											{ quality = 1; price = 1100; };
	class Exile_Car_Kart_Green											{ quality = 1; price = 1100; };
	class Exile_Car_Kart_Blue												{ quality = 1; price = 1100; };
	class Exile_Car_Kart_Orange											{ quality = 1; price = 1100; };
	class Exile_Car_Kart_White											{ quality = 1; price = 1100; };
	class Exile_Car_Kart_Yellow											{ quality = 1; price = 1100; };
	class Exile_Car_Kart_Black											{ quality = 1; price = 1100; };

	///////////////////////////////////////////////////////////////////////////////
	// MOTOR BOATS
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Boat_MotorBoat_Police								{ quality = 1; price = 700; };
	class Exile_Boat_MotorBoat_Orange								{ quality = 1; price = 700; };
	class Exile_Boat_MotorBoat_White								{ quality = 1; price = 700; };

	///////////////////////////////////////////////////////////////////////////////
	// RUBBER DUCKS
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Boat_RubberDuck_CSAT								{ quality = 1; price = 500; };
	class Exile_Boat_RubberDuck_Digital							{ quality = 1; price = 500; };
	class Exile_Boat_RubberDuck_Orange							{ quality = 1; price = 500; };
	class Exile_Boat_RubberDuck_Blue								{ quality = 1; price = 500; };
	class Exile_Boat_RubberDuck_Black								{ quality = 1; price = 500; };

	///////////////////////////////////////////////////////////////////////////////
	// SDV
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Boat_SDV_CSAT												{ quality = 2; price = 11000; };
	class Exile_Boat_SDV_Digital										{ quality = 2; price = 11000; };
	class Exile_Boat_SDV_Grey												{ quality = 2; price = 11000; };

	///////////////////////////////////////////////////////////////////////////////
	// UH-1H Huey
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Huey_Green 									{ quality = 2; price = 21000; };
	class Exile_Chopper_Huey_Desert									{ quality = 2; price = 21000; };
	class Exile_Chopper_Huey_Armed_Green						{ quality = 2; price = 30000; };
	class Exile_Chopper_Huey_Armed_Desert						{ quality = 2; price = 30000; };

	///////////////////////////////////////////////////////////////////////////////
	// Hellcat
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Hellcat_Green								{ quality = 3; price = 27500; };
	class Exile_Chopper_Hellcat_FIA									{ quality = 3; price = 27500; };

	///////////////////////////////////////////////////////////////////////////////
	// Hummingbird
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Hummingbird_Green						{ quality = 3; price = 23000; };

	///////////////////////////////////////////////////////////////////////////////
	// Hummingbird (Civillian)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Hummingbird_Civillian_Blue				{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Red					{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_ION					{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_BlueLine		{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Digital			{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Elliptical	{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Furious			{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_GrayWatcher	{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Jeans				{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Light				{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Shadow			{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Sheriff			{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Speedy			{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Sunset			{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Vrana				{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Wasp				{ quality = 1; price = 17000; };
	class Exile_Chopper_Hummingbird_Civillian_Wave				{ quality = 1; price = 17000; };

	///////////////////////////////////////////////////////////////////////////////
	// Huron
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Huron_Black								{ quality = 5; price = 50000; };
	class Exile_Chopper_Huron_Green								{ quality = 5; price = 50000; };

	///////////////////////////////////////////////////////////////////////////////
	// Mohawk
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Mohawk_FIA								{ quality = 4; price = 45000; };

	///////////////////////////////////////////////////////////////////////////////
	// Orca
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Orca_CSAT									{ quality = 3; price = 28000; };
	class Exile_Chopper_Orca_Black								{ quality = 3; price = 28000; };
	class Exile_Chopper_Orca_BlackCustom					{ quality = 3; price = 28000; };

	///////////////////////////////////////////////////////////////////////////////
	// Taru
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Taru_Transport_CSAT				{ quality = 3; price = 20000; };
	class Exile_Chopper_Taru_Transport_Black			{ quality = 3; price = 20000; };
	class Exile_Chopper_Taru_CSAT									{ quality = 3; price = 30000; };
	class Exile_Chopper_Taru_Black								{ quality = 3; price = 30000; };
	class Exile_Chopper_Taru_Covered_CSAT					{ quality = 3; price = 30000; };
	class Exile_Chopper_Taru_Covered_Black				{ quality = 3; price = 30000; };

	///////////////////////////////////////////////////////////////////////////////
	// Cessna
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Plane_Cessna											{ quality = 1; price = 16500; };

	///////////////////////////////////////////////////////////////////////////////
	// An-2
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Plane_AN2_Green										{ quality = 2; price = 17000; };
	class Exile_Plane_AN2_White										{ quality = 2; price = 17000; };
	class Exile_Plane_AN2_Stripe									{ quality = 2; price = 17000; };

	///////////////////////////////////////////////////////////////////////////////
	// Hatchback
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Hatchback_Beige								{ quality = 1; price = 12000; };
	class Exile_Car_Hatchback_Green								{ quality = 1; price = 12000; };
	class Exile_Car_Hatchback_Blue								{ quality = 1; price = 12000; };
	class Exile_Car_Hatchback_BlueCustom					{ quality = 1; price = 12000; };
	class Exile_Car_Hatchback_BeigeCustom					{ quality = 1; price = 12000; };
	class Exile_Car_Hatchback_Yellow							{ quality = 1; price = 12000; };
	class Exile_Car_Hatchback_Grey								{ quality = 1; price = 12000; };
	class Exile_Car_Hatchback_Black								{ quality = 1; price = 12000; };
	class Exile_Car_Hatchback_Dark								{ quality = 1; price = 12000; };
	class Exile_Car_Hatchback_Rusty1							{ quality = 1; price = 12000; };
	class Exile_Car_Hatchback_Rusty2							{ quality = 1; price = 12000; };
	class Exile_Car_Hatchback_Rusty3							{ quality = 1; price = 12000; };

	///////////////////////////////////////////////////////////////////////////////
	// Golf
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Golf_Red												{ quality = 1; price = 12000; };
	class Exile_Car_Golf_Black											{ quality = 1; price = 12000; };
	class Golf_Civ_pink															{ quality = 1; price = 12000; };
	class CUP_C_Golf4_red_Civ												{ quality = 1; price = 12000; };
	class CUP_C_Golf4_black_Civ											{ quality = 1; price = 12000; };
	class CUP_C_Golf4_yellow_Civ										{ quality = 1; price = 12000; };
	class CUP_C_Golf4_blue_Civ											{ quality = 1; price = 12000; };
	class CUP_C_Golf4_white_Civ											{ quality = 1; price = 12000; };
	class CUP_C_Golf4_green_Civ											{ quality = 1; price = 12000; };
	class CUP_C_Golf4_camo_Civ											{ quality = 1; price = 16000; };
	class CUP_C_Golf4_camodigital_Civ								{ quality = 1; price = 16000; };
	class CUP_C_Golf4_camodark_Civ									{ quality = 1; price = 16000; };
	class CUP_C_Golf4_reptile_Civ										{ quality = 1; price = 16000; };
	class CUP_C_Golf4_whiteblood_Civ								{ quality = 1; price = 16000; };
	class CUP_C_Golf4_crowe_Civ											{ quality = 1; price = 16000; };

	///////////////////////////////////////////////////////////////////////////////
	// Ikarus
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Ikarus_Blue 										{ quality = 1; price = 8000; };
	class Exile_Car_Ikarus_Red 											{ quality = 1; price = 8000; };
	class Exile_Car_Ikarus_Party 										{ quality = 1; price = 8000; };

	///////////////////////////////////////////////////////////////////////////////
	// Ural (Open)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Ural_Open_Blue								{ quality = 1; price = 12500; };
	class Exile_Car_Ural_Open_Yellow							{ quality = 1; price = 12500; };
	class Exile_Car_Ural_Open_Worker							{ quality = 1; price = 12500; };
	class Exile_Car_Ural_Open_Military						{ quality = 1; price = 12500; };

	///////////////////////////////////////////////////////////////////////////////
	// Ural (Covered)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Ural_Covered_Blue								{ quality = 1; price = 12500; };
	class Exile_Car_Ural_Covered_Yellow							{ quality = 1; price = 12500; };
	class Exile_Car_Ural_Covered_Worker							{ quality = 1; price = 12500; };
	class Exile_Car_Ural_Covered_Military						{ quality = 1; price = 12500; };

	///////////////////////////////////////////////////////////////////////////////
	// V3S
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_V3S_Open											{ quality = 1; price = 16000; };
	class Exile_Car_V3S_Covered										{ quality = 1; price = 16000; };

	///////////////////////////////////////////////////////////////////////////////
	// SUVXL
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_SUVXL_Black 									{ quality = 3; price = 20000; };

	///////////////////////////////////////////////////////////////////////////////
	// Tractor
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Tractor_Red 									{ quality = 1; price = 2000; };

	///////////////////////////////////////////////////////////////////////////////
	// Tractor (Old)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_OldTractor_Red 									{ quality = 1; price = 1200; };

	///////////////////////////////////////////////////////////////////////////////
	// Tow Tractor
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_TowTractor_White								{ quality = 1; price = 1800; };

	///////////////////////////////////////////////////////////////////////////////
	// Octavius
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Octavius_White									{ quality = 2; price = 6000; };
	class Exile_Car_Octavius_Black									{ quality = 2; price = 6000; };

	///////////////////////////////////////////////////////////////////////////////
	// UAZ
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_UAZ_Green												{ quality = 2; price = 7000; };

	///////////////////////////////////////////////////////////////////////////////
	// UAZ (Open)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_UAZ_Open_Green									{ quality = 2; price = 8000; };

	///////////////////////////////////////////////////////////////////////////////
	// Land Rover
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_LandRover_Red 								{ quality = 2; price = 11000; };
	class Exile_Car_LandRover_Urban 							{ quality = 2; price = 11000; };
	class Exile_Car_LandRover_Green 							{ quality = 2; price = 11000; };
	class Exile_Car_LandRover_Sand 								{ quality = 2; price = 11000; };
	class Exile_Car_LandRover_Desert 							{ quality = 2; price = 11000; };

	///////////////////////////////////////////////////////////////////////////////
	// Land Rover (Ambulance)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_LandRover_Ambulance_Green				{ quality = 2; price = 12000; };
	class Exile_Car_LandRover_Ambulance_Desert			{ quality = 2; price = 12000; };
	class Exile_Car_LandRover_Ambulance_Sand				{ quality = 2; price = 12000; };

	///////////////////////////////////////////////////////////////////////////////
	// Lada
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Lada_Green 											{ quality = 2; price = 6000; };
	class Exile_Car_Lada_Taxi 											{ quality = 2; price = 6000; };
	class Exile_Car_Lada_Red 												{ quality = 2; price = 6000; };
	class Exile_Car_Lada_White 											{ quality = 2; price = 6000; };
	class Exile_Car_Lada_Hipster 										{ quality = 2; price = 6000; };

	///////////////////////////////////////////////////////////////////////////////
	// Volha
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Volha_Blue											{ quality = 2; price = 6000; };
	class Exile_Car_Volha_White											{ quality = 2; price = 6000; };
	class Exile_Car_Volha_Black											{ quality = 2; price = 6000; };

	///////////////////////////////////////////////////////////////////////////////
	// Hatchback (Sport)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Hatchback_Sport_Red							{ quality = 2; price = 14000; };
	class Exile_Car_Hatchback_Sport_Blue						{ quality = 2; price = 14000; };
	class Exile_Car_Hatchback_Sport_Orange					{ quality = 2; price = 14000; };
	class Exile_Car_Hatchback_Sport_White						{ quality = 2; price = 14000; };
	class Exile_Car_Hatchback_Sport_Beige						{ quality = 2; price = 14000; };
	class Exile_Car_Hatchback_Sport_Green						{ quality = 2; price = 14000; };

	///////////////////////////////////////////////////////////////////////////////
	// HEMMT
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_HEMMT 												{ quality = 2; price = 48000; };

	///////////////////////////////////////////////////////////////////////////////
	// Strider
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Strider 											{ quality = 2; price = 25000; };
	class I_MRAP_03_hmg_F 												{ quality = 5; price = 35000; };

	///////////////////////////////////////////////////////////////////////////////
	// Hunter
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Hunter 												{ quality = 2; price = 25000; };
	class B_MRAP_01_hmg_F 												{ quality = 5; price = 33000; };

	///////////////////////////////////////////////////////////////////////////////
	// Ifrit
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Ifrit 												{ quality = 2; price = 25000; };
	class O_MRAP_02_hmg_F 												{ quality = 5; price = 33000; };

	///////////////////////////////////////////////////////////////////////////////
	// MSE-3 Marid
	///////////////////////////////////////////////////////////////////////////////
	class O_T_APC_Wheeled_02_rcws_ghex_F 					{ quality = 5; price = 35000; };
	class O_APC_Wheeled_02_rcws_F 								{ quality = 5; price = 35000; };

	///////////////////////////////////////////////////////////////////////////////
	// Offroad
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Offroad_Red										{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Beige									{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_White									{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Blue									{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_DarkRed								{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_BlueCustom						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla01						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla02						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla03						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla04						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla05						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla06						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla07						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla08						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla09						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla10						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla11						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Guerilla12						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Rusty1								{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Rusty2								{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Rusty3								{ quality = 2; price = 12000; };

	///////////////////////////////////////////////////////////////////////////////
	// Offroad (Armed)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Offroad_Armed_Guerilla01 			{ quality = 3; price = 16000; };
	class Exile_Car_Offroad_Armed_Guerilla02 			{ quality = 3; price = 16000; };
	class Exile_Car_Offroad_Armed_Guerilla03 			{ quality = 3; price = 16000; };
	class Exile_Car_Offroad_Armed_Guerilla04 			{ quality = 3; price = 16000; };
	class Exile_Car_Offroad_Armed_Guerilla05 			{ quality = 3; price = 16000; };
	class Exile_Car_Offroad_Armed_Guerilla06 			{ quality = 3; price = 16000; };
	class Exile_Car_Offroad_Armed_Guerilla07 			{ quality = 3; price = 16000; };
	class Exile_Car_Offroad_Armed_Guerilla08 			{ quality = 3; price = 16000; };
	class Exile_Car_Offroad_Armed_Guerilla09 			{ quality = 3; price = 16000; };
	class Exile_Car_Offroad_Armed_Guerilla10 			{ quality = 3; price = 16000; };
	class Exile_Car_Offroad_Armed_Guerilla11 			{ quality = 3; price = 16000; };
	class Exile_Car_Offroad_Armed_Guerilla12 			{ quality = 3; price = 16000; };

	///////////////////////////////////////////////////////////////////////////////
	// Offroad (Repair)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Offroad_Repair_Civillian 				{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Red 							{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Beige 						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_White 						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Blue 						{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_DarkRed 					{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_BlueCustom 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla01 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla02 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla03 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla04 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla05 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla06 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla07 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla08 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla09 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla10 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla11 			{ quality = 2; price = 12000; };
	class Exile_Car_Offroad_Repair_Guerilla12 			{ quality = 2; price = 12000; };

	///////////////////////////////////////////////////////////////////////////////
	// SUV
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_SUV_Red 											{ quality = 2; price = 14000; };
	class Exile_Car_SUV_Black 										{ quality = 2; price = 14000; };
	class Exile_Car_SUV_Grey 											{ quality = 2; price = 14000; };
	class Exile_Car_SUV_Orange 										{ quality = 2; price = 14000; };

	///////////////////////////////////////////////////////////////////////////////
	// SUV (Armed)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_SUV_Armed_Black 							{ quality = 4; price = 25000; };

	///////////////////////////////////////////////////////////////////////////////
	// BRDM2
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_BRDM2_HQ 											{ quality = 5; price = 25000; };

	///////////////////////////////////////////////////////////////////////////////
	// BTR40
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_BTR40_MG_Green 								{ quality = 3; price = 38000; };
	class Exile_Car_BTR40_MG_Camo 								{ quality = 3; price = 38000; };
	class Exile_Car_BTR40_Green 									{ quality = 2; price = 15000; };
	class Exile_Car_BTR40_Camo 										{ quality = 2; price = 15000; };

	///////////////////////////////////////////////////////////////////////////////
	// HMMWV
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_HMMWV_M134_Green 							{ quality = 3; price = 33000; };
	class Exile_Car_HMMWV_M134_Desert 						{ quality = 3; price = 33000; };
	class Exile_Car_HMMWV_M2_Green 								{ quality = 3; price = 40000; };
	class Exile_Car_HMMWV_M2_Desert 							{ quality = 3; price = 40000; };
	class Exile_Car_HMMWV_MEV_Green 							{ quality = 3; price = 21000; };
	class Exile_Car_HMMWV_MEV_Desert 							{ quality = 3; price = 21000; };
	class Exile_Car_HMMWV_UNA_Green 							{ quality = 3; price = 21000; };
	class Exile_Car_HMMWV_UNA_Desert 							{ quality = 3; price = 21000; };

	///////////////////////////////////////////////////////////////////////////////
	// Tempest
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Tempest 											{ quality = 4; price = 48300; };

	///////////////////////////////////////////////////////////////////////////////
	// Van
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Van_Black 										{ quality = 2; price = 12000; };
	class Exile_Car_Van_White 										{ quality = 2; price = 12000; };
	class Exile_Car_Van_Red 											{ quality = 2; price = 12000; };
	class Exile_Car_Van_Guerilla01 								{ quality = 2; price = 12000; };
	class Exile_Car_Van_Guerilla02 								{ quality = 2; price = 12000; };
	class Exile_Car_Van_Guerilla03 								{ quality = 2; price = 12000; };
	class Exile_Car_Van_Guerilla04 								{ quality = 2; price = 12000; };
	class Exile_Car_Van_Guerilla05 								{ quality = 2; price = 12000; };
	class Exile_Car_Van_Guerilla06 								{ quality = 2; price = 12000; };
	class Exile_Car_Van_Guerilla07 								{ quality = 2; price = 12000; };
	class Exile_Car_Van_Guerilla08 								{ quality = 2; price = 12000; };

	///////////////////////////////////////////////////////////////////////////////
	// Van (Box)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Van_Box_Black 								{ quality = 2; price = 17000; };
	class Exile_Car_Van_Box_White 								{ quality = 2; price = 17000; };
	class Exile_Car_Van_Box_Red 									{ quality = 2; price = 17000; };
	class Exile_Car_Van_Box_Guerilla01 						{ quality = 2; price = 17000; };
	class Exile_Car_Van_Box_Guerilla02 						{ quality = 2; price = 17000; };
	class Exile_Car_Van_Box_Guerilla03 						{ quality = 2; price = 17000; };
	class Exile_Car_Van_Box_Guerilla04 						{ quality = 2; price = 17000; };
	class Exile_Car_Van_Box_Guerilla06 						{ quality = 2; price = 17000; };
	class Exile_Car_Van_Box_Guerilla07 						{ quality = 2; price = 17000; };
	class Exile_Car_Van_Box_Guerilla08 						{ quality = 2; price = 17000; };

	///////////////////////////////////////////////////////////////////////////////
	// Van (Fuel)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Van_Fuel_Black								{ quality = 3; price = 22000; };
	class Exile_Car_Van_Fuel_White								{ quality = 3; price = 22000; };
	class Exile_Car_Van_Fuel_Red									{ quality = 3; price = 22000; };
	class Exile_Car_Van_Fuel_Guerilla01						{ quality = 3; price = 22000; };
	class Exile_Car_Van_Fuel_Guerilla02						{ quality = 3; price = 22000; };
	class Exile_Car_Van_Fuel_Guerilla03						{ quality = 3; price = 22000; };

	///////////////////////////////////////////////////////////////////////////////
	// Zamak
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Zamak 												{ quality = 4; price = 43000; };

	///////////////////////////////////////////////////////////////////////////////
	// Water Scooter
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Boat_WaterScooter									{ quality = 2; price = 800; };

	///////////////////////////////////////////////////////////////////////////////
	// RHIB
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Boat_RHIB													{ quality = 2; price = 1500; };

	///////////////////////////////////////////////////////////////////////////////
	// Ceaser BTT
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Plane_Ceasar											{ quality = 2; price = 15000; };

	///////////////////////////////////////////////////////////////////////////////
	// V-44 X Blackfish
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Plane_BlackfishInfantry							{ quality = 6; price = 60000; };
	class Exile_Plane_BlackfishVehicle							{ quality = 6; price = 60000; };

	///////////////////////////////////////////////////////////////////////////////
	// Prowler
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_ProwlerLight									{ quality = 3; price = 22000; };
	class Exile_Car_ProwlerUnarmed								{ quality = 3; price = 22000; };

	///////////////////////////////////////////////////////////////////////////////
	// Qilin
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_QilinUnarmed									{ quality = 3; price = 22000; };

	///////////////////////////////////////////////////////////////////////////////
	// MB 4WD
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_MB4WD													{ quality = 2; price = 15000; };
	class Exile_Car_MB4WDOpen											{ quality = 2; price = 15000; };

	///////////////////////////////////////////////////////////////////////////////
	// Arma Boats
	///////////////////////////////////////////////////////////////////////////////
	class I_Boat_Armed_01_minigun_F								{ quality = 5; price = 16500; };
	class B_Boat_Armed_01_minigun_F								{ quality = 5; price = 16500; };
	class O_Boat_Armed_01_hmg_F									{ quality = 5; price = 15500; };

	///////////////////////////////////////////////////////////////////////////////
	// Arma Choppers
	///////////////////////////////////////////////////////////////////////////////
	//Hummingbird
	class B_Heli_Light_01_F												{ quality = 1; price = 18000; };
	class B_Heli_Light_01_stripped_F							{ quality = 1; price = 18000; };
	class B_Heli_Light_01_armed_F									{ quality = 5; price = 30000; };
	class CUP_B_AH6M_Cannons_USA									{ quality = 5; price = 30000; };
	//Ghost Hawk
	class B_CTRG_Heli_Transport_01_tropic_F				{ quality = 2; price = 22500; };
	class B_CTRG_Heli_Transport_01_sand_F					{ quality = 2; price = 22500; };
	class B_Heli_Transport_01_F										{ quality = 6; price = 22500; };
	class B_Heli_Transport_01_camo_F							{ quality = 6; price = 22500; };
	//ORCA
	class O_Heli_Light_02_unarmed_F								{ quality = 3; price = 23500; };
	class O_Heli_Light_02_F												{ quality = 6; price = 35500; };
	class O_Heli_Light_02_v2_F										{ quality = 6; price = 35500; };
	//Hellcat
	class I_Heli_light_03_unarmed_F								{ quality = 2; price = 21500; };
	class I_Heli_light_03_F												{ quality = 6; price = 33500; };
	
	///////////////////////////////////////////////////////////////////////////////
	// CUP Vehicles
	///////////////////////////////////////////////////////////////////////////////
	//// Unarmed
	class CUP_V3S_Open_NAPA												{ quality = 1; price = 16000; };
	class CUP_O_Ural_Open_RU											{ quality = 1; price = 12500; };
	class CUP_B_Ural_Open_CDF											{ quality = 1; price = 12500; };
	class CUP_B_MTVR_USMC													{ quality = 1; price = 12500; };
	class CUP_O_Ural_RU														{ quality = 1; price = 12500; };
	class CUP_B_Ural_CDF													{ quality = 1; price = 12500; };
	class CUP_B_MTVR_Ammo_USMC										{ quality = 3; price = 16500; };
	class CUP_O_Ural_Reammo_RU										{ quality = 3; price = 16500; };
	class CUP_B_Ural_Reammo_CDF										{ quality = 3; price = 16500; };
	class CUP_B_MTVR_Repair_USMC									{ quality = 3; price = 14000; };
	class CUP_O_Ural_Repair_RU										{ quality = 3; price = 14000; };
	class CUP_B_Ural_Repair_CDF										{ quality = 3; price = 14000; };
	class CUP_B_MTVR_Refuel_USMC									{ quality = 3; price = 15500; };
	class CUP_O_Ural_Refuel_RU										{ quality = 3; price = 15500; };
	class CUP_B_Ural_Refuel_CDF										{ quality = 3; price = 15500; };
	class CUP_C_LR_Transport_CTK									{ quality = 1; price = 12800; };
	class CUP_O_LR_Transport_TKA									{ quality = 1; price = 12800; };
	class CUP_O_LR_Transport_TKM									{ quality = 1; price = 12800; };
	class CUP_B_LR_Transport_CZ_W									{ quality = 1; price = 12800; };
	class CUP_B_LR_Transport_CZ_D									{ quality = 1; price = 12800; };
	class CUP_B_LR_Transport_GB_W									{ quality = 1; price = 12800; };
	class CUP_B_LR_Transport_GB_D									{ quality = 1; price = 12800; };
	class CUP_B_LR_Ambulance_CZ_W									{ quality = 1; price = 12800; };
	class CUP_B_LR_Ambulance_CZ_D									{ quality = 1; price = 12800; };
	class CUP_B_LR_Ambulance_GB_W									{ quality = 1; price = 12800; };
	class CUP_B_LR_Ambulance_GB_D									{ quality = 1; price = 12800; };
	class CUP_O_LR_Ambulance_TKA									{ quality = 1; price = 12800; };
	class CUP_C_UAZ_Unarmed_TK_CIV								{ quality = 1; price = 12500; };
	class CUP_O_UAZ_Unarmed_RU										{ quality = 1; price = 12500; };
	class CUP_I_UAZ_Unarmed_UN										{ quality = 1; price = 12500; };
	class CUP_O_UAZ_Unarmed_TKA										{ quality = 1; price = 12500; };
	class CUP_O_UAZ_Unarmed_CHDKZ									{ quality = 1; price = 12500; };
	class CUP_B_UAZ_Unarmed_ACR										{ quality = 1; price = 12500; };
	class CUP_B_UAZ_Unarmed_CDF										{ quality = 1; price = 12500; };
	class CUP_O_UAZ_Open_CHDKZ										{ quality = 1; price = 12500; };
	class CUP_O_UAZ_Open_RU												{ quality = 1; price = 12500; };
	class CUP_O_UAZ_Open_TKA											{ quality = 1; price = 12500; };
	class CUP_I_UAZ_Open_UN												{ quality = 1; price = 12500; };
	class CUP_B_UAZ_Open_ACR											{ quality = 1; price = 12500; };
	class CUP_B_UAZ_Open_CDF											{ quality = 1; price = 12500; };
	class CUP_C_UAZ_Open_TK_CIV										{ quality = 1; price = 12500; };
	class CUP_B_HMMWV_Unarmed_USA									{ quality = 2; price = 13000; };
	class CUP_B_HMMWV_Unarmed_USMC								{ quality = 2; price = 13000; };
	class CUP_B_HMMWV_Ambulance_USMC							{ quality = 2; price = 13000; };
	class CUP_B_HMMWV_Ambulance_USA								{ quality = 2; price = 13000; };
	class CUP_B_HMMWV_Ambulance_ACR								{ quality = 2; price = 13000; };
	class CUP_B_HMMWV_Transport_USA								{ quality = 2; price = 13000; };
	//// Armed
	class CUP_O_UAZ_MG_RU													{ quality = 3; price = 22500; };
	class CUP_O_GAZ_Vodnik_PK_RU									{ quality = 3; price = 25000; }; 
	class CUP_B_LR_Special_CZ_W										{ quality = 3; price = 24500; };
	class CUP_B_LR_Special_Des_CZ_D								{ quality = 3; price = 24500; };
	class CUP_B_LR_MG_CZ_W												{ quality = 3; price = 24500; };
	class CUP_B_LR_MG_GB_W												{ quality = 3; price = 24500; };
	class CUP_B_HMMWV_M1114_USMC									{ quality = 3; price = 25000; };
	class CUP_B_HMMWV_M2_USMC											{ quality = 3; price = 25000; };
	class CUP_B_HMMWV_Crows_M2_USA								{ quality = 3; price = 25000; };
	class CUP_B_HMMWV_M2_GPK_USA									{ quality = 3; price = 26500; };
	class CUP_B_HMMWV_M2_USA											{ quality = 3; price = 26500; };
	class CUP_B_HMMWV_DSHKM_GPK_ACR								{ quality = 3; price = 26500; };
	class CUP_B_HMMWV_SOV_USA											{ quality = 3; price = 28500; };
	class CUP_B_Dingo_GER_Wdl											{ quality = 4; price = 31500; };
	class CUP_B_Dingo_GER_Des											{ quality = 4; price = 31500; };
	class CUP_B_Dingo_CZ_Wdl											{ quality = 4; price = 31500; };
	class CUP_B_BAF_Coyote_L2A1_W									{ quality = 3; price = 28500; };
	class CUP_B_Jackal2_L2A1_GB_W									{ quality = 3; price = 28500; };
	class CUP_B_M1126_ICV_M2_Woodland_Slat				{ quality = 3; price = 35500; };
	class CUP_B_M1126_ICV_M2_Woodland							{ quality = 3; price = 28500; };
	class CUP_B_M1130_CV_M2_Woodland_Slat					{ quality = 3; price = 35500; };
	class CUP_B_M1130_CV_M2_Woodland							{ quality = 3; price = 28500; };
	class CUP_B_RG31_M2_USMC											{ quality = 3; price = 32500; };
	class CUP_B_RG31_M2_GC_USMC										{ quality = 3; price = 32500; };
	class CUP_B_RG31_M2_OD_USMC										{ quality = 3; price = 32500; };
	class CUP_B_RG31E_M2_USMC											{ quality = 3; price = 32500; };
	class CUP_B_Mastiff_HMG_GB_W									{ quality = 5; price = 42500; };
	class CUP_B_Mastiff_HMG_GB_D									{ quality = 5; price = 42500; };
	class CUP_B_Mastiff_LMG_GB_W									{ quality = 5; price = 42500; };
	class CUP_B_Mastiff_LMG_GB_D									{ quality = 5; price = 42500; };
	class CUP_B_Ridgback_HMG_GB_W									{ quality = 5; price = 40500; };
	class CUP_B_Ridgback_HMG_GB_D									{ quality = 5; price = 40500; };
	class CUP_B_Ridgback_LMG_GB_W									{ quality = 5; price = 40500; };
	class CUP_B_Ridgback_LMG_GB_D									{ quality = 5; price = 40500; };
	class CUP_B_Wolfhound_HMG_GB_W								{ quality = 5; price = 43500; };
	class CUP_B_Wolfhound_HMG_GB_D								{ quality = 5; price = 43500; };
	class CUP_B_Wolfhound_LMG_GB_W								{ quality = 5; price = 43500; };
	class CUP_B_Wolfhound_LMG_GB_D								{ quality = 5; price = 43500; };
	class CUP_B_Ural_ZU23_CDF											{ quality = 6; price = 75000; };
	class CUP_O_Ural_ZU23_CHDKZ										{ quality = 6; price = 75000; };
	class CUP_O_Ural_ZU23_RU											{ quality = 6; price = 75000; };
	class CUP_O_Ural_ZU23_TKA											{ quality = 6; price = 75000; };
	class CUP_O_ZSU23_CSAT												{ quality = 6; price = 100000; };
	class CUP_O_ZSU23_SLA													{ quality = 6; price = 100000; };
	class CUP_O_ZSU23_TK													{ quality = 6; price = 100000; };
	class CUP_I_ZSU23_AAF													{ quality = 6; price = 100000; };
	class CUP_B_AAV_USMC													{ quality = 3; price = 31500; };
	class CUP_I_AAV_RACS													{ quality = 3; price = 31500; };
	//// CUP Drones
	class CUP_B_AH6X_USA													{ quality = 6; price = 30000; };// Unmanned Littlebird (BLUFOR)
	class CUP_B_Pchela1T_CDF											{ quality = 6; price = 15000; };// Pchela1T (CDF) (BLUFOR)
	class CUP_O_Pchela1T_RU												{ quality = 6; price = 15000; };// Pchela1T (RU) (OPFOR)
	//// CUP Choppers
	class CUP_B_CH53E_USMC												{ quality = 1; price = 20000; };
	class CUP_B_CH53E_VIV_USMC										{ quality = 1; price = 30000; };
	class CUP_B_UH1Y_UNA_F												{ quality = 1; price = 20000; };
	class CUP_B_UH1Y_MEV_F												{ quality = 1; price = 20000; };
	class CUP_C_Mi17_Civilian_RU									{ quality = 1; price = 20000; };
	class CUP_B_Mi17_CDF													{ quality = 1; price = 30000; };
	class CUP_O_Mi17_TK														{ quality = 1; price = 30000; };
	class CUP_B_Mi17_medevac_CDF									{ quality = 1; price = 20000; };
	class CUP_B_Mi171Sh_Unarmed_ACR								{ quality = 1; price = 20000; };
	class CUP_O_Mi8_medevac_CHDKZ									{ quality = 1; price = 20000; };
	class CUP_O_Mi8_medevac_RU										{ quality = 1; price = 20000; };
	class CUP_O_Mi8_VIV_CHDKZ											{ quality = 2; price = 25000; };
	class CUP_O_Mi8_VIV_RU												{ quality = 2; price = 25000; };
	class CUP_Merlin_HC3_FFV											{ quality = 1; price = 20000; };
	class CUP_Merlin_HC3													{ quality = 1; price = 20000; };
	class CUP_Merlin_HC3_MED											{ quality = 1; price = 20000; };
	class CUP_B_MH60S_USMC												{ quality = 1; price = 32500; };
	class CUP_B_MH60S_FFV_USMC										{ quality = 1; price = 22500; };
	class CUP_B_MH6J_USA													{ quality = 1; price = 18000; };
	class CUP_I_MH6J_RACS													{ quality = 1; price = 18000; };
	class CUP_B_AW159_Unarmed_BAF									{ quality = 1; price = 20000; };
	class CUP_B_CH47F_USA													{ quality = 3; price = 45000; };
	class CUP_B_CH47F_GB													{ quality = 3; price = 45000; };
	class CUP_B_UH60M_US													{ quality = 3; price = 35000; };
	class CUP_B_UH60L_US													{ quality = 2; price = 35000; };
	class CUP_B_UH60M_FFV_US											{ quality = 4; price = 35000; };
	class CUP_B_UH60L_FFV_US											{ quality = 4; price = 25000; };
	class CUP_B_UH60M_Unarmed_US									{ quality = 1; price = 17000; };
	class CUP_B_UH60L_Unarmed_US									{ quality = 1; price = 17000; };
	class CUP_B_UH60M_Unarmed_FFV_US							{ quality = 1; price = 17000; };
	class CUP_B_UH60L_Unarmed_FFV_US							{ quality = 1; price = 17000; };
	class CUP_B_UH60M_Unarmed_FFV_MEV_US					{ quality = 1; price = 17000; };
	class CUP_B_UH60L_Unarmed_FFV_MEV_US					{ quality = 1; price = 17000; };
	class CUP_I_UH60L_RACS												{ quality = 2; price = 32500; };
	class CUP_I_UH60L_FFV_RACS										{ quality = 2; price = 32500; };
	class CUP_I_UH60L_Unarmed_RACS								{ quality = 1; price = 20000; };
	class CUP_I_UH60L_Unarmed_FFV_Racs						{ quality = 1; price = 20000; };
	class CUP_I_UH60L_Unarmed_FFV_MEV_Racs				{ quality = 1; price = 20000; };
	class CUP_O_MI6A_TKA													{ quality = 3; price = 30000; };
	class CUP_B_MI6A_CDF													{ quality = 3; price = 30000; };
	class CUP_O_MI6A_RU														{ quality = 3; price = 30000; };
	class CUP_C_MI6A_RU														{ quality = 3; price = 30000; };
	class CUP_B_MV22_VIV_USMC											{ quality = 3; price = 50000; };
	//// Planes
	class CUP_C_C47_CIV														{ quality = 1; price = 25000; };
	class CUP_B_C47_USA														{ quality = 1; price = 25000; };
	class CUP_B_AC47_Spooky_USA										{ quality = 3; price = 35000; };
	class CUP_I_C130J_Cargo_RACS									{ quality = 6; price = 75000; };
	//// Boats
	class CUP_B_RHIB_USMC													{ quality = 5; price = 12500; };
	class CUP_I_RHIB_RACS													{ quality = 5; price = 12500; };
	
	///////////////////////////////////////////////////////////////////////////////
	// Apex Vehicles
	///////////////////////////////////////////////////////////////////////////////
	// Offroad (MB4 WD)
	class C_Offroad_02_unarmed_F									{ quality = 2; price = 12000; };
	class C_Offroad_02_unarmed_black_F						{ quality = 2; price = 12000; };
	class C_Offroad_02_unarmed_blue_F							{ quality = 2; price = 12000; };
	class C_Offroad_02_unarmed_green_F						{ quality = 2; price = 12000; };
	class C_Offroad_02_unarmed_orange_F						{ quality = 2; price = 12000; };
	class C_Offroad_02_unarmed_red_F							{ quality = 2; price = 12000; };
	class C_Offroad_02_unarmed_white_F						{ quality = 2; price = 12000; };
	class I_C_Offroad_02_unarmed_F								{ quality = 2; price = 12000; };
	class I_C_Offroad_02_unarmed_brown_F					{ quality = 2; price = 12000; };
	class I_C_Offroad_02_unarmed_olive_F					{ quality = 2; price = 12000; };
	// Offroad (Police)
	class B_GEN_Offroad_01_gen_F									{ quality = 2; price = 12000; };
	// Prowler
	//// Unarmed
	class B_T_LSV_01_unarmed_F 										{ quality = 3; price = 22000; };
	class B_T_LSV_01_unarmed_CTRG_F 							{ quality = 3; price = 22000; };
	class B_LSV_01_unarmed_F 											{ quality = 3; price = 22000; };
	class B_LSV_01_unarmed_black_F 								{ quality = 3; price = 22000; };
	class B_LSV_01_unarmed_olive_F 								{ quality = 3; price = 22000; };
	class B_LSV_01_unarmed_sand_F 								{ quality = 3; price = 22000; };
	class B_T_LSV_01_unarmed_black_F 							{ quality = 3; price = 22000; };
	class B_T_LSV_01_unarmed_olive_F 							{ quality = 3; price = 22000; };
	class B_T_LSV_01_unarmed_sand_F 							{ quality = 3; price = 22000; };
	class B_CTRG_LSV_01_light_F 									{ quality = 3; price = 22000; };
	//// Armed
	class B_T_LSV_01_armed_F 											{ quality = 4; price = 28000; };
	class B_T_LSV_01_armed_CTRG_F 								{ quality = 4; price = 28000; };
	class B_T_LSV_01_armed_black_F 								{ quality = 4; price = 28000; };
	class B_T_LSV_01_armed_olive_F 								{ quality = 4; price = 28000; };
	class B_T_LSV_01_armed_sand_F 								{ quality = 4; price = 28000; };
	class B_LSV_01_armed_F 												{ quality = 4; price = 28000; };
	class B_LSV_01_armed_black_F 									{ quality = 4; price = 28000; };
	class B_LSV_01_armed_olive_F 									{ quality = 4; price = 28000; };
	class B_LSV_01_armed_sand_F 									{ quality = 4; price = 28000; };
	// Qilin
	//// Unarmed
	class O_T_LSV_02_unarmed_F 										{ quality = 3; price = 22000; };
	class O_T_LSV_02_unarmed_viper_F 							{ quality = 3; price = 22000; };
	class O_T_LSV_02_unarmed_black_F 							{ quality = 3; price = 22000; };
	class O_T_LSV_02_unarmed_ghex_F 							{ quality = 3; price = 22000; };
	class O_T_LSV_02_unarmed_arid_F 							{ quality = 3; price = 22000; };
	class O_LSV_02_unarmed_F 											{ quality = 3; price = 22000; };
	class O_LSV_02_unarmed_viper_F 								{ quality = 3; price = 22000; };
	class O_LSV_02_unarmed_black_F 								{ quality = 3; price = 22000; };
	class O_LSV_02_unarmed_ghex_F 								{ quality = 3; price = 22000; };
	class O_LSV_02_unarmed_arid_F 								{ quality = 3; price = 22000; };
	//// Armed
	class O_T_LSV_02_armed_F 											{ quality = 4; price = 28000; };
	class O_T_LSV_02_armed_viper_F 								{ quality = 4; price = 28000; };
	class O_T_LSV_02_armed_black_F 								{ quality = 4; price = 28000; };
	class O_T_LSV_02_armed_ghex_F 								{ quality = 4; price = 28000; };
	class O_T_LSV_02_armed_arid_F 								{ quality = 4; price = 28000; };
	class O_LSV_02_armed_F 												{ quality = 4; price = 28000; };
	class O_LSV_02_armed_viper_F 									{ quality = 4; price = 28000; };
	class O_LSV_02_armed_black_F 									{ quality = 4; price = 28000; };
	class O_LSV_02_armed_ghex_F 									{ quality = 4; price = 28000; };
	class O_LSV_02_armed_arid_F 									{ quality = 4; price = 28000; };
	// QUAD BIKES
	class O_T_Quadbike_01_ghex_F									{ quality = 1; price = 2500; };		
	// HEMMT
	class B_T_Truck_01_covered_F 									{ quality = 3; price = 48000; };
	// Tempest
	class O_T_Truck_03_transport_ghex_F						{ quality = 4; price = 48300; };
	class O_T_Truck_03_covered_ghex_F							{ quality = 4; price = 48300; };
	class O_T_Truck_03_device_ghex_F							{ quality = 4; price = 48300; };
	// Van
	class I_C_Van_01_transport_F									{ quality = 2; price = 17000; };
	class I_C_Van_01_transport_brown_F						{ quality = 2; price = 17000; };
	class I_C_Van_01_transport_olive_F						{ quality = 2; price = 17000; };
	// MOTOR BOATS
	class B_G_Boat_Transport_02_F									{ quality = 2; price = 1500; };
	class O_G_Boat_Transport_02_F									{ quality = 2; price = 1500; };
	class I_G_Boat_Transport_02_F									{ quality = 2; price = 1500; };
	class I_C_Boat_Transport_02_F									{ quality = 2; price = 1500; };
	class C_Boat_Transport_02_F										{ quality = 2; price = 1505; };
	class C_Scooter_Transport_01_F								{ quality = 1; price = 500; };
	// Hummingbird (Civillian)
	class I_C_Heli_Light_01_civil_F								{ quality = 1; price = 17000; };
	// V-44 X Blackfish
	class B_T_VTOL_01_infantry_blue_F							{ quality = 5; price = 40000; };
	class B_T_VTOL_01_infantry_olive_F						{ quality = 5; price = 40000; };
	class B_T_VTOL_01_vehicle_blue_F							{ quality = 5; price = 50000; };
	class B_T_VTOL_01_vehicle_olive_F							{ quality = 5; price = 50000; };
	// Caesar BTT
	class C_Plane_Civil_01_racing_F								{ quality = 1; price = 15000; };

	///////////////////////////////////////////////////////////////////////////////
	// ORANGE DLC (LAWS OF WAR)
	///////////////////////////////////////////////////////////////////////////////
	//IDAP Uniforms
	class U_C_IDAP_Man_cargo_F												{ quality = 2; price = 80; };
	class U_C_IDAP_Man_jeans_F												{ quality = 2; price = 80; };
	class U_C_IDAP_Man_Casual_F												{ quality = 2; price = 80; };
	class U_C_IDAP_Man_shorts_F												{ quality = 2; price = 80; };
	class U_C_IDAP_Man_tee_F													{ quality = 2; price = 80; };
	class U_C_IDAP_Man_teeshorts_F										{ quality = 2; price = 80; };
	//Construction Coveralls
	class U_C_ConstructionCoverall_Black_F						{ quality = 2; price = 80; };
	class U_C_ConstructionCoverall_Blue_F							{ quality = 2; price = 80; };
	class U_C_ConstructionCoverall_Red_F							{ quality = 2; price = 80; };
	class U_C_ConstructionCoverall_Vrana_F						{ quality = 2; price = 80; };
	//Misc Uniforms
	class U_BG_Guerilla1_2_F													{ quality = 2; price = 80; };
	class U_C_Mechanic_01_F														{ quality = 2; price = 80; };
	class U_C_Paramedic_01_F													{ quality = 2; price = 80; };
	//Vests
	class V_EOD_blue_F																{ quality = 4; price = 250; };
	class V_EOD_IDAP_blue_F														{ quality = 4; price = 250; };
	class V_EOD_coyote_F															{ quality = 4; price = 250; };
	class V_EOD_olive_F																{ quality = 4; price = 250; };
	class V_Plain_crystal_F														{ quality = 1; price = 25; };
	class V_Plain_medical_F														{ quality = 1; price = 25; };
	class V_LegStrapBag_black_F												{ quality = 1; price = 50; };
	class V_LegStrapBag_coyote_F											{ quality = 1; price = 50; };
	class V_LegStrapBag_olive_F												{ quality = 1; price = 50; };
	class V_Pocketed_black_F													{ quality = 1; price = 50; };
	class V_Pocketed_coyote_F													{ quality = 1; price = 50; };
	class V_Pocketed_olive_F													{ quality = 1; price = 50; };
	class V_Safety_blue_F															{ quality = 1; price = 25; };
	class V_Safety_orange_F														{ quality = 1; price = 25; };
	class V_Safety_yellow_F														{ quality = 1; price = 25; };
	//Caps
	class H_Cap_Black_IDAP_F													{ quality = 1; price = 6; };
	class H_Cap_Orange_IDAP_F													{ quality = 1; price = 6; };
	class H_Cap_White_IDAP_F													{ quality = 1; price = 6; };
	//Hard Hats
	class H_Construction_basic_black_F								{ quality = 1; price = 75; };
	class H_Construction_earprot_black_F							{ quality = 1; price = 75; };
	class H_Construction_headset_black_F							{ quality = 1; price = 75; };
	class H_Construction_basic_orange_F								{ quality = 1; price = 75; };
	class H_Construction_earprot_orange_F							{ quality = 1; price = 75; };
	class H_Construction_headset_orange_F							{ quality = 1; price = 75; };
	class H_Construction_basic_red_F									{ quality = 1; price = 75; };
	class H_Construction_earprot_red_F								{ quality = 1; price = 75; };
	class H_Construction_headset_red_F								{ quality = 1; price = 75; };
	class H_Construction_basic_vrana_F								{ quality = 1; price = 75; };
	class H_Construction_earprot_vrana_F							{ quality = 1; price = 75; };
	class H_Construction_headset_vrana_F							{ quality = 1; price = 75; };
	class H_Construction_basic_white_F								{ quality = 1; price = 75; };
	class H_Construction_earprot_white_F							{ quality = 1; price = 75; };
	class H_Construction_headset_white_F							{ quality = 1; price = 75; };
	class H_Construction_basic_yellow_F								{ quality = 1; price = 75; };
	class H_Construction_earprot_yellow_F							{ quality = 1; price = 75; };
	class H_Construction_headset_yellow_F							{ quality = 1; price = 75; };
	//Safari Hats
	class H_Hat_Safari_olive_F												{ quality = 1; price = 10; };
	class H_Hat_Safari_sand_F													{ quality = 1; price = 10; };
	//Basic Helmets
	class H_PASGT_basic_blue_F												{ quality = 3; price = 75; };
	class H_PASGT_basic_olive_F												{ quality = 3; price = 75; };
	class H_PASGT_basic_white_F												{ quality = 3; price = 75; };
	class H_PASGT_basic_blue_press_F									{ quality = 3; price = 75; };
	class H_PASGT_neckprot_blue_press_F								{ quality = 3; price = 85; };
	//Facewear
	class G_Respirator_blue_F													{ quality = 1; price = 10; };
	class G_Respirator_white_F												{ quality = 1; price = 10; };
	class G_Respirator_yellow_F												{ quality = 1; price = 10; };
	class G_EyeProtectors_F														{ quality = 1; price = 10; };
	class G_EyeProtectors_Earpiece_F									{ quality = 1; price = 10; };
	class G_WirelessEarpiece_F												{ quality = 1; price = 10; };
	//Backpacks
	class B_LegStrapBag_black_F												{ quality = 1; price = 25; };
	class B_LegStrapBag_coyote_F											{ quality = 1; price = 25; };
	class B_LegStrapBag_olive_F												{ quality = 1; price = 25; };
	class B_Messenger_Black_F													{ quality = 1; price = 50; };
	class B_Messenger_Coyote_F												{ quality = 1; price = 50; };
	class B_Messenger_Gray_F													{ quality = 1; price = 50; };
	class B_Messenger_Olive_F													{ quality = 1; price = 50; };
	class B_Messenger_IDAP_F													{ quality = 1; price = 50; };
	//Vans
	class B_G_Van_02_vehicle_F												{ quality = 2; price = 17000; };
	class I_G_Van_02_vehicle_F												{ quality = 2; price = 17000; };
	class I_G_Van_02_transport_F											{ quality = 2; price = 17000; };
	class I_C_Van_02_vehicle_F												{ quality = 2; price = 17000; };
	class I_C_Van_02_transport_F											{ quality = 2; price = 17000; };
	class C_Van_02_medevac_F													{ quality = 2; price = 20000; };
	class C_Van_02_service_F													{ quality = 2; price = 20000; };
	class C_IDAP_Van_02_medevac_F											{ quality = 2; price = 20000; };
	//Misc Veh
	class C_IDAP_Offroad_02_unarmed_F									{ quality = 2; price = 12000; };
	class C_IDAP_Offroad_01_F													{ quality = 2; price = 12000; };
	class C_IDAP_Truck_02_transport_F									{ quality = 4; price = 43000; };
	class C_IDAP_Truck_02_F														{ quality = 4; price = 43000; };
	//Aircraft
	class C_IDAP_Heli_Transport_02_F									{ quality = 1; price = 20000; };
	//UAV
	class B_UAV_06_medical_backpack_F									{ quality = 5; price = 10000; };
	class B_UAV_06_backpack_F													{ quality = 5; price = 10000; };
	class O_UAV_06_medical_backpack_F									{ quality = 5; price = 10000; };
	class O_UAV_06_backpack_F													{ quality = 5; price = 10000; };
	class I_UAV_06_medical_backpack_F									{ quality = 5; price = 10000; };
	class I_UAV_06_backpack_F													{ quality = 5; price = 10000; };
	class C_IDAP_UAV_06_medical_backpack_F						{ quality = 5; price = 10000; };
	class C_IDAP_UAV_06_backpack_F										{ quality = 5; price = 10000; };
	class C_UAV_06_medical_backpack_F									{ quality = 5; price = 10000; };
	class C_UAV_06_backpack_F													{ quality = 5; price = 10000; };

	///////////////////////////////////////////////////////////////////////////////
	// Mr.Sanchez Headlamps
	///////////////////////////////////////////////////////////////////////////////
	class SAN_Headlamp_v1														{ quality = 1; price = 25; };	// Headlamp Alpha
	class SAN_Headlamp_v2														{ quality = 1; price = 50; };	// Headlamp Bravo

	///////////////////////////////////////////////////////////////////////////////
	// Flags
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Item_FlagStolen1						{ quality = 1; price = 5000;  sellPrice = 5000;  };
	class Exile_Item_FlagStolen2						{ quality = 1; price = 10000; sellPrice = 10000; };
	class Exile_Item_FlagStolen3						{ quality = 1; price = 15000; sellPrice = 15000; };
	class Exile_Item_FlagStolen4						{ quality = 1; price = 20000; sellPrice = 20000; };
	class Exile_Item_FlagStolen5						{ quality = 1; price = 25000; sellPrice = 25000; };
	class Exile_Item_FlagStolen6						{ quality = 1; price = 30000; sellPrice = 30000; };
	class Exile_Item_FlagStolen7						{ quality = 1; price = 35000; sellPrice = 35000; };
	class Exile_Item_FlagStolen8						{ quality = 1; price = 40000; sellPrice = 40000; };
	class Exile_Item_FlagStolen9						{ quality = 1; price = 45000; sellPrice = 45000; };
	class Exile_Item_FlagStolen10						{ quality = 1; price = 50000; sellPrice = 50000; };

	///////////////////////////////////////////////////////////////////////////////
	// RARE LOOT ITEMS
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Item_Magazine01							{ quality = 6; price = 200000; sellPrice = 100000; };
	class Exile_Item_Magazine02							{ quality = 6; price = 250000; sellPrice = 125000; };
	class Exile_Item_Magazine03							{ quality = 6; price = 300000; sellPrice = 150000; };
	class Exile_Item_Magazine04							{ quality = 6; price = 350000; sellPrice = 175000; };
	class Exile_Item_RubberDuck							{ quality = 6; price = 400000; sellPrice = 200000; };
	class CUP_item_Kostey_photos						{ quality = 6; price = 600000; sellPrice = 650000; };

	///////////////////////////////////////////////////////////////////////////////
	// DONATION GOAL ITEMS AND VEHICLES
	///////////////////////////////////////////////////////////////////////////////
	//UNIFORMS
	class U_O_V_Soldier_Viper_F										{ quality = 7; price = 500; };
	class U_O_V_Soldier_Viper_hex_F								{ quality = 7; price = 500; };
	class U_C_Driver_1														{ quality = 7; price = 400; };
	class U_C_Driver_2														{ quality = 7; price = 400; };
	class U_C_Driver_3														{ quality = 7; price = 400; };
	class U_C_Driver_4														{ quality = 7; price = 400; };
	class U_C_Driver_1_black											{ quality = 7; price = 400; };
	class U_C_Driver_1_blue												{ quality = 7; price = 400; };
	class U_C_Driver_1_green											{ quality = 7; price = 400; };
	class U_C_Driver_1_red												{ quality = 7; price = 400; };
	class U_C_Driver_1_white											{ quality = 7; price = 400; };
	class U_C_Driver_1_yellow											{ quality = 7; price = 400; };
	class U_C_Driver_1_orange											{ quality = 7; price = 400; };
	class Exile_Uniform_ExileCustoms							{ quality = 7; price = 400; };
	class U_C_WorkerCoveralls											{ quality = 7; price = 400; };
	class U_C_Scientist														{ quality = 7; price = 400; };
	//HEADGEAR
	class Exile_Headgear_SantaHat									{ quality = 7; price = 200; };
	class Exile_Headgear_SafetyHelmet							{ quality = 7; price = 200; };
	class H_RacingHelmet_1_F											{ quality = 7; price = 200; };
	class H_RacingHelmet_2_F											{ quality = 7; price = 200; };
	class H_RacingHelmet_3_F											{ quality = 7; price = 200; };
	class H_RacingHelmet_4_F											{ quality = 7; price = 200; };
	class H_RacingHelmet_1_black_F								{ quality = 7; price = 200; };
	class H_RacingHelmet_1_blue_F									{ quality = 7; price = 200; };
	class H_RacingHelmet_1_green_F								{ quality = 7; price = 200; };
	class H_RacingHelmet_1_red_F									{ quality = 7; price = 200; };
	class H_RacingHelmet_1_white_F								{ quality = 7; price = 200; };
	class H_RacingHelmet_1_yellow_F								{ quality = 7; price = 200; };
	class H_RacingHelmet_1_orange_F								{ quality = 7; price = 200; };
	//EQUIPMENT
	class H_HelmetO_ViperSP_ghex_F								{ quality = 8; price = 100000; };
	class H_HelmetO_ViperSP_hex_F									{ quality = 8; price = 100000; };
	class NVGogglesB_blk_F												{ quality = 8; price = 75000; };	//Normal NightV but fullscreen thermal
	class NVGogglesB_grn_F												{ quality = 8; price = 75000; };	//Normal NightV but fullscreen thermal
	class NVGogglesB_gry_F												{ quality = 8; price = 75000; };	//Normal NightV but fullscreen thermal
	//WEAPONS
	class CUP_glaunch_M32													{ quality = 8; price = 5000; };
	class HLC_wp_M134Painless											{ quality = 8; price = 25000; };
	//AMMO
	class CUP_6Rnd_HE_M203												{ quality = 8; price = 500; };
	class CUP_6Rnd_FlareWhite_M203								{ quality = 8; price = 200; };
	class CUP_6Rnd_FlareGreen_M203								{ quality = 8; price = 200; };
	class CUP_6Rnd_FlareRed_M203									{ quality = 8; price = 200; };
	class CUP_6Rnd_FlareYellow_M203								{ quality = 8; price = 200; };
	class CUP_6Rnd_Smoke_M203											{ quality = 8; price = 200; };
	class CUP_6Rnd_SmokeRed_M203									{ quality = 8; price = 200; };
	class CUP_6Rnd_SmokeGreen_M203								{ quality = 8; price = 200; };
	class CUP_6Rnd_SmokeYellow_M203								{ quality = 8; price = 200; };
	class hlc_500rnd_762x51_Belt									{ quality = 8; price = 1000; };
	//LAUNCHERS
	class CUP_launch_Javelin											{ quality = 8; price = 25000; };
	class launch_O_Titan_short_ghex_F							{ quality = 8; price = 25000; };
	class launch_B_Titan_short_F									{ quality = 8; price = 25000; };
	class launch_I_Titan_short_F									{ quality = 8; price = 25000; };
	//ROCKETS
	class CUP_Javelin_M														{ quality = 8; price = 10000; };
	class Titan_AT																{ quality = 8; price = 10000; };
	//OPTICS
	class optic_tws																{ quality = 8; price = 50000; };
	class optic_tws_mg														{ quality = 8; price = 50000; };
	class CUP_optic_GOSHAWK												{ quality = 8; price = 50000; };
	class hlc_optic_goshawk												{ quality = 8; price = 50000; };
	class CUP_optic_AN_PAS_13c1										{ quality = 8; price = 50000; };
	class CUP_optic_AN_PAS_13c2										{ quality = 8; price = 50000; };
	class CUP_optic_CWS														{ quality = 8; price = 50000; };
	//Construction Parts
	class Exile_Item_MetalHedgehogKit							{ quality = 7; price = 1000; sellPrice = 200; };
	class Exile_Item_ConcreteDoorwayKit						{ quality = 7; price = 1000; sellPrice = 200; };
	class Exile_Item_ConcreteDoorKit							{ quality = 7; price = 1000; sellPrice = 200; };
	class Exile_Item_ConcreteFloorKit							{ quality = 7; price = 1000; sellPrice = 200; };
	class Exile_Item_ConcreteFloorPortKit					{ quality = 7; price = 1000; sellPrice = 200; };
	class Exile_Item_ConcreteGateKit							{ quality = 7; price = 1000; sellPrice = 200; };
	class Exile_Item_ConcreteStairsKit						{ quality = 7; price = 1000; sellPrice = 200; };
	class Exile_Item_ConcreteSupportKit						{ quality = 7; price = 1000; sellPrice = 200; };
	class Exile_Item_ConcreteWallKit							{ quality = 7; price = 1000; sellPrice = 200; };
	class Exile_Item_ConcreteWindowKit						{ quality = 7; price = 1000; sellPrice = 200; };
	class Exile_Item_RepairKitConcrete						{ quality = 7; price = 1000; sellPrice = 200; };
	class Exile_Item_WoodDrawBridgeKit						{ quality = 7; price = 500; sellPrice = 200; };
	class Exile_Item_WoodFloorPortSmallKit				{ quality = 7; price = 500; sellPrice = 200; };
	class Exile_Item_WoodLadderKit								{ quality = 7; price = 500; sellPrice = 200; };
	class Exile_Item_WoodDoorwayKit								{ quality = 7; price = 250; sellPrice = 200; };
	class Exile_Item_WoodDoorKit									{ quality = 7; price = 250; sellPrice = 200; };
	class Exile_Item_WoodFloorKit									{ quality = 7; price = 250; sellPrice = 200; };
	class Exile_Item_WoodFloorPortKit							{ quality = 7; price = 250; sellPrice = 200; };
	class Exile_Item_WoodGateKit									{ quality = 7; price = 250; sellPrice = 200; };
	class Exile_Item_WoodStairsKit								{ quality = 7; price = 250; sellPrice = 200; };
	class Exile_Item_WoodSupportKit								{ quality = 7; price = 250; sellPrice = 200; };
	class Exile_Item_WoodWallHalfKit							{ quality = 7; price = 250; sellPrice = 200; };
	class Exile_Item_WoodWallKit									{ quality = 7; price = 250; sellPrice = 200; };
	class Exile_Item_WoodWindowKit								{ quality = 7; price = 250; sellPrice = 200; };
	class Exile_Item_RepairKitWood								{ quality = 7; price = 250; sellPrice = 200; };
	class Exile_Item_FortificationUpgrade					{ quality = 7; price = 250; sellPrice = 200; };
	//EBM
	class Land_i_Barracks_V1_F_Kit								{ quality = 10; price = 250000; sellPrice = 200; };
	class Land_Airport_Tower_F_Kit								{ quality = 10; price = 250000; sellPrice = 200; };
	class Land_Dome_Big_F_Kit											{ quality = 10; price = 250000; sellPrice = 200; };
	class Land_Hangar_F_Kit												{ quality = 10; price = 250000; sellPrice = 200; };
	class Land_i_Addon_03_V1_F_Kit								{ quality = 10; price = 250000; sellPrice = 200; };
	class Land_i_Addon_03mid_V1_F_Kit							{ quality = 10; price = 250000; sellPrice = 200; };
	class Land_TentHangar_V1_F_Kit								{ quality = 10; price = 250000; sellPrice = 200; }; 
	class Land_i_Garage_V2_F_Kit									{ quality = 10; price = 250000; sellPrice = 200; };
	class Land_Cargo_Tower_V2_F_Kit								{ quality = 10; price = 250000; sellPrice = 200; };
	class Exile_ConcreteMixer_Kit									{ quality = 10; price = 350000; sellPrice = 200; };
	class Land_Bunker_F_Kit												{ quality = 10; price = 250000; sellPrice = 200; };
	class	Land_Airport_01_hangar_F_Kit						{ quality = 10; price = 250000; sellPrice = 200; };
	//VEHICLES
	class CUP_C_Golf4_kitty_Civ										{ quality = 9; price = 50000; };		// Hello Kitty Golf
	class O_MBT_02_cannon_F												{ quality = 9; price = 200000; };		// T-100 Varsuk CSAT
	class O_T_MBT_02_cannon_ghex_F								{ quality = 9; price = 200000; };		// T-100 Varsuk GHEX
	class CUP_B_M1A2_TUSK_MG_USMC									{ quality = 9; price = 300000; };		// M1A2 Abrams TUSK (Woodland)
	class CUP_B_M1A2_TUSK_MG_DES_USMC							{ quality = 9; price = 300000; };		// M1A2 Abrams TUSK (Desert)
	class O_APC_Tracked_02_cannon_F								{ quality = 9; price = 200000; };		// BTR-K Kamysh CSAT
	class O_T_APC_Tracked_02_cannon_ghex_F				{ quality = 9; price = 200000; };		// BTR-K Kamysh GHEX
	class I_APC_Wheeled_03_cannon_F								{ quality = 9; price = 125000; };		// AFV-4 Gorgon
	class I_APC_tracked_03_cannon_F								{ quality = 9; price = 125000; };		// FV-720 Mora
	class CUP_B_M1128_MGS_Desert									{ quality = 9; price = 300000; };		// M1128 Stryker
	class CUP_B_M1128_MGS_Desert_Slat							{ quality = 9; price = 300000; };		// M1128 Stryker
	class CUP_B_M1128_MGS_Woodland								{ quality = 9; price = 300000; };		// M1128 Stryker
	class CUP_B_M1128_MGS_Woodland_Slat						{ quality = 9; price = 300000; };		// M1128 Stryker
	class O_APC_Tracked_02_AA_F										{ quality = 9; price = 250000; };   // ZSU-39 Tigris CSAT
	class O_T_APC_Tracked_02_AA_ghex_F						{ quality = 9; price = 250000; };   // ZSU-39 Tigris GHEX
	class I_MBT_03_cannon_F												{ quality = 9; price = 300000; };   // MBT-52 Kuma
	class B_MBT_01_TUSK_F													{ quality = 9; price = 300000; };   // M2A4 Slammer UP
	class B_APC_Tracked_01_rcws_F									{ quality = 9; price = 225000; };   // IFV-6C Panther
	class B_APC_Tracked_01_CRV_F									{ quality = 9; price = 200000; };   // CRV-6E Bobcat
	class B_MBT_01_arty_F													{ quality = 9; price = 400000; };   // M4 Scorcher
	class O_MBT_02_arty_F													{ quality = 9; price = 400000; };   // 2S9 Sochor (CSAT)
	class O_T_MBT_02_arty_ghex_F									{ quality = 9; price = 400000; };   // 2S9 Sochor (GHEX)
	class CUP_I_T55_TK_GUE												{ quality = 9; price = 200000; };		// T-55 Desert
	class CUP_O_T55_TK														{ quality = 9; price = 200000; };		// T-55 Desert Camo
	class CUP_O_T55_SLA														{ quality = 9; price = 200000; };		// T-55 OD
	class CUP_O_T55_CSAT													{ quality = 9; price = 200000; };		// T-55 CSAT
	class CUP_O_T55_CSAT_T												{ quality = 9; price = 200000; };		// T-55 CSAT Green
	class CUP_O_T72_CSAT													{ quality = 9; price = 200000; };		// T-72 CSAT
	class CUP_O_T72_CSAT_T												{ quality = 9; price = 200000; };		// T-72 CSAT Green
	class CUP_B_T72_CDF														{ quality = 9; price = 200000; };		// T-72 CDF Woodland
	class CUP_O_T72_RU														{ quality = 9; price = 200000; };		// T-72 Desert Camo 1
	class CUP_I_T72_RACS													{ quality = 9; price = 200000; };		// T-72 Desert Camo 2
	class CUP_I_T72_NAPA													{ quality = 9; price = 200000; };		// T-72 OD
	class CUP_O_2S6M_RU														{ quality = 9; price = 225000; };		// 2S6 Tunguska-M
	class CUP_B_M163_USA													{ quality = 9; price = 300000; };   // M163A1 VADS (Woodland)
	class CUP_I_M163_AAF													{ quality = 9; price = 300000; };   // M163A1 VADS (Digital)
	class CUP_I_M163_RACS													{ quality = 9; price = 300000; };   // M163A1 VADS (RACS)
	class CUP_B_M6LineBacker_USA_D								{ quality = 9; price = 300000; };   // M6 Linebacker (USA Desert)
	class CUP_B_M6LineBacker_USA_W								{ quality = 9; price = 300000; };   // M6 Linebacker (USA Woodland)
	class CUP_B_M6LineBacker_NATO_T								{ quality = 9; price = 300000; };   // M6 Linebacker (NATO Desert)
	class CUP_B_HMMWV_Avenger_USA									{ quality = 9; price = 250000; };   // HMMWV Avenger (Desert)
	class CUP_B_HMMWV_Avenger_USMC								{ quality = 9; price = 250000; };   // HMMWV Avenger (Woodland)
	class CUP_B_HMMWV_TOW_USA 										{ quality = 9; price = 250000; };   // HMMWV TOW (Desert)
	class CUP_B_HMMWV_TOW_USMC										{ quality = 9; price = 250000; };   // HMMWV TOW (Woodland)
	class CUP_B_HMMWV_AGS_GPK_ACR									{ quality = 9; price = 200000; };   // HMMWV M1114 AGS
	class CUP_B_Ridgback_GMG_GB_D									{ quality = 9; price = 200000; };   // Ridgeback PPV GMG (Desert)
	class CUP_B_Ridgback_GMG_GB_W									{ quality = 9; price = 200000; };   // Ridgeback PPV GMG (Woodland)
	class CUP_B_Mastiff_GMG_GB_D									{ quality = 9; price = 225000; };   // Mastiff PPV GMG (Desert)
	class CUP_B_Mastiff_GMG_GB_W									{ quality = 9; price = 225000; };   // Mastiff PPV GMG (Woodland)
	class CUP_B_Wolfhound_GMG_GB_D								{ quality = 9; price = 250000; };   // Wolfhound TSV GMG (Desert)
	class CUP_B_Wolfhound_GMG_GB_W								{ quality = 9; price = 250000; };   // Wolfhound TSV GMG (Woodland)
	//AIRCRAFT
	class O_Heli_Attack_02_F											{ quality = 10; price = 300000; };	// Mi-48 Kajman CSAT
	class O_Heli_Attack_02_black_F								{ quality = 10; price = 300000; };	// Mi-48 Kajman Black
	class B_Heli_Attack_01_F											{ quality = 10; price = 300000; };	// AH-99 Blackfoot
	class CUP_B_UH1Y_GUNSHIP_USMC									{ quality = 10; price = 250000; };	// UH-1Y Venom Gunship
	class CUP_B_AH1Z_NoWeapons_USMC								{ quality = 10; price = 200000; };	// AH-1Z Viper USMC (No Weapons)
	class CUP_B_AH1Z_USMC													{ quality = 10; price = 250000; };	// AH-1Z Viper USMC
	class CUP_B_AH1Z_AT_USMC											{ quality = 10; price = 250000; };	// AH-1Z Viper USMC (Anti Tank)
	class CUP_B_AH1Z_Escort_USMC									{ quality = 10; price = 250000; };	// AH-1Z Viper USMC (Escort)
	class CUP_B_F35B_AA_USMC											{ quality = 10; price = 200000; };	// F-35B Lightning II (AA) USMC
	class CUP_B_F35B_AA_BAF												{ quality = 10; price = 200000; };	// F-35B Lightning II (AA) BAF
	class CUP_B_AV8B_CAP_USMC											{ quality = 10; price = 200000; };	// AV-8B Harrier II (CAP) USMC
	class CUP_I_AV8B_CAP_AAF											{ quality = 10; price = 200000; };	// AV-8B Harrier II (CAP) AAF
	class CUP_B_AW159_RN_Blackcat									{ quality = 10; price = 300000; };	// AW159 Wildcat (Black Cat)
	class CUP_B_AW159_RN_Grey											{ quality = 10; price = 300000; };	// AW159 Wildcat (Grey)
	class CUP_I_Wildcat_Digital_AAF								{ quality = 10; price = 300000; };	// AW159 Wildcat (Digital)
	class CUP_I_Wildcat_Green_AAF									{ quality = 10; price = 300000; };	// AW159 Wildcat (Green)
	class CUP_O_Mi8_SLA_2													{ quality = 10; price = 300000; };	// Mi-8MTV3 SLA (Camo)
	class CUP_O_Mi8_RU														{ quality = 10; price = 300000; };	// Mi-8MTV3 RU (Camo)
	class O_T_VTOL_02_infantry_hex_F							{ quality = 10; price = 350000; };	// Y-32 Xi'an (Infantry Transport) HEX
	class O_T_VTOL_02_infantry_ghex_F							{ quality = 10; price = 350000; };	// Y-32 Xi'an (Infantry Transport) GHEX
	class O_T_VTOL_02_infantry_grey_F							{ quality = 10; price = 350000; };	// Y-32 Xi'an (Infantry Transport) Grey
	class O_T_VTOL_02_vehicle_hex_F								{ quality = 10; price = 350000; };	// Y-32 Xi'an (Vehicle Transport) HEX
	class O_T_VTOL_02_vehicle_ghex_F							{ quality = 10; price = 350000; };	// Y-32 Xi'an (Vehicle Transport) GHEX
	class O_T_VTOL_02_vehicle_grey_F							{ quality = 10; price = 350000; };	// Y-32 Xi'an (Vehicle Transport) Grey
	class B_Plane_Fighter_01_F										{ quality = 10; price = 350000; };  // F/A-181 Black Wasp II
	////class B_Plane_Fighter_01_Stealth_F					{ quality = 10; price = 350000; };  // F/A-181 Black Wasp II (Stealth)
	////class O_Plane_Fighter_02_F									{ quality = 10; price = 350000; };  // To-201 Shikra
	////class O_Plane_Fighter_02_Stealth_F					{ quality = 10; price = 350000; };  // To-201 Shikra (Stealth)
	////class I_Plane_Fighter_04_F									{ quality = 10; price = 350000; };  // A-149 Gryphon
	class B_Plane_CAS_01_F												{ quality = 10; price = 350000; };  // A-164 Wipeout (CAS)
	class CUP_B_A10_AT_USA												{ quality = 10; price = 350000; };  // A-10C Thunderbolt II (AT)
	class CUP_B_A10_CAS_USA												{ quality = 10; price = 350000; };  // A-10C Thunderbolt II (CAS)
	class CUP_B_AH64D_USA													{ quality = 10; price = 300000; };  // AH-64D Apache
	class CUP_B_AH64D_AT_USA											{ quality = 10; price = 300000; };  // AH-64D Apache (AT)
	class CUP_B_AH64D_ES_USA											{ quality = 10; price = 300000; };  // AH-64D Apache (Escort)
	class CUP_B_AH64D_LB_USA											{ quality = 10; price = 300000; };  // AH-64D Apache (Longbow)
	class CUP_B_AH64D_MR_USA											{ quality = 10; price = 300000; };  // AH-64D Apache (Multi-Role)
	//DRONES
	//class CUP_B_USMC_MQ9													{ quality = 8; price = 150000; };  // MQ-9 Reaper (BLUFOR)
	//class B_UAV_02_F															{ quality = 8; price = 150000; };  // MQ-4A Greyhawk (BLUFOR)
	//class B_UAV_02_CAS_F													{ quality = 8; price = 150000; };  // MQ-4A Greyhawk (CAS) (BLUFOR)
	//class I_UAV_02_F															{ quality = 8; price = 150000; };  // K40 Ababil-3 (IND)
	//class I_UAV_02_CAS_F													{ quality = 8; price = 150000; };  // K40 Ababil-3 (CAS) (IND)
	//class O_UAV_02_F															{ quality = 8; price = 150000; };  // K40 Ababil-3 (OPFOR)
	//class O_UAV_02_CAS_F													{ quality = 8; price = 150000; };  // K40 Ababil-3 (CAS) (OPFOR)
	//class B_T_UAV_03_F														{ quality = 8; price = 150000; };  // MQ-12 Falcon (CAS) (BLUFOR)
	//class O_T_UAV_04_CAS_F												{ quality = 8; price = 150000; };  // KH-3A Fenghuang
	//class B_UAV_05_F															{ quality = 8; price = 150000; };  // UCAV Sentinel
	//UGVs
	//class B_UGV_01_rcws_F													{ quality = 8; price = 100000; };  // Stomper RCWS (BLUFOR)
	//class I_UGV_01_rcws_F													{ quality = 8; price = 100000; };  // Stomper RCWS (IND)
	//class O_UGV_01_rcws_F													{ quality = 8; price = 100000; };  // Saif RCWS (OPFOR)
	//class O_T_UGV_01_rcws_ghex_F									{ quality = 8; price = 100000; };  // Saif RCWS GHEX (OPFOR)

};

class CfgExileCustomCode 
{
	/*
		You can overwrite every single file of our code without touching it.
		To do that, add the function name you want to overwrite plus the 
		path to your custom file here. If you wonder how this works, have a
		look at our bootstrap/fn_preInit.sqf function.

		Simply add the following scheme here:

		<Function Name of Exile> = "<New File Name>";

		Example:

		ExileClient_util_fusRoDah = "myaddon\myfunction.sqf";
	*/

	//Get Dynamic Vehicles To Only Spawn Within The Lythium Map Area
	ExileServer_world_spawnVehicles = "fixes\ExileServer_world_spawnVehicles.sqf";

	//infiSTAR Improved Network Security - The original function was not shuffling
	ExileClient_util_array_shuffle = "fixes\ExileClient_util_array_shuffle.sqf";

	//Set cContainer Limits Based On Territory Size
	ExileClient_util_world_canBuildHere                            	= "custom\container_limits\ExileClient_util_world_canBuildHere.sqf";
	ExileServer_object_supplyBox_network_installSupplyBoxRequest   	= "custom\container_limits\ExileServer_object_supplyBox_network_installSupplyBoxRequest.sqf";
	ExileServer_object_construction_network_buildConstructionRequest= "custom\container_limits\ExileServer_object_construction_network_buildConstructionRequest.sqf";

	//Update Time Until Restart to DB
	ExileServer_system_rcon_thread_check = "custom\ExileServer_system_rcon_thread_check.sqf";

	//Add Use InstaDoc Keybind (Custom Control - Use Action 13)  
	ExileClient_gui_hud_event_onKeyUp = "custom\ExileClient_gui_hud_event_onKeyUp.sqf";

	//Base Spawning Enabled
	ExileClient_gui_selectSpawnLocation_show = "custom\ExileClient_gui_selectSpawnLocation_show.sqf";

	//Respect Based Loadouts and Set XM8 to Online by default
	ExileServer_object_player_createBambi = "custom\ExileServer_object_player_createBambi.sqf";
	ExileServer_object_player_network_createPlayerRequest = "custom\ExileServer_object_player_network_createPlayerRequest.sqf";
	ExileServer_object_player_database_load = "custom\ExileServer_object_player_database_load.sqf";

	//R3F onEnterSafezone & Customized Message & SafeZone ESP Distance
	ExileClient_object_player_event_onEnterSafezone = "custom\ExileClient_object_player_event_onEnterSafezone.sqf";

	//Customized Message When Leaving Safe Zone
	ExileClient_object_player_event_onLeaveSafezone = "custom\ExileClient_object_player_event_onLeaveSafezone.sqf";

	//Extended Time Toasts and Baguettes Are On Screen
	ExileClient_gui_toaster_addToast = "custom\ExileClient_gui_toaster_addToast.sqf";
	ExileClient_gui_baguette_show = "custom\ExileClient_gui_baguette_show.sqf";

	//Improved Kill Feed Messages
	ExileServer_object_player_event_onMpKilled = "custom\ExileServer_object_player_event_onMpKilled.sqf";
	//Temp Fix for PvP Deaths being Reported as Killed by NPC
	ExileServer_util_getFragKiller = "fixes\ExileServer_util_getFragKiller.sqf";
	ExileServer_util_getFragType = "fixes\ExileServer_util_getFragType.sqf";

	//Rocket Launcher Fix (Can Purchase to Inventory?)
	ExileClient_util_playerEquipment_add = "custom\ExileClient_util_playerEquipment_add.sqf";

	//Eject Player From Vehicle When Killed
	exileserver_object_vehicle_event_onmpkilled = "custom\exileserver_object_vehicle_event_onmpkilled.sqf";

	//Supply Box Message Change And PopTabs Added To Money Crate
	ExileServer_system_event_supplyBox_start = "custom\ExileServer_system_event_supplyBox_start.sqf";

	//CBA Compatible Gear
	ExileClient_util_gear_getCompatibleWeaponItems = "custom\ExileClient_util_gear_getCompatibleWeaponItems.sqf";
	ExileClient_util_item_getCompatibleWeaponItems = "custom\ExileClient_util_item_getCompatibleWeaponItems.sqf";

	//Enable Selling From Crates
	ExileClient_gui_traderDialog_updateInventoryDropdown = "custom\ExileClient_gui_traderDialog_updateInventoryDropdown.sqf";
	ExileClient_gui_wasteDumpDialog_show = "custom\ExileClient_gui_wasteDumpDialog_show.sqf";
	//Deletes Crates When Player Sells Cargo Only
	ExileServer_system_trading_network_wasteDumpRequest = "custom\ExileServer_system_trading_network_wasteDumpRequest.sqf";
  
	//Service and Re-arm Ammo Removal
	//ExileServer_object_vehicle_createNonPersistentVehicle = "custom\ExileServer_object_vehicle_createNonPersistentVehicle.sqf";
	//ExileServer_object_vehicle_createPersistentVehicle = "custom\ExileServer_object_vehicle_createPersistentVehicle.sqf";
	//ExileServer_object_vehicle_database_load = "custom\ExileServer_object_vehicle_database_load.sqf";
	// Service and Re-arm Ammo Removal & Safe Vehicle Spawning
	ExileServer_system_trading_network_purchaseVehicleRequest = "custom\ExileServer_system_trading_network_purchaseVehicleRequest.sqf";

	//Enable Building During Combat
	ExileClient_construction_handleAbort = "custom\BuildInCombat\ExileClient_construction_handleAbort.sqf";
	ExileClient_object_construction_deconstruct = "custom\BuildInCombat\ExileClient_object_construction_deconstruct.sqf";
	ExileClient_construction_beginExistingObject = "custom\BuildInCombat\ExileClient_construction_beginExistingObject.sqf";
	ExileClient_construction_beginNewObject = "custom\BuildInCombat\ExileClient_construction_beginNewObject.sqf";
	ExileClient_construction_thread = "custom\BuildInCombat\ExileClient_construction_thread.sqf";
	ExileClient_object_construction_move = "custom\BuildInCombat\ExileClient_object_construction_move.sqf";

	//Enable Repair Construction While In Combat
	ExileClient_action_repairConstruction_completed = "custom\BuildInCombat\ExileClient_action_repairConstruction_completed.sqf";
	ExileClient_action_repairConstruction_condition = "custom\BuildInCombat\ExileClient_action_repairConstruction_condition.sqf";
	ExileClient_object_construction_repair = "custom\BuildInCombat\ExileClient_object_construction_repair.sqf";

	//Enable Repair Vehicle While In Combat
	ExileClient_action_repairVehicle_condition = "custom\BuildInCombat\ExileClient_action_repairVehicle_condition.sqf";

	//Increase Safe and Vehicle Pop-Tab Capacity
	ExileServer_system_money_network_putMoneyRequest = "custom\ExileServer_system_money_network_putMoneyRequest.sqf";
	ExileClient_gui_inventory_updatePopTabControls = "custom\ExileClient_gui_inventory_updatePopTabControls.sqf";

	//God Mode While In Bambi State
	ExileClient_object_player_bambiStateBegin = "custom\ExileClient_object_player_bambiStateBegin.sqf";
	ExileClient_object_player_bambiStateEnd = "custom\ExileClient_object_player_bambiStateEnd.sqf";

	//ExAd XM8 Apps
	ExileClient_gui_xm8_slide = "ExAdClient\XM8\CustomCode\ExileClient_gui_xm8_slide.sqf";
	ExileClient_gui_xm8_show = "ExAdClient\XM8\CustomCode\ExileClient_gui_xm8_show.sqf";
	ExileServer_system_territory_database_load = "ExAdClient\VirtualGarage\CustomCode\ExileServer_system_territory_database_load.sqf";

	//Extended Base Mod Loot Manager System
	exileclient_system_lootmanager_thread_spawn = "addons\EBM\exileclient_system_lootmanager_thread_spawn.sqf";

	//Happys Enigma Revive
	ExileClient_object_player_death_startBleedingOut = "addons\EnigmaRevive\ExileClient_object_player_death_startBleedingOut.sqf";
	//Happys Enigma Revive AntiDupe ---NEW with v0.65
	ExileClient_object_player_event_onInventoryOpened = "addons\EnigmaRevive\ExileClient_object_player_event_onInventoryOpened.sqf";

	//Attach Chemlight
	ExileClient_object_player_initialize = "addons\AttachChemlight\ExileClient_object_player_initialize.sqf";

	//Update Vehicle In Database With Proper Data For Vehicles With No Weapon And Magazine Cargo Values
	ExileServer_object_vehicle_database_update = "custom\ExileServer_object_vehicle_database_update.sqf";

	//Set Static Price For Changing Pin Code On Vehicle
	ExileClient_gui_vehicleRekeyDialog_event_onDropDownSelectionChanged = "custom\ExileClient_gui_vehicleRekeyDialog_event_onDropDownSelectionChanged.sqf";

	//New Player Toast Announcement
	ExileServer_system_network_event_onPlayerConnected = "custom\ExileServer_system_network_event_onPlayerConnected.sqf";

	//Custom Response When Trying To Purchase 0 Poptab Vehicles/Items
	ExileClient_system_trading_network_purchaseVehicleResponse = "custom\ExileClient_system_trading_network_purchaseVehicleResponse.sqf";
	ExileClient_system_trading_network_purchaseItemResponse = "custom\ExileClient_system_trading_network_purchaseItemResponse.sqf";

};

class CfgExileEnvironment
{
	class Lythium 
	{
		class FireFlies
		{
			// 1 = enabled, 0 = disabled
			enable = 1;

			// At this hour fire flies begin to spawn
			startHour = 18;

			// At this hour fire flies stop spawning
			endHour = 6;
		};

		class Anomalies
		{
			// 1 = enabled, 0 = disabled
			enable = 0;

			// At this hour anomalies begin to spawn
			startHour = 19;

			// At this hour anomalies stop spawning
			endHour = 6;
		};

		class Breathing
		{
			// 1 = enabled, 0 = disabled
			enable = 0;
		};

		class Snow
		{
			// 1 = enabled, 0 = disabled
			enable = 0;

			// https://community.bistudio.com/wiki/surfaceType
			surfaces[] = {};
		};

		class Radiation 
		{
			// 1 = enabled, 0 = disabled
			enable = 0;

			/*
				Defines contaminated zones in a specific map. 
				You can define multiple zones per map. The format
				of the zones is:

				[Position ASL(!), Full Radiation Radius, Maximum Radius]

				The radius works as follows:

	            |-------------------------------------------------------|
	                                Maximum Radius
				
				|------------------------|
				  Full Radiation Radius   

				Within the full radiation radius, radiation factor is
				always at a maximum. Outside of this, it lowers down
				to no radiation smoothly.

				Radiation:

	            |------------------------|------------------------------|
	            1        1      1        1     0.75    0.5     0.25    0
			*/
			contaminatedZones[] = {};
		};

		class Temperature
		{
			// Temperature in °C for the time of day, per hour
			// Add the first index to the last index, so it is 25 indizes!
			daytimeTemperature[] = {15.93,16.89,18.42,20.40,22.68,25.10,27.48,29.63,31.40,32.66,33.32,33.80,33.80,33.32,32.66,31.40,29.63,27.48,25.10,22.68,20.40,18.42,16.89,15.93,15.93};
		
			// Temperature change in °C when it is 100% overcast
			overcast = -2;

			// Temperature change in °C when it is 100% raining
			rain = -5;

			// Temperature change in °C when it is 100% windy
			wind = -1;

			// Temperature change per 100m altitude in °C
			altitude = -0.5;

			// Difference from the daytime temperature to the water temperature
			water = -5;
		};
	};
};

class CfgExileHUD
{
	class ShortItemNames
	{
		SmokeShell[] 											= {"WHITE", 	"SMOKE"};
		1Rnd_Smoke_Grenade_shell[] 				= {"WHITE", 	"SMOKE"};
		3Rnd_Smoke_Grenade_shell[] 				= {"WHITE", 	"SMOKE"};

		SmokeShellBlue[] 									= {"BLUE", 		"SMOKE"};
		1Rnd_SmokeBlue_Grenade_shell[] 		= {"BLUE", 		"SMOKE"};
		3Rnd_SmokeBlue_Grenade_shell[] 		= {"BLUE", 		"SMOKE"};

		SmokeShellGreen[] 								= {"GREEN", 	"SMOKE"};
		1Rnd_SmokeGreen_Grenade_shell[] 	= {"GREEN", 	"SMOKE"};
		3Rnd_SmokeGreen_Grenade_shell[] 	= {"GREEN", 	"SMOKE"};

		SmokeShellOrange[] 								= {"ORANGE", 	"SMOKE"};
		1Rnd_SmokeOrange_Grenade_shell[]	= {"ORANGE", 	"SMOKE"};
		3Rnd_SmokeOrange_Grenade_shell[] 	= {"ORANGE", 	"SMOKE"};

		SmokeShellPurple[] 								= {"PURPLE", 	"SMOKE"};
		1Rnd_SmokePurple_Grenade_shell[] 	= {"PURPLE", 	"SMOKE"};
		3Rnd_SmokePurple_Grenade_shell[] 	= {"PURPLE", 	"SMOKE"};

		SmokeShellRed[] 									= {"RED", 		"SMOKE"};
		1Rnd_SmokeRed_Grenade_shell[] 		= {"RED", 		"SMOKE"};
		3Rnd_SmokeRed_Grenade_shell[] 		= {"RED", 		"SMOKE"};
				
		SmokeShellYellow[] 								= {"YELLOW", 	"SMOKE"};
		1Rnd_SmokeYellow_Grenade_shell[] 	= {"YELLOW", 	"SMOKE"};
		3Rnd_SmokeYellow_Grenade_shell[] 	= {"YELLOW", 	"SMOKE"};
				
		UGL_FlareCIR_F[] 									= {"IR", 		"FLARE"};
		3Rnd_UGL_FlareCIR_F[] 						= {"IR", 		"FLARE"};

		UGL_FlareGreen_F[] 								= {"GREEN", 	"FLARE"};
		3Rnd_UGL_FlareGreen_F[] 					= {"GREEN", 	"FLARE"};

		UGL_FlareRed_F[] 									= {"RED", 		"FLARE"};
		3Rnd_UGL_FlareRed_F[] 						= {"RED", 		"FLARE"};

		UGL_FlareWhite_F[] 								= {"WHITE", 	"FLARE"};
		3Rnd_UGL_FlareWhite_F[] 					= {"WHITE", 	"FLARE"};

		UGL_FlareYellow_F[] 							= {"YELLOW", 	"FLARE"};
		3Rnd_UGL_FlareYellow_F[] 					= {"YELLOW", 	"FLARE"};

		Chemlight_blue[] 									= {"BLUE", 		"LIGHT"};
		Chemlight_green[] 								= {"GREEN", 	"LIGHT"};
		Chemlight_red[] 									= {"RED", 		"LIGHT"};
		Chemlight_yellow[] 								= {"YELLOW", 	"LIGHT"};

		1Rnd_HE_Grenade_shell[] 					= {"40MM"};
		3Rnd_HE_Grenade_shell[] 					= {"40MM"};

		O_IR_Grenade[] 										= {"IR"};
		I_IR_Grenade[] 										= {"IR"};
		B_IR_Grenade[] 										= {"IR"};

		HandGrenade[] 										= {"RGO"};
		MiniGrenade[] 										= {"RGN"};

		Exile_Item_ZipTie[]								= {"ZIP", "TIE"};

		//CUP
		CUP_1Rnd_HE_M203[] 								= {"40MM"};
		CUP_1Rnd_HEDP_M203[] 							= {"40MM"};
		CUP_FlareWhite_M203[] 						= {"WHITE", 	"FLARE"};
		CUP_FlareGreen_M203[] 						= {"GREEN", 	"FLARE"};
		CUP_FlareRed_M203[] 							= {"RED", 		"FLARE"};
		CUP_FlareYellow_M203[] 						= {"YELLOW", 	"FLARE"};
		CUP_1Rnd_Smoke_M203[] 						= {"WHITE", 	"SMOKE"};
		CUP_1Rnd_SmokeRed_M203[] 					= {"RED", 		"SMOKE"};
		CUP_1Rnd_SmokeGreen_M203[]				= {"GREEN", 	"SMOKE"};
		CUP_1Rnd_SmokeYellow_M203[]				= {"YELLOW", 	"SMOKE"};

		//NIA
		hlc_VOG25_AK[]										= {"40MM"};
		hlc_GRD_White[]										= {"WHITE", 	"SMOKE"};
		hlc_GRD_red[]											= {"RED",			"SMOKE"};
		hlc_GRD_green[]										= {"GREEN", 	"SMOKE"};
		hlc_GRD_blue[]										= {"BLUE",		"SMOKE"};
		hlc_GRD_orange[]									= {"ORANGE", 	"SMOKE"};
		hlc_GRD_purple[]									= {"PURPLE", 	"SMOKE"};
	};
};

class CfgExileLootSettings
{
	/**
	 * Lifetime of loot in minutes. Synchronize this with
	 * the garbage collector settings of your server
	 * CfgSettings!
	 */
	lifeTime = 8;

	/**
	 * Interval in seconds when the client searches for
	 * new buildings to spawn loot in
	 */
	spawnInterval = 30;

	/**
	 * This is a percentage value to determine how many loot
	 * positions should contain loot when the system spawns loot.
	 *
	 * If a building has 20 positions defined, Exile will 
	 * spawn loot in 10 random positions of them.
	 * 
	 * This means smaller buildings spawn less loot and larger
	 * ones spawn more loot.
	 *
	 * You can also cap it at a maximum value. See below.
	 */
	maximumPositionCoverage = 75;

 	/**
 	 * Limit the number of loot positions per building. If the 
 	 * above percentage value exceeds this value, it will be capped.
 	 *
 	 * Example: Coverage is 50%. Building has 60 loot positions defined.
 	 * This results in 30 loot positions and that is too much. So we
 	 * cap this at 10
 	 */
	maximumNumberOfLootSpotsPerBuilding = 10;

	/**
	 * Exile spawns a random number of items per loot spot. This 
	 * is the upper cap for that. So 3 means it could spawn 1, 2 
	 * or 3.
	 */
	maximumNumberOfItemsPerLootSpot = 2;

	/**
	 * Radius in meter to spawn loot AROUND each player.
	 * Do NOT touch this value if you dont know what you do.
	 * The higher the number, the higher the drop rates, the
	 * easier your server will lag.
	 *
	 * 50m  = Minimum
	 * 200m = Maximum
	 */
	spawnRadius = 90;

	/**
	 * Defines the radius around trader cities where the system should
	 * not spawn loot. Set this to 0 if you want to have loot spawning
	 * in trader citites, ugh.
	 */
	minimumDistanceToTraderZones = 500;

	/**
	 * Defines the radius around territories where no loot spawns.
	 * This does not regard the actual size of a territory. So do not
	 * set this to a lower value than the maximum radius of a territory,
	 * which is 150m by default.
	 */
	minimumDistanceToTerritories = 150;
};

class CfgExileMobileXM8
{
	/**
	 * Add the 4 digit permission code here, so players can authorize
	 * your server to send them messages to their Mobile XM8 app.
	 */
	code = "";
};

class CfgExileMusic
{
	Ambient[] = {"ExileTrack03","ExileTrack04"};
	Combat[] = {"ExileTrack06","ExileTrack07"};
	Intro[] = {"ExileTrack02","ExileTrack03"};
};

class CfgExileParty 
{
	showESP = 1;
	allow3DMarkers = 1;
};

class CfgExileRussianRoulette
{
	/*
		Minimum amount to join a session of 
		russian roulette
	*/
	buyInAmount = 100;
};

class CfgFlags 
{
	class USA
	{
		name = "USA";
		texture = "\A3\Data_F\Flags\flag_us_co.paa";
		uids[] = {};
	};
	class BSOD
	{
		name = "BSOD";
		texture = "custom\flags\BSOD.paa";
		uids[] = {};
	};
	class Dont_Tread
	{
		name = "Don't Tread On Me";
		texture = "custom\flags\Dont_Tread.paa";
		uids[] = {};
	};
	class Fallout_Boy
	{
		name = "Fallout Boy";
		texture = "custom\flags\Fallout_Boy.paa";
		uids[] = {};
	};
	class Free_Beer
	{
		name = "Free Beer";
		texture = "custom\flags\Free_Beer.paa";
		uids[] = {};
	};
	class Heisenberg_1
	{
		name = "Heisenberg 1";
		texture = "custom\flags\Heisenberg_1.paa";
		uids[] = {};
	};
	class Heisenberg_2
	{
		name = "Heisenberg 2";
		texture = "custom\flags\Heisenberg_2.paa";
		uids[] = {};
	};
	class VaultTec
	{
		name = "Vault-Tec";
		texture = "custom\flags\VaultTec.paa";
		uids[] = {};
	};
};

class ExileAbstractAction
{
	title = "";
	condition = "true";
	action = "";
	priority = 1.5;
	showWindow = false;
};

/**
 * Sort this by probability of occurence to speed things up a bit
 */
class CfgInteractionMenus
{
	#include "addons\EBM\menus.hpp"
	class Car 
	{
		targetType = 2;
		target = "Car";

		class Actions 
		{
			/*
			class ScanLock: ExileAbstractAction
			{
				title = "Scan Lock";
				condition = "('Exile_Item_ThermalScannerPro' in (magazines player)) && !ExilePlayerInSafezone && ((locked ExileClientInteractionObject) != 1)";
				action = "_this call ExileClient_object_lock_scan";
			};
			*/

			// Locks a vehicle
			class Lock: ExileAbstractAction
			{
				title = "Lock";
				condition = "((locked ExileClientInteractionObject) isEqualTo 0) && ((locked ExileClientInteractionObject) != 1)";
				action = "true spawn ExileClient_object_lock_toggle";
			};

			// Unlocks a vehicle
			class Unlock: ExileAbstractAction
			{
				title = "Unlock";
				condition = "((locked ExileClientInteractionObject) isEqualTo 2) && ((locked ExileClientInteractionObject) != 1)";
				action = "false spawn ExileClient_object_lock_toggle";
			};

			// Claim vehicle with code lock
			class ClaimVehicle: ExileAbstractAction
			{
 			   title = "Claim Ownership";
 			   condition = "('Exile_Item_Codelock' in (magazines player))"; // "true"
 			   action = "call ExileClient_ClaimVehicles_network_claimRequestSend";
			};

			//Salvage metal from cars
			class SalvageMetal: ExileAbstractAction
			{
				title = "Salvage Metal";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call Kuplion_fnc_salvageMetal";
			};

			// Recover Body
			class Recover: ExileAbstractAction
			{
				title = "Recover Body";
				condition = "(!(alive (ExileClientInteractionObject)))";
				action = "_this call NR_fnc_RecoverBody";
			};

			// Repairs a vehicle to 100%. Requires Duckttape
			class Repair: ExileAbstractAction
			{
				title = "Repair";
				condition = "true";
				action = "['RepairVehicle', _this select 0] call ExileClient_action_execute";
			};

			/*
			// Hot-wires a vehicle
			class Hotwire: ExileAbstractAction
			{
				title = "Hotwire";
				condition = "((locked ExileClientInteractionObject) isEqualTo 2) && ((locked ExileClientInteractionObject) != 1)";
				action = "['HotwireVehicle', _this select 0] call ExileClient_action_execute";
			};
			*/

			// Flips a vehicle so the player doesnt have to call an admin
			// Check if vector up is fucked
			class Flip: ExileAbstractAction
			{
				title = "Flip";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_flip";
			};

			// Fills fuel from a can into a car
			class Refuel: ExileAbstractAction
			{
				title = "Refuel";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_refuel";
			};

			// Drains fuel from a car into an empty jerry can
			class DrainFuel: ExileAbstractAction
			{
				title = "Drain Fuel";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_drain";
			};

			// ExAd Pack Quad
			class PackDeployedVehicle: ExileAbstractAction
			{
				title = "Pack Vehicle";
				condition = "call ExAd_XM8_DV_fnc_canPack";
				action = "call ExAd_XM8_DV_fnc_pack";
			};
		};
	};

	class Tank 
	{
		targetType = 2;
		target = "Tank";

		class Actions 
		{
			/*
			class ScanLock: ExileAbstractAction
			{
				title = "Scan Lock";
				condition = "('Exile_Item_ThermalScannerPro' in (magazines player)) && !ExilePlayerInSafezone && ((locked ExileClientInteractionObject) != 1)";
				action = "_this call ExileClient_object_lock_scan";
			};
			*/

			// Locks a vehicle
			class Lock: ExileAbstractAction
			{
				title = "Lock";
				condition = "((locked ExileClientInteractionObject) isEqualTo 0) && ((locked ExileClientInteractionObject) != 1)";
				action = "true spawn ExileClient_object_lock_toggle";
			};

			// Unlocks a vehicle
			class Unlock: ExileAbstractAction
			{
				title = "Unlock";
				condition = "((locked ExileClientInteractionObject) isEqualTo 2) && ((locked ExileClientInteractionObject) != 1)";
				action = "false spawn ExileClient_object_lock_toggle";
			};

			// Claim vehicle with code lock
			class ClaimVehicle: ExileAbstractAction
			{
 			   title = "Claim Ownership";
 			   condition = "('Exile_Item_Codelock' in (magazines player))"; // "true"
 			   action = "call ExileClient_ClaimVehicles_network_claimRequestSend";
			};

			//Salvage metal from cars
			class SalvageMetal: ExileAbstractAction
			{
				title = "Salvage Metal";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call Kuplion_fnc_salvageMetal";
			};

			// Recover Body
			class Recover: ExileAbstractAction
			{
				title = "Recover Body";
				condition = "(!(alive (ExileClientInteractionObject)))";
				action = "_this call NR_fnc_RecoverBody";
			};

			// Repairs a vehicle to 100%. Requires Duckttape
			class Repair: ExileAbstractAction
			{
				title = "Repair";
				condition = "true";
				action = "['RepairVehicle', _this select 0] call ExileClient_action_execute";
			};

			/*
			// Hot-wires a vehicle
			class Hotwire: ExileAbstractAction
			{
				title = "Hotwire";
				condition = "((locked ExileClientInteractionObject) isEqualTo 2) && ((locked ExileClientInteractionObject) != 1)";
				action = "['HotwireVehicle', _this select 0] call ExileClient_action_execute";
			};
			*/

			// Flips a vehicle so the player doesnt have to call an admin
			// Check if vector up is fucked
			class Flip: ExileAbstractAction
			{
				title = "Flip";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_flip";
			};

			// Fills fuel from a can into a car
			class Refuel: ExileAbstractAction
			{
				title = "Refuel";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_refuel";
			};

			// Drains fuel from a car into an empty jerry can
			class DrainFuel: ExileAbstractAction
			{
				title = "Drain Fuel";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_drain";
			};
		};
	};

	class Air
	{
		target = "Air";
		targetType = 2;

		class Actions
		{
			/*
			class ScanLock: ExileAbstractAction
			{
				title = "Scan Lock";
				condition = "('Exile_Item_ThermalScannerPro' in (magazines player)) && ((locked ExileClientInteractionObject) != 1) && !ExilePlayerInSafezone";
				action = "_this call ExileClient_object_lock_scan";
			};
			*/

			// Locks a vehicle
			class Lock: ExileAbstractAction
			{
				title = "Lock";
				condition = "((locked ExileClientInteractionObject) isEqualTo 0) && ((locked ExileClientInteractionObject) != 1)";
				action = "true spawn ExileClient_object_lock_toggle";
			};

			// Unlocks a vehicle
			class Unlock: ExileAbstractAction
			{
				title = "Unlock";
				condition = "((locked ExileClientInteractionObject) isEqualTo 2) && ((locked ExileClientInteractionObject) != 1)";
				action = "false spawn ExileClient_object_lock_toggle";
			};

			// Claim vehicle with code lock
			class ClaimVehicle: ExileAbstractAction
			{
 			   title = "Claim Ownership";
 			   condition = "('Exile_Item_Codelock' in (magazines player))"; // "true"
 			   action = "call ExileClient_ClaimVehicles_network_claimRequestSend";
			};

			/*
			// Hot-wires a vehicle
			class Hotwire: ExileAbstractAction
			{
				title = "Hotwire";
				condition = "((locked ExileClientInteractionObject) isEqualTo 2) && ((locked ExileClientInteractionObject) != 1)";
				action = "['HotwireVehicle', _this select 0] call ExileClient_action_execute";
			};
			*/

			//Salvage metal from cars
			class SalvageMetal: ExileAbstractAction
			{
				title = "Salvage Metal";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call Kuplion_fnc_salvageMetal";
			};

			// Recover Body
			class Recover: ExileAbstractAction
			{
				title = "Recover Body";
				condition = "(!(alive (ExileClientInteractionObject)))";
				action = "_this call NR_fnc_RecoverBody";
			};

			// Repairs a vehicle to 100%. Requires Duckttape
			class Repair: ExileAbstractAction
			{
				title = "Repair";
				condition = "true";
				action = "['RepairVehicle', _this select 0] call ExileClient_action_execute";
			};

			// Flips a vehicle so the player doesnt have to call an admin
			// Check if vector up is fucked
			class Flip: ExileAbstractAction
			{
				title = "Flip";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_flip";
			};

			// Fills fuel from a can into a car
			class Refuel: ExileAbstractAction
			{
				title = "Refuel";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_refuel";
			};

			// Drains fuel from a car into an empty jerry can
			class DrainFuel: ExileAbstractAction
			{
				title = "Drain Fuel";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_drain";
			};

			class RotateLeft: ExileAbstractAction
			{
				title = "Rotate Left";	
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "[ExileClientInteractionObject,-15] call ExileClient_object_vehicle_rotate";
			};

			class RotateRight: ExileAbstractAction
			{
				title = "Rotate Right";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "[ExileClientInteractionObject,15] call ExileClient_object_vehicle_rotate";
			};
		};
	};

	class TraderATM
	{
		targetType = 2;
		target = "Exile_Trader_CommunityCustoms";
		
		class Actions
		{
			// Access Locker Through Gypsy Trader Vehicle
			class CoinPurse: ExileAbstractAction
			{
 			   title = "Coin Purse";
 			   condition = "true";
 			   action = "call ExileClient_gui_lockerDialog_show";
			};
		};
	};

	class Praetorian1C
	{
		targetType = 2;
		target = "B_AAA_System_01_F";

		class Actions
		{
			// Locks a vehicle
			class Lock : ExileAbstractAction
			{
				title = "Lock";
				condition = "((ExileClientInteractionObject getvariable ['ExileIsLocked',1]) isEqualTo 0)";
				action = "true spawn ExileClient_object_lock_toggle";
			};
			// Unlocks a vehicle
			class Unlock : ExileAbstractAction
			{
				title = "Unlock";
				condition = "((ExileClientInteractionObject getvariable ['ExileIsLocked',1]) isEqualTo -1)";
				action = "false spawn ExileClient_object_lock_toggle";
			};
			// Repairs a vehicle to 100%. Requires Duckttape
			class Repair: ExileAbstractAction
			{
				title = "Repair";
				condition = "true";
				action = "['RepairVehicle', _this select 0] call ExileClient_action_execute";
			};
			// Claim vehicle with code lock
			class ClaimVehicle: ExileAbstractAction
			{
 			   title = "Claim Ownership";
 			   condition = "('Exile_Item_Codelock' in (magazines player))"; // "true"
 			   action = "call ExileClient_ClaimVehicles_network_claimRequestSend";
			};
		};
	};

	class Safe
	{
		targetType = 2;
		target = "Exile_Container_Safe";

		class Actions 
		{
			/*
			class ScanLock: ExileAbstractAction
			{
				title = "Scan Lock";
				condition = "('Exile_Item_ThermalScannerPro' in (magazines player)) && !((ExileClientInteractionObject getvariable ['ExileIsLocked',1]) isEqualTo 1) && !ExilePlayerInSafezone";
				action = "_this call ExileClient_object_lock_scan";
			};
			*/

			// Locks a vehicle
			class Lock : ExileAbstractAction
			{
				title = "Lock";
				condition = "((ExileClientInteractionObject getvariable ['ExileIsLocked',1]) isEqualTo 0)";
				action = "true spawn ExileClient_object_lock_toggle";
			};

			class Unlock : ExileAbstractAction
			{
				title = "Unlock";
				condition = "((ExileClientInteractionObject getvariable ['ExileIsLocked',1]) isEqualTo -1)";
				action = "false spawn ExileClient_object_lock_toggle";
			};

			class Pack : ExileAbstractAction
			{
				title = "Pack";
				condition = "((ExileClientInteractionObject getvariable ['ExileIsLocked',1]) isEqualTo 0)";
				action = "_this spawn ExileClient_object_container_pack";
			};

			class SetPinCode : ExileAbstractAction
			{
				title = "Set PIN";
				condition = "((ExileClientInteractionObject getvariable ['ExileIsLocked',1]) isEqualTo 0)";
				action = "_this spawn ExileClient_object_lock_setPin";
			};
		};
	};

	class Laptop
	{
		targetType = 2;
		target = "Exile_Construction_Laptop_Static";

		class Actions
		{
			class CameraSystem: ExileAbstractAction
			{
				title = "CCTV Access";
				condition = "((ExileClientInteractionObject animationPhase 'LaptopLidRotation') >= 0.5)";
				action = "_this call ExileClient_gui_baseCamera_show";
			};
		};
	};

	class SupplyBox
	{
		targetType = 2;
		target = "Exile_Container_SupplyBox";

		class Actions
		{
			/*
			class Mount: ExileAbstractAction
			{
				title = "Mount";
				condition = "(isNull (attachedTo ExileClientInteractionObject)) && ((ExileClientInteractionObject getvariable ['ExileOwnerUID',1]) isEqualTo 1)";
				action = "_this call ExileClient_object_supplyBox_mount";
			};
			*/
			class Install: ExileAbstractAction
			{
				title = "Install";
				condition = "isNull (attachedTo ExileClientInteractionObject) && ((ExileClientInteractionObject getvariable ['ExileOwnerUID',1]) isEqualTo 1)";
				action = "_this call ExileClient_object_supplyBox_install";
			};

			/*
			class Unmount: ExileAbstractAction
			{
				title = "Unmount";
				condition = "!(isNull (attachedTo ExileClientInteractionObject)) && ((ExileClientInteractionObject getvariable ['ExileOwnerUID',1]) isEqualTo 1)";
				action = "_this call ExileClient_object_supplyBox_unmount";
			};
			*/
		};
	};
	
	class Drawbridge
	{
		targetType = 2;
		target = "Exile_Construction_WoodDrawBridge_Abstract";

		class Actions
		{
			class Lower: ExileAbstractAction
			{
				title = "Lower";
				condition = "ExileClientInteractionObject call ExileClient_object_construction_openBridgeShow";
				action = "ExileClientInteractionObject animateSource ['DrawBridge_Source', 0];";
			};
			
			class Raise: ExileAbstractAction
			{
				title = "Raise";
				condition = "((ExileClientInteractionObject animationSourcePhase 'DrawBridge_Source') < 0.5)";
				action = "ExileClientInteractionObject animateSource ['DrawBridge_Source', 2]";
			};
		};
	};

	class Construction
	{
		targetType = 2;
		target = "Exile_Construction_Abstract_Static";

		class Actions 
		{
			/*
			class ScanLock: ExileAbstractAction
			{
				title = "Scan Lock";
				condition = "('Exile_Item_ThermalScannerPro' in (magazines player)) && !((ExileClientInteractionObject getvariable ['ExileIsLocked',1]) isEqualTo 1)";
				action = "_this call ExileClient_object_lock_scan";
			};
			*/

			class Unlock : ExileAbstractAction
			{
				title = "Unlock";
				condition = "((ExileClientInteractionObject getvariable ['ExileIsLocked',1]) isEqualTo -1)";
				action = "false spawn ExileClient_object_lock_toggle";
			};

			class Lock : ExileAbstractAction
			{
				title = "Lock";
				condition = "((ExileClientInteractionObject getvariable ['ExileIsLocked',1]) isEqualTo 0)";
				action = "true spawn ExileClient_object_lock_toggle";
			};

			// Picks up the construction so you can move it
			class Move: ExileAbstractAction
			{
				title = "Move";
				condition = "call ExileClient_util_world_isInOwnTerritory";
				action = "_this spawn ExileClient_object_construction_move";
			};

			// Removes the construction.
			class Deconstruct: ExileAbstractAction
			{
				title = "Remove";
				condition = "call ExileClient_util_world_isInOwnTerritory";
				action = "_this spawn ExileClient_object_construction_deconstruct";
			};

			class AddALock : ExileAbstractAction
			{
				title = "Add a Lock";
				condition = "call ExileClient_object_construction_lockAddShow";
				action = "_this spawn ExileClient_object_construction_lockAdd";
			};

			class Upgrade : ExileAbstractAction
			{
				title = "Upgrade";
				condition = "call ExileClient_object_construction_upgradeShow";
				action = "_this call ExileClient_object_construction_upgrade";
			};

			/*
			class MakeBoom : ExileAbstractAction
			{
				title = "Plant charge";
				condition = "call ExileClient_system_breaching_condition";
				action = "_this call ExileClient_system_breaching_action";
			};
			*/

			class Repair : ExileAbstractAction
			{
				title = "Repair";
				condition = "(!((ExileClientInteractionObject getVariable ['ExileConstructionDamage',0]) isEqualTo 0)) && (call ExileClient_util_world_isInOwnTerritory)";
				action = "_this call ExileClient_object_construction_repair";
			};
		};
	};

	/*
		Tent, Storage crate etc.
	*/
	class Container
	{
		targetType = 2;
		target = "Exile_Container_Abstract";

		class Actions 
		{
			class Pack 
			{
				title = "Pack";
				condition = "!((typeOf ExileClientInteractionObject) isEqualTo 'Exile_Container_SupplyBox')";
				action = "_this spawn ExileClient_object_container_pack";
			};
			// Picks up the container so you can move it
			class Move: ExileAbstractAction
			{
				title = "Move";
				condition = "(getNumber(configFile >> 'CfgVehicles' >> typeOf ExileClientInteractionObject >> 'exileIsLockable') isEqualTo 0) || ((ExileClientInteractionObject getvariable ['ExileIsLocked',1]) isEqualTo 0)";
				action = "_this spawn ExileClient_object_construction_move";
			};
		};
	};
	
	class Flag
	{
		targetType = 2;
		target = "Exile_Construction_Flag_Static";

		class Actions
		{
			/*
			class Manage : ExileAbstractAction
			{
				title = "Manage";
				condition = "true";
				action = "_this call ExileClient_gui_baseManagement_event_show";
			};
			*/

			/*
			class StealFlag: ExileAbstractAction
			{
				title = "Steal Flag";
				condition = "((ExileClientInteractionObject getvariable ['ExileFlagStolen',1]) isEqualTo 0)";
				action = "['StealFlag', _this select 0] call ExileClient_action_execute";
			};
			*/
			
			class RestoreFlag: ExileAbstractAction
			{
				title = "Restore Flag";
				condition = "((ExileClientInteractionObject getvariable ['ExileFlagStolen',0]) isEqualTo 1)";
				action = "['restoreFlagRequest', [netID ExileClientInteractionObject]] call ExileClient_system_network_send";
			};

			class VG : ExileAbstractAction
			{
				title = "Virtual Garage";
				condition = "(([_object, getPlayerUID player] call ExileClient_util_territory_getAccessLevel) select 0) >= ExAd_VG_ACCESS_LEVEL";
				action = "[] spawn {[] call ExileClient_gui_xm8_show; UISleep 1; call XM8_VG_checkNearByFlags}";
			};
		};
	};

	class Boat 
	{
		targetType = 2;
		target = "Ship";

		class Actions
		{
			// Locks a vehicle
			class Lock: ExileAbstractAction
			{
				title = "Lock";
				condition = "((locked ExileClientInteractionObject) isEqualTo 0) && ((locked ExileClientInteractionObject) != 1)";
				action = "true spawn ExileClient_object_lock_toggle";
			};

			// Unlocks a vehicle
			class Unlock: ExileAbstractAction
			{
				title = "Unlock";
				condition = "((locked ExileClientInteractionObject) isEqualTo 2) && ((locked ExileClientInteractionObject) != 1)";
				action = "false spawn ExileClient_object_lock_toggle";
			};

			// Claim vehicle with code lock
			class ClaimVehicle: ExileAbstractAction
			{
 			   title = "Claim Ownership";
 			   condition = "('Exile_Item_Codelock' in (magazines player))"; // "true"
 			   action = "call ExileClient_ClaimVehicles_network_claimRequestSend";
			};

			/*
			// Hot-wires a vehicle
			class Hotwire: ExileAbstractAction
			{
				title = "Hotwire";
				condition = "((locked ExileClientInteractionObject) isEqualTo 2) && ((locked ExileClientInteractionObject) != 1)";
				action = "['HotwireVehicle', _this select 0] call ExileClient_action_execute";
			};
			*/

			// Repairs a vehicle to 100%. Requires Duckttape
			class Repair: ExileAbstractAction
			{
				title = "Repair";
				condition = "true";
				action = "['RepairVehicle', _this select 0] call ExileClient_action_execute";
			};

			// Fills fuel from a can into a car
			class Refuel: ExileAbstractAction
			{
				title = "Refuel";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_refuel";
			};

			// Drains fuel from a car into an empty jerry can
			class DrainFuel: ExileAbstractAction
			{
				title = "Drain Fuel";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_drain";
			};

			// Pushes a boat into look direction to move into water
			class Push: ExileAbstractAction
			{
				title = "Push Off";
				condition = "((crew ExileClientInteractionObject) isEqualTo [])";
				action = "_this call ExileClient_object_vehicle_push";
			};

			// ExAd Pack Jet Ski
			class PackDeployedVehicle: ExileAbstractAction
			{
				title = "Pack Vehicle";
				condition = "call ExAd_XM8_DV_fnc_canPack";
				action = "call ExAd_XM8_DV_fnc_pack";
			};
		};
	};

	class Bikes
	{
		targetType = 2;
		target = "Bicycle";

		class Actions
		{
			class Flip: ExileAbstractAction
			{
				title = "Flip";
				condition = "true";
				action = "_this call ExileClient_object_vehicle_flip";
			};

			// ExAd Pack Bike
			class PackDeployedVehicle: ExileAbstractAction
			{
				title = "Pack Bike";
				condition = "call ExAd_XM8_DV_fnc_canPack";
				action = "call ExAd_XM8_DV_fnc_pack";
			};
		};
	};

	class Motorcycles
	{
		targetType = 2;
		target = "Motorcycle";

		class Actions
		{
			// Repairs a vehicle to 100%. Requires Duckttape
			class Repair: ExileAbstractAction
			{
				title = "Repair";
				condition = "true";
				action = "['RepairVehicle', _this select 0] call ExileClient_action_execute";
			};

			// Fills fuel from a can into a car
			class Refuel: ExileAbstractAction
			{
				title = "Refuel";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_refuel";
			};

			// Drains fuel from a car into an empty jerry can
			class DrainFuel: ExileAbstractAction
			{
				title = "Drain Fuel";
				condition = "call ExileClient_object_vehicle_interaction_show";
				action = "_this call ExileClient_object_vehicle_drain";
			};

			class Flip: ExileAbstractAction
			{
				title = "Flip";
				condition = "true";
				action = "_this call ExileClient_object_vehicle_flip";
			};

			// Recover Body
			class Recover: ExileAbstractAction
			{
				title = "Recover Body";
				condition = "(!(alive (ExileClientInteractionObject)))";
				action = "_this call NR_fnc_RecoverBody";
			};

			// ExAd Pack Motorcycle
			class PackDeployedVehicle: ExileAbstractAction
			{
				title = "Pack Motorcycle";
				condition = "call ExAd_XM8_DV_fnc_canPack";
				action = "call ExAd_XM8_DV_fnc_pack";
			};
		};
	};

	class Player 
	{
		targetType = 2;
		target = "Exile_Unit_Player";

		class Actions 
		{
			class Free: ExileAbstractAction
			{
				title = "Free";
				condition = "(alive ExileClientInteractionObject) && (ExileClientInteractionObject getVariable ['ExileIsHandcuffed', false]) && !ExileClientIsHandcuffed";
				action = "_this call ExileClient_object_handcuffs_free";
			};
			
			class Search: ExileAbstractAction
			{
				title = "Search Gear";
				condition = "(alive ExileClientInteractionObject) && (ExileClientInteractionObject getVariable ['ExileIsHandcuffed', false]) && !ExileClientIsHandcuffed";
				action = "_this call ExileClient_object_handcuffs_searchGear";
			};

			class Identify: ExileAbstractAction
			{
				title = "Identify Body";
				condition = "!(alive ExileClientInteractionObject)";
				action = "_this call ExileClient_object_player_identifyBody";
			};

			//////////////Added by [_ZEN_]happydayz/////////////////
			class Revive: ExileAbstractAction
			{
				title = "Perform CPR";
				condition = "(!(alive ExileClientInteractionObject) && (ExileClientInteractionObject getVariable ['EnigmaRevivePermitted', true]) && (magazines player find 'Exile_Item_Defibrillator' >= 0))";
				action = "_this spawn Enigma_RevivePlyr";
			};
			
			class HideCorpse: ExileAbstractAction
			{
				title = "Hide Body";
				condition = "!(alive ExileClientInteractionObject) && ('Exile_Melee_Shovel' isEqualTo (currentWeapon player))";
				action = "['HideBody', (_this select 0)] call ExileClient_action_execute";
			};
		};
	};
	
	class Animal
	{
		targetType = 2;
		target = "Exile_Animal_Abstract";

		class Actions 
		{			
			class Gut: ExileAbstractAction
			{
				title = "Gut Animal";
				condition = "!(alive ExileClientInteractionObject) && (ExileClientInteractionObject getVariable ['CanBeGutted', false])";
				action = "['GutAnimal', ExileClientInteractionObject] call ExileClient_action_execute";
			};
		};
	};
};
/**
 * Classname is used for reference
 * name is displayed in crafting requirements
 * models is used for crafting and interaction menus
 */
class CfgInteractionModels
{
	class WaterSource
	{
		name = "Water tanks, barrels, coolers or pumps";
		models[] = 	
		{
			"barrelwater_f", 
			"barrelwater_grey_f",
			"waterbarrel_f",
			"watertank_f",
			"stallwater_f",
			"waterpump_01_f",
			"water_source_f",

			// EBM
			"Sink_F",
			"Tank_rust_F",
			"Waterpump_01_F",

			// Namalsk
			"wellpump",
			"Land_KBud",
			
			//Tanoa
			"watertank_01_f",
			"watertank_02_f",
			"watertank_03_f",
			"watertank_04_f",

			//Lythium
			"Land_jbad_Fridge",
			"Land_Jbad_Misc_Well_C",
			"Land_Jbad_Misc_Well_L",
			"Land_jbad_reservoir",
			"Land_jhad_stand_water",
			"Land_jbad_teapot"
		};
	};

	class CleanWaterSource
	{
		name = "Water cooler";
		models[] = 	
		{
			"watercooler"
		};
	};

	class WorkBench
	{
		name = "Work Bench";
		models[] = 
		{
			"workstand_f.p3d"
		};
	};

	class ShippingContainerSource
	{
		name = "Shipping Containers";
		models[] = 
		{
			// Arma 3
			"CargoBox_V1_F",
			"Cargo20_blue_F",
			"Cargo20_brick_red_F",
			"Cargo20_cyan_F",
			"Cargo20_grey_F",
			"Cargo20_light_blue_F",
			"Cargo20_light_green_F",
			"Cargo20_military_green_F",
			"Cargo20_military_ruins_F",
			"Cargo20_orange_F",
			"Cargo20_red_F",
			"Cargo20_sand_F",
			"Cargo20_white_F",
			"Cargo20_yellow_F",
			"Cargo40_blue_F",
			"Cargo40_brick_red_F",
			"Cargo40_cyan_F",
			"Cargo40_grey_F",
			"Cargo40_light_blue_F",
			"Cargo40_light_green_F",
			"Cargo40_military_green_F",
			"Cargo40_orange_F",
			"Cargo40_red_F",
			"Cargo40_sand_F",
			"Cargo40_white_F",
			"Cargo40_yellow_F",

			// Namalsk
			"nam_container.p3d",
			"misc_cargo1d.p3d",
			"misc_cargo1b.p3d",
			"misc_cargo1bo.p3d",
			"misc_cargo2c.p3d",
			"misc_cargo1ao.p3d",
			
			//Tanoa
			"Land_ContainerLine_01_F",
			"Land_ContainerLine_02_F",
			"Land_ContainerLine_03_F",

			// Also allow wrecks
			"wreck_"
/*			
			"wreck_bmp2_f.p3d",
			"wreck_brdm2_f.p3d",
			"wreck_car2_f.p3d",
			"wreck_car3_f.p3d",
			"wreck_car_f.p3d",
			"wreck_cardismantled_f.p3d",
			"wreck_hmmwv_f.p3d",
			"wreck_hunter_f.p3d",
			"wreck_offroad2_f.p3d",
			"wreck_offroad_f.p3d",
			"wreck_skodovka_f.p3d",
			"wreck_slammer_f.p3d",
			"wreck_slammer_hull_f.p3d",
			"wreck_slammer_turret_f.p3d",
			"wreck_t72_hull_f.p3d",
			"wreck_t72_turret_f.p3d",
			"wreck_truck_dropside_f.p3d",
			"wreck_truck_f.p3d",
			"wreck_uaz_f.p3d",
			"wreck_ural_f.p3d"
			"wreck_van_f.p3d",
			*/


			// TODO: Ask community for CUP/AiA model names	
		};
	};

	class WoodSource
	{
		name = "Trees";
		models[] = 
		{
			" t_",
			" bo_t_",

			// A2 trees
      " str_",
      " Smrk_",
      " les_",
      " brg_",

			// Lythium Trees
			" jbad_t_"
		};
	};

	// TODO: Add https://community.bistudio.com/wikidata/images/thumb/6/60/Arma3_CfgVehicles_Land_Tank_rust_F.jpg/150px-Arma3_CfgVehicles_Land_Tank_rust_F.jpg
	class FuelSource
	{
		name = "Fuel pumps, stations or barrels";
		models[] = 
		{
			"fuelstation_feed_f.p3d",
			"metalbarrel_f.p3d",
			"flexibletank_01_f.p3d",
			"fs_feed_f.p3d",
			//Chernarus - CUP
			"a_fuelstation_feed.p3d",
			"ind_tanksmall.p3d",
			"ind_tanksmall2.p3d",
			"ind_tanksmall2_ep1.p3d",
			"fuel_tank_big.p3d",
			"fuel_tank_stairs.p3d",
			"fuel_tank_small.p3d",
			//Tanoa
			"fuelstation_01_pump_f.p3d",
			"fuelstation_02_pump_f.p3d",
			//Lythium
			"Jbad_Ind_FuelStation_Feed.p3d"
		};	
	};
};
class CfgLocker 
{
	numbersOnly = "0123456789";
	
	maxDeposit = 2000000;
};

class CfgPlayer 
{
	// In minutes ammount of time it takes to go from 100 - 0 if stationary
	hungerDecay = 160;
	thirstDecay = 120;

	// Damage taken from 0 (health||thirst)/sec
	healthDecay = 5.0;

	// Health regen if over BOTH
	thirstRegen = 85;
	hungerRegen = 85;

	// IF above meet recover HP%/MIN
	recoveryPerMinute = 3;

	// Set custom aim precision coefficient for weapon sway
	// https://community.bistudio.com/wiki/Arma_3_Stamina
	// Set to -1 if you want to use Arma 3 default value
	// setCustomAimCoef
	customAimCoefficient = 0.5;

	// 0 or 1
	enableFatigue = 0;
	enableStamina = 0;

	disableMapDrawing = 0;
	
	// Use the current gradient to affect the players movement when autorunning.
	// 0 == default exile auto run
	useGradientAffectedAutoRun = 0;
};

class CfgSlothMachine
{
	spinCost = 100;
	Jackpot = 10100;
	
	chances[] = 
	{
		{85, ""}, 					// 85% = Nothing
		{95, "Level1"}, 			// 10% = 1pt
		{96, "Level2"}, 			// 1% = 10pt
		{97, "Level3"}, 			// 1% = 25pt
		{98, "Level4"}, 			// 1% = 50pt
		{99, "Level5"},				// 1% = 100pt
		{100, "Jackpot"} 			// 1% = Jackpot
	};

	class Prizes 
	{
		class Level1
		{
			symbol = "\exile_assets\texture\item\Exile_Item_ToiletPaper.paa";
			prize = 101;
		};

		class Level2
		{
			symbol = "\exile_assets\texture\item\Exile_Item_CockONut.paa";
			prize = 110;
		};

		class Level3
		{
			symbol = "\exile_assets\texture\item\Exile_Item_Beer.paa";
			prize = 125;
		};

		class Level4
		{
			symbol = "\exile_assets\texture\item\Exile_Item_Knife.paa";
			prize = 150;
		};

		class Level5
		{
			symbol = "\exile_assets\texture\item\Exile_Item_Safe.paa";
			prize = 200;
		};
		
		class Jackpot
		{
			symbol = "\exile_assets\texture\item\Exile_Item_XmasPresent.paa";
		};
	};
};

class CfgTerritories
{
	// Base Cost / Radius
	// Level 1 is allways for Pop Tabs, >= 2 for Respect
	prices[] = 
	{
		// Purchase Price		Radius			# of Objects	# of Safes		# of Boxes		# of Crates		# of Tents		# of MilBox		# of SmallContainer		# of Cargo20S		# of Cargo20G		# of HugeContainer
		{5000,							15,					30,						5,						1,						5,						5,						5,						3,										2,							2,							1									}, // Level 1
		{10000,							30,					60,						7,						2,						5,						5,						5,						3,										2,							2,							1									}, // Level 2 
		{15000,							45,					90,						9,						3,						5,						5,						5,						3,										2,							2,							2									}, // Level 3
		{20000,							60,					120,					11,						4,						5,						5,						5,						3,										2,							2,							2									}, // Level 4
		{25000,							75,					150,					14,						5,						10,						10,						10,						6,										4,							4,							3									}, // Level 5
		{30000,							90,					180,					16,						6,						10,						10,						10,						6,										4,							4,							3									}, // Level 6
		{35000,							105,				210,					18,						7,						10,						10,						10,						6,										4,							4,							4									}, // Level 7
		{40000,							120,				240,					20,						8,						15,						15,						15,						9,										6,							6,							4									}, // Level 8
		{45000,							135,				270,					22,						9,						15,						15,						15,						9,										6,							6,							5									}, // Level 9
		{50000,							150,				300,					25,						10,						15,						15,						15,						9,										6,							6,							5									}  // Level 10
	};

	// A shortcut of the above maximum radius
	maximumRadius = 150;

	// The above * 2 plus coverving the 20m you can move while placing things
	minimumDistanceToOtherTerritories = 325; 

	// Maximum number of territories a player can own
	maximumNumberOfTerritoriesPerPlayer = 1;

	/**
	 * Defines the minimum distance to safe zones / trader cities where players
	 * cannot build territories
	 */
	minimumDistanceToTraderZones = 1000;

	/**
	 * Defines the minimum distance to spawn zones where players
	 * cannot build territories
	 */
	minimumDistanceToSpawnZones = 1000;

	// Amount of pop tabs per object to pay
	popTabAmountPerObject = 10;
};

class CfgTraderCategories
{
	#include "addons\EBM\traders.hpp"
	#include "addons\NIA\traders.hpp"
	#include "addons\COG\traders.hpp"
	#include "addons\TRYK\traders.hpp"
	class Community
	{
		name = "Community Items";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			// Add your items here <3
		};
	};

	class Community2
	{
		name = "Community Items 2";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			"Exile_Item_DuctTape",
			"Exile_Item_LightBulb",
			"Exile_Item_Rope",
			"Exile_Item_CodeLock",
			"Exile_Item_Cheathas",
			"Exile_Item_MountainDupe"
		};
	};

	class Community3
	{
		name = "Community Items 3";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			"Exile_Item_DuctTape",
			"Exile_Item_LightBulb",
			"Exile_Item_Rope",
			"Exile_Item_CodeLock",
			"Exile_Item_Cheathas",
			"Exile_Item_MountainDupe"
		};
	};

	class Community4
	{
		name = "Community Items 4";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			// Add your items here <3
		};
	};

	class Community5
	{
		name = "Community Items 5";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			// Add your items here <3
		};
	};

	class Community6
	{
		name = "Community Items 6";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			// Add your items here <3
		};
	};

	class Community7
	{
		name = "Community Items 7";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			// Add your items here <3
		};
	};

	class Community8
	{
		name = "Community Items 8";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			// Add your items here <3
		};
	};

	class Community9
	{
		name = "Community Items 9";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			// Add your items here <3
		};
	};

	class Community10
	{
		name = "Community Items 10";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			// Add your items here <3
		};
	};

	class GoalUniforms
	{
		name = "Donation Goal Uniforms";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			"U_O_V_Soldier_Viper_F",
			"U_O_V_Soldier_Viper_hex_F",
			"U_C_Driver_1",
			"U_C_Driver_2",
			"U_C_Driver_3",
			"U_C_Driver_4",
			"U_C_Driver_1_black",
			"U_C_Driver_1_blue",
			"U_C_Driver_1_green",
			"U_C_Driver_1_red",
			"U_C_Driver_1_white",
			"U_C_Driver_1_yellow",
			"U_C_Driver_1_orange",
			"Exile_Uniform_ExileCustoms",
			"U_C_WorkerCoveralls",
			"U_C_Scientist"
		};
	};

	class GoalHeadgear
	{
		name = "Donation Goal Headgear";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\headgear_ca.paa";
		items[] = 
		{
			"Exile_Headgear_SantaHat",
			"Exile_Headgear_SafetyHelmet",
			"H_RacingHelmet_1_F",
			"H_RacingHelmet_2_F",
			"H_RacingHelmet_3_F",
			"H_RacingHelmet_4_F",
			"H_RacingHelmet_1_black_F",
			"H_RacingHelmet_1_blue_F",
			"H_RacingHelmet_1_green_F",
			"H_RacingHelmet_1_red_F",
			"H_RacingHelmet_1_white_F",
			"H_RacingHelmet_1_yellow_F",
			"H_RacingHelmet_1_orange_F"
		};
	};

	class GoalGoggles
	{
		name = "Donation Goal Thermal Headgear";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"H_HelmetO_ViperSP_ghex_F",
			"H_HelmetO_ViperSP_hex_F",
			"NVGogglesB_blk_F",
			"NVGogglesB_grn_F",
			"NVGogglesB_gry_F"
		};
	};

	class GoalOptics
	{
		name = "Donation Goal Thermal Optics";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemoptic_ca.paa";
		items[] = 
		{
			"optic_tws",
			"optic_tws_mg",
			"CUP_optic_GOSHAWK",
			"hlc_optic_goshawk",
			"CUP_optic_AN_PAS_13c1",
			"CUP_optic_AN_PAS_13c2",
			"CUP_optic_CWS"
		};
	};

	class GoalWeapons
	{
		name = "Donation Goal Weapons";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"CUP_glaunch_M32",
			"HLC_wp_M134Painless"
		};
	};

	class GoalAmmo
	{
		name = "Donation Goal Ammo";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"CUP_6Rnd_HE_M203",
			"CUP_6Rnd_FlareWhite_M203",
			"CUP_6Rnd_FlareGreen_M203",
			"CUP_6Rnd_FlareRed_M203",
			"CUP_6Rnd_FlareYellow_M203",
			"CUP_6Rnd_Smoke_M203",
			"CUP_6Rnd_SmokeRed_M203",
			"CUP_6Rnd_SmokeGreen_M203",
			"CUP_6Rnd_SmokeYellow_M203",
			"hlc_500rnd_762x51_Belt"
		};
	};

	class GoalLaunchers
	{
		name = "Donation Goal Launchers";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"CUP_launch_Javelin",
			"launch_O_Titan_short_ghex_F",
			"launch_B_Titan_short_F",
			"launch_I_Titan_short_F"
		};
	};

	class GoalRockets
	{
		name = "Donation Goal Rockets";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"CUP_Javelin_M",
			"Titan_AT"
		};
	};

	class GoalConstruction
	{
		name = "Donation Goal Base Materials";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Exile_Item_MetalHedgehogKit",
			"Exile_Item_ConcreteDoorwayKit",
			"Exile_Item_ConcreteDoorKit",
			"Exile_Item_ConcreteFloorKit",
			"Exile_Item_ConcreteFloorPortKit",
			"Exile_Item_ConcreteGateKit",
			"Exile_Item_ConcreteStairsKit",
			"Exile_Item_ConcreteSupportKit",
			"Exile_Item_ConcreteWallKit",
			"Exile_Item_ConcreteWindowKit",
			"Exile_Item_RepairKitConcrete",
			"Exile_Item_WoodDrawBridgeKit",
			"Exile_Item_WoodFloorPortSmallKit",
			"Exile_Item_WoodLadderKit",
			"Exile_Item_WoodDoorwayKit",
			"Exile_Item_WoodDoorKit",
			"Exile_Item_WoodFloorKit",
			"Exile_Item_WoodFloorPortKit",
			"Exile_Item_WoodGateKit",
			"Exile_Item_WoodStairsKit",
			"Exile_Item_WoodSupportKit",
			"Exile_Item_WoodWallHalfKit",
			"Exile_Item_WoodWallKit",
			"Exile_Item_WoodWindowKit",
			"Exile_Item_RepairKitWood",
			"Exile_Item_FortificationUpgrade"
		};
	};

	class GoalEBM
	{
		name = "Donation Goal EBM Buildings";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Land_i_Barracks_V1_F_Kit",
			"Land_Airport_Tower_F_Kit",
			"Land_Dome_Big_F_Kit",
			"Land_Hangar_F_Kit",
			"Land_i_Addon_03_V1_F_Kit",
			"Land_i_Addon_03mid_V1_F_Kit",
			"Land_TentHangar_V1_F_Kit",
			"Land_i_Garage_V2_F_Kit",
			"Land_Cargo_Tower_V2_F_Kit",
			"Land_Bunker_F_Kit",
			"Exile_ConcreteMixer_Kit",
			"Land_Airport_01_hangar_F_Kit"
		};
	};

	class GoalVehicles
	{
		name = "Donation Goal Vehicles";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"CUP_C_Golf4_kitty_Civ",
			"O_MBT_02_cannon_F",
			"O_T_MBT_02_cannon_ghex_F",
			"CUP_I_T55_TK_GUE",
			"CUP_O_T55_TK",
			"CUP_O_T55_SLA",
			"CUP_O_T55_CSAT",
			"CUP_O_T55_CSAT_T",
			"CUP_O_T72_CSAT",
			"CUP_O_T72_CSAT_T",
			"CUP_B_T72_CDF",
			"CUP_O_T72_RU",
			"CUP_I_T72_RACS",
			"CUP_I_T72_NAPA",
			"CUP_O_2S6M_RU",
			"CUP_B_M1A2_TUSK_MG_USMC",
			"CUP_B_M1A2_TUSK_MG_DES_USMC",
			"O_APC_Tracked_02_cannon_F",
			"O_T_APC_Tracked_02_cannon_ghex_F",
			"I_APC_Wheeled_03_cannon_F",
			"I_APC_tracked_03_cannon_F",
			"CUP_B_M1128_MGS_Desert",
			"CUP_B_M1128_MGS_Desert_Slat",
			"CUP_B_M1128_MGS_Woodland",
			"CUP_B_M1128_MGS_Woodland_Slat",
			"O_APC_Tracked_02_AA_F",
			"O_T_APC_Tracked_02_AA_ghex_F",
			"I_MBT_03_cannon_F",
			"B_MBT_01_TUSK_F",
			"B_APC_Tracked_01_rcws_F",
			"B_APC_Tracked_01_CRV_F",
			"B_MBT_01_arty_F",
			"O_MBT_02_arty_F",
			"O_T_MBT_02_arty_ghex_F",
			"CUP_B_M163_USA",
			"CUP_I_M163_AAF",
			"CUP_I_M163_RACS",
			"CUP_B_M6LineBacker_USA_D",
			"CUP_B_M6LineBacker_USA_W",
			"CUP_B_M6LineBacker_NATO_T",
			"CUP_B_HMMWV_Avenger_USA",
			"CUP_B_HMMWV_Avenger_USMC",
			"CUP_B_HMMWV_TOW_USA",
			"CUP_B_HMMWV_TOW_USMC",
			"CUP_B_HMMWV_AGS_GPK_ACR",
			"CUP_B_Mastiff_GMG_GB_D",
			"CUP_B_Mastiff_GMG_GB_W",
			"CUP_B_Ridgback_GMG_GB_D",
			"CUP_B_Ridgback_GMG_GB_W",
			"CUP_B_Wolfhound_GMG_GB_D",
			"CUP_B_Wolfhound_GMG_GB_W",
			"COG_BLCK_Hunter_GMG",
			"COG_CPK1_Hunter_GMG",
			"COG_CPK2_Hunter_GMG",
			"COG_GHEX_Hunter_GMG",
			"COG_ODRB_Hunter_GMG",
			"COG_ORNG_Hunter_GMG",
			"COG_BLCK_Strider_GMG",
			"COG_CPK1_Strider_GMG",
			"COG_CPK2_Strider_GMG",
			"COG_GHEX_Strider_GMG",
			"COG_ODRB_Strider_GMG",
			"COG_ORNG_Strider_GMG",
			"COG_BLCK_Ifrit_GMG",
			"COG_CPK1_Ifrit_GMG",
			"COG_CPK2_Ifrit_GMG",
			"COG_GHEX_Ifrit_GMG",
			"COG_ODRB_Ifrit_GMG",
			"COG_ORNG_Ifrit_GMG"
		};
	};

	class GoalAircraft
	{
		name = "Donation Goal Aircraft";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"O_Heli_Attack_02_F",
			"O_Heli_Attack_02_black_F",
			"B_Heli_Attack_01_F",
			"CUP_B_UH1Y_GUNSHIP_USMC",
			"CUP_B_AH1Z_NoWeapons_USMC",
			"CUP_B_AH1Z_USMC",
			"CUP_B_AH1Z_AT_USMC",
			"CUP_B_AH1Z_Escort_USMC",
			"CUP_B_F35B_AA_USMC",
			"CUP_B_F35B_AA_BAF",
			"CUP_B_AV8B_CAP_USMC",
			"CUP_I_AV8B_CAP_AAF",
			"CUP_B_AW159_RN_Blackcat",
			"CUP_B_AW159_RN_Grey",
			"CUP_I_Wildcat_Digital_AAF",
			"CUP_I_Wildcat_Green_AAF",
			"CUP_O_Mi8_SLA_2",
			"CUP_O_Mi8_RU",
			"O_T_VTOL_02_infantry_hex_F",
			"O_T_VTOL_02_infantry_ghex_F",
			"O_T_VTOL_02_infantry_grey_F",
			"O_T_VTOL_02_vehicle_hex_F",
			"O_T_VTOL_02_vehicle_ghex_F",
			"O_T_VTOL_02_vehicle_grey_F",
			//"B_Plane_Fighter_01_F",
			//"B_Plane_Fighter_01_Stealth_F",
			//"O_Plane_Fighter_02_F",
			//"O_Plane_Fighter_02_Stealth_F",
			//"I_Plane_Fighter_04_F",
			"B_Plane_CAS_01_F",
			"CUP_B_A10_AT_USA",
			"CUP_B_A10_CAS_USA",
			"CUP_B_AH64D_USA",
			"CUP_B_AH64D_AT_USA",
			"CUP_B_AH64D_ES_USA",
			"CUP_B_AH64D_LB_USA",
			"CUP_B_AH64D_MR_USA"
		};
	};

	class GoalDrones
	{
		name = "Donation Goal Drones";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\gps_ca.paa";
		items[] =
		{
			"CUP_B_USMC_MQ9",					// MQ-9 Reaper (BLUFOR)
			"B_UAV_02_F",							// MQ-4A Greyhawk (BLUFOR)
			"B_UAV_02_CAS_F",					// MQ-4A Greyhawk (CAS) (BLUFOR)
			"I_UAV_02_F",							// K40 Ababil-3 (IND)
			"I_UAV_02_CAS_F",					// K40 Ababil-3 (CAS) (IND)
			"O_UAV_02_F",							// K40 Ababil-3 (OPFOR)
			"O_UAV_02_CAS_F",					// K40 Ababil-3 (CAS) (OPFOR)
			"B_T_UAV_03_F",						// MQ-12 Falcon (CAS) (BLUFOR)
			"O_T_UAV_04_CAS_F",				// KH-3A Fenghuang
			"B_UAV_05_F"							// UCAV Sentinel (BLUFOR)
		};
	};

	class GoalUGVs
	{
		name = "Donation Goal UGVs";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\gps_ca.paa";
		items[] =
		{
			"B_UGV_01_rcws_F",							// Stomper RCWS (BLUFOR)
			"I_UGV_01_rcws_F",							// Stomper RCWS (IND)
			"O_UGV_01_rcws_F",							// Saif RCWS (OPFOR)
			"O_T_UGV_01_rcws_ghex_F"				// Saif RCWS GHEX (OPFOR)
		};
	};

	class OrangeDLCUniforms
	{
		name = "Orange DLC Uniforms";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			"U_C_IDAP_Man_cargo_F",
			"U_C_IDAP_Man_jeans_F",
			"U_C_IDAP_Man_Casual_F",
			"U_C_IDAP_Man_shorts_F",
			"U_C_IDAP_Man_tee_F",
			"U_C_IDAP_Man_teeshorts_F",
			"U_C_ConstructionCoverall_Black_F",
			"U_C_ConstructionCoverall_Blue_F",
			"U_C_ConstructionCoverall_Red_F",
			"U_C_ConstructionCoverall_Vrana_F",
			"U_BG_Guerilla1_2_F",
			"U_C_Mechanic_01_F",
			"U_C_Paramedic_01_F"
		};
	};

	class OrangeDLCVests
	{
		name = "Orange DLC Vests";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\vest_ca.paa";
		items[] =
		{
			"V_EOD_blue_F",
			"V_EOD_IDAP_blue_F",
			"V_EOD_coyote_F",
			"V_EOD_olive_F",
			"V_Plain_crystal_F",
			"V_Plain_medical_F",
			"V_LegStrapBag_black_F",
			"V_LegStrapBag_coyote_F",
			"V_LegStrapBag_olive_F",
			"V_Pocketed_black_F",
			"V_Pocketed_coyote_F",
			"V_Pocketed_olive_F",
			"V_Safety_blue_F",
			"V_Safety_orange_F",
			"V_Safety_yellow_F"
		};
	};

	class OrangeDLCHeadgear
	{
		name = "Orange DLC Headgear";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\headgear_ca.paa";
		items[] =
		{
			"H_Cap_Black_IDAP_F",
			"H_Cap_Orange_IDAP_F",
			"H_Cap_White_IDAP_F",
			"H_Construction_basic_black_F",
			"H_Construction_earprot_black_F",
			"H_Construction_headset_black_F",
			"H_Construction_basic_orange_F",
			"H_Construction_earprot_orange_F",
			"H_Construction_headset_orange_F",
			"H_Construction_basic_red_F",
			"H_Construction_earprot_red_F",
			"H_Construction_headset_red_F",
			"H_Construction_basic_vrana_F",
			"H_Construction_earprot_vrana_F",
			"H_Construction_headset_vrana_F",
			"H_Construction_basic_white_F",
			"H_Construction_earprot_white_F",
			"H_Construction_headset_white_F",
			"H_Construction_basic_yellow_F",
			"H_Construction_earprot_yellow_F",
			"H_Construction_headset_yellow_F",
			"H_Hat_Safari_olive_F",
			"H_Hat_Safari_sand_F",
			"H_PASGT_basic_blue_F",
			"H_PASGT_basic_olive_F",
			"H_PASGT_basic_white_F",
			"H_PASGT_basic_blue_press_F",
			"H_PASGT_neckprot_blue_press_F"
		};
	};
	
	class OrangeDLCFacewear
	{
		name = "Orange DLC Facewear";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\Goggles_ca.paa";
		items[] =
		{
			"G_Respirator_blue_F",
			"G_Respirator_white_F",
			"G_Respirator_yellow_F",
			"G_EyeProtectors_F",
			"G_EyeProtectors_Earpiece_F",
			"G_WirelessEarpiece_F"
		};
	};
	
	class OrangeDLCBackpacks
	{
		name = "Orange DLC Backpacks";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\backpack_ca.paa";
		items[] =
		{
			"B_LegStrapBag_black_F",
			"B_LegStrapBag_coyote_F",
			"B_LegStrapBag_olive_F",
			"B_Messenger_Black_F",
			"B_Messenger_Coyote_F",
			"B_Messenger_Gray_F",
			"B_Messenger_Olive_F",
			"B_Messenger_IDAP_F"
		};
	};

	class OrangeDLCCars
	{
		name = "Orange DLC Cars";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"B_G_Van_02_vehicle_F",
			"I_G_Van_02_vehicle_F",
			"I_G_Van_02_transport_F",
			"I_C_Van_02_vehicle_F",
			"I_C_Van_02_transport_F",
			"C_Van_02_medevac_F",
			"C_Van_02_service_F",
			"C_IDAP_Van_02_medevac_F",
			"C_IDAP_Offroad_02_unarmed_F",
			"C_IDAP_Offroad_01_F"
		};
	};

	class OrangeDLCTrucks
	{
		name = "Orange DLC Trucks";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"C_IDAP_Truck_02_transport_F",
			"C_IDAP_Truck_02_F"
		};
	};

	class OrangeDLCChoppers
	{
		name = "Orange DLC Helicopters";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"C_IDAP_Heli_Transport_02_F"
		};
	};

	class OrangeDLCUAVs
	{
		name = "Orange DLC UAVs";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\gps_ca.paa";
		items[] =
		{
			"B_UAV_06_medical_backpack_F",
			"B_UAV_06_backpack_F",
			"O_UAV_06_medical_backpack_F",
			"O_UAV_06_backpack_F",
			"I_UAV_06_medical_backpack_F",
			"I_UAV_06_backpack_F",
			"C_IDAP_UAV_06_medical_backpack_F",
			"C_IDAP_UAV_06_backpack_F",
			"C_UAV_06_medical_backpack_F",
			"C_UAV_06_backpack_F"
		};
	};

	class Uniforms
	{
		name = "Uniforms";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] =
		{
			"U_C_Journalist",
			"U_C_Poloshirt_blue",
			"U_C_Poloshirt_burgundy",
			"U_C_Poloshirt_salmon",
			"U_C_Poloshirt_stripped",
			"U_C_Poloshirt_tricolour",
			"U_C_Poor_1",
			"U_C_Poor_2",
			"U_C_Poor_shorts_1",
			"U_OrestesBody",
			"U_Rangemaster",
			"U_NikosAgedBody",
			"U_NikosBody",
			"U_Competitor",
			"U_B_CombatUniform_mcam",
			"U_B_CombatUniform_mcam_tshirt",
			"U_B_CombatUniform_mcam_vest",
			"U_B_CombatUniform_mcam_worn",
			"U_B_CTRG_1",
			"U_B_CTRG_2",
			"U_B_CTRG_3",
			"U_I_CombatUniform",
			"U_I_CombatUniform_shortsleeve",
			"U_I_CombatUniform_tshirt",
			"U_I_OfficerUniform",
			"U_O_CombatUniform_ocamo",
			"U_O_CombatUniform_oucamo",
			"U_O_OfficerUniform_ocamo",
			"U_B_SpecopsUniform_sgg",
			"U_O_SpecopsUniform_blk",
			"U_O_SpecopsUniform_ocamo",
			"U_I_G_Story_Protagonist_F",
			"Exile_Uniform_Woodland",
			"U_C_HunterBody_grn",
			"U_IG_Guerilla1_1",
			"U_IG_Guerilla2_1",
			"U_IG_Guerilla2_2",
			"U_IG_Guerilla2_3",
			"U_IG_Guerilla3_1",
			"U_BG_Guerilla2_1",
			"U_IG_Guerilla3_2",
			"U_BG_Guerrilla_6_1",
			"U_BG_Guerilla1_1",
			"U_BG_Guerilla2_2",
			"U_BG_Guerilla2_3",
			"U_BG_Guerilla3_1",
			"U_BG_leader",
			"U_IG_leader",
			"U_I_G_resistanceLeader_F",
			"U_B_FullGhillie_lsh",
			"U_I_FullGhillie_lsh",
			"U_O_FullGhillie_lsh",
			"U_B_FullGhillie_sard",
			"U_I_FullGhillie_sard",
			"U_O_FullGhillie_sard",
			"U_B_FullGhillie_ard",
			"U_I_FullGhillie_ard",
			"U_O_FullGhillie_ard",
			"U_B_GhillieSuit",
			"U_I_GhillieSuit",
			"U_O_GhillieSuit",
			"U_I_Wetsuit",
			"U_O_Wetsuit",
			"U_B_Wetsuit",
			"U_I_Protagonist_VR",
			"U_O_Protagonist_VR",
			"U_B_Protagonist_VR",
			"U_B_survival_uniform",
			"U_B_HeliPilotCoveralls",
			"U_I_HeliPilotCoveralls",
			"U_B_PilotCoveralls",
			"U_I_pilotCoveralls",
			"U_O_PilotCoveralls",
			//Apex
			"U_B_T_Soldier_F",
			"U_B_T_Soldier_AR_F",
			"U_B_T_Soldier_SL_F",
			"U_B_T_Sniper_F",
			"U_O_T_Sniper_F",
			"U_B_T_FullGhillie_tna_F",
			"U_O_T_FullGhillie_tna_F",
			"U_B_CTRG_Soldier_F",
			"U_B_CTRG_Soldier_2_F",
			"U_B_CTRG_Soldier_3_F",
			"U_B_GEN_Soldier_F",
			"U_B_GEN_Commander_F",
			"U_O_T_Soldier_F",
			"U_O_T_Officer_F",
			"U_I_C_Soldier_Para_1_F",
			"U_I_C_Soldier_Para_2_F",
			"U_I_C_Soldier_Para_3_F",
			"U_I_C_Soldier_Para_4_F",
			"U_I_C_Soldier_Para_5_F",
			"U_I_C_Soldier_Bandit_1_F",
			"U_I_C_Soldier_Bandit_2_F",
			"U_I_C_Soldier_Bandit_3_F",
			"U_I_C_Soldier_Bandit_4_F",
			"U_I_C_Soldier_Bandit_5_F",
			"U_I_C_Soldier_Camo_F",
			"U_C_man_sport_1_F",
			"U_C_man_sport_2_F",
			"U_C_man_sport_3_F",
			"U_C_Man_casual_1_F",
			"U_C_Man_casual_2_F",
			"U_C_Man_casual_3_F",
			"U_C_Man_casual_4_F",
			"U_C_Man_casual_5_F",
			"U_C_Man_casual_6_F",
			"U_B_CTRG_Soldier_urb_1_F",
			"U_B_CTRG_Soldier_urb_2_F",
			"U_B_CTRG_Soldier_urb_3_F"
		};
	};

	class Vests
	{
		name = "Vests";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\vest_ca.paa";
		items[] =
		{
			"V_Press_F",
			"V_Rangemaster_belt",
			"V_TacVest_blk",
			"V_TacVest_blk_POLICE",
			"V_TacVest_brn",
			"V_TacVest_camo",
			"V_TacVest_khk",
			"V_TacVest_oli",
			"V_TacVestCamo_khk",
			"V_TacVestIR_blk",
			"V_I_G_resistanceLeader_F",
			"V_BandollierB_blk",
			"V_BandollierB_cbr",
			"V_BandollierB_khk",
			"V_BandollierB_oli",
			"V_BandollierB_rgr",
			"V_Chestrig_blk",
			"V_Chestrig_khk",
			"V_Chestrig_oli",
			"V_Chestrig_rgr",
			"V_HarnessO_brn",
			"V_HarnessO_gry",
			"V_HarnessOGL_brn",
			"V_HarnessOGL_gry",
			"V_HarnessOSpec_brn",
			"V_HarnessOSpec_gry",
			"V_PlateCarrier1_blk",
			"V_PlateCarrier1_rgr",
			"V_PlateCarrier2_rgr",
			"V_PlateCarrier3_rgr",
			"V_PlateCarrierGL_blk",
			"V_PlateCarrierGL_mtp",
			"V_PlateCarrierGL_rgr",
			"V_PlateCarrierH_CTRG",
			"V_PlateCarrierIA1_dgtl",
			"V_PlateCarrierIA2_dgtl",
			"V_PlateCarrierIAGL_dgtl",
			"V_PlateCarrierIAGL_oli",
			"V_PlateCarrierL_CTRG",
			"V_PlateCarrierSpec_blk",
			"V_PlateCarrierSpec_mtp",
			"V_PlateCarrierSpec_rgr",
			//Apex
			"V_TacChestrig_grn_F",
			"V_TacChestrig_oli_F",
			"V_TacChestrig_cbr_F",
			"V_PlateCarrier1_tna_F",
			"V_PlateCarrier2_tna_F",
			"V_PlateCarrierSpec_tna_F",
			"V_PlateCarrierGL_tna_F",
			"V_HarnessO_ghex_F",
			"V_HarnessOGL_ghex_F",
			"V_BandollierB_ghex_F",
			"V_TacVest_gen_F",
			"V_PlateCarrier1_rgr_noflag_F",
			"V_PlateCarrier2_rgr_noflag_F",
			// Jets
			"V_DeckCrew_yellow_F",
			"V_DeckCrew_blue_F",
			"V_DeckCrew_green_F",
			"V_DeckCrew_red_F",
			"V_DeckCrew_white_F",
			"V_DeckCrew_brown_F",
			"V_DeckCrew_violet_F"
		};
	};

	class Headgear
	{
		name = "Headgear";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\headgear_ca.paa";
		items[] =
		{
			"H_Cap_blk",
			"H_Cap_blk_Raven",
			"H_Cap_blu",
			"H_Cap_brn_SPECOPS",
			"H_Cap_grn",
			"H_Cap_headphones",
			"H_Cap_khaki_specops_UK",
			"H_Cap_oli",
			"H_Cap_press",
			"H_Cap_red",
			"H_Cap_tan",
			"H_Cap_tan_specops_US",
			"H_Watchcap_blk",
			"H_Watchcap_camo",
			"H_Watchcap_khk",
			"H_Watchcap_sgg",
			"H_MilCap_blue",
			"H_MilCap_dgtl",
			"H_MilCap_mcamo",
			"H_MilCap_ocamo",
			"H_MilCap_oucamo",
			"H_MilCap_rucamo",
			"H_Bandanna_camo",
			"H_Bandanna_cbr",
			"H_Bandanna_gry",
			"H_Bandanna_khk",
			"H_Bandanna_khk_hs",
			"H_Bandanna_mcamo",
			"H_Bandanna_sgg",
			"H_Bandanna_surfer",
			"H_Booniehat_dgtl",
			"H_Booniehat_dirty",
			"H_Booniehat_grn",
			"H_Booniehat_indp",
			"H_Booniehat_khk",
			"H_Booniehat_khk_hs",
			"H_Booniehat_mcamo",
			"H_Booniehat_tan",
			"H_Hat_blue",
			"H_Hat_brown",
			"H_Hat_camo",
			"H_Hat_checker",
			"H_Hat_grey",
			"H_Hat_tan",
			"H_StrawHat",
			"H_StrawHat_dark",
			"H_Beret_02",
			"H_Beret_blk",
			"H_Beret_blk_POLICE",
			"H_Beret_brn_SF",
			"H_Beret_Colonel",
			"H_Beret_grn",
			"H_Beret_grn_SF",
			"H_Beret_ocamo",
			"H_Beret_red",
			"H_Shemag_khk",
			"H_Shemag_olive",
			"H_Shemag_olive_hs",
			"H_Shemag_tan",
			"H_ShemagOpen_khk",
			"H_ShemagOpen_tan",
			"H_TurbanO_blk",
			"H_HelmetB",
			"H_HelmetB_black",
			"H_HelmetB_camo",
			"H_HelmetB_desert",
			"H_HelmetB_grass",
			"H_HelmetB_light",
			"H_HelmetB_light_black",
			"H_HelmetB_light_desert",
			"H_HelmetB_light_grass",
			"H_HelmetB_light_sand",
			"H_HelmetB_light_snakeskin",
			"H_HelmetB_paint",
			"H_HelmetB_plain_blk",
			"H_HelmetB_sand",
			"H_HelmetB_snakeskin",
			"H_HelmetCrew_B",
			"H_HelmetCrew_I",
			"H_HelmetCrew_O",
			"H_HelmetIA",
			"H_HelmetIA_camo",
			"H_HelmetIA_net",
			"H_HelmetLeaderO_ocamo",
			"H_HelmetLeaderO_oucamo",
			"H_HelmetO_ocamo",
			"H_HelmetO_oucamo",
			"H_HelmetSpecB",
			"H_HelmetSpecB_blk",
			"H_HelmetSpecB_paint1",
			"H_HelmetSpecB_paint2",
			"H_HelmetSpecO_blk",
			"H_HelmetSpecO_ocamo",
			"H_CrewHelmetHeli_B",
			"H_CrewHelmetHeli_I",
			"H_CrewHelmetHeli_O",
			"H_HelmetCrew_I",
			"H_HelmetCrew_B",
			"H_HelmetCrew_O",
			"H_PilotHelmetHeli_B",
			"H_PilotHelmetHeli_I",
			"H_PilotHelmetHeli_O",
			"H_PilotHelmetFighter_B",
			"H_PilotHelmetFighter_I",
			"H_PilotHelmetFighter_O",
			//Apex
			"H_Helmet_Skate",
			"H_HelmetB_TI_tna_F",
			"H_HelmetB_tna_F",
			"H_HelmetB_Enh_tna_F",
			"H_HelmetB_Light_tna_F",
			"H_HelmetSpecO_ghex_F",
			"H_HelmetLeaderO_ghex_F",
			"H_HelmetO_ghex_F",
			"H_HelmetCrew_O_ghex_F",
			"H_MilCap_tna_F",
			"H_MilCap_ghex_F",
			"H_Booniehat_tna_F",
			"H_Beret_gen_F",
			"H_MilCap_gen_F",
			"H_Cap_oli_Syndikat_F",
			"H_Cap_tan_Syndikat_F",
			"H_Cap_blk_Syndikat_F",
			"H_Cap_grn_Syndikat_F"
		};
	};

	class Glasses
	{
		name = "Glasses";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\Goggles_ca.paa";
		items[] =
		{
			"G_Spectacles",
			"G_Spectacles_Tinted",
			"G_Combat",
			"G_Lowprofile",
			"G_Shades_Black",
			"G_Shades_Green",
			"G_Shades_Red",
			"G_Squares",
			"G_Squares_Tinted",
			"G_Sport_BlackWhite",
			"G_Sport_Blackyellow",
			"G_Sport_Greenblack",
			"G_Sport_Checkered",
			"G_Sport_Red",
			"G_Tactical_Black",
			"G_Aviator",
			"G_Lady_Mirror",
			"G_Lady_Dark",
			"G_Lady_Red",
			"G_Lady_Blue",
			"G_Diving",
			"G_B_Diving",
			"G_O_Diving",
			"G_I_Diving",
			"G_Goggles_VR",
			"G_Balaclava_blk",
			"G_Balaclava_oli",
			"G_Balaclava_combat",
			"G_Balaclava_lowprofile",
			"G_Bandanna_blk",
			"G_Bandanna_oli",
			"G_Bandanna_khk",
			"G_Bandanna_tan",
			"G_Bandanna_beast",
			"G_Bandanna_shades",
			"G_Bandanna_sport",
			"G_Bandanna_aviator",
			"G_Shades_Blue",
			"G_Sport_Blackred",
			"G_Tactical_Clear",
			"G_Balaclava_TI_blk_F",
			"G_Balaclava_TI_tna_F",
			"G_Balaclava_TI_G_blk_F",
			"G_Balaclava_TI_G_tna_F",
			"G_Combat_Goggles_tna_F"
		};
	};

	class PointerAttachments
	{
		name = "Pointer Attachments";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"acc_flashlight",
			"acc_pointer_IR"
		};
	};

	class BipodAttachments
	{
		name = "Bipod Attachments";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itembipod_ca.paa";
		items[] =
		{
			"bipod_01_F_blk",
			"bipod_01_F_mtp",
			"bipod_01_F_snd",
			"bipod_02_F_blk",
			"bipod_02_F_hex",
			"bipod_02_F_tan",
			"bipod_03_F_blk",
			"bipod_03_F_oli",
			//Apex
			"bipod_01_F_khk"
		};
	};

	class MuzzleAttachments
	{
		name = "Suppressor Attachments";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemmuzzle_ca.paa";
		items[] =
		{
			"muzzle_snds_338_black",
			"muzzle_snds_338_green",
			"muzzle_snds_338_sand",
			"muzzle_snds_93mmg",
			"muzzle_snds_93mmg_tan",
			"muzzle_snds_acp",
			"muzzle_snds_B",
			"muzzle_snds_H",
			"muzzle_snds_H_MG",
			"muzzle_snds_H_SW",
			"muzzle_snds_L",
			"muzzle_snds_M",
			//CUP
			"CUP_muzzle_PBS4",
			"CUP_muzzle_PB6P9",
			"CUP_muzzle_Bizon",
			"CUP_muzzle_snds_M110",
			"CUP_muzzle_snds_M14",
			"CUP_muzzle_snds_M9",
			"CUP_muzzle_snds_MicroUzi",
			"CUP_muzzle_snds_AWM",
			"CUP_muzzle_snds_G36_black",
			"CUP_muzzle_snds_G36_desert",
			"CUP_muzzle_snds_L85",
			"CUP_muzzle_snds_M16_camo",
			"CUP_muzzle_snds_M16",
			"CUP_muzzle_snds_SCAR_L",
			"CUP_muzzle_mfsup_SCAR_L",
			"CUP_muzzle_snds_SCAR_H",
			"CUP_muzzle_mfsup_SCAR_H",
			"CUP_muzzle_snds_XM8",
			//Apex
			"muzzle_snds_H_khk_F",
			"muzzle_snds_H_snd_F",
			"muzzle_snds_58_blk_F",
			"muzzle_snds_m_khk_F",
			"muzzle_snds_m_snd_F",
			"muzzle_snds_B_khk_F",
			"muzzle_snds_B_snd_F",
			"muzzle_snds_58_wdm_F",
			"muzzle_snds_65_TI_blk_F",
			"muzzle_snds_65_TI_hex_F",
			"muzzle_snds_65_TI_ghex_F",
			"muzzle_snds_H_MG_blk_F",
			"muzzle_snds_H_MG_khk_F"
		};
	};

	class Drones
	{
		name = "Unmanned Aerial Vehicles";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\gps_ca.paa";
		items[] =
		{
			"CUP_B_AH6X_USA",					// Unmanned Littlebird (BLUFOR)
			"CUP_B_Pchela1T_CDF",			// Pchela1T (CDF) (BLUFOR)
			"CUP_O_Pchela1T_RU"				// Pchela1T (RU) (OPFOR)
		};
	};

	class UAVs
	{
		name = "Unmanned Aerial Vehicles";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\gps_ca.paa";
		items[] =
		{
			"I_UavTerminal",
			"I_UAV_01_backpack_F",
			"O_UAV_01_backpack_F",
			"B_UAV_01_backpack_F"
		};
	};

	class UGVs
	{
		name = "Unmanned Ground Vehicles";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\gps_ca.paa";
		items[] =
		{
			"B_UGV_01_F",									// Stomper (BLUFOR)
			"I_UGV_01_F",									// Stomper (IND)
			"O_UGV_01_F",									// Saif (OPFOR)
			"O_T_UGV_01_ghex_F"						// Saif GHEX (OPFOR)
		};
	};

	class StaticMGs
	{
		name = "Static Machine Guns";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"I_HMG_01_high_weapon_F",
			"O_HMG_01_high_weapon_F",
			"B_HMG_01_high_weapon_F",
			"I_HMG_01_support_high_F",
			"O_HMG_01_support_high_F",
			"B_HMG_01_support_high_F"
		};
	};

	class StaticMGAmmo
	{
		name = "Static Machine Gun Ammo";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\CargoMag_ca.paa";
		items[] = 
		{
			"500Rnd_127x99_mag_Tracer_Green",
			"500Rnd_127x99_mag_Tracer_Yellow",
			"500Rnd_127x99_mag_Tracer_Red"
		};
	};

	class OpticAttachments
	{
		name = "Scopes";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemoptic_ca.paa";
		items[] =
		{
			"optic_Aco",
			"optic_ACO_grn",
			"optic_ACO_grn_smg",
			"optic_Aco_smg",
			"optic_AMS",
			"optic_AMS_khk",
			"optic_AMS_snd",
			"optic_Arco",
			"optic_DMS",
			"optic_Hamr",
			"optic_Holosight",
			"optic_Holosight_smg",
			"optic_KHS_blk",
			"optic_KHS_hex",
			"optic_KHS_old",
			"optic_KHS_tan",
			"optic_LRPS",
			"optic_MRCO",
			"optic_MRD",
			"optic_Nightstalker",
			"optic_NVS",
			"optic_SOS",
			"optic_Yorris",
			//CUP
			"CUP_optic_AN_PVS_10",
			"CUP_optic_AN_PVS_4",
			"CUP_optic_NSPU",
			"CUP_optic_PSO_1",
			"CUP_optic_PSO_3",
			"CUP_optic_Kobra",
			"CUP_optic_PechenegScope",
			"CUP_optic_LeupoldMk4",
			"CUP_optic_HoloBlack",
			"CUP_optic_HoloWdl",
			"CUP_optic_HoloDesert",
			"CUP_optic_Eotech533",
			"CUP_optic_CompM4",
			"CUP_optic_SUSAT",
			"CUP_optic_ACOG",
			"CUP_optic_Leupold_VX3",
			"CUP_optic_CompM2_Black",
			"CUP_optic_CompM2_Woodland",
			"CUP_optic_CompM2_Woodland2",
			"CUP_optic_CompM2_Desert",
			"CUP_optic_RCO",
			"CUP_optic_RCO_desert",
			"CUP_optic_LeupoldM3LR",
			"CUP_optic_LeupoldMk4_10x40_LRT_Desert",
			"CUP_optic_LeupoldMk4_10x40_LRT_Woodland",
			"CUP_optic_ElcanM145",
			"CUP_optic_LeupoldMk4_CQ_T",
			"CUP_optic_ELCAN_SpecterDR",
			"CUP_optic_Elcan_reflex",
			"CUP_optic_LeupoldMk4_MRT_tan",
			"CUP_optic_SB_11_4x20_PM",
			"CUP_optic_ZDDot",
			"CUP_optic_MRad",
			"CUP_optic_TrijiconRx01_desert",
			"CUP_optic_TrijiconRx01_black",
			//Apex
			"optic_Arco_blk_F",
			"optic_Arco_ghex_F",
			"optic_DMS_ghex_F",
			"optic_Hamr_khk_F",
			"optic_ERCO_blk_F",
			"optic_ERCO_khk_F",
			"optic_ERCO_snd_F",
			"optic_SOS_khk_F",
			"optic_LRPS_tna_F",
			"optic_LRPS_ghex_F",
			"optic_Holosight_blk_F",
			"optic_Holosight_khk_F",
			"optic_Holosight_smg_blk_F"
		};
	};

	class Hardware
	{
		name = "Hardware";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Exile_Item_DuctTape",
			"Exile_Item_ExtensionCord",
			"Exile_Item_FuelCanisterEmpty",
			"Exile_Item_WaterCanisterEmpty",
			"Exile_Item_JunkMetal",
			"Exile_Item_LightBulb",
			"Exile_Item_MetalBoard",
			"Exile_Item_MetalPole",
			"Exile_Item_SafeKit",
			"Exile_Item_CamoTentKit",
			"Exile_Item_CodeLock",
			"Exile_Item_Rope",
			"Exile_Item_Laptop",
			"Exile_Item_BaseCameraKit",
			"Exile_Item_MetalScrews",
			"Exile_Item_MetalWire",
			"Exile_Item_Cement",
			"Exile_Item_Sand"

			/*
			--Not for Sale--
			"Exile_Item_MetalHedgehogKit",
			"Exile_Item_MobilePhone",
			--Unused--
			"Exile_Item_FireExtinguisher",
			"Exile_Item_OilCanister",
			"Exile_Item_Carwheel",
			"Exile_Item_SleepingMat",
			"Exile_Item_SprayCan_Black",
			"Exile_Item_SprayCan_Red",
			"Exile_Item_SprayCan_Green",
			"Exile_Item_SprayCan_White",
			"Exile_Item_SprayCan_Blue"
		*/
		};
	};

	class Food
	{
		name = "Fast Food";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Exile_Item_EMRE",
			"Exile_Item_GloriousKnakworst",
			"Exile_Item_Surstromming",
			"Exile_Item_SausageGravy",
			"Exile_Item_Catfood",
			"Exile_Item_ChristmasTinner",
			"Exile_Item_BBQSandwich",
			"Exile_Item_MacasCheese",
			"Exile_Item_Dogfood",
			"Exile_Item_BeefParts",
			"Exile_Item_Cheathas",
			"Exile_Item_Noodles",
			"Exile_Item_SeedAstics",
			"Exile_Item_Raisins",
			"Exile_Item_Moobar",
			"Exile_Item_InstantCoffee"
			
			// Hunted Animals
			// Note: Adding these to the trader will defeat the purpose of hunting!
			/*
			"Exile_Item_SheepSteak_Cooked",
			"Exile_Item_AlsatianSteak_Cooked",
			"Exile_Item_CatSharkFilet_Cooked",
			"Exile_Item_FinSteak_Cooked",
			"Exile_Item_GoatSteak_Cooked",
			"Exile_Item_TurtleFilet_Cooked",
			"Exile_Item_TunaFilet_Cooked",
			"Exile_Item_RabbitSteak_Cooked",
			"Exile_Item_ChickenFilet_Cooked",
			"Exile_Item_RoosterFilet_Cooked",
			"Exile_Item_MulletFilet_Cooked",
			"Exile_Item_SalemaFilet_Cooked",
			"Exile_Item_MackerelFilet_Cooked",
			"Exile_Item_OrnateFilet_Cooked",
			"Exile_Item_SnakeFilet_Cooked",
			"Exile_Item_CatSharkFilet_Raw",
			"Exile_Item_TunaFilet_Raw",
			"Exile_Item_AlsatianSteak_Raw",
			"Exile_Item_TurtleFilet_Raw",
			"Exile_Item_SheepSteak_Raw",
			"Exile_Item_FinSteak_Raw",
			"Exile_Item_GoatSteak_Raw",
			"Exile_Item_ChickenFilet_Raw",
			"Exile_Item_RoosterFilet_Raw",
			"Exile_Item_MackerelFilet_Raw",
			"Exile_Item_MulletFilet_Raw",
			"Exile_Item_OrnateFilet_Raw",
			"Exile_Item_RabbitSteak_Raw",
			"Exile_Item_SalemaFilet_Raw",
			"Exile_Item_SnakeFilet_Raw"
			*/
		};
	};
	
	class NonVeganFood
	{
		name = "Non-Vegan Food";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Exile_Item_CatSharkFilet_Raw",
			"Exile_Item_TunaFilet_Raw",
			"Exile_Item_AlsatianSteak_Raw",
			"Exile_Item_TurtleFilet_Raw",
			"Exile_Item_SheepSteak_Raw",
			"Exile_Item_FinSteak_Raw",
			"Exile_Item_GoatSteak_Raw",
			"Exile_Item_ChickenFilet_Raw",
			"Exile_Item_RoosterFilet_Raw",
			"Exile_Item_MackerelFilet_Raw",
			"Exile_Item_MulletFilet_Raw",
			"Exile_Item_OrnateFilet_Raw",
			"Exile_Item_RabbitSteak_Raw",
			"Exile_Item_SalemaFilet_Raw",
			"Exile_Item_SnakeFilet_Raw"
		};
	};
	

	class Drinks
	{
		name = "Drinks";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Exile_Item_PlasticBottleCoffee",
			"Exile_Item_PowerDrink",
			"Exile_Item_PlasticBottleFreshWater",
			"Exile_Item_Beer",
			"Exile_Item_EnergyDrink",
			"Exile_Item_ChocolateMilk",
			"Exile_Item_MountainDupe",
			"Exile_Item_PlasticBottleEmpty"
		};
	};

	class Tools
	{
		name = "Tools";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Exile_Item_Matches",
			"Exile_Item_CookingPot",
			"Exile_Melee_Axe",
			"Exile_Item_Shovel",
			"Exile_Item_CanOpener",
			"Exile_Item_Handsaw",
			"Exile_Item_Pliers",
			"Exile_Item_Screwdriver",
			"Exile_Item_Wrench",
			"Exile_Item_Hammer",
			"Exile_Item_Grinder",
			"Exile_Item_Foolbox",

			/*
			"Exile_Item_CordlessScrewdriver",
			"Exile_Item_FireExtinguisher",
			"Exile_Item_OilCanister",
			"Exile_Item_SleepingMat",
			"Exile_Item_ToiletPaper",
			"Exile_Item_ZipTie",
			"Exile_Item_BurlapSack",
			"Exile_Item_Bullets_556",
			"Exile_Item_Bullets_762",
			"Exile_Item_WeaponParts",
			*/

			"Binocular",
			"Rangefinder",
			"Laserdesignator",
			"Laserdesignator_01_khk_F",
			"Laserdesignator_02",
			"Laserdesignator_02_ghex_F",
			"Laserdesignator_03",
			"NVGoggles",
			"NVGoggles_INDEP",
			"NVGoggles_OPFOR",
			"SAN_Headlamp_v1",
			"SAN_Headlamp_v2",
			"Chemlight_blue",
			"Chemlight_green",
			"Chemlight_red",
			"Chemlight_yellow",
			"ItemGPS",
			"ItemMap",
			"ItemCompass",
			"ItemRadio",
			"ItemWatch",
			"Exile_Item_XM8",

			//Apex
			"O_NVGoggles_hex_F",
			"O_NVGoggles_urb_F",
			"O_NVGoggles_ghex_F",
			"NVGoggles_tna_F"
		};
	};

	class FirstAid
	{
		name = "FirstAid";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"FirstAidKit",
			"Exile_Item_InstaDoc",
			"Exile_Item_Bandage",
			"Exile_Item_Vishpirin",
			"Exile_Item_Heatpack",
			"Exile_Item_Defibrillator"
		};
	};

	class Navigation
	{
		name = "Special Environment";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"B_Parachute",
			"V_RebreatherB",
			"V_RebreatherIA",
			"V_RebreatherIR",
			"Exile_Headgear_GasMask",
			"G_Diving",
			"G_B_Diving",
			"G_O_Diving",
			"G_I_Diving",
			"NVGoggles",
			"NVGoggles_INDEP",
			"NVGoggles_OPFOR",
			"O_NVGoggles_hex_F",
			"O_NVGoggles_urb_F",
			"O_NVGoggles_ghex_F",
			"NVGoggles_tna_F"
		};
	};

	class Backpacks
	{
		name = "Backpacks";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\backpack_ca.paa";
		items[] =
		{
			"B_AssaultPack_blk",
			"B_AssaultPack_cbr",
			"B_AssaultPack_dgtl",
			"B_AssaultPack_khk",
			"B_AssaultPack_mcamo",
			"B_AssaultPack_rgr",
			"B_AssaultPack_sgg",
			"B_Bergen_blk",
			"B_Bergen_mcamo",
			"B_Bergen_rgr",
			"B_Bergen_sgg",
			"B_Carryall_cbr",
			"B_Carryall_khk",
			"B_Carryall_mcamo",
			"B_Carryall_ocamo",
			"B_Carryall_oli",
			"B_Carryall_oucamo",
			"B_FieldPack_blk",
			"B_FieldPack_cbr",
			"B_FieldPack_ocamo",
			"B_FieldPack_oucamo",
			"B_HuntingBackpack",
			"B_Kitbag_cbr",
			"B_Kitbag_mcamo",
			"B_Kitbag_sgg",
			"B_OutdoorPack_blk",
			"B_OutdoorPack_blu",
			"B_OutdoorPack_tan",
			"B_TacticalPack_blk",
			"B_TacticalPack_mcamo",
			"B_TacticalPack_ocamo",
			"B_TacticalPack_oli",
			"B_TacticalPack_rgr",
			//Apex
			"B_Bergen_mcamo_F",
			"B_Bergen_dgtl_F",
			"B_Bergen_hex_F",
			"B_Bergen_tna_F",
			"B_AssaultPack_tna_F",
			"B_Carryall_ghex_F",
			"B_FieldPack_ghex_F",
			"B_ViperHarness_blk_F",
			"B_ViperHarness_ghex_F",
			"B_ViperHarness_hex_F",
			"B_ViperHarness_khk_F",
			"B_ViperHarness_oli_F",
			"B_ViperLightHarness_blk_F",
			"B_ViperLightHarness_ghex_F",
			"B_ViperLightHarness_hex_F",
			"B_ViperLightHarness_khk_F",
			"B_ViperLightHarness_oli_F"
		};
	};

	class Ammunition
	{
		name = "Ammunition";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\CargoMag_ca.paa";
		items[] =
		{
			"100Rnd_65x39_caseless_mag",
			"100Rnd_65x39_caseless_mag_Tracer",
			"10Rnd_127x54_Mag",
			"10Rnd_338_Mag",
			"10Rnd_762x54_Mag",
			"10Rnd_93x64_DMR_05_Mag",
			"11Rnd_45ACP_Mag",
			"130Rnd_338_Mag",		//SPMG
			"150Rnd_762x54_Box",
			"150Rnd_762x54_Box_Tracer",
			"150Rnd_93x64_Mag",		//NAVID
			"16Rnd_9x21_Mag",
			"16Rnd_9x21_red_Mag",
			"16Rnd_9x21_green_Mag",
			"16Rnd_9x21_yellow_Mag",
			"30Rnd_9x21_Mag",
			"30Rnd_9x21_Yellow_Mag",
			"30Rnd_9x21_Green_Mag",
			"30Rnd_9x21_Red_Mag",
			"200Rnd_65x39_cased_Box",
			"200Rnd_65x39_cased_Box_Tracer",
			"20Rnd_556x45_UW_mag",
			"20Rnd_762x51_Mag",
			"30Rnd_45ACP_Mag_SMG_01",
			"30Rnd_45ACP_Mag_SMG_01_tracer_green",
			"30Rnd_45ACP_Mag_SMG_01_Tracer_Red",
			"30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow",
			"30Rnd_556x45_Stanag",
			"30Rnd_556x45_Stanag_Tracer_Green",
			"30Rnd_556x45_Stanag_Tracer_Red",
			"30Rnd_556x45_Stanag_Tracer_Yellow",
			"30Rnd_65x39_caseless_green",
			"30Rnd_65x39_caseless_green_mag_Tracer",
			"30Rnd_65x39_caseless_mag",
			"30Rnd_65x39_caseless_mag_Tracer",
			"5Rnd_127x108_APDS_Mag",
			"5Rnd_127x108_Mag",
			"6Rnd_45ACP_Cylinder",
			"6Rnd_GreenSignal_F",
			"6Rnd_RedSignal_F",
			"7Rnd_408_Mag",
			"9Rnd_45ACP_Mag",
			"Exile_Magazine_30Rnd_762x39_AK",
			"Exile_Magazine_30Rnd_545x39_AK_Green",
			"Exile_Magazine_30Rnd_545x39_AK_Red",
			"Exile_Magazine_30Rnd_545x39_AK_White",
			"Exile_Magazine_30Rnd_545x39_AK_Yellow",
			"Exile_Magazine_45Rnd_545x39_RPK_Green",
			"Exile_Magazine_75Rnd_545x39_RPK_Green",
			"Exile_Magazine_20Rnd_762x51_DMR",
			"Exile_Magazine_20Rnd_762x51_DMR_Yellow",
			"Exile_Magazine_20Rnd_762x51_DMR_Red",
			"Exile_Magazine_20Rnd_762x51_DMR_Green",
			"Exile_Magazine_10Rnd_303",
			"Exile_Magazine_100Rnd_762x54_PK_Green",
			"Exile_Magazine_7Rnd_45ACP",
			"Exile_Magazine_8Rnd_9x18",
			"Exile_Magazine_30Rnd_545x39_AK",
			"Exile_Magazine_6Rnd_45ACP",
			"Exile_Magazine_5Rnd_22LR",
			"Exile_Magazine_10Rnd_762x54",
			"Exile_Magazine_10Rnd_9x39",
			"Exile_Magazine_20Rnd_9x39",
			"Exile_Magazine_8Rnd_74Pellets",
			"Exile_Magazine_8Rnd_74Slug",
			//CUP 
			"CUP_20Rnd_B_AA12_Pellets",
			"CUP_20Rnd_B_AA12_74Slug", 
			"CUP_20Rnd_B_AA12_HE",
			"CUP_8Rnd_B_Beneli_74Slug",
			"CUP_8Rnd_B_Saiga12_74Slug_M",
			"CUP_8Rnd_9x18_Makarov_M",
			"CUP_8Rnd_9x18_MakarovSD_M",
			"CUP_15Rnd_9x19_M9",
			"CUP_18Rnd_9x19_Phantom",
			"CUP_17Rnd_9x19_glock17",
			"CUP_10Rnd_9x19_Compact",
			"CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M",
			"CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
			"CUP_200Rnd_TE4_Red_Tracer_556x45_M249",
			"CUP_200Rnd_TE4_Yellow_Tracer_556x45_M249",
			"CUP_200Rnd_TE1_Red_Tracer_556x45_M249",
			"CUP_100Rnd_TE4_Green_Tracer_556x45_M249",
			"CUP_100Rnd_TE4_Red_Tracer_556x45_M249",
			"CUP_100Rnd_TE4_Yellow_Tracer_556x45_M249",
			"CUP_64Rnd_9x19_Bizon_M",
			"CUP_64Rnd_Green_Tracer_9x19_Bizon_M",
			"CUP_64Rnd_Red_Tracer_9x19_Bizon_M",
			"CUP_64Rnd_White_Tracer_9x19_Bizon_M",
			"CUP_64Rnd_Yellow_Tracer_9x19_Bizon_M",
			"CUP_30Rnd_9x19_EVO",
			"CUP_30Rnd_9x19_UZI",
			"CUP_30Rnd_9x19_MP5",
			"CUP_20Rnd_B_765x17_Ball_M",
			"CUP_5Rnd_127x99_as50_M",
			"CUP_5Rnd_86x70_L115A1",
			"CUP_5Rnd_127x108_KSVK_M",
			"CUP_10Rnd_762x51_CZ750_Tracer",
			"CUP_10Rnd_762x51_CZ750",
			"CUP_5Rnd_762x51_M24",
			"CUP_10Rnd_127x99_m107",
			"CUP_20Rnd_762x51_B_M110",
			"CUP_20Rnd_TE1_Yellow_Tracer_762x51_M110",
			"CUP_20Rnd_TE1_Red_Tracer_762x51_M110",
			"CUP_20Rnd_TE1_Green_Tracer_762x51_M110",
			"CUP_20Rnd_TE1_White_Tracer_762x51_M110",
			"CUP_10Rnd_762x54_SVD_M",
			"CUP_10Rnd_9x39_SP5_VSS_M",
			"CUP_20Rnd_9x39_SP5_VSS_M",
			"CUP_5x_22_LR_17_HMR_M",
			"CUP_30Rnd_545x39_AK_M",
			"CUP_30Rnd_TE1_Green_Tracer_545x39_AK_M",
			"CUP_30Rnd_TE1_Red_Tracer_545x39_AK_M",
			"CUP_30Rnd_TE1_White_Tracer_545x39_AK_M",
			"CUP_30Rnd_TE1_Yellow_Tracer_545x39_AK_M",
			"CUP_75Rnd_TE4_LRT4_Green_Tracer_545x39_RPK_M",
			"CUP_30Rnd_762x39_AK47_M",
			"CUP_30Rnd_556x45_Stanag",
			"CUP_30Rnd_556x45_G36",
			"CUP_30Rnd_TE1_Red_Tracer_556x45_G36",
			"CUP_30Rnd_TE1_Green_Tracer_556x45_G36",
			"CUP_30Rnd_TE1_Yellow_Tracer_556x45_G36",
			"CUP_100Rnd_556x45_BetaCMag",
			"CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag",
			"CUP_100Rnd_TE1_Green_Tracer_556x45_BetaCMag",
			"CUP_100Rnd_TE1_Yellow_Tracer_556x45_BetaCMag",
			"CUP_20Rnd_556x45_Stanag",
			"CUP_20Rnd_762x51_CZ805B",
			"CUP_20Rnd_TE1_Yellow_Tracer_762x51_CZ805B",
			"CUP_20Rnd_TE1_Red_Tracer_762x51_CZ805B",
			"CUP_20Rnd_TE1_Green_Tracer_762x51_CZ805B",
			"CUP_20Rnd_TE1_White_Tracer_762x51_CZ805B",
			"CUP_20Rnd_762x51_DMR",
			"CUP_20Rnd_TE1_Yellow_Tracer_762x51_DMR",
			"CUP_20Rnd_TE1_Red_Tracer_762x51_DMR",
			"CUP_20Rnd_TE1_Green_Tracer_762x51_DMR",
			"CUP_20Rnd_TE1_White_Tracer_762x51_DMR",
			"CUP_20Rnd_762x51_FNFAL_M",
			"CUP_30Rnd_Sa58_M_TracerG",
			"CUP_30Rnd_Sa58_M_TracerR",
			"CUP_30Rnd_Sa58_M_TracerY",
			"CUP_30Rnd_Sa58_M",
			"CUP_20Rnd_762x51_B_SCAR",
			"CUP_20Rnd_TE1_Yellow_Tracer_762x51_SCAR",
			"CUP_20Rnd_TE1_Red_Tracer_762x51_SCAR",
			"CUP_20Rnd_TE1_Green_Tracer_762x51_SCAR",
			"CUP_20Rnd_TE1_White_Tracer_762x51_SCAR",
			//Apex
			"30Rnd_9x21_Mag_SMG_02",
			"30Rnd_9x21_Mag_SMG_02_Tracer_Red",
			"30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
			"30Rnd_9x21_Mag_SMG_02_Tracer_Green",
			"30Rnd_580x42_Mag_F",
			"30Rnd_580x42_Mag_Tracer_F",
			"100Rnd_580x42_Mag_F",
			"100Rnd_580x42_Mag_Tracer_F",
			"20Rnd_650x39_Cased_Mag_F",
			"10Rnd_50BW_Mag_F",
			"150Rnd_556x45_Drum_Mag_F",
			"150Rnd_556x45_Drum_Mag_Tracer_F",
			"30Rnd_762x39_Mag_F",
			"30Rnd_762x39_Mag_Green_F",
			"30Rnd_762x39_Mag_Tracer_F",
			"30Rnd_762x39_Mag_Tracer_Green_F",
			"30Rnd_545x39_Mag_F",
			"30Rnd_545x39_Mag_Green_F",
			"30Rnd_545x39_Mag_Tracer_F",
			"30Rnd_545x39_Mag_Tracer_Green_F",
			"200Rnd_556x45_Box_F",
			"200Rnd_556x45_Box_Red_F",
			"200Rnd_556x45_Box_Tracer_F",
			"200Rnd_556x45_Box_Tracer_Red_F",
			"10Rnd_9x21_Mag",
			"Exile_Magazine_5Rnd_127x108_Bullet_Cam_Mag",
			"Exile_Magazine_5Rnd_127x108_APDS_Bullet_Cam_Mag",
			"Exile_Magazine_10Rnd_93x64_DMR_05_Bullet_Cam_Mag",
			"Exile_Magazine_7Rnd_408_Bullet_Cam_Mag",
			"Exile_Magazine_10Rnd_338_Bullet_Cam_Mag",
			"Exile_Magazine_10Rnd_127x99_m107_Bullet_Cam_Mag",
			"Exile_Magazine_5Rnd_127x108_KSVK_Bullet_Cam_Mag",
			"Exile_Magazine_5Rnd_127x108_APDS_KSVK_Bullet_Cam_Mag",
			"Exile_Magazine_10Rnd_765x17_SA61",
			"Exile_Magazine_20Rnd_765x17_SA61",
			"Exile_Magazine_10Rnd_127x99_m107",
			"Exile_Magazine_5Rnd_127x108_APDS_KSVK",
			"Exile_Magazine_5Rnd_127x108_KSVK"
		};
	};

	class Flares
	{
		name = "Flares";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"FlareGreen_F",
			"FlareRed_F",
			"FlareWhite_F",
			"FlareYellow_F",
			"UGL_FlareGreen_F",
			"UGL_FlareRed_F",
			"UGL_FlareWhite_F",
			"UGL_FlareYellow_F",
			"UGL_FlareCIR_F",
			"3Rnd_UGL_FlareGreen_F",
			"3Rnd_UGL_FlareRed_F",
			"3Rnd_UGL_FlareWhite_F",
			"3Rnd_UGL_FlareYellow_F",
			"3Rnd_UGL_FlareCIR_F",
			"CUP_FlareWhite_M203",
			"CUP_FlareGreen_M203",
			"CUP_FlareRed_M203",
			"CUP_FlareYellow_M203"
		};
	};

	class Smokes
	{
		name = "Smokes";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"SmokeShell",
			"SmokeShellBlue",
			"SmokeShellGreen",
			"SmokeShellOrange",
			"SmokeShellPurple",
			"SmokeShellRed",
			"SmokeShellYellow",
			"1Rnd_Smoke_Grenade_shell",
			"1Rnd_SmokeBlue_Grenade_shell",
			"1Rnd_SmokeGreen_Grenade_shell",
			"1Rnd_SmokeOrange_Grenade_shell",
			"1Rnd_SmokePurple_Grenade_shell",
			"1Rnd_SmokeRed_Grenade_shell",
			"1Rnd_SmokeYellow_Grenade_shell",
			"3Rnd_Smoke_Grenade_shell",
			"3Rnd_SmokeBlue_Grenade_shell",
			"3Rnd_SmokeGreen_Grenade_shell",
			"3Rnd_SmokeOrange_Grenade_shell",
			"3Rnd_SmokePurple_Grenade_shell",
			"3Rnd_SmokeRed_Grenade_shell",
			"3Rnd_SmokeYellow_Grenade_shell",
			"CUP_1Rnd_Smoke_M203",
			"CUP_1Rnd_SmokeRed_M203",
			"CUP_1Rnd_SmokeGreen_M203",
			"CUP_1Rnd_SmokeYellow_M203"
		};
	};

	class Grenades
	{
		name = "Grenades";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\cargothrow_ca.paa";
		items[] = 
		{
			"HandGrenade",
			"MiniGrenade",
			"B_IR_Grenade",
			"O_IR_Grenade",
			"I_IR_Grenade",
			"1Rnd_HE_Grenade_shell",
			"3Rnd_HE_Grenade_shell",
			//CUP
			"CUP_1Rnd_HE_M203",
			"CUP_1Rnd_HEDP_M203"
		};
	};

	class Explosives
	{
		name = "Explosives";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\cargothrow_ca.paa";
		items[] =
		{
			"APERSBoundingMine_Range_Mag",
			"APERSMine_Range_Mag",
			"APERSTripMine_Wire_Mag",
			"ClaymoreDirectionalMine_Remote_Mag",
			"DemoCharge_Remote_Mag",
			"IEDLandBig_Remote_Mag",
			"IEDLandSmall_Remote_Mag",
			"IEDUrbanBig_Remote_Mag",
			"IEDUrbanSmall_Remote_Mag",
			"SatchelCharge_Remote_Mag",
			"SLAMDirectionalMine_Wire_Mag"
		};
	};

	class RocketLaunchers 
	{
		name = "Rocket Launchers";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"launch_B_Titan_F",
			"launch_I_Titan_F",
			"launch_O_Titan_F",
			"launch_RPG32_F",
			"launch_RPG32_ghex_F",
			"CUP_launch_RPG7V",
			"CUP_launch_Metis",
			"CUP_launch_Mk153Mod0",
			"CUP_launch_MAAWS",
			"CUP_launch_NLAW",
			"CUP_Stinger"
		};
	};

	class LauncherOptics
	{
		name = "Rocket Launcher Optics";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"CUP_optic_NSPU_RPG",
			"CUP_optic_PGO7V",
			"CUP_optic_PGO7V2",
			"CUP_optic_PGO7V3",
			"CUP_optic_SMAW_Scope",
			"CUP_optic_MAAWS_Scope"
		};
	};

	class Rockets 
	{
		name = "Rockets";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Titan_AA",
			"RPG32_F",
			"RPG32_HE_F",
			"CUP_PG7V_M",
			"CUP_PG7VM_M",
			"CUP_PG7VL_M",
			"CUP_PG7VR_M",
			"CUP_OG7_M",
			"CUP_TBG7V_M",
			"CUP_AT13_M",
			"CUP_SMAW_HEAA_M",
			"CUP_SMAW_HEDP_M",
			"CUP_MAAWS_HEAT_M",
			"CUP_MAAWS_HEDP_M",
			"CUP_NLAW_M",
			"CUP_Stinger_M"
		};
	};

	class Pistols
	{
		name = "Pistols";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\handgun_ca.paa";
		items[] =
		{
			"hgun_ACPC2_F",
			"hgun_P07_F",
			"hgun_Pistol_heavy_01_F",
			"hgun_Pistol_heavy_02_F",
			"hgun_Pistol_Signal_F",
			"hgun_Rook40_F",
			"Exile_Weapon_Colt1911",
			"Exile_Weapon_Makarov",
			"Exile_Weapon_Taurus",
			"Exile_Weapon_TaurusGold",
			//CUP
			"CUP_hgun_Glock17",
			"CUP_hgun_Compact",
			"CUP_hgun_Makarov",
			"CUP_hgun_PB6P9",
			"CUP_hgun_MicroUzi",
			"CUP_hgun_Phantom", 
			"CUP_hgun_SA61",
			"CUP_hgun_Duty",
			//Apex
			"hgun_Pistol_01_F",
			"hgun_P07_khk_F",
			"Exile_Weapon_SA61"
		};
	};

	class SubMachineGuns
	{
		name = "Sub Machine Guns";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"hgun_PDW2000_F",
			"SMG_01_F",
			"SMG_02_F",
			"SMG_05_F",
			//CUP
			"CUP_smg_bizon",
			"CUP_smg_EVO",
			"CUP_smg_MP5SD6",
			"CUP_smg_MP5A5"
		};
	};

	class LightMachineGuns
	{
		name = "Light Machine Guns";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"arifle_MX_SW_Black_F",
			"arifle_MX_SW_khk_F",
			"arifle_MX_SW_F",
			"LMG_Mk200_F",
			"LMG_Zafir_F",
			"LMG_03_F",
			"Exile_Weapon_RPK",
			"Exile_Weapon_PK",
			"Exile_Weapon_PKP",
			"MMG_01_hex_F",
			"MMG_01_tan_F",
			"COG_Navid_Black_Hex",
			"MMG_02_black_F",
			"MMG_02_camo_F",
			"MMG_02_sand_F",
			//CUP
			"CUP_lmg_M240",
			"CUP_lmg_M249",
			"CUP_lmg_M249_para",
			"CUP_lmg_Mk48_wdl",
			"CUP_lmg_Mk48_des",
			"CUP_lmg_PKM",
			"CUP_lmg_Pecheneg"
		};
	};

	class AssaultRifles
	{
		name = "Assault Rifles";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"arifle_Katiba_C_F",
			"arifle_Katiba_F",
			"arifle_Katiba_GL_F",
			"arifle_Mk20_F",
			"arifle_Mk20_GL_F",
			"arifle_Mk20_GL_plain_F",
			"arifle_Mk20_plain_F",
			"arifle_Mk20C_F",
			"arifle_Mk20C_plain_F",
			"arifle_MX_Black_F",
			"arifle_MX_F",
			"arifle_MX_GL_Black_F",
			"arifle_MX_GL_F",
			"arifle_MXC_Black_F",
			"arifle_MXC_F",
			"arifle_SDAR_F",
			"arifle_TRG20_F",
			"arifle_TRG21_F",
			"arifle_TRG21_GL_F",
			"Exile_Weapon_AK107",
			"Exile_Weapon_AK107_GL",
			"Exile_Weapon_AK74",
			"Exile_Weapon_AK74_GL",
			"Exile_Weapon_AK47",
			"Exile_Weapon_AKS_Gold",
			//CUP
			"CUP_arifle_AK74",
			"CUP_arifle_AK107",
			"CUP_arifle_AK107_GL",
			"CUP_arifle_AKS74",
			"CUP_arifle_AKS74U",
			"CUP_arifle_AK74_GL",
			"CUP_arifle_AKM",
			"CUP_arifle_AKS",
			"CUP_arifle_AKS_Gold",
			"CUP_arifle_RPK74",
			"CUP_arifle_FNFAL_railed",
			"CUP_arifle_G36K",
			"CUP_arifle_G36K_camo",
			"CUP_arifle_G36C",
			"CUP_arifle_G36C_camo",
			"CUP_arifle_L85A2",
			"CUP_arifle_L85A2_GL",
			"CUP_arifle_L86A2",
			"CUP_arifle_M16A2",
			"CUP_arifle_M16A2_GL",
			"CUP_arifle_M16A4_GL",
			"CUP_arifle_M4A1",
			"CUP_arifle_M4A1_camo",
			"CUP_arifle_M16A4_Base",
			"CUP_arifle_M4A1_BUIS_GL",
			"CUP_arifle_M4A1_BUIS_camo_GL",
			"CUP_arifle_M4A1_black",
			"CUP_arifle_M4A1_desert",
			"CUP_arifle_XM8_Compact_Rail",
			"CUP_arifle_XM8_Railed",
			"CUP_arifle_XM8_Carbine",
			"CUP_arifle_XM8_Carbine_GL",
			"CUP_arifle_xm8_SAW",
			"CUP_arifle_xm8_sharpshooter",
			"CUP_arifle_CZ805_A1",
			"CUP_arifle_CZ805_GL",
			"CUP_arifle_CZ805_A2",
			"CUP_arifle_CZ805_B",
			"CUP_arifle_CZ805_B_GL",
			"CUP_arifle_Mk16_CQC",
			"CUP_arifle_Mk16_CQC_FG",
			"CUP_arifle_Mk16_CQC_SFG",
			"CUP_arifle_Mk16_CQC_EGLM",
			"CUP_arifle_Mk16_STD",
			"CUP_arifle_Mk16_STD_FG",
			"CUP_arifle_Mk16_STD_SFG",
			"CUP_arifle_Mk16_SV",
			"CUP_arifle_Mk17_CQC",
			"CUP_arifle_Mk17_CQC_FG",
			"CUP_arifle_Mk17_CQC_SFG",
			"CUP_arifle_Mk17_CQC_EGLM",
			"CUP_arifle_Mk17_STD",
			"CUP_arifle_Mk17_STD_FG",
			"CUP_arifle_Mk17_STD_SFG",
			"CUP_arifle_Mk20",
			"CUP_arifle_Sa58P",
			"CUP_arifle_Sa58V",
			"CUP_arifle_Sa58P_des",
			"CUP_arifle_Sa58V_camo",
			"CUP_arifle_Sa58RIS1",
			"CUP_arifle_Sa58RIS1_des",
			"CUP_arifle_Sa58RIS2",
			"CUP_arifle_Sa58RIS2_camo",
			//Apex
			"arifle_AK12_F",
			"arifle_AK12_GL_F",
			"arifle_AKM_F",
			"arifle_AKM_FL_F",
			"arifle_AKS_F",
			"arifle_ARX_blk_F",
			"arifle_ARX_ghex_F",
			"arifle_ARX_hex_F",
			"arifle_CTAR_blk_F",
			"arifle_CTAR_hex_F",
			"arifle_CTAR_ghex_F",
			"arifle_CTAR_GL_blk_F",
			"arifle_CTARS_blk_F",
			"arifle_CTARS_hex_F",
			"arifle_CTARS_ghex_F",
			"arifle_SPAR_01_blk_F",
			"arifle_SPAR_01_khk_F",
			"arifle_SPAR_01_snd_F",
			"arifle_SPAR_01_GL_blk_F",
			"arifle_SPAR_01_GL_khk_F",
			"arifle_SPAR_01_GL_snd_F",
			"arifle_SPAR_02_blk_F",
			"arifle_SPAR_02_khk_F",
			"arifle_SPAR_02_snd_F",
			"arifle_SPAR_03_blk_F",
			"arifle_SPAR_03_khk_F",
			"arifle_SPAR_03_snd_F",
			"arifle_MX_khk_F",
			"arifle_MX_GL_khk_F",
			"arifle_MXC_khk_F",
			"Exile_Weapon_M4",
			"Exile_Weapon_M16A4",
			"Exile_Weapon_M16A2"
		};
	};

	class Shotguns
	{
		name = "Shotguns";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Exile_Weapon_M1014",
			//CUP
			"CUP_sgun_AA12",
			"CUP_sgun_M1014",
			"CUP_sgun_Saiga12K"
		};
	};

	class GrenadeLaunchers
	{
		name = "Grenade Launchers";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"CUP_glaunch_Mk13",
			"CUP_glaunch_M79"
		};
	};

	class SniperRifles
	{
		name = "Sniper Rifles";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"arifle_MXM_Black_F",
			"arifle_MXM_F",
			"arifle_MXM_khk_F",
			"srifle_DMR_01_F",
			"srifle_DMR_02_camo_F",
			"srifle_DMR_02_F",
			"srifle_DMR_02_sniper_F",
			"srifle_DMR_03_F",
			"srifle_DMR_03_khaki_F",
			"srifle_DMR_03_multicam_F",
			"srifle_DMR_03_tan_F",
			"srifle_DMR_03_woodland_F",
			"srifle_DMR_04_F",
			"srifle_DMR_04_Tan_F",
			"srifle_DMR_05_blk_F",
			"srifle_DMR_05_hex_F",
			"srifle_DMR_05_tan_f",
			"srifle_DMR_06_camo_F",
			"srifle_DMR_06_olive_F",
			"srifle_EBR_F",
			"srifle_GM6_camo_F",
			"srifle_GM6_F",
			"srifle_LRR_camo_F",
			"srifle_LRR_F",
			"Exile_Weapon_CZ550",
			"Exile_Weapon_SVD",
			"Exile_Weapon_SVDCamo",
			"Exile_Weapon_VSSVintorez",
			"Exile_Weapon_DMR",
			"Exile_Weapon_LeeEnfield",
			//CUP
			"CUP_srifle_AWM_wdl",
			"CUP_srifle_AWM_des",
			"CUP_srifle_ksvk",
			"CUP_srifle_CZ750",
			"CUP_srifle_DMR",
			"CUP_srifle_CZ550",
			"CUP_srifle_M14",
			"CUP_srifle_Mk12SPR",
			"CUP_srifle_M24_wdl",
			"CUP_srifle_M40A3",
			"CUP_srifle_M107_Base",
			"CUP_srifle_M110",
			"CUP_srifle_SVD",
			"CUP_srifle_VSSVintorez",
			"CUP_srifle_AS50",
			//Apex
			"srifle_LRR_tna_F",
			"srifle_GM6_ghex_F",
			"srifle_DMR_07_blk_F",
			"srifle_DMR_07_hex_F",
			"srifle_DMR_07_ghex_F",
			"Exile_Weapon_m107",
			"Exile_Weapon_ksvk"
		};
	};

	class Bikes
	{
		name = "Bikes";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			//"Exile_Bike_OldBike",
			//"Exile_Bike_MountainBike",
			//"CUP_B_M1030"
		};
	};

	class Cars
	{
		name = "Cars";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			//"Exile_Car_Kart_Black",
			//"Exile_Bike_QuadBike_Black",
			//"Exile_Car_OldTractor_Red",
			//"Exile_Car_TowTractor_White",
			//"Exile_Car_Tractor_Red",
			"Exile_Car_UAZ_Green",
			"Exile_Car_UAZ_Open_Green",
			"Exile_Car_Octavius_Black",
			"Golf_Civ_pink",
			"CUP_C_Golf4_red_Civ",
			"CUP_C_Golf4_black_Civ",
			"CUP_C_Golf4_yellow_Civ",
			"CUP_C_Golf4_blue_Civ",
			"CUP_C_Golf4_white_Civ",
			"CUP_C_Golf4_green_Civ",
			"CUP_C_Golf4_camo_Civ",
			"CUP_C_Golf4_camodigital_Civ",
			"CUP_C_Golf4_camodark_Civ",
			"CUP_C_Golf4_reptile_Civ",
			"CUP_C_Golf4_whiteblood_Civ",
			"CUP_C_Golf4_crowe_Civ",
			"Exile_Car_LandRover_Green",
			"Exile_Car_LandRover_Ambulance_Green",
			"Exile_Car_Lada_Green",
			"Exile_Car_Volha_Black",
			//"Exile_Car_Hatchback_Black",
			//"Exile_Car_Hatchback_Sport_Red",
			"Exile_Car_SUV_Black",
			"Exile_Car_SUVXL_Black",
			"Exile_Car_SUV_Armed_Black",
			"Exile_Car_Offroad_DarkRed",
			"Exile_Car_Offroad_Repair_Civillian",
			"Exile_Car_Offroad_Armed_Guerilla01",
			"Exile_Car_BRDM2_HQ",
			"Exile_Car_BTR40_MG_Green",
			"Exile_Car_BTR40_Green",
			"Exile_Car_HMMWV_M134_Green",
			"Exile_Car_HMMWV_M2_Green",
			"Exile_Car_HMMWV_MEV_Green",
			"Exile_Car_HMMWV_UNA_Green",
			"Exile_Car_Strider",
			"I_MRAP_03_hmg_F",   //HMG Strider
			"Exile_Car_Hunter",
			"B_MRAP_01_hmg_F", //HMG Hunter
			"Exile_Car_Ifrit",
			"O_MRAP_02_hmg_F", //HMG Ifrit
			"O_T_APC_Wheeled_02_rcws_ghex_F", //HMG Marid
			"O_APC_Wheeled_02_rcws_F", //HMG Marid
			"Exile_Car_ProwlerLight",
			"Exile_Car_ProwlerUnarmed",
			"Exile_Car_QilinUnarmed",
			"Exile_Car_MB4WD",
			"Exile_Car_MB4WDOpen",
			//// CUP Unarmed
			"CUP_C_LR_Transport_CTK",
			"CUP_O_LR_Transport_TKA",
			"CUP_B_LR_Transport_CZ_W",
			"CUP_B_LR_Transport_GB_W",
			"CUP_B_LR_Ambulance_CZ_W",
			"CUP_B_LR_Ambulance_GB_W",
			"CUP_O_LR_Ambulance_TKA",
			"CUP_O_UAZ_Unarmed_RU",
			"CUP_B_UAZ_Unarmed_CDF",
			"CUP_O_UAZ_Open_RU",
			"CUP_B_UAZ_Open_CDF",
			"CUP_B_HMMWV_Unarmed_USMC",
			"CUP_B_HMMWV_Ambulance_USMC",
			//// CUP Armed
			"CUP_O_UAZ_MG_RU",
			"CUP_O_GAZ_Vodnik_PK_RU",
			"CUP_B_LR_Special_CZ_W",
			"CUP_B_LR_MG_CZ_W",
			"CUP_B_LR_MG_GB_W",
			"CUP_B_HMMWV_M1114_USMC",
			"CUP_B_HMMWV_M2_USMC",
			"CUP_B_HMMWV_DSHKM_GPK_ACR",
			"CUP_B_Dingo_GER_Wdl",
			"CUP_B_Dingo_GER_Des",
			"CUP_B_Dingo_CZ_Wdl",
			"CUP_B_BAF_Coyote_L2A1_W",
			"CUP_B_Jackal2_L2A1_GB_W",
			"CUP_B_M1126_ICV_M2_Woodland_Slat",
			"CUP_B_M1126_ICV_M2_Woodland",
			"CUP_B_M1130_CV_M2_Woodland_Slat",
			"CUP_B_M1130_CV_M2_Woodland",
			"CUP_B_RG31_M2_USMC",
			"CUP_B_RG31_M2_GC_USMC",
			"CUP_B_RG31_M2_OD_USMC",
			"CUP_B_RG31E_M2_USMC",
			"CUP_B_AAV_USMC",
			"CUP_I_AAV_RACS",
			//// Apex Unarmed
			"B_GEN_Offroad_01_gen_F",
			//// Apex Armed
			"B_T_LSV_01_armed_F",
			"B_T_LSV_01_armed_black_F",
			"B_T_LSV_01_armed_sand_F",
			"O_T_LSV_02_armed_F",
			"O_T_LSV_02_armed_black_F",
			"O_T_LSV_02_armed_arid_F"
		};
	};

	class Trucks
	{
		name = "Trucks";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Exile_Car_Van_Black",
			"Exile_Car_Van_Box_Black",
			"Exile_Car_Van_Fuel_Black",
			"Exile_Car_Ural_Open_Worker",
			"Exile_Car_Ural_Covered_Worker",
			"Exile_Car_V3S_Covered",
			"Exile_Car_Zamak",
			"Exile_Car_Tempest",
			"Exile_Car_HEMMT",
			"Exile_Car_Ikarus_Party",
			//// CUP Unarmed
			"CUP_V3S_Open_NAPA",
			"CUP_O_Ural_Open_RU",
			"CUP_B_Ural_Open_CDF",
			"CUP_B_MTVR_USMC",
			"CUP_O_Ural_RU",
			"CUP_B_Ural_CDF",
			"CUP_B_MTVR_Ammo_USMC",
			"CUP_O_Ural_Reammo_RU",
			"CUP_B_Ural_Reammo_CDF",
			"CUP_B_MTVR_Repair_USMC",
			"CUP_O_Ural_Repair_RU",
			"CUP_B_Ural_Repair_CDF",
			"CUP_B_MTVR_Refuel_USMC",
			"CUP_O_Ural_Refuel_RU",
			"CUP_B_Ural_Refuel_CDF",
			//// CUP Armed
			"CUP_B_Ridgback_HMG_GB_W",
			"CUP_B_Ridgback_HMG_GB_D",
			"CUP_B_Ridgback_LMG_GB_W",
			"CUP_B_Ridgback_LMG_GB_D",
			"CUP_B_Wolfhound_HMG_GB_W",
			"CUP_B_Wolfhound_HMG_GB_D",
			"CUP_B_Wolfhound_LMG_GB_W",
			"CUP_B_Wolfhound_LMG_GB_D",
			"CUP_B_Mastiff_HMG_GB_W",
			"CUP_B_Mastiff_HMG_GB_D",
			"CUP_B_Mastiff_LMG_GB_W",
			"CUP_B_Mastiff_LMG_GB_D",
			"CUP_B_Ural_ZU23_CDF",
			"CUP_O_Ural_ZU23_CHDKZ",
			"CUP_O_Ural_ZU23_RU",
			"CUP_O_Ural_ZU23_TKA",
			"CUP_O_ZSU23_CSAT",
			"CUP_O_ZSU23_SLA",
			"CUP_O_ZSU23_TK",
			"CUP_I_ZSU23_AAF",
			//// Apex Unarmed
			"B_T_Truck_01_covered_F",
			"O_T_Truck_03_transport_ghex_F",
			"O_T_Truck_03_covered_ghex_F",
			"O_T_Truck_03_device_ghex_F",
			"I_C_Van_01_transport_brown_F",
			"I_C_Van_01_transport_olive_F"
		};
	};

	class Choppers
	{
		name = "Helicopters";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Exile_Chopper_Hummingbird_Green",
			"Exile_Chopper_Hummingbird_Civillian_Wasp",
			"Exile_Chopper_Huey_Green",
			"Exile_Chopper_Huey_Armed_Green",
			"Exile_Chopper_Taru_Black",
			"Exile_Chopper_Taru_Covered_Black",
			"Exile_Chopper_Taru_Transport_Black",
			"Exile_Chopper_Orca_BlackCustom",
			"Exile_Chopper_Mohawk_FIA",
			"Exile_Chopper_Huron_Black",
			"Exile_Chopper_Hellcat_Green",
			//Arma
			////Littlebird
			"B_Heli_Light_01_F",
			"B_Heli_Light_01_stripped_F",
			"B_Heli_Light_01_armed_F",
			"CUP_B_AH6M_Cannons_USA",
			////Ghost Hawk
			"B_CTRG_Heli_Transport_01_tropic_F",
			"B_Heli_Transport_01_F",
			"B_Heli_Transport_01_camo_F",
			////ORCA
			"O_Heli_Light_02_unarmed_F",
			"O_Heli_Light_02_F",
			"O_Heli_Light_02_v2_F",
			////Hellcat
			"I_Heli_light_03_unarmed_F",
			"I_Heli_light_03_F",
			// CUP
			"CUP_B_CH53E_USMC",
			"CUP_B_CH53E_VIV_USMC",
			"CUP_B_UH1Y_UNA_F",
			"CUP_B_UH1Y_MEV_F",
			"CUP_C_Mi17_Civilian_RU",
			"CUP_B_Mi17_CDF",
			"CUP_O_Mi17_TK",
			"CUP_B_Mi17_medevac_CDF",
			"CUP_B_Mi171Sh_Unarmed_ACR",
			"CUP_O_Mi8_medevac_CHDKZ",
			"CUP_O_Mi8_medevac_RU",
			"CUP_O_Mi8_VIV_CHDKZ",
			"CUP_O_Mi8_VIV_RU",
			"CUP_Merlin_HC3_FFV",
			"CUP_Merlin_HC3",
			"CUP_Merlin_HC3_MED",
			"CUP_B_MH6J_USA",
			"CUP_I_MH6J_RACS",
			"CUP_B_MH60S_USMC",
			"CUP_B_MH60S_FFV_USMC",
			"CUP_B_AW159_Unarmed_BAF",
			"CUP_B_CH47F_USA",
			"CUP_B_CH47F_GB",
			"CUP_B_UH60M_US",
			"CUP_B_UH60L_US",
			"CUP_B_UH60M_FFV_US",
			"CUP_B_UH60L_FFV_US",
			"CUP_B_UH60M_Unarmed_US",
			"CUP_B_UH60L_Unarmed_US",
			"CUP_B_UH60M_Unarmed_FFV_US",
			"CUP_B_UH60L_Unarmed_FFV_US",
			"CUP_B_UH60M_Unarmed_FFV_MEV_US",
			"CUP_B_UH60L_Unarmed_FFV_MEV_US",
			"CUP_I_UH60L_RACS",
			"CUP_I_UH60L_FFV_RACS",
			"CUP_I_UH60L_Unarmed_RACS",
			"CUP_I_UH60L_Unarmed_FFV_Racs",
			"CUP_I_UH60L_Unarmed_FFV_MEV_Racs",
			"CUP_O_MI6A_TKA",
			"CUP_B_MI6A_CDF",
			"CUP_O_MI6A_RU",
			"CUP_C_MI6A_RU",
			"CUP_B_MV22_VIV_USMC",
			// Apex
			"I_C_Heli_Light_01_civil_F",
			"B_T_VTOL_01_infantry_blue_F",
			"B_T_VTOL_01_infantry_olive_F",
			"B_T_VTOL_01_vehicle_blue_F",
			"B_T_VTOL_01_vehicle_olive_F"
		};
	};

	class Boats
	{
		name = "Boats";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Exile_Boat_RubberDuck_CSAT",
			"Exile_Boat_RubberDuck_Digital",
			"Exile_Boat_RubberDuck_Orange",
			"Exile_Boat_RubberDuck_Blue",
			"Exile_Boat_RubberDuck_Black",
			"Exile_Boat_MotorBoat_Police",
			"Exile_Boat_MotorBoat_Orange",
			"Exile_Boat_MotorBoat_White",
			"Exile_Boat_SDV_CSAT",
			"Exile_Boat_SDV_Digital",
			"Exile_Boat_SDV_Grey",
			"Exile_Boat_WaterScooter",
			"Exile_Boat_RHIB",
			//// Apex
			"C_Boat_Transport_02_F",
			"I_Boat_Armed_01_minigun_F",
			"B_Boat_Armed_01_minigun_F",
			"O_Boat_Armed_01_hmg_F",
			"CUP_B_RHIB_USMC",
			"CUP_I_RHIB_RACS"
		};
	};

	class Planes
	{
		name = "Planes";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Exile_Plane_Cessna",
			"Exile_Plane_AN2_Green",
			"Exile_Plane_Ceasar",
			"Exile_Plane_BlackfishInfantry",
			"Exile_Plane_BlackfishVehicle",
			//// CUP
			"CUP_C_C47_CIV",
			"CUP_B_C47_USA",
			"CUP_B_AC47_Spooky_USA",
			//// Apex
			"C_Plane_Civil_01_racing_F"
		};
	};

	class Diving
	{
		name = "Diving";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"G_Diving",
			"G_B_Diving",
			"G_O_Diving",
			"G_I_Diving",
			"V_RebreatherB",
			"V_RebreatherIA",
			"V_RebreatherIR",
			"U_I_Wetsuit",
			"U_O_Wetsuit",
			"U_B_Wetsuit"
		};
	};
};

class CfgTraders
{
	/**
	 * Weapons, scopes, silencers, ammo
	 */
	class Exile_Trader_Armory
	{
		name = "ARMORY";
		showWeaponFilter = 1;
		categories[] = 
		{
			"GoalOptics",
			"GoalWeapons",
			"GoalAmmo",
			"PointerAttachments",
			"BipodAttachments",
			"MuzzleAttachments",
			"OpticAttachments",
			"Ammunition",
			"Pistols",
			"Shotguns",
			"GrenadeLaunchers",
			"SubMachineGuns",
			"LightMachineGuns",
			"AssaultRifles",
			"SniperRifles",
			"Flares",
			"Smokes",
			"Grenades"
		};
	};

	/**
	 * Satchels, nades, UAVs, static MGs
	 */
	class Exile_Trader_SpecialOperations
	{
		name = "SPECIAL OPERATIONS";
		showWeaponFilter = 1; // for noob tubes
		categories[] = 
		{
			"GoalGoggles",
			"GoalLaunchers",
			"GoalRockets",
			"OrangeDLCUAVs",
			"UAVs",
			"StaticMGs",
			"StaticMGAmmo",
			"Explosives",
			"Navigation",
			"RocketLaunchers",
			"LauncherOptics",
			"Rockets",
			"Diving"
		};
	};

	/**
	 * Uniforms, vests, helmets, backpacks
	 */
	class Exile_Trader_Equipment
	{	
		name = "EQUIPMENT";
		showWeaponFilter = 0;
		categories[] = 
		{
			"GoalUniforms",
			"GoalHeadgear",
			"OrangeDLCUniforms",
			"OrangeDLCVests",
			"OrangeDLCHeadgear",
			"OrangeDLCFacewear",
			"OrangeDLCBackpacks",
			"TRYKUniforms",
			"TRYKHeadgear",
			"TRYKFacewear",
			"TRYKNVG",
			"TRYKVests",
			"TRYKBackpacks",
			"Uniforms",
			"Headgear",
			"Glasses",
			"Vests",
			"Backpacks",
			"FirstAid"
		};
	};

	/**
	 * Cans, cans, cans
	 */
	class Exile_Trader_Food
	{
		name = "FAST FOOD";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Food",
			"Drinks",
			"NonVeganFood"
		};
	};

	/**
	 * Light bulbs, metal, etc.
	 */
	class Exile_Trader_Hardware
	{
		name = "HARDWARE";
		showWeaponFilter = 0;
		categories[] = 
		{
			"GoalConstruction",
			"GoalEBM",
			"Hardware",
			"Tools",
			"COGContructables",
			"EBMBuildings",
			"EBMContainers",
			"EBMFlora",
			"EBMLamps",
			"EBMMisc",
			"EBMSigns",
			"EBMWalls",
			"EBMBarriers"
		};
	};

	/**
	 * Sells cars and general vehicles
	 */
	class Exile_Trader_Vehicle
	{
		name = "VEHICLE";
		showWeaponFilter = 0;
		categories[] = 
		{
			"GoalVehicles",
			"OrangeDLCCars",
			"OrangeDLCTrucks",
			"COGStriders",
			"COGIfrits",
			"COGHunters",
			"COGJeeps",
			"COGBeetles",
			"VWBeetles",
			"UGVs",
			"Cars",
			"Trucks"
		};
	};

	/**
	 * Sells choppers and planes
	 */
	class Exile_Trader_Aircraft
	{
		name = "AIRCRAFT";
		showWeaponFilter = 0;
		categories[] = 
		{
			"GoalAircraft",
			"OrangeDLCChoppers",
			"Choppers", 
			"Planes",
			"Drones"
		};
	};

	/**
	 * Sells ships and boats
	 */ 
	class Exile_Trader_Boat
	{
		name = "BOAT";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Boats"
		};
	};

	class Exile_Trader_Diving
	{
		name = "DIVERS";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Diving"
		};
	};

	/**
	 * Sells Community Items
	 */ 
	class Exile_Trader_CommunityCustoms
	{
		name = "Gypsy Trader";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Ammunition",
			"BipodAttachments",
			"MuzzleAttachments",
			"OpticAttachments",
			"PointerAttachments",
			"Rockets",
			"Explosives",
			"Grenades",
			"Food",
			"Drinks",
			"FirstAid",
			"Hardware",
			"Tools"
		};
	};

	class Exile_Trader_CommunityCustoms2
	{
		name = "COG Car Sales";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community2"
		};
	};

	class Exile_Trader_CommunityCustoms3
	{
		name = "COG Fun Zone";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community3"
		};
	};

	class Exile_Trader_CommunityCustoms4
	{
		name = "Black Market";
		showWeaponFilter = 0;
		categories[] = 
		{
			"NIAMuzzleAttachments",
			"NIAAttachments",
			"NIAOpticAttachments",
			"NIAPistols",
			"NIAShotguns",
			"NIASubMachineGuns",
			"NIALightMachineGuns",
			"NIAACRAssaultRifles",
			"NIAAssaultRifles",
			"NIASniperRifles",
			"NIAAmmunition",
			"NIAGrenadeSmoke"
		};
	};

	class Exile_Trader_CommunityCustoms5
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community5"
		};
	};

	class Exile_Trader_CommunityCustoms6
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community6"
		};
	};

	class Exile_Trader_CommunityCustoms7
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community7"
		};
	};

	class Exile_Trader_CommunityCustoms8
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community8"
		};
	};

	class Exile_Trader_CommunityCustoms9
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community9"
		};
	};

	class Exile_Trader_CommunityCustoms10
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community10"
		};
	};
};
class CfgTrading 
{
	/*
	* This factor defines the difference between sales/purchase price of
	* items and vehicles. It is used if there is no sales price defined
	* in CfgExileArsenal. 
	*/
	sellPriceFactor = 0.5;
	
	rekeyPriceFactor = 0.05;

	class requiredRespect 
	{
		Level1 = 0;
		Level2 = 10000;
		Level3 = 20000;
		Level4 = 30000;
		Level5 = 40000;
		Level6 = 50000;
		Level7 = 300000;
		Level8 = 450000;
		Level9 = 600000;
		Level10 = 750000;
	};
};

class CfgVehicleCustoms
{
	///////////////////////////////////////////////////////////////////////////////
	// QUAD BIKES
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Bike_QuadBike_Abstract
	{
		skins[] =
		{

			{"Exile_Bike_QuadBike_Blue",		100, "Blue",		{"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLUE_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLUE_CO.paa"}},
			{"Exile_Bike_QuadBike_Red",			100, "Red",			{"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_RED_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVRED_CO.paa"}},
			{"Exile_Bike_QuadBike_White",		100, "White",		{"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_WHITE_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVWHITE_CO.paa"}},
			{"Exile_Bike_QuadBike_Nato",		150, "NATO",		{"\A3\Soft_F\Quadbike_01\Data\Quadbike_01_co.paa","\A3\Soft_F\Quadbike_01\Data\Quadbike_01_wheel_co.paa"}},
			{"Exile_Bike_QuadBike_Csat",		150, "CSAT",		{"\A3\Soft_F\Quadbike_01\Data\Quadbike_01_OPFOR_CO.paa","\A3\Soft_F\Quadbike_01\Data\Quadbike_01_wheel_OPFOR_CO.paa"}},
			{"Exile_Bike_QuadBike_Fia",			150, "FIA",			{"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_INDP_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_INDP_CO.paa"}},
			{"Exile_Bike_QuadBike_Guerilla01",	150, "Guerilla 01",	{"\A3\Soft_F_Bootcamp\Quadbike_01\Data\Quadbike_01_IG_CO.paa","\A3\soft_f_gamma\Quadbike_01\Data\Quadbike_01_wheel_IG_CO.paa"}},
			{"Exile_Bike_QuadBike_Guerilla02",	150, "Guerilla 02",	{"\A3\Soft_F_Bootcamp\Quadbike_01\Data\Quadbike_01_INDP_Hunter_CO.paa","\A3\soft_f_gamma\Quadbike_01\Data\Quadbike_01_wheel_INDP_Hunter_CO.paa"}},
			{"Exile_Bike_QuadBike_Black",		100, "Black",		{"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLACK_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLACK_CO.paa"}},
			{"Exile_Bike_QuadBike_Black",		100, "Hex",		{"\A3\Soft_f_Exp\Quadbike_01\data\Quadbike_01_ghex_CO.paa","\A3\Soft_f_Exp\Quadbike_01\data\Quadbike_01_wheel_ghex_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// MOTOR BOATS
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Boat_MotorBoat_Abstract
	{
		skins[] =
		{
			{"Exile_Boat_MotorBoat_Police",		350, "Police", {"\a3\boat_f_gamma\Boat_Civil_01\data\Boat_Civil_01_ext_police_co.paa","\a3\boat_f_gamma\Boat_Civil_01\data\Boat_Civil_01_int_police_co.paa"}},
			{"Exile_Boat_MotorBoat_Orange",		300, "Orange", {"\a3\boat_f_gamma\Boat_Civil_01\data\Boat_Civil_01_ext_rescue_co.paa","\a3\boat_f_gamma\Boat_Civil_01\data\Boat_Civil_01_int_rescue_co.paa"}},
			{"Exile_Boat_MotorBoat_White",		300, "White",  {"\a3\boat_f_gamma\Boat_Civil_01\data\Boat_Civil_01_ext_co.paa","\a3\boat_f_gamma\Boat_Civil_01\data\Boat_Civil_01_int_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// RUBBER DUCKS
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Boat_RubberDuck_Abstract
	{
		skins[] =
		{
			{"Exile_Boat_RubberDuck_CSAT",		200, "CSAT", {"\A3\boat_F\Boat_Transport_01\data\Boat_Transport_01_OPFOR_CO.paa"}},
			{"Exile_Boat_RubberDuck_Digital",	200, "Digital",{"\A3\boat_F\Boat_Transport_01\data\Boat_Transport_01_INDP_CO.paa"}},
			{"Exile_Boat_RubberDuck_Orange",	150, "Orange", {"\A3\boat_F\Boat_Transport_01\data\Boat_Transport_01_rescue_CO.paa"}},
			{"Exile_Boat_RubberDuck_Blue",		150, "Blue", {"\A3\boat_F\Boat_Transport_01\data\Boat_Transport_01_civilian_CO.paa"}},
			{"Exile_Boat_RubberDuck_Black",		150, "Black", {"\A3\boat_F\Boat_Transport_01\data\boat_transport_01_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// SDV
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Boat_SDV_Abstract
	{
		skins[] =
		{
			{"Exile_Boat_SDV_CSAT",		200, "CSAT", {"\A3\boat_f_beta\SDV_01\data\SDV_ext_opfor_CO.paa"}},
			{"Exile_Boat_SDV_Digital",	200, "Digital", {"\A3\boat_f_beta\SDV_01\data\SDV_ext_INDP_CO.paa"}},
			{"Exile_Boat_SDV_Grey",		100, "Grey", {"\A3\boat_f_beta\SDV_01\data\SDV_ext_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Hellcat
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Hellcat_Abstract
	{
		skins[] =
		{
			{"Exile_Chopper_Hellcat_Green", 350, "Green", 	{"\A3\Air_F_EPB\Heli_Light_03\data\Heli_Light_03_base_CO.paa"}},
			{"Exile_Chopper_Hellcat_FIA", 	500, "FIA", 	{"\A3\Air_F_EPB\Heli_Light_03\data\heli_light_03_base_indp_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Karts
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Kart_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Kart_BluKing", 				100, "Bluking", 	{"\a3\Soft_F_Kart\Kart_01\Data\Kart_01_blu_CO.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_01_logos_blu_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_1_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_3_CA.paa"}},
			{"Exile_Car_Kart_RedStone", 			100, "RedStone", 	{"\a3\Soft_F_Kart\Kart_01\Data\Kart_01_black_CO.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_01_logos_black_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_1_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_3_CA.paa"}},
			{"Exile_Car_Kart_Vrana", 				100, "Vrana", 		{"\a3\Soft_F_Kart\Kart_01\Data\Kart_01_vrana_CO.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_01_logos_vrana_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_1_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_3_CA.paa"}},
			{"Exile_Car_Kart_Green", 				100, "Green", 		{"\a3\Soft_F_Kart\Kart_01\Data\Kart_01_base_green_CO.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_01_logos_blu_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_1_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_3_CA.paa"}},
			{"Exile_Car_Kart_Blue", 				100, "Blue", 		{"\a3\Soft_F_Kart\Kart_01\Data\Kart_01_base_blue_CO.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_01_logos_blu_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_1_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_3_CA.paa"}},
			{"Exile_Car_Kart_Orange", 				100, "Orange",		{"\a3\Soft_F_Kart\Kart_01\Data\Kart_01_base_orange_CO.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_01_logos_blu_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_1_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_3_CA.paa"}},
			{"Exile_Car_Kart_White", 				100, "White", 		{"\a3\Soft_F_Kart\Kart_01\Data\Kart_01_base_white_CO.paa","","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_1_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_3_CA.paa"}},
			{"Exile_Car_Kart_Yellow", 				100, "Yellow", 		{"\a3\Soft_F_Kart\Kart_01\Data\Kart_01_base_yellow_CO.paa","","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_1_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_3_CA.paa"}},
			{"Exile_Car_Kart_Black", 				100, "Black", 		{"\a3\Soft_F_Kart\Kart_01\Data\Kart_01_base_black_CO.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_01_logos_black_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_1_CA.paa","\a3\Soft_F_Kart\Kart_01\Data\Kart_num_3_CA.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Hummingbird (Civillian)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Hummingbird_Civillian_Abstract
	{
		skins[] =
		{
			{"Exile_Chopper_Hummingbird_Civillian_Blue", 				350, "Blue", 				{"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Red", 				350, "Red", 				{"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian", 						350, "Green", 			{"\a3\Air_F\Heli_Light_01\Data\heli_light_01_ext_blufor_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian", 						350, "AAF", 				{"\a3\Air_F\Heli_Light_01\Data\heli_light_01_ext_indp_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_ION", 				350, "ION", 				{"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_ion_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_BlueLine",	 	350, "BlueLine", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueLine_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Digital", 		350, "Digital", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_digital_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Elliptical", 	350, "Elliptical", 	{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Furious", 		350, "Furious", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_GrayWatcher", 350, "GrayWatcher",	{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_graywatcher_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Jeans", 			350, "Jeans", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Light", 			350, "Light", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_light_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Shadow", 			350, "Shadow", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_shadow_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Sheriff", 		350, "Sheriff", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Speedy", 			350, "Speedy", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Sunset", 			350, "Sunset", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Vrana", 			350, "Vrana", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Wasp", 				350, "Wasp", 				{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa"}},
			{"Exile_Chopper_Hummingbird_Civillian_Wave", 				350, "Wave", 				{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Hummingbird
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Hummingbird_Abstract
	{
		skins[] = 
		{
			{"Exile_Chopper_Hummingbird_Green",		350, "Green", 			{"\a3\Air_F\Heli_Light_01\Data\heli_light_01_ext_blufor_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "AAF", 				{"\a3\Air_F\Heli_Light_01\Data\heli_light_01_ext_indp_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "Blue", 				{"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "Red", 				{"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "ION", 				{"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_ion_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green", 	350, "BlueLine", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueLine_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green", 	350, "Digital", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_digital_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green", 	350, "Elliptical", 	{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green", 	350, "Furious", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "GrayWatcher",	{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_graywatcher_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "Jeans", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "Light", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_light_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "Shadow", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_shadow_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green", 	350, "Sheriff", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "Speedy", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "Sunset", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "Vrana", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "Wasp", 				{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa"}},
			{"Exile_Chopper_Hummingbird_Green",		350, "Wave", 				{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Pawnee
	///////////////////////////////////////////////////////////////////////////////
	class Heli_Light_01_armed_base_F
	{
		skins[] = 
		{
			{"B_Heli_Light_01_armed_F",		350, "Blue", 				{"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "Red", 				{"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "Green", 			{"\a3\Air_F\Heli_Light_01\Data\heli_light_01_ext_blufor_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "AAF", 				{"\a3\Air_F\Heli_Light_01\Data\heli_light_01_ext_indp_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "ION", 				{"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_ion_co.paa"}},
			{"B_Heli_Light_01_armed_F", 	350, "BlueLine", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueLine_co.paa"}},
			{"B_Heli_Light_01_armed_F", 	350, "Digital", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_digital_co.paa"}},
			{"B_Heli_Light_01_armed_F", 	350, "Elliptical", 	{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa"}},
			{"B_Heli_Light_01_armed_F", 	350, "Furious", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "GrayWatcher",	{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_graywatcher_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "Jeans", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "Light", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_light_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "Shadow", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_shadow_co.paa"}},
			{"B_Heli_Light_01_armed_F", 	350, "Sheriff", 		{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "Speedy", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "Sunset", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "Vrana", 			{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "Wasp", 				{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa"}},
			{"B_Heli_Light_01_armed_F",		350, "Wave", 				{"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Huron
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Huron_Abstract
	{
		skins[] =
		{
			{"Exile_Chopper_Huron_Black", 	450, "Black", {"\A3\Air_F_Heli\Heli_Transport_03\Data\Heli_Transport_03_ext01_black_CO.paa","\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_black_co.paa"}},
			{"Exile_Chopper_Huron_Green", 	450, "Green", {"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_co.paa","\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Orca
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Orca_Abstract
	{
		skins[] =
		{
			{"Exile_Chopper_Orca_CSAT", 				350, "CSAT", 					{"\A3\Air_F\Heli_Light_02\Data\Heli_Light_02_ext_OPFOR_CO.paa"}},
			{"Exile_Chopper_Orca", 							350, "AAF", 					{"\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_indp_co.paa"}},
			{"Exile_Chopper_Orca_Black", 				350, "Black", 				{"\A3\Air_F\Heli_Light_02\Data\Heli_Light_02_ext_CO.paa"}},
			{"Exile_Chopper_Orca_BlackCustom", 	350, "Black Custom", 	{"\A3\Air_F_Heli\Heli_Light_02\Data\Heli_Light_02_ext_OPFOR_V2_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Taru
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Taru_Abstract
	{
		skins[] =
		{
			{"Exile_Chopper_Taru_CSAT",		500, "CSAT", 	{"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_base_01_co.paa","A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_base_02_co.paa"}},
			{"Exile_Chopper_Taru_Black",	500, "BLACK", 	{"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_base_01_black_CO.paa","A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_base_02_black_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Taru (Transport)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Taru_Transport_Abstract
	{
		skins[] =
		{
			{"Exile_Chopper_Taru_Transport_CSAT",	500, "CSAT", 	{"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_base_01_co.paa","A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_base_02_co.paa"}},
			{"Exile_Chopper_Taru_Transport_Black",	500, "Black", 	{"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_base_01_black_CO.paa","A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_base_02_black_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Taru (Covered)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Taru_Covered_Abstract
	{
		skins[] =
		{
			{"Exile_Chopper_Taru_Covered_CSAT",		500, "CSAT",	{"A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_base_01_CO.paa","A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_base_02_CO.paa","A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_Pod_Ext01_CO.paa","A3\Air_F_Heli\Heli_Transport_04\Data\Heli_Transport_04_Pod_Ext02_CO.paa"}},
			{"Exile_Chopper_Taru_Covered_Black",	500, "Black",	{"A3\Air_F_Heli\Heli_Transport_04\Data\heli_transport_04_base_01_black_co.paa","A3\Air_F_Heli\Heli_Transport_04\Data\heli_transport_04_base_02_black_co.paa","A3\Air_F_Heli\Heli_Transport_04\Data\heli_transport_04_pod_ext01_black_co.paa","A3\Air_F_Heli\Heli_Transport_04\Data\heli_transport_04_pod_ext02_black_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Hatchback
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Hatchback_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Hatchback_Rusty1", 			50, "Rusty White",		{"\exile_assets\model\RTV\Exile_Car_Hatchback_01_co.paa"}},
			{"Exile_Car_Hatchback_Rusty2", 			50, "Rusty Red",		{"\exile_assets\model\RTV\Exile_Car_Hatchback_02_co.paa"}},
			{"Exile_Car_Hatchback_Rusty3", 			50, "Rusty Yellow",		{"\exile_assets\model\RTV\Exile_Car_Hatchback_03_co.paa"}},
			{"Exile_Car_Hatchback_Beige", 			100, "Beige",			{"\A3\Soft_F_Gamma\Hatchback_01\data\Hatchback_01_ext_BASE01_CO.paa"}},
			{"Exile_Car_Hatchback_Green", 			100, "Green",			{"\A3\Soft_F_Gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa"}},
			{"Exile_Car_Hatchback_Blue", 			100, "Blue",			{"\A3\Soft_F_Gamma\Hatchback_01\data\Hatchback_01_ext_BASE03_CO.paa"}},
			{"Exile_Car_Hatchback_BlueCustom", 		100, "Blue Custom",		{"\A3\Soft_F_Gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa"}},
			{"Exile_Car_Hatchback_BeigeCustom", 	100, "Beige Custom",	{"\A3\Soft_F_Gamma\Hatchback_01\data\Hatchback_01_ext_BASE05_CO.paa"}},
			{"Exile_Car_Hatchback_Yellow", 			100, "Yellow",			{"\A3\Soft_F_Gamma\Hatchback_01\data\Hatchback_01_ext_BASE06_CO.paa"}},
			{"Exile_Car_Hatchback_Grey", 			100, "Grey",			{"\A3\Soft_F_Gamma\Hatchback_01\data\Hatchback_01_ext_BASE07_CO.paa"}},
			{"Exile_Car_Hatchback_Black", 			100, "Black",			{"\A3\Soft_F_Gamma\Hatchback_01\data\Hatchback_01_ext_BASE08_CO.paa"}},
			{"Exile_Car_Hatchback_Dark", 			100, "Dark",			{"\A3\Soft_F_Gamma\Hatchback_01\data\Hatchback_01_ext_BASE09_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Hatchback (Sport)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Hatchback_Sport_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Hatchback_Sport_Red", 		100, "Red",		{"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT01_CO.paa"}},
			{"Exile_Car_Hatchback_Sport_Blue", 		100, "Blue",	{"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT02_CO.paa"}},
			{"Exile_Car_Hatchback_Sport_Orange", 	100, "Orange",	{"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT03_CO.paa"}},
			{"Exile_Car_Hatchback_Sport_White", 	100, "White",	{"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT04_CO.paa"}},
			{"Exile_Car_Hatchback_Sport_Beige", 	100, "Beige",	{"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT05_CO.paa"}},
			{"Exile_Car_Hatchback_Sport_Green", 	100, "Green",	{"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT06_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Offroad
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Offroad_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Offroad_Rusty1", 		50, "Rusty White",	{"\exile_assets\model\RTV\Exile_offroad_03_co.paa","\exile_assets\model\RTV\Exile_offroad_03_co.paa"}},
			{"Exile_Car_Offroad_Rusty2", 		50, "Rusty Red",	{"\exile_assets\model\RTV\Exile_offroad_01_co.paa","\exile_assets\model\RTV\Exile_offroad_01_co.paa"}},
			{"Exile_Car_Offroad_Rusty3", 		50, "Rusty Blue",	{"\exile_assets\model\RTV\Exile_offroad_02_co.paa","\exile_assets\model\RTV\Exile_offroad_02_co.paa"}},
			{"Exile_Car_Offroad_Red", 			500, "Red",			{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_CO.paa"}},
			{"Exile_Car_Offroad_Beige", 		500, "Beige",		{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE01_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE01_CO.paa"}},
			{"Exile_Car_Offroad_White", 		500, "White",		{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE02_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE02_CO.paa"}},
			{"Exile_Car_Offroad_Blue", 			500, "Blue",		{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE03_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE03_CO.paa"}},
			{"Exile_Car_Offroad_DarkRed", 		500, "Dark Red",	{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE04_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE04_CO.paa"}},
			{"Exile_Car_Offroad_BlueCustom", 	500, "Blue Custom",	{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE05_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE05_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla01", 	700, "Guerilla 01",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_01_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_01_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla02", 	700, "Guerilla 02",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_02_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_02_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla03", 	700, "Guerilla 03",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_03_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_03_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla04", 	700, "Guerilla 04",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_04_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_04_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla05", 	700, "Guerilla 05",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_05_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_05_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla06", 	700, "Guerilla 06",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_06_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_06_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla07", 	700, "Guerilla 07",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_07_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_07_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla08", 	700, "Guerilla 08",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_08_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_08_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla09", 	700, "Guerilla 09",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_09_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_09_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla10", 	700, "Guerilla 10",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_10_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_10_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla11", 	700, "Guerilla 11",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_11_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_11_CO.paa"}},
			{"Exile_Car_Offroad_Guerilla12", 	700, "Guerilla 12",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_12_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_12_CO.paa"}},
			{"Exile_Car_Offroad_DarkRed",		700, "Exile Black", {"exile_assets\texture\vehicle\Exile_Offroad_Black_co.paa"}},
			{"Exile_Car_Offroad_DarkRed",		700, "Exile Light Blue", {"exile_assets\texture\vehicle\Exile_Offroad_LightBlue_co.paa"}},
			{"Exile_Car_Offroad_DarkRed",		700, "Exile Orange",{"exile_assets\texture\vehicle\Exile_Offroad_Orange_co.paa"}},
			{"Exile_Car_Offroad_DarkRed",		700, "Exile Pink",	{"exile_assets\texture\vehicle\Exile_Offroad_Pink_co.paa"}},
			{"Exile_Car_Offroad_DarkRed",		700, "Exile White",	{"exile_assets\texture\vehicle\Exile_Offroad_White_co.paa"}},
			{"Exile_Car_Offroad_DarkRed",		700, "Exile Yellow",{"exile_assets\texture\vehicle\Exile_Offroad_Yellow_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Land Rover
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_LandRover_Abstract
	{
		skins[] =
		{
			{"Exile_Car_LandRover_Red", 250, "Red", {"Exile_psycho_LRC\data\r_lr_base_co.paa","Exile_psycho_LRC\data\r_lr_special_co.paa"}},
			{"Exile_Car_LandRover_Urban", 250, "Urban", {"Exile_psycho_LRC\data\textures\lr_base_urbancamo_co.paa","Exile_psycho_LRC\data\textures\lr_special_urbancamo_co.paa"}},
			{"Exile_Car_LandRover_Green", 250, "Green", {"Exile_psycho_LRC\data\lr_acr_base_co.paa","Exile_psycho_LRC\data\lr_acr_spec_co.paa"}},
			{"Exile_Car_LandRover_Sand", 250, "Sand", {"Exile_psycho_LRC\data\lr_acr_sand_base_co.paa","Exile_psycho_LRC\data\lr_special_acr_co.paa"}},
			{"Exile_Car_LandRover_Desert", 250, "Desert", {"Exile_psycho_LRC\data\lr_acrs_base_co.paa","Exile_psycho_LRC\data\lr_special_acr_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Land Rover (Ambulance)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_LandRover_Ambulance_Abstract
	{
		skins[] =
		{
			{"Exile_Car_LandRover_Ambulance_Green", 250, "Green", {"Exile_psycho_LRC\data\lr_acr_base_co.paa","Exile_psycho_LRC\data\lr_amb_ext_co.paa","Exile_psycho_LRC\data\lr_acr_spec_co.paa"}},
			{"Exile_Car_LandRover_Ambulance_Desert", 250, "Desert", {"Exile_psycho_LRC\data\lr_acrs_base_co.paa","Exile_psycho_LRC\data\lr_amb_ext_co.paa","Exile_psycho_LRC\data\lr_special_acr_co.paa"}},
			{"Exile_Car_LandRover_Ambulance_Sand", 250, "Sand", {"Exile_psycho_LRC\data\lr_acr_sand_base_co.paa","Exile_psycho_LRC\data\lr_amb_ext_co.paa","Exile_psycho_LRC\data\lr_special_acr_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Octavius
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Octavius_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Octavius_White", 250, "White", {"exile_psycho_Octavia\Data\car_body_co.paa"}},
			{"Exile_Car_Octavius_Black", 250, "Black", {"exile_psycho_Octavia\Data\car_body_bl_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// UH-1H Huey
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Huey_Abstract
	{
		skins[] =
		{
			{"Exile_Chopper_Huey_Green", 700, "Green", {"Exile_psycho_UH1H\data\uh1h_co.paa","Exile_psycho_UH1H\data\uh1h_in_co.paa","Exile_psycho_UH1H\data\default_co.paa","Exile_psycho_UH1H\data\alpha_ca.paa"}},
			{"Exile_Chopper_Huey_Desert", 700, "Desert", {"Exile_psycho_UH1H\data\uh1d_tka_co.paa","Exile_psycho_UH1H\data\uh1d_in_tka_co.paa","Exile_psycho_UH1H\data\default_co.paa","Exile_psycho_UH1H\data\alpha_ca.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// UH-1H Huey (Armed)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Chopper_Huey_Armed_Abstract
	{
		skins[] =
		{
			{"Exile_Chopper_Huey_Armed_Green", 700, "Green", {"Exile_psycho_UH1H\data\uh1h_co.paa","Exile_psycho_UH1H\data\uh1h_in_co.paa","Exile_psycho_UH1H\data\default_co.paa","Exile_psycho_UH1H\data\alpha_ca.paa"}},
			{"Exile_Chopper_Huey_Armed_Desert", 700, "Desert", {"Exile_psycho_UH1H\data\uh1d_tka_co.paa","Exile_psycho_UH1H\data\uh1d_in_tka_co.paa","Exile_psycho_UH1H\data\default_co.paa","Exile_psycho_UH1H\data\alpha_ca.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Offroad (Armed)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Offroad_Armed_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Offroad_Armed_Guerilla01",	250, "Guerilla 01", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_01_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_01_CO.paa"}},
			{"Exile_Car_Offroad_Armed_Guerilla02",	250, "Guerilla 02", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_02_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_02_CO.paa"}},
			{"Exile_Car_Offroad_Armed_Guerilla03",	250, "Guerilla 03", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_03_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_03_CO.paa"}},
			{"Exile_Car_Offroad_Armed_Guerilla04",	250, "Guerilla 04", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_04_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_04_CO.paa"}},
			{"Exile_Car_Offroad_Armed_Guerilla05",	250, "Guerilla 05", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_05_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_05_CO.paa"}},
			{"Exile_Car_Offroad_Armed_Guerilla06",	250, "Guerilla 06", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_06_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_06_CO.paa"}},
			{"Exile_Car_Offroad_Armed_Guerilla07",	250, "Guerilla 07", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_07_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_07_CO.paa"}},
			{"Exile_Car_Offroad_Armed_Guerilla08",	250, "Guerilla 08", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_08_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_08_CO.paa"}},
			{"Exile_Car_Offroad_Armed_Guerilla09",	250, "Guerilla 09", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_09_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_09_CO.paa"}},
			{"Exile_Car_Offroad_Armed_Guerilla10",	250, "Guerilla 10", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_10_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_10_CO.paa"}},
			{"Exile_Car_Offroad_Armed_Guerilla11",	250, "Guerilla 11", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_11_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_11_CO.paa"}},
			{"Exile_Car_Offroad_Armed_Guerilla12",	250, "Guerilla 12", {"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_12_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_12_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Offroad (Repair)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Offroad_Repair_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Offroad_Repair_Civillian",		150, "Civillian",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\Offroad_01_ext_repair_CIV_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\Offroad_01_ext_repair_CIV_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Red",			150, "Red",			{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Beige",			150, "Beige",		{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE01_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE01_CO.paa"}},
			{"Exile_Car_Offroad_Repair_White",			150, "White",		{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE02_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE02_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Blue",			150, "Blue",		{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE03_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE03_CO.paa"}},
			{"Exile_Car_Offroad_Repair_DarkRed",		150, "DarkRed",		{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE04_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE04_CO.paa"}},
			{"Exile_Car_Offroad_Repair_BlueCustom",		150, "BlueCustom",	{"\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE05_CO.paa","\a3\Soft_F\Offroad_01\data\Offroad_01_ext_BASE05_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla01",		250, "Guerilla 01",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_01_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_01_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla02",		250, "Guerilla 02",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_02_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_02_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla03",		250, "Guerilla 03",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_03_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_03_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla04",		250, "Guerilla 04",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_04_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_04_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla05",		250, "Guerilla 05",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_05_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_05_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla06",		250, "Guerilla 06",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_06_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_06_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla07",		250, "Guerilla 07",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_07_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_07_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla08",		250, "Guerilla 08",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_08_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_08_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla09",		250, "Guerilla 09",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_09_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_09_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla10",		250, "Guerilla 10",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_10_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_10_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla11",		250, "Guerilla 11",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_11_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_11_CO.paa"}},
			{"Exile_Car_Offroad_Repair_Guerilla12",		250, "Guerilla 12",	{"\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_12_CO.paa","\A3\Soft_F_Bootcamp\Offroad_01\Data\offroad_01_ext_IG_12_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// SUV
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_SUV_Abstract
	{
		skins[] =
		{
			{"Exile_Car_SUV_Red", 		100, "Red",					{"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_CO.paa"}},
			{"Exile_Car_SUV_Black", 	150, "Black",				{"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_02_CO.paa"}},
			{"Exile_Car_SUV_Grey", 		100, "Grey",				{"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_03_CO.paa"}},
			{"Exile_Car_SUV_Orange", 	100, "Orange",				{"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_04_CO.paa"}},
			{"Exile_Car_SUV_Black", 	150, "Snow Camo",			{"exile_assets\texture\vehicle\Exile_SUV_Snow_co.paa"}},
			{"Exile_Car_SUV_Black", 	150, "Leaf Camo",			{"exile_assets\texture\vehicle\Exile_SUV_Leaf_Light_co.paa"}},
			{"Exile_Car_SUV_Black", 	150, "Leaf Camo (Dark)",	{"exile_assets\texture\vehicle\Exile_SUV_Leaf_Dark_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// SUV XL
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_SUVXL_Abstract
	{
		skins[] = 
		{
			{"Exile_Car_SUVXL_Black", 100, "Black", {"\Exile_psycho_SUV_a3\Data\suv_body_co.paa"}},
			{"Exile_Car_SUVXL_Black", 150, "Blue White", {"\Exile_psycho_SUV_a3\Data\textures\suv_body_bluewhite.paa"}},
			{"Exile_Car_SUVXL_Black", 150, "Charcoal", {"\Exile_psycho_SUV_a3\Data\textures\suv_body_charcoal_co.paa"}},
			{"Exile_Car_SUVXL_Black", 150, "Orange", {"\Exile_psycho_SUV_a3\Data\textures\suv_body_orange_co.paa"}},
			{"Exile_Car_SUVXL_Black", 200, "Hello Kitty", {"\Exile_psycho_SUV_a3\Data\textures\suv_body_Pink_hello_co.paa"}},
			{"Exile_Car_SUVXL_Black", 150, "Red", {"\Exile_psycho_SUV_a3\Data\textures\suv_body_red_co.paa"}},
			{"Exile_Car_SUVXL_Black", 150, "Silver", {"\Exile_psycho_SUV_a3\Data\textures\suv_body_silver_co.paa"}},
			{"Exile_Car_SUVXL_Black", 100, "White", {"\Exile_psycho_SUV_a3\Data\textures\suv_body_white_co.paa"}},
			{"Exile_Car_SUVXL_Black", 150, "Yellow", {"\Exile_psycho_SUV_a3\Data\textures\suv_body_yellow_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Van
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Van_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Van_Black",			100, "Black",		{"\A3\soft_f_gamma\van_01\Data\Van_01_ext_black_CO.paa","\A3\soft_f_gamma\van_01\Data\van_01_adds_CO.paa"}},
			{"Exile_Car_Van_White",			100, "White",		{"\A3\soft_f_gamma\van_01\Data\van_01_ext_CO.paa","\A3\soft_f_gamma\van_01\Data\van_01_adds_CO.paa"}},
			{"Exile_Car_Van_Red",			100, "Red",			{"\A3\soft_f_gamma\van_01\Data\Van_01_ext_red_CO.paa","\A3\soft_f_gamma\van_01\Data\van_01_adds_CO.paa"}},
			{"Exile_Car_Van_Guerilla01",	150, "Guerilla 01",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_01_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_01_CO.paa"}},
			{"Exile_Car_Van_Guerilla02",	150, "Guerilla 02",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_02_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_02_CO.paa"}},
			{"Exile_Car_Van_Guerilla03",	150, "Guerilla 03",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_03_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_03_CO.paa"}},
			{"Exile_Car_Van_Guerilla04",	150, "Guerilla 04",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_04_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_04_CO.paa"}},
			{"Exile_Car_Van_Guerilla05",	150, "Guerilla 05",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_05_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_05_CO.paa"}},
			{"Exile_Car_Van_Guerilla06",	150, "Guerilla 06",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_06_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_06_CO.paa"}},
			{"Exile_Car_Van_Guerilla07",	150, "Guerilla 07",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_07_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_07_CO.paa"}},
			{"Exile_Car_Van_Guerilla08",	150, "Guerilla 08",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_08_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_08_CO.paa"}},
			{"Exile_Car_Van_Black",	150, "Brown",	{"\A3\Soft_F_Exp\Van_01\Data\Van_01_ext_brn_co.paa","\A3\soft_f_gamma\van_01\Data\van_01_adds_CO.paa","\A3\Soft_F_Exp\Van_01\Data\Van_01_int_base_2_CO.paa"}},
			{"Exile_Car_Van_Black",	150, "Olive",	{"\A3\Soft_F_Exp\Van_01\Data\Van_01_ext_oli_co.paa","\A3\soft_f_gamma\van_01\Data\van_01_adds_CO.paa","\A3\Soft_F_Exp\Van_01\Data\Van_01_int_base_3_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Van (Box)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Van_Box_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Van_Box_Black",				100, "Black",		{"\A3\soft_f_gamma\van_01\Data\Van_01_ext_black_CO.paa","\A3\soft_f_gamma\van_01\Data\van_01_adds_CO.paa"}},
			{"Exile_Car_Van_Box_White",				100, "White",		{"\A3\soft_f_gamma\van_01\Data\van_01_ext_CO.paa","\A3\soft_f_gamma\van_01\Data\van_01_adds_CO.paa"}},
			{"Exile_Car_Van_Box_Red",				100, "Red",			{"\A3\soft_f_gamma\van_01\Data\Van_01_ext_red_CO.paa","\A3\soft_f_gamma\van_01\Data\van_01_adds_CO.paa"}},
			{"Exile_Car_Van_Box_Guerilla01",		150, "Guerilla 01",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_01_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_01_CO.paa"}},
			{"Exile_Car_Van_Box_Guerilla02",		150, "Guerilla 02",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_02_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_02_CO.paa"}},
			{"Exile_Car_Van_Box_Guerilla03",		150, "Guerilla 03",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_03_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_03_CO.paa"}},
			{"Exile_Car_Van_Box_Guerilla04",		150, "Guerilla 04",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_04_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_04_CO.paa"}},
			{"Exile_Car_Van_Box_Guerilla06",		150, "Guerilla 06",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_06_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_06_CO.paa"}},
			{"Exile_Car_Van_Box_Guerilla07",		150, "Guerilla 07",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_07_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_07_CO.paa"}},
			{"Exile_Car_Van_Box_Guerilla08",		150, "Guerilla 08",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_08_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_adds_IG_08_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Van (Fuel)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Van_Fuel_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Van_Fuel_Black",			100, "Black",		{"\A3\soft_f_gamma\van_01\Data\Van_01_ext_black_CO.paa","\A3\soft_f_gamma\Van_01\Data\Van_01_tank_CO.paa"}},
			{"Exile_Car_Van_Fuel_White",			100, "White",		{"\A3\soft_f_gamma\van_01\Data\van_01_ext_CO.paa","\A3\soft_f_gamma\Van_01\Data\Van_01_tank_CO.paa"}},
			{"Exile_Car_Van_Fuel_Red",				100, "Red",			{"\A3\soft_f_gamma\van_01\Data\Van_01_ext_red_CO.paa","\A3\soft_f_gamma\Van_01\Data\Van_01_tank_CO.paa"}},
			{"Exile_Car_Van_Fuel_Guerilla01",		150, "Guerilla 01",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_01_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_tank_IG_01_CO.paa"}},
			{"Exile_Car_Van_Fuel_Guerilla02",		150, "Guerilla 02",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_02_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_tank_IG_02_CO.paa"}},
			{"Exile_Car_Van_Fuel_Guerilla03",		150, "Guerilla 03",	{"\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_ext_IG_03_CO.paa","\A3\Soft_F_Bootcamp\Van_01\Data\Van_01_tank_IG_03_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Tempest
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Tempest_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Tempest", 		200, "Green Hex",	{"\A3\Soft_F_Exp\Truck_03\Data\Truck_03_ext01_ghex_CO.paa","\A3\Soft_F_Exp\Truck_03\Data\Truck_03_ext02_ghex_CO.paa","\A3\Soft_F_Exp\Truck_03\Data\Truck_03_cargo_ghex_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Ikarus
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Ikarus_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Ikarus_Blue", 		200, "Blue",	{"Exile_psycho_Ikarus\Data\bus_exterior_co.paa"}},
			{"Exile_Car_Ikarus_Red", 		200, "Red",		{"Exile_psycho_Ikarus\Data\bus_exterior_eciv_co.paa"}},
			{"Exile_Car_Ikarus_Party", 		500, "Party",	{"Exile_psycho_Ikarus\Data\bus_exterior_eciv_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Ural (Open)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Ural_Open_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Ural_Open_Blue",			300, "Blue",		{"Exile_psycho_Ural\data\Ural_kabina_civil_co.paa","Exile_psycho_Ural\data\ural_plachta_civil_co.paa"}},
			{"Exile_Car_Ural_Open_Yellow",			300, "Yellow",		{"Exile_psycho_Ural\data\ural_kabina_civ1_co.paa","Exile_psycho_Ural\data\ural_plachta_civ1_co.paa"}},
			{"Exile_Car_Ural_Open_Worker",			300, "Worker",		{"Exile_psycho_Ural\data\ural_kabina_civ2_co.paa","Exile_psycho_Ural\data\Ural_plachta_civil_co.paa"}},
			{"Exile_Car_Ural_Open_Military",		300, "Military",	{"Exile_psycho_Ural\data\ural_kabina_khk_co.paa","Exile_psycho_Ural\data\ural_plachta_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Ural (Covered)
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Ural_Covered_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Ural_Covered_Blue",			300, "Blue",		{"Exile_psycho_Ural\data\ural_kabina_civil_co.paa","Exile_psycho_Ural\data\ural_plachta_civil_co.paa"}},
			{"Exile_Car_Ural_Covered_Yellow",		300, "Yellow",		{"Exile_psycho_Ural\data\ural_kabina_civ1_co.paa","Exile_psycho_Ural\data\ural_plachta_civ1_co.paa"}},
			{"Exile_Car_Ural_Covered_Worker",		300, "Worker",		{"Exile_psycho_Ural\data\ural_kabina_civ2_co.paa","Exile_psycho_Ural\data\Ural_plachta_civil_co.paa"}},
			{"Exile_Car_Ural_Covered_Military",		300, "Military",	{"Exile_psycho_Ural\data\ural_kabina_khk_co.paa","Exile_psycho_Ural\data\ural_plachta_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Lada
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Lada_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Lada_Green", 		100, "Green",	{"exile_psycho_lada\data\lada_eciv1_co.paa","exile_psycho_lada\data\Lada_glass_ECIV1_CA.paa"}},
			{"Exile_Car_Lada_Taxi", 		100, "Taxi",	{"exile_psycho_lada\data\Lada_red_CO.paa"}},
			{"Exile_Car_Lada_Red", 			100, "Red",		{"exile_psycho_lada\data\Lada_red_CO.paa"}},
			{"Exile_Car_Lada_Hipster", 		100, "Hipster",	{"exile_psycho_lada\data\lada_eciv2_co.paa","exile_psycho_lada\data\Lada_glass_ECIV2_CA.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Volha
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Volha_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Volha_Blue", 		100, "Blue",	{"Exile_psycho_Gaz_volha\data\Volha_ECIV_CO.paa"}},
			{"Exile_Car_Volha_White", 		100, "White",	{"Exile_psycho_Gaz_volha\data\Volha_Gray_ECIV_CO.paa"}},
			{"Exile_Car_Volha_Black",		100, "Black",	{"Exile_psycho_Gaz_volha\data\Volha_Black_ECIV_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// EXILE STRIDER
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Strider_Abstract
	{
		skins[] = 
		{
			{"Exile_Car_Strider",		1000, "NATO",		{"\A3\soft_f_beta\mrap_03\data\mrap_03_ext_co.paa","\A3\data_f\vehicles\turret_co.paa"}},
			{"Exile_Car_Strider",		1000, "HEX",		{"\A3\soft_f_beta\mrap_03\data\mrap_03_ext_indp_co.paa","\A3\data_f\vehicles\turret_indp_co.paa"}},
			{"Exile_Car_Strider",		1000, "CSAT",		{"custom\textures\mrap_03_ext_csat_co.paa","\A3\data_f\vehicles\turret_opfor_co.paa"}},
			{"Exile_Car_Strider",		1000, "Black",	{"custom\textures\mrap_03_ext_black_co.paa","custom\textures\turret_black_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// ARMA STRIDER
	///////////////////////////////////////////////////////////////////////////////
	class MRAP_03_hmg_base_F
	{
		skins[] = 
		{
			{"I_MRAP_03_hmg_F",		1000, "NATO",		{"\A3\soft_f_beta\mrap_03\data\mrap_03_ext_co.paa","\A3\data_f\vehicles\turret_co.paa"}},
			{"I_MRAP_03_hmg_F",		1000, "HEX",		{"\A3\soft_f_beta\mrap_03\data\mrap_03_ext_indp_co.paa","\A3\data_f\vehicles\turret_indp_co.paa"}},
			{"I_MRAP_03_hmg_F",		1000, "CSAT",		{"custom\textures\mrap_03_ext_csat_co.paa","\A3\data_f\vehicles\turret_opfor_co.paa"}},
			{"I_MRAP_03_hmg_F",		1000, "Black",	{"custom\textures\mrap_03_ext_black_co.paa","custom\textures\turret_black_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// HUNTER
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Hunter_Abstract
	{
		skins[] =
		{
			{"Exile_Car_Hunter",		1000, "Khaki",								{"\A3\soft_F\MRAP_01\data\MRAP_01_base_CO.paa","\A3\soft_F\MRAP_01\data\MRAP_01_adds_CO.paa"}},
			{"Exile_Car_Hunter",		1000, "Exile White Edition",	{"exile_assets\texture\vehicle\Exile_Hunter_Snow_co.paa","exile_assets\texture\vehicle\Exile_Hunter_Snow_Back_co.paa"}},
			{"Exile_Car_Hunter",		1000, "Exile Hex",				{"exile_assets\texture\vehicle\Exile_Hunter_Hex_co.paa","exile_assets\texture\vehicle\Exile_Hunter_Black_Back_co.paa"}},
			{"Exile_Car_Hunter",		1000, "Exile Black",			{"exile_assets\texture\vehicle\Exile_Hunter_Black_co.paa","exile_assets\texture\vehicle\Exile_Hunter_Black_Back_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// IFRIT
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Ifrit_Abstract
	{
		skins[] =
		{

			{"Exile_Car_Ifrit",		1000, "Green Hex",	{"\A3\Soft_F_Exp\MRAP_02\data\MRAP_02_ext_01_ghex_CO.paa","\A3\Soft_F_Exp\MRAP_02\data\MRAP_02_ext_02_ghex_CO.paa","\A3\Data_F_Exp\Vehicles\Turret_ghex_CO.paa"}},
			{"Exile_Car_Ifrit",		1000, "CSAT",				{"\A3\soft_F\MRAP_02\data\MRAP_02_ext_01_CO.paa","\A3\soft_F\MRAP_02\data\MRAP_02_ext_02_CO.paa","\A3\Data_F\Vehicles\turret_opfor_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// IFRIT (Armed)
	///////////////////////////////////////////////////////////////////////////////
	class MRAP_02_hmg_base_F
	{
		skins[] = 
		{
			{"O_MRAP_02_hmg_F",		1000, "Green Hex",	{"\A3\Soft_F_Exp\MRAP_02\data\MRAP_02_ext_01_ghex_CO.paa","\A3\Soft_F_Exp\MRAP_02\data\MRAP_02_ext_02_ghex_CO.paa","\A3\Data_F_Exp\Vehicles\Turret_ghex_CO.paa"}},
			{"O_MRAP_02_hmg_F",		1000, "CSAT",				{"\A3\soft_F\MRAP_02\data\MRAP_02_ext_01_CO.paa","\A3\soft_F\MRAP_02\data\MRAP_02_ext_02_CO.paa","\A3\Data_F\Vehicles\turret_opfor_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// HMMWV
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_HMMWV_M2_Abstract
	{
		skins[] =
		{

			{"Exile_Car_HMMWV_M2_Green",		1000, "Green",	{"Exile_psycho_hmmw\data\hmmwv_body_co.paa"}},
			{"Exile_Car_HMMWV_M2_Desert",		1000, "Desert",	{"Exile_psycho_hmmw\data\des\hmmwv_body_co.paa"}}
		};
	};

	class Exile_Car_HMMWV_M134_Abstract
	{
		skins[] =
		{

			{"Exile_Car_HMMWV_M134_Green",		1000, "Green",	{"Exile_psycho_hmmw\data\hmmwv_body_co.paa"}},
			{"Exile_Car_HMMWV_M134_Desert",		1000, "Desert",	{"Exile_psycho_hmmw\data\des\hmmwv_body_co.paa"}}
		};
	};

	class Exile_Car_HMMWV_MEV_Abstract
	{
		skins[] =
		{

			{"Exile_Car_HMMWV_MEV_Green",		1000, "Green",	{"Exile_psycho_hmmw\data\hmmwv_body_cm.paa"}},
			{"Exile_Car_HMMWV_MEV_Desert",		1000, "Desert",	{"Exile_psycho_hmmw\data\des\hmmwv_body_cm.paa"}}
		};
	};

	class Exile_Car_HMMWV_UNA_Abstract
	{
		skins[] =
		{

			{"Exile_Car_HMMWV_UNA_Green",		1000, "Green",	{"Exile_psycho_hmmw\data\hmmwv_body_co.paa"}},
			{"Exile_Car_HMMWV_UNA_Desert",		1000, "Desert",	{"Exile_psycho_hmmw\data\des\hmmwv_body_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// BTR40
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_BTR40_MG_Abstract
	{
		skins[] =
		{

			{"Exile_Car_BTR40_MG_Green",		1000, "Green",	{"exile_psycho_btr40\data\btr40ext_co.paa"}},
			{"Exile_Car_BTR40_MG_Camo",			1000, "Camo",	{"exile_psycho_btr40\data\btr40extcamo_co.paa"}}
		};
	};

	class Exile_Car_BTR40_Abstract
	{
		skins[] =
		{

			{"Exile_Car_BTR40_Green",			1000, "Green",	{"exile_psycho_btr40\data\btr40ext_co.paa"}},
			{"Exile_Car_BTR40_Camo",			1000, "Camo",	{"exile_psycho_btr40\data\btr40extcamo_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Golf
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Car_Golf_Abstract
	{
		skins[] =
		{

			{"Exile_Car_Golf_Red",				1000, "Red",	{"exile_psycho_VWGolf\data\vwgolf_body_co.paa"}},
			{"Exile_Car_Golf_Black",			1000, "Black",	{"exile_psycho_VWGolf\data\texture\black_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// AN-2
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Plane_AN2_Abstract
	{
		skins[] =
		{
			{"Exile_Plane_AN2_Green", 700, "Green", {"Exile_psycho_An2\data\an2_1_co.paa","Exile_psycho_An2\data\an2_2_co.paa","Exile_psycho_An2\data\an2_wings_co.paa"}},
			{"Exile_Plane_AN2_White", 700, "Red, White & Blue", {"Exile_psycho_An2\data\an2_1_a_co.paa",
		"Exile_psycho_An2\data\an2_2_a_co.paa","Exile_psycho_An2\data\an2_wings_a_co.paa"}},
			{"Exile_Plane_AN2_Stripe", 700, "Green Stripe", {"Exile_psycho_An2\data\an2_1_b_co.paa","Exile_psycho_An2\data\an2_2_b_co.paa","Exile_psycho_An2\data\an2_wings_b_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// RHIB
	///////////////////////////////////////////////////////////////////////////////
	class B_G_Boat_Transport_02_F
	{
		skins[] =
		{
			{"Exile_Boat_RHIB",		150, "Blue", {"\A3\Boat_F_Exp\Boat_Transport_02\Data\Boat_Transport_02_exterior_civilian_CO.paa","\A3\Boat_F_Exp\Boat_Transport_02\Data\Boat_Transport_02_interior_2_civilian_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Water Scooter
	///////////////////////////////////////////////////////////////////////////////
	class Exile_Boat_WaterScooter_Abstract
	{
		skins[] =
		{
			{"Exile_Boat_WaterScooter",		150, "Blue", {"\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Blue_co.paa","\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Blue_co.paa"}},
			{"Exile_Boat_WaterScooter",		150, "Grey", {"\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Grey_co.paa","\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Grey_co.paa"}},
			{"Exile_Boat_WaterScooter",		150, "Lime", {"\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Lime_co.paa","\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Lime_co.paa"}},
			{"Exile_Boat_WaterScooter",		150, "Red", {"\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Red_CO.paa","\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_CO.paa"}},
			{"Exile_Boat_WaterScooter",		150, "White", {"\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_CO.paa","\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_CO.paa"}},
			{"Exile_Boat_WaterScooter",		150, "Yellow", {"\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_Yellow_CO.paa","\A3\Boat_F_Exp\Scooter_Transport_01\Data\Scooter_Transport_01_VP_Yellow_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Ceasar BTT
	///////////////////////////////////////////////////////////////////////////////
	class C_Plane_Civil_01_F
	{
		skins[] =
		{
			{"Exile_Plane_Ceasar",		150, "Racing (Tan Interior)", {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Racer_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Racer_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"}},
			{"Exile_Plane_Ceasar",		150, "Racing", {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Racer_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Racer_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"}},
			{"Exile_Plane_Ceasar",		150, "Red Line (Tan Interior)", {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"}},
			{"Exile_Plane_Ceasar",		150, "Tribal (Tan Interior)", {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"}},
			{"Exile_Plane_Ceasar",		150, "Tribal", {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"}},
			{"Exile_Plane_Ceasar",		150, "Blue Wave (Tan Interior)", {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Wave_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Wave_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"}},
			{"Exile_Plane_Ceasar",		150, "Blue Wave", {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Wave_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Wave_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa","A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// V-44 X Blackfish (Infantry Transport)
	///////////////////////////////////////////////////////////////////////////////
	class B_T_VTOL_01_infantry_F
	{
		skins[] =
		{
			{"Exile_Plane_BlackfishInfantry",		150, "Blue", {"\A3\Air_F_Exp\VTOL_01\Data\VTOL_01_EXT01_blue_CO.paa","\A3\Air_F_Exp\VTOL_01\Data\VTOL_01_EXT02_blue_CO.paa","\A3\Air_F_Exp\VTOL_01\Data\VTOL_01_EXT03_blue_CO.paa","\A3\Air_F_Exp\VTOL_01\Data\VTOL_01_EXT04_blue_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// V-44 X Blackfish (Vehicle Transport)
	///////////////////////////////////////////////////////////////////////////////
	class B_T_VTOL_01_vehicle_F
	{
		skins[] =
		{
			{"Exile_Plane_BlackfishVehicle",		150, "Blue", {"\A3\Air_F_Exp\VTOL_01\Data\VTOL_01_EXT01_blue_CO.paa","\A3\Air_F_Exp\VTOL_01\Data\VTOL_01_EXT02_blue_CO.paa","\A3\Air_F_Exp\VTOL_01\Data\VTOL_01_EXT03_blue_CO.paa","\A3\Air_F_Exp\VTOL_01\Data\VTOL_01_EXT04_blue_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Prowler (Light)
	///////////////////////////////////////////////////////////////////////////////
	class B_CTRG_LSV_01_light_F
	{
		skins[] =
		{
			{"Exile_Car_ProwlerLight",		150, "Black", {"\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_01_black_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_02_black_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_03_black_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_Adds_black_CO.paa"}},
			{"Exile_Car_ProwlerLight",		150, "Dazzle", {"\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_01_dazzle_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_02_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_03_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_Adds_olive_CO.paa"}},
			{"Exile_Car_ProwlerLight",		150, "Sand", {"\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_01_sand_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_02_sand_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_03_sand_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_Adds_sand_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Prowler (Unarmed)
	///////////////////////////////////////////////////////////////////////////////
	class B_T_LSV_01_unarmed_black_F
	{
		skins[] =
		{
			{"Exile_Car_ProwlerUnarmed",		150, "Olive", {"\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_01_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_02_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_03_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_Adds_olive_CO.paa"}},
			{"Exile_Car_ProwlerUnarmed",		150, "Dazzle", {"\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_01_dazzle_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_02_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_03_olive_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_Adds_olive_CO.paa"}},
			{"Exile_Car_ProwlerUnarmed",		150, "Sand", {"\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_01_sand_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_02_sand_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_03_sand_CO.paa","\A3\Soft_F_Exp\LSV_01\Data\NATO_LSV_Adds_sand_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// Qilin (Unarmed)
	///////////////////////////////////////////////////////////////////////////////
	class O_T_LSV_02_unarmed_black_F
	{
		skins[] =
		{
			{"Exile_Car_QilinUnarmed",		150, "Arid", {"\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_01_arid_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_02_arid_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_03_arid_CO.paa"}},
			{"Exile_Car_QilinUnarmed",		150, "Green Hex", {"\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_01_ghex_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa","\A3\Soft_F_Exp\LSV_02\Data\CSAT_LSV_03_ghex_CO.paa"}}
		};
	};

	///////////////////////////////////////////////////////////////////////////////
	// MB 4WD
	///////////////////////////////////////////////////////////////////////////////
	class C_Offroad_02_unarmed_orange_F
	{
		skins[] =
		{
			{"Exile_Car_MB4WD",		150, "Black", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_black_co.paa"}},
			{"Exile_Car_MB4WD",		150, "Blue", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_blue_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_blue_co.paa"}},
			{"Exile_Car_MB4WD",		150, "Brown", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_brown_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_brown_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_brown_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_brown_co.paa"}},
			{"Exile_Car_MB4WD",		150, "Green", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_green_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_green_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_green_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_green_co.paa"}},
			{"Exile_Car_MB4WD",		150, "Olive", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_olive_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_olive_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_olive_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_olive_co.paa"}},
			{"Exile_Car_MB4WD",		150, "Red", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_red_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_red_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_red_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_red_co.paa"}},
			{"Exile_Car_MB4WD",		150, "White", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_white_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_white_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_white_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_white_co.paa"}}
		};
	};

	class I_C_Offroad_02_unarmed_F
	{
		skins[] =
		{
			{"Exile_Car_MB4WDOpen",		150, "Black", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_black_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_black_co.paa"}},
			{"Exile_Car_MB4WDOpen",		150, "Blue", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_blue_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_blue_co.paa"}},
			{"Exile_Car_MB4WDOpen",		150, "Brown", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_brown_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_brown_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_brown_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_brown_co.paa"}},
			{"Exile_Car_MB4WDOpen",		150, "Green", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_green_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_green_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_green_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_green_co.paa"}},
			{"Exile_Car_MB4WDOpen",		150, "Orange", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_orange_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_orange_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_orange_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_orange_co.paa"}},
			{"Exile_Car_MB4WDOpen",		150, "Red", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_red_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_red_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_red_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_red_co.paa"}},
			{"Exile_Car_MB4WDOpen",		150, "White", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_white_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_white_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_white_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_white_co.paa"}},
			{"Exile_Car_MB4WDOpen",		150, "Olive", {"\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_olive_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_olive_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_olive_co.paa","\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_int_olive_co.paa"}}
		};
	};
};

class CfgVehicleTransport 
{
	class Exile_Container_SupplyBox
	{
		vehicles[] = {"Exile_Car_Van_Abstract", "Exile_Car_Offroad_Abstract", "Exile_Car_Zamak_Abstract", "Exile_Car_HEMMT_Abstract", "Exile_Car_Tempest_Abstract"};

		class Exile_Car_Van_Abstract
		{
			attachPosition[] = {0, -1.1, 0.2};
			cargoIndizes[] = {2, 3, 4, 5, 6, 7}; 
			detachPosition[] = {0, -4.4};
		};

		class Exile_Car_Offroad_Abstract
		{
			attachPosition[] = {0, -1.6, 0.4};
			cargoIndizes[] = {1, 2, 3, 4}; 
			detachPosition[] = {0, -4};
		};

		class Exile_Car_Zamak_Abstract
		{
			attachPosition[] = {0.03, 0.3, 0};
			cargoIndizes[] = {2, 3, 4, 5, 6, 7}; 
			detachPosition[] = {0.03, -4.8};
		};

		class Exile_Car_HEMMT_Abstract
		{
			attachPosition[] = {0.05, -0.1, 0.3};
			cargoIndizes[] = {1, 2, 8, 9}; 
			detachPosition[] = {0.05, -6.1};
		};

		class Exile_Car_Tempest_Abstract
		{
			attachPosition[] = {0.08, -0.85, 0.4};
			cargoIndizes[] = {1, 6, 7, 9}; 
			detachPosition[] = {0.08, -6};
		};
	};
};